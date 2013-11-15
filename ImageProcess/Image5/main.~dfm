object Form1: TForm1
  Left = 238
  Top = 202
  Width = 652
  Height = 395
  Caption = 'ImageProcess homework 5'
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
  object Button1: TButton
    Left = 312
    Top = 8
    Width = 89
    Height = 25
    Caption = 'Draw Histogram'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 424
    Top = 8
    Width = 105
    Height = 25
    Caption = 'Histogram Equalized'
    TabOrder = 1
    OnClick = Button2Click
  end
  object PageControl2: TPageControl
    Left = 328
    Top = 40
    Width = 300
    Height = 300
    ActivePage = TabSheet3
    TabOrder = 2
    object TabSheet3: TTabSheet
      Caption = '原圖'
      object Image1: TImage
        Left = 21
        Top = 9
        Width = 256
        Height = 256
        AutoSize = True
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Equalization'
      ImageIndex = 1
      object Image4: TImage
        Left = 21
        Top = 8
        Width = 256
        Height = 256
        AutoSize = True
      end
    end
  end
  object Chart1: TChart
    Left = 8
    Top = 40
    Width = 300
    Height = 300
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'Histogram')
    Legend.Visible = False
    View3D = False
    TabOrder = 3
    object Series1: TAreaSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlue
      AreaLinesPen.Color = clBlue
      AreaLinesPen.Visible = False
      DrawArea = True
      LinePen.Visible = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 400
    Top = 80
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 448
    Top = 80
  end
  object MainMenu1: TMainMenu
    Left = 500
    Top = 96
    object N1: TMenuItem
      Caption = '檔案'
      object BMP1: TMenuItem
        Caption = '開啟BMP'
        OnClick = BMP1Click
      end
      object JPEG1: TMenuItem
        Caption = '開啟JPEG'
      end
      object N2: TMenuItem
        Caption = '儲存檔案'
      end
      object N3: TMenuItem
        Caption = '離開'
      end
    end
  end
end
