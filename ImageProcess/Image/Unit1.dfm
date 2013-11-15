object Form1: TForm1
  Left = 221
  Top = 126
  Width = 800
  Height = 600
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 184
    Width = 200
    Height = 200
    Stretch = True
    OnMouseMove = Image1MouseMove
  end
  object Label1: TLabel
    Left = 88
    Top = 168
    Width = 27
    Height = 13
    Alignment = taCenter
    Caption = ' 縮圖'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 120
    Top = 32
    Width = 75
    Height = 25
    Caption = '開啟'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 120
    Top = 72
    Width = 75
    Height = 25
    Caption = '存檔'
    TabOrder = 1
    OnClick = Button2Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 547
    Width = 792
    Height = 19
    Panels = <
      item
        Width = 173
      end
      item
        Width = 173
      end
      item
        Width = 173
      end
      item
        Width = 173
      end>
    SimplePanel = False
  end
  object Button3: TButton
    Left = 320
    Top = 72
    Width = 75
    Height = 25
    Caption = '灰階'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 320
    Top = 32
    Width = 75
    Height = 25
    Caption = '縮小'
    TabOrder = 4
    OnClick = Button4Click
  end
  object RadioGroup1: TRadioGroup
    Left = 16
    Top = 24
    Width = 81
    Height = 81
    Caption = '檔案類型'
    ItemIndex = 0
    Items.Strings = (
      'BMP'
      'JPEG')
    TabOrder = 5
  end
  object RadioGroup2: TRadioGroup
    Left = 208
    Top = 8
    Width = 97
    Height = 113
    Caption = '縮小方法'
    ItemIndex = 4
    Items.Strings = (
      '左上'
      '右上'
      '左下'
      '右下'
      '平均值'
      '中間數')
    TabOrder = 6
  end
  object RadioGroup3: TRadioGroup
    Left = 416
    Top = 16
    Width = 97
    Height = 105
    Caption = '縮小倍率'
    ItemIndex = 0
    Items.Strings = (
      '1  / 4'
      '1  / 16'
      '1  / 64'
      '1  / 256')
    TabOrder = 7
  end
  object Button5: TButton
    Left = 536
    Top = 32
    Width = 75
    Height = 25
    Caption = '預設圖'
    Enabled = False
    TabOrder = 8
    OnClick = Button5Click
  end
  inline Frame21: TFrame2
    Left = 227
    Top = 128
    Width = 558
    Height = 377
    TabOrder = 9
    inherited Image2: TImage
      Left = 0
      Top = 0
      Width = 400
      Height = 345
      OnMouseMove = Frame21Image2MouseMove
    end
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 128
    Top = 416
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 24
    Top = 416
  end
end
