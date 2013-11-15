<%@ Page language="c#" Codebehind="add_product.aspx.cs" AutoEventWireup="false" Inherits="C09102014.add_product" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>add_product</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body bgColor="#33ccff">
		<form id="Form1" method="post" runat="server">
			<P>
				<asp:Label id="Label2" style="Z-INDEX: 105; LEFT: 64px; POSITION: absolute; TOP: 176px" runat="server"
					Width="64px" Height="16px">類別編號</asp:Label>
				<asp:Label id="Label1" style="Z-INDEX: 104; LEFT: 64px; POSITION: absolute; TOP: 144px" runat="server"
					Width="64px" Height="8px">商品圖片</asp:Label>
				<asp:Label id="Label5" style="Z-INDEX: 102; LEFT: 64px; POSITION: absolute; TOP: 112px" runat="server"
					Width="64px" Height="16px">商品數量</asp:Label>
				<asp:Label id="Label4" style="Z-INDEX: 101; LEFT: 64px; POSITION: absolute; TOP: 80px" runat="server"
					Width="64px" Height="16px">商品標題</asp:Label>
				<asp:Label id="Label3" style="Z-INDEX: 100; LEFT: 64px; POSITION: absolute; TOP: 48px" runat="server"
					Width="64px" Height="24px">商品名稱</asp:Label>
				<asp:Button id="Button1" style="Z-INDEX: 103; LEFT: 160px; POSITION: absolute; TOP: 232px" runat="server"
					Width="80px" Text="新增"></asp:Button></P>
			<P><FONT face="新細明體"><INPUT id="ptitle" style="Z-INDEX: 107; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 80px; HEIGHT: 24px"
						type="text" size="37" runat="server"></FONT></P>
			<P><FONT face="新細明體"><INPUT id="pqty" style="Z-INDEX: 108; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 112px; HEIGHT: 24px"
						type="text" size="37" runat="server"></FONT></P>
			<P><FONT face="新細明體">
					<asp:Label id="Label7" style="Z-INDEX: 119; LEFT: 64px; POSITION: absolute; TOP: 16px" runat="server"
						Width="64px" Height="24px">拍賣編號</asp:Label></FONT></P>
			<P><FONT face="新細明體"><INPUT id="ppic" style="Z-INDEX: 109; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 144px; HEIGHT: 24px"
						type="text" size="37" runat="server"></FONT></P>
			<FONT face="新細明體"></FONT>
			<P><FONT face="新細明體"><INPUT id="pclass" style="Z-INDEX: 110; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 176px; HEIGHT: 24px"
						type="text" size="37" runat="server">
					<asp:RequiredFieldValidator id="RequiredFieldValidator6" style="Z-INDEX: 121; LEFT: 176px; POSITION: absolute; TOP: 328px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="bid"></asp:RequiredFieldValidator><INPUT id="bid" style="Z-INDEX: 120; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 16px; HEIGHT: 24px"
						type="text" size="37" name="Text1" runat="server">
					<asp:RequiredFieldValidator id="RequiredFieldValidator5" style="Z-INDEX: 117; LEFT: 24px; POSITION: absolute; TOP: 280px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="pname"></asp:RequiredFieldValidator>
					<asp:RequiredFieldValidator id="RequiredFieldValidator1" style="Z-INDEX: 116; LEFT: 176px; POSITION: absolute; TOP: 280px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="ptitle"></asp:RequiredFieldValidator>
					<asp:RequiredFieldValidator id="RequiredFieldValidator4" style="Z-INDEX: 114; LEFT: 24px; POSITION: absolute; TOP: 328px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="pclass"></asp:RequiredFieldValidator>
					<asp:RequiredFieldValidator id="RequiredFieldValidator3" style="Z-INDEX: 113; LEFT: 176px; POSITION: absolute; TOP: 304px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="ppic"></asp:RequiredFieldValidator>
					<asp:RequiredFieldValidator id="RequiredFieldValidator2" style="Z-INDEX: 112; LEFT: 24px; POSITION: absolute; TOP: 304px"
						runat="server" Width="72px" Height="24px" ErrorMessage="RequiredFieldValidator" ControlToValidate="pqty"></asp:RequiredFieldValidator>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT id="pname" style="Z-INDEX: 106; LEFT: 152px; WIDTH: 256px; POSITION: absolute; TOP: 48px; HEIGHT: 24px"
						type="text" size="37" runat="server">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT style="Z-INDEX: 111; LEFT: 296px; WIDTH: 72px; POSITION: absolute; TOP: 232px; HEIGHT: 24px"
						type="reset" value="取消">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				</FONT>
			</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"><FONT color="#ff0000" size="2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;請輸入url位
						<asp:Label id="Label6" style="Z-INDEX: 118; LEFT: 480px; POSITION: absolute; TOP: 88px" runat="server"
							Width="200px" Height="24px"></asp:Label>置</FONT></FONT></P>
		</form>
	</body>
</HTML>
