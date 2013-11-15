//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "jpeg.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const double YUVToRGB[3][3]={{0.299, 0.587, 0.114},
                              {-0.147,-0.289, 0.436},
                              { 0.615,-0.515,-0.100}};
const double YIQToRGB[3][3]={{0.299, 0.587, 0.114},
                              {0.596,-0.274,-0.322},
                              {0.211,-0.522, 0.311}};
const double RGBToYUV[3][3]={{1.0, 0.0  , 1.140},
                              { 1.0,-0.395,-0.581},
                              { 1.0, 2.032, 0.0}};
const double RGBToYIQ[3][3]={{1.0, 0.956, 0.621},
                              { 1.0,-0.272,-0.649},
                              { 1.0,-1.106, 1.703}};
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TForm1::OpenImage(int type)
{
        map = new Graphics::TBitmap();
        graylevel= new Graphics::TBitmap();

        if (type == 1) {
                OpenPictureDialog1->FilterIndex = 2;
                if (OpenPictureDialog1->Execute()) {
                        TJPEGImage *JImage= new TJPEGImage;
                        // load jpeg from OpenDialog
                        JImage->LoadFromFile(OpenPictureDialog1->FileName);
                        //Image1->Picture->Bitmap->Assign(JImage);
                        map->Assign(JImage);
                }
        } else {
                OpenPictureDialog1->FilterIndex = 4;
                if (OpenPictureDialog1->Execute())
                        //Image1->Picture->Bitmap->LoadFromFile(OpenPictureDialog1->FileName);
                        map->LoadFromFile(OpenPictureDialog1->FileName);
        }
        Image1->Picture->Bitmap=map;
        graylevel->Width = map->Width;
        graylevel->Height= map->Height;
        for(int x=0;x<map->Width;x++)
        for(int y=0;y<map->Height;y++){
                int r=GetRValue(map->Canvas->Pixels[x][y]);
                int g=GetGValue(map->Canvas->Pixels[x][y]);
                int b=GetBValue(map->Canvas->Pixels[x][y]);
                int gray=0.299*r+0.587*g+0.114*b;
                //int gray=(r+g+b)/3;
                graylevel->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }

        Image2->Visible=false;
        Image2->Left=Image1->Width+18;

        Form1->Width=Image1->Width*2+36;
        Form1->Left=(1024- Form1->Width)/2;
        Form1->Height=Image1->Height+Image1->Top+29+50;
        if(Form1->Width>1024){
                Form1->Width=1024;
                Form1->Left=0;
        }
        Button2->Enabled=true;
        Button3->Enabled=true;
        Button4->Enabled=true;
        Button5->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Image2->Visible=true;
        Image2->Picture->Bitmap=graylevel;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
       Image1->Picture->Bitmap=map;
       Image2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BMPClick(TObject *Sender)
{
        OpenImage(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::JPEGClick(TObject *Sender)
{
        OpenImage(1);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
        exit(1);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        TVarRec pos[2]={X,Y};
        int r=GetRValue(Image1->Canvas->Pixels[X][Y]);
        int g=GetGValue(Image1->Canvas->Pixels[X][Y]);
        int b=GetBValue(Image1->Canvas->Pixels[X][Y]);
        TVarRec color[3]={r,g,b};
        StatusBar1->Panels->Items[0]->Text=Format(" Image1 ¦ì¸m :( %d , %d )",pos,2)+
                                           Format(" RGB :( %d , %d , %d )",color,3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        TVarRec pos[2]={X,Y};
        int r=GetRValue(Image2->Canvas->Pixels[X][Y]);
        int g=GetGValue(Image2->Canvas->Pixels[X][Y]);
        int b=GetBValue(Image2->Canvas->Pixels[X][Y]);
        TVarRec color[3]={r,g,b};
        StatusBar1->Panels->Items[1]->Text=Format(" Image2 ¦ì¸m :( %d , %d )",pos,2)+
                                           Format(" RGB :( %d , %d , %d )",color,3);

}
//---------------------------------------------------------------------------
double* TForm1::RtoY(double *color,int type)
{
        double *Y=new double[3];
        memset(Y,0,sizeof(double[3]));

        double temp[3][3];
        switch(type){
                case 0: memcpy(temp,YUVToRGB,sizeof(double[3][3])); break;
                case 1: memcpy(temp,YIQToRGB,sizeof(double[3][3])); break;
        }

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                Y[i]+=temp[i][j]*color[j];
        return Y;
}

double* TForm1::YtoR(double *Y,int type)
{

        double temp[3][3];
        switch(type){
                case 0: memcpy(temp,RGBToYUV,sizeof(double[3][3])); break;
                case 1: memcpy(temp,RGBToYIQ,sizeof(double[3][3])); break;
        }
        double *color=new double[3];
        memset(color,0,sizeof(double[3]));

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                color[i]+=temp[i][j]*Y[j];
        return color;
}

double* TForm1::Quantization(double *color,double *N)
{
        double *result=new double[3];
        memset(result,0,sizeof(double[3]));
        for(int i=0;i<3;i++)
                result[i]=N[i]*(int)(color[i]/N[i])+N[i]/2;
        return result;
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        int flag=StrToInt(Edit1->Text);
        if(Image2->Visible==false){
                Image2->Visible=true;
                Image2->Picture->Bitmap=graylevel;
        }
        TrackBar1Update();
        Image1->Picture->Bitmap=graylevel;
        for(int x=0;x<graylevel->Width;x++)
        for(int y=0;y<graylevel->Height;y++){
                double *buff=new double[3];
                double *N=new double[3];
                N[0]=N[1]=N[2]=256/flag;
                buff[0]=GetGValue(graylevel->Canvas->Pixels[x][y]);
                buff[1]=buff[2]=buff[0];
                buff=Quantization(buff,N);
                Image1->Canvas->Pixels[x][y]=(TColor)RGB(buff[0],buff[1],buff[2]);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        int flag=StrToInt(Edit1->Text);
        TrackBar1Update();
        Image1->Picture->Bitmap=map;
        Image2->Visible=true;
        Image2->Picture->Bitmap=map;
        for(int x=0;x<map->Width;x++)
        for(int y=0;y<map->Height;y++){
                double *buff=new double[3];
                double *N=new double[3];
                buff[0]=GetRValue(map->Canvas->Pixels[x][y]);
                buff[1]=GetGValue(map->Canvas->Pixels[x][y]);
                buff[2]=GetBValue(map->Canvas->Pixels[x][y]);

                if(ComboBox1->Text=="RGB"){
                                N[0]=N[1]=N[2]=256/flag;
                                buff=Quantization(buff,N);
                }
                else if(ComboBox1->Text=="YUV"){
                                buff=RtoY(buff,0);
                                buff[1]+=(222.36/2);
                                buff[2]+=(313.65/2);
                                N[0]=256/flag;
                                N[1]=222.36/flag;
                                N[2]=313.65/flag;
                                buff[1]-=(222.36/2);
                                buff[2]-=(313.65/2);
                                buff=Quantization(buff,N);
                                buff=YtoR(buff,0);
                }
                else if(ComboBox1->Text=="YIQ"){
                                buff=RtoY(buff,1);
                                buff[1]+=(303.96/2);
                                buff[2]+=(266.22/2);
                                N[0]=256/flag;
                                N[1]=303.96/flag;
                                N[2]=266.22/flag;
                                buff[1]-=(303.96/2);
                                buff[2]-=(266.22/2);
                                buff=Quantization(buff,N);
                                buff=YtoR(buff,1);
                }
                for(int i=0;i<3;i++){
                        if(buff[i]>255)        buff[i]=255;
                        else if(buff[i]<0)     buff[i]=0;
                }
                Image2->Canvas->Pixels[x][y]=(TColor)RGB((int)buff[0],(int)buff[1],(int)buff[2]);

                delete buff;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
        Edit1->Text=TrackBar1->Position;
}
//---------------------------------------------------------------------------

void TForm1::TrackBar1Update()
{
        TrackBar1->Position=StrToInt(Edit1->Text);
}
