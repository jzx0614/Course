<%@ Page language="c#" Codebehind="delete_qanda.aspx.cs" AutoEventWireup="false" Inherits="C09102014.delete_qanda" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>delete_qanda</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:DataGrid id="DataGrid1" style="Z-INDEX: 101; LEFT: 24px; POSITION: absolute; TOP: 128px"
					runat="server" Width="912px" Height="168px" BorderColor="#E7E7FF" BorderStyle="None" BorderWidth="1px"
					BackColor="White" CellPadding="3" GridLines="Horizontal" DataKeyField="Qnum">
					<FooterStyle ForeColor="#4A3C8C" BackColor="#B5C7DE"></FooterStyle>
					<SelectedItemStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#738A9C"></SelectedItemStyle>
					<AlternatingItemStyle BackColor="#F7F7F7"></AlternatingItemStyle>
					<ItemStyle ForeColor="#4A3C8C" BackColor="#E7E7FF"></ItemStyle>
					<HeaderStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#4A3C8C"></HeaderStyle>
					<Columns>
						<asp:ButtonColumn Text="刪除" ButtonType="PushButton" CommandName="Delete"></asp:ButtonColumn>
					</Columns>
					<PagerStyle HorizontalAlign="Right" ForeColor="#4A3C8C" BackColor="#E7E7FF" Mode="NumericPages"></PagerStyle>
				</asp:DataGrid>
				<asp:Label id="Label2" style="Z-INDEX: 102; LEFT: 264px; POSITION: absolute; TOP: 64px" runat="server"
					Width="464px" Height="24px">Label</asp:Label></FONT>
		</form>
	</body>
</HTML>
