<%@ Page language="c#" Codebehind="login.aspx.cs" AutoEventWireup="false" Inherits="C09102014.login" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>login</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout" bgColor="#ffffff" background="image/um.jpg">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:Label id="Label1" style="Z-INDEX: 101; LEFT: 280px; POSITION: absolute; TOP: 64px" runat="server"
					Width="120px" Height="24px" Font-Size="Large" ForeColor="#C00000" Font-Names="標楷體">管理者登入</asp:Label>
				<asp:TextBox id="passwd" style="Z-INDEX: 105; LEFT: 272px; POSITION: absolute; TOP: 152px" runat="server"
					Width="200px" TextMode="Password"></asp:TextBox>
				<asp:Label id="Label3" style="Z-INDEX: 103; LEFT: 176px; POSITION: absolute; TOP: 152px" runat="server"
					Width="48px" Height="24px">密碼：</asp:Label>
				<asp:Label id="Label2" style="Z-INDEX: 102; LEFT: 176px; POSITION: absolute; TOP: 120px" runat="server"
					Width="48px" Height="24px"> 帳號：</asp:Label>
				<asp:TextBox id="username" style="Z-INDEX: 104; LEFT: 272px; POSITION: absolute; TOP: 120px"
					runat="server" Width="200px"></asp:TextBox>
				<asp:Button id="Button1" style="Z-INDEX: 106; LEFT: 216px; POSITION: absolute; TOP: 216px" runat="server"
					Width="96px" Text="確定"></asp:Button><INPUT style="Z-INDEX: 107; LEFT: 368px; WIDTH: 104px; POSITION: absolute; TOP: 216px; HEIGHT: 24px"
					type="reset" value="取消">
				<asp:Label id="Label4" style="Z-INDEX: 108; LEFT: 232px; POSITION: absolute; TOP: 280px" runat="server"
					Width="232px" Height="24px"></asp:Label></FONT>
		</form>
	</body>
</HTML>
