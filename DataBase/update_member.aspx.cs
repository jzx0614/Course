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
	/// update_member 的摘要描述。
	/// </summary>
	public class update_member : System.Web.UI.Page
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
			{
				reflesh();
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
			this.DataGrid1.CancelCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_CancelCommand);
			this.DataGrid1.EditCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_EditCommand);
			this.DataGrid1.UpdateCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_UpdateComand);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion


		private void DataGrid1_EditCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			DataGrid1.EditItemIndex = (int)e.Item.ItemIndex;
			reflesh();
		}

		private void DataGrid1_CancelCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			DataGrid1.EditItemIndex = -1;
			reflesh();
		}

		public void reflesh()
		{
			SqlDataAdapter myCommand = new SqlDataAdapter("select * from member;", sqlcnt);

			DataSet ds = new DataSet();
			myCommand.Fill(ds, "member");
			DataGrid1.DataSource=ds.Tables["member"].DefaultView;
			DataGrid1.DataBind();
		}

		private void DataGrid1_UpdateComand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			string updateCmd = "UPDATE member SET 帳號 = @Id, 密碼 = @Pwd, 姓氏 = @Name1, 名字 = @Name2, "+ 
				" 暱稱 = @Nick, 姓別 = @Sex , 西元 = @Year, 月 = @Month, 日 = @Day, 身分證字號 = @Idnum, "
				+ "聯絡信箱 = @Mail, 通訊地址 = @Addr, 通訊電話 = @Tel, 行動電話 = @Mtel where 帳號 = @Id";
			SqlCommand myCommand = new SqlCommand(updateCmd, sqlcnt);
			myCommand.Parameters.Add(new SqlParameter("@Id", SqlDbType.VarChar, 20));
			myCommand.Parameters.Add(new SqlParameter("@Pwd", SqlDbType.VarChar, 20));
			myCommand.Parameters.Add(new SqlParameter("@Name1", SqlDbType.VarChar, 10));
			myCommand.Parameters.Add(new SqlParameter("@Name2", SqlDbType.VarChar, 10));
			myCommand.Parameters.Add(new SqlParameter("@Nick", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Sex", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Year", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@Month", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@Day", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@Idnum", SqlDbType.VarChar, 10));
			myCommand.Parameters.Add(new SqlParameter("@Mail", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Addr", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Tel", SqlDbType.VarChar, 20));
			myCommand.Parameters.Add(new SqlParameter("@Mtel", SqlDbType.VarChar, 20));
			myCommand.Parameters["@Id"].Value = DataGrid1.DataKeys[(int)e.Item.ItemIndex];
			string[] cols = {"@Id","@Pwd","@Name1","@Name2","@Nick","@Sex","@Year","@Month","@Day","@Idnum","@Mail","@Addr","@Tel","@Mtel"};
			int numcols = e.Item.Cells.Count;
			for (int i=2; i< numcols; i++) //skip first, second and last column
			{
				string colvalue = ((TextBox)e.Item.Cells[i].Controls[0]).Text;

				// check for null values in required fields
				if (colvalue == "") 
				{
					Label2.Text = "不允許 Null 值"+cols[i-1];
					Label2.Style["color"] = "red";
					return;
				}
				myCommand.Parameters[cols[i-1]].Value = colvalue;
				
			}
			myCommand.Connection.Open();

			try 
			{
				Label2.Text=updateCmd;
				myCommand.ExecuteNonQuery();
				Label2.Text = "<b>已更新資料錄</b><br>" + updateCmd;
				DataGrid1.EditItemIndex = -1;
			}
			catch (SqlException E)
			{
				if (E.Number == 2627)
					Label2.Text = "錯誤: 具有相同主索引鍵的資料錄已經存在";
				else
					Label2.Text = "錯誤: 無法更新資料錄，請確定各欄位是否都已正確填入"+updateCmd;
				Label2.Style["color"] = "red";
			}

			myCommand.Connection.Close();

			reflesh();
		}
	}
}
