<%@ Page language="c#" Codebehind="add_class.aspx.cs" AutoEventWireup="false" Inherits="C09102014.add_class" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>add_product</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body bgColor="#33ccff" ms_positioning="GridLayout">
		<form id="Form1" method="post" runat="server">
			<P>
				<asp:Label id="Label3" style="Z-INDEX: 101; LEFT: 64px; POSITION: absolute; TOP: 48px" runat="server"
					Width="64px" Height="24px">類別名稱</asp:Label>
				<asp:Button id="Button1" style="Z-INDEX: 102; LEFT: 128px; POSITION: absolute; TOP: 144px" runat="server"
					Width="80px" Text="新增"></asp:Button></P>
			<P><FONT face="新細明體"><INPUT id="pclass" style="Z-INDEX: 104; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 80px; HEIGHT: 24px"
						type="text" size="37" runat="server" NAME="ptitle"></FONT></P>
			<P><FONT face="新細明體"></FONT></P>
			<P><FONT face="新細明體">
					<asp:Label id="Label7" style="Z-INDEX: 109; LEFT: 64px; POSITION: absolute; TOP: 16px" runat="server"
						Width="64px" Height="24px">類別編號</asp:Label></FONT></P>
			<P><FONT face="新細明體"></FONT></P>
			<FONT face="新細明體"></FONT>
			<P><FONT face="新細明體">
					<asp:Label id="Label6" style="Z-INDEX: 118; LEFT: 472px; POSITION: absolute; TOP: 96px" runat="server"
						Height="24px" Width="200px"></asp:Label>&nbsp;<INPUT id="id" style="Z-INDEX: 110; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 16px; HEIGHT: 24px"
						type="text" size="37" name="Text1" runat="server">
					<asp:RequiredFieldValidator id="RequiredFieldValidator1" style="Z-INDEX: 108; LEFT: 24px; POSITION: absolute; TOP: 272px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="id"></asp:RequiredFieldValidator>
					<asp:RequiredFieldValidator id="RequiredFieldValidator3" style="Z-INDEX: 107; LEFT: 24px; POSITION: absolute; TOP: 328px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="pclass"></asp:RequiredFieldValidator>
					<asp:RequiredFieldValidator id="RequiredFieldValidator2" style="Z-INDEX: 106; LEFT: 24px; POSITION: absolute; TOP: 304px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="cname"></asp:RequiredFieldValidator>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					<asp:Label id="Label4" style="Z-INDEX: 111; LEFT: 48px; POSITION: absolute; TOP: 80px" runat="server"
						Width="80px" Height="16px">父類別編號</asp:Label>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT id="cname" style="Z-INDEX: 103; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 48px; HEIGHT: 24px"
						type="text" size="37" runat="server" NAME="pname">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT style="Z-INDEX: 105; LEFT: 256px; WIDTH: 72px; POSITION: absolute; TOP: 144px; HEIGHT: 24px"
						type="reset" value="取消">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				</FONT>
			</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"><FONT color="#ff0000" size="2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</FONT></FONT></P>
		</form>
	</body>
</HTML>
