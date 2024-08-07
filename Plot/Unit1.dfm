object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'LAFLAS Plot'
  ClientHeight = 957
  ClientWidth = 1310
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu
  TextHeight = 15
  object Chart: TChart
    Left = 0
    Top = 0
    Width = 1136
    Height = 957
    Cursor = crCross
    AllowPanning = pmNone
    BackWall.Pen.Visible = False
    MarginBottom = 0
    MarginLeft = 2
    MarginRight = 2
    MarginTop = 0
    ScrollMouseButton = mbLeft
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    ClipPoints = False
    Frame.Visible = False
    Panning.InsideBounds = True
    Panning.MouseWheel = pmwNone
    Shadow.Visible = False
    View3D = False
    Zoom.MouseButton = mbRight
    ZoomWheel = pmwNormal
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitWidth = 873
    ExplicitHeight = 793
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      14
      15
      14)
    ColorPaletteIndex = 13
  end
  object Panel1: TPanel
    Left = 1136
    Top = 0
    Width = 174
    Height = 957
    Align = alRight
    Caption = 'Panel1'
    TabOrder = 1
    object Label1: TLabel
      Left = 1
      Top = 1
      Width = 172
      Height = 15
      Align = alTop
      Caption = 'X:'
      ExplicitLeft = 48
      ExplicitTop = 88
      ExplicitWidth = 10
    end
    object Label2: TLabel
      Left = 1
      Top = 145
      Width = 172
      Height = 30
      Align = alTop
      Caption = #13#10'Y:'
      ExplicitWidth = 10
    end
    object ScrollBoxX: TScrollBox
      Left = 1
      Top = 16
      Width = 172
      Height = 129
      Align = alTop
      TabOrder = 0
    end
    object ScrollBoxY: TScrollBox
      Left = 1
      Top = 175
      Width = 172
      Height = 781
      Align = alClient
      TabOrder = 1
      ExplicitLeft = 25
      ExplicitTop = 632
      ExplicitWidth = 112
      ExplicitHeight = 172
    end
  end
  object OpenDialog: TOpenDialog
    Left = 1232
    Top = 888
  end
  object MainMenu: TMainMenu
    Left = 848
    Top = 896
    object F1: TMenuItem
      Caption = 'File'
      object OpenCSV1: TMenuItem
        Caption = 'Open CSV'
        OnClick = OpenCSV1Click
      end
    end
    object OpenCSV2: TMenuItem
      Caption = 'About'
    end
  end
end
