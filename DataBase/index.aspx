<%@ Page language="c#" Codebehind="index.aspx.cs" AutoEventWireup="false" Inherits="C09102014.index" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>仿Yahoo拍賣_偽奇摩之首頁</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
	</HEAD>
	<body MS_POSITIONING="GridLayout" bgColor="#f0ffff">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<TABLE id="Table1" style="Z-INDEX: 101; LEFT: 128px; WIDTH: 740px; POSITION: absolute; TOP: 88px; HEIGHT: 32px"
					cellSpacing="1" cellPadding="1" width="740" align="center" bgColor="#ffffcc" border="0"
					runat="server">
					<TR>
						<TD style="WIDTH: 500px; HEIGHT: 20px"><asp:label id="Label1" runat="server" Height="16px" Width="488px">歡迎光臨!</asp:label></TD>
						<TD style="WIDTH: 150px; HEIGHT: 20px"></TD>
						<TD style="WIDTH: 150px; HEIGHT: 20px" align="center"><asp:hyperlink id="HyperLink1" runat="server" Height="16px" Width="80px" NavigateUrl="addbid.aspx">我要賣東西</asp:hyperlink></TD>
					</TR>
				</TABLE>
				<TABLE id="Table3" style="Z-INDEX: 107; LEFT: 128px; WIDTH: 168px; POSITION: absolute; TOP: 312px; HEIGHT: 184px"
					cellSpacing="1" cellPadding="1" width="168" border="0">
					<TR>
						<TD style="HEIGHT: 28px" align="center" bgColor="#ffcc66"><FONT face="新細明體">拍 賣 佈 告 欄</FONT></TD>
					</TR>
					<TR>
						<TD vAlign="middle" align="center" bgColor="linen">
							<TABLE id="Table6" style="WIDTH: 152px; HEIGHT: 133px" cellSpacing="1" cellPadding="1"
								width="152" border="0">
								<TR>
									<TD style="HEIGHT: 35px" bgColor="#ccffff"><asp:hyperlink id="HyperLink3" runat="server" Height="10px" Width="80px" NavigateUrl="teaching.aspx">。拍賣教室</asp:hyperlink></TD>
								</TR>
								<TR>
									<TD style="HEIGHT: 30px" bgColor="#ffccff">
										<P><asp:hyperlink id="HyperLink4" runat="server" Height="8px" Width="83px" NavigateUrl="help.aspx">。求助中心</asp:hyperlink></P>
									</TD>
								</TR>
								<TR>
									<TD style="HEIGHT: 30px" bgColor="#ccffff"><asp:hyperlink id="HyperLink5" runat="server" Height="11px" Width="119px" NavigateUrl="hot.aspx">。熱門商品</asp:hyperlink></TD>
								</TR>
								<TR>
									<TD bgColor="#ffccff">
										<asp:HyperLink id="HyperLink6" runat="server" Height="19px" Width="80px" NavigateUrl="security.aspx">。交易安全</asp:HyperLink></TD>
								</TR>
							</TABLE>
						</TD>
					</TR>
				</TABLE>
				<asp:image id="Image1" style="Z-INDEX: 102; LEFT: 128px; POSITION: absolute; TOP: 16px" runat="server"
					Height="56px" Width="328px" ImageUrl="image\logo.jpg"></asp:image></FONT>
			<hr style="Z-INDEX: 103; LEFT: 120px; WIDTH: 749px; POSITION: absolute; TOP: 768px; HEIGHT: 2px"
				SIZE="2">
			<asp:label id="Label2" style="Z-INDEX: 104; LEFT: 432px; POSITION: absolute; TOP: 784px" runat="server"
				Height="8px" Width="128px" Font-Size="Smaller">製作者: 簡志軒 楊有信</asp:label>
			<HR style="Z-INDEX: 105; LEFT: 368px; WIDTH: 490px; POSITION: absolute; TOP: 40px; HEIGHT: 2px"
				color="#ffff33" SIZE="2">
			<TABLE id="Table2" style="Z-INDEX: 106; LEFT: 128px; WIDTH: 168px; POSITION: absolute; TOP: 128px; HEIGHT: 176px"
				cellSpacing="1" cellPadding="1" width="168" border="0">
				<TR>
					<TD style="HEIGHT: 28px" align="center" bgColor="#ffcc66"><FONT face="新細明體">拍 賣 搜 尋</FONT></TD>
				</TR>
				<TR>
					<TD vAlign="middle" align="center" bgColor="linen"><FONT face="新細明體">
							<P><asp:textbox id="TextBox1" runat="server" Height="24px" Width="136px"></asp:textbox></P>
							<P><asp:dropdownlist id="DropDownList1" runat="server" Height="32px" Width="70px">
									<asp:ListItem Value="關鍵字">關鍵字</asp:ListItem>
									<asp:ListItem Value="賣家編號">賣家編號</asp:ListItem>
									<asp:ListItem Value="拍賣編號">拍賣編號</asp:ListItem>
								</asp:dropdownlist>&nbsp;
								<asp:button id="Button1" runat="server" Height="24px" Width="40px" Font-Size="Smaller" Text="搜尋"></asp:button></P>
							<P><asp:hyperlink id="HyperLink2" runat="server" Height="24px" Width="75px" NavigateUrl="search_bid.aspx">進階搜尋</asp:hyperlink></P>
						</FONT>
					</TD>
				</TR>
			</TABLE>
			<asp:image id="Image2" style="Z-INDEX: 108; LEFT: 304px; POSITION: absolute; TOP: 128px" runat="server"
				Height="216px" Width="392px" ImageUrl="image\ad1.JPG"></asp:image><asp:image id="Image3" style="Z-INDEX: 109; LEFT: 712px; POSITION: absolute; TOP: 136px" runat="server"
				Height="88px" Width="152px" ImageUrl="image\ad2.gif"></asp:image><asp:image id="Image4" style="Z-INDEX: 110; LEFT: 712px; POSITION: absolute; TOP: 240px" runat="server"
				Height="104px" Width="152px" ImageUrl="image\ad3.gif"></asp:image>
			<TABLE id="Table4" style="Z-INDEX: 111; LEFT: 304px; WIDTH: 560px; POSITION: absolute; TOP: 352px; HEIGHT: 144px"
				cellSpacing="1" cellPadding="1" width="560" border="0">
				<TR>
					<TD style="WIDTH: 27px" vAlign="middle" align="center" bgColor="#ff3366">
						<P><FONT face="新細明體" color="#ffff66">新貨上架</FONT></P>
					</TD>
					<TD><FONT face="新細明體">
							<asp:Image id="Image5" runat="server" Width="112px" Height="78px" ImageUrl="image/prora81-thumb-1112704133845943-5.jpg"></asp:Image>&nbsp;
							<asp:Image id="Image6" runat="server" Width="128px" Height="78px" ImageUrl="image/cdz468-thumb-1116959010537668-2.jpg"></asp:Image>&nbsp;
							<asp:Image id="Image7" runat="server" Width="128px" Height="78px" ImageUrl="image/michaeltsai0502-thumb-1115324479509416-3.jpg"></asp:Image>&nbsp;
							<asp:Image id="Image8" runat="server" Width="128px" Height="78px" ImageUrl="image/spenser_y-thumb-1104077829-8.jpg"></asp:Image></FONT></TD>
				</TR>
			</TABLE>
			<TABLE id="Table5" style="Z-INDEX: 112; LEFT: 128px; WIDTH: 736px; POSITION: absolute; TOP: 500px; HEIGHT: 234px"
				cellSpacing="1" cellPadding="1" width="736" border="0">
				<TR>
					<TD style="HEIGHT: 26px" align="center" bgColor="#ffcc00" colspan="2"><FONT face="新細明體">拍 
							賣 分 類</FONT></TD>
				</TR>
				<TR>
					<TD bgColor="lightgoldenrodyellow" style="WIDTH: 360px" align="center"><FONT face="新細明體">
							<asp:HyperLink id="HyperLink7" runat="server" Width="128px" Height="22px" NavigateUrl="see_bid.aspx?classnum=1">電腦軟硬體與PDA</asp:HyperLink>
						</FONT>
					</TD>
					<TD bgColor="#fafad2" align="center"><FONT face="新細明體">
							<asp:HyperLink id="HyperLink8" runat="server" Width="128px" Height="22px" NavigateUrl="see_bid.aspx?classnum=4">運動、戶外與休閒 </asp:HyperLink></FONT></TD>
				</TR>
				<TR>
					<TD style="WIDTH: 360px" bgColor="#fafad2" align="center"><FONT face="新細明體">
							<asp:HyperLink id="HyperLink9" runat="server" Width="120px" Height="22px" NavigateUrl="see_bid.aspx?classnum=7">手錶與流行飾品 </asp:HyperLink></FONT></TD>
					<TD bgColor="#fafad2" align="center">
						<asp:HyperLink id="HyperLink10" runat="server" Width="128px" Height="22px" NavigateUrl="see_bid.aspx?classnum=11">圖書、雜誌與文具</asp:HyperLink></TD>
				</TR>
				<TR>
					<TD style="WIDTH: 360px" bgColor="#fafad2" align="center">
						<asp:HyperLink id="HyperLink11" runat="server" Width="88px" Height="22px" NavigateUrl="see_bid.aspx?classnum=14">手機與通訊</asp:HyperLink></TD>
					<TD bgColor="#fafad2" align="center"><FONT face="新細明體"></FONT></TD>
				</TR>
			</TABLE>
		</form>
	</body>
</HTML>
