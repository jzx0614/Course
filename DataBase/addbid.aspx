<%@ Page language="c#" Codebehind="addbid.aspx.cs" AutoEventWireup="false" Inherits="C09102014.addbid" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>addbid</title>
		<meta name="GENERATOR" Content="Microsoft Visual Studio .NET 7.1">
		<meta name="CODE_LANGUAGE" Content="C#">
		<meta name="vs_defaultClientScript" content="JavaScript">
		<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form EncType="multipart/form-data" method="post" runat="server" ID="Form2">
			<asp:Label id="Label3" style="Z-INDEX: 101; LEFT: 104px; POSITION: absolute; TOP: 1192px" runat="server"
				Width="320px" Height="40px" Font-Size="X-Large" ForeColor="Blue">３　新增相片</asp:Label>
			<asp:Label id="Label33" style="Z-INDEX: 166; LEFT: 112px; POSITION: absolute; TOP: 192px" runat="server"
				Height="24px" Width="728px" BackColor="#FFE0C0">輔助性選擇讓您更方便(沒有子類別顯示及表示已經到類別底端)</asp:Label>
			<asp:Label id="Label32" style="Z-INDEX: 165; LEFT: 104px; POSITION: absolute; TOP: 136px" runat="server"
				ForeColor="Blue" Font-Size="X-Large" Height="40px" Width="320px">１　選擇商品類別</asp:Label>
			<asp:Button id="Button2" style="Z-INDEX: 159; LEFT: 432px; POSITION: absolute; TOP: 440px" runat="server"
				Width="88px" Text="Step 2"></asp:Button>
			<asp:ListBox id="ListBox2" style="Z-INDEX: 157; LEFT: 376px; POSITION: absolute; TOP: 296px"
				runat="server" Height="138px" Width="200px"></asp:ListBox>
			<asp:Label id="Label26" style="Z-INDEX: 150; LEFT: 264px; POSITION: absolute; TOP: 920px" runat="server"
				Height="16px" Width="16px">年</asp:Label>
			<asp:TextBox id="y2" style="Z-INDEX: 149; LEFT: 200px; POSITION: absolute; TOP: 920px" runat="server"
				Width="56px"></asp:TextBox>
			<asp:TextBox id="TextBox6" style="Z-INDEX: 139; LEFT: 288px; POSITION: absolute; TOP: 880px"
				runat="server" Width="48px"></asp:TextBox>
			<asp:TextBox id="d1" style="Z-INDEX: 142; LEFT: 384px; POSITION: absolute; TOP: 880px" runat="server"
				Width="48px"></asp:TextBox>
			<asp:Label id="Label25" style="Z-INDEX: 144; LEFT: 264px; POSITION: absolute; TOP: 880px" runat="server"
				Height="16px" Width="16px">年</asp:Label>
			<asp:Label id="Label24" style="Z-INDEX: 146; LEFT: 352px; POSITION: absolute; TOP: 880px" runat="server"
				Height="16px" Width="24px">月</asp:Label>
			<asp:Label id="Label23" style="Z-INDEX: 148; LEFT: 448px; POSITION: absolute; TOP: 880px" runat="server"
				Height="16px" Width="24px">日</asp:Label>
			<asp:Label id="Label14" style="Z-INDEX: 126; LEFT: 120px; POSITION: absolute; TOP: 920px" runat="server"
				Width="64px" Height="8px">結束時間</asp:Label>
			<asp:Label id="Label12" style="Z-INDEX: 123; LEFT: 376px; POSITION: absolute; TOP: 744px" runat="server"
				Width="64px" Height="24px">商品新舊</asp:Label>
			<asp:Label id="Label9" style="Z-INDEX: 116; LEFT: 120px; POSITION: absolute; TOP: 792px" runat="server"
				Width="64px" Height="24px">所在地區</asp:Label>
			<asp:Label id="Label8" style="Z-INDEX: 115; LEFT: 608px; POSITION: absolute; TOP: 744px" runat="server"
				Width="64px" Height="24px">交貨方式</asp:Label>
			<asp:Label id="Label7" style="Z-INDEX: 114; LEFT: 120px; POSITION: absolute; TOP: 744px" runat="server"
				Width="64px" Height="24px">付款方式</asp:Label>
			<asp:TextBox id="商品標題" style="Z-INDEX: 113; LEFT: 200px; POSITION: absolute; TOP: 688px" runat="server"
				Width="336px"></asp:TextBox>
			<asp:Label id="Label6" style="Z-INDEX: 112; LEFT: 120px; POSITION: absolute; TOP: 696px" runat="server"
				Width="64px" Height="24px">商品標題</asp:Label>
			<asp:TextBox id="TextBox2" style="Z-INDEX: 110; LEFT: 200px; POSITION: absolute; TOP: 648px"
				runat="server" Width="336px"></asp:TextBox>
			<asp:Label id="Label5" style="Z-INDEX: 109; LEFT: 112px; POSITION: absolute; TOP: 608px" runat="server"
				Width="736px" Height="24px" BackColor="#FFE0C0">請填寫商品詳細敘述</asp:Label>
			<asp:Label id="Label1" style="Z-INDEX: 104; LEFT: 104px; POSITION: absolute; TOP: 552px" runat="server"
				Width="320px" Height="40px" Font-Size="X-Large" ForeColor="Blue">２　拍賣物品資料</asp:Label>&nbsp;&nbsp;
			<asp:Button id="btnUpload" style="Z-INDEX: 100; LEFT: 456px; POSITION: absolute; TOP: 1344px"
				runat="server" Width="88px" Text="送出申請"></asp:Button>
			<HR style="Z-INDEX: 102; LEFT: 344px; WIDTH: 490px; POSITION: absolute; TOP: 64px; HEIGHT: 2px"
				color="#ffff33" SIZE="2">
			<asp:image id="Image1" style="Z-INDEX: 103; LEFT: 104px; POSITION: absolute; TOP: 40px" runat="server"
				Width="328px" Height="56px" ImageUrl="image\logo.jpg"></asp:image>
			<input type="file" id="File1" runat="server" NAME="File1" style="Z-INDEX: 105; LEFT: 112px; WIDTH: 392px; POSITION: absolute; TOP: 1280px; HEIGHT: 22px"
				size="46">
			<asp:Label id="Label2" style="Z-INDEX: 106; LEFT: 112px; POSITION: absolute; TOP: 1240px" runat="server"
				Width="744px" Height="24px" BackColor="#FFE0C0">請選擇您要上傳的資料</asp:Label>
			<asp:Label id="Label4" style="Z-INDEX: 107; LEFT: 120px; POSITION: absolute; TOP: 648px" runat="server"
				Width="64px" Height="24px">商品名稱</asp:Label>
			<asp:TextBox id="商品名稱" style="Z-INDEX: 111; LEFT: 200px; POSITION: absolute; TOP: 648px" runat="server"
				Width="336px"></asp:TextBox>
			<asp:TextBox id="所在地區" style="Z-INDEX: 117; LEFT: 200px; POSITION: absolute; TOP: 792px" runat="server"
				Width="320px"></asp:TextBox>
			<asp:Label id="Label10" style="Z-INDEX: 118; LEFT: 536px; POSITION: absolute; TOP: 792px" runat="server"
				Width="128px" Height="24px">(以縣或市為單位)</asp:Label>
			<asp:Label id="Label11" style="Z-INDEX: 119; LEFT: 120px; POSITION: absolute; TOP: 840px" runat="server"
				Width="64px" Height="24px">運費</asp:Label>
			<asp:TextBox id="運費" style="Z-INDEX: 120; LEFT: 200px; POSITION: absolute; TOP: 840px" runat="server"
				Width="320px"></asp:TextBox>
			<asp:DropDownList id="付款方式" style="Z-INDEX: 121; LEFT: 200px; POSITION: absolute; TOP: 744px" runat="server"
				Width="128px" Height="24px">
				<asp:ListItem Value="現金">現金</asp:ListItem>
				<asp:ListItem Value="ATM">ATM</asp:ListItem>
				<asp:ListItem Value="支票或匯票">支票或匯票</asp:ListItem>
			</asp:DropDownList>
			<asp:DropDownList id="交貨方式" style="Z-INDEX: 122; LEFT: 688px; POSITION: absolute; TOP: 744px" runat="server"
				Width="128px" Height="24px">
				<asp:ListItem Value="面交">面交</asp:ListItem>
				<asp:ListItem Value="郵寄">郵寄</asp:ListItem>
			</asp:DropDownList>
			<asp:DropDownList id="商品新舊" style="Z-INDEX: 124; LEFT: 456px; POSITION: absolute; TOP: 744px" runat="server"
				Width="88px" Height="24px">
				<asp:ListItem Value="1">新</asp:ListItem>
				<asp:ListItem Value="0">舊</asp:ListItem>
			</asp:DropDownList>
			<asp:Label id="Label13" style="Z-INDEX: 125; LEFT: 120px; POSITION: absolute; TOP: 880px" runat="server"
				Width="64px" Height="8px">開始時間</asp:Label>
			<asp:Label id="Label15" style="Z-INDEX: 127; LEFT: 536px; POSITION: absolute; TOP: 888px" runat="server"
				Width="80px" Height="16px">直接購買價</asp:Label>
			<asp:TextBox id="直接購買價" style="Z-INDEX: 128; LEFT: 624px; POSITION: absolute; TOP: 880px" runat="server"
				Width="120px"></asp:TextBox>
			<asp:Label id="Label16" style="Z-INDEX: 129; LEFT: 536px; POSITION: absolute; TOP: 928px" runat="server"
				Width="56px" Height="16px">起標價</asp:Label>
			<asp:TextBox id="起標價" style="Z-INDEX: 130; LEFT: 624px; POSITION: absolute; TOP: 920px" runat="server"
				Width="120px"></asp:TextBox>
			<asp:TextBox id="交易守則" style="Z-INDEX: 131; LEFT: 512px; POSITION: absolute; TOP: 1032px" runat="server"
				Width="312px" Height="106px" TextMode="MultiLine"></asp:TextBox>
			<asp:Label id="Label17" style="Z-INDEX: 132; LEFT: 496px; POSITION: absolute; TOP: 1000px"
				runat="server" Width="128px" Height="16px">交易守則(可不寫)</asp:Label>
			<asp:Label id="Label18" style="Z-INDEX: 133; LEFT: 120px; POSITION: absolute; TOP: 960px" runat="server"
				Width="64px" Height="16px">商品數量</asp:Label>
			<asp:TextBox id="商品數量" style="Z-INDEX: 134; LEFT: 200px; POSITION: absolute; TOP: 952px" runat="server"
				Width="112px" Height="26px"></asp:TextBox>
			<asp:Label id="Label19" style="Z-INDEX: 135; LEFT: 120px; POSITION: absolute; TOP: 1000px"
				runat="server" Height="24px" Width="144px"> 商品描述(可不填寫)</asp:Label>
			<asp:TextBox id="商品敘述" style="Z-INDEX: 136; LEFT: 120px; POSITION: absolute; TOP: 1032px" runat="server"
				Height="106px" Width="320px" TextMode="MultiLine"></asp:TextBox>
			<asp:Label id="error" style="Z-INDEX: 137; LEFT: 272px; POSITION: absolute; TOP: 1392px" runat="server"
				Height="16px" Width="472px"></asp:Label>
			<asp:TextBox id="y1" style="Z-INDEX: 138; LEFT: 200px; POSITION: absolute; TOP: 880px" runat="server"
				Width="56px"></asp:TextBox>
			<asp:TextBox id="m1" style="Z-INDEX: 140; LEFT: 288px; POSITION: absolute; TOP: 880px" runat="server"
				Width="48px"></asp:TextBox>
			<asp:TextBox id="TextBox4" style="Z-INDEX: 141; LEFT: 384px; POSITION: absolute; TOP: 880px"
				runat="server" Width="48px"></asp:TextBox>
			<asp:Label id="Label20" style="Z-INDEX: 143; LEFT: 264px; POSITION: absolute; TOP: 880px" runat="server"
				Height="16px" Width="16px">年</asp:Label>
			<asp:Label id="Label21" style="Z-INDEX: 145; LEFT: 352px; POSITION: absolute; TOP: 880px" runat="server"
				Height="16px" Width="24px">月</asp:Label>
			<asp:Label id="Label22" style="Z-INDEX: 147; LEFT: 448px; POSITION: absolute; TOP: 880px" runat="server"
				Height="16px" Width="24px">日</asp:Label>
			<asp:TextBox id="m2" style="Z-INDEX: 151; LEFT: 288px; POSITION: absolute; TOP: 920px" runat="server"
				Width="48px"></asp:TextBox>
			<asp:Label id="Label27" style="Z-INDEX: 152; LEFT: 352px; POSITION: absolute; TOP: 920px" runat="server"
				Height="8px" Width="16px">月</asp:Label>
			<asp:TextBox id="d2" style="Z-INDEX: 153; LEFT: 384px; POSITION: absolute; TOP: 920px" runat="server"
				Height="22px" Width="48px"></asp:TextBox>
			<asp:Label id="Label28" style="Z-INDEX: 154; LEFT: 448px; POSITION: absolute; TOP: 920px" runat="server"
				Height="16px" Width="24px">日</asp:Label>
			<asp:Label id="error1" style="Z-INDEX: 155; LEFT: 712px; POSITION: absolute; TOP: 136px" runat="server"
				Height="24px" Width="129px"></asp:Label>
			<asp:ListBox id="ListBox1" style="Z-INDEX: 156; LEFT: 128px; POSITION: absolute; TOP: 296px"
				runat="server" Height="138px" Width="200px"></asp:ListBox>
			<asp:Button id="Button1" style="Z-INDEX: 158; LEFT: 184px; POSITION: absolute; TOP: 440px" runat="server"
				Width="88px" Text="Step 1"></asp:Button>
			<asp:ListBox id="ListBox3" style="Z-INDEX: 160; LEFT: 632px; POSITION: absolute; TOP: 296px"
				runat="server" Height="140px" Width="200px"></asp:ListBox>
			<asp:Button id="Button3" style="Z-INDEX: 161; LEFT: 696px; POSITION: absolute; TOP: 440px" runat="server"
				Width="80px" Text="Step 3"></asp:Button>
			<asp:Label id="Label29" style="Z-INDEX: 162; LEFT: 136px; POSITION: absolute; TOP: 256px" runat="server"
				Height="24px" Width="48px">主類別</asp:Label>
			<asp:Label id="Label30" style="Z-INDEX: 163; LEFT: 376px; POSITION: absolute; TOP: 256px" runat="server"
				Height="16px" Width="72px">子類別 - 1</asp:Label>
			<asp:Label id="Label31" style="Z-INDEX: 164; LEFT: 632px; POSITION: absolute; TOP: 256px" runat="server"
				Height="24px" Width="72px">子類別 - 2</asp:Label>
		</form>
	</body>
</HTML>
