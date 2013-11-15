<%@ Page language="c#" Codebehind="update_product.aspx.cs" AutoEventWireup="false" Inherits="C09102014.update_product" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>WebForm1</title>
		<meta content="True" name="vs_showGrid">
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
	</HEAD>
	<body bgColor="#33ccff">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:datagrid id="MyDataGrid1" style="Z-INDEX: 105; LEFT: 16px; POSITION: absolute; TOP: 552px"
					runat="server" DataKeyField="類別編號" UseAccessibleHeader="True" CaptionAlign="Right" Height="20px"
					HorizontalAlign="Center" Font-Names="Verdana, 新細明體" Font-Size="8pt" HeaderStyle-BackColor="#aaaadd"
					Font-Name="Verdana, 新細明體" CellSpacing="1" CellPadding="2" BorderColor="Black" BackColor="#CCCCFF"
					Width="100%">
					<FooterStyle Wrap="False"></FooterStyle>
					<SelectedItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></SelectedItemStyle>
					<EditItemStyle Wrap="False" HorizontalAlign="Center" ForeColor="Black" VerticalAlign="Middle" BackColor="White"></EditItemStyle>
					<AlternatingItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></AlternatingItemStyle>
					<ItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
					<HeaderStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#AAAADD"></HeaderStyle>
					<Columns>
						<asp:ButtonColumn Text="刪除" ButtonType="PushButton" CommandName="Delete">
							<ItemStyle HorizontalAlign="Center"></ItemStyle>
						</asp:ButtonColumn>
						<asp:EditCommandColumn ButtonType="PushButton" UpdateText="更新" CancelText="取消" EditText="編輯">
							<ItemStyle HorizontalAlign="Center"></ItemStyle>
						</asp:EditCommandColumn>
					</Columns>
					<PagerStyle VerticalAlign="Middle" Visible="False" HorizontalAlign="Center" ForeColor="Black"
						BackColor="Yellow" Wrap="False"></PagerStyle>
				</asp:datagrid>
				<P align="center">&nbsp;</P>
				<P align="center">
					<asp:Label id="Label2" runat="server" Width="488px" Height="24px"></asp:Label></P>
				<P align="center">
					<asp:datagrid id="MyDataGrid" runat="server" Width="100%" BackColor="#CCCCFF" BorderColor="Black"
						CellPadding="2" CellSpacing="1" Font-Name="Verdana, 新細明體" HeaderStyle-BackColor="#aaaadd"
						Font-Size="8pt" Font-Names="Verdana,新細明體" HorizontalAlign="Center" Height="20px" CaptionAlign="Right"
						UseAccessibleHeader="True" DataKeyField="拍賣編號">
						<FooterStyle Wrap="False"></FooterStyle>
						<SelectedItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></SelectedItemStyle>
						<EditItemStyle Wrap="False" HorizontalAlign="Center" ForeColor="Black" VerticalAlign="Middle" BackColor="White"></EditItemStyle>
						<AlternatingItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></AlternatingItemStyle>
						<ItemStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle"></ItemStyle>
						<HeaderStyle Wrap="False" HorizontalAlign="Center" VerticalAlign="Middle" BackColor="#AAAADD"></HeaderStyle>
						<Columns>
							<asp:EditCommandColumn ButtonType="PushButton" UpdateText="更新" CancelText="取消" EditText="編輯">
								<ItemStyle HorizontalAlign="Center"></ItemStyle>
							</asp:EditCommandColumn>
						</Columns>
						<PagerStyle VerticalAlign="Middle" Visible="False" HorizontalAlign="Center" ForeColor="Black"
							BackColor="Yellow" Wrap="False"></PagerStyle>
					</asp:datagrid></P>
			</FONT>
		</form>
	</body>
</HTML>
