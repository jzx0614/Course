object Form1: TForm1
  Left = 192
  Top = 112
  Width = 639
  Height = 422
  Caption = '影像處理 第五次程式'
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
  object PageControl1: TPageControl
    Left = 312
    Top = 8
    Width = 313
    Height = 353
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Default'
      object Image1: TImage
        Left = 2
        Top = 10
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Histogram Equalization'
      ImageIndex = 1
      object Image2: TImage
        Left = 2
        Top = 10
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Histogram Specifiction'
      ImageIndex = 2
      object Image3: TImage
        Left = 2
        Top = 10
        Width = 300
        Height = 300
        AutoSize = True
      end
    end
  end
  object Chart1: TChart
    Left = 8
    Top = 40
    Width = 300
    Height = 320
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'Histogram Equalization')
    Legend.Visible = False
    View3D = False
    TabOrder = 1
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
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
    object Series2: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlue
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
    object Series3: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clGreen
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
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 81
    Height = 25
    Caption = 'Equalization'
    Enabled = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 88
    Top = 8
    Width = 81
    Height = 25
    Caption = 'Specifiction'
    Enabled = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 216
    Top = 8
    Width = 33
    Height = 21
    TabOrder = 4
    Text = '0'
  end
  object Edit2: TEdit
    Left = 272
    Top = 8
    Width = 33
    Height = 21
    TabOrder = 5
    Text = '127'
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 280
    Top = 40
  end
  object MainMenu1: TMainMenu
    Left = 248
    Top = 40
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
      object N1: TMenuItem
        Caption = '儲存圖片'
        OnClick = N1Click
      end
      object Exit: TMenuItem
        Caption = '離開'
        OnClick = ExitClick
      end
    end
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 216
    Top = 40
  end
end
