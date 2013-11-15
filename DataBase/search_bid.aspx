<%@ Page language="c#" Codebehind="search_bid.aspx.cs" AutoEventWireup="false" Inherits="C09102014.search_bid" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>search_bid</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body bgColor="#f0ffff" ms_positioning="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:image id="Image1" runat="server" Width="328px" Height="56px" ImageUrl="image\logo.jpg"></asp:image>
				<HR style="Z-INDEX: 101; LEFT: 360px; POSITION: absolute; TOP: 40px; HEIGHT: 2px" align="right"
					width="70%" color="#ffff33" SIZE="2">
				<P>
					<TABLE id="Table1" style="HEIGHT: 24px" cellSpacing="0" cellPadding="0" width="100%" align="center"
						border="0">
						<TR>
							<TD width="90%">
								<asp:label id="Label1" runat="server" Width="608px" Height="16px" Font-Size="X-Small">歡迎光臨!</asp:label>
							</TD>
							<TD width="10%">
								<asp:HyperLink id="HyperLink1" runat="server" Width="80px" Height="24px" Font-Size="X-Small"></asp:HyperLink>
							</TD>
						</TR>
						<TR>
							<TD width="90%">
								<asp:label id="Label2" runat="server" Width="100%" Height="16px" BackColor="Yellow" Font-Bold="True">進階搜尋</asp:label></TD>
							<TD width="10%">
								<asp:HyperLink id="HyperLink2" runat="server" Width="100%" Height="16px" Font-Size="X-Small" BackColor="Yellow"
									NavigateUrl="index.aspx">拍賣首頁</asp:HyperLink></TD>
						</TR>
					</TABLE>
			</FONT></P>
			<P>
				<HR style="Z-INDEX: 102; LEFT: 8px; WIDTH: 100.07%; POSITION: absolute; TOP: 144px; HEIGHT: 4px"
					align="center" width="100.07%" color="#ffff99" SIZE="4">
			<P></P>
			<FONT face="新細明體">
				<DIV><FONT face="新細明體">&nbsp;
				</DIV>
				<DIV align="center">
					<TABLE id="Table2" style="HEIGHT: 272px" cellSpacing="0" cellPadding="0" width="80%" bgColor="white"
						border="0" runat="server" align="center">
						<TR>
							<TD style="HEIGHT: 27px" align="left"><FONT size="4"><STRONG>&nbsp; 進階搜尋</STRONG> <STRONG>：</STRONG></FONT></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">
								<P>&nbsp;&nbsp;&nbsp;<!--StartFragment --> &nbsp;請輸入關鍵字：&nbsp;
									<asp:TextBox id="TextBox1" runat="server" Height="26px" Width="175px"></asp:TextBox>&nbsp;&nbsp;</P>
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">&nbsp;&nbsp;&nbsp;<!--StartFragment --> 
								目前出價：在 <INPUT id="low_m" type="text" size="7" name="mincurprice" runat="server">
								元(最低) 和 <INPUT id="high_m" type="text" size="7" name="maxcurprice" runat="server">
								元(最高) 之間
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 54px" align="left">&nbsp;<!--StartFragment --> &nbsp; 直接購買價：在 <INPUT id="l_n_m" type="text" size="7" name="minbuyPrice" runat="server">
								元(最低) 和 <INPUT id="h_n_m" type="text" size="7" name="maxbuyPrice" runat="server">
								元(最高) 之間
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 60px" align="left">&nbsp;<!--StartFragment -->
								商品所在地區：<FONT size="-1">
									<asp:DropDownList id="DropDownList1" runat="server" Height="24px" Width="222px">
										<asp:ListItem Value="所有地區">所有地區</asp:ListItem>
									</asp:DropDownList></FONT></TD>
						</TR>
						<TR>
							<TD align="left">
								<P><FONT face="新細明體">&nbsp;&nbsp;
										<asp:Button id="Button1" runat="server" Height="22px" Width="75px" Text="搜尋"></asp:Button></FONT></P>
							</TD>
						</TR>
					</TABLE>
				</DIV>
			</FONT></FONT><FONT face="新細明體">
				<P align="center">
					<TABLE id="Table3" style="HEIGHT: 272px" cellSpacing="0" cellPadding="0" width="80%" bgColor="white"
						border="0" runat="server">
						<TR>
							<TD style="HEIGHT: 27px" align="left"><FONT size="4"><STRONG>&nbsp;&nbsp;以會員帳號搜尋</STRONG>
									<STRONG>：</STRONG></FONT></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">
								<P>&nbsp;&nbsp;&nbsp;<!--StartFragment --> &nbsp;請輸入會員帳號：&nbsp;
									<asp:TextBox id="TextBox2" runat="server" Height="26px" Width="175px"></asp:TextBox>&nbsp;&nbsp;
									<asp:Button id="Button3" runat="server" Height="22px" Width="75px" Text="搜尋"></asp:Button></P>
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">&nbsp;&nbsp;&nbsp;<!--StartFragment --><STRONG>以關鍵字搜尋賣方商品 
									：</STRONG></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 54px" align="left">&nbsp;<!--StartFragment --> 
								&nbsp;&nbsp;&nbsp;請輸入關鍵字：&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT id="likeword" style="WIDTH: 192px; HEIGHT: 22px" type="text" size="26" name="minbuyPrice"
									runat="server"></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 60px" align="left">&nbsp;<!--StartFragment --> &nbsp;&nbsp; 
								請輸入會員帳號 (<FONT color="#ff3300">最多可輸入５個帳號</FONT>)</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 60px" align="left">&nbsp;&nbsp; 1. <INPUT id="Text1" style="WIDTH: 104px; HEIGHT: 22px" type="text" size="12" name="minbuyPrice"
									runat="server">&nbsp;2. <INPUT id="Text2" style="WIDTH: 104px; HEIGHT: 22px" type="text" size="12" name="minbuyPrice"
									runat="server">&nbsp;3.<INPUT id="Text3" style="WIDTH: 104px; HEIGHT: 22px" type="text" size="12" name="minbuyPrice"
									runat="server">&nbsp;4. <INPUT id="Text4" style="WIDTH: 104px; HEIGHT: 22px" type="text" size="12" name="minbuyPrice"
									runat="server">5.&nbsp;&nbsp;<INPUT id="Text5" style="WIDTH: 104px; HEIGHT: 22px" type="text" size="12" name="minbuyPrice"
									runat="server">&nbsp;&nbsp;</TD>
						</TR>
						<TR>
							<TD align="left">
								<P><FONT face="新細明體">&nbsp;&nbsp;&nbsp;&nbsp;
										<asp:Button id="Button2" runat="server" Height="22px" Width="75px" Text="搜尋"></asp:Button></FONT></P>
							</TD>
						</TR>
					</TABLE>
				</P>
				<P>
					<HR style="WIDTH: 749px; HEIGHT: 2px" SIZE="2">
				</P>
				<P align="center">&nbsp;<FONT face="新細明體">
						<asp:label id="Label3" runat="server" Height="8px" Width="128px" Font-Size="Smaller">製作者: 簡志軒 楊有信</asp:label></P>
			</FONT>
			<P><FONT face="新細明體">&nbsp;</P>
			</FONT>
			<P><FONT face="新細明體">&nbsp;</P>
			</FONT></FONT></form>
	</body>
</HTML>
