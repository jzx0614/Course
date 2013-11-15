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
	/// select_qanda 的摘要描述。
	/// </summary>
	public class select_qanda : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		protected System.Web.UI.WebControls.Label Label1;
		SqlConnection sqlcnt;
		protected System.Web.UI.WebControls.Label Label2;
		string cmd;
		bool run = true;
		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				Label1.Text = "請依照性質查詢!!";
			}
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
			if (DropDownList1.SelectedValue.ToString() != "all")
			{
				if (TextBox1.Text=="")
				{
					Label1.Text = "查詢條件不足!";
					run = false;
				}
				else if (DropDownList1.SelectedValue.ToString() != "問題")
					cmd += "select * from QandA where " + DropDownList1.SelectedValue.ToString() + "= '" + TextBox1.Text + "';";
				else cmd += "select * from QandA where " + DropDownList1.SelectedValue.ToString() + " like '%" + TextBox1.Text + "%';";
			}
			else cmd = "select * from QandA;";
			if (run)
			{
				SqlDataAdapter da = new SqlDataAdapter(cmd,sqlcnt);
				try 
				{
					DataSet ds = new DataSet();
					da.Fill(ds,"QandA");
					DataGrid1.DataSource = ds.Tables["QandA"].DefaultView;
					DataGrid1.DataBind();
				}
				catch (SqlException)
				{
				}
				Label1.Text = cmd;
			}
			TextBox1.Text = "";
			cmd = "";
			run = true;
		}
	}
}
