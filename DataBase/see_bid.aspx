<%@ Page language="c#" Codebehind="see_bid.aspx.cs" AutoEventWireup="false" Inherits="C09102014.see_bid" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>see_bid</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
	</HEAD>
	<body bgColor="azure">
		<form id="Form1" method="post" runat="server">
			<P><FONT face="�s�ө���"><asp:image id="Image1" style="Z-INDEX: 102; LEFT: 8px; POSITION: absolute; TOP: 8px" runat="server"
						ImageUrl="image\logo.jpg" Height="56px" Width="328px"></asp:image></P>
			<HR style="Z-INDEX: 101; LEFT: 368px; WIDTH: 490px; POSITION: absolute; TOP: 40px; HEIGHT: 2px"
				color="#ffff33" SIZE="2">
			<P>&nbsp;&nbsp;</FONT></P>
			<P><FONT face="�s�ө���">&nbsp;</P>
			<P align="center"><IMG height="86" src="image/ad4.JPG" width="651"></P>
			<P></P>
			<P align="center">
				<HR width="100%" color="#ffff00">
			<P></P>
			<P>
			<P align="center"><asp:table id="Table1" runat="server" Height="24px" Width="659px">
					<asp:TableRow></asp:TableRow>
				</asp:table></P>
			<HR width="100%" color="#ffff00">
			<P></P>
			<P></P>
			<P align="center">&nbsp;<INPUT id="Text1" type="text" name="textfield" runat="server">
				<asp:dropdownlist id="DropDownList1" runat="server" Height="32px" Width="107px">
					<asp:ListItem Value="�u�b�o�����O">�u�b�o�����O</asp:ListItem>
					<asp:ListItem Value="�j�M�Ҧ����O">�j�M�Ҧ����O</asp:ListItem>
				</asp:dropdownlist><asp:button id="Button1" runat="server" Width="72px" Text="�j�M"></asp:button>&nbsp;<A href="search_bid.aspx">�i���j�M</A></P>
			<P align="center"></P>
			</FONT>
			<P align="center"><asp:label id="Label1" runat="server" Height="16px" Width="100%" BackColor="Yellow" Font-Size="Larger"
					Font-Bold="True">�`�ذӫ~</asp:label></P>
			<P align="center"><asp:datagrid id="MyDataGrid" runat="server" Width="100%" PageSize="1" AutoGenerateColumns="False"
					AllowCustomPaging="True" HorizontalAlign="Center">
					<HeaderStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#CCCCCC"></HeaderStyle>
					<Columns>
						<asp:BoundColumn DataField="���s��" HeaderText="���s��">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:HyperLinkColumn DataNavigateUrlField="���s��" DataNavigateUrlFormatString="see_product.aspx?bid={0}"
							DataTextField="�ӫ~���D" HeaderText="�ӫ~���D">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Left" VerticalAlign="Middle"></ItemStyle>
							<FooterStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></FooterStyle>
						</asp:HyperLinkColumn>
						<asp:BoundColumn DataField="�ثe�X��" HeaderText="�ثe�X��">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="�����ɶ�" HeaderText="�����ɶ�">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
					</Columns>
					<PagerStyle VerticalAlign="Middle" NextPageText="�U�@��" Font-Size="Large" PrevPageText="�W�@��" HorizontalAlign="Center"
						ForeColor="#3333CC" PageButtonCount="3" Wrap="False"></PagerStyle>
				</asp:datagrid></P>
			<P align="center"></P>
			<HR width="100%" color="#ffff00">
			<P align="center">&nbsp;
				<asp:label id="Label2" runat="server" Height="24px" Width="144px" Font-Size="X-Small">�s�@�� ²�Ӱa�@�����H</asp:label></P>
			<P align="center">&nbsp;</P>
			<P align="center"><FONT face="�s�ө���"></FONT>&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
		</form>
	</body>
</HTML>
