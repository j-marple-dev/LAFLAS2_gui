//---------------------------------------------------------------------------

#ifndef FormEditOptH
#define FormEditOptH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TFormOCF : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *LoadButton;
	TButton *SaveButton;
	TSaveDialog *SaveDialog;
	TOpenDialog *OpenDialog;
	TPopupMenu *CommonPopup;
	TMenuItem *AddColumn;
	TMenuItem *DelColumn;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TStringGrid *OptParamSG;
	TStringGrid *OptEqCnstrSG;
	TStringGrid *OptLbCnstrSG;
	TPanel *Panel6;
	TPanel *Panel3;
	TStringGrid *OptUbCnstrSG;
	TLabel *Label1;
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall LoadButtonClick(TObject *Sender);
	void __fastcall Panel1Resize(TObject *Sender);
	void __fastcall OnCommonMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall CommonAddClick(TObject *Sender);
	void __fastcall CommonDelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormOCF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOCF *FormOCF;
//---------------------------------------------------------------------------
#endif
