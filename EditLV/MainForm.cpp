//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

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
  MainPageControl->ActivePageIndex = 0;

  FixMassSG->ColWidths[0] = 150;
  FixMassSG->FixedColor = clGreen;
  FixMassSG->Cells[0][0] = "Id.";
  FixMassSG->Cells[0][1] = "Quantity";
  FixMassSG->Cells[0][2] = "Mass [kg]";

  VarMassSG->ColWidths[0] = 350;
  VarMassSG->ColWidths[1] = 150;
  VarMassSG->Cells[0][0] = "Id.";
  VarMassSG->Cells[0][1] = "Quantity";
  VarMassSG->Cells[0][2] = "Structural Mass [kg]";
  VarMassSG->Cells[0][3] = "Propellant Mass [kg]";
  VarMassSG->Cells[0][4] = "ISP [sec]";
  VarMassSG->Cells[0][5] = "Nozzle Exit Area [m^2]";
  VarMassSG->Cells[0][6] = "Thrust Description Type {T|M}";
  VarMassSG->Cells[0][7] = "  time [sec], {Ton | Mdot [kg/s]}";

  EnvironmentsSG->ColWidths[0] = 250;
  EnvironmentsSG->ColWidths[1] = 150;
  EnvironmentsSG->Cells[0][0] = "Earth Model {0|1}";
  EnvironmentsSG->Cells[0][1] = "Air Model   {0|1|2}";

  InitialSG->ColWidths[0] = 260;
  InitialSG->ColWidths[1] = 150;
  InitialSG->Cells[0][0] = "Latitude [deg]";
  InitialSG->Cells[0][1] = "Longitude [deg]";
  InitialSG->Cells[0][2] = "Altitude [m]";
  InitialSG->Cells[0][3] = "Azimuth [deg]";
  InitialSG->Cells[0][4] = "Flight Path Angle [deg]";
  InitialSG->Cells[0][5] = "Velocity [m/s]";

  AerodynamicSG->ColWidths[0] = 300;
  AerodynamicSG->ColWidths[1] = 150;
  AerodynamicSG->Cells[0][0] = "Id.";
  AerodynamicSG->Cells[0][1] = "Reference Area [m^2]";
  AxialForceSG->ColWidths[0] = 300;
  AxialForceSG->ColWidths[1] = 150;
  AxialForceSG->Cells[0][0] = "Mach, Axial Force Coeff.";
  NormalForceSG->ColWidths[0] = 300;
  NormalForceSG->ColWidths[1] = 150;
  NormalForceSG->Cells[0][0]  = "Mach, Normal Force Coeff.";
  SideForceSG->ColWidths[0] = 300;
  SideForceSG->ColWidths[1] = 150;
  SideForceSG->Cells[0][0]  = "Mach, Side Force Coeff.";

  PhaseInfoSG->ColWidths[0] = 300;
  PhaseInfoSG->ColWidths[1] = 150;
  PhaseInfoSG->Cells[0][0]  = "Phase IIP";
  PhaseInfoSG->Cells[0][1]  = "IIP Rate";
  PhaseInfoSG->Cells[0][2]  = "Phase Type     {R| }";
  PhaseInfoSG->Cells[0][3]  = "Phase Sequence {P| }";
  PhaseSG->ColWidths[0] = 300;
  PhaseSG->ColWidths[1] = 150;
  PhaseSG->Cells[0][0]  = "Id.";
  PhaseSG->Cells[0][1]  = "End Time [sec]";
  PhaseSG->Cells[0][2]  = "Use Aerodynamics {0|1}";
  PhaseSG->Cells[0][3]  = "FixMass Attatched Flags";
  PhaseSG->Cells[0][4]  = "VarMass Attatched Flags";
  PhaseSG->Cells[0][5]  = "VarMass Active Flags";
  PhaseSG->Cells[0][6]  = "Control Type {p|q|r|i|s|g|a}";
  PhaseSG->Cells[0][7]  = "  {Pitch_s | Alpha_s} [deg]";
  PhaseSG->Cells[0][8]  = "  {Pitch_e | Alpha_e} [deg]";
  PhaseSG->Cells[0][9]  = "  {Yaw_s | Beta_s}    [deg]";
  PhaseSG->Cells[0][10] = "  {Yaw_e | Beta_e}    [deg]";
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
  AerodynamicSG->ColCount += 1;
  AerodynamicSG->ColWidths[AerodynamicSG->ColCount - 1] = 150;
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
  if (AerodynamicSG->ColCount == 2) {
	return;
  }
  AerodynamicSG->ColCount -= 1;
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
  PhaseSG->ColCount     -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::MainPageControlChange(TObject *Sender)
{
  String phaseSG_Cells03 = "FixMass Attatched Flags";
  String phaseSG_Cells04 = "VarMass Attatched Flags";
  String phaseSG_Cells05 = "VarMass Active Flags";

  int tabIndex;

  tabIndex = MainPageControl->ActivePageIndex;
  if (tabIndex == 3) {
	PhaseSG->Cells[0][3] = phaseSG_Cells03 + " : " + IntToStr(FixMassSG->ColCount - 1);
	PhaseSG->Cells[0][4] = phaseSG_Cells04 + " : " + IntToStr(VarMassSG->ColCount - 1);
	PhaseSG->Cells[0][5] = phaseSG_Cells05 + " : " + IntToStr(VarMassSG->ColCount - 1);
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::PhaseSGMouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
  int ACol, ARow;

  PhaseSG->MouseToCell(X, Y, ACol, ARow);
  if (ARow == 6) {
	PhaseSG->ShowHint = true;
  } else {
	PhaseSG->ShowHint = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::PhaseSGSelectCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, bool &CanSelect)
{
/*
  static UnicodeString controlType;

  if (ARow == 6 && controlType != PhaseSG->Cells[ACol][6]) {
	PhaseSG->Cells[ACol][7]  = "";
	PhaseSG->Cells[ACol][8]  = "";
	PhaseSG->Cells[ACol][9]  = "";
	PhaseSG->Cells[ACol][10] = "";
  }

  if (ARow < 7 | 10 < ARow) {
	return;
  }

  controlType = PhaseSG->Cells[ACol][6];
  if (controlType.IsEmpty()) {
	return;
  }
  switch (controlType[1]) {
  case 'q':
	PhaseSG->Cells[ACol][10] = "--";
	break;

  case 'r':
	PhaseSG->Cells[ACol][8]  = "--";
	PhaseSG->Cells[ACol][10] = "--";
	break;

  case 'i':
	PhaseSG->Cells[ACol][7] = "--";
	PhaseSG->Cells[ACol][9] = "--";
	break;

  case 's':
	PhaseSG->Cells[ACol][8] = "--";
	break;

  case 'g':
	PhaseSG->Cells[ACol][7] = "--";
	PhaseSG->Cells[ACol][8] = "--";
	break;

  default:
	break;
  }
*/
}
//---------------------------------------------------------------------------


void __fastcall TEditLVForm::VarMassSGMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
  int ACol, ARow;

  VarMassSG->MouseToCell(X, Y, ACol, ARow);
  if (ARow == 6) {
	VarMassSG->ShowHint = true;
  } else {
	VarMassSG->ShowHint = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::EnvironmentsSGMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
  int ACol, ARow;

  EnvironmentsSG->MouseToCell(X, Y, ACol, ARow);
  if (ARow == 0 || ARow == 1) {
	EnvironmentsSG->ShowHint = true;
  } else {
	EnvironmentsSG->ShowHint = false;
  }
}
//---------------------------------------------------------------------------

using namespace std;

string tostr(String str)
{
  AnsiString temp = str;

  return string(temp.c_str());
}

void __fastcall TEditLVForm::SaveButtonClick(TObject *Sender)
{
  SaveDialog->Title = "Save Launch Vehicle File";
  if (SaveDialog->Execute()) {
	String fileName = SaveDialog->FileName;

	ofstream outFile(fileName.c_str());

	outFile << "F" << endl;
	outFile << to_string(FixMassSG->ColCount - 1) <<  endl;  // # fix mass
	for (int i = 1; i <= FixMassSG->ColCount - 1; i++) {
	  outFile << tostr(FixMassSG->Cells[i][0]) << endl;      // id
	  outFile << tostr(FixMassSG->Cells[i][1]) << endl;      // quantity
	  outFile << tostr(FixMassSG->Cells[i][2]) << endl;      // mass
	}
	outFile << "#" << endl;

	outFile << "V" << endl;
	outFile << to_string(VarMassSG->ColCount - 1) <<  endl;  // # var mass
	for (int i = 1; i <= VarMassSG->ColCount - 1; i++) {
	  outFile << tostr(VarMassSG->Cells[i][0]) << endl;      // id
	  outFile << tostr(VarMassSG->Cells[i][1]) << endl;      // quantity
	  outFile << tostr(VarMassSG->Cells[i][2]) << endl;      // structural mass
	  outFile << tostr(VarMassSG->Cells[i][3]) << endl;      // propellant mass
	  outFile << tostr(VarMassSG->Cells[i][4]) << endl;      // ISP
	  outFile << tostr(VarMassSG->Cells[i][5]) << endl;      // nozzle area
	  outFile << tostr(VarMassSG->RowCount-7) << endl;       // # thrust profile
	  outFile << tostr(VarMassSG->Cells[i][6]) << endl;      // T or M
	  for (int j = 7; j <= VarMassSG->RowCount-1; j++) {
		string profile = tostr(VarMassSG->Cells[i][j]);
		replace(profile.begin(), profile.end(), ',', '\t');
		outFile << profile << endl;                          // thrust profile
	  }
	}
	outFile << "#" << endl;

	outFile << "A" << endl;
	outFile << to_string(AxialForceSG->ColCount - 1) <<  endl;  // # aerodynamic
	for (int i = 1; i <= AxialForceSG->ColCount - 1; i++) {
	  outFile << tostr(AerodynamicSG->Cells[i][0]) << endl;     // id
	  outFile << tostr(AerodynamicSG->Cells[i][1]) << endl;     // ref area
	  outFile << tostr(AxialForceSG->RowCount) << endl;         // # MCA
	  for (int j = 0; j <= AxialForceSG->RowCount - 1 ; j++) {
		string profile = tostr(AxialForceSG->Cells[i][j]);
		replace(profile.begin(), profile.end(), ',', '\t');
		outFile << profile << endl;                             // MCA profile
	  }
	  outFile << tostr(NormalForceSG->RowCount) << endl;        // # MCN
	  for (int j = 0; j <= NormalForceSG->RowCount - 1 ; j++) {
		string profile = tostr(NormalForceSG->Cells[i][j]);
		replace(profile.begin(), profile.end(), ',', '\t');
		outFile << profile << endl;                             // MCN profile
	  }
	  outFile << tostr(SideForceSG->RowCount) << endl;          // # MCY
	  for (int j = 0; j <= SideForceSG->RowCount - 1 ; j++) {
		string profile = tostr(SideForceSG->Cells[i][j]);
		replace(profile.begin(), profile.end(), ',', '\t');
		outFile << profile << endl;                             // MCY profile
	  }
	}
	outFile << "#" << endl;

	outFile << "N" << endl;
	outFile << tostr(EnvironmentsSG->Cells[1][0]) << endl;
	outFile << tostr(EnvironmentsSG->Cells[1][1]) << endl;
	outFile << "#" << endl;

	outFile << "I" << endl;
	outFile << tostr(InitialSG->Cells[1][0]) << "\t";
	outFile << tostr(InitialSG->Cells[1][1]) << "\t";
	outFile << tostr(InitialSG->Cells[1][2]) << "\n";
	outFile << tostr(InitialSG->Cells[1][3]) << "\t";
	outFile << tostr(InitialSG->Cells[1][4]) << "\t";
	outFile << tostr(InitialSG->Cells[1][5]) << "\n";
	outFile << "#" << endl;

	outFile << "P" << endl;
	outFile << to_string(PhaseSG->ColCount - 1) << " ";   // #phase
	outFile << tostr(PhaseInfoSG->Cells[1][0])  << " ";   // phase iip
	outFile << tostr(PhaseInfoSG->Cells[1][1])  << endl;  // iIIP rate
	outFile << tostr(PhaseInfoSG->Cells[1][2])  << endl;  // phase type
	outFile << tostr(PhaseInfoSG->Cells[1][3])  << endl;  // phase seq
	string flags;
	for (int i = 1; i <= PhaseSG->ColCount - 1; i++) {
	  outFile << tostr(PhaseSG->Cells[i][0]) << endl;     // id
	  outFile << tostr(PhaseSG->Cells[i][1]) << endl;     // end time
	  outFile << tostr(PhaseSG->Cells[i][2]) << endl;     // use a/d coeff.
	  flags = tostr(PhaseSG->Cells[i][3]);                // fix mass flags
	  replace(flags.begin(), flags.end(), ',', ' ');
	  outFile << flags << endl;
	  flags = tostr(PhaseSG->Cells[i][4]);                // var mass flags
	  replace(flags.begin(), flags.end(), ',', ' ');
	  outFile << flags << endl;
	  flags = tostr(PhaseSG->Cells[i][5]);                // var mass active
	  replace(flags.begin(), flags.end(), ',', ' ');
	  outFile << flags << endl;
	  outFile << tostr(PhaseSG->Cells[i][6]) << endl;      // control type
	  outFile << tostr(PhaseSG->Cells[i][7])  << "\t";
	  outFile << tostr(PhaseSG->Cells[i][8])  << endl;
	  outFile << tostr(PhaseSG->Cells[i][9])  << "\t";
	  outFile << tostr(PhaseSG->Cells[i][10]) << endl;
	  outFile << tostr(PhaseSG->Cells[i][11]) << endl;     // #grid
	}
	outFile << "#" << endl;

	outFile.close();
  }
}
//---------------------------------------------------------------------------

