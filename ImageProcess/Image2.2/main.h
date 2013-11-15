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
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TImage *Image1;
        TImage *Image2;
        TOpenPictureDialog *OpenPictureDialog1;
        TButton *Button5;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *BMP;
        TMenuItem *JPEG;
        TMenuItem *Exit;
        TStatusBar *StatusBar1;
        TComboBox *ComboBox1;
        TEdit *Edit1;
        TTrackBar *TrackBar1;
        TLabel *Label;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall BMPClick(TObject *Sender);
        void __fastcall JPEGClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Image2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall TrackBar1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        Graphics::TBitmap *map;
        Graphics::TBitmap *graylevel;
        void TForm1::OpenImage(int type);
        double* TForm1::RtoY(double *,int );
        double* TForm1::YtoR(double *,int );
        __fastcall TForm1(TComponent* Owner);
        double* Quantization(double *color,double *N);
        void TrackBar1Update();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
