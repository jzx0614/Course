//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------

class ArraySet
{
  public:
        double *Rw,*Iw;
        ArraySet(int,int);
        void wStoreValue(int,int);
        void wMakeIndex(int);
        void DataReOrder(int,int);
        void DataStoreValue(int, int, double, double);
        double GetR(int w,int h){return Rdata[w][h];}
        double GetI(int w,int h){return Idata[w][h];}
        void FourierTransform(int);
        ~ArraySet();
  private:
        int width,height,*idx;
        double **Rdata,**Idata;
};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TOpenPictureDialog *OpenPictureDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *BMP;
        TMenuItem *JPEG;
        TMenuItem *Exit;
        TStatusBar *StatusBar1;
        TMenuItem *Edit;
        TMenuItem *Undo;
        TMenuItem *Tools1;
        TMenuItem *GrayLevel1;
        TMenuItem *Mask1;
        TMenuItem *Sobel1;
        TMenuItem *Prewitt1;
        TMenuItem *Laplacian1;
        TButton *Button3;
        TPageControl *PageControl1;
        TTabSheet *TabSheet6;
        TImage *Image7;
        TTabSheet *TabSheet7;
        TImage *Image8;
        TMenuItem *Laplacian21;
        TMenuItem *Laplacian31;
        TTabSheet *TabSheet2;
        TImage *Image3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TTabSheet *TabSheet1;
        TImage *Image2;
        TTabSheet *TabSheet3;
        TImage *Image4;
        void __fastcall BMPClick(TObject *Sender);
        void __fastcall JPEGClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image7MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall UndoClick(TObject *Sender);
        void __fastcall GrayLevel1Click(TObject *Sender);
        void __fastcall Sobel1Click(TObject *Sender);
        void __fastcall Prewitt1Click(TObject *Sender);
        void __fastcall Laplacian1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Laplacian21Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        Graphics::TBitmap *map;
        Graphics::TBitmap *graylevel;
        void TForm1::OpenImage(int type);
        void C_Mask(int [3][3],int**);
        void Mask(int type);
        void FTransform();
        void IFTransform();
        void Pass_Filter(int type);
        void ShowGraph(int Im);
        double **IR;
        double **IJ;
        ArraySet *G;
        int abs(int);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif
