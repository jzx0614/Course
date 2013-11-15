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
	/// delete_member 的摘要描述。
	/// </summary>
	public class delete_member : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		protected System.Web.UI.WebControls.Label Label2;
		SqlConnection sqlcnt;
		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="member"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
				BindGrid();
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
			this.DataGrid1.DeleteCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_DeleteCommand);
			this.DataGrid1.SelectedIndexChanged += new System.EventHandler(this.DataGrid1_SelectedIndexChanged);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void DataGrid1_SelectedIndexChanged(object sender, System.EventArgs e)
		{
		
		}
		private void DataGrid1_DeleteCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			String deleteCmd = "DELETE from member where 帳號 = @Id";

			SqlCommand myCommand = new SqlCommand(deleteCmd, sqlcnt);
			myCommand.Parameters.Add(new SqlParameter("@Id", SqlDbType.VarChar, 20));

			myCommand.Parameters["@Id"].Value = DataGrid1.DataKeys[(int)e.Item.ItemIndex];

			myCommand.Connection.Open();

			try
			{
				myCommand.ExecuteNonQuery();
				Label2.Text = "<b>已刪除資料錄</b><br>" + deleteCmd;
			}
			catch (SqlException)
			{
				Label2.Text = "錯誤: 無法刪除資料錄";
				Label2.Style["color"] = "red";
			}

			myCommand.Connection.Close();

			BindGrid();		
		}
		public void BindGrid()
		{
			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from member", sqlcnt);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "bid");			
			DataGrid1.DataSource=ds1.Tables["bid"].DefaultView;			
			DataGrid1.DataBind();
		}

	}
}
