<%@ Page language="c#" Codebehind="select_bid.aspx.cs" AutoEventWireup="false" Inherits="C09102014.select_bid" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>select_bid</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="�s�ө���">
				<asp:TextBox id="Textpnum" style="Z-INDEX: 101; LEFT: 192px; POSITION: absolute; TOP: 48px" runat="server"
					Width="286px"></asp:TextBox>
				<asp:Label id="pnum" style="Z-INDEX: 116; LEFT: 72px; POSITION: absolute; TOP: 48px" runat="server"
					Width="96px" Height="24px">���s��</asp:Label>
				<asp:TextBox id="Textpay" style="Z-INDEX: 115; LEFT: 192px; POSITION: absolute; TOP: 144px" runat="server"
					Width="286px"></asp:TextBox>
				<asp:Label id="pay" style="Z-INDEX: 114; LEFT: 72px; POSITION: absolute; TOP: 144px" runat="server"
					Width="96px" Height="24px">�I�ڤ覡</asp:Label>
				<asp:Label id="zone" style="Z-INDEX: 111; LEFT: 72px; POSITION: absolute; TOP: 112px" runat="server"
					Width="96px" Height="24px">�Ҧb�a��</asp:Label>
				<asp:Label id="snum" style="Z-INDEX: 110; LEFT: 72px; POSITION: absolute; TOP: 80px" runat="server"
					Width="96px" Height="24px">��a�s��</asp:Label>
				<asp:Label id="black" style="Z-INDEX: 109; LEFT: 72px; POSITION: absolute; TOP: 176px" runat="server"
					Width="96px" Height="24px">�ӫ~�¦W��</asp:Label>
				<asp:Label id="newold" style="Z-INDEX: 108; LEFT: 72px; POSITION: absolute; TOP: 208px" runat="server"
					Width="96px" Height="24px">�ӫ~�s��</asp:Label>
				<asp:TextBox id="Textsnum" style="Z-INDEX: 107; LEFT: 192px; POSITION: absolute; TOP: 80px" runat="server"
					Width="286px"></asp:TextBox>
				<asp:TextBox id="Textzone" style="Z-INDEX: 106; LEFT: 192px; POSITION: absolute; TOP: 112px"
					runat="server" Width="286px"></asp:TextBox>
				<asp:Button id="Button1" style="Z-INDEX: 102; LEFT: 496px; POSITION: absolute; TOP: 192px" runat="server"
					Width="80px" Text="�d��"></asp:Button>
				<asp:Button id="Button2" style="Z-INDEX: 103; LEFT: 832px; POSITION: absolute; TOP: 192px" runat="server"
					Width="96px" Text="�C�X�Ҧ����"></asp:Button>
				<asp:DataGrid id="DataGrid1" style="Z-INDEX: 104; LEFT: 8px; POSITION: absolute; TOP: 240px" runat="server"
					Width="100%" Height="151px" BorderColor="#E7E7FF" BorderStyle="None" BorderWidth="1px" BackColor="White"
					CellPadding="3" GridLines="Horizontal">
					<FooterStyle ForeColor="#4A3C8C" BackColor="#B5C7DE"></FooterStyle>
					<SelectedItemStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#738A9C"></SelectedItemStyle>
					<AlternatingItemStyle BackColor="#F7F7F7"></AlternatingItemStyle>
					<ItemStyle ForeColor="#4A3C8C" BackColor="#E7E7FF"></ItemStyle>
					<HeaderStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#4A3C8C"></HeaderStyle>
					<PagerStyle HorizontalAlign="Right" ForeColor="#4A3C8C" BackColor="#E7E7FF" Mode="NumericPages"></PagerStyle>
				</asp:DataGrid>
				<asp:Label id="Label1" style="Z-INDEX: 105; LEFT: 504px; POSITION: absolute; TOP: 48px" runat="server"
					Width="425px" Height="126px"></asp:Label>
				<asp:DropDownList id="Dropnewold" style="Z-INDEX: 112; LEFT: 192px; POSITION: absolute; TOP: 200px"
					runat="server" Width="120px" Height="16px">
					<asp:ListItem Value="-1" Selected="True">Don't Care</asp:ListItem>
					<asp:ListItem Value="1">�s�ӫ~</asp:ListItem>
					<asp:ListItem Value="0">�°ӫ~</asp:ListItem>
				</asp:DropDownList>
				<asp:DropDownList id="Dropblack" style="Z-INDEX: 113; LEFT: 192px; POSITION: absolute; TOP: 168px"
					runat="server" Width="120px" Height="16px">
					<asp:ListItem Value="-1">Don't Care</asp:ListItem>
					<asp:ListItem Value="1">�¦W��</asp:ListItem>
					<asp:ListItem Value="0">���O�¦W��</asp:ListItem>
				</asp:DropDownList></FONT>
		</form>
	</body>
</HTML>
