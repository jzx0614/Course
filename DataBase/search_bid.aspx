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
			<FONT face="�s�ө���">
				<asp:image id="Image1" runat="server" Width="328px" Height="56px" ImageUrl="image\logo.jpg"></asp:image>
				<HR style="Z-INDEX: 101; LEFT: 360px; POSITION: absolute; TOP: 40px; HEIGHT: 2px" align="right"
					width="70%" color="#ffff33" SIZE="2">
				<P>
					<TABLE id="Table1" style="HEIGHT: 24px" cellSpacing="0" cellPadding="0" width="100%" align="center"
						border="0">
						<TR>
							<TD width="90%">
								<asp:label id="Label1" runat="server" Width="608px" Height="16px" Font-Size="X-Small">�w����{!</asp:label>
							</TD>
							<TD width="10%">
								<asp:HyperLink id="HyperLink1" runat="server" Width="80px" Height="24px" Font-Size="X-Small"></asp:HyperLink>
							</TD>
						</TR>
						<TR>
							<TD width="90%">
								<asp:label id="Label2" runat="server" Width="100%" Height="16px" BackColor="Yellow" Font-Bold="True">�i���j�M</asp:label></TD>
							<TD width="10%">
								<asp:HyperLink id="HyperLink2" runat="server" Width="100%" Height="16px" Font-Size="X-Small" BackColor="Yellow"
									NavigateUrl="index.aspx">��歺��</asp:HyperLink></TD>
						</TR>
					</TABLE>
			</FONT></P>
			<P>
				<HR style="Z-INDEX: 102; LEFT: 8px; WIDTH: 100.07%; POSITION: absolute; TOP: 144px; HEIGHT: 4px"
					align="center" width="100.07%" color="#ffff99" SIZE="4">
			<P></P>
			<FONT face="�s�ө���">
				<DIV><FONT face="�s�ө���">&nbsp;
				</DIV>
				<DIV align="center">
					<TABLE id="Table2" style="HEIGHT: 272px" cellSpacing="0" cellPadding="0" width="80%" bgColor="white"
						border="0" runat="server" align="center">
						<TR>
							<TD style="HEIGHT: 27px" align="left"><FONT size="4"><STRONG>&nbsp; �i���j�M</STRONG> <STRONG>�G</STRONG></FONT></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">
								<P>&nbsp;&nbsp;&nbsp;<!--StartFragment --> &nbsp;�п�J����r�G&nbsp;
									<asp:TextBox id="TextBox1" runat="server" Height="26px" Width="175px"></asp:TextBox>&nbsp;&nbsp;</P>
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">&nbsp;&nbsp;&nbsp;<!--StartFragment --> 
								�ثe�X���G�b <INPUT id="low_m" type="text" size="7" name="mincurprice" runat="server">
								��(�̧C) �M <INPUT id="high_m" type="text" size="7" name="maxcurprice" runat="server">
								��(�̰�) ����
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 54px" align="left">&nbsp;<!--StartFragment --> &nbsp; �����ʶR���G�b <INPUT id="l_n_m" type="text" size="7" name="minbuyPrice" runat="server">
								��(�̧C) �M <INPUT id="h_n_m" type="text" size="7" name="maxbuyPrice" runat="server">
								��(�̰�) ����
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 60px" align="left">&nbsp;<!--StartFragment -->
								�ӫ~�Ҧb�a�ϡG<FONT size="-1">
									<asp:DropDownList id="DropDownList1" runat="server" Height="24px" Width="222px">
										<asp:ListItem Value="�Ҧ��a��">�Ҧ��a��</asp:ListItem>
									</asp:DropDownList></FONT></TD>
						</TR>
						<TR>
							<TD align="left">
								<P><FONT face="�s�ө���">&nbsp;&nbsp;
										<asp:Button id="Button1" runat="server" Height="22px" Width="75px" Text="�j�M"></asp:Button></FONT></P>
							</TD>
						</TR>
					</TABLE>
				</DIV>
			</FONT></FONT><FONT face="�s�ө���">
				<P align="center">
					<TABLE id="Table3" style="HEIGHT: 272px" cellSpacing="0" cellPadding="0" width="80%" bgColor="white"
						border="0" runat="server">
						<TR>
							<TD style="HEIGHT: 27px" align="left"><FONT size="4"><STRONG>&nbsp;&nbsp;�H�|���b���j�M</STRONG>
									<STRONG>�G</STRONG></FONT></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">
								<P>&nbsp;&nbsp;&nbsp;<!--StartFragment --> &nbsp;�п�J�|���b���G&nbsp;
									<asp:TextBox id="TextBox2" runat="server" Height="26px" Width="175px"></asp:TextBox>&nbsp;&nbsp;
									<asp:Button id="Button3" runat="server" Height="22px" Width="75px" Text="�j�M"></asp:Button></P>
							</TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 45px" align="left">&nbsp;&nbsp;&nbsp;<!--StartFragment --><STRONG>�H����r�j�M���ӫ~ 
									�G</STRONG></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 54px" align="left">&nbsp;<!--StartFragment --> 
								&nbsp;&nbsp;&nbsp;�п�J����r�G&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<INPUT id="likeword" style="WIDTH: 192px; HEIGHT: 22px" type="text" size="26" name="minbuyPrice"
									runat="server"></TD>
						</TR>
						<TR>
							<TD style="HEIGHT: 60px" align="left">&nbsp;<!--StartFragment --> &nbsp;&nbsp; 
								�п�J�|���b�� (<FONT color="#ff3300">�̦h�i��J���ӱb��</FONT>)</TD>
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
								<P><FONT face="�s�ө���">&nbsp;&nbsp;&nbsp;&nbsp;
										<asp:Button id="Button2" runat="server" Height="22px" Width="75px" Text="�j�M"></asp:Button></FONT></P>
							</TD>
						</TR>
					</TABLE>
				</P>
				<P>
					<HR style="WIDTH: 749px; HEIGHT: 2px" SIZE="2">
				</P>
				<P align="center">&nbsp;<FONT face="�s�ө���">
						<asp:label id="Label3" runat="server" Height="8px" Width="128px" Font-Size="Smaller">�s�@��: ²�Ӱa �����H</asp:label></P>
			</FONT>
			<P><FONT face="�s�ө���">&nbsp;</P>
			</FONT>
			<P><FONT face="�s�ө���">&nbsp;</P>
			</FONT></FONT></form>
	</body>
</HTML>
