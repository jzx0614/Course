object Form1: TForm1
  Left = 240
  Top = 163
  Width = 646
  Height = 458
  Caption = '影像處理 第二次程式'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 56
    Width = 300
    Height = 300
    AutoSize = True
    OnMouseMove = Image1MouseMove
  end
  object Image2: TImage
    Left = 328
    Top = 56
    Width = 300
    Height = 300
    AutoSize = True
    OnMouseMove = Image2MouseMove
  end
  object Label: TLabel
    Left = 128
    Top = 24
    Width = 25
    Height = 25
    AutoSize = False
    Caption = '色'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Button2: TButton
    Left = 8
    Top = 24
    Width = 75
    Height = 25
    Caption = 'Graylevel'
    Enabled = False
    TabOrder = 0
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 152
    Top = 24
    Width = 100
    Height = 25
    Caption = 'Gray Quantization'
    Enabled = False
    TabOrder = 1
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 256
    Top = 24
    Width = 100
    Height = 25
    Caption = 'Quantization'
    Enabled = False
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Default'
    Enabled = False
    TabOrder = 3
    OnClick = Button5Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 385
    Width = 638
    Height = 19
    Panels = <
      item
        Alignment = taCenter
        Width = 250
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object ComboBox1: TComboBox
    Left = 288
    Top = 0
    Width = 65
    Height = 21
    BiDiMode = bdLeftToRight
    ItemHeight = 13
    ParentBiDiMode = False
    TabOrder = 5
    Text = 'RGB'
    Items.Strings = (
      'RGB'
      'YUV'
      'YIQ')
  end
  object Edit1: TEdit
    Left = 96
    Top = 24
    Width = 33
    Height = 21
    TabOrder = 6
    Text = '128'
  end
  object TrackBar1: TTrackBar
    Left = 88
    Top = 0
    Width = 200
    Height = 25
    Max = 256
    Orientation = trHorizontal
    Frequency = 0
    Position = 128
    SelEnd = 0
    SelStart = 0
    TabOrder = 7
    ThumbLength = 15
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 64
    Top = 88
  end
  object MainMenu1: TMainMenu
    Left = 152
    Top = 88
    object File1: TMenuItem
      Caption = 'File'
      object BMP: TMenuItem
        Caption = 'Open BMP'
        OnClick = BMPClick
      end
      object JPEG: TMenuItem
        Caption = 'Open JPEG'
        OnClick = JPEGClick
      end
      object Exit: TMenuItem
        Caption = 'Exit'
        OnClick = ExitClick
      end
    end
  end
end
