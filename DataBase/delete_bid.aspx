<%@ Page language="c#" Codebehind="delete_bid.aspx.cs" AutoEventWireup="false" Inherits="C09102014.delete_bid" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>delete_bid</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:Label id="Label1" style="Z-INDEX: 101; LEFT: 224px; POSITION: absolute; TOP: 32px" runat="server"
					Width="540px" Height="16px"></asp:Label>
				<asp:DataGrid id="DataGrid1" style="Z-INDEX: 102; LEFT: 16px; POSITION: absolute; TOP: 80px" runat="server"
					Width="928px" Height="288px" BorderColor="#3366CC" BorderStyle="None" BorderWidth="1px" BackColor="White"
					CellPadding="4" DataKeyField="拍賣編號">
					<FooterStyle ForeColor="#003399" BackColor="#99CCCC"></FooterStyle>
					<SelectedItemStyle Font-Bold="True" ForeColor="#CCFF99" BackColor="#009999"></SelectedItemStyle>
					<ItemStyle ForeColor="#003399" BackColor="White"></ItemStyle>
					<HeaderStyle Font-Bold="True" ForeColor="#CCCCFF" BackColor="#003399"></HeaderStyle>
					<Columns>
						<asp:ButtonColumn Text="刪除" ButtonType="PushButton" CommandName="Delete"></asp:ButtonColumn>
					</Columns>
					<PagerStyle HorizontalAlign="Left" ForeColor="#003399" BackColor="#99CCCC" Mode="NumericPages"></PagerStyle>
				</asp:DataGrid></FONT>
		</form>
	</body>
</HTML>
