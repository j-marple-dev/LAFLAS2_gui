//---------------------------------------------------------------------------

#ifndef FormEditLVH
#define FormEditLVH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TEditLVForm : public TForm
{
__published:	// IDE-managed Components
	TPageControl *MainPageControl;
	TTabSheet *FixMassTab;
	TTabSheet *VarMassTab;
	TTabSheet *AeroDynamicsTab;
	TTabSheet *PhaseTab;
	TTabSheet *EnvironmentsTab;
	TTabSheet *InitConditionTab;
	TPanel *Panel1;
	TButton *LoadButton;
	TButton *SaveButton;
	TStringGrid *FixMassSG;
	TSpeedButton *FixMassAddButton;
	TSpeedButton *FixMassDelButton;
	TStringGrid *VarMassSG;
	TButton *VarMassAddButton;
	TButton *VarMassDelButton;
	TButton *AddThrustButton;
	TButton *DelThrustButton;
	TStringGrid *EnvironmentsSG;
	TStringGrid *InitialSG;
	TStringGrid *AxialForceSG;
	TStringGrid *NormalForceSG;
	TButton *AerodynamicAddButton;
	TButton *AerodynamicDelButton;
	TButton *AddSFButton;
	TButton *DelSFButton;
	TStringGrid *SideForceSG;
	TButton *AddNFButton;
	TButton *DelNFButton;
	TButton *AddAFButton;
	TButton *DelAFButton;
    TStringGrid *PhaseSG;
	TSaveTextFileDialog *SaveDialog;
	TStringGrid *AerodynamicSG;
	TStringGrid *PhaseInfoSG;
	TOpenDialog *OpenDialog;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FixMassAddButtonClick(TObject *Sender);
	void __fastcall FixMassDelButtonClick(TObject *Sender);
	void __fastcall VarMassAddButtonClick(TObject *Sender);
	void __fastcall VarMassDelButtonClick(TObject *Sender);
	void __fastcall AddThrustButtonClick(TObject *Sender);
	void __fastcall DelThrustButtonClick(TObject *Sender);
	void __fastcall AerodynamicAddButtonClick(TObject *Sender);
	void __fastcall AerodynamicDelButtonClick(TObject *Sender);
	void __fastcall AddAFButtonClick(TObject *Sender);
	void __fastcall DelAFButtonClick(TObject *Sender);
	void __fastcall AddNFButtonClick(TObject *Sender);
	void __fastcall DelNFButtonClick(TObject *Sender);
	void __fastcall AddSFButtonClick(TObject *Sender);
	void __fastcall DelSFButtonClick(TObject *Sender);
	void __fastcall PhaseAddButtonClick(TObject *Sender);
	void __fastcall PhaseDelButtonClick(TObject *Sender);
	void __fastcall MainPageControlChange(TObject *Sender);
	void __fastcall PhaseSGMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall PhaseSGSelectCell(TObject *Sender, System::LongInt ACol, System::LongInt ARow,
		  bool &CanSelect);
	void __fastcall VarMassSGMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall EnvironmentsSGMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y);
	void __fastcall SaveButtonClick(TObject *Sender);
	void __fastcall LoadButtonClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TEditLVForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditLVForm *EditLVForm;
//---------------------------------------------------------------------------
#endif
