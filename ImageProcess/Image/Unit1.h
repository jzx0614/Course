//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TSavePictureDialog *SavePictureDialog1;
        TOpenPictureDialog *OpenPictureDialog1;
        TStatusBar *StatusBar1;
        TButton *Button3;
        TButton *Button4;
        TRadioGroup *RadioGroup1;
        TRadioGroup *RadioGroup2;
        TRadioGroup *RadioGroup3;
        TButton *Button5;
        TFrame2 *Frame21;
        TImage *Image1;
        TLabel *Label1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Frame21Image2MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
public:		// User declarations
        int N;	// User declarations
        Graphics::TBitmap *map;
        __fastcall TForm1(TComponent* Owner);
        void bubble_sort(int * p, int * q, int * r);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
