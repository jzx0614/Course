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
			<P><FONT face="新細明體"><asp:image id="Image1" style="Z-INDEX: 102; LEFT: 8px; POSITION: absolute; TOP: 8px" runat="server"
						ImageUrl="image\logo.jpg" Height="56px" Width="328px"></asp:image></P>
			<HR style="Z-INDEX: 101; LEFT: 368px; WIDTH: 490px; POSITION: absolute; TOP: 40px; HEIGHT: 2px"
				color="#ffff33" SIZE="2">
			<P>&nbsp;&nbsp;</FONT></P>
			<P><FONT face="新細明體">&nbsp;</P>
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
					<asp:ListItem Value="只在這個類別">只在這個類別</asp:ListItem>
					<asp:ListItem Value="搜尋所有類別">搜尋所有類別</asp:ListItem>
				</asp:dropdownlist><asp:button id="Button1" runat="server" Width="72px" Text="搜尋"></asp:button>&nbsp;<A href="search_bid.aspx">進階搜尋</A></P>
			<P align="center"></P>
			</FONT>
			<P align="center"><asp:label id="Label1" runat="server" Height="16px" Width="100%" BackColor="Yellow" Font-Size="Larger"
					Font-Bold="True">注目商品</asp:label></P>
			<P align="center"><asp:datagrid id="MyDataGrid" runat="server" Width="100%" PageSize="1" AutoGenerateColumns="False"
					AllowCustomPaging="True" HorizontalAlign="Center">
					<HeaderStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#CCCCCC"></HeaderStyle>
					<Columns>
						<asp:BoundColumn DataField="拍賣編號" HeaderText="拍賣編號">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:HyperLinkColumn DataNavigateUrlField="拍賣編號" DataNavigateUrlFormatString="see_product.aspx?bid={0}"
							DataTextField="商品標題" HeaderText="商品標題">
							<ItemStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Left" VerticalAlign="Middle"></ItemStyle>
							<FooterStyle Font-Size="X-Small" Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></FooterStyle>
						</asp:HyperLinkColumn>
						<asp:BoundColumn DataField="目前出價" HeaderText="目前出價">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
						<asp:BoundColumn DataField="結束時間" HeaderText="結束時間">
							<ItemStyle Font-Size="X-Small" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						</asp:BoundColumn>
					</Columns>
					<PagerStyle VerticalAlign="Middle" NextPageText="下一頁" Font-Size="Large" PrevPageText="上一頁" HorizontalAlign="Center"
						ForeColor="#3333CC" PageButtonCount="3" Wrap="False"></PagerStyle>
				</asp:datagrid></P>
			<P align="center"></P>
			<HR width="100%" color="#ffff00">
			<P align="center">&nbsp;
				<asp:label id="Label2" runat="server" Height="24px" Width="144px" Font-Size="X-Small">製作者 簡志軒　楊有信</asp:label></P>
			<P align="center">&nbsp;</P>
			<P align="center"><FONT face="新細明體"></FONT>&nbsp;</P>
			<P align="center">&nbsp;</P>
			<P align="center">&nbsp;</P>
		</form>
	</body>
</HTML>
