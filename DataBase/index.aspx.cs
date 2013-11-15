using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace C09102014
{
	/// <summary>
	/// index 的摘要描述。
	/// </summary>
	public class index : System.Web.UI.Page
	{
		protected System.Web.UI.HtmlControls.HtmlTable Table1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.Image Image2;
		protected System.Web.UI.WebControls.Image Image3;
		protected System.Web.UI.WebControls.Image Image4;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
		protected System.Web.UI.WebControls.HyperLink HyperLink3;
		protected System.Web.UI.WebControls.HyperLink HyperLink4;
		protected System.Web.UI.WebControls.HyperLink HyperLink5;
		protected System.Web.UI.WebControls.HyperLink HyperLink6;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.HyperLink HyperLink7;
		protected System.Web.UI.WebControls.HyperLink HyperLink8;
		protected System.Web.UI.WebControls.HyperLink HyperLink9;
		protected System.Web.UI.WebControls.HyperLink HyperLink10;
		protected System.Web.UI.WebControls.HyperLink HyperLink11;
		protected System.Web.UI.WebControls.Image Image5;
		protected System.Web.UI.WebControls.Image Image6;
		protected System.Web.UI.WebControls.Image Image7;
		protected System.Web.UI.WebControls.Image Image8;
		protected System.Web.UI.WebControls.Label Label1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			if (Session["uname"]==null)
			{
				Label1.Text = "歡迎光臨! <a href=user_login.aspx>會員登入</a>-<a href=user_add_member.aspx>我要註冊</a>";
			}
			else 
			{
				Label1.Text = Session["暱稱"].ToString() + "(" + Session["uname"].ToString() + 
					"登入中) <a href=user_logout.aspx>會員登出</a>-<a href=user_modify.aspx>修改我的資料</a>";
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
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button1_Click(object sender, System.EventArgs e)
		{
			string str_url="see_bid.aspx?";
			if(TextBox1.Text!=""&&DropDownList1.SelectedIndex!=2)
			{
				if(DropDownList1.SelectedIndex==0)
					str_url+="likeword="+TextBox1.Text;
				else if(DropDownList1.SelectedIndex==1)
					str_url+="sid="+TextBox1.Text;
				Response.Redirect(str_url);	
			}
			else if(TextBox1.Text!="")
			{

				Response.Redirect("see_product.aspx?bid="+TextBox1.Text);
			}
		}


	}
}
