<%@ Page language="c#" Codebehind="select_class.aspx.cs" AutoEventWireup="false" Inherits="C09102014.select_class" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>select_product</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout" bgColor="#33ccff">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:Button id="Button2" style="Z-INDEX: 111; LEFT: 440px; POSITION: absolute; TOP: 96px" runat="server"
					Width="80px" Text="取消"></asp:Button>
				<asp:datagrid id="MyDataGrid" style="Z-INDEX: 110; LEFT: 16px; POSITION: absolute; TOP: 152px"
					runat="server" Width="100%" Height="20px" BackColor="#CCCCFF" BorderColor="Black" CellPadding="2"
					CellSpacing="1" Font-Name="Verdana, 新細明體" HeaderStyle-BackColor="#aaaadd" Font-Size="8pt"
					Font-Names="Verdana,新細明體" HorizontalAlign="Center" CaptionAlign="Right" UseAccessibleHeader="True"
					DataKeyField="類別編號">
					<FooterStyle Wrap="False"></FooterStyle>
					<SelectedItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></SelectedItemStyle>
					<EditItemStyle Wrap="False" HorizontalAlign="Center" ForeColor="Black" VerticalAlign="Middle" BackColor="White"></EditItemStyle>
					<AlternatingItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></AlternatingItemStyle>
					<ItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
					<HeaderStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#AAAADD"></HeaderStyle>
					<PagerStyle VerticalAlign="Middle" Visible="False" HorizontalAlign="Center" ForeColor="Black"
						BackColor="Yellow" Wrap="False"></PagerStyle>
				</asp:datagrid>
				<asp:TextBox id="TextBox3" style="Z-INDEX: 106; LEFT: 160px; POSITION: absolute; TOP: 96px" runat="server"
					Width="240px"></asp:TextBox>
				<asp:TextBox id="TextBox2" style="Z-INDEX: 105; LEFT: 160px; POSITION: absolute; TOP: 72px" runat="server"
					Width="240px"></asp:TextBox>
				<asp:Label id="Label4" style="Z-INDEX: 102; LEFT: 48px; POSITION: absolute; TOP: 96px" runat="server"
					Width="80px" Height="16px">父類別編號</asp:Label>
				<asp:Label id="Label3" style="Z-INDEX: 101; LEFT: 64px; POSITION: absolute; TOP: 72px" runat="server"
					Width="64px" Height="24px">類別名稱</asp:Label>
				<asp:Label id="Label2" style="Z-INDEX: 100; LEFT: 64px; POSITION: absolute; TOP: 48px" runat="server"
					Width="64px" Height="16px">類別編號</asp:Label>
				<asp:TextBox id="TextBox1" style="Z-INDEX: 104; LEFT: 160px; POSITION: absolute; TOP: 48px" runat="server"
					Width="240px"></asp:TextBox>
				<asp:Button id="Button1" style="Z-INDEX: 108; LEFT: 440px; POSITION: absolute; TOP: 56px" runat="server"
					Width="80px" Text="搜尋"></asp:Button></FONT>
		</form>
	</body>
</HTML>
