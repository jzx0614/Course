<%@ Page language="c#" Codebehind="user_add_member.aspx.cs" AutoEventWireup="false" Inherits="C09102014.user_add_member" %>
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
				<asp:TextBox id="TextBox1" style="Z-INDEX: 100; LEFT: 232px; POSITION: absolute; TOP: 128px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:image id="Image1" style="Z-INDEX: 133; LEFT: 128px; POSITION: absolute; TOP: 16px" runat="server"
					Width="328px" Height="56px" ImageUrl="image\logo.jpg"></asp:image>
				<asp:Label id="Label16" style="Z-INDEX: 132; LEFT: 120px; POSITION: absolute; TOP: 512px" runat="server"
					Width="98px">通 訊 地 址 ：</asp:Label>
				<asp:TextBox id="TextBox12" style="Z-INDEX: 131; LEFT: 232px; POSITION: absolute; TOP: 512px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Button id="Button2" style="Z-INDEX: 129; LEFT: 424px; POSITION: absolute; TOP: 592px" runat="server"
					Width="72px" Height="24px" Text="確定送出"></asp:Button>
				<asp:TextBox id="TextBox11" style="Z-INDEX: 127; LEFT: 232px; POSITION: absolute; TOP: 480px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label14" style="Z-INDEX: 126; LEFT: 120px; POSITION: absolute; TOP: 480px" runat="server"
					Width="98px">行 動 電 話 ：</asp:Label>
				<asp:TextBox id="TextBox10" style="Z-INDEX: 125; LEFT: 232px; POSITION: absolute; TOP: 448px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label13" style="Z-INDEX: 124; LEFT: 120px; POSITION: absolute; TOP: 448px" runat="server"
					Width="98px">通 訊 電 話 ：</asp:Label>
				<asp:TextBox id="TextBox9" style="Z-INDEX: 123; LEFT: 232px; POSITION: absolute; TOP: 416px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label12" style="Z-INDEX: 122; LEFT: 120px; POSITION: absolute; TOP: 416px" runat="server"
					Width="98px">聯 絡 信 箱 ：</asp:Label>
				<asp:TextBox id="TextBox8" style="Z-INDEX: 121; LEFT: 232px; POSITION: absolute; TOP: 384px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:Label id="Label11" style="Z-INDEX: 120; LEFT: 120px; POSITION: absolute; TOP: 384px" runat="server"
					Width="98px">身分證字號：</asp:Label>
				<asp:Label id="Label10" style="Z-INDEX: 119; LEFT: 544px; POSITION: absolute; TOP: 352px" runat="server"
					Width="24px">日</asp:Label>
				<asp:DropDownList id="DropDownList3" style="Z-INDEX: 118; LEFT: 464px; POSITION: absolute; TOP: 352px"
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
				<asp:Label id="Label9" style="Z-INDEX: 116; LEFT: 344px; POSITION: absolute; TOP: 352px" runat="server"
					Width="24px">年</asp:Label>
				<asp:Label id="Label8" style="Z-INDEX: 115; LEFT: 120px; POSITION: absolute; TOP: 352px" runat="server"
					Width="97px">生　　　日：</asp:Label>
				<asp:Label id="Label7" style="Z-INDEX: 113; LEFT: 120px; POSITION: absolute; TOP: 320px" runat="server"
					Width="97px">性　　　別：</asp:Label>
				<asp:Label id="Label6" style="Z-INDEX: 112; LEFT: 120px; POSITION: absolute; TOP: 288px" runat="server"
					Width="97px">暱　　　稱：</asp:Label>
				<asp:Label id="Label5" style="Z-INDEX: 111; LEFT: 120px; POSITION: absolute; TOP: 256px" runat="server"
					Width="97px">名　　　字：</asp:Label>
				<asp:Label id="Label4" style="Z-INDEX: 110; LEFT: 120px; POSITION: absolute; TOP: 224px" runat="server"
					Width="97px">姓　　　氏：</asp:Label>
				<asp:Label id="Label3" style="Z-INDEX: 109; LEFT: 120px; POSITION: absolute; TOP: 192px" runat="server"
					Width="98px">驗 證 密 碼 ：</asp:Label>
				<asp:Label id="Label2" style="Z-INDEX: 108; LEFT: 120px; POSITION: absolute; TOP: 160px" runat="server"
					Width="98px">密　　　碼：</asp:Label>
				<asp:TextBox id="TextBox7" style="Z-INDEX: 106; LEFT: 232px; POSITION: absolute; TOP: 352px"
					runat="server" Width="96px"></asp:TextBox>
				<asp:TextBox id="TextBox6" style="Z-INDEX: 105; LEFT: 232px; POSITION: absolute; TOP: 288px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:TextBox id="TextBox5" style="Z-INDEX: 104; LEFT: 232px; POSITION: absolute; TOP: 256px"
					runat="server" Width="328px"></asp:TextBox>
				<asp:TextBox id="TextBox4" style="Z-INDEX: 103; LEFT: 232px; POSITION: absolute; TOP: 224px"
					runat="server" Width="104px"></asp:TextBox>
				<asp:TextBox id="TextBox3" style="Z-INDEX: 102; LEFT: 232px; POSITION: absolute; TOP: 192px"
					runat="server" Width="328px" TextMode="Password"></asp:TextBox>
				<asp:TextBox id="TextBox2" style="Z-INDEX: 101; LEFT: 232px; POSITION: absolute; TOP: 160px"
					runat="server" Width="328px" TextMode="Password"></asp:TextBox>
				<asp:Label id="Label1" style="Z-INDEX: 107; LEFT: 120px; POSITION: absolute; TOP: 128px" runat="server"
					Width="98px">帳　　　號：</asp:Label>
				<asp:DropDownList id="DropDownList1" style="Z-INDEX: 114; LEFT: 232px; POSITION: absolute; TOP: 320px"
					runat="server" Width="72px" Height="8px">
					<asp:ListItem Value="男">男姓</asp:ListItem>
					<asp:ListItem Value="女">女性</asp:ListItem>
				</asp:DropDownList>
				<asp:DropDownList id="DropDownList2" style="Z-INDEX: 117; LEFT: 384px; POSITION: absolute; TOP: 352px"
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
				<asp:Button id="Button1" style="Z-INDEX: 128; LEFT: 296px; POSITION: absolute; TOP: 592px" runat="server"
					Width="72px" Height="24px" Text="重新填寫"></asp:Button>
				<asp:Label id="Label15" style="Z-INDEX: 130; LEFT: 616px; POSITION: absolute; TOP: 128px" runat="server"
					Width="232px" Height="428px" ForeColor="Red" BorderWidth="1px" BorderColor="#C04000"><br>  1. 每個欄位一定要確實填寫喔!!<br><br>2. 註冊成功後會自動前往首頁，<br>  在進行登入!!</asp:Label>
				<asp:Label id="Label17" style="Z-INDEX: 134; LEFT: 120px; POSITION: absolute; TOP: 88px" runat="server"
					Width="729px" Height="24px" BorderColor="White" ForeColor="Blue" BackColor="#FFFFC0">仿 Yahoo! 拍賣會員註冊填寫</asp:Label></FONT>
			<HR style="Z-INDEX: 135; LEFT: 112px; WIDTH: 749px; POSITION: absolute; TOP: 632px; HEIGHT: 2px"
				SIZE="2">
			<asp:Label id="Label18" style="Z-INDEX: 137; LEFT: 432px; POSITION: absolute; TOP: 640px" runat="server"
				Width="128px" Height="16px" Font-Size="Smaller">製作者: 簡志軒 楊有信</asp:Label>
			<HR style="Z-INDEX: 138; LEFT: 368px; WIDTH: 473px; POSITION: absolute; TOP: 32px; HEIGHT: 2px"
				color="#ffff33" SIZE="2">
		</form>
	</body>
</HTML>
