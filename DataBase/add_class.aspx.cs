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
	/// add_class 的摘要描述。
	/// </summary>
	public class add_class : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.RequiredFieldValidator RequiredFieldValidator1;
		protected System.Web.UI.WebControls.RequiredFieldValidator RequiredFieldValidator3;
		protected System.Web.UI.WebControls.RequiredFieldValidator RequiredFieldValidator2;
		protected System.Web.UI.HtmlControls.HtmlInputText pclass;
		protected System.Web.UI.HtmlControls.HtmlInputText id;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.HtmlControls.HtmlInputText cname;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			if(Session["group"]==null||(Session["group"].ToString()!="product"&&Session["group"].ToString()!="root"))
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
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button1_Click(object sender, System.EventArgs e)
		{
			Label6.Text = "";

			if (Page.IsValid)
			{

				String insertCmd = "insert into class values (@id, @cname, @pclass)";

				SqlCommand myCommand = new SqlCommand(insertCmd, myConnection);

				myCommand.Parameters.Add(new SqlParameter("@id", SqlDbType.Int, 4));
				myCommand.Parameters["@id"].Value = id.Value;

				myCommand.Parameters.Add(new SqlParameter("@cname", SqlDbType.VarChar, 50));
				myCommand.Parameters["@cname"].Value = cname.Value;

				myCommand.Parameters.Add(new SqlParameter("@pclass", SqlDbType.Int, 4));
				myCommand.Parameters["@pclass"].Value = pclass.Value;

				myCommand.Connection.Open();

				try
				{
					myCommand.ExecuteNonQuery();
					Label6.Text = "<b>已加入此資料錄</b><br>" + insertCmd + "<p>";
				}
				catch (SqlException E)
				{
					if (E.Number == 2627)
						Label6.Text = "錯誤: 具有相同主索引鍵的資料錄已經存在<p>";
					else
						Label6.Text = "錯誤: 無法加入資料錄，請確定各欄位是否都已正確填入<p>";
					Label6.Style["color"] = "red";
				}

				myCommand.Connection.Close();
			}
			
		
		}
	}
}
