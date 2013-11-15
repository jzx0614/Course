#include <gl/glut.h>
#include <math.h>
#include <stdio.h>           // Standard C/C++ Input-Output
#include <windows.h>
#define PI_OVER_180  0.0174532925f

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

typedef struct _VERTEX {
	float x, y, z;
	float u, v;
} VERTEX;

typedef struct _TRIANGLE {
	VERTEX vertex[4];
} TRIANGLE;
typedef struct _SECTOR {
	int numtriangles;
	TRIANGLE* triangle;
} SECTOR;

GLfloat g_xpos = 4.0f;          // Position In X-Axis 
GLfloat g_zpos = -4.0f;          // Position In Z-Axis 
GLfloat	g_yrot = 120.0f;          // Y Rotation 
GLfloat	g_z = 0.0f;	            // Depth Into The Screen 
GLfloat g_walkbias = 0.0f;      // Gives The Illusion That We Are Walking (NEW) 
GLfloat g_walkbiasangle = 0.0f; // Gives The Illusion That We Are Walking (NEW) 
SECTOR  g_sector1; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
bool    g_key[255];             // Lookup Table For Key's State (NEW)
bool turnOn = false;
bool car_on=false;
float wheelRotateAngle = 0.0;
GLfloat x_car = 1.0f;          // Position In X-Axis 
GLfloat	z_car = 2.0f;
GLfloat	y_car = 0.0f; 
GLfloat	g_fogColor[4] = {0.8f,0.8f,0.8f,1.0f};          // Fog Color (NEW)
GLUquadricObj *quadratic;
/*******************************************************************************************************/
class mRGB{ // holds a color triple ?each with 256 possible intensities
    public: 
		unsigned char r,g,b;
};

//The RGBpixmap class stores the number of rows and columns in the pixmap, as well as the address of the first pixel in memory:

class RGBpixmap{
  public: 
	int nRows, nCols; // dimensions of the pixmap
	mRGB* pixel; 	// array of pixels
	int readBMPFile(char * fname); // read BMP file into this pixmap
	void setTexture(GLuint textureName);
};

RGBpixmap pix[4];    // make  (empty) pixmap
float xSpeed = 0.3, ySpeed = 0.3,  xAngle = 10.0, yAngle = 10.0;
typedef unsigned short ushort;
typedef unsigned long ulong;
FILE * inf; // global in this file for convenience
//<<<<<<<<<<<<<<<<<<<<< getShort >>>>>>>>>>>>>>>>>>>>
ushort getShort() //helper function
{ //BMP format uses little-endian integer types
  // get a 2-byte integer stored in little-endian form
		char ic;
		ushort ip;
		fread(&ic, 1, 1, inf);
		ip = ic;  //first byte is little one 
		fread(&ic, 1, 1, inf);
		ip |= ((ushort)ic << 8); // or in high order byte
		return ip;
}
//<<<<<<<<<<<<<<<<<<<< getLong >>>>>>>>>>>>>>>>>>>
ulong getLong() //helper function
{  //BMP format uses little-endian integer types
   // get a 4-byte integer stored in little-endian form
		ulong ip = 0;
		char ic = 0;
		unsigned char uc = ic;
		fread(&ic, 1, 1, inf);
		uc = ic; 
		ip = uc;
		fread(&ic, 1, 1, inf);
		uc = ic; 
		ip |=((ulong)uc << 8);
		fread(&ic, 1, 1, inf);
		uc = ic; 
		ip |=((ulong)uc << 16);
		fread(&ic, 1, 1, inf);
		uc = ic; 
		ip |=((ulong)uc << 24);
		return ip;
	}
//<<<<<<<<<<<<<<<<<< RGBPixmap:: readBmpFile>>>>>>>>>>>>>
int RGBpixmap:: readBMPFile(char * fname) 
{  // Read into memory an mRGB image from an uncompressed BMP file.
	// return 0 on failure, 1 on success
	inf =fopen(fname, "rb");
	if(!inf)
	{ 
		printf("can't open file: %s\n", fname);
	}
	int k, row, col, numPadBytes, nBytesInRow;
	// read the file header information
	char ch1, ch2;
	fread(&ch1, 1, 1, inf);
	fread(&ch2, 1, 1, inf);
	ulong fileSize =      getLong();
	ushort reserved1 =    getShort();    // always 0
	ushort reserved2= 	getShort();     // always 0 
	ulong offBits =		getLong(); // offset to image - unreliable
	ulong headerSize =     getLong();     // always 40
	ulong numCols =		getLong(); // number of columns in image
	ulong numRows = 		getLong(); // number of rows in image
	ushort planes=    	getShort();      // always 1 
	ushort bitsPerPixel=   getShort();    //8 or 24; allow 24 here
	ulong compression =    getLong();      // must be 0 for uncompressed 
	ulong imageSize = 	getLong();       // total bytes in image 
	ulong xPels =    	getLong();    // always 0 
	ulong yPels =    	getLong();    // always 0 
	ulong numLUTentries = getLong();    // 256 for 8 bit, otherwise 0 
	ulong impColors = 	getLong();       // always 0 
	if(bitsPerPixel != 24) 
	{ // error - must be a 24 bit uncompressed image
		printf("not a 24 bit/pixelimage, or is compressed!\n");
		fclose(inf);
		return 0;
	} 
	//add bytes at end of each row so total # is a multiple of 4
	// round up 3*numCols to next mult. of 4
	nBytesInRow = ((3 * numCols + 3)/4) * 4;
	numPadBytes = nBytesInRow - 3 * numCols; // need this many
	nRows = numRows; // set class's data members
	nCols = numCols;
	pixel = new mRGB[nRows * nCols]; //make space for array
	if(!pixel) return 0; // out of memory!
	long count = 0;
	char dum;
	for(row = 0; row < nRows; row++) // read pixel values
	{
		for(col = 0; col < nCols; col++)
		{
			char r,g,b;
			fread(&b, 1, 1, inf);
			fread(&g, 1, 1, inf);
			fread(&r, 1, 1, inf);
			pixel[count].r = r; //place them in colors
			pixel[count].g = g;
			pixel[count++].b = b;
		}
   		for(k = 0; k < numPadBytes ; k++) 
		{//skip pad bytes at row's end
			fread(&dum, 1, 1, inf);
		}
	}
	fclose(inf);
	return 1; // success
}

void RGBpixmap :: setTexture(GLuint textureName)
{
	glBindTexture(GL_TEXTURE_2D,textureName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,nCols,nRows,0, GL_RGB,
               GL_UNSIGNED_BYTE, pixel);
}
/******************************************************************************************/
GLfloat mat_ambient[] = {0.7f,0.7f,0.7f,1.0f};
GLfloat mat_diffuse[] = {0.6f,0.6f,0.6f,1.0f};
GLfloat mat_specular[] = {1.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[] = {50.0f};

GLfloat mat1_ambient[] = {0.25,0.25,0.25,1.0f};
GLfloat mat1_diffuse[] = {0.4,0.4,0.4,1.0f};
GLfloat mat1_specular[] = {0.77,0.77,0.77,1.0f};
GLfloat mat1_shininess[] = {50.0f};

GLfloat mat3_ambient[] = {0.0,0.0,10.0,1.0f};
GLfloat mat3_diffuse[] = {0.2,0.2,0.2,1.0f};
GLfloat mat3_specular[] = {0.77,0.77,0.77,1.0f};
GLfloat mat3_shininess[] = {50.0f};

GLfloat mat_ambient1[] = {0.0,0.0,0.0,1.0f};
GLfloat mat_diffuse1[] = {0.01,0.01,0.01,1.0f};
GLfloat mat_specular1[] = {0.5,0.5,0.5,1.0f};
GLfloat mat_shininess1[] = {32.0f};

//Bronze
GLfloat mat_ambient3[] = {0.2125,0.1275,0.054,1.0f};
GLfloat mat_diffuse3[] = {0.714,0.4284,0.18144,1.0f};
GLfloat mat_specular3[] = {0.393548,0.271906,0.166721,1.0f};
GLfloat mat_shininess3[] = {25.6};

//Gold
GLfloat mat_ambient6[] = {0.24725,0.1995,0.0745,1.0f};
GLfloat mat_diffuse6[] = {0.75164,0.60648,0.22648,1.0f};
GLfloat mat_specular6[] = {0.628281,0.555802,0.366065,1.0f};
GLfloat mat_shininess6[] = {51.2};
//Pewter
GLfloat mat_ambient7[] = {0.10588,0.058824,0.113725,1.0f};
GLfloat mat_diffuse7[] = {0.427451,0.470588,0.541176,1.0f};
GLfloat mat_specular7[] = {0.3333,0.3333,0.521569,1.0f};
GLfloat mat_shininess7[] = {9.84615};

//Polished Silver
GLfloat mat_ambient9[] = {0.23125,0.23125,0.23125,1.0f};
GLfloat mat_diffuse9[] = {0.2775,0.2775,0.2775,1.0f};
GLfloat mat_specular9[] = {0.773911,0.773911,0.773911,1.0f};
GLfloat mat_shininess9[] = {89.6};

GLfloat mat_ambient10[] = {0.5,2,0.8,1.0f};
GLfloat mat_diffuse10[] = {0.50754,0.50754,0.50754,1.0f};
GLfloat mat_specular10[] = {0.508273,0.508273,0.508273,1.0f};
GLfloat mat_shininess10[] = {60.0f};

GLfloat mat_ambient40[] = {0.25f,0.25f,0.25f,1.0f};
GLfloat mat_diffuse40[] = {0,0,0.4f,1.0f};
GLfloat mat_specular40[] = {0.77f,0.77f,0.77f,1.0f};
GLfloat mat_shininess40[] = {90.0f};

GLfloat mat_ambient30[] = {0.19f,1.73f,0.02f,1.0f};
GLfloat mat_diffuse30[] = {0.70f,0.27f,0.08f,1.0f};
GLfloat mat_specular30[] = {0.25f,0.13f,0.08f,1.0f};
GLfloat mat_shininess30[] = {80.0f};


GLuint	base;				// Base Display List For The Font Set
GLfloat	rot;				// Used To Rotate The Text

GLvoid BuildFont()								// Build Our Bitmap Font
{
	GLYPHMETRICSFLOAT	gmf[256];						// Address Buffer For Font Storage
	HFONT	font;										// Windows Font ID

	base = glGenLists(256);								// Storage For 256 Characters

	font = CreateFont(	-12,							// Height Of Font
						0,								// Width Of Font
						0,								// Angle Of Escapement
						0,								// Orientation Angle
						FW_BOLD,						// Font Weight
						FALSE,							// Italic
						FALSE,							// Underline
						FALSE,							// Strikeout
						ANSI_CHARSET,					// Character Set Identifier
						OUT_TT_PRECIS,					// Output Precision
						CLIP_DEFAULT_PRECIS,			// Clipping Precision
						ANTIALIASED_QUALITY,			// Output Quality
						FF_MODERN,		// Family And Pitch
						"");					// Font Name

	SelectObject(wglGetCurrentDC(), font);							// Selects The Font We Created

	wglUseFontOutlines(	wglGetCurrentDC(),							// Select The Current DC
						0,								// Starting Character
						255,							// Number Of Display Lists To Build
						base,							// Starting Display Lists
						0.1f,							// Deviation From The True Outlines
						0.2f,							// Font Thickness In The Z Direction
						WGL_FONT_POLYGONS,				// Use Polygons, Not Lines
						gmf);							// Address Of Buffer To Recieve Data
}


GLvoid glPrint(char *text)								// Custom GL "Print" Routine
{
  if (text == NULL)										// If There's No Text
    return;												// Do Nothing

  glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
    glListBase(base);									// Sets The Base Character to 32
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
  glPopAttrib();										// Pops The Display List Bits
}
void readstr(FILE* f, char* string)
{
	do {
		fgets(string, 255, f);
	} while ((string[0] == '/') || (string[0] == '\n'));
}
void setupWorld()
{
	float x, y, z, u, v;
	int numtriangles;
	FILE *filein;
	char oneline[255];
	filein = fopen("world1.txt", "rt"); // File To Load World Data From

	readstr(filein, oneline);
	sscanf(oneline, "NUMPOLLIES %d\n", &numtriangles);
	//printf("%d",numtriangles);
	g_sector1.triangle = new TRIANGLE[numtriangles];
	g_sector1.numtriangles = numtriangles;
	for (int loop = 0; loop < numtriangles; loop++) {
		for (int vert = 0; vert < 4; vert++) {
			readstr(filein, oneline);
			sscanf(oneline, "%f %f %f %f %f %f %f", &x, &y, &z, &u, &v);
			g_sector1.triangle[loop].vertex[vert].x = x;
			g_sector1.triangle[loop].vertex[vert].y = y;
			g_sector1.triangle[loop].vertex[vert].z = z;
			g_sector1.triangle[loop].vertex[vert].u = u;
			g_sector1.triangle[loop].vertex[vert].v = v;
		}
	}
	fclose(filein);
	return;
}
void myTextureCube(float length)
{
	glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-length/2.0, -length/2.0,  length/2.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( length/2.0, -length/2.0,  length/2.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( length/2.0,  length/2.0,  length/2.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(length/2.0,  length/2.0,  length/2.0);
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-length/2.0, -length/2.0, -length/2.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-length/2.0,  length/2.0, -length/2.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( length/2.0,  length/2.0, -length/2.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( length/2.0, -length/2.0, -length/2.0);
		// Top Face
		glTexCoord2f(0.0, 0.0); glVertex3f(-length/2.0, length/2.0, -length/2.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-length/2.0, length/2.0,  length/2.0);
		glTexCoord2f(1.0, 1.0); glVertex3f( length/2.0, length/2.0,  length/2.0);
		glTexCoord2f(1.0, 0.0); glVertex3f( length/2.0, length/2.0, -length/2.0);
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-length/2.0, -length/2.0, -length/2.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( length/2.0, -length/2.0, -length/2.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( length/2.0, -length/2.0,  length/2.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-length/2.0, -length/2.0,  length/2.0);
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( length/2.0, -length/2.0, -length/2.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( length/2.0,  length/2.0, -length/2.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( length/2.0,  length/2.0,  length/2.0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( length/2.0, -length/2.0,  length/2.0);
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-length/2.0, -length/2.0, -length/2.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-length/2.0, -length/2.0,  length/2.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-length/2.0,  length/2.0,  length/2.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-length/2.0,  length/2.0, -length/2.0);
	glEnd();
}
// Our GL Specific Initializations. Returns true On Success, false On Fail.


void wall(double thickness)
{
	glPushMatrix();
	glTranslated(0.5,0.5*thickness,0.5);
	glScaled(1.0,thickness,1.0);
	glutSolidCube(1.0);
//	myTextureCube(1.0);
	glPopMatrix();
}
//<<<<<<<<<<<<<<<<<<< jack part >>>>>>>>>>>>>>
void jackPart()
{
	glPushMatrix();
		glScaled(0.2,0.2,1.0);
		glutSolidSphere(1,15,15);
	glPopMatrix();
	glPushMatrix();
		glTranslated(0,0,1.2);
		glutSolidSphere(0.2,15,15);
		glTranslated(0,0,-2.4);
		glutSolidSphere(0.2,15,15);
	glPopMatrix();
}
//<<<<<<<<<<<<<<<<<<< jack >>>>>>>>>>>>>>
void jack()
{
	glPushMatrix();
		jackPart();
		glRotated(90.0,0,1,0);
		jackPart();
		glRotated(90.0,1,0,0);
		jackPart();
	glPopMatrix();
}
//<<<<<<<<<<<<<<<<<<< car wheel >>>>>>>>>>>>>>
void wheel()
{
		glPushMatrix();
			glScaled(0.08,0.08,0.08);
			jack();
		glPopMatrix();
		glPushMatrix();
			glScaled(0.3,0.3,0.3);
			glutSolidTorus(0.1, 0.3, 100,100);
		glPopMatrix();
}

void car(void)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	GLfloat lightIntensity[] = {0.7f,0.7f,0.7f,1.0f};
	GLfloat light_position[] = {2.0f,6.0f,3.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	glPushMatrix();
		glTranslated(-0.5,0,-0.5);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat3_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat3_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat3_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat3_shininess);
	glPushMatrix();
		glTranslated(0.5,0.175,0.42);
		glScaled(1.0,0.05,0.5);
		myTextureCube(1.0);
	glPopMatrix();

	glMaterialfv(GL_FRONT,GL_AMBIENT,mat1_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat1_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat1_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat1_shininess);
	
	glPushMatrix();
		glTranslated(0.1,0.14,0.735);
		glRotated(wheelRotateAngle,0,0,1);
		wheel();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0.8,0.14,0.735);
		glRotated(wheelRotateAngle,0,0,1);
		wheel();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0.1,0.14,0.1);
		glRotated(wheelRotateAngle,0,0,1);
		wheel();
	glPopMatrix();
	glPushMatrix();
		glTranslated(0.8,0.14,0.1);
		glRotated(wheelRotateAngle,0,0,1);
		wheel();
	glPopMatrix();
	glPopMatrix();
	glFlush();
}
void spin(void)
{
	wheelRotateAngle += 20.0;
	if (wheelRotateAngle >= 360.0)
		wheelRotateAngle = 0.0;

}
void light(void)
{
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	

	GLfloat mat_ambient[] = {0.1f,0.8f,0.6f,1.0f};//周圍光
	GLfloat mat_diffuse[] = {0.2f,0.3f,0.2f,1.0f};//反射光
	GLfloat mat_specular[] = {0.1f,0.1f,0.3f,1.0f};//鏡射光
	GLfloat mat_shininess[] = {110.0f};// 0~128 光的強度
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	GLfloat lightIntensity[] = {1,1,1,1.0f};
	GLfloat light_position[] = {1.0f,1.0f,1.0f,0};//光源位置
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);

	GLfloat light_position1[] = {0.0f,0.85f,0.0f,1.0f};//光源位置
	GLfloat light_ambient1[] = {1.0,1.0,0.0,1.0f};
	GLfloat light_diffuse1[] = {1.0,1.0,0.0,1.0f};
	GLfloat light_specular1[] = {1.0,1.0,0.0,1.0f};
	GLfloat light_spotdirection1[] = {0.0,-0.85,0.0};
	GLfloat light_spotexponent1[] = {0.5};//0~128
	GLfloat light_spotcutoff1[] = {80.0};//0~90,180 : no cutoff

	glLightfv(GL_LIGHT1,GL_POSITION,light_position1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,light_diffuse1);
	glLightfv(GL_LIGHT1,GL_AMBIENT,light_ambient1);
	glLightfv(GL_LIGHT1,GL_SPECULAR,light_specular1);
	//////	3	/////////
	glLightfv(GL_LIGHT1,GL_SPOT_DIRECTION,light_spotdirection1);
	glLightfv(GL_LIGHT1,GL_SPOT_EXPONENT,light_spotexponent1);
	glLightfv(GL_LIGHT1,GL_SPOT_CUTOFF,light_spotcutoff1);
	//////	3	/////////

    GLUquadricObj * qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj,GLU_FILL);

//物體顏色	


    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient40);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse40);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular40);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess40);
	glPushMatrix();
		glRotated(-90.0, 1, 0,0);
		gluCylinder(qobj, 0.02, 0.02, 0.7, 30,30);// 8.2燈柱
	glPopMatrix();


	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient30);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse30);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular30);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess30);
	glPushMatrix();
		glTranslated(0,0.5,0);	
		glRotated(-90,1,0,0);
		gluCylinder(qobj, 0.35, 0.05, 0.3, 50,50);// 8.2燈罩
	glPopMatrix();
	glFlush();

}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
	float ori_xpos=x_car,ori_zpos=z_car;
  switch(theKey)
  {
		case	'o':
			turnOn = !turnOn;
			  break;
		case	'd':
			y_car -= 5.0f;
			break;
		case	'a':
			y_car += 5.0f;
			break;
		case	'w':
			x_car -= (float)sin(y_car*PI_OVER_180) * 0.2f;
			z_car -= (float)cos(y_car*PI_OVER_180) * 0.2f;
			break;
		case	's':
			x_car += (float)sin(y_car*PI_OVER_180) * 0.2f;
			z_car += (float)cos(y_car*PI_OVER_180) * 0.2f;
			break;
	  	default: 
			break;		      // do nothing

	}
  	if (((ori_xpos<5.0)&&(ori_xpos>-5.0)&&((5.0-ori_zpos)*(5.0-z_car)<0.0))
		||((ori_xpos<5.0)&&(ori_xpos>-5.0)&&((-5.0-ori_zpos)*(-5.0-z_car)<0.0))
		||((ori_zpos<5.0)&&(ori_zpos>-5.0)&&((5.0-ori_xpos)*(5.0-x_car)<0.0))
		||((ori_zpos<5.0)&&(ori_zpos>-5.0)&&((-5.0-ori_xpos)*(-5.0-x_car)<0.0))
		||((ori_xpos<3.0)&&(ori_xpos>-3.0)&&((3.0-ori_zpos)*(3.0-z_car)<0.0))
		||((ori_xpos<0.0)&&(ori_xpos>-3.0)&&(((0.3333*ori_xpos-2)-ori_zpos)*((0.3333*x_car-2.0)-z_car)<0.0))
		||((ori_xpos<3.0)&&(ori_xpos>1.0)&&(((0.3333*ori_xpos-2)-ori_zpos)*((0.3333*x_car-2)-z_car)<0.0))
		||((ori_zpos<3.0)&&(ori_zpos>-3.0)&&((-3.0-ori_xpos)*(-3.0-x_car)<0.0))
		||((ori_zpos<3.0)&&(ori_zpos>-1.0)&&((3.0-ori_xpos)*(3.0-x_car)<0.0)))
	{
	  switch(theKey)
	  {

			case	'w':
				x_car += (float)sin(y_car*PI_OVER_180) * 0.5f;
				z_car += (float)cos(y_car*PI_OVER_180) * 0.5f;
				break;
			case	's':
				x_car -= (float)sin(y_car*PI_OVER_180) * 0.5f;
				z_car -= (float)cos(y_car*PI_OVER_180) * 0.5f;
				break;
	  		default: 
				break;		      // do nothing

		}
	}
  if(theKey=='d'||theKey=='s'||theKey=='a'||theKey=='w')
    car_on=true;
  else if(theKey=='c')
	car_on=false;

}
void init(void)
{


    glClearColor(1.0f,1.0f,1.0f,0.0f);       // set white background color
	
	GLfloat lightIntensity[] = {0.7f,0.7f,0.7f,1.0f};
	GLfloat light_position[] = {4.0f,3.0f,-3.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	glMatrixMode(GL_PROJECTION);

	pix[0].readBMPFile("img/fi_paper.bmp");  // make pixmap from image
	pix[1].readBMPFile("img/brick01.bmp");
	pix[2].readBMPFile("img/ground01.bmp");
	pix[3].readBMPFile("img/sky03.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	pix[0].setTexture(2002);		// create texture
	pix[1].setTexture(2003);
	pix[2].setTexture(2004);
	pix[3].setTexture(2005);

	BuildFont();
	
    glEnable(GL_DEPTH_TEST);						   // Enables Depth Testing
    glShadeModel(GL_SMOOTH);						   // Enable Smooth Shading
    
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	setupWorld();

	glFogi(GL_FOG_MODE, GL_LINEAR);       // Fog Mode
	glFogfv(GL_FOG_COLOR, g_fogColor);                 // Set Fog Color
	glFogf(GL_FOG_DENSITY, 0.35f);                     // How Dense Will The Fog Be
	glFogf(GL_FOG_START, 1.0f);                        // Fog Start Depth
	glFogf(GL_FOG_END, 6.0f);                          // Fog End Depth

	quadratic=gluNewQuadric();									// Create A Pointer To The Quadric Object
	gluQuadricNormals(quadratic, GLU_SMOOTH);					// Create Smooth Normals 
	gluQuadricTexture(quadratic, GL_TRUE);						// Create Texture Coords 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glColor4f(1.0f, 1.0f, 1.0f, 0.5);					// Full Brightness.  50% Alpha
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);					// Set The Blending Function For Translucency
	memset(g_key, 0, sizeof(g_key)); 
}
void render(void)   
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	glLoadIdentity();									// Reset The View

	GLfloat x_m, y_m, z_m, u_m, v_m;

	int numtriangles;

	glRotatef(-g_lookupdown,1.0f,0,0);
	glRotatef(-g_yrot,0,1.0f,0);
	

	glTranslatef(-g_xpos, -0.55-g_walkbias, -g_zpos);

	
	numtriangles = g_sector1.numtriangles;

	// Process Each Triangle
	for (int loop_m = 0; loop_m < numtriangles; loop_m++)
	{
		glEnable(GL_TEXTURE_2D);                           // Enable Texture Mapping 
		if(loop_m == 0)
			glBindTexture(GL_TEXTURE_2D, 2004);

		else if(loop_m ==1){
			glBindTexture(GL_TEXTURE_2D, 2005);
			glEnable(GL_FOG);
		}
		else if(loop_m >=2  && loop_m <= 5)
			glBindTexture(GL_TEXTURE_2D, 2004);
		else if(loop_m == 6)
			glBindTexture(GL_TEXTURE_2D, 2002);
		else 
			glBindTexture(GL_TEXTURE_2D, 2003);
		glBegin(GL_QUADS);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			x_m = g_sector1.triangle[loop_m].vertex[0].x;
			y_m = g_sector1.triangle[loop_m].vertex[0].y;
			z_m = g_sector1.triangle[loop_m].vertex[0].z;
			u_m = g_sector1.triangle[loop_m].vertex[0].u;
			v_m = g_sector1.triangle[loop_m].vertex[0].v;
			glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);
			
			x_m = g_sector1.triangle[loop_m].vertex[1].x;
			y_m = g_sector1.triangle[loop_m].vertex[1].y;
			z_m = g_sector1.triangle[loop_m].vertex[1].z;
			u_m = g_sector1.triangle[loop_m].vertex[1].u;
			v_m = g_sector1.triangle[loop_m].vertex[1].v;
			glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);
			
			x_m = g_sector1.triangle[loop_m].vertex[2].x;
			y_m = g_sector1.triangle[loop_m].vertex[2].y;
			z_m = g_sector1.triangle[loop_m].vertex[2].z;
			u_m = g_sector1.triangle[loop_m].vertex[2].u;
			v_m = g_sector1.triangle[loop_m].vertex[2].v;
			glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);

			x_m = g_sector1.triangle[loop_m].vertex[3].x;
			y_m = g_sector1.triangle[loop_m].vertex[3].y;
			z_m = g_sector1.triangle[loop_m].vertex[3].z;
			u_m = g_sector1.triangle[loop_m].vertex[3].u;
			v_m = g_sector1.triangle[loop_m].vertex[3].v;
			glTexCoord2f(u_m,v_m); glVertex3f(x_m,y_m,z_m);
		glEnd();
		glFlush();
		if(loop_m == 5)	
			glDisable(GL_FOG);                                  // Enables GL_FOG
	}
		

	glPushMatrix();
		glEnable(GL_FOG);
		glBindTexture(GL_TEXTURE_2D, 2005);			// Turn Blending On
		glTranslated(1,0,2);
		glScalef(0.8,0.8,0.8);
		gluSphere(quadratic,1.3f,50,50);
		glDisable(GL_FOG);
	glPopMatrix();
    
		
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient7);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse7);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular7);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess7);
	glPushMatrix();
	glEnable(GL_FOG);
		glTranslated(1.2,1.05,-1.7);
		glRotated(160,0,1,0);
		glScalef(0.3,0.3,0.3);
		glPrint("Jzx's House");	
	glDisable(GL_FOG);
	glPopMatrix();
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient10);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse10);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular10);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess10);
	glPushMatrix();
		glTranslated(1.25,1.32,-1.45);
		glRotated(160,0,1,0);
		glRotated(90,1,0,0);
		glScalef(2.0,1.0,0.3);
		wall(0.1);
	glPopMatrix();
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++){
		glPushMatrix();
			glTranslated(-0.1+i*0.2,1.0,0.1+j*0.2);
			glRotated(180,1,0,0);
			glScalef(0.2,0.2,0.2);
			light();
		glPopMatrix();
	}

	glPushMatrix();
		glTranslated(-1,0.0,1);
		car();	
		glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient30);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse30);
		glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular30);
		glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess30);
		glTranslated(0,0.4,-0.1);
		glScalef(0.3,0.4,0.3);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-1,0.0,-1.0);
		car();	
		glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient30);
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse30);
		glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular30);
		glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess30);
		glTranslated(0,0.4,-0.1);
		glScalef(0.3,0.4,0.3);
		glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslated(x_car,0.0,z_car);
		glScalef(0.5,0.5,0.5);
		glRotatef(y_car,0,1.0f,0);
		
		glRotatef(90,0,1.0f,0);
		car();
		glTranslated(0.0,0.3,-0.1);
		glRotatef(45,0.0f,0.0f,1.0f);
		glRotatef(90,1.0f,0.0f,0.0f);
		glScalef(0.2,1.8,0.2);
		gluCylinder(quadratic, 0.2, 0.2, 0.7, 30,30);
	glPopMatrix();
    // Swap The Buffers To Become Our Rendering Visible
    glutSwapBuffers();
}

// Our Reshaping Handler (Required Even In Fullscreen-Only Modes)
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);     // Select The Projection Matrix
	glLoadIdentity();                // Reset The Projection Matrix
	// Calculate The Aspect Ratio And Set The Clipping Volume
	if (h == 0) h = 1;
	gluPerspective(45.0f, (float)w/(float)h, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix
	glLoadIdentity(); // Reset The Modelview Matrix
}
void special_keys(int a_keys, int x, int y)
{
			g_key[a_keys] = true;
}

// Our Keyboard Handler For Special Key Releases.
void special_keys_up(int key, int x, int y)
{
	g_key[key] = false;
}

void idle_function()
{
	float ori_xpos=g_xpos,ori_zpos=g_zpos;
	// Process User Input
	if(car_on)
		spin();
	if (g_key[GLUT_KEY_PAGE_UP]) {
		g_lookupdown += 1.0f;
	}
	if (g_key[GLUT_KEY_PAGE_DOWN]) {
		g_lookupdown -= 1.0f;
	}
	if (g_key[GLUT_KEY_UP]) {
		g_xpos -= (float)sin(g_yrot*PI_OVER_180) * 0.1f;
		g_zpos -= (float)cos(g_yrot*PI_OVER_180) * 0.1f;
		if (g_walkbiasangle >= 359.0f) g_walkbiasangle = 0.0f;
		else g_walkbiasangle += 30;
		g_walkbias = (float)sin(g_walkbiasangle*PI_OVER_180) / 20.0f;

	}
	if (g_key[GLUT_KEY_DOWN]) {
		g_xpos += (float)sin(g_yrot*PI_OVER_180) * 0.1f;
		g_zpos += (float)cos(g_yrot*PI_OVER_180) * 0.1f;
		if (g_walkbiasangle <= 1.0f) g_walkbiasangle = 359.0f;
		else g_walkbiasangle -= 30;
		g_walkbias = (float)sin(g_walkbiasangle*PI_OVER_180) / 20.0f;

	}
	if (((ori_xpos<5.0)&&(ori_xpos>-5.0)&&((5.0-ori_zpos)*(5.0-g_zpos)<0.0))
		||((ori_xpos<5.0)&&(ori_xpos>-5.0)&&((-5.0-ori_zpos)*(-5.0-g_zpos)<0.0))
		||((ori_zpos<5.0)&&(ori_zpos>-5.0)&&((5.0-ori_xpos)*(5.0-g_xpos)<0.0))
		||((ori_zpos<5.0)&&(ori_zpos>-5.0)&&((-5.0-ori_xpos)*(-5.0-g_xpos)<0.0))
		||((ori_xpos<3.0)&&(ori_xpos>-3.0)&&((3.0-ori_zpos)*(3.0-g_zpos)<0.0))
		||((ori_xpos<0.0)&&(ori_xpos>-3.0)&&(((0.3333*ori_xpos-2)-ori_zpos)*((0.3333*g_xpos-2.0)-g_zpos)<0.0))
		||((ori_xpos<3.0)&&(ori_xpos>1.0)&&(((0.3333*ori_xpos-2)-ori_zpos)*((0.3333*g_xpos-2)-g_zpos)<0.0))
		||((ori_zpos<3.0)&&(ori_zpos>-3.0)&&((-3.0-ori_xpos)*(-3.0-g_xpos)<0.0))
		||((ori_zpos<3.0)&&(ori_zpos>-1.0)&&((3.0-ori_xpos)*(3.0-g_xpos)<0.0)))
	{

		if (g_key[GLUT_KEY_UP]) {
			g_xpos += (float)sin(g_yrot*PI_OVER_180) * 0.3f;
			g_zpos += (float)cos(g_yrot*PI_OVER_180) * 0.3f;
			if (g_walkbiasangle >= 359.0f) g_walkbiasangle = 0.0f;
			else g_walkbiasangle += 30;
			g_walkbias = (float)sin(g_walkbiasangle*PI_OVER_180) / 20.0f;
		}
		if (g_key[GLUT_KEY_DOWN]) {
			g_xpos -= (float)sin(g_yrot*PI_OVER_180) * 0.3f;
			g_zpos -= (float)cos(g_yrot*PI_OVER_180) * 0.3f;
			if (g_walkbiasangle <= 1.0f) g_walkbiasangle = 359.0f;
			else g_walkbiasangle -= 30;
			g_walkbias = (float)sin(g_walkbiasangle*PI_OVER_180) / 20.0f;
		}
	}
	if (g_key[GLUT_KEY_RIGHT]) {
		g_yrot -= 1.0f;
	}
	if (g_key[GLUT_KEY_LEFT]) {
		g_yrot += 1.0f;
	}

	if (turnOn == true)
		glEnable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT1);

	// Do The Rendering
	render();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);                           // GLUT Initializtion
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE); // (CHANGED)
	glutInitWindowSize(500, 500);                // Window Size If We Start In Windowed Mode
	glutCreateWindow("MyHouse Demo"); // Window Title 
	init();
	glutDisplayFunc(render);                         // Register The Display Function
	glutReshapeFunc(reshape);                        // Register The Reshape Handler
	glutSpecialFunc(special_keys);                   // Register Special Keys Handler
	glutSpecialUpFunc(special_keys_up);              // Called When A Special Key Released (NEW)
	glutIdleFunc(idle_function);                     // Process User Input And Does Rendering (CHANGED)
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();                                  // Go To GLUT Main Loop
	return 0;
}