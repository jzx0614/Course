<%@ Page language="c#" Codebehind="buy.aspx.cs" AutoEventWireup="false" Inherits="C09102014.buy" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>buy</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
	</HEAD>
	<body bgColor="#f0ffff">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<P><asp:image id="Image1" runat="server" Width="328px" Height="56px" ImageUrl="image\logo.jpg"></asp:image></P>
			</FONT>
			<P>
				<HR style="Z-INDEX: 101; LEFT: 360px; POSITION: absolute; TOP: 40px; HEIGHT: 2px" align="right"
					width="70%" color="#ffff33" SIZE="2">
			<P></P>
			<P>
				<TABLE id="Table1" style="HEIGHT: 24px" cellSpacing="0" cellPadding="0" width="100%" align="center"
					border="0">
					<TR>
						<TD width="90%"><asp:label id="Label1" runat="server" Width="608px" Height="16px" Font-Size="X-Small">歡迎光臨!</asp:label></TD>
						<TD width="10%"><asp:hyperlink id="HyperLink1" runat="server" Width="80px" Height="24px" Font-Size="X-Small"></asp:hyperlink></TD>
					</TR>
					<TR>
						<TD width="90%"><asp:label id="Label2" runat="server" Width="100%" Height="16px" BackColor="Yellow" Font-Bold="True">仿Yahoo　奇摩拍賣</asp:label></TD>
						<TD width="10%"><asp:hyperlink id="HyperLink2" runat="server" Width="100%" Height="16px" Font-Size="X-Small" BackColor="Yellow">回上一頁</asp:hyperlink></TD>
					</TR>
				</TABLE>
			</P>
			<HR style="WIDTH: 100.07%; HEIGHT: 4px" align="center" width="100.07%" color="#ffff99"
				SIZE="4">
			<FONT face="新細明體">
				<DIV align="center"><asp:label id="Label5" runat="server" Width="304px" Height="14px"></asp:label></DIV>
				<DIV align="center">&nbsp;</DIV>
			</FONT>
			<TABLE id="Table3" style="WIDTH: 553px; HEIGHT: 288px" cellSpacing="0" cellPadding="1"
				width="553" align="center" border="0">
				<TR>
					<TD style="HEIGHT: 34px" bgColor="#ffff66" colSpan="2">
						<P align="center"><FONT face="新細明體"><STRONG>你必須經過確認才能繼續</STRONG></FONT></P>
					</TD>
				</TR>
				<TR>
					<TD style="HEIGHT: 76px" align="center" width="30%">
						<P><FONT face="新細明體">商品名稱：</FONT></P>
					</TD>
					<TD style="HEIGHT: 76px" align="center"><FONT face="新細明體"><asp:label id="Label12" runat="server" Width="160px" Height="32px"></asp:label></FONT></TD>
				</TR>
				<TR>
					<TD style="HEIGHT: 25px" align="center"><FONT face="新細明體">拍賣編號：</FONT></TD>
					<TD style="HEIGHT: 25px" align="center"><asp:label id="Label11" runat="server" Width="160px" Height="32px"></asp:label></TD>
				</TR>
				<TR>
					<TD style="HEIGHT: 24px" align="center"><FONT face="新細明體">目前最高出價：</FONT></TD>
					<TD style="HEIGHT: 24px" align="center"><FONT face="新細明體">
							<P align="center"><asp:label id="Label10" runat="server" Width="160px" Height="32px"></asp:label></P>
						</FONT>
					</TD>
				</TR>
				<TR>
					<TD style="HEIGHT: 10px" align="center"><FONT face="新細明體">你的出價：</FONT></TD>
					<TD style="HEIGHT: 10px" align="center"><asp:label id="Label9" runat="server" Width="160px" Height="32px"></asp:label></TD>
				</TR>
				<TR>
					<TD style="HEIGHT: 17px" align="center"><FONT face="新細明體">購買數量：</FONT></TD>
					<TD style="HEIGHT: 17px" align="center"><asp:label id="Label8" runat="server" Width="160px" Height="32px"></asp:label></TD>
				</TR>
				<TR>
					<TD align="center" colSpan="2">&nbsp;<!--StartFragment -->
						<FONT color="red" size="-1"><B>當你確實想買這項商品時才出價。如果你得標，你有法律上的購買責任。</B></FONT>
					</TD>
				</TR>
				<TR>
					<TD align="center" colSpan="2"></TD>
				</TR>
			</TABLE>
			<DIV align="center">
				<TABLE id="Table2" style="WIDTH: 442px; HEIGHT: 200px" cellSpacing="0" cellPadding="0"
					width="442" align="center" bgColor="#ffff99" border="0">
					<TR>
						<TD>
							<P align="center">&nbsp;<!--StartFragment -->
								<FONT size="-1"><B>請輸入你的Yahoo!奇摩密碼</B></FONT>
							</P>
						</TD>
					</TR>
					<TR>
						<TD>
							<P align="center">&nbsp;<!--StartFragment -->
								<FONT size="-1"><B><FONT color="red" size="3">嚴禁隨便喊價，違者停權並公佈姓名！</FONT></B></FONT>
							</P>
						</TD>
					</TR>
					<TR>
						<TD>
							<P align="center">&nbsp;<!--StartFragment -->
								<FONT size="-1">帳號：</FONT>
								<asp:label id="Label3" runat="server" Width="160px" Height="14px"></asp:label></P>
						</TD>
					</TR>
					<TR>
						<TD>
							<P align="center">&nbsp;<!--StartFragment -->
								<FONT size="-1">密碼：</FONT>
								<asp:textbox id="TextBox1" runat="server" Width="152px" Height="22px"></asp:textbox></P>
						</TD>
					</TR>
					<TR>
						<TD>
							<P align="center"><asp:button id="Button2" runat="server" Width="56px" Text="出價"></asp:button><FONT face="新細明體">&nbsp;
									<asp:button id="Button3" runat="server" Width="56px" Text="取消"></asp:button></P>
							</FONT></TD>
					</TR>
				</TABLE>
			</DIV>
			<DIV align="center"><FONT face="新細明體"></FONT>&nbsp;</DIV>
			<DIV align="center">
				<TABLE id="Table4" style="WIDTH: 442px; HEIGHT: 66px" cellSpacing="0" cellPadding="0" width="442"
					align="center" border="0">
					<TR>
						<TD>
							<P align="center">&nbsp;<!--StartFragment -->
								<B>按下 「出價」 之前，請確定你已經讀過<!----><A href="http://tw.bid.yahoo.com/phtml/auc/tw/auction_tos.html">使用規範</A><!---->
									且同意遵守這些規範。如果你不同意，請按「取消」。</B></P>
							<P align="center"><B><FONT color="red">請注意：一但出價成功，你即無法取消出價。</FONT></B>
							</P>
						</TD>
					</TR>
				</TABLE>
			</DIV>
			<DIV align="center"><FONT face="新細明體"></FONT>&nbsp;</DIV>
			<DIV align="center"><FONT face="新細明體"></FONT>&nbsp;</DIV>
			<DIV align="center"><FONT face="新細明體">
					<HR style="HEIGHT: 2px" width="90%" color="#ffff33" noShade SIZE="2">
					<P align="center"><asp:label id="Label4" runat="server" Width="128px" Height="14px" Font-Size="Smaller">製作者: 簡志軒 楊有信</asp:label>
				</FONT><FONT face="新細明體">&nbsp;<!--StartFragment -->
					&nbsp;</FONT></P></DIV>
			<DIV align="center">
			</DIV>
			</FONT>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
		</form>
	</body>
</HTML>
