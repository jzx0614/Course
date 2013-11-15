//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <iostream.h>
#pragma hdrstop

#include "main.h"
#include "jpeg.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        map = new Graphics::TBitmap();
        graylevel= new Graphics::TBitmap();
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

void __fastcall TForm1::UndoClick(TObject *Sender)
{
       Image1->Picture->Bitmap=map;
       Image2->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GrayLevel1Click(TObject *Sender)
{
        Image1->Picture->Bitmap=graylevel;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Graphics::TBitmap *temp=new Graphics::TBitmap();
        temp->Width=map->Width;
        temp->Height=map->Height;
        int S1_array[3][3]={{-1,-2,-1},
                            { 0, 0, 0},
                            { 1, 2, 1}};
        int S2_array[3][3]={{-1, 0, 1},
                            {-2, 0, 2},
                            {-1, 0, 1}};
        int **result1=new int *[Image1->Width];
        int **result2=new int *[Image1->Width];
        for(int i=0;i<Image1->Width;i++)
        {
                result1[i]=new int [Image1->Height];
                result2[i]=new int [Image1->Height];
        }
        C_Mask(S1_array,result1);
        C_Mask(S2_array,result2);

        for(int x=0;x<Image1->Width;x++){
        for(int y=0;y<Image1->Height;y++){
                int gray=pow(result1[x][y]*result1[x][y]+result2[x][y]*result2[x][y],0.5);
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }
        }
        Image2->Visible=true;
        Image2->Picture->Bitmap=temp;
        PageControl1->ActivePageIndex=0;
        //AnsiString Value;
        //Value=InputBox(" Sobel Dialog ","Input a T value","128");
}
//---------------------------------------------------------------------------

void TForm1::OpenImage(int type)
{
        if (type == 1) {
                OpenPictureDialog1->FilterIndex = 2;
                if (OpenPictureDialog1->Execute()) {
                        TJPEGImage *JImage= new TJPEGImage;
                        JImage->LoadFromFile(OpenPictureDialog1->FileName);
                        map->Assign(JImage);
                        delete JImage;
                }
        }
        else {
                OpenPictureDialog1->FilterIndex = 4;
                if (OpenPictureDialog1->Execute())
                        map->LoadFromFile(OpenPictureDialog1->FileName);
        }

        graylevel->Width = map->Width;
        graylevel->Height= map->Height;
        for(int x=0;x<map->Width;x++)
        for(int y=0;y<map->Height;y++){
                int r=GetRValue(map->Canvas->Pixels[x][y]);
                int g=GetGValue(map->Canvas->Pixels[x][y]);
                int b=GetBValue(map->Canvas->Pixels[x][y]);
                int gray=0.299*r+0.587*g+0.114*b;
                graylevel->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }
                
        Image1->Picture->Bitmap=map;
        Image2->Visible=false;
        Image3->Visible=false;
        Image3->Visible=false;
        Image5->Visible=false;
        Image6->Visible=false;

        Form1->Width=Image1->Width*2+36;
        Form1->Left=(1024- Form1->Width)/2;
        Form1->Height=Image1->Height+Image1->Top+29+50;

        PageControl1->Left=Image1->Width+18;
        PageControl1->Width=Image1->Width+8;
        PageControl1->Height=Image1->Height+50;



        GrayLevel1->Enabled=true;
        Undo->Enabled=true;
        Button1->Enabled=true;
        Button2->Enabled=true;
        Button3->Enabled=true;
}
//---------------------------------------------------------------------------
int TForm1::abs(int num)
{
        return (num>0) ? num : -num;
}
void TForm1::C_Mask(int type[3][3],int **color)
{

        int sum=0;
        for(int x=0;x<Image1->Width;x++){
                for(int y=0;y<Image1->Height;y++){
                        sum=0;
                        for(int i=x-1;i<x+2;i++)
                        for(int j=y-1;j<y+2;j++)
                                if((0<=i && i<Image1->Width) || (0<=j && j<Image1->Height))
                                        sum+=type[i-x+1][j-y+1]*GetRValue(graylevel->Canvas->Pixels[i][j]);
                        color[x][y]=sum;
                }
        }
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Graphics::TBitmap *temp=new Graphics::TBitmap();
        temp->Width=map->Width;
        temp->Height=map->Height;
        int P1_array[3][3]={{-1,-1,-1},
                            { 0, 0, 0},
                            { 1, 1, 1}};
        int P2_array[3][3]={{-1, 0, 1},
                            {-1, 0, 1},
                            {-1, 0, 1}};
        int **result1=new int *[Image1->Width];
        int **result2=new int *[Image1->Width];
        for(int i=0;i<Image1->Width;i++)
        {
                result1[i]=new int [Image1->Height];
                result2[i]=new int [Image1->Height];
        }
        C_Mask(P1_array,result1);
        C_Mask(P2_array,result2);

        for(int x=0;x<Image1->Width;x++){
        for(int y=0;y<Image1->Height;y++){
                int gray=pow(result1[x][y]*result1[x][y]+result2[x][y]*result2[x][y],0.5);
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }
        }
        Image3->Visible=true;
        Image3->Picture->Bitmap=temp;
        PageControl1->ActivePageIndex=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Graphics::TBitmap *temp=new Graphics::TBitmap();
        temp->Width=map->Width;
        temp->Height=map->Height;
        int L1_array[3][3]={{ 0,-1, 0},
                            {-1, 4,-1},
                            { 0,-1, 0}};
        int L2_array[3][3]={{ 1,-2, 1},
                            {-2, 4,-2},
                            { 1,-2, 1}};
        int L3_array[3][3]={{-1,-1,-1},
                            {-1, 8,-1},
                            {-1,-1,-1}};
        int **result1=new int *[Image1->Width];
        for(int i=0;i<Image1->Width;i++)
                result1[i]=new int [Image1->Height];

        C_Mask(L1_array,result1);
        for(int x=0;x<Image1->Width;x++)
        for(int y=0;y<Image1->Height;y++){
                int gray=abs(result1[x][y]);
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }
        Image4->Visible=true;
        Image4->Picture->Bitmap=temp;
        PageControl1->ActivePageIndex=2;
        C_Mask(L2_array,result1);
        for(int x=0;x<Image1->Width;x++)
        for(int y=0;y<Image1->Height;y++){
                int gray=abs(result1[x][y]);
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }
        Image5->Visible=true;
        Image5->Picture->Bitmap=temp;
        PageControl1->ActivePageIndex=3;
        C_Mask(L3_array,result1);
        for(int x=0;x<Image1->Width;x++)
        for(int y=0;y<Image1->Height;y++){
                int gray=abs(result1[x][y]);
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }
        Image6->Visible=true;
        Image6->Picture->Bitmap=temp;
        PageControl1->ActivePageIndex=4;
}
//---------------------------------------------------------------------------

