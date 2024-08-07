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
void __fastcall TFormOCF::AddParamButtonClick(TObject *Sender)
{
  OptParamSG->ColCount += 1;
  OptParamSG->ColWidths[OptParamSG->ColCount - 1] = 50;
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::DelParamButtonClick(TObject *Sender)
{
  if (OptParamSG->ColCount == 1) {
	return;
  }
  OptParamSG->ColCount -= 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::AddEqCnstrButtonClick(TObject *Sender)
{
  OptEqCnstrSG->ColCount += 1;
  OptEqCnstrSG->ColWidths[OptEqCnstrSG->ColCount - 1] = 60;
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::AddLbCnstrButtonClick(TObject *Sender)
{
  OptLbCnstrSG->ColCount += 1;
  OptLbCnstrSG->ColWidths[OptLbCnstrSG->ColCount - 1] = 60;
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::DelLbCnstrButtonClick(TObject *Sender)
{
  if (OptLbCnstrSG->ColCount == 1) {
	return;
  }
  OptLbCnstrSG->ColCount -= 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::AddUbCnstrButtonClick(TObject *Sender)
{
  OptUbCnstrSG->ColCount += 1;
  OptUbCnstrSG->ColWidths[OptUbCnstrSG->ColCount - 1] = 60;
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::DelUbCnstrButtonClick(TObject *Sender)
{
  if (OptUbCnstrSG->ColCount == 1) {
	return;
  }
  OptUbCnstrSG->ColCount -= 1;
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::DelEqCnstrButtonClick(TObject *Sender)
{
  if (OptEqCnstrSG->ColCount == 1) {
	return;
  }
  OptEqCnstrSG->ColCount -= 1;
}

using namespace std;

string tostr(String str)
{
  AnsiString temp = str;

  return string(temp.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::SaveButtonClick(TObject *Sender)
{
  SaveDialog->Title = "Save Optimization Configuration File";
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
  OptParamSG->Cells[0][0] = "Id.";
  OptParamSG->Cells[0][1] = "Type";

  OptEqCnstrSG->ColWidths[0] = 100;
  OptEqCnstrSG->ColWidths[1] = 80;
  OptEqCnstrSG->Cells[0][0] = "Cstr P";
  OptEqCnstrSG->Cells[0][1] = "Cstr N";
  OptEqCnstrSG->Cells[0][2] = "Cstr V";

  OptLbCnstrSG->ColWidths[0] = 100;
  OptLbCnstrSG->ColWidths[1] = 80;
  OptLbCnstrSG->Cells[0][0] = "Cstr P";
  OptLbCnstrSG->Cells[0][1] = "Cstr N";
  OptLbCnstrSG->Cells[0][2] = "Cstr V";

  OptUbCnstrSG->ColWidths[0] = 100;
  OptUbCnstrSG->ColWidths[1] = 80;
  OptUbCnstrSG->Cells[0][0] = "Cstr P";
  OptUbCnstrSG->Cells[0][1] = "Cstr N";
  OptUbCnstrSG->Cells[0][2] = "Cstr V";
}
//---------------------------------------------------------------------------
void __fastcall TFormOCF::LoadButtonClick(TObject *Sender)
{
  OpenDialog->Title = "Load Optimization Configuration File";
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
