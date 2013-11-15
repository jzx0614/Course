#include <gl/glut.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

const char *c_button={"0X/=123-456+789C"};
int count=0,len_count=0,e_count=0;
int model=1,flag;

char outshow[15];
char len[4],edge[4];
float p=0,t=1;

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

RGBpixmap pix[3];    // make  (empty) pixmap
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
/*=======================================================================================================*/
class buff_num
{
	public:
		double num1,num2;
		char sign;
}b_num;

void printstring(int x,int y)
{
	glColor3f(1.0,1.0,1.0);
	glRecti(110,300,285,330);
	
	glColor3f(0.0,0.0,0.0);
	glRasterPos2f(x,y);	
	for(int i=0;i<strlen(outshow);i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,outshow[i]);	
	}
}

void DrawButton(void)
{	
	glColor3f(0.5,0.5,0.5);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
				glBegin(GL_POLYGON);
					glColor3f(0.7,0.7,0.7);
					glVertex2f(110+45*i, 110+45*j);
					glVertex2f(110+45*i, 140+45*j);
					glColor3f(0.5,0.5,0.5);
					glVertex2f(150+45*i, 140+45*j);
					glVertex2f(150+45*i, 110+45*j);
				glEnd();

			glColor3f(0.0,0.0,0.0);

			glRasterPos2f(128+45*i,118+45*j);
			glutBitmapCharacter(GLUT_BITMAP_9_BY_15,c_button[i+j*4]);
		}
}
void Drawabacus(void)
{	
	glBegin(GL_POLYGON);
		glColor3f(0.5,0.7,0.7);
		glVertex2f(100, 100);
		glColor3f(0.0,0.0,0.6);
		glVertex2f(100, 350);
		glColor3f(1,0.2,0.5);
		glVertex2f(295, 350);
		glColor3f(1,1,0.5);
		glVertex2f(295, 100);
	glEnd();
	

	glColor3f(1.0,1.0,1.0);
	glRecti(110,300,285,330);

	DrawButton();
}

void DrawTitle()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,2003);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(10.0, 440.0);
		glTexCoord2f(3.125f, 0.0f); glVertex2f(790.0, 440.0);
		glTexCoord2f(3.125f, 3.75f); glVertex2f(790.0, 480.0);
		glTexCoord2f(0.0f, 3.75f); glVertex2f(10.0, 480.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	char buff[]={"C09102014 Chih-Syaun Jian"};
	glColor3f(0.0,0.5,0.0);
	glRasterPos2f(10+p,450);
	for(int i=0;i<strlen(buff);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,buff[i]);

	glFlush();
	glutSwapBuffers();
}
void DrawBackGround(void)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,2002);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0, 0.0);
		glTexCoord2f(3.125f, 0.0f); glVertex2f(800.0, 0.0);
		glTexCoord2f(3.125f, 3.75f); glVertex2f(800.0, 480.0);
		glTexCoord2f(0.0f, 3.75f); glVertex2f(0.0, 480.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void DrawInput(void)
{
	char buff1[]={"Width:        Length:             OK!"};
	glColor3f(1.0f,1.0f,1.0f);
	glRecti(460,380,500,400);

	glColor3f(1.0f,1.0f,1.0f);
	glRecti(590,380,630,400);

	glColor3f(0.7f,0.7f,0.7f);
	glRecti(700,380,740,400);

	glColor3f(0.3,0.3,0.4);
	glRasterPos2f(400,383);
	for(int i=0;i<strlen(buff1);i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,buff1[i]);
}
void search(char thekey){
	if('0'<=thekey&&thekey<='9')
	{	
		outshow[count++]=thekey;
		printstring(280-strlen(outshow)*9,310);

		if(((thekey=='0')&&(count==1))) count--;
	}
	else
	{
		
		b_num.num2=atof(outshow);
		if(b_num.num2!='\0'){
			switch(b_num.sign){
				case '+':	b_num.num1+=b_num.num2; break;
				case '-':	b_num.num1-=b_num.num2; break;
				case 'X':	b_num.num1*=b_num.num2; break;
				case '/':	b_num.num1/=b_num.num2; break;
				default:				break;
			}
		}
		count=0;
		if(thekey=='C'){
			b_num.num1=0;
			b_num.sign='+';
		}
		else if(thekey!='=')
			b_num.sign=thekey;
		sprintf(outshow,"%.2lf",b_num.num1);
		printstring(280-strlen(outshow)*9,310);
		memset(outshow,'\0',sizeof(outshow));
	}

}
void DrawEllipse(double height, double width)
{
	int n=500;
	//if(n<3) return ; //bad number of sides
	double angle = 3.14159265 / 2; //initial angle
	double angleInc = 2 * 3.14159265 / n;  //angle increment
	float xx=544,yy=220;
	
	glColor3f(0.8f,0.9f,0.9f);
	glRecti(344,70,744,370);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,2004);
	glBegin(GL_POLYGON);
	for(int k=0; k<n; k++) //repeat n times
	{
		angle += angleInc;
		glTexCoord2f(cos(angle)*0.5+0.5,sin(angle)*0.5+0.5);
		glVertex2f( cos(angle)*width + xx, sin(angle)*height + yy);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glFlush();

}
void myInit(void)
{
	glClearColor(0.8f,0.9f,0.9f,0.0f);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	gluOrtho2D(0.0,800.0,0.0,480.0);
	b_num.num1=0;
	b_num.sign='+';

	glEnable(GL_TEXTURE_2D);
	pix[0].readBMPFile("um.bmp");  // make pixmap from image
	pix[1].readBMPFile("bk175.bmp");
	pix[2].readBMPFile("test.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	pix[0].setTexture(2002);		// create texture
	pix[1].setTexture(2003);		// create texture
	pix[2].setTexture(2004);		// create texture
}
void myDisplay(void)
{	

	glClear(GL_COLOR_BUFFER_BIT);

	DrawBackGround();
	DrawEllipse(100,100);
	DrawTitle();
	DrawInput();
	Drawabacus();
	
	glFlush();

}
void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{	
	if(model==1){
		if(theKey==13) theKey='=';
		if(count<15){
			for(int i=0;i<strlen(c_button);i++)
				if(theKey==c_button[i])
					search(c_button[i]);
		}
		else count=14;
	}
	else if(model==2)
	{	
		glColor3f(0.0,0.0,0.0);
		if('0'<=theKey&&theKey<='9'){
			if(flag==1){
				if(e_count<3){
					edge[e_count++]=theKey;
					glRasterPos2f(465,385);
					for(int i=0;i<strlen(edge);i++)
						glutBitmapCharacter(GLUT_BITMAP_9_BY_15,edge[i]);
				}
			}
			else if (flag==2){
				if(len_count<3){
					len[len_count++]=theKey;
					glRasterPos2f(595,385);
					for(int i=0;i<strlen(len);i++)
						glutBitmapCharacter(GLUT_BITMAP_9_BY_15,len[i]);
				}
			}			
		}
	}
}
void myMouse(int button,int  state,int x,int y)
{
	
	if(button == GLUT_LEFT_BUTTON && state ==GLUT_DOWN){
		y=480-y;
		if(x<=344) {
			glutSetCursor(GLUT_CURSOR_HELP); 
			model=1;
		}
		else{
			model=2;
			if((460<=x&&x<=500)&&(380<=y&&y<=400))
			{
				glutSetCursor(GLUT_CURSOR_TEXT);
				flag=1;
			}
			else if((590<=x&&x<=630)&&(380<=y&&y<=400))			
			{
				glutSetCursor(GLUT_CURSOR_TEXT);
				flag=2;
			}
			else if((700<=x&&x<=740)&&(380<=y&&y<=400))
			{
				double t_len=atof(len);
				double t_edge=atoi(edge);
				if(t_len>=200) t_len=200;
				if(t_edge>=150) t_edge=150;
				DrawEllipse(t_edge,t_len);
				len_count=0;e_count=0;
				memset(len,0,sizeof(len));
				memset(edge,0,sizeof(edge));
				DrawInput();
			}
		}
		if(count<15){
			for(int i=0;i<4;i++)
				if((110+(45*i)<=x)&&(x<=150+(45*i)))
					for(int j=0;j<4;j++)
						if((110+45*j<=y)&&(y<=140+45*j)){
							glutSetCursor(GLUT_CURSOR_WAIT);
							search(c_button[i+j*4]);
						}
		
		}
		else count=14;

	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}
	glFlush();
}
void idleFun()
{
	DrawTitle();
	if ((p >= 490.0)||(p<0))
		t=-t;
	p += t; 
}
void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,480);
	glutInitWindowPosition(150,150);
	glutCreateWindow("My homework");

	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(myDisplay);
	glutIdleFunc(idleFun);
	
	myInit();
	glutMainLoop();
}