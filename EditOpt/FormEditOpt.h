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
//---------------------------------------------------------------------------
class TFormOCF : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TButton *LoadButton;
	TButton *SaveButton;
	TStringGrid *OptParamSG;
	TButton *AddParamButton;
	TButton *DelParamButton;
	TStringGrid *OptEqCnstrSG;
	TButton *AddEqCnstrButton;
	TButton *DelEqCnstrButton;
	TStringGrid *OptLbCnstrSG;
	TButton *AddLbCnstrButton;
	TButton *DelLbCnstrButton;
	TStringGrid *OptUbCnstrSG;
	TButton *AddUbCnstrButton;
	TButton *DelUbCnstrButton;
	TSaveDialog *SaveDialog;
	TOpenDialog *OpenDialog;
	void __fastcall AddParamButtonClick(TObject *Sender);
	void __fastcall DelParamButtonClick(TObject *Sender);
	void __fastcall AddEqCnstrButtonClick(TObject *Sender);
	void __fastcall AddLbCnstrButtonClick(TObject *Sender);
	void __fastcall DelLbCnstrButtonClick(TObject *Sender);
	void __fastcall AddUbCnstrButtonClick(TObject *Sender);
	void __fastcall DelUbCnstrButtonClick(TObject *Sender);
	void __fastcall DelEqCnstrButtonClick(TObject *Sender);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall LoadButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormOCF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOCF *FormOCF;
//---------------------------------------------------------------------------
#endif
