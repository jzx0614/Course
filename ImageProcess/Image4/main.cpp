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

#define pi_2  6.28318530717959

ArraySet::ArraySet(int w,int h){
        width=w;
        height=h;

        Rdata=new double *[w];
        Idata=new double *[w];
        for(int i=0;i<w;i++)
        {
                Rdata[i]=new double [h];
                Idata[i]=new double [h];
        }
};
ArraySet::~ArraySet(){
    delete Rw;
    delete Iw;
}
void ArraySet::wStoreValue(int sign,int type)
{
    double theta, angle;
    int totalN;
    if(type==0){
        totalN=width;
        Rw=new double [width];
        Iw=new double [width];
    }
    else{
        totalN=height;
        Rw=new double [height];
        Iw=new double [height];
    }
    theta = sign * ( pi_2 / totalN);
    for (int i=0; i<totalN; i++)
    {
        angle = i * theta;
        Rw[i] = cos(angle);
        Iw[i] = sin(angle);
    }
}
void ArraySet::DataReOrder(int type,int p)
{
    int i, j, k, halfn,totalN= (type==0) ? width : height;
    double Rt,It;
    
    halfn = totalN >> 1;
    for ( i=0, j=0; i< totalN - 1; i++ )
    {
        if ( i< j )
        {
            if(type==0){
                Rt = Rdata[p][i];
                It = Idata[p][i];
                Rdata[p][i] = Rdata[p][j];
                Idata[p][i] = Idata[p][j];            
                Rdata[p][j] = Rt;
                Idata[p][j] = It;            
            }
            else{
                Rt = Rdata[i][p];
                It = Idata[i][p];
                Rdata[i][p] = Rdata[j][p];
                Idata[i][p] = Idata[j][p];            
                Rdata[j][p] = Rt;
                Idata[j][p] = It;                        
            }
        }
        k = halfn;
        while ( k<=j )
        {
            j -= k;
            k >>= 1;
        }
        j += k;
    }
}
void ArraySet::wMakeIndex(int type){
    int i, j, k, halfn,t;
    int totalN = type==0 ? width : height;
    halfn = totalN >> 1;
    idx = new int [halfn];
    for ( i=0; i<halfn; i++ )
        idx[i] = i;
    for ( i=0, j=0; i < halfn-1; i++ )
    {
        if ( i< j ){
            t=idx[i];idx[i]=idx[j];idx[j]=t;
        }    
        k = halfn/2;
        while(k<=j){
            j -= k;
            k>>=1;
        }    
        j += k;
    }
 
}
void ArraySet::DataStoreValue(int w, int h , double r, double i)
{
        Rdata[w][h]=r;
        Idata[w][h]=i;
}
void ArraySet::FourierTransform(int sign)
{
    int totalN =  width ;
    int p,even,N,M;
    double Rodd,Iodd;
    wStoreValue(sign,0);
    wMakeIndex(0);
  
    for(int r=0;r<width;r++){
            N=totalN;
            while ( N >>=1  ){
                p=0;even=0;
                do{
                        for(int i=0;i<N;i++)
                        {
                                M=even+N;
                                if(idx[p]==0)
                                {
                                   Rodd=Rdata[r][M];
                                   Iodd=Idata[r][M];
                                }    
                                else{
                                   Rodd=Rw[idx[p]]*Rdata[r][M]-Iw[idx[p]]*Idata[r][M];
                                   Iodd=Iw[idx[p]]*Rdata[r][M]+Rw[idx[p]]*Idata[r][M];
                                }        
                                Rdata[r][M] = Rdata[r][even] - Rodd;
                                Idata[r][M] = Idata[r][even] - Iodd;
                                Rdata[r][even]= Rdata[r][even] + Rodd;
                                Idata[r][even]= Idata[r][even] + Iodd;                                   
                                even++;                            
                        }
                        even+=N;
                        p++;
                }while(even<totalN);
            }
            DataReOrder(0,r);
    }
    totalN = height;
    wStoreValue(sign,1);
    wMakeIndex(1);
   
    for(int v=0;v<height;v++){
            N=totalN;
            while ( N /= 2 ){
                p=0;even=0;
                do{
                        for(int i=0;i<N;i++)
                        {
                                M=even+N;
                                if(idx[p]==0)
                                {
                                   Rodd=Rdata[M][v];
                                   Iodd=Idata[M][v];
                                }  
                                else{
                                     Rodd=Rw[idx[p]]*Rdata[M][v]-Iw[idx[p]]*Idata[M][v];
                                     Iodd=Iw[idx[p]]*Rdata[M][v]+Rw[idx[p]]*Idata[M][v];
                                }    
                                Rdata[M][v] = Rdata[even][v] - Rodd;
                                Idata[M][v] = Idata[even][v] - Iodd;
                                Rdata[even][v]= Rdata[even][v] + Rodd;
                                Idata[even][v]= Idata[even][v] + Iodd;
                                even++;                                                                        
                        }
                        p++;
                        even+=N;
                        
                        
                }while(even<totalN);                
            }
            DataReOrder(1,v);
    }
    for (int i=0; i<width;i++)
    for (int j=0; j<height;j++){
        Rdata[i][j]/=totalN;
        Idata[i][j]/=totalN;
    }
}
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        map = new Graphics::TBitmap();
        graylevel= new Graphics::TBitmap();
        OpenImage(0);

        IR=new double *[graylevel->Width];
        IJ=new double *[graylevel->Width];

        for(int i=0;i<graylevel->Width;i++){
                IR[i]=new double [graylevel->Height];
                IJ[i]=new double [graylevel->Height];
        }
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
void __fastcall TForm1::Image7MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        TVarRec pos[2]={X,Y};
        int r=GetRValue(Image3->Canvas->Pixels[X][Y]);
        int g=GetGValue(Image3->Canvas->Pixels[X][Y]);
        int b=GetBValue(Image3->Canvas->Pixels[X][Y]);
        TVarRec color[3]={r,g,b};
        StatusBar1->Panels->Items[1]->Text=Format(" Image3 ¦ì¸m :( %d , %d )",pos,2)+
                                           Format(" RGB :( %d , %d , %d )",color,3);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::UndoClick(TObject *Sender)
{
       Image1->Picture->Bitmap=map;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GrayLevel1Click(TObject *Sender)
{
        Image1->Picture->Bitmap=graylevel;
}
//---------------------------------------------------------------------------


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

        Image1->Picture->Bitmap=graylevel;
        if(Image1->Width>300){
               Form1->Width=Image1->Width*2+36;
               Form1->Left=(1024- Form1->Width)/2;
               Form1->Height=Image1->Height+Image1->Top+29+50;

               PageControl1->Left=Image1->Width+18;
               PageControl1->Width=Image1->Width+8;
               PageControl1->Height=Image1->Height+50;
        }


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
//---------------------------------------------------------------------------
void TForm1::Mask(int type)
{
        Graphics::TBitmap *temp=new Graphics::TBitmap();
        temp->Width=map->Width;
        temp->Height=map->Height;
        int gray;
        int **result1=new int *[Image1->Width];
        int **result2=new int *[Image1->Width];
        for(int i=0;i<Image1->Width;i++)
        {
                result1[i]=new int [Image1->Height];
                result2[i]=new int [Image1->Height];
        }
        int S1_array[3][3]={{-1,-2,-1},
                            { 0, 0, 0},
                            { 1, 2, 1}};
        int S2_array[3][3]={{-1, 0, 1},
                            {-2, 0, 2},
                            {-1, 0, 1}};
        int P1_array[3][3]={{-1,-1,-1},
                            { 0, 0, 0},
                            { 1, 1, 1}};
        int P2_array[3][3]={{-1, 0, 1},
                            {-1, 0, 1},
                            {-1, 0, 1}};
        int L1_array[3][3]={{ 0,-1, 0},
                            {-1, 4,-1},
                            { 0,-1, 0}};
        int L2_array[3][3]={{ 1,-2, 1},
                            {-2, 4,-2},
                            { 1,-2, 1}};
        int L3_array[3][3]={{-1,-1,-1},
                            {-1, 8,-1},
                            {-1,-1,-1}};
        switch(type){
           case 0:
                C_Mask(S1_array,result1);
                C_Mask(S2_array,result2);
                break;
           case 1:
                C_Mask(P1_array,result1);
                C_Mask(P2_array,result2);
                break;
           case 2:
                C_Mask(L1_array,result1);
                break;
           case 3:
                C_Mask(L2_array,result1);
                break;
           case 4:
                C_Mask(L3_array,result1);
                break;
        }
        for(int x=0;x<Image1->Width;x++){
           for(int y=0;y<Image1->Height;y++){
              if(type==0||type==1)
                gray=pow(result1[x][y]*result1[x][y]+result2[x][y]*result2[x][y],0.5);
              else
                gray=abs(result1[x][y]);
              temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
           }
        }
        Image2->Picture->Bitmap=temp;
        PageControl1->ActivePageIndex=3;
        delete temp;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Sobel1Click(TObject *Sender)
{
        Mask(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Prewitt1Click(TObject *Sender)
{
       Mask(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Laplacian1Click(TObject *Sender)
{
        Mask(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Laplacian21Click(TObject *Sender)
{
        Mask(3);
}
//---------------------------------------------------------------------------

void TForm1::ShowGraph(int Im)
{
        double K;
        if(Im==3)
                K=StrToInt(InputBox("InputBox","Input a K number","20"));
        Graphics::TBitmap *temp=new Graphics::TBitmap();
        temp->Width=graylevel->Width;
        temp->Height=graylevel->Height;
        int gray;
        for(int x=0;x<Image1->Width;x++)
        for(int y=0;y<Image1->Height;y++){
                if(Im==1)  gray=IR[x][y]*255;
                else       gray=(int)sqrt(pow(G->GetR(x,y),2.0)+pow(G->GetI(x,y),2.0));
                if(Im==3)  gray=K*log(1+gray);
                if(gray>255) gray=255;
                temp->Canvas->Pixels[x][y]=(TColor)RGB(gray,gray,gray);
        }

        if(Im==0){
                Image7->Visible=true;
                Image7->Picture->Bitmap=temp;
                PageControl1->ActivePageIndex=0;
        }
        else if(Im==1){
                Image8->Visible=true;
                Image8->Picture->Bitmap=temp;
                PageControl1->ActivePageIndex=1;
        }
        else if(Im==2){
                Image3->Visible=true;
                Image3->Picture->Bitmap=temp;
                PageControl1->ActivePageIndex=2;
        }
        else if(Im==3){
                Image4->Visible=true;
                Image4->Picture->Bitmap=temp;
                PageControl1->ActivePageIndex=2;
        }
        delete temp;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Pass_Filter(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Pass_Filter(1);
}
//---------------------------------------------------------------------------

void TForm1::Pass_Filter(int type)
{
        int W=Image1->Width;
        int H=Image1->Height;
        double f0=StrToInt(InputBox("InputBox","Input a f0 number","20"));
        double N=StrToInt(InputBox("InputBox","Input a n number","5"));
        G=new ArraySet(Image1->Width,Image1->Height);
        for(int x=0;x<Image1->Width;x++)
        for(int y=0;y<Image1->Height;y++)
                G->DataStoreValue(x,y,pow(-1,x+y)*GetRValue(Image1->Canvas->Pixels[x][y]),0);


        G->FourierTransform(1);

        for(int i=0;i<W;i++)
        for(int j=0;j<H;j++){
                IR[i][j]=0;
        }
        for(int u=0;u<Image1->Width;u++)
        for(int v=0;v<Image1->Height;v++){
            if(u==W/2&&v==H/2&&type==1) {
                G->DataStoreValue(u,v,0,0);
                continue;
            }
           IR[u][v]= (type==0) ? 1.0/(1+pow(sqrt(pow(u-W/2,2)+pow(v-H/2,2))/f0,2*N))
                               : 1.0/(1+pow(f0/sqrt(pow(u-W/2,2)+pow(v-H/2,2)),2*N));
           double Rnum =G->GetR(u,v)*IR[u][v];
           double Inum =G->GetI(u,v)*IR[u][v];
           G->DataStoreValue(u,v,Rnum,Inum);
        }

        ShowGraph(1);
        ShowGraph(0);
        ShowGraph(3);
        G->FourierTransform(-1);
        ShowGraph(2);
        delete G;
}


void __fastcall TForm1::Button5Click(TObject *Sender)
{
        G=new ArraySet(Image1->Width,Image1->Height);
        for(int x=0;x<Image1->Width;x++)
        for(int y=0;y<Image1->Height;y++)
                G->DataStoreValue(x,y,pow(-1,x+y)*GetRValue(Image1->Canvas->Pixels[x][y]),0);

        G->FourierTransform(1);
        ShowGraph(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        G->FourierTransform(-1);
        ShowGraph(2);
        delete G;

}
//---------------------------------------------------------------------------


