<%@ Page language="c#" Codebehind="user_modify.aspx.cs" AutoEventWireup="false" Inherits="C09102014.user_modify" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>user_modify</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<FONT face="新細明體"></FONT>
			<asp:image id="Image1" style="Z-INDEX: 100; LEFT: 128px; POSITION: absolute; TOP: 32px" runat="server"
				ImageUrl="image\logo.jpg" Width="328px" Height="56px"></asp:image>
			<asp:Button id="Button1" style="Z-INDEX: 135; LEFT: 752px; POSITION: absolute; TOP: 504px" runat="server"
				Width="96px" Text="取消並返回"></asp:Button>
			<asp:Button id="確定送出" style="Z-INDEX: 132; LEFT: 376px; POSITION: absolute; TOP: 504px" runat="server"
				Width="96px" Text="確定送出"></asp:Button>
			<asp:Label id="Label16" style="Z-INDEX: 128; LEFT: 136px; POSITION: absolute; TOP: 464px" runat="server"
				Width="98px">通 訊 地 址 ：</asp:Label>
			<asp:TextBox id="通訊地址" style="Z-INDEX: 127; LEFT: 248px; POSITION: absolute; TOP: 464px" runat="server"
				Width="328px"></asp:TextBox>
			<asp:TextBox id="行動電話" style="Z-INDEX: 126; LEFT: 248px; POSITION: absolute; TOP: 432px" runat="server"
				Width="328px"></asp:TextBox>
			<asp:Label id="Label14" style="Z-INDEX: 125; LEFT: 136px; POSITION: absolute; TOP: 432px" runat="server"
				Width="98px">行 動 電 話 ：</asp:Label>
			<asp:TextBox id="通訊電話" style="Z-INDEX: 124; LEFT: 248px; POSITION: absolute; TOP: 400px" runat="server"
				Width="328px"></asp:TextBox>
			<asp:Label id="Label13" style="Z-INDEX: 123; LEFT: 136px; POSITION: absolute; TOP: 400px" runat="server"
				Width="98px">通 訊 電 話 ：</asp:Label>
			<asp:TextBox id="聯絡信箱" style="Z-INDEX: 122; LEFT: 248px; POSITION: absolute; TOP: 368px" runat="server"
				Width="328px"></asp:TextBox>
			<asp:Label id="Label12" style="Z-INDEX: 121; LEFT: 136px; POSITION: absolute; TOP: 368px" runat="server"
				Width="98px">聯 絡 信 箱 ：</asp:Label>
			<asp:Label id="Label10" style="Z-INDEX: 120; LEFT: 560px; POSITION: absolute; TOP: 344px" runat="server"
				Width="24px">日</asp:Label>
			<asp:DropDownList id="日" style="Z-INDEX: 119; LEFT: 480px; POSITION: absolute; TOP: 344px" runat="server"
				Width="72px" Height="24px">
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
			<asp:Label id="Label9" style="Z-INDEX: 117; LEFT: 360px; POSITION: absolute; TOP: 344px" runat="server"
				Width="24px">年</asp:Label>
			<asp:Label id="Label8" style="Z-INDEX: 116; LEFT: 136px; POSITION: absolute; TOP: 344px" runat="server"
				Width="97px">生　　　日：</asp:Label>
			<asp:Label id="Label7" style="Z-INDEX: 114; LEFT: 136px; POSITION: absolute; TOP: 312px" runat="server"
				Width="97px">性　　　別：</asp:Label>
			<asp:Label id="Label6" style="Z-INDEX: 113; LEFT: 136px; POSITION: absolute; TOP: 280px" runat="server"
				Width="97px">暱　　　稱：</asp:Label>
			<asp:Label id="Label5" style="Z-INDEX: 112; LEFT: 136px; POSITION: absolute; TOP: 248px" runat="server"
				Width="97px">名　　　字：</asp:Label>
			<asp:Label id="Label4" style="Z-INDEX: 111; LEFT: 136px; POSITION: absolute; TOP: 216px" runat="server"
				Width="97px">姓　　　氏：</asp:Label>
			<asp:Label id="Label3" style="Z-INDEX: 110; LEFT: 136px; POSITION: absolute; TOP: 184px" runat="server"
				Width="98px">驗 證 密 碼 ：</asp:Label>
			<asp:Label id="Label2" style="Z-INDEX: 109; LEFT: 136px; POSITION: absolute; TOP: 152px" runat="server"
				Width="98px">密　　　碼：</asp:Label>
			<asp:TextBox id="年" style="Z-INDEX: 108; LEFT: 248px; POSITION: absolute; TOP: 344px" runat="server"
				Width="96px"></asp:TextBox>
			<asp:TextBox id="暱稱" style="Z-INDEX: 107; LEFT: 248px; POSITION: absolute; TOP: 280px" runat="server"
				Width="328px"></asp:TextBox>
			<asp:TextBox id="名字" style="Z-INDEX: 106; LEFT: 248px; POSITION: absolute; TOP: 248px" runat="server"
				Width="328px"></asp:TextBox>
			<asp:TextBox id="姓氏" style="Z-INDEX: 105; LEFT: 248px; POSITION: absolute; TOP: 216px" runat="server"
				Width="104px"></asp:TextBox>
			<asp:TextBox id="驗證密碼" style="Z-INDEX: 103; LEFT: 248px; POSITION: absolute; TOP: 184px" runat="server"
				Width="328px" TextMode="Password"></asp:TextBox>
			<asp:TextBox id="密碼" style="Z-INDEX: 101; LEFT: 248px; POSITION: absolute; TOP: 152px" runat="server"
				Width="328px" TextMode="Password"></asp:TextBox>
			<asp:DropDownList id="性別" style="Z-INDEX: 115; LEFT: 248px; POSITION: absolute; TOP: 312px" runat="server"
				Width="72px" Height="8px">
				<asp:ListItem Value="男">男姓</asp:ListItem>
				<asp:ListItem Value="女">女性</asp:ListItem>
			</asp:DropDownList>
			<asp:DropDownList id="月" style="Z-INDEX: 118; LEFT: 400px; POSITION: absolute; TOP: 344px" runat="server"
				Width="72px" Height="24px">
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
			<HR style="Z-INDEX: 102; LEFT: 368px; WIDTH: 490px; POSITION: absolute; TOP: 56px; HEIGHT: 2px"
				color="#ffff33" SIZE="2">
			<asp:Label id="Label1" style="Z-INDEX: 104; LEFT: 136px; POSITION: absolute; TOP: 104px" runat="server"
				Width="721px" Height="8px" BackColor="#FFFF80" ForeColor="#00C000">Yahoo!奇摩拍賣 -  修改我的資料</asp:Label>
			<HR style="Z-INDEX: 129; LEFT: 136px; WIDTH: 744px; POSITION: absolute; TOP: 544px; HEIGHT: 2px"
				SIZE="2">
			<asp:Label id="Label11" style="Z-INDEX: 130; LEFT: 448px; POSITION: absolute; TOP: 552px" runat="server"
				Width="128px" Height="16px" Font-Size="Smaller">製作者: 簡志軒 楊有信</asp:Label>
			<asp:Button id="重新填寫" style="Z-INDEX: 131; LEFT: 264px; POSITION: absolute; TOP: 504px" runat="server"
				Width="96px" Text="重新填寫"></asp:Button>
			<asp:Label id="Label15" style="Z-INDEX: 134; LEFT: 584px; POSITION: absolute; TOP: 152px" runat="server"
				Width="272px" Height="336px" ForeColor="Red" Font-Size="Smaller" BorderColor="#C0C0FF"
				BorderWidth="1px"></asp:Label>
		</form>
	</body>
</HTML>
