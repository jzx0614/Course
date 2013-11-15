//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "jpeg.hpp"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit2"
#pragma resource "*.dfm"

TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        map = new Graphics::TBitmap();
        if (RadioGroup1->ItemIndex == 1) {
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
                if (OpenPictureDialog1->Execute()) {
                        map->LoadFromFile(OpenPictureDialog1->FileName);
                }
        }

        Image1->Picture->Bitmap=map;
        Frame21->Image2->Height=map->Height;
        Frame21->Image2->Width=map->Width;
        Frame21->Image2->Picture->Bitmap=map;
        Button5->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if (RadioGroup1->ItemIndex == 1)
                SavePictureDialog1->FilterIndex = 2;
        else
                SavePictureDialog1->FilterIndex = 4;
        if(SavePictureDialog1 -> Execute())
                Frame21->Image2->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Graphics::TBitmap  *temp=new Graphics::TBitmap();
        temp->Width=Frame21->Image2->Picture->Bitmap->Width;
        temp->Height=Frame21->Image2->Picture->Bitmap->Height;
        for(int x=0;x<Frame21->Image2->Picture->Bitmap->Width;x++)
        for(int y=0;y<Frame21->Image2->Picture->Bitmap->Height;y++){
                int r=GetRValue(Image1->Canvas->Pixels[x][y]);
                int g=GetGValue(Image1->Canvas->Pixels[x][y]);
                int b=GetBValue(Image1->Canvas->Pixels[x][y]);
                int gray=(r+g+b)/3 ;
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }

        Frame21->Image2->Picture->Bitmap=temp;
        Image1->Picture->Bitmap=temp;

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
        StatusBar1->Panels->Items[0]->Text=Format(" Image1 現在位置 :( %d , %d )",pos,2);
        StatusBar1->Panels->Items[1]->Text=Format(" Image1 RGB :( %d , %d , %d )",color,3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

        int Width = Frame21->Image2->Picture->Bitmap->Width;
        int Height= Frame21->Image2->Picture->Bitmap->Height;

        Graphics::TBitmap *temp= new Graphics::TBitmap();

        switch(RadioGroup3->ItemIndex){
                case 0: N=2;  break;
                case 1: N=4;  break;
                case 2: N=8;  break;
                case 3: N=16; break;
        }
        temp->Width=Width/N;
        temp->Height=Height/N;


        for(int x=0;x<Width;x+=N)
        for(int y=0;y<Height;y+=N){
                if(RadioGroup2->ItemIndex<=3){
                        int w,h;
                        switch(RadioGroup2->ItemIndex){
                                case 0: w=N-1; h=0;  break;
                                case 1: w=0;   h=0;  break;
                                case 2: w=0;   h=N-1;break;
                                case 3: w=N-1; h=N-1;break;
                        }
                       temp->Canvas->Pixels[x/N][y/N]=Frame21->Image2->Canvas->Pixels[x+w][y+h];
                }
                else{
                        int num=0;
                        int *r = new int [N*N];
                        int *g = new int [N*N];
                        int *b = new int [N*N];
                        for(int i=0;i<N;i++)
                        for(int j=0;j<N;j++){
                                r[num]=GetRValue(Frame21->Image2->Canvas->Pixels[x+i][y+j]);
                                g[num]=GetGValue(Frame21->Image2->Canvas->Pixels[x+i][y+j]);
                                b[num++]=GetBValue(Frame21->Image2->Canvas->Pixels[x+i][y+j]);
                        }
                        if (RadioGroup2->ItemIndex == 4){
                                int r_sum=0,g_sum=0,b_sum=0;
                                for(int i=0;i<(2*N);i++){
                                           r_sum+=r[i];
                                           g_sum+=g[i];
                                           b_sum+=b[i];
                                }
                                temp->Canvas->Pixels[x/N][y/N]=(TColor)RGB(r_sum/(2*N),g_sum/(2*N),b_sum/(2*N));
                        }
                        else if (RadioGroup2->ItemIndex == 5){
                                bubble_sort(r,g,b);
                                temp->Canvas->Pixels[x/N][y/N]=(TColor)RGB(r[(N*N)/2],g[(N*N)/2],b[(N*N)/2]);
                        }
                }
        }
        Frame21->Image2->Width =Width/N;
        Frame21->Image2->Height=Height/N;
        Frame21->Image2->Picture->Bitmap=temp;
        Image1->Picture->Bitmap=temp;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
       Frame21->Image2->Height=map->Height;
       Frame21->Image2->Width=map->Width;
       Frame21->Image2->Picture->Bitmap=map;
       Image1->Picture->Bitmap=map;
}
//---------------------------------------------------------------------------


void TForm1::bubble_sort(int * p, int * q, int * r)
{
        int temp,size=N*2;
        for(int x=0;x<size-1;x++)
        for(int y=x;y<size-1-x;y++){
                if((p[y]>p[y+1])||
                   (p[y]==p[y+1]&&q[y]>q[y+1])||
                   (p[y]==p[y+1]&&q[y]==q[y+1]&&r[y]>r[y+1])){
                        temp=p[y];p[y]=p[y+1];p[y+1]=temp;
                        temp=q[y];q[y]=q[y+1];q[y+1]=temp;
                        temp=r[y];r[y]=r[y+1];r[y+1]=temp;
                }
        }
        //TODO: Add your source code here
}

void __fastcall TForm1::Frame21Image2MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        TVarRec pos[2]={X,Y};
        int r=GetRValue(Frame21->Image2->Canvas->Pixels[X][Y]);
        int g=GetGValue(Frame21->Image2->Canvas->Pixels[X][Y]);
        int b=GetBValue(Frame21->Image2->Canvas->Pixels[X][Y]);
        TVarRec color[3]={r,g,b};
        StatusBar1->Panels->Items[2]->Text=Format(" Image2 現在位置 :( %d , %d )",pos,2);
        StatusBar1->Panels->Items[3]->Text=Format(" Image2 RGB :( %d , %d , %d )",color,3);
}
//---------------------------------------------------------------------------

