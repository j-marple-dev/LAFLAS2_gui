object FormOCF: TFormOCF
  Left = 0
  Top = 0
  Caption = 'LAFLAS Optimization Config Editor'
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
    OnResize = Panel1Resize
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
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 831
    Height = 680
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 1
    ExplicitHeight = 641
    object TabSheet1: TTabSheet
      Margins.Left = 10
      Margins.Top = 10
      Margins.Right = 10
      Margins.Bottom = 10
      object Label1: TLabel
        Left = 0
        Top = 113
        Width = 823
        Height = 60
        Margins.Top = 10
        Margins.Bottom = 10
        Align = alTop
        Caption = 
          '  Id  =  0  : Type = t, n, a, e'#13#10'  Id  < 100 : Type = p, y, t'#13#10' ' +
          ' Id >= 100 : Type = m'#13#10' '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 217
      end
      object OptParamSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 113
        Align = alTop
        ColCount = 2
        RowCount = 2
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnMouseUp = OnCommonMouseUp
        ExplicitTop = 8
      end
      object OptEqCnstrSG: TStringGrid
        Left = 0
        Top = 173
        Width = 823
        Height = 121
        Align = alTop
        ColCount = 2
        RowCount = 3
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 1
        OnMouseUp = OnCommonMouseUp
        ExplicitLeft = 8
        ExplicitTop = 121
      end
      object OptLbCnstrSG: TStringGrid
        Left = 0
        Top = 317
        Width = 823
        Height = 113
        Align = alTop
        ColCount = 2
        RowCount = 3
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 2
        OnMouseUp = OnCommonMouseUp
        ExplicitLeft = 8
        ExplicitTop = 360
      end
      object Panel6: TPanel
        Left = 0
        Top = 430
        Width = 823
        Height = 23
        Align = alTop
        TabOrder = 3
        ExplicitLeft = 16
        ExplicitTop = 440
      end
      object Panel3: TPanel
        Left = 0
        Top = 294
        Width = 823
        Height = 23
        Align = alTop
        TabOrder = 4
        ExplicitLeft = 3
        ExplicitTop = 286
      end
      object OptUbCnstrSG: TStringGrid
        Left = 0
        Top = 453
        Width = 823
        Height = 96
        Align = alTop
        ColCount = 2
        RowCount = 3
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 5
        OnMouseUp = OnCommonMouseUp
        ExplicitTop = 528
        ExplicitWidth = 831
      end
    end
  end
  object SaveDialog: TSaveDialog
    Left = 592
    Top = 688
  end
  object OpenDialog: TOpenDialog
    Left = 536
    Top = 688
  end
  object CommonPopup: TPopupMenu
    Left = 648
    Top = 688
    object AddColumn: TMenuItem
      Caption = 'Add Column'
      OnClick = CommonAddClick
    end
    object DelColumn: TMenuItem
      Caption = 'Delete Column'
      OnClick = CommonDelClick
    end
  end
end
