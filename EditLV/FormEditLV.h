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
#include <Vcl.Menus.hpp>
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
	TStringGrid *VarMassSG;
	TButton *AddThrustButton;
	TButton *DelThrustButton;
	TStringGrid *EnvironmentsSG;
	TStringGrid *InitialSG;
	TStringGrid *AxialForceSG;
	TStringGrid *NormalForceSG;
	TStringGrid *SideForceSG;
	TStringGrid *PhaseSG;
	TSaveTextFileDialog *SaveDialog;
	TStringGrid *AerodynamicSG;
	TStringGrid *PhaseInfoSG;
	TOpenDialog *OpenDialog;
	TPopupMenu *CommonPopup;
	TMenuItem *AddColumn;
	TMenuItem *DelColumn;
	TPopupMenu *AerodynamicPopup;
	TMenuItem *AddColumn1;
	TMenuItem *DeleteColumn1;
	TPanel *Panel2;
	TButton *AddSFButton;
	TButton *DelSFButton;
	TPanel *Panel3;
	TButton *AddNFButton;
	TButton *DelNFButton;
	TPanel *Panel5;
	TPanel *Panel6;
	TButton *DelAFButton;
	TButton *AddAFButton;
	TPanel *Panel4;
	TPopupMenu *PhasePopup;
	TMenuItem *AddPhase;
	TMenuItem *DelPhase;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall AddThrustButtonClick(TObject *Sender);
	void __fastcall DelThrustButtonClick(TObject *Sender);
	void __fastcall AddAFButtonClick(TObject *Sender);
	void __fastcall DelAFButtonClick(TObject *Sender);
	void __fastcall AddNFButtonClick(TObject *Sender);
	void __fastcall DelNFButtonClick(TObject *Sender);
	void __fastcall AddSFButtonClick(TObject *Sender);
	void __fastcall DelSFButtonClick(TObject *Sender);
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
	void __fastcall CommonAddClick(TObject *Sender);
	void __fastcall CommonDelClick(TObject *Sender);
	void __fastcall CommonSGMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall AerodynamicAddClick(TObject *Sender);
	void __fastcall AerodynamicDelClick(TObject *Sender);
	void __fastcall CommonAeroSGMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PhaseSGMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall AddPhaseClick(TObject *Sender);
	void __fastcall DelPhaseClick(TObject *Sender);
	void __fastcall Panel1Resize(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TEditLVForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditLVForm *EditLVForm;
//---------------------------------------------------------------------------
#endif
