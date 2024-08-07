//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <fstream>
#include <sstream>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void TForm1::LoadCSV(const String &fileName)
{
  std::string line;

  std::ifstream file(fileName.c_str());

  csvData.clear();

  while (std::getline(file, line)) {
	std::vector<std::string> row;
	std::istringstream s(line);
	std::string field;
	while (getline(s, field, ',')) {
	  row.push_back(field);
	}
	csvData.push_back(row);
  }
  file.close();
}

void TForm1::CreateCheckBoxes()
{
  checkBoxXMap.clear();
  ScrollBoxX->DisableAlign();
  ScrollBoxX->DestroyComponents();
  ScrollBoxX->EnableAlign();


  checkBoxYMap.clear();
  ScrollBoxY->DisableAlign();
  ScrollBoxY->DestroyComponents();
  ScrollBoxY->EnableAlign();

  if (!csvData.empty()) {
	for (size_t i = 0; i < csvData[0].size(); ++i) {
	  TCheckBox *checkBox = new TCheckBox(ScrollBoxX);

	  checkBox->Parent  = ScrollBoxX;
	  checkBox->Caption = csvData[0][i].c_str();
	  checkBox->Top     = i * 25;
	  checkBox->Left    = 10;
	  checkBox->OnClick = CheckBoxXClick;

	  checkBoxXMap[checkBox] = i;
	}

	for (size_t i = 0; i < csvData[0].size(); ++i) {
	  TCheckBox *checkBox = new TCheckBox(ScrollBoxY);

	  checkBox->Parent  = ScrollBoxY;
	  checkBox->Caption = csvData[0][i].c_str();
	  checkBox->Top     = i * 25;
	  checkBox->Left    = 10;
	  checkBox->OnClick = CheckBoxYClick;

	  checkBoxYMap[checkBox] = i;
	}
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBoxXClick(TObject *Sender)
{
  for (const auto &entry : checkBoxXMap) {
	TCheckBox *checkBox = entry.first;
	if (checkBox->Checked) {
	  colX = entry.second;
	}
  }

  UpdateChart();
}

void __fastcall TForm1::CheckBoxYClick(TObject *Sender)
{
  UpdateChart();
}

void TForm1::UpdateChart()
{
  Chart->SeriesList->Clear();

  for (const auto &entry : checkBoxYMap) {
	TCheckBox *checkBox = entry.first;
	int columnIndex     = entry.second;

	if (checkBox->Checked) {
	  TFastLineSeries *series = new TFastLineSeries(Chart);
	  Chart->AddSeries(series);

	  series->Title = checkBox->Caption;
	  series->LinePen->Width = 3;
	  series->Stairs = false;
	  for (size_t i = 1; i < csvData.size(); ++i) {
		double x = StrToFloatDef(csvData[i][colX].c_str(), 0);
		double y = StrToFloatDef(csvData[i][columnIndex].c_str(), 0);
		series->AddXY(x, y);
	  }
	}
  }

  Chart->Legend->Visible = Chart->SeriesCount() == 1 ? false : true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenCSV1Click(TObject *Sender)
{
  if (OpenDialog->Execute()) {
	LoadCSV(OpenDialog->FileName);
	CreateCheckBoxes();
  }
}
//---------------------------------------------------------------------------

