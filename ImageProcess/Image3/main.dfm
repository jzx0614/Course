object Form1: TForm1
  Left = 224
  Top = 189
  Width = 646
  Height = 454
  Caption = '影像處理 第三次程式'
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
  object StatusBar1: TStatusBar
    Left = 0
    Top = 381
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
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Sobel'
    Enabled = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Prewitt'
    Enabled = False
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 168
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Laplacian'
    Enabled = False
    TabOrder = 3
    OnClick = Button3Click
  end
  object PageControl1: TPageControl
    Left = 312
    Top = 8
    Width = 313
    Height = 353
    ActivePage = TabSheet1
    TabOrder = 4
    object TabSheet1: TTabSheet
      Caption = 'Sobel'
      object Image2: TImage
        Left = 0
        Top = 24
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Prewitt'
      ImageIndex = 1
      object Image3: TImage
        Left = 0
        Top = 24
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Laplacian1'
      ImageIndex = 2
      object Image4: TImage
        Left = 0
        Top = 24
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Laplacian2'
      ImageIndex = 3
      object Image5: TImage
        Left = 0
        Top = 24
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'Laplacian3'
      ImageIndex = 4
      object Image6: TImage
        Left = 0
        Top = 24
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 64
    Top = 88
  end
  object MainMenu1: TMainMenu
    Left = 152
    Top = 88
    object File1: TMenuItem
      Caption = '檔案'
      object BMP: TMenuItem
        Caption = '開啟 BMP'
        OnClick = BMPClick
      end
      object JPEG: TMenuItem
        Caption = '開啟 JPEG'
        OnClick = JPEGClick
      end
      object Exit: TMenuItem
        Caption = '離開'
        OnClick = ExitClick
      end
    end
    object Edit: TMenuItem
      Caption = '編輯'
      object Undo: TMenuItem
        Caption = '復原'
        Enabled = False
        OnClick = UndoClick
      end
    end
    object Tools1: TMenuItem
      Caption = '工具'
      object GrayLevel1: TMenuItem
        Caption = '灰階化'
        Enabled = False
        OnClick = GrayLevel1Click
      end
    end
  end
end
