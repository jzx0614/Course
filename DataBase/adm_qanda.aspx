<%@ Page language="c#" Codebehind="adm_qanda.aspx.cs" AutoEventWireup="false" Inherits="C09102014.adm_qanda" %>
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
				<P align="center">&nbsp;</P>
				<P align="center">
					<asp:HyperLink id="select" runat="server" Width="112px" Height="24px" NavigateUrl="select_qanda.aspx">查詢問與答資料</asp:HyperLink></P>
				<P align="center">
					<asp:HyperLink id="update" runat="server" Width="113px" Height="24px" NavigateUrl="update_qanda.aspx">修改問與答資料</asp:HyperLink></P>
				<P align="center">
					<asp:HyperLink id="delete" runat="server" Width="119px" Height="24px" NavigateUrl="delete_qanda.aspx">刪除問與答資料</asp:HyperLink></P>
			</FONT>
		</form>
	</BODY>
</HTML>
