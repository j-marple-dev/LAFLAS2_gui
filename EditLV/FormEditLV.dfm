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
        Top = 81
        Width = 823
        Height = 195
        Align = alClient
        ColCount = 2
        RowCount = 1
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 0
        OnMouseUp = CommonAeroSGMouseUp
        ExplicitLeft = -3
        ExplicitTop = 5
        ExplicitHeight = 191
      end
      object NormalForceSG: TStringGrid
        Left = 0
        Top = 322
        Width = 823
        Height = 122
        Align = alBottom
        ColCount = 2
        RowCount = 1
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 1
        OnMouseUp = CommonAeroSGMouseUp
        ExplicitTop = 84
      end
      object SideForceSG: TStringGrid
        Left = 0
        Top = 490
        Width = 823
        Height = 114
        Align = alBottom
        ColCount = 2
        RowCount = 1
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 2
        OnMouseUp = CommonAeroSGMouseUp
        ExplicitTop = 498
      end
      object AerodynamicSG: TStringGrid
        Left = 0
        Top = 0
        Width = 823
        Height = 58
        Align = alTop
        ColCount = 2
        RowCount = 2
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goEditing, goFixedRowDefAlign]
        ParentFont = False
        TabOrder = 3
        OnMouseUp = CommonAeroSGMouseUp
      end
      object Panel2: TPanel
        Left = 0
        Top = 604
        Width = 823
        Height = 46
        Align = alBottom
        TabOrder = 4
        VerticalAlignment = taAlignTop
        ExplicitTop = 609
        object AddSFButton: TButton
          Left = 0
          Top = 3
          Width = 100
          Height = 25
          Caption = 'Add side'
          TabOrder = 0
          OnClick = AddSFButtonClick
        end
        object DelSFButton: TButton
          Left = 116
          Top = 3
          Width = 100
          Height = 25
          Caption = 'Delete side'
          TabOrder = 1
          OnClick = DelSFButtonClick
        end
      end
      object Panel3: TPanel
        Left = 0
        Top = 444
        Width = 823
        Height = 46
        Align = alBottom
        TabOrder = 5
        ExplicitTop = 445
        object AddNFButton: TButton
          Left = 0
          Top = 3
          Width = 100
          Height = 25
          Caption = 'Add normal'
          TabOrder = 0
          OnClick = AddNFButtonClick
        end
        object DelNFButton: TButton
          Left = 117
          Top = 3
          Width = 100
          Height = 25
          Caption = 'Del normal'
          TabOrder = 1
          OnClick = DelNFButtonClick
        end
      end
      object Panel5: TPanel
        Left = 0
        Top = 276
        Width = 823
        Height = 46
        Align = alBottom
        TabOrder = 6
        ExplicitTop = 270
        object DelAFButton: TButton
          Left = 116
          Top = 3
          Width = 100
          Height = 25
          Caption = 'Delete axial'
          TabOrder = 0
          OnClick = DelAFButtonClick
        end
        object AddAFButton: TButton
          Left = 0
          Top = 3
          Width = 100
          Height = 25
          Caption = 'Add axial'
          TabOrder = 1
          OnClick = AddAFButtonClick
        end
      end
      object Panel6: TPanel
        Left = 0
        Top = 58
        Width = 823
        Height = 23
        Align = alTop
        TabOrder = 7
        ExplicitTop = 59
      end
    end
    object PhaseTab: TTabSheet
      Caption = 'Phase'
      ImageIndex = 3
      object PhaseSG: TStringGrid
        Left = 0
        Top = 121
        Width = 823
        Height = 529
        Hint = 
          'p : pitch_s, pitch_e, yaw_s, yaw_e'#13#10'q : pitch_s, pitch_e, yaw_s'#13 +
          #10'r : pitch_s, yaw_s'#13#10'i : pitch_e, yaw_e'#13#10's : pitch_s, yaw_s, yaw' +
          '_e'#13#10'g : yaw_s, yaw_e'#13#10#13#10'a : alpha_s, alpha_e, beta_s, beta_e'
        Align = alClient
        ColCount = 12
        FixedCols = 0
        RowCount = 3
        FixedRows = 2
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goEditing, goFixedRowDefAlign]
        ParentFont = False
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        OnMouseMove = PhaseSGMouseMove
        OnMouseUp = PhaseSGMouseUp
        OnSelectCell = PhaseSGSelectCell
        ExplicitLeft = 3
        ExplicitTop = 176
        ExplicitHeight = 481
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
      object Panel4: TPanel
        Left = 0
        Top = 106
        Width = 823
        Height = 15
        Align = alTop
        TabOrder = 2
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
      Left = 424
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
  object AerodynamicPopup: TPopupMenu
    Left = 680
    Top = 680
    object AddColumn1: TMenuItem
      Caption = 'Add Column'
      OnClick = AerodynamicAddClick
    end
    object DeleteColumn1: TMenuItem
      Caption = 'Delete Column'
      OnClick = AerodynamicDelClick
    end
  end
  object PhasePopup: TPopupMenu
    Left = 736
    Top = 680
    object AddPhase: TMenuItem
      Caption = 'Add Phase'
      OnClick = AddPhaseClick
    end
    object DelPhase: TMenuItem
      Caption = 'Delete Phase'
      OnClick = DelPhaseClick
    end
  end
end
