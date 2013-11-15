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
using System.Data.SqlClient;

namespace C09102014
{
	/// <summary>
	/// login 的摘要描述。
	/// </summary>
	public class login : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.TextBox username;
		protected System.Web.UI.WebControls.TextBox passwd;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Button Button1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			Session.RemoveAll();
			// 在這裡放置使用者程式碼以初始化網頁
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
			string cmd="select 密碼,群組 from admin where 帳號='"+username.Text+"'";
			Label4.Text=cmd;
			SqlConnection myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			SqlCommand myCommand = new SqlCommand(cmd, myConnection);

			myConnection.Open();

			SqlDataReader dr = myCommand.ExecuteReader();
			if(dr.Read())
			{
				if(dr["密碼"].ToString()==passwd.Text)
				{
					Session["group"]=dr["群組"].ToString();
					if(Session["group"].ToString()=="product")
						Response.Redirect("adm_product.aspx");
					else if(Session["group"].ToString()=="bid")
						Response.Redirect("adm_bid.aspx");
					else
						Response.Redirect("adm_member.aspx");
				}
				else
					Label4.Text="密碼錯誤"+dr["密碼"];
			}
			else{
				Label4.Text="此帳號不存在";
			}
	
			dr.Close();
			myConnection.Close();			
		}
	}
}
