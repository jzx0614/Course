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
			<FONT face="�s�ө���">
				<asp:imagebutton id="ImageButton1" style="Z-INDEX: 101; LEFT: 96px; POSITION: absolute; TOP: 96px"
					runat="server" Height="72px" Width="88px"></asp:imagebutton>
				<TABLE id="Table5" style="Z-INDEX: 108; LEFT: 664px; WIDTH: 176px; POSITION: absolute; TOP: 184px; HEIGHT: 170px"
					cellSpacing="1" cellPadding="1" width="176" border="0" runat="server">
					<TR>
						<TD style="HEIGHT: 21px" align="center" bgColor="#ffff99">�n�J����</TD>
					</TR>
					<TR>
						<TD vAlign="top" align="center" bgColor="aliceblue"><FONT face="�s�ө���">
								<P>&nbsp;</P>
								<P>�b��:
									<asp:textbox id="TextBox2" runat="server" Height="26px" Width="120px"></asp:textbox>�K�X:
									<asp:textbox id="TextBox3" runat="server" Height="26px" Width="120px" TextMode="Password"></asp:textbox></P>
								<P><asp:button id="Button2" runat="server" Height="22px" Width="68px" Text="�n�J"></asp:button></P>
							</FONT>
						</TD>
					</TR>
				</TABLE>
				<TABLE id="Table3" style="Z-INDEX: 107; LEFT: 664px; WIDTH: 176px; POSITION: absolute; TOP: 184px; HEIGHT: 172px"
					cellSpacing="1" cellPadding="1" width="176" border="0" runat="server">
					<TR>
						<TD style="HEIGHT: 21px" align="center" bgColor="#ffff99">�X���v�ЩΥߧY�R</TD>
					</TR>
					<TR>
						<TD vAlign="top" align="center" bgColor="beige"><FONT face="�s�ө���">
								<P><FONT size="2">�̧C�X���G
										<asp:label id="Label3" runat="server" Height="10px" Width="84px"></asp:label></FONT></P>
								<P><FONT size="1"><FONT size="2">���X��</FONT> &nbsp;</FONT>
									<asp:textbox id="Textbox4" runat="server" Height="20px" Width="90px"></asp:textbox></P>
								<P><FONT size="2">�q�ʼƶq&nbsp; </FONT>
									<asp:textbox id="Textbox5" runat="server" Height="20px" Width="90px"></asp:textbox></P>
								<P><asp:button id="Button1" runat="server" Height="22px" Width="68px" Text="�w���X��"></asp:button></P>
							</FONT>
						</TD>
					</TR>
				</TABLE>
			</FONT>
			<TABLE id="Table2" style="Z-INDEX: 106; LEFT: 296px; WIDTH: 352px; POSITION: absolute; TOP: 184px; HEIGHT: 412px"
				cellSpacing="1" cellPadding="1" width="352" border="0" runat="server">
				<TR>
					<TD style="HEIGHT: 20px" align="center" bgColor="#ffff99">����ɮ�</TD>
				</TR>
				<TR>
					<TD vAlign="top">&nbsp;�ثe�X��:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						<asp:label id="�ثe�X��" runat="server" Height="16px" Width="192px"></asp:label>
						<P><FONT face="�s�ө���">&nbsp;�����ʶR��:&nbsp;&nbsp;&nbsp;
								<asp:label id="�����ʶR��" runat="server" Height="2px" Width="216px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;�̰��X����:&nbsp;&nbsp;&nbsp;
								<asp:label id="�̰��X����" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;�ӫ~�ƶq:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="�ӫ~�ƶq" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;�_�л���:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="�_�л���" runat="server" Height="16px" Width="200px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;�Ҧb�a��:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="�Ҧb�a��" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;�}�l�ɶ�:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="�}�l�ɶ�" runat="server" Height="16px" Width="168px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;�����ɶ�:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="�����ɶ�" runat="server" Height="16px" Width="192px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;���s��:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="���s��" runat="server" Height="16px" Width="200px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">&nbsp;�B�e�O��:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
								<asp:label id="�B�e�O��" runat="server" Height="16px" Width="200px"></asp:label></FONT></P>
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
					<TD style="HEIGHT: 20px" align="center" bgColor="#ffff99">�����</TD>
				</TR>
				<TR>
					<TD vAlign="top" bgColor="honeydew">
						<P><FONT face="�s�ө���">��a:
								<asp:label id="��a" runat="server" Height="16px" Width="128px"></asp:label></P>
						</FONT>
						<P><FONT face="�s�ө���">����:
								<asp:label id="����" runat="server" Height="12px" Width="48px"></asp:label>&nbsp;</FONT></P>
						<P><FONT face="�s�ө���">�I�ڤ覡:</FONT>
							<asp:label id="�I�ڤ覡" runat="server" Height="16px" Width="104px"></asp:label></P>
						<P><FONT face="�s�ө���">��f�覡:
								<asp:label id="��f�覡" runat="server" Height="16px" Width="104px"></asp:label></FONT></P>
						<P><FONT face="�s�ө���">�ӫ~�s��:
								<asp:label id="�ӫ~�s��" runat="server" Height="16px" Width="104px"></asp:label></P>
						</FONT></TD>
				</TR>
			</TABLE>
			<P><FONT face="�s�ө���"></FONT></P>
			<P></P>
			<P></P>
			<FONT face="�s�ө���">
				<P><FONT face="�s�ө���"></FONT></P>
			</FONT>
			<P><FONT face="�s�ө���">
					<TABLE id="Table7" style="Z-INDEX: 109; LEFT: 664px; WIDTH: 176px; POSITION: absolute; TOP: 384px; HEIGHT: 172px"
						cellSpacing="1" cellPadding="1" width="176" border="0" runat="server">
						<TR>
							<TD style="HEIGHT: 21px" align="center" bgColor="#ffff99"><STRONG>�Q�����R��</STRONG></TD>
						</TR>
						<TR>
							<TD vAlign="top" align="center" bgColor="beige"><FONT face="�s�ө���">
									<P><FONT size="2"></FONT>&nbsp;</P>
									<P><FONT size="2">�����ʻ��G
											<asp:label id="Label4" runat="server" Height="10px" Width="84px"></asp:label></FONT>&nbsp;</P>
									<P><FONT size="2">�q�ʼƶq&nbsp; </FONT>
										<asp:textbox id="Textbox6" runat="server" Height="20px" Width="90px"></asp:textbox></P>
									<P><asp:button id="Button4" runat="server" Height="22px" Width="68px" Text="�ߧY�R"></asp:button></P>
								</FONT>
							</TD>
						</TR>
					</TABLE>
				</FONT>
			</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P align="center">
				<TABLE id="Table6" style="WIDTH: 707px; HEIGHT: 38px" cellSpacing="0" cellPadding="0" width="707"
					border="0">
					<TR>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="HyperLink1" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_self">�ӫ~�ݻP��</asp:hyperlink></TD>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="Hyperlink4" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_self">�X������</asp:hyperlink></TD>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="Hyperlink2" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_self">�ӫ~��T</asp:hyperlink></TD>
						<TD style="HEIGHT: 11px"><asp:hyperlink id="Hyperlink5" runat="server" Height="16px" Width="160px" BackColor="#FFFF80" Target="_blank">�^�����D</asp:hyperlink></TD>
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
						<asp:BoundColumn DataField="�R��b��" HeaderText="�X����">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="�X��" HeaderText="�X�����B">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Right" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="�q�ʼƶq" HeaderText="�ƶq">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="���" HeaderText="�X���ɶ�">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Right" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
					</Columns>
					<PagerStyle VerticalAlign="Middle" NextPageText="�U�@��" Font-Size="Large" PrevPageText="�W�@��" HorizontalAlign="Center"
						ForeColor="#3333CC" PageButtonCount="3" Wrap="False"></PagerStyle>
				</asp:datagrid></P>
			<P align="center">
				<asp:datagrid id="MyDataGrid" runat="server" Width="80%" PageSize="1" AutoGenerateColumns="False"
					AllowCustomPaging="True" HorizontalAlign="Center">
					<HeaderStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#CCCCCC"></HeaderStyle>
					<Columns>
						<asp:BoundColumn DataField="�b��" HeaderText="�b��">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="���D" HeaderText="���D">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Left"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="����" HeaderText="����">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Left" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="���" HeaderText="�o�ݮɶ�">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Right" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
					</Columns>
					<PagerStyle VerticalAlign="Middle" NextPageText="�U�@��" Font-Size="Large" PrevPageText="�W�@��" HorizontalAlign="Center"
						ForeColor="#3333CC" PageButtonCount="3" Wrap="False"></PagerStyle>
				</asp:datagrid></P>
			<P align="center">&nbsp;</P>
			<P align="center"><asp:textbox id="TextBox1" runat="server" Width="408px" Height="96px" TextMode="MultiLine"></asp:textbox></P>
			<P align="center"><asp:button runat="server" id="Button3" Width="105px" Height="24px" Text="�T�w�e�X"></asp:button></P>
			<HR style="HEIGHT: 2px" width="90%" color="#ffff33" noShade SIZE="2">
			<P align="center"><asp:label id="Label2" runat="server" Width="128px" Height="14px" Font-Size="Smaller">�s�@��: ²�Ӱa �����H</asp:label></P>
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
