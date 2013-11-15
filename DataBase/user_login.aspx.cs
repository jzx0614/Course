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
	/// user_login 的摘要描述。
	/// </summary>
	public class user_login : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.HtmlControls.HtmlTableCell TD1;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.HtmlControls.HtmlTable Table3;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Button Button1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
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
			string cmd="select 密碼, 暱稱, Enable from member where 帳號='"+TextBox1.Text+"'";
			SqlConnection myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			SqlCommand myCommand = new SqlCommand(cmd, myConnection);

			myConnection.Open();

			SqlDataReader dr = myCommand.ExecuteReader();
			if(dr.Read())
			{
				if(dr["密碼"].ToString()==TextBox2.Text && dr["Enable"].ToString()=="True")
				{
					Session["uname"] = TextBox1.Text;
					Session["暱稱"] = dr["暱稱"].ToString();
					Response.Redirect("index.aspx");
				}
				else if (dr["Enable"].ToString()=="False")
				{
					Label1.Text="此帳號已經被凍結了!!<br>請洽詢管理者";
				}
				else
				{
					Label1.Text="密碼錯誤";
				}
			}
			else
			{
				Label1.Text="此帳號不存在";
			}
	
			dr.Close();
			myConnection.Close();	
		}
	}
}
