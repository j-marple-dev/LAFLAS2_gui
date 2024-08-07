object FormOCF: TFormOCF
  Left = 0
  Top = 0
  Caption = 'Optimization Configuration Editor'
  ClientHeight = 722
  ClientWidth = 831
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 680
    Width = 831
    Height = 42
    Align = alBottom
    BevelOuter = bvNone
    Color = clGrayText
    ParentBackground = False
    TabOrder = 0
    ExplicitTop = 663
    ExplicitWidth = 825
    object LoadButton: TButton
      Left = 296
      Top = 9
      Width = 75
      Height = 25
      Caption = 'Load'
      TabOrder = 0
      OnClick = LoadButtonClick
    end
    object SaveButton: TButton
      Left = 416
      Top = 9
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 1
      OnClick = SaveButtonClick
    end
  end
  object OptParamSG: TStringGrid
    Left = 0
    Top = 0
    Width = 831
    Height = 113
    Hint = 
      'Id  =  0 :     Type = t, n, a, e'#13#10'Id < 100 :   Type = p, y, t'#13#10'I' +
      'd >= 100 : Type = m'
    Align = alTop
    ColCount = 2
    RowCount = 2
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Consolas'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    ExplicitWidth = 823
  end
  object AddParamButton: TButton
    Left = 19
    Top = 119
    Width = 85
    Height = 25
    Caption = 'Add param'
    TabOrder = 2
    OnClick = AddParamButtonClick
  end
  object DelParamButton: TButton
    Left = 110
    Top = 119
    Width = 85
    Height = 25
    Caption = 'Delete param'
    TabOrder = 3
    OnClick = DelParamButtonClick
  end
  object OptEqCnstrSG: TStringGrid
    Left = 0
    Top = 176
    Width = 831
    Height = 121
    ColCount = 2
    RowCount = 3
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Consolas'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
    ParentFont = False
    TabOrder = 4
  end
  object AddEqCnstrButton: TButton
    Left = 19
    Top = 303
    Width = 85
    Height = 25
    Caption = 'Add EQ cnstr.'
    TabOrder = 5
    OnClick = AddEqCnstrButtonClick
  end
  object DelEqCnstrButton: TButton
    Left = 110
    Top = 303
    Width = 85
    Height = 25
    Caption = 'Delete EQ cnstr.'
    TabOrder = 6
    OnClick = DelEqCnstrButtonClick
  end
  object OptLbCnstrSG: TStringGrid
    Left = 8
    Top = 360
    Width = 823
    Height = 113
    ColCount = 2
    RowCount = 3
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Consolas'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
    ParentFont = False
    TabOrder = 7
  end
  object AddLbCnstrButton: TButton
    Left = 16
    Top = 479
    Width = 85
    Height = 25
    Caption = 'Add LB cnstr.'
    TabOrder = 8
    OnClick = AddLbCnstrButtonClick
  end
  object DelLbCnstrButton: TButton
    Left = 107
    Top = 479
    Width = 85
    Height = 25
    Caption = 'Del LB cnstr.'
    TabOrder = 9
    OnClick = DelLbCnstrButtonClick
  end
  object OptUbCnstrSG: TStringGrid
    Left = 0
    Top = 528
    Width = 831
    Height = 96
    ColCount = 2
    RowCount = 3
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Consolas'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
    ParentFont = False
    TabOrder = 10
  end
  object AddUbCnstrButton: TButton
    Left = 19
    Top = 630
    Width = 85
    Height = 25
    Caption = 'Add UB cnstr.'
    TabOrder = 11
    OnClick = AddUbCnstrButtonClick
  end
  object DelUbCnstrButton: TButton
    Left = 110
    Top = 630
    Width = 85
    Height = 25
    Caption = 'Delete UB cnstr.'
    TabOrder = 12
    OnClick = DelUbCnstrButtonClick
  end
  object SaveDialog: TSaveDialog
    Left = 776
    Top = 640
  end
  object OpenDialog: TOpenDialog
    Left = 720
    Top = 640
  end
end
