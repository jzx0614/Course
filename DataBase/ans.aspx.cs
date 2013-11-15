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
	/// ans 的摘要描述。
	/// </summary>
	public class ans : System.Web.UI.Page
	{
		string bidnum;
		string qnum;
		protected System.Web.UI.WebControls.Label Label1;
		string seller;
		protected System.Web.UI.WebControls.Table Table1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		SqlConnection sqlcnt;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			bidnum = Request.QueryString["bid"];
			qnum = Request.QueryString["qnum"];
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			string cmd = "select 賣家編號 from bid where 拍賣編號='" + bidnum + "';";
			SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
			sqlcnt.Open();
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			seller = dr["賣家編號"].ToString();
			sqlcnt.Close();
			
			Label2.Visible = false;
			TextBox1.Visible=false;
			Button1.Visible=false;

			if (Session["uname"]==null)
			{
				Label1.Text = "您非賣家，不能替賣家解答問題。";
			}
			else if (Session["uname"]!=null && Session["uname"].ToString() != seller)
			{
				Label1.Text = "您非賣家，不能替賣家回答問題。";
			}
			else
			{
				
				string cmd2 = "select Qnum,問題 from QandA where 答案 is null and 拍賣編號='"+bidnum + "'";
				SqlCommand sqlcmd2 = new SqlCommand(cmd2, sqlcnt);
				sqlcnt.Open();
				SqlDataReader dr2 = sqlcmd2.ExecuteReader();
				int i = 1;
				Label1.Text = "您需要回答的問題有: ";
				while (dr2.Read())
				{
					TableRow r = new TableRow();
					Table1.Rows.Add(r);
					TableCell c0 = new TableCell();
					c0.Text = "問題 " + i.ToString();
					r.Cells.Add(c0);
					TableCell c1 = new TableCell();
					c1.Text = "<a href=ans.aspx?qnum=" + dr2["Qnum"].ToString() + "&bid=" + bidnum + ">" + dr2["問題"].ToString() + "</a>";
					r.Cells.Add(c1);
					i++;
				}
				sqlcnt.Close();
				if(qnum!=null)
				{
					Label2.Visible = true;
					TextBox1.Visible=true;
					Button1.Visible= true;
					SqlCommand sqlcmd3 = new SqlCommand("select 問題 from QandA where Qnum ='"+qnum+"'",sqlcnt);
					sqlcnt.Open();
					SqlDataReader dr1 = sqlcmd3.ExecuteReader();
					dr1.Read();
					Label3.Text = dr1["問題"].ToString();
				}
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
			SqlConnection sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			SqlCommand sqlcmd = new SqlCommand("update QandA set 答案='" + TextBox1.Text +"' where Qnum='" + qnum +"';",sqlcnt);
			sqlcnt.Open();
			sqlcmd.ExecuteNonQuery();
			Label2.Visible = false;
			Label1.Text = "更新成功!";
			TextBox1.Visible = false;
			Button1.Visible = false;		
		}
	}
}
