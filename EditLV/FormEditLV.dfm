object EditLVForm: TEditLVForm
  Left = 0
  Top = 0
  Caption = 'LAFLAS Launch Vehicle Editor'
  ClientHeight = 722
  ClientWidth = 831
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  OnResize = FormResize
  TextHeight = 15
  object MainPageControl: TPageControl
    Left = 0
    Top = 0
    Width = 831
    Height = 680
    Margins.Left = 10
    Margins.Top = 10
    Margins.Right = 10
    Margins.Bottom = 10
    ActivePage = PhaseTab
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnChange = MainPageControlChange
    ExplicitWidth = 825
    ExplicitHeight = 663
    object FixMassTab: TTabSheet
      Caption = 'Fixed mass'
      object FixMassSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 601
        Align = alTop
        ColCount = 2
        FixedColor = clGreen
        RowCount = 3
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goTabs, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 0
        OnMouseUp = CommonSGMouseUp
        ColWidths = (
          118
          108)
      end
    end
    object VarMassTab: TTabSheet
      Caption = 'Variable mass'
      ImageIndex = 1
      object VarMassSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 601
        Hint = 'T : Thrust [ton]'#13#10'M : Mass consumption rate [kg/s]'
        Align = alTop
        ColCount = 2
        FixedColor = clGray
        RowCount = 8
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goTabs, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 0
        OnMouseMove = VarMassSGMouseMove
        OnMouseUp = CommonSGMouseUp
        ColWidths = (
          64
          92)
        RowHeights = (
          24
          24
          24
          24
          24
          24
          24
          24)
      end
      object AddThrustButton: TButton
        Left = 3
        Top = 607
        Width = 100
        Height = 25
        Caption = 'Add Thrust'
        TabOrder = 1
        OnClick = AddThrustButtonClick
      end
      object DelThrustButton: TButton
        Left = 117
        Top = 607
        Width = 100
        Height = 25
        Caption = 'Delete Thrust'
        TabOrder = 2
        OnClick = DelThrustButtonClick
      end
    end
    object AeroDynamicsTab: TTabSheet
      Caption = 'Aerodynamic coefficients'
      ImageIndex = 2
      object AxialForceSG: TStringGrid
        Left = 0
        Top = 80
        Width = 823
        Height = 185
        ColCount = 2
        RowCount = 1
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 0
      end
      object NormalForceSG: TStringGrid
        Left = 0
        Top = 317
        Width = 823
        Height = 122
        ColCount = 2
        RowCount = 1
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 1
      end
      object AerodynamicAddButton: TButton
        Left = 651
        Top = 622
        Width = 75
        Height = 25
        Caption = 'Add'
        TabOrder = 2
        OnClick = AerodynamicAddButtonClick
      end
      object AerodynamicDelButton: TButton
        Left = 745
        Top = 622
        Width = 75
        Height = 25
        Caption = 'Delete'
        TabOrder = 3
        OnClick = AerodynamicDelButtonClick
      end
      object AddSFButton: TButton
        Left = 11
        Top = 607
        Width = 75
        Height = 25
        Caption = 'Add side'
        TabOrder = 4
        OnClick = AddSFButtonClick
      end
      object DelSFButton: TButton
        Left = 100
        Top = 607
        Width = 75
        Height = 25
        Caption = 'Delete side'
        TabOrder = 5
        OnClick = DelSFButtonClick
      end
      object SideForceSG: TStringGrid
        Left = 0
        Top = 487
        Width = 823
        Height = 114
        ColCount = 2
        RowCount = 1
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 6
      end
      object AddNFButton: TButton
        Left = 11
        Top = 445
        Width = 75
        Height = 25
        Caption = 'Add normal'
        TabOrder = 7
        OnClick = AddNFButtonClick
      end
      object DelNFButton: TButton
        Left = 100
        Top = 445
        Width = 75
        Height = 25
        Caption = 'Del normal'
        TabOrder = 8
        OnClick = DelNFButtonClick
      end
      object AddAFButton: TButton
        Left = 11
        Top = 271
        Width = 75
        Height = 25
        Caption = 'Add axial'
        TabOrder = 9
        OnClick = AddAFButtonClick
      end
      object DelAFButton: TButton
        Left = 92
        Top = 271
        Width = 75
        Height = 25
        Caption = 'Delete axial'
        TabOrder = 10
        OnClick = DelAFButtonClick
      end
      object AerodynamicSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 57
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
        TabOrder = 11
      end
    end
    object PhaseTab: TTabSheet
      Caption = 'Phase'
      ImageIndex = 3
      object PhaseSG: TStringGrid
        Left = 0
        Top = 128
        Width = 823
        Height = 481
        Hint = 
          'p : pitch_s, pitch_e, yaw_s, yaw_e'#13#10'q : pitch_s, pitch_e, yaw_s'#13 +
          #10'r : pitch_s, yaw_s'#13#10'i : pitch_e, yaw_e'#13#10's : pitch_s, yaw_s, yaw' +
          '_e'#13#10'g : yaw_s, yaw_e'#13#10#13#10'a : alpha_s, alpha_e, beta_s, beta_e'
        ColCount = 2
        RowCount = 12
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        OnMouseMove = PhaseSGMouseMove
        OnMouseUp = CommonSGMouseUp
        OnSelectCell = PhaseSGSelectCell
      end
      object PhaseInfoSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 106
        Hint = 
          'p : pitch_s, pitch_e, yaw_s, yaw_e'#13#10'q : pitch_s, pitch_e, yaw_s'#13 +
          #10'r : pitch_s, yaw_s'#13#10'i : pitch_e, yaw_e'#13#10's : pitch_s, yaw_s, yaw' +
          '_e'#13#10'g : yaw_s, yaw_e'#13#10#13#10'a : alpha_s, alpha_e, beta_s, beta_e'
        Align = alTop
        ColCount = 2
        RowCount = 4
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goFixedRowDefAlign]
        ParentFont = False
        ParentShowHint = False
        ShowHint = False
        TabOrder = 1
        ExplicitWidth = 817
      end
    end
    object EnvironmentsTab: TTabSheet
      Caption = 'Environments'
      ImageIndex = 4
      object EnvironmentsSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 601
        Hint = 
          'Earth model'#13#10'   0 :'#13#10'   1 :'#13#10#13#10'Air model'#13#10'   0 : air 59'#13#10'   1 : ' +
          'air 62'#13#10'   2 : air 76'
        Align = alTop
        ColCount = 2
        RowCount = 2
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 0
        OnMouseMove = EnvironmentsSGMouseMove
      end
    end
    object InitConditionTab: TTabSheet
      Caption = 'Initial conditions'
      ImageIndex = 5
      object InitialSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 601
        Align = alTop
        ColCount = 2
        RowCount = 6
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 0
      end
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 680
    Width = 831
    Height = 42
    Align = alBottom
    BevelOuter = bvNone
    Color = clGrayText
    ParentBackground = False
    TabOrder = 1
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
  object SaveDialog: TSaveTextFileDialog
    Left = 564
    Top = 682
  end
  object OpenDialog: TOpenDialog
    Left = 520
    Top = 680
  end
  object CommonPopupMenu: TPopupMenu
    Left = 608
    Top = 680
    object AddFixMass: TMenuItem
      Caption = 'Add Column'
      OnClick = CommonAddClick
    end
    object DelFixMass: TMenuItem
      Caption = 'Delete Column'
      OnClick = CommonDelClick
    end
  end
end
