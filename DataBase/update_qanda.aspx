<%@ Page language="c#" Codebehind="update_qanda.aspx.cs" AutoEventWireup="false" Inherits="C09102014.update_qanda" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>update_qanda</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="�s�ө���">
				<asp:DataGrid id="DataGrid1" style="Z-INDEX: 101; LEFT: 40px; POSITION: absolute; TOP: 104px"
					runat="server" Width="898px" Height="248px" BorderColor="#E7E7FF" BorderStyle="None" BorderWidth="1px"
					BackColor="White" CellPadding="3" GridLines="Horizontal" DataKeyField="Qnum">
					<FooterStyle ForeColor="#4A3C8C" BackColor="#B5C7DE"></FooterStyle>
					<SelectedItemStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#738A9C"></SelectedItemStyle>
					<AlternatingItemStyle BackColor="#F7F7F7"></AlternatingItemStyle>
					<ItemStyle ForeColor="#4A3C8C" BackColor="#E7E7FF"></ItemStyle>
					<HeaderStyle Font-Bold="True" ForeColor="#F7F7F7" BackColor="#4A3C8C"></HeaderStyle>
					<Columns>
						<asp:EditCommandColumn ButtonType="PushButton" UpdateText="��s" CancelText="����" EditText="�s��"></asp:EditCommandColumn>
					</Columns>
					<PagerStyle HorizontalAlign="Right" ForeColor="#4A3C8C" BackColor="#E7E7FF" Mode="NumericPages"></PagerStyle>
				</asp:DataGrid>
				<asp:Label id="Label2" style="Z-INDEX: 102; LEFT: 192px; POSITION: absolute; TOP: 40px" runat="server"
					Width="592px" Height="24px"></asp:Label></FONT>
		</form>
	</body>
</HTML>
