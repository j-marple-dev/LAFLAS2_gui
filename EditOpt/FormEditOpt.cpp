//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "FormEditOpt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOCF *FormOCF;
//---------------------------------------------------------------------------
__fastcall TFormOCF::TFormOCF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


using namespace std;

string tostr(String str)
{
  AnsiString temp = str;

  return string(temp.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::SaveButtonClick(TObject *Sender)
{
  SaveDialog->Title       = "Save Optimization Config File";
  SaveDialog->Filter      = "OCF File (*.ocf)|*.ocf|LAFLAS 1 File (*.dat)|*.dat";
  SaveDialog->FilterIndex = 1;
  SaveDialog->DefaultExt  = "ocf";

  if (SaveDialog->Execute()) {
	String fileName = SaveDialog->FileName;

	ofstream outFile(fileName.c_str());

	outFile << to_string(OptParamSG->ColCount - 1) <<  endl;  // #parameters
	for (int i = 1; i <= OptParamSG->ColCount - 1; i++) {
	  outFile << tostr(OptParamSG->Cells[i][0]) << "\t";      // id
	  outFile << tostr(OptParamSG->Cells[i][1]) << endl;      // type
	}
	outFile << "#" << endl;

	outFile << to_string(OptEqCnstrSG->ColCount - 1) <<  endl; // #eq constraints
	for (int i = 1; i <= OptEqCnstrSG->ColCount - 1; i++) {
	  outFile << tostr(OptEqCnstrSG->Cells[i][0]) << "\t";     // cstr p
	  outFile << tostr(OptEqCnstrSG->Cells[i][1]) << "\t";     // cstr n
	  outFile << tostr(OptEqCnstrSG->Cells[i][2]) << endl;     // cstr v
	}
	outFile << "#" << endl;

	outFile << to_string(OptLbCnstrSG->ColCount - 1) <<  endl; // #lb constraints
	for (int i = 1; i <= OptLbCnstrSG->ColCount - 1; i++) {
	  outFile << tostr(OptLbCnstrSG->Cells[i][0]) << "\t";     // cstr p
	  outFile << tostr(OptLbCnstrSG->Cells[i][1]) << "\t";     // cstr n
	  outFile << tostr(OptLbCnstrSG->Cells[i][2]) << endl;     // cstr v
	}
	outFile << "#" << endl;

	outFile << to_string(OptUbCnstrSG->ColCount - 1) <<  endl; // #ub constraints
	for (int i = 1; i <= OptUbCnstrSG->ColCount - 1; i++) {
	  outFile << tostr(OptUbCnstrSG->Cells[i][0]) << "\t";    // cstr p
	  outFile << tostr(OptUbCnstrSG->Cells[i][1]) << "\t";    // cstr n
	  outFile << tostr(OptUbCnstrSG->Cells[i][2]) << endl;    // cstr v
	}
	outFile << "#" << endl;

	outFile << "E";
	outFile.close();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::FormCreate(TObject *Sender)
{
  OptParamSG->ColWidths[0] = 60;
  OptParamSG->ColWidths[1] = 50;
  OptParamSG->Cells[0][0] = "Id";
  OptParamSG->Cells[0][1] = "Type";

  OptEqCnstrSG->ColWidths[0] = 150;
  OptEqCnstrSG->ColWidths[1] = 80;
  OptEqCnstrSG->Cells[0][0] = "Constraint P";
  OptEqCnstrSG->Cells[0][1] = "Constraint N";
  OptEqCnstrSG->Cells[0][2] = "Constraint V";

  OptLbCnstrSG->ColWidths[0] = 150;
  OptLbCnstrSG->ColWidths[1] = 80;
  OptLbCnstrSG->Cells[0][0] = "Constraint P";
  OptLbCnstrSG->Cells[0][1] = "Constraint N";
  OptLbCnstrSG->Cells[0][2] = "Constraint V";

  OptUbCnstrSG->ColWidths[0] = 150;
  OptUbCnstrSG->ColWidths[1] = 80;
  OptUbCnstrSG->Cells[0][0] = "Constraint P";
  OptUbCnstrSG->Cells[0][1] = "Constraint N";
  OptUbCnstrSG->Cells[0][2] = "Constraint V";
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::LoadButtonClick(TObject *Sender)
{
  OpenDialog->Title       = "Load Optimization Config File";
  OpenDialog->Filter      = "OCF File (*.ocf)|*.ocf|LAFLAS 1 File (*.dat)|*.dat";
  OpenDialog->FilterIndex = 1;

  if (OpenDialog->Execute()) {
	String filePath = OpenDialog->FileName;

	ifstream inFile(filePath.c_str());
	if (!inFile) {
	  ShowMessage("Cannot find: " + filePath);
	  return;
	}

	string line;
	int    count;

	getline(inFile, line);
	count = stoi(line);
	OptParamSG->ColCount = count + 1;

	for (int i = 1; i <= count; i++) {
	  OptParamSG->ColWidths[i] = 50;

	  getline(inFile, line);

	  vector<std::string> tokens;
	  string token;

	  istringstream iss(line);
	  while (iss >> token) {
		tokens.push_back(token);
	  }
	  OptParamSG->Cells[i][0] = tokens[0].c_str();
	  OptParamSG->Cells[i][1] = tokens[1].c_str();

	  tokens.clear();
	}
	getline(inFile, line);   // #

	getline(inFile, line);
	count = stoi(line);
	OptEqCnstrSG->ColCount = count + 1;

	for (int i = 1; i <= count; i++) {
	  OptEqCnstrSG->ColWidths[i] = 80;

	  getline(inFile, line);

	  vector<std::string> tokens;
	  string token;

	  istringstream iss(line);
	  while (iss >> token) {
		tokens.push_back(token);
	  }
	  OptEqCnstrSG->Cells[i][0] = tokens[0].c_str();
	  OptEqCnstrSG->Cells[i][1] = tokens[1].c_str();
	  OptEqCnstrSG->Cells[i][2] = tokens[2].c_str();

	  tokens.clear();
	}
	getline(inFile, line);   // #


	getline(inFile, line);
	count = stoi(line);
	OptLbCnstrSG->ColCount = count + 1;

	for (int i = 1; i <= count; i++) {
	  OptLbCnstrSG->ColWidths[i] = 80;

	  getline(inFile, line);

	  vector<std::string> tokens;
	  string token;

	  istringstream iss(line);
	  while (iss >> token) {
		tokens.push_back(token);
	  }
	  OptLbCnstrSG->Cells[i][0] = tokens[0].c_str();
	  OptLbCnstrSG->Cells[i][1] = tokens[1].c_str();
	  OptLbCnstrSG->Cells[i][2] = tokens[2].c_str();

	  tokens.clear();
	}
	getline(inFile, line);   // #

	getline(inFile, line);
	count = stoi(line);
	OptUbCnstrSG->ColCount = count + 1;

	for (int i = 1; i <= count; i++) {
	  OptUbCnstrSG->ColWidths[i] = 80;

	  getline(inFile, line);

	  vector<std::string> tokens;
	  string token;

	  istringstream iss(line);
	  while (iss >> token) {
		tokens.push_back(token);
	  }
	  OptUbCnstrSG->Cells[i][0] = tokens[0].c_str();
	  OptUbCnstrSG->Cells[i][1] = tokens[1].c_str();
	  OptUbCnstrSG->Cells[i][2] = tokens[2].c_str();

	  tokens.clear();
	}
	getline(inFile, line);   // #

	inFile.close();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::Panel1Resize(TObject *Sender)
{
  int panelCenterX = Panel1->Width / 2;
  int panelCenterY = Panel1->Height / 2;

  int buttonWidth = LoadButton->Width + SaveButton->Width;

  int spacing = 50;

  int totalWidth = buttonWidth + spacing;
  int startX = panelCenterX - (totalWidth / 2);

  LoadButton->Left = startX;
  LoadButton->Top  = panelCenterY - (LoadButton->Height / 2);

  SaveButton->Left = startX + SaveButton->Width + spacing;
  SaveButton->Top  = panelCenterY - (SaveButton->Height / 2);
}
//---------------------------------------------------------------------------

static TStringGrid *CommonSG;

void __fastcall TFormOCF::CommonAddClick(TObject *Sender)
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

void __fastcall TFormOCF::CommonDelClick(TObject *Sender)
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

void __fastcall TFormOCF::OnCommonMouseUp(TObject *Sender, TMouseButton Button,
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
	CommonPopup->Popup(point.x, point.y);
  }
}
//---------------------------------------------------------------------------



