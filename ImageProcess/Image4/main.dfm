object Form1: TForm1
  Left = 310
  Top = 177
  Width = 646
  Height = 454
  Caption = '�v���B�z �ĥ|���{��'
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
    Top = 64
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
  object Button3: TButton
    Left = 88
    Top = 8
    Width = 75
    Height = 25
    Caption = 'BLPF'
    TabOrder = 1
    OnClick = Button3Click
  end
  object PageControl1: TPageControl
    Left = 320
    Top = 16
    Width = 313
    Height = 353
    ActivePage = TabSheet3
    TabOrder = 2
    object TabSheet6: TTabSheet
      Caption = 'FFT'
      ImageIndex = 5
      object Image7: TImage
        Left = 5
        Top = 25
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet7: TTabSheet
      Caption = 'H (u,v)'
      ImageIndex = 6
      object Image8: TImage
        Left = 5
        Top = 25
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'IFFT'
      ImageIndex = 3
      object Image3: TImage
        Left = 5
        Top = 25
        Width = 300
        Height = 300
        AutoSize = True
        OnMouseMove = Image7MouseMove
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Mask'
      ImageIndex = 3
      object Image2: TImage
        Left = 5
        Top = 25
        Width = 300
        Height = 300
        AutoSize = True
        OnMouseMove = Image1MouseMove
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'log(u,v)'
      ImageIndex = 4
      object Image4: TImage
        Left = 5
        Top = 25
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
  end
  object Button4: TButton
    Left = 88
    Top = 32
    Width = 75
    Height = 25
    Caption = 'BHPF'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'FFT'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 32
    Width = 75
    Height = 25
    Caption = 'IFFT'
    TabOrder = 5
    OnClick = Button6Click
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 64
    Top = 88
  end
  object MainMenu1: TMainMenu
    Left = 152
    Top = 88
    object File1: TMenuItem
      Caption = '�ɮ�'
      object BMP: TMenuItem
        Caption = '�}�� BMP'
        OnClick = BMPClick
      end
      object JPEG: TMenuItem
        Caption = '�}�� JPEG'
        OnClick = JPEGClick
      end
      object Exit: TMenuItem
        Caption = '���}'
        OnClick = ExitClick
      end
    end
    object Edit: TMenuItem
      Caption = '�s��'
      object Undo: TMenuItem
        Caption = '�_��'
        OnClick = UndoClick
      end
    end
    object Tools1: TMenuItem
      Caption = '�u��'
      object GrayLevel1: TMenuItem
        Caption = '�Ƕ���'
        OnClick = GrayLevel1Click
      end
    end
    object Mask1: TMenuItem
      Caption = 'Mask'
      object Sobel1: TMenuItem
        Caption = 'Sobel'
        OnClick = Sobel1Click
      end
      object Prewitt1: TMenuItem
        Caption = 'Prewitt'
        OnClick = Prewitt1Click
      end
      object Laplacian1: TMenuItem
        Caption = 'Laplacian1'
        OnClick = Laplacian1Click
      end
      object Laplacian21: TMenuItem
        Caption = 'Laplacian2'
        OnClick = Laplacian21Click
      end
      object Laplacian31: TMenuItem
        Caption = 'Laplacian3'
      end
    end
  end
end