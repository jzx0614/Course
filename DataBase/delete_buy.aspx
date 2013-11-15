<%@ Page language="c#" Codebehind="delete_buy.aspx.cs" AutoEventWireup="false" Inherits="C09102014.delete_buy" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>delete_product</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body bgColor="#33ccff">
		<form id="Form1" method="post" runat="server">
			<P align="center">
				<asp:Label id="Label2" runat="server" Height="24px" Width="488px"></asp:Label></P>
			<P align="center">
				<asp:datagrid id="MyDataGrid" runat="server" DataKeyField="買方帳號" UseAccessibleHeader="True" CaptionAlign="Right"
					Height="20px" HorizontalAlign="Center" Font-Names="Verdana, 新細明體" Font-Size="8pt" HeaderStyle-BackColor="#aaaadd"
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
					</Columns>
					<PagerStyle VerticalAlign="Middle" Visible="False" HorizontalAlign="Center" ForeColor="Black"
						BackColor="Yellow" Wrap="False"></PagerStyle>
				</asp:datagrid></P>
		</form>
	</body>
</HTML>
