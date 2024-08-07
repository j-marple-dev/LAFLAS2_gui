//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

#include "FormEditLV.h"
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
  VarMassSG->ColWidths[1] = 200;
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

  PhaseSG->ColWidths[0]  = 200;  PhaseSG->Cells[0][0]  = "Id";                 PhaseSG->Cells[0][1]  = " ";
  PhaseSG->ColWidths[1]  = 120;  PhaseSG->Cells[1][0]  = "End Time";           PhaseSG->Cells[1][1]  = "[sec]";
  PhaseSG->ColWidths[2]  = 180;  PhaseSG->Cells[2][0]  = "Aerodynamic Flag";   PhaseSG->Cells[2][1]  = "[0 | 1]";
  PhaseSG->ColWidths[3]  = 180;  PhaseSG->Cells[3][0]  = "FixMass Attatched";  PhaseSG->Cells[3][1]  = "[0|1]+(,[0|1]+)*";
  PhaseSG->ColWidths[4]  = 180;  PhaseSG->Cells[4][0]  = "VarMass Attatched";  PhaseSG->Cells[4][1]  = "[0|1]+(,[0|1]+)*";
  PhaseSG->ColWidths[5]  = 150;  PhaseSG->Cells[5][0]  = "VarMass Active";     PhaseSG->Cells[5][1]  = "[0|1]+(,[0|1]+)*";
  PhaseSG->ColWidths[6]  = 120;  PhaseSG->Cells[6][0]  = "Control Type";       PhaseSG->Cells[6][1]  = "[p|q|r|i|s|g|a]";
  PhaseSG->ColWidths[7]  = 150;  PhaseSG->Cells[7][0]  = "Pitch_s | Alpha_s";  PhaseSG->Cells[7][1]  = "[deg]";
  PhaseSG->ColWidths[8]  = 150;  PhaseSG->Cells[8][0]  = "Pitch_e | Alpha_e";  PhaseSG->Cells[8][1]  = "[deg]";
  PhaseSG->ColWidths[9]  = 150;  PhaseSG->Cells[9][0]  = "Yaw_s | Beta_s";     PhaseSG->Cells[9][1]  = "[deg]";
  PhaseSG->ColWidths[10] = 150;  PhaseSG->Cells[10][0] = "Yaw_e | Beta_e";     PhaseSG->Cells[10][1] = "[deg]";
  PhaseSG->ColWidths[11] = 120;  PhaseSG->Cells[11][0] = "Grid Number";
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

void __fastcall TEditLVForm::MainPageControlChange(TObject *Sender)
{
/*
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
*/
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::PhaseSGMouseMove(TObject *Sender, TShiftState Shift,
		  int X, int Y)
{
  int ACol, ARow;

  PhaseSG->MouseToCell(X, Y, ACol, ARow);
  if (ACol == 6) {
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
  SaveDialog->Title       = "Save Launch Vehicle File";
  SaveDialog->Filter      = "LV File (*.lv)|*.lv|LAFLAS 1 File (*.dat)|*.dat";
  SaveDialog->FilterIndex = 1;
  SaveDialog->DefaultExt  = "lv";

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
		replace(profile.begin(), profile.end(), ',', ' ');
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
		replace(profile.begin(), profile.end(), ',', ' ');
		outFile << profile << endl;                             // MCA profile
	  }
	  outFile << tostr(NormalForceSG->RowCount) << endl;        // # MCN
	  for (int j = 0; j <= NormalForceSG->RowCount - 1 ; j++) {
		string profile = tostr(NormalForceSG->Cells[i][j]);
		replace(profile.begin(), profile.end(), ',', ' ');
		outFile << profile << endl;                             // MCN profile
	  }
	  outFile << tostr(SideForceSG->RowCount) << endl;          // # MCY
	  for (int j = 0; j <= SideForceSG->RowCount - 1 ; j++) {
		string profile = tostr(SideForceSG->Cells[i][j]);
		replace(profile.begin(), profile.end(), ',', ' ');
		outFile << profile << endl;                             // MCY profile
	  }
	}
	outFile << "#" << endl;

	outFile << "N" << endl;
	outFile << tostr(EnvironmentsSG->Cells[1][0]) << " ";
	outFile << tostr(EnvironmentsSG->Cells[1][1]) << endl;
	outFile << "#" << endl;

	outFile << "I" << endl;
	outFile << tostr(InitialSG->Cells[1][0]) << " ";
	outFile << tostr(InitialSG->Cells[1][1]) << " ";
	outFile << tostr(InitialSG->Cells[1][2]) << "\n";
	outFile << tostr(InitialSG->Cells[1][3]) << " ";
	outFile << tostr(InitialSG->Cells[1][4]) << " ";
	outFile << tostr(InitialSG->Cells[1][5]) << "\n";
	outFile << "#" << endl;

	outFile << "P" << endl;
	outFile << to_string(PhaseSG->RowCount - 1) << " ";   // #phase
	outFile << tostr(PhaseInfoSG->Cells[1][0])  << " ";   // phase iip
	outFile << tostr(PhaseInfoSG->Cells[1][1])  << endl;  // iIIP rate
	outFile << tostr(PhaseInfoSG->Cells[1][2])  << endl;  // phase type
	outFile << tostr(PhaseInfoSG->Cells[1][3])  << endl;  // phase seq
	string flags;
	for (int i = 2; i <= PhaseSG->RowCount - 1; i++) {
	  outFile << tostr(PhaseSG->Cells[0][i]) << endl;     // id
	  outFile << tostr(PhaseSG->Cells[1][i]) << endl;     // end time
	  outFile << tostr(PhaseSG->Cells[2][i]) << endl;     // use a/d coeff.
	  flags = tostr(PhaseSG->Cells[3][i]);                // fix mass flags
	  replace(flags.begin(), flags.end(), ',', ' ');
	  outFile << flags << endl;
	  flags = tostr(PhaseSG->Cells[4][i]);                // var mass flags
	  replace(flags.begin(), flags.end(), ',', ' ');
	  outFile << flags << endl;
	  flags = tostr(PhaseSG->Cells[5][i]);                // var mass active
	  replace(flags.begin(), flags.end(), ',', ' ');
	  outFile << flags << endl;
	  outFile << tostr(PhaseSG->Cells[6][i])  << endl;    // control type
	  outFile << tostr(PhaseSG->Cells[7][i])  << " ";
	  outFile << tostr(PhaseSG->Cells[8][i])  << endl;
	  outFile << tostr(PhaseSG->Cells[9][i])  << " ";
	  outFile << tostr(PhaseSG->Cells[10][i]) << endl;
	  outFile << tostr(PhaseSG->Cells[11][i]) << endl;    // #grid
	}
	outFile << "#" << endl;
	outFile << "E";
	outFile.close();
  }
}
//---------------------------------------------------------------------------

void LoadFixMass(ifstream &inFile, TStringGrid *sg)
{
  string line;


  getline(inFile, line);
  int count = stoi(line);
  sg->ColCount = count + 1;

  for (int i = 1; i <= count; i++) {
	sg->ColWidths[i] = 150;

	getline(inFile, line);                   // id.
	sg->Cells[i][0] = line.c_str();

	getline(inFile, line);                   // quantity
	sg->Cells[i][1] = line.c_str();

	getline(inFile, line);                   // mass
	sg->Cells[i][2] = line.c_str();
  }
}

void LoadVarMass(ifstream &inFile, TStringGrid *sg)
{
  string line;


  getline(inFile, line);
  int count = stoi(line);
  sg->ColCount = count + 1;

  for (int i = 1; i <= count; i++) {
	sg->ColWidths[i] = 200;

	getline(inFile, line);                   // id.
	sg->Cells[i][0] = line.c_str();

	getline(inFile, line);                   // quantity
	sg->Cells[i][1] = line.c_str();

	getline(inFile, line);                   // structural mass
	sg->Cells[i][2] = line.c_str();

	getline(inFile, line);                   // propellant mass
	sg->Cells[i][3] = line.c_str();

	getline(inFile, line);                   // isp
	sg->Cells[i][4] = line.c_str();

	getline(inFile, line);                   // nozzle area
	sg->Cells[i][5] = line.c_str();

	getline(inFile, line);                   // #thrust profile
	int rowCount = stoi(line);
	sg->RowCount = 7 + rowCount;

	getline(inFile, line);                   // T or M
	sg->Cells[i][6] = line.c_str();

	string num1, num2;
	for (int j = 7; j < 7+rowCount; j++) {
	  getline(inFile, line);
	  istringstream iss(line);
	  iss >> num1 >> num2;
	  line = num1 + ", " + num2;
	  sg->Cells[i][j] = line.c_str();
	}
  }
}

void LoadAerodynamics(ifstream &inFile, TStringGrid *adSG, TStringGrid *afSG, TStringGrid *nfSG, TStringGrid *sfSG)
{
  string line;
  int    rowCount;


  getline(inFile, line);
  int count = stoi(line);
  adSG->ColCount = count + 1;
  afSG->ColCount = count + 1;
  nfSG->ColCount = count + 1;
  sfSG->ColCount = count + 1;

  for (int i = 1; i <= count; i++) {
	adSG->ColWidths[i] = 150;
	afSG->ColWidths[i] = 150;
	nfSG->ColWidths[i] = 150;
	sfSG->ColWidths[i] = 150;

	getline(inFile, line);                   // id.
	adSG->Cells[i][0] = line.c_str();

	getline(inFile, line);                   // ref area
	adSG->Cells[i][1] = line.c_str();

	getline(inFile, line);                 // #axial force
	rowCount = stoi(line);
	afSG->RowCount = rowCount;

	string num1, num2;
	for (int j = 0; j < rowCount; j++) {
	  getline(inFile, line);
	  istringstream iss(line);
	  iss >> num1 >> num2;
	  line = num1 + ", " + num2;
	  afSG->Cells[i][j] = line.c_str();
	}

	getline(inFile, line);                 // #normal force
	rowCount = stoi(line);
	nfSG->RowCount = rowCount;

	for (int j = 0; j < rowCount; j++) {
	  getline(inFile, line);
	  istringstream iss(line);
	  iss >> num1 >> num2;
	  line = num1 + ", " + num2;
	  nfSG->Cells[i][j] = line.c_str();
	}

	getline(inFile, line);                 // #side force
	rowCount = stoi(line);
	sfSG->RowCount = rowCount;

	for (int j = 0; j < rowCount; j++) {
	  getline(inFile, line);
	  istringstream iss(line);
	  iss >> num1 >> num2;
	  line = num1 + ", " + num2;
	  sfSG->Cells[i][j] = line.c_str();
	}
  }
}

void LoadEnvironments(ifstream &inFile, TStringGrid *sg)
{
  string line;

  string earth;
  string air;


  getline(inFile, line);
  istringstream iss(line);
  iss >> earth >> air;

  sg->Cells[1][0] = earth.c_str();
  sg->Cells[1][1] = air.c_str();
}

void LoadInitialCondition(ifstream &inFile, TStringGrid *sg)
{
  string line;

  string lat0, lon0, alt0;
  string azi0, pat0, vel0;


  getline(inFile, line);
  istringstream iss(line);
  iss >> lat0 >> lon0 >> alt0;

  getline(inFile, line);
  istringstream iss2(line);            // iss.str(line) is not working
  iss2 >> azi0 >> pat0 >> vel0;

  sg->Cells[1][0] = lat0.c_str();
  sg->Cells[1][1] = lon0.c_str();
  sg->Cells[1][2] = alt0.c_str();
  sg->Cells[1][3] = azi0.c_str();
  sg->Cells[1][4] = pat0.c_str();
  sg->Cells[1][5] = vel0.c_str();
}

void LoadPhase(ifstream &inFile, TStringGrid *infoSG, TStringGrid *phaseSG)
{
  string line;
  string str1, str2, str3;

  int phaseCount;


  getline(inFile, line);
  istringstream iss(line);
  iss >> str1 >> str2 >> str3;
  phaseCount          = stoi(str1);      // #phase
  infoSG->Cells[1][0] = str2.c_str();    // #iip
  infoSG->Cells[1][1] = str3.c_str();    // #iip rate

  getline(inFile, line);
  infoSG->Cells[1][2] = line.c_str();    // phase type

  getline(inFile, line);
  infoSG->Cells[1][3] = line.c_str();    // phase sequence

  phaseSG->RowCount = phaseCount + 2;
  for (int i = 2; i <= phaseCount; i++) {
	//phaseSG->ColWidths[i] = 100;

	getline(inFile, line);
	phaseSG->Cells[0][i] = line.c_str();

	getline(inFile, line);
	phaseSG->Cells[1][i] = line.c_str();

	getline(inFile, line);
	phaseSG->Cells[2][i] = line.c_str();

	getline(inFile, line);                           // fixmass attatched flags
	stringstream ss3(line);
	string result3;
	while (ss3 >> str1) {
	  if (!result3.empty()) {
		result3 += ", ";
	  }
	  result3 += str1;
	}
	phaseSG->Cells[3][i] = result3.c_str();

	getline(inFile, line);
	stringstream ss4(line);
	string result4;
	while (ss4 >> str1) {
	  if (!result4.empty()) {
		result4 += ", ";
	  }
	  result4 += str1;
	}
	phaseSG->Cells[4][i] = result4.c_str();

	getline(inFile, line);
	stringstream ss5(line);
	string result5;
	while (ss5 >> str1) {
	  if (!result5.empty()) {
		result5 += ", ";
	  }
	  result5 += str1;
	}
	phaseSG->Cells[5][i] = result5.c_str();

	getline(inFile, line);
	phaseSG->Cells[6][i] = line.c_str();

	getline(inFile, line);
	istringstream ss7(line);
	int j = 7;
	while (ss7 >> str1) {
	  phaseSG->Cells[j][i] = str1.c_str();
	  j++;
	}

	getline(inFile, line);
	istringstream ss9(line);
	j = 9;
	while (ss9 >> str1) {
	  phaseSG->Cells[j][i] = str1.c_str();
	  j++;
	}

	getline(inFile, line);
	phaseSG->Cells[11][i] = line.c_str();
  }
}

void __fastcall TEditLVForm::LoadButtonClick(TObject *Sender)
{
  OpenDialog->Title       = "Load Launch Vehicle File";
  OpenDialog->Filter      = "LV File (*.lv)|*.lv|LAFLAS 1 File (*.dat)|*.dat";
  OpenDialog->FilterIndex = 1;

  if (OpenDialog->Execute()) {
	String filePath = OpenDialog->FileName;

	ifstream inFile(filePath.c_str());
	if (!inFile) {
	  ShowMessage("Cannot find: " + filePath);
	  return;
	}

	int    i;
	int    count;
	string line;

	while (getline(inFile, line)) {   // false when eof
	  switch (line[0]) {
	  case 'F': LoadFixMass(inFile, FixMassSG); 	break;
	  case 'V': LoadVarMass(inFile, VarMassSG);		break;
	  case 'A': LoadAerodynamics(inFile, AerodynamicSG, AxialForceSG, NormalForceSG, SideForceSG);  break;
	  case 'N': LoadEnvironments(inFile, EnvironmentsSG);  break;
	  case 'I': LoadInitialCondition(inFile, InitialSG);   break;
	  case 'P': LoadPhase(inFile, PhaseInfoSG, PhaseSG);   break;
	  case 'T':
		break;

	  default:
		break;
	  }

	}



	inFile.close();
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::FormResize(TObject *Sender)
{
  PhaseSG->Width = PhaseInfoSG->Width; //this->ClientWidth - 20;
}
//---------------------------------------------------------------------------


static TStringGrid *CommonSG;

void __fastcall TEditLVForm::CommonAddClick(TObject *Sender)
{
  int curCol = CommonSG->Tag;

  CommonSG->ColCount += 1;
  CommonSG->ColWidths[CommonSG->ColCount - 1] = CommonSG->ColWidths[1];

  if (curCol == CommonSG->ColCount - 1) {
	return;
  }

  for (int i = CommonSG->ColCount - 1; i > curCol + 1; i--) {
	for (int j = 0; j < CommonSG->RowCount; j++) {
	  CommonSG->Cells[i][j] = CommonSG->Cells[i-1][j];
	}
  }

  for (int j = 0; j < CommonSG->RowCount; j++) {
	CommonSG->Cells[curCol+1][j] = "";
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::CommonDelClick(TObject *Sender)
{
  int curCol = CommonSG->Tag;

  if (curCol == 0) {
	return;
  }
  if (curCol == 1 && CommonSG->ColCount == 2) {
	for (int j = 0; j < CommonSG->RowCount; j++) {
	  CommonSG->Cells[curCol][j] = "";
	}
	return;
  }


  for (int i = curCol; i < CommonSG->ColCount - 1; i++) {
	for (int j = 0; j < CommonSG->RowCount; j++)	{
	  CommonSG->Cells[i][j] = CommonSG->Cells[i+1][j];
	}
  }
  CommonSG->ColCount -= 1;
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::CommonSGMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  TStringGrid *grid = dynamic_cast<TStringGrid*>(Sender);

  if (Button == mbRight) {
	int ACol, ARow;
	grid->MouseToCell(X, Y, ACol, ARow);

	if (ACol == -1 || ARow == -1) {
	  return;
	}

	CommonSG = grid;
	CommonSG->Tag = ACol;

	TPoint point = CommonSG->ClientToScreen(Point(X, Y));
	CommonPopupMenu->Popup(point.x, point.y);
  }
}
//---------------------------------------------------------------------------

static TStringGrid *CommonAeroSG;

void __fastcall TEditLVForm::AerodynamicAddClick(TObject *Sender)
{
  CommonSG = AerodynamicSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonAddClick(Sender);

  CommonSG = AxialForceSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonAddClick(Sender);

  CommonSG = NormalForceSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonAddClick(Sender);

  CommonSG = SideForceSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonAddClick(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::AerodynamicDelClick(TObject *Sender)
{
  CommonSG = AerodynamicSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonDelClick(Sender);

  CommonSG = AxialForceSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonDelClick(Sender);

  CommonSG = NormalForceSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonDelClick(Sender);

  CommonSG = SideForceSG;
  CommonSG->Tag = CommonAeroSG->Tag;
  CommonDelClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::CommonAeroSGMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  TStringGrid *grid = dynamic_cast<TStringGrid*>(Sender);

  if (Button == mbRight) {
	int ACol, ARow;
	grid->MouseToCell(X, Y, ACol, ARow);

	if (ACol == -1 || ARow == -1) {
	  return;
	}

	CommonAeroSG = grid;
	CommonAeroSG->Tag = ACol;

	TPoint point = CommonAeroSG->ClientToScreen(Point(X, Y));
	AerodynamicPopup->Popup(point.x, point.y);
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::PhaseSGMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  if (Button == mbRight) {
	int ACol, ARow;
	PhaseSG->MouseToCell(X, Y, ACol, ARow);

	if (ACol == -1 || ARow == -1 || ARow == 0) {
	  return;
	}

	PhaseSG->Tag = ARow;

	TPoint point = PhaseSG->ClientToScreen(Point(X, Y));
	PhasePopup->Popup(point.x, point.y);
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::AddPhaseClick(TObject *Sender)
{
  int curRow = PhaseSG->Tag;


  PhaseSG->RowCount += 1;

  if (curRow == PhaseSG->RowCount - 1) {
	return;
  }

  for (int i = PhaseSG->RowCount - 1; i > curRow+1; i--) {
	for (int j = 0; j < PhaseSG->ColCount; j++) {
	  PhaseSG->Cells[j][i] = PhaseSG->Cells[j][i-1];
	}
  }

  for (int j = 0; j < PhaseSG->ColCount; j++) {
	PhaseSG->Cells[j][curRow+1] = "";
  }
}
//---------------------------------------------------------------------------

void __fastcall TEditLVForm::DelPhaseClick(TObject *Sender)
{
  int curRow = PhaseSG->Tag;

  if (curRow == 0 || curRow == 1) {
	return;
  }
  if (curRow == 2 && PhaseSG->RowCount == 3) {
	for (int j = 0; j < PhaseSG->ColCount; j++) {
	  PhaseSG->Cells[j][curRow] = "";
	}
	return;
  }


  for (int i = curRow; i < PhaseSG->RowCount - 1; i++) {
	for (int j = 0; j < PhaseSG->ColCount; j++)	{
	  PhaseSG->Cells[j][i] = PhaseSG->Cells[j][i+1];
	}
  }
  PhaseSG->RowCount -= 1;
}
//---------------------------------------------------------------------------


