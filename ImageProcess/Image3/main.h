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
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TImage *Image3;
        TImage *Image2;
        TTabSheet *TabSheet3;
        TImage *Image4;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TImage *Image5;
        TImage *Image6;
        void __fastcall BMPClick(TObject *Sender);
        void __fastcall JPEGClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall UndoClick(TObject *Sender);
        void __fastcall GrayLevel1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        Graphics::TBitmap *map;
        Graphics::TBitmap *graylevel;
        void TForm1::OpenImage(int type);
        void C_Mask(int [3][3],int**);
        int abs(int);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
