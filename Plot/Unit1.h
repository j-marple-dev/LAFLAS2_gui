//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <VCLTee.Series.hpp>
#include <Vcl.Menus.hpp>

#include <vector>
#include <string>
#include <map>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *OpenDialog;
	TMainMenu *MainMenu;
	TMenuItem *OpenCSV1;
	TMenuItem *OpenCSV2;
	TChart *Chart;
	TPanel *Panel1;
	TScrollBox *ScrollBoxX;
	TScrollBox *ScrollBoxY;
	TLabel *Label1;
	TLabel *Label2;
	void __fastcall CheckBoxXClick(TObject *Sender);
	void __fastcall CheckBoxYClick(TObject *Sender);

	void __fastcall OpenCSV1Click(TObject *Sender);
private:	// User declarations
	unsigned int colX;

	std::vector<std::vector<std::string>> csvData;

	std::map<TCheckBox*, int> checkBoxXMap;
	std::map<TCheckBox*, int> checkBoxYMap;

    void LoadCSV(const String &fileName);
    void UpdateChart();
	void CreateCheckBoxes();

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
