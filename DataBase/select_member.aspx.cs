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
	/// WebForm2 的摘要描述。
	/// </summary>
	public class select_member : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.Button search;
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Label Label2;
		SqlConnection sqlcnt;
		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="member"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			/*
			if (!IsPostBack)
			{
				reflesh();
			}*/
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
			this.TextBox1.TextChanged += new System.EventHandler(this.TextBox1_TextChanged);
			this.search.Click += new System.EventHandler(this.search_Click);
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.DropDownList1.SelectedIndexChanged += new System.EventHandler(this.DropDownList1_SelectedIndexChanged);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion


		private void search_Click(object sender, System.EventArgs e)
		{
			string str = "select * from member where " + DropDownList1.SelectedValue.ToString() + " = '" + TextBox1.Text + "';";
			SqlDataAdapter sqlcmd = new SqlDataAdapter(str, sqlcnt);
			try 
			{
				DataSet ds = new DataSet();
				sqlcmd.Fill(ds,"member");
				DataGrid1.DataSource = ds.Tables["member"].DefaultView;
				DataGrid1.DataBind();
			}
			catch (SqlException)
			{
			}
			TextBox1.Text = "";
			str = "";
		}

		private void TextBox1_TextChanged(object sender, System.EventArgs e)
		{
		
		}





		public void reflesh()
		{
			SqlDataAdapter myCommand = new SqlDataAdapter("select * from member;", sqlcnt);

			DataSet ds = new DataSet();
			myCommand.Fill(ds, "member");
			DataGrid1.DataSource=ds.Tables["member"].DefaultView;
			DataGrid1.DataBind();
		}



		private void DropDownList1_SelectedIndexChanged(object sender, System.EventArgs e)
		{
		
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			string str = "select * from member;";
			SqlDataAdapter sqlcmd = new SqlDataAdapter(str, sqlcnt);
			try 
			{
				DataSet ds = new DataSet();
				sqlcmd.Fill(ds,"member");
				DataGrid1.DataSource = ds.Tables["member"].DefaultView;
				DataGrid1.DataBind();
			}
			catch (SqlException)
			{
			}
			TextBox1.Text = "";
			str = "";
		}
	}
}
