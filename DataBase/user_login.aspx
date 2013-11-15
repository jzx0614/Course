<%@ Page language="c#" Codebehind="user_login.aspx.cs" AutoEventWireup="false" Inherits="C09102014.user_login" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>user_login</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<asp:image id="Image1" style="Z-INDEX: 100; LEFT: 128px; POSITION: absolute; TOP: 40px" runat="server"
				Width="328px" Height="56px" ImageUrl="image\logo.jpg"></asp:image>
			<HR style="Z-INDEX: 101; LEFT: 368px; WIDTH: 490px; POSITION: absolute; TOP: 64px; HEIGHT: 2px"
				color="#ffff33" SIZE="2">
			<asp:Label id="Label2" style="Z-INDEX: 103; LEFT: 128px; POSITION: absolute; TOP: 112px" runat="server"
				Width="728px" Height="16px" BackColor="#FFFF80" ForeColor="Green">歡迎來到Yahoo!奇摩拍賣</asp:Label>
			<TABLE id="Table1" style="Z-INDEX: 105; LEFT: 616px; WIDTH: 240px; POSITION: absolute; TOP: 144px; HEIGHT: 296px"
				cellSpacing="1" cellPadding="1" width="240" border="1" borderColor="#cc6600" bgColor="#cccccc">
				<TR>
					<TD id="TD1" runat="server" align="center" valign="top"><FONT face="新細明體" color="#006600" size="4">
							<P>&nbsp;</P>
							<P>
								<asp:Label id="Label6" runat="server" Width="184px" Height="24px" ForeColor="Green" Font-Size="Medium">《仿Yahoo!奇摩會員》</asp:Label>
								<asp:Label id="Label7" runat="server" Width="136px" Height="8px" ForeColor="Green" Font-Size="Smaller">請輸入帳號和密碼</asp:Label></P>
							<P>
								<asp:Label id="Label5" runat="server" Width="198px" Height="16px" ForeColor="Red" Font-Size="Smaller">重要提醒：Yahoo!奇摩不會<br>主動要求會員提供密碼詳情</asp:Label></P>
							<P>
								<asp:Label id="Label3" runat="server" Width="45px" Height="16px" ForeColor="Black">帳號:</asp:Label>
								<asp:TextBox id="TextBox1" runat="server" Width="165px"></asp:TextBox>
								<asp:Label id="Label4" runat="server" Width="45px" Height="16px" ForeColor="Black">密碼:</asp:Label>
								<asp:TextBox id="TextBox2" runat="server" Width="167px" TextMode="Password"></asp:TextBox>
								<asp:Button id="Button1" runat="server" Width="48px" Text="登入" Height="24px"></asp:Button></P>
							<P>
								<asp:Label id="Label1" runat="server" Width="194px" Height="56px" ForeColor="Red"></asp:Label></P>
						</FONT>
					</TD>
				</TR>
			</TABLE>
			<TABLE id="Table2" style="Z-INDEX: 106; LEFT: 128px; WIDTH: 480px; POSITION: absolute; TOP: 144px; HEIGHT: 296px"
				cellSpacing="1" cellPadding="1" width="480" border="0">
				<TR>
					<TD align="center" valign="top">
						<P><FONT face="新細明體">&nbsp;<!--StartFragment --><FONT color="#717171">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
									<FONT class="maf">Yahoo! 奇摩 會員請輸入</FONT></FONT></FONT></P>
						<P>&nbsp;<!--StartFragment --> 新 使 用 者
						</P>
						<P>&nbsp;<!--StartFragment --> <STRONG>立即註冊<FONT size="+0">享用Yahoo!奇摩的服務</FONT></STRONG>&nbsp;</P>
						<P><FONT face="新細明體" color="#339900">
								<TABLE id="Table3" style="WIDTH: 446px; HEIGHT: 160px" cellSpacing="1" cellPadding="1"
									width="446" border="0" runat="server">
									<TBODY>
										<TR>
											<TD valign="top">
												<P><FONT face="新細明體"><!--StartFragment -->
													</FONT>
												</P>
										<TR>
											<TD width="1" valign="top" align="left"><FONT class="t1">‧</FONT></TD>
											<TD valign="top" align="left"><FONT class="t1" color="#009900">中古、新品、收藏品，超低價格任你標。</FONT></TD>
							</FONT>
						<P></P>
						<P><FONT face="新細明體"></P>
				</TR>
				<TR>
					<TD valign="top" align="left"><FONT class="t1">‧</FONT></TD>
					<TD valign="top" align="left"><FONT class="t1" color="#009900">你也可拿出私家珍藏，拍賣換現金！ </FONT>
					</TD>
				</TR>
				<TR>
					<TD valign="top" align="left"><FONT class="t1">‧</FONT></TD>
					<TD valign="top" align="left"><FONT class="t1" color="#009900">使用我的拍賣，讓你隨時掌握買賣的狀況。 </FONT>
					</TD>
				</TR>
				<TR>
					<TD valign="top" align="left"><FONT class="t1">‧</FONT></TD>
					<TD valign="top" align="left"><FONT class="t1" color="#009900">參與慈善拍賣，發揮愛心，一舉兩得！</FONT></TD>
				</TR>
				</FONT>
				<P></P>
				</TD></TR></TABLE>
			</FONT></P></TD></TR></TBODY></TABLE> &nbsp;
			<P><FONT face="新細明體"></FONT></P>
			</TD></TR></TABLE>
			<HR style="Z-INDEX: 107; LEFT: 120px; WIDTH: 749px; POSITION: absolute; TOP: 480px; HEIGHT: 2px"
				SIZE="2">
			<asp:Label id="Label8" style="Z-INDEX: 108; LEFT: 440px; POSITION: absolute; TOP: 488px" runat="server"
				Width="128px" Height="16px" Font-Size="Smaller">製作者: 簡志軒 楊有信</asp:Label></form>
	</body>
</HTML>
