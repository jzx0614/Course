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
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TOpenPictureDialog *OpenPictureDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *BMP;
        TMenuItem *JPEG;
        TMenuItem *Exit;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TChart *Chart1;
        TButton *Button1;
        TButton *Button2;
        TImage *Image1;
        TSavePictureDialog *SavePictureDialog1;
        TMenuItem *N1;
        TImage *Image2;
        TImage *Image3;
        TLineSeries *Series2;
        TLineSeries *Series1;
        TLineSeries *Series3;
        TEdit *Edit1;
        TEdit *Edit2;
        void __fastcall BMPClick(TObject *Sender);
        void __fastcall JPEGClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        Graphics::TBitmap *map;
        double Histogram[256];
        int H_equalization[256];
        int H_specification[256];
        void TForm1::OpenImage(int type);
        void TForm1::ShowGraph(int Im,int color[]);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
