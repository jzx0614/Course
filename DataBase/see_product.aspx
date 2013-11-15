<%@ Page language="c#" Codebehind="see_product.aspx.cs" AutoEventWireup="false" Inherits="C09102014.see_product" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>see_product</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
	</HEAD>
	<body bgColor="#f0ffff">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:imagebutton id="ImageButton1" style="Z-INDEX: 101; LEFT: 96px; POSITION: absolute; TOP: 96px"
					runat="server" Height="72px" Width="88px"></asp:imagebutton>
				<TABLE id="Table5" style="Z-INDEX: 108; LEFT: 664px; WIDTH: 176px; POSITION: absolute; TOP: 184px; HEIGHT: 170px"
					cellSpacing="1" cellPadding="1" width="176" border="0" runat="server">
					<TR>
						<TD style="HEIGHT: 21px" align="center" bgColor="#ffff99">登入介面</TD>
					</TR>
					<TR>
						<TD vAlign="top" align="center" bgColor="aliceblue"><FONT face="新細明體">
								<P>&nbsp;</P>
								<P>帳號:
									<asp:textbox id="TextBox2" runat="server" Height="26px" Width="120px"></asp:textbox>密碼:
									<asp:textbox id="TextBox3" runat="server" Height="26px" Width="120px" TextMode="Password"></asp:textbox></P>
								<P><asp:button id="Button2" runat="server" Height="22px" Width="68px" Text="登入"></asp:button></P>
							</FONT>
						</TD>
					</TR>
				</TABLE>
				<TABLE id="Table3" style="Z-INDEX: 107; LEFT: 664px; WIDTH: 176px; POSITION: absolute; TOP: 184px; HEIGHT: 172px"
					cellSpacing="1" cellPadding="1" width="176" border="0" runat="server">
					<TR>
						<TD style="HEIGHT: 21px" align="center" bgColor="#ffff99">出價競標或立即買</TD>
					</TR>
					<TR>
						<TD vAlign="top" align="center" bgColor="beige"><FONT face="新細明體">
								<P><FONT size="2">最低出價：
										<asp:label id="Label3" runat="server" Height="10px" Width="84px"></asp:label></FONT></P>
								<P><FONT size="1"><FONT size="2">拍賣出價</FONT> &nbsp;</FONT>
									<asp:textbox id="Textbox4" runat="server" Height="20px" Width="90px"></asp:textbox></P>
								<P><FONT size="2">訂購數量&nbsp; </FONT>
									<asp:textbox id="Textbox5" runat="server" Height="20px" Width="90px"></asp:textbox></P>
								<P><asp:button id="Button1" runat="server" Height="22px" Width="68px" Text="預覽出價"></asp:button></P>
							</FONT>
						</TD>
					</TR>
				</TABLE>
			</FONT>
			<TABLE id="Table2" style="Z-INDEX: 106; LEFT: 296px; WIDTH: 352px; POSITION: absolute; TOP: 184px; HEIGHT: 412px"
				cellSpacing="1" cellPadding="1" width="352" border="0" runat="server">
				<TR>
					<TD style="HEIGHT: 20px" align="center" bgColor="#ffff99">拍賣檔案</TD>
				</TR>
				<TR>
					<TD vAlign="top">&nbsp;目前出價:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						<asp:label id="目前出價" runat="server" Height="16px" Width="192px"></asp:label>
						<P><FONT face="新細明體">&nbsp;直接購買價:&nbsp;&nbsp;&nbsp;
								<asp:label id="直接購買價" runat="server" Height="2px" Width="216px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;最高出價者:&nbsp;&nbsp;&nbsp;
								<asp:label id="最高出價者" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;商品數量:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="商品數量" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;起標價格:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="起標價格" runat="server" Height="16px" Width="200px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;所在地區:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="所在地區" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;開始時間:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="開始時間" runat="server" Height="16px" Width="168px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;結束時間:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="結束時間" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;拍賣編號:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="拍賣編號" runat="server" Height="16px" Width="200px"></asp:label></FONT></P>
						<P><FONT face="新細明體">&nbsp;運送費用:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="運送費用" runat="server" Height="16px" Width="200px"></asp:label></FONT></P>
					</TD>
				</TR>
			</TABLE>
			<HR style="Z-INDEX: 102; LEFT: 344px; WIDTH: 490px; POSITION: absolute; TOP: 48px; HEIGHT: 2px"
				color="#ffff33" noShade SIZE="2">
			<asp:image id="Image1" style="Z-INDEX: 103; LEFT: 104px; POSITION: absolute; TOP: 24px" runat="server"
				Height="56px" Width="328px" ImageUrl="image\logo.jpg"></asp:image><asp:label id="Label1" style="Z-INDEX: 104; LEFT: 208px; POSITION: absolute; TOP: 128px" runat="server"
				Height="24px" Width="625px" BackColor="Yellow">Label</asp:label>
			<TABLE id="Table1" style="Z-INDEX: 105; LEFT: 96px; WIDTH: 192px; POSITION: absolute; TOP: 184px; HEIGHT: 120px"
				cellSpacing="1" cellPadding="1" width="192" border="0" runat="server">
				<TR>
					<TD style="HEIGHT: 20px" align="center" bgColor="#ffff99">賣方資料</TD>
				</TR>
				<TR>
					<TD vAlign="top" bgColor="honeydew">
						<P><FONT face="新細明體">賣家:
								<asp:label id="賣家" runat="server" Height="16px" Width="128px"></asp:label></P>
						</FONT>
						<P><FONT face="新細明體">評價:
								<asp:label id="評價" runat="server" Height="12px" Width="48px"></asp:label>&nbsp;</FONT></P>
						<P><FONT face="新細明體">付款方式:</FONT>
							<asp:label id="付款方式" runat="server" Height="16px" Width="104px"></asp:label></P>
						<P><FONT face="新細明體">交貨方式:
								<asp:label id="交貨方式" runat="server" Height="16px" Width="104px"></asp:label></FONT></P>
						<P><FONT face="新細明體">商品新舊:
								<asp:label id="商品新舊" runat="server" Height="16px" Width="104px"></asp:label></P>
						</FONT></TD>
				</TR>
			</TABLE>
			<P><FONT face="新細明體"></FONT></P>
			<P></P>
			<P></P>
			<FONT face="新細明體">
				<P><FONT face="新細明體"></FONT></P>
			</FONT>
			<P><FONT face="新細明體">
					<TABLE id="Table7" style="Z-INDEX: 109; LEFT: 664px; WIDTH: 176px; POSITION: absolute; TOP: 384px; HEIGHT: 172px"
						cellSpacing="1" cellPadding="1" width="176" border="0" runat="server">
						<TR>
							<TD style="HEIGHT: 21px" align="center" bgColor="#ffff99"><STRONG>想直接買嗎</STRONG></TD>
						</TR>
						<TR>
							<TD vAlign="top" align="center" bgColor="beige"><FONT face="新細明體">
									<P><FONT size="2"></FONT>&nbsp;</P>
									<P><FONT size="2">直接購價：
											<asp:label id="Label4" runat="server" Height="10px" Width="84px"></asp:label></FONT>&nbsp;</P>
									<P><FONT size="2">訂購數量&nbsp; </FONT>
										<asp:textbox id="Textbox6" runat="server" Height="20px" Width="90px"></asp:textbox></P>
									<P><asp:button id="Button4" runat="server" Height="22px" Width="68px" Text="立即買"></asp:button></P>
								</FONT>
							</TD>
						</TR>
					</TABLE>
				</FONT>
			</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P><FONT face="新細明體"></FONT>&nbsp;</P>
			<P align="center">
				<TABLE id="Table6" style="WIDTH: 707px; HEIGHT: 38px" cellSpacing="0" cellPadding="0" width="707"
					border="0">
					<TR>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="HyperLink1" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_self">商品問與答</asp:hyperlink></TD>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="Hyperlink4" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_self">出價紀錄</asp:hyperlink></TD>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="Hyperlink2" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_self">商品資訊</asp:hyperlink></TD>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="Hyperlink5" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_blank">回答問題</asp:hyperlink></TD>
					</TR>
					<TR>
						<TD style="HEIGHT: 17px" bgColor="#ffff66" colSpan="4">&nbsp;
						</TD>
					</TR>
				</TABLE>
			</P>
			<P align="center">
				<asp:imagebutton id="ImageButton2" runat="server" Height="234px" Width="292px"></asp:imagebutton>
				<asp:label id="Label5" runat="server" Width="382px" Height="232px"></asp:label></P>
			<P align="center"><asp:datagrid id="Datagrid1" runat="server" Width="80%" HorizontalAlign="Center" AllowCustomPaging="True"
					AutoGenerateColumns="False" PageSize="1">
					<HeaderStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#CCCCCC"></HeaderStyle>
					<Columns>
						<asp:BoundColumn DataField="買方帳號" HeaderText="出價者">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="出價" HeaderText="出價金額">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Right" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="訂購數量" HeaderText="數量">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="日期" HeaderText="出價時間">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Right" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
					</Columns>
					<PagerStyle VerticalAlign="Middle" NextPageText="下一頁" Font-Size="Large" PrevPageText="上一頁" HorizontalAlign="Center"
						ForeColor="#3333CC" PageButtonCount="3" Wrap="False"></PagerStyle>
				</asp:datagrid></P>
			<P align="center">
				<asp:datagrid id="MyDataGrid" runat="server" Width="80%" PageSize="1" AutoGenerateColumns="False"
					AllowCustomPaging="True" HorizontalAlign="Center">
					<HeaderStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#CCCCCC"></HeaderStyle>
					<Columns>
						<asp:BoundColumn DataField="帳號" HeaderText="帳號">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="問題" HeaderText="問題">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Left"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="答案" HeaderText="答覆">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Left" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="日期" HeaderText="發問時間">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Right" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
					</Columns>
					<PagerStyle VerticalAlign="Middle" NextPageText="下一頁" Font-Size="Large" PrevPageText="上一頁" HorizontalAlign="Center"
						ForeColor="#3333CC" PageButtonCount="3" Wrap="False"></PagerStyle>
				</asp:datagrid></P>
			<P align="center">&nbsp;</P>
			<P align="center"><asp:textbox id="TextBox1" runat="server" Width="408px" Height="96px" TextMode="MultiLine"></asp:textbox></P>
			<P align="center"><asp:button runat="server" id="Button3" Width="105px" Height="24px" Text="確定送出"></asp:button></P>
			<HR style="HEIGHT: 2px" width="90%" color="#ffff33" noShade SIZE="2">
			<P align="center"><asp:label id="Label2" runat="server" Width="128px" Height="14px" Font-Size="Smaller">製作者: 簡志軒 楊有信</asp:label></P>
			<P align="center">
			</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">
			<P></P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
		</form>
	</body>
</HTML>
