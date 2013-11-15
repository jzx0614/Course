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
        OpenImage(0);
        Button1->Enabled=true;
        Button2->Enabled=true;
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
        memset(Histogram,0,sizeof(Histogram));
        for(int x=0;x<map->Width;x++)
        for(int y=0;y<map->Height;y++){
                int r=GetRValue(map->Canvas->Pixels[x][y]);
                int g=GetGValue(map->Canvas->Pixels[x][y]);
                int b=GetBValue(map->Canvas->Pixels[x][y]);
                int gray=0.299*r+0.587*g+0.114*b;
                if(gray>255) gray=255;
                if(gray<0) gray=0;
                Histogram[gray]++;
                map->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }

        Image1->Picture->Bitmap=map;

        if(Image1->Width>300){
                PageControl1->Width=Image1->Width+8;
                Form1->Width=PageControl1->Width+400;
        }
        if(Image1->Height>300){
                PageControl1->Height=Image1->Height+50;
                Form1->Height=PageControl1->Height+70;
        }

        Series1->Clear();
        Series1->AddArray(Histogram,256);
        PageControl1->ActivePageIndex=0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
        if(SavePictureDialog1 -> Execute())
                Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
}
//---------------------------------------------------------------------------
void TForm1::ShowGraph(int Im,int color[])
{
        Graphics::TBitmap *temp=new Graphics::TBitmap();
        temp->Width=map->Width;
        temp->Height=map->Height;
        double showtable[256]={0};
        int min=StrToInt(Edit1->Text);

        for(int x=0;x<Image1->Width;x++)
        for(int y=0;y<Image1->Height;y++){
                int gray=color[GetRValue(map->Canvas->Pixels[x][y])];
                if(Im==3&&gray<=min) gray=min; 
                showtable[gray]++;
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }

        if(Im==2){
                Series3->Clear();
                Series2->Clear();
                Series2->AddArray(showtable,256);
                Image2->Picture->Bitmap=temp;
                PageControl1->ActivePageIndex=1;
        }
        else if(Im==3){
                Series2->Clear();
                Series3->Clear();
                Series3->AddArray(showtable,256);
                Image3->Picture->Bitmap=temp;
                PageControl1->ActivePageIndex=2;
        }
        delete temp;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{

        long total=map->Height*map->Width;
        double sum[256]={0};
        memcpy(sum,Histogram,sizeof(sum));
        memset(H_equalization,0,sizeof(H_equalization));

        for(int x=0;x<=255;x++){
                if(x>0)   sum[x]+=sum[x-1];
                H_equalization[x]=(long)(sum[x]/(double)total*255);
        }
        ShowGraph(2,H_equalization);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        long total=map->Height*map->Width;
        long sum[256]={0};
        int m[256]={0};
        memset(H_specification,0,sizeof(H_specification));
        int min=StrToInt(Edit1->Text);
        int max=StrToInt(Edit2->Text);

        for(int i=min;i<=max;i++){
            sum[i]=(total/(max-min+1))*(i-min+1);
            H_specification[i]=(double)sum[i]/(double)total*255;
        }
        for(int i=0;i<=255;i++){
                for(int j=0;j<=255;j++){
                        if(H_specification[j]>=H_equalization[i])
                        {
                                m[i]=j;
                                break;
                        }
                }

        }
       ShowGraph(3,m);


}
//---------------------------------------------------------------------------

