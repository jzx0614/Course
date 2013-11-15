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
	/// user_modify 的摘要描述。
	/// </summary>
	public class user_modify : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label Label12;
		protected System.Web.UI.WebControls.Label Label13;
		protected System.Web.UI.WebControls.Label Label14;
		protected System.Web.UI.WebControls.Label Label16;
		protected System.Web.UI.WebControls.TextBox 聯絡信箱;
		protected System.Web.UI.WebControls.TextBox 通訊電話;
		protected System.Web.UI.WebControls.TextBox 行動電話;
		protected System.Web.UI.WebControls.TextBox 通訊地址;
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.DropDownList 月;
		protected System.Web.UI.WebControls.DropDownList 性別;
		protected System.Web.UI.WebControls.TextBox 密碼;
		protected System.Web.UI.WebControls.TextBox 驗證密碼;
		protected System.Web.UI.WebControls.TextBox 姓氏;
		protected System.Web.UI.WebControls.TextBox 名字;
		protected System.Web.UI.WebControls.TextBox 暱稱;
		protected System.Web.UI.WebControls.TextBox 年;
		protected System.Web.UI.WebControls.DropDownList 日;
		protected System.Web.UI.WebControls.Button 重新填寫;
		protected System.Web.UI.WebControls.Button 確定送出;
		protected System.Web.UI.WebControls.Label Label15;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Image Image1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			
			if (! IsPostBack)
			{
				Label1.Text += "(" + Session["uname"].ToString() + ")";
				reflesh();
			}
		}
		private void reflesh()
		{
			string cmd="select * from member where 帳號='"+Session["uname"].ToString()+"'";
			SqlConnection myConnection = new SqlConnection("server=127.0.0.1;uid=project;pwd=project;database=C09102014");
			SqlCommand myCommand = new SqlCommand(cmd, myConnection);
			myConnection.Open();
			SqlDataReader dr = myCommand.ExecuteReader();
			if(dr.Read())
			{
				姓氏.Text = dr["姓氏"].ToString();
				名字.Text = dr["名字"].ToString();
				暱稱.Text = dr["暱稱"].ToString();
				聯絡信箱.Text = dr["聯絡信箱"].ToString();
				名字.Text = dr["名字"].ToString();
				通訊電話.Text = dr["通訊電話"].ToString();
				行動電話.Text = dr["行動電話"].ToString();
				通訊地址.Text = dr["通訊地址"].ToString();
			}
				
			dr.Close();
			myConnection.Close();	
			Label15.Text="若不更改密碼，請在密碼欄留空白！";
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
			this.確定送出.Click += new System.EventHandler(this.確定送出_Click);
			this.重新填寫.Click += new System.EventHandler(this.重新填寫_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void 重新填寫_Click(object sender, System.EventArgs e)
		{
			Label15.Text="若不更改密碼，請在密碼欄留空白！";
			reflesh();
		}

		private void 確定送出_Click(object sender, System.EventArgs e)
		{
			Label15.Text="";
			bool go = true;
			bool setpwd = true;
			if (密碼.Text!=驗證密碼.Text)
			{
				Label15.Text += "密碼輸入不同<br>";
				go =false;
			}
			if (密碼.Text=="" && 驗證密碼.Text=="")
			{
				setpwd = false;
			}
			if (姓氏.Text=="")
			{
				Label15.Text += "姓氏不可為空白<br>";
				go = false;
			}
			if (名字.Text=="")
			{
				Label15.Text += "名字不可為空白<br>";
				go = false;
			}
			if (年.Text=="")
			{
				Label15.Text += "出生年份不可為空白<br>";
				go = false;
			}
			if (聯絡信箱.Text=="")
			{
				Label15.Text += "聯絡信箱不可為空白<br>";
				go = false;
			}
			if (通訊電話.Text=="")
			{
				Label15.Text += "通訊電話不可為空白<br>";
				go = false;
			}
			if (行動電話.Text=="")
			{
				Label15.Text += "行動電話不可為空白<br>";
				go = false;
			}
			if (通訊地址.Text=="")
			{
				Label15.Text += "通訊地址不可為空白<br>";
				go = false;
			}
			if (go)
			{
				string cmd = "update member set ";
				if (setpwd)
				{
					cmd += "密碼='" + 密碼.Text + "', ";
				}
				cmd += " 姓氏='" + 姓氏.Text + "', " +
					"名字='" + 名字.Text + "', " +
					"暱稱='" + 暱稱.Text + "', " +
					"姓別='" + 性別.SelectedValue.ToString() + "', "+
					"西元='" + 年.Text + "', " +
					"月='" + 月.SelectedValue.ToString() + "', "+
					"日='" + 日.SelectedValue.ToString() + "', " +
					"聯絡信箱='" + 聯絡信箱.Text + "', "+
					"通訊電話='" + 通訊電話.Text + "', "+
					"行動電話='" + 行動電話.Text + "', " +
					"通訊地址='" + 通訊地址.Text + "' " +
					"where 帳號='" + Session["uname"].ToString() + "'";
				SqlConnection myConnection = new SqlConnection("server=127.0.0.1;uid=project;pwd=project;database=C09102014");
				SqlCommand myCommand = new SqlCommand(cmd, myConnection);
				myConnection.Open();
				myCommand.ExecuteNonQuery();
				myCommand.Connection.Close();
				Response.Redirect("index.aspx");
			}
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			Response.Redirect("index.aspx");
		}
	}
}
