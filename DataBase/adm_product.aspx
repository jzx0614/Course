<%@ Page language="c#" Codebehind="adm_product.aspx.cs" AutoEventWireup="false" Inherits="C09102014.query" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>query</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<base target="main">
	</HEAD>
	<BODY bgColor="#00ccff">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<P align="center">&nbsp;</P>
				<P align="center">
					<asp:HyperLink id="insert" runat="server" Width="97px" Height="24px" NavigateUrl="add_product.aspx">新增商品資料</asp:HyperLink></P>
				<P align="center">
					<asp:HyperLink id="select" runat="server" Width="97px" Height="24px" NavigateUrl="select_product.aspx">查詢商品資料</asp:HyperLink></P>
				<P align="center">
					<asp:HyperLink id="update" runat="server" Width="97px" Height="24px" NavigateUrl="update_product.aspx">修改商品資料</asp:HyperLink></P>
				<P align="center">
					<asp:HyperLink id="delete" runat="server" Width="97px" Height="24px" NavigateUrl="delete_product.aspx">刪除商品資料</asp:HyperLink></P>
			</FONT>
		</form>
	</BODY>
</HTML>
