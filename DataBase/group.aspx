<%@ Page language="c#" Codebehind="group.aspx.cs" AutoEventWireup="false" Inherits="C09102014.group" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>group</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
		<base target="contents">
	</HEAD>
	<body bgColor="#00ccff">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<P align="right">
					<asp:HyperLink id="member" style="Z-INDEX: 101; LEFT: 32px; POSITION: absolute; TOP: 32px" runat="server"
						Width="96px" Height="24px" NavigateUrl="adm_member.aspx">會員系統管理</asp:HyperLink></P>
				<P align="right">
					<asp:HyperLink id="HyperLink5" style="Z-INDEX: 106; LEFT: 576px; POSITION: absolute; TOP: 32px"
						runat="server" NavigateUrl="adm_buy.aspx" Height="24px" Width="96px">出價系統管理</asp:HyperLink></P>
				<P align="right">
					<asp:HyperLink id="HyperLink3" style="Z-INDEX: 105; LEFT: 480px; POSITION: absolute; TOP: 32px"
						runat="server" Width="81px" Height="24px" NavigateUrl="adm_qanda.aspx">問與答管理</asp:HyperLink>
					<asp:HyperLink id="HyperLink1" style="Z-INDEX: 104; LEFT: 368px; POSITION: absolute; TOP: 32px"
						runat="server" Width="96px" Height="24px" NavigateUrl="adm_bid.aspx">拍賣系統管理</asp:HyperLink>
					<asp:HyperLink id="HyperLink2" style="Z-INDEX: 103; LEFT: 256px; POSITION: absolute; TOP: 32px"
						runat="server" Width="96px" Height="24px" NavigateUrl="adm_class.aspx">商品分類管理</asp:HyperLink>
					<asp:HyperLink id="product" style="Z-INDEX: 102; LEFT: 144px; POSITION: absolute; TOP: 32px" runat="server"
						Width="96px" Height="24px" NavigateUrl="adm_product.aspx">商品系統管理</asp:HyperLink>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</P>
				<P align="right">
					<asp:HyperLink id="HyperLink4" runat="server" NavigateUrl="login.aspx" Height="11px" Width="26px"
						Target="main" Font-Size="Smaller">登入</asp:HyperLink>&nbsp;&nbsp;&nbsp;&nbsp;
					<asp:HyperLink id="HyperLink6" runat="server" NavigateUrl="login.aspx" Height="11px" Width="26px"
						Font-Size="Smaller" Target="main">登出</asp:HyperLink></P>
			</FONT>
		</form>
	</body>
</HTML>
