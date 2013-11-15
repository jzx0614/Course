<%@ Page language="c#" Codebehind="select_member.aspx.cs" AutoEventWireup="false" Inherits="C09102014.select_member" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>WebForm2</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:DataGrid id="DataGrid1" style="Z-INDEX: 101; LEFT: 24px; POSITION: absolute; TOP: 56px" runat="server"
					Width="100%" Height="14px" BackColor="White" BorderColor="#CC9966" Font-Bold="True" CellPadding="2"
					BorderStyle="None" BorderWidth="1px" AllowCustomPaging="True" Font-Size="Smaller" CellSpacing="1"
					HorizontalAlign="Center" DataKeyField="帳號">
					<FooterStyle ForeColor="#330099" BackColor="#FFFFCC"></FooterStyle>
					<SelectedItemStyle Font-Bold="True" ForeColor="#663399" BackColor="#FFCC66"></SelectedItemStyle>
					<ItemStyle ForeColor="#330099" BackColor="White"></ItemStyle>
					<HeaderStyle Font-Bold="True" ForeColor="#FFFFCC" BackColor="#990000"></HeaderStyle>
					<PagerStyle Visible="False" HorizontalAlign="Center" ForeColor="#330099" BackColor="#FFFFCC"
						Mode="NumericPages"></PagerStyle>
				</asp:DataGrid>
				<BLOCKQUOTE dir="ltr" style="MARGIN-RIGHT: 0px">
					<P>
						<asp:TextBox id="TextBox1" style="Z-INDEX: 102; LEFT: 136px; POSITION: absolute; TOP: 16px" runat="server"
							Width="256px" Height="24px"></asp:TextBox>
						<asp:Button id="search" style="Z-INDEX: 103; LEFT: 504px; POSITION: absolute; TOP: 16px" runat="server"
							Width="56px" Text="查詢"></asp:Button>
						<asp:Label id="Label1" style="Z-INDEX: 104; LEFT: 32px; POSITION: absolute; TOP: 16px" runat="server"
							Width="96px" Height="24px">使用者查詢：</asp:Label>
						<asp:Button id="Button1" style="Z-INDEX: 105; LEFT: 608px; POSITION: absolute; TOP: 16px" runat="server"
							Width="128px" Height="24px" Text="列出所有會員"></asp:Button>
						<asp:DropDownList id="DropDownList1" style="Z-INDEX: 106; LEFT: 408px; POSITION: absolute; TOP: 16px"
							runat="server" Height="16px" Width="80px">
							<asp:ListItem Value="帳號" Selected="True">帳號</asp:ListItem>
							<asp:ListItem Value="姓氏">姓氏</asp:ListItem>
							<asp:ListItem Value="名字">名字</asp:ListItem>
							<asp:ListItem Value="性別">性別</asp:ListItem>
						</asp:DropDownList>
						<asp:Label id="Label2" style="Z-INDEX: 107; LEFT: 184px; POSITION: absolute; TOP: 432px" runat="server"
							Height="24px" Width="392px"></asp:Label></P>
				</BLOCKQUOTE></FONT>
		</form>
	</body>
</HTML>
