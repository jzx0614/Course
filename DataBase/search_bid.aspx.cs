using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace C09102014
{
	/// <summary>
	/// search_bid 的摘要描述。
	/// </summary>
	public class search_bid : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.HtmlControls.HtmlTable Table2;
		protected System.Web.UI.HtmlControls.HtmlForm Form1;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.HtmlControls.HtmlTable Table3;
		protected System.Web.UI.WebControls.Button Button3;
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.HtmlControls.HtmlInputText low_m;
		protected System.Web.UI.HtmlControls.HtmlInputText high_m;
		protected System.Web.UI.HtmlControls.HtmlInputText l_n_m;
		protected System.Web.UI.HtmlControls.HtmlInputText h_n_m;
		protected System.Web.UI.HtmlControls.HtmlInputText likeword;
		protected System.Web.UI.HtmlControls.HtmlInputText Text1;
		protected System.Web.UI.HtmlControls.HtmlInputText Text2;
		protected System.Web.UI.HtmlControls.HtmlInputText Text3;
		protected System.Web.UI.HtmlControls.HtmlInputText Text4;
		protected System.Web.UI.HtmlControls.HtmlInputText Text5;
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			if (Session["uname"]==null)
			{
				Label1.Text = "歡迎光臨!";
				HyperLink1.Text="登入";
				HyperLink1.NavigateUrl="user_login.aspx";
			}
			else 
			{
				Label1.Text = "歡迎光臨! "+Session["暱稱"].ToString()+" ("+Session["uname"].ToString()+")";
				HyperLink1.Text="登出";
				HyperLink1.NavigateUrl="user_logout.aspx";
			}
			myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			string sqlcmd="select DISTINCT 所在地區 from bid";	
			
			SqlCommand myCommand = new SqlCommand(sqlcmd, myConnection);
			myConnection.Open();
			SqlDataReader dr = myCommand.ExecuteReader();
			while (dr.Read()) 
			{
				string place=dr.GetString(0);
				ListItem buf=new ListItem(place,place);
				DropDownList1.Items.Add(buf);
			}
		}

		#region Web Form 設計工具產生的程式碼
		override protected void OnInit(EventArgs e)
		{
			//
			// CODEGEN: 此為 ASP.NET Web Form 設計工具所需的呼叫。
			//
			InitializeComponent();
			base.OnInit(e);
		}
		
		/// <summary>
		/// 此為設計工具支援所必須的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		private void InitializeComponent()
		{    
			this.myConnection = new System.Data.SqlClient.SqlConnection();
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.Button3.Click += new System.EventHandler(this.Button3_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button1_Click(object sender, System.EventArgs e)
		{
			string str_url="see_bid.aspx?";
			string first="";
			if(TextBox1.Text!="")
			{
				str_url+="likeword="+TextBox1.Text;
				first="&";
			}
			if(low_m.Value!="")
			{
				str_url+=first+"low_money="+low_m.Value;
				first="&";
			}
			if(high_m.Value!="")
			{
				str_url+=first+"high_money="+high_m.Value;
				first="&";
			}
			if(l_n_m.Value!="")
			{
				str_url+=first+"l_n_money="+l_n_m.Value;
				first="&";
			}
			if(h_n_m.Value!="")
			{
				str_url+=first+"h_n_money="+h_n_m.Value;
				first="&";
			}
			if(DropDownList1.SelectedIndex!=0)
			{
				str_url+=first+"place="+DropDownList1.SelectedItem.Text;
			}
			Response.Redirect(str_url);
		}

		private void Button3_Click(object sender, System.EventArgs e)
		{
			string str_url="see_bid.aspx?";			
			if(TextBox2.Text!="")
				str_url+="sid="+TextBox2.Text;
			Response.Redirect(str_url);
		}

		private void Button2_Click(object sender, System.EventArgs e)
		{
			string str_url="see_bid.aspx?";
			string first="";
			if(likeword.Value!="")
			{
				str_url+="likeword="+likeword.Value;
				first="&";
			}
			if(Text1.Value!="")
			{
				str_url+=first+"sid1="+Text1.Value;
				first="&";
			}
			if(Text2.Value!="")
			{
				str_url+=first+"sid2="+Text2.Value;
				first="&";
			}
			if(Text3.Value!="")
			{
				str_url+=first+"sid3="+Text3.Value;
				first="&";
			}
			if(Text4.Value!="")
			{
				str_url+=first+"sid4="+Text4.Value;
				first="&";
			}
			if(Text5.Value!="")
				str_url+=first+"sid5="+Text5.Value;

			Response.Redirect(str_url);		
		}
	}
}
