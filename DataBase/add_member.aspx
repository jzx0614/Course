<%@ Page language="c#" Codebehind="add_member.aspx.cs" AutoEventWireup="false" Inherits="C09102014.add_member" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>add_member</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體">
				<asp:TextBox id="TextBox1" style="Z-INDEX: 101; LEFT: 208px; POSITION: absolute; TOP: 80px" runat="server"
					Width="328px"></asp:TextBox>
				<asp:Label id="Label16" style="Z-INDEX: 133; LEFT: 96px; POSITION: absolute; TOP: 464px" runat="server"
					Width="98px">通 訊 地 址 ：</asp:Label>
				<asp:TextBox id="TextBox12" style="Z-INDEX: 132; LEFT: 208px; POSITION: absolute; TOP: 464px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Button id="Button2" style="Z-INDEX: 130; LEFT: 400px; POSITION: absolute; TOP: 544px" runat="server"
					Width="72px" Height="24px" Text="確定送出"></asp:Button>
				<asp:TextBox id="TextBox11" style="Z-INDEX: 128; LEFT: 208px; POSITION: absolute; TOP: 432px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label14" style="Z-INDEX: 127; LEFT: 96px; POSITION: absolute; TOP: 432px" runat="server"
					Width="98px">行 動 電 話 ：</asp:Label>
				<asp:TextBox id="TextBox10" style="Z-INDEX: 126; LEFT: 208px; POSITION: absolute; TOP: 400px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label13" style="Z-INDEX: 125; LEFT: 96px; POSITION: absolute; TOP: 400px" runat="server"
					Width="98px">通 訊 電 話 ：</asp:Label>
				<asp:TextBox id="TextBox9" style="Z-INDEX: 124; LEFT: 208px; POSITION: absolute; TOP: 368px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label12" style="Z-INDEX: 123; LEFT: 96px; POSITION: absolute; TOP: 368px" runat="server"
					Width="98px">聯 絡 信 箱 ：</asp:Label>
				<asp:TextBox id="TextBox8" style="Z-INDEX: 122; LEFT: 208px; POSITION: absolute; TOP: 336px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label11" style="Z-INDEX: 121; LEFT: 96px; POSITION: absolute; TOP: 336px" runat="server"
					Width="98px">身分證字號：</asp:Label>
				<asp:Label id="Label10" style="Z-INDEX: 120; LEFT: 520px; POSITION: absolute; TOP: 304px" runat="server"
					Width="24px">日</asp:Label>
				<asp:DropDownList id="DropDownList3" style="Z-INDEX: 119; LEFT: 440px; POSITION: absolute; TOP: 304px"
					runat="server" Width="72px" Height="24px">
					<asp:ListItem Value="1" Selected="True">1</asp:ListItem>
					<asp:ListItem Value="2">2</asp:ListItem>
					<asp:ListItem Value="3">3</asp:ListItem>
					<asp:ListItem Value="4">4</asp:ListItem>
					<asp:ListItem Value="5">5</asp:ListItem>
					<asp:ListItem Value="6">6</asp:ListItem>
					<asp:ListItem Value="7">7</asp:ListItem>
					<asp:ListItem Value="8">8</asp:ListItem>
					<asp:ListItem Value="9">9</asp:ListItem>
					<asp:ListItem Value="10">10</asp:ListItem>
					<asp:ListItem Value="11">11</asp:ListItem>
					<asp:ListItem Value="12">12</asp:ListItem>
					<asp:ListItem Value="13">13</asp:ListItem>
					<asp:ListItem Value="14">14</asp:ListItem>
					<asp:ListItem Value="15">15</asp:ListItem>
					<asp:ListItem Value="16">16</asp:ListItem>
					<asp:ListItem Value="17">17</asp:ListItem>
					<asp:ListItem Value="18">18</asp:ListItem>
					<asp:ListItem Value="19">19</asp:ListItem>
					<asp:ListItem Value="20">20</asp:ListItem>
					<asp:ListItem Value="21">21</asp:ListItem>
					<asp:ListItem Value="22">22</asp:ListItem>
					<asp:ListItem Value="23">23</asp:ListItem>
					<asp:ListItem Value="24">24</asp:ListItem>
					<asp:ListItem Value="25">25</asp:ListItem>
					<asp:ListItem Value="26">26</asp:ListItem>
					<asp:ListItem Value="27">27</asp:ListItem>
					<asp:ListItem Value="28">28</asp:ListItem>
					<asp:ListItem Value="29">29</asp:ListItem>
					<asp:ListItem Value="30">30</asp:ListItem>
					<asp:ListItem Value="31">31</asp:ListItem>
				</asp:DropDownList>
				<asp:Label id="Label9" style="Z-INDEX: 117; LEFT: 320px; POSITION: absolute; TOP: 304px" runat="server"
					Width="24px">年</asp:Label>
				<asp:Label id="Label8" style="Z-INDEX: 116; LEFT: 96px; POSITION: absolute; TOP: 304px" runat="server"
					Width="97px">生　　　日：</asp:Label>
				<asp:Label id="Label7" style="Z-INDEX: 114; LEFT: 96px; POSITION: absolute; TOP: 272px" runat="server"
					Width="97px">性　　　別：</asp:Label>
				<asp:Label id="Label6" style="Z-INDEX: 113; LEFT: 96px; POSITION: absolute; TOP: 240px" runat="server"
					Width="97px">暱　　　稱：</asp:Label>
				<asp:Label id="Label5" style="Z-INDEX: 112; LEFT: 96px; POSITION: absolute; TOP: 208px" runat="server"
					Width="97px">名　　　字：</asp:Label>
				<asp:Label id="Label4" style="Z-INDEX: 111; LEFT: 96px; POSITION: absolute; TOP: 176px" runat="server"
					Width="97px">姓　　　氏：</asp:Label>
				<asp:Label id="Label3" style="Z-INDEX: 110; LEFT: 96px; POSITION: absolute; TOP: 144px" runat="server"
					Width="98px">驗 證 密 碼 ：</asp:Label>
				<asp:Label id="Label2" style="Z-INDEX: 109; LEFT: 96px; POSITION: absolute; TOP: 112px" runat="server"
					Width="98px">密　　　碼：</asp:Label>
				<asp:TextBox id="TextBox7" style="Z-INDEX: 107; LEFT: 208px; POSITION: absolute; TOP: 304px"
					runat="server" Width="96px"></asp:TextBox>
				<asp:TextBox id="TextBox6" style="Z-INDEX: 106; LEFT: 208px; POSITION: absolute; TOP: 240px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:TextBox id="TextBox5" style="Z-INDEX: 105; LEFT: 208px; POSITION: absolute; TOP: 208px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:TextBox id="TextBox4" style="Z-INDEX: 104; LEFT: 208px; POSITION: absolute; TOP: 176px"
					runat="server" Width="104px"></asp:TextBox>
				<asp:TextBox id="TextBox3" style="Z-INDEX: 103; LEFT: 208px; POSITION: absolute; TOP: 144px"
					runat="server" Width="328px" TextMode="Password"></asp:TextBox>
				<asp:TextBox id="TextBox2" style="Z-INDEX: 102; LEFT: 208px; POSITION: absolute; TOP: 112px"
					runat="server" Width="328px" TextMode="Password"></asp:TextBox>
				<asp:Label id="Label1" style="Z-INDEX: 108; LEFT: 96px; POSITION: absolute; TOP: 80px" runat="server"
					Width="98px">帳　　　號：</asp:Label>
				<asp:DropDownList id="DropDownList1" style="Z-INDEX: 115; LEFT: 208px; POSITION: absolute; TOP: 272px"
					runat="server" Width="72px" Height="8px">
					<asp:ListItem Value="男">男姓</asp:ListItem>
					<asp:ListItem Value="女">女性</asp:ListItem>
				</asp:DropDownList>
				<asp:DropDownList id="DropDownList2" style="Z-INDEX: 118; LEFT: 360px; POSITION: absolute; TOP: 304px"
					runat="server" Width="72px" Height="24px">
					<asp:ListItem Value="1" Selected="True">一月</asp:ListItem>
					<asp:ListItem Value="2">二月</asp:ListItem>
					<asp:ListItem Value="3">三月</asp:ListItem>
					<asp:ListItem Value="4">四月</asp:ListItem>
					<asp:ListItem Value="5">五月</asp:ListItem>
					<asp:ListItem Value="6">六月</asp:ListItem>
					<asp:ListItem Value="7">七月</asp:ListItem>
					<asp:ListItem Value="8">八月</asp:ListItem>
					<asp:ListItem Value="9">九月</asp:ListItem>
					<asp:ListItem Value="10">十月</asp:ListItem>
					<asp:ListItem Value="11">十一月</asp:ListItem>
					<asp:ListItem Value="12">十二月</asp:ListItem>
				</asp:DropDownList>
				<asp:Button id="Button1" style="Z-INDEX: 129; LEFT: 272px; POSITION: absolute; TOP: 544px" runat="server"
					Width="72px" Height="24px" Text="重新填寫"></asp:Button>
				<asp:Label id="Label15" style="Z-INDEX: 131; LEFT: 592px; POSITION: absolute; TOP: 80px" runat="server"
					Width="232px" Height="428px" ForeColor="Red" BorderWidth="1px" BorderColor="#C04000"><br>  每個欄位一定要確實填寫喔!!</asp:Label>
				<asp:LinkButton id="LinkButton1" style="Z-INDEX: 134; LEFT: 632px; POSITION: absolute; TOP: 32px"
					runat="server" Width="112px" Height="24px">會員管理首頁</asp:LinkButton></FONT>
		</form>
	</body>
</HTML>
