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
	/// select_product 的摘要描述。
	/// </summary>
	public class select_buy : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.TextBox TextBox3;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.DataGrid MyDataGrid;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.TextBox TextBox4;
		protected System.Web.UI.WebControls.TextBox TextBox5;
		protected System.Data.SqlClient.SqlConnection myConnection;
	    
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			
			myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");

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
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		public void BindGrid(string sqlcmd)
		{

			SqlDataAdapter myCommand1 = new SqlDataAdapter(sqlcmd, myConnection);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "product");			
			MyDataGrid.DataSource=ds1.Tables["product"].DefaultView;			
			MyDataGrid.DataBind();
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			string sqlcmd="select * from buy where";		
			string str_and="";
			if(TextBox1.Text!="")
			{
				sqlcmd +=str_and+" 買方帳號 ='"+TextBox1.Text+"' ";
				str_and="and";
			}
			if(TextBox2.Text!="")
			{
				sqlcmd +=str_and+" 訂購數量 = "+TextBox2.Text;
				str_and="and";
			}
			if(TextBox3.Text!="")
			{
				sqlcmd +=str_and+" 出價 ="+TextBox3.Text;
				str_and="and";
			}
			if(TextBox4.Text!="")
			{
				sqlcmd +=str_and+" 日期 = "+TextBox4.Text;
				str_and="and";
			}
			if(TextBox5.Text!="")
			{
				sqlcmd +=str_and+" 拍賣編號 ='"+TextBox5.Text+"' ";
				str_and="and";
			}
			BindGrid(sqlcmd);
		}

		private void Button2_Click(object sender, System.EventArgs e)
		{
			TextBox1.Text="";
			TextBox2.Text="";
			TextBox3.Text="";
			TextBox4.Text="";
			TextBox5.Text="";
		}


	}
}
