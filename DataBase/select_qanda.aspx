<%@ Page language="c#" Codebehind="select_qanda.aspx.cs" AutoEventWireup="false" Inherits="C09102014.select_qanda" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>select_qanda</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="�s�ө���">
				<asp:TextBox id="TextBox1" style="Z-INDEX: 101; LEFT: 205px; POSITION: absolute; TOP: 34px" runat="server"
					Width="349px" Height="23px"></asp:TextBox>
				<asp:DropDownList id="DropDownList1" style="Z-INDEX: 102; LEFT: 568px; POSITION: absolute; TOP: 32px"
					runat="server" Width="104px" Height="16px">
					<asp:ListItem Value="all" Selected="True">�C�X�Ҧ����</asp:ListItem>
					<asp:ListItem Value="Q#">���D�s��</asp:ListItem>
					<asp:ListItem Value="���s��">���s��</asp:ListItem>
					<asp:ListItem Value="���D">���D</asp:ListItem>
					<asp:ListItem Value="���">���</asp:ListItem>
				</asp:DropDownList>
				<asp:Button id="Button1" style="Z-INDEX: 103; LEFT: 680px; POSITION: absolute; TOP: 32px" runat="server"
					Width="40px" Text="�d��"></asp:Button>
				<asp:DataGrid id="DataGrid1" style="Z-INDEX: 104; LEFT: 48px; POSITION: absolute; TOP: 104px"
					runat="server" Width="880px" Height="200px" BorderColor="#E7E7FF" BorderStyle="None" BorderWidth="1px"
					BackColor="White" CellPadding="3" GridLines="Horizontal">
					<FooterStyle ForeColor="#4A3C8C" BackColor="#B5C7DE"></FooterStyle>
					<SelectedItemStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#738A9C"></SelectedItemStyle>
					<AlternatingItemStyle BackColor="#F7F7F7"></AlternatingItemStyle>
					<ItemStyle ForeColor="#4A3C8C" BackColor="#E7E7FF"></ItemStyle>
					<HeaderStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#4A3C8C"></HeaderStyle>
					<PagerStyle HorizontalAlign="Right" ForeColor="#4A3C8C" BackColor="#E7E7FF" Mode="NumericPages"></PagerStyle>
				</asp:DataGrid>
				<asp:Label id="Label1" style="Z-INDEX: 105; LEFT: 320px; POSITION: absolute; TOP: 72px" runat="server"
					Width="394px">Label</asp:Label>
				<asp:Label id="Label2" style="Z-INDEX: 106; LEFT: 208px; POSITION: absolute; TOP: 72px" runat="server"
					Width="96px" Height="16px">SQL CMD:</asp:Label></FONT>
		</form>
	</body>
</HTML>
