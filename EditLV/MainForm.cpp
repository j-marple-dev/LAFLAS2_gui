//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEditLVForm *EditLVForm;
//---------------------------------------------------------------------------
__fastcall TEditLVForm::TEditLVForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TEditLVForm::FormCreate(TObject *Sender)
{
  FixMassSG->ColWidths[0] = 150;
  FixMassSG->FixedColor = clGreen;
  FixMassSG->Cells[0][0] = "Id.";
  FixMassSG->Cells[0][1] = "Quantity";
  FixMassSG->Cells[0][2] = "Mass [kg]";

  VarMassSG->ColWidths[0] = 320;
  VarMassSG->ColWidths[1] = 150;
  VarMassSG->Cells[0][0] = "Id.";
  VarMassSG->Cells[0][1] = "Quantity";
  VarMassSG->Cells[0][2] = "Structural Mass [kg]";
  VarMassSG->Cells[0][3] = "Propellant Mass [kg]";
  VarMassSG->Cells[0][4] = "ISP [sec]";
  VarMassSG->Cells[0][5] = "Nozzle Exit Area [m^2]";
  VarMassSG->Cells[0][6] = "Thrust Description Type {T|M}";
  VarMassSG->Cells[0][7] = "      time [sec], thrust";

  EnvironmentsSG->ColWidths[0] = 150;
  EnvironmentsSG->ColWidths[1] = 150;
  EnvironmentsSG->Cells[0][0] = "Earth Model";
  EnvironmentsSG->Cells[0][1] = "Air Model";

  InitialSG->ColWidths[0] = 260;
  InitialSG->ColWidths[1] = 150;
  InitialSG->Cells[0][0] = "Latitude [deg]";
  InitialSG->Cells[0][1] = "Longitude [deg]";
  InitialSG->Cells[0][2] = "Altitude [m]";
  InitialSG->Cells[0][3] = "Azimuth [deg]";
  InitialSG->Cells[0][4] = "Flight Path Angle [deg]";
  InitialSG->Cells[0][5] = "Velocity [m/s]";

  AxialForceSG->ColWidths[0] = 300;
  AxialForceSG->ColWidths[1] = 150;
  AxialForceSG->Cells[0][0] = "Id.";
  AxialForceSG->Cells[0][1] = "Reference Area [m^2]";
  AxialForceSG->Cells[0][2] = "Mach, Axial Force Coeff.";
  NormalForceSG->ColWidths[0] = 300;
  NormalForceSG->ColWidths[1] = 150;
  NormalForceSG->Cells[0][0]  = "Mach, Normal Force Coeff.";
  SideForceSG->ColWidths[0] = 300;
  SideForceSG->ColWidths[1] = 150;
  SideForceSG->Cells[0][0]  = "Mach, Side Force Coeff.";

  PhaseSG->ColWidths[0] = 300;
  PhaseSG->ColWidths[1] = 150;
  PhaseSG->Cells[0][0]  = "Id.";
  PhaseSG->Cells[0][1]  = "End Time [sec]";
  PhaseSG->Cells[0][2]  = "Use Aerodynamic coeff. ?";
  PhaseSG->Cells[0][3]  = "FixMass Attatchment Flags";
  PhaseSG->Cells[0][4]  = "VarMass Attatchment Flags";
  PhaseSG->Cells[0][5]  = "VarMass Active Flags";
  PhaseSG->Cells[0][6]  = "Control Type";
  PhaseSG->Cells[0][7]  = "  Pitch_s | Alpha_s [deg]";
  PhaseSG->Cells[0][8]  = "  Pitch_e | Alpha_e [deg]";
  PhaseSG->Cells[0][9]  = "  Yaw_s | Beta_s [deg]";
  PhaseSG->Cells[0][10] = "  Yaw_e | Beta_e [deg]";
  PhaseSG->Cells[0][11] = "Number of Grids";
}
//---------------------------------------------------------------------------
void __fastcall TEditLVForm::FixMassAddButtonClick(TObject *Sender)
{
  FixMassSG->ColCount += 1;
  FixMassSG->ColWidths[FixMassSG->ColCount - 1] = 150;
}
//---------------------------------------------------------------------------
void __fastcall TEditLVForm::FixMassDelButtonClick(TObject *Sender)
{
  if (FixMassSG->ColCount == 1) {
	return;
  }
  FixMassSG->ColCount -= 1;
}
//---------------------------------------------------------------------------
void __fastcall TEditLVForm::VarMassAddButtonClick(TObject *Sender)
{
  VarMassSG->ColCount += 1;
  VarMassSG->ColWidths[VarMassSG->ColCount - 1] = 150;
}
//---------------------------------------------------------------------------
void __fastcall TEditLVForm::VarMassDelButtonClick(TObject *Sender)
{
  if (VarMassSG->ColCount == 1) {
	return;
  }
  VarMassSG->ColCount -= 1;
}
//---------------------------------------------------------------------------
void __fastcall TEditLVForm::AddThrustButtonClick(TObject *Sender)
{
  VarMassSG->RowCount += 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::DelThrustButtonClick(TObject *Sender)
{
  if (VarMassSG->RowCount == 8) {
	return;
  }
  VarMassSG->RowCount -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::AerodynamicAddButtonClick(TObject *Sender)
{
  AxialForceSG->ColCount  += 1;
  AxialForceSG->ColWidths[AxialForceSG->ColCount - 1] = 150;
  NormalForceSG->ColCount += 1;
  NormalForceSG->ColWidths[NormalForceSG->ColCount - 1] = 150;
  SideForceSG->ColCount   += 1;
  SideForceSG->ColWidths[SideForceSG->ColCount - 1] = 150;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::AerodynamicDelButtonClick(TObject *Sender)
{
  if (AxialForceSG->ColCount == 1) {
	return;
  }
  AxialForceSG->ColCount  -= 1;
  NormalForceSG->ColCount -= 1;
  SideForceSG->ColCount   -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::AddAFButtonClick(TObject *Sender)
{
  AxialForceSG->RowCount += 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::DelAFButtonClick(TObject *Sender)
{
  if (AxialForceSG->RowCount == 3) {
	return;
  }
  AxialForceSG->RowCount -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::AddNFButtonClick(TObject *Sender)
{
  NormalForceSG->RowCount += 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::DelNFButtonClick(TObject *Sender)
{
  NormalForceSG->RowCount -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::AddSFButtonClick(TObject *Sender)
{
  SideForceSG->RowCount += 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::DelSFButtonClick(TObject *Sender)
{
  SideForceSG->RowCount -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::PhaseAddButtonClick(TObject *Sender)
{
  PhaseSG->ColCount += 1;
  PhaseSG->ColWidths[PhaseSG->ColCount - 1] = 150;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::PhaseDelButtonClick(TObject *Sender)
{
  if (PhaseSG->ColCount == 1) {
	return;
  }
  PhaseSG->ColCount -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::MainPageControlChange(TObject *Sender)
{
  int tabIndex;

  tabIndex = MainPageControl->ActivePageIndex;
  if (tabIndex == 3) {
	if (FixMassSG->Cells[1][0].Length() == 0 || VarMassSG->Cells[1][0].Length() == 0) {
	  ShowMessage("Fix Mass and Var Mass should be defined ahead");
	}
  }
}
//---------------------------------------------------------------------------

