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
	/// buy 的摘要描述。
	/// </summary>
	public class buy : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.Label Label12;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.Button Button3;
		protected System.Web.UI.WebControls.Image Image1;
		protected string money;
		protected string qty;
		protected string bidnum;
		protected int high_money;
		protected int low_money;
		protected string passwd;
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;

	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			money=Request.QueryString["money"];
			qty=Request.QueryString["qty"];
			bidnum=Request.QueryString["bid"];
			if (Session["uname"]==null)
			{
				Label1.Text = "歡迎光臨!";
				HyperLink1.Text="登入";
				HyperLink1.NavigateUrl="user_login.aspx";
				
			}
			else 
			{
				Label1.Text = "歡迎光臨! "+Session["暱稱"].ToString()+" ("+Session["uname"].ToString()+")";
				HyperLink1.Text="登出";
				HyperLink1.NavigateUrl="user_logout.aspx";
				Label3.Text=Session["uname"].ToString();
			}
			if(bidnum!=null)
			{
				Label11.Text=bidnum;
				Label9.Text=money;
				Label8.Text=qty;
				HyperLink2.NavigateUrl="see_product.aspx?bid="+bidnum;
				myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
				string cmd = "select * from product, bid where product.拍賣編號=bid.拍賣編號 and product.拍賣編號='" + bidnum + "'";
				SqlCommand sqlcmd = new SqlCommand(cmd, myConnection);
				myConnection.Open();
				SqlDataReader dr = sqlcmd.ExecuteReader();
				if(dr.HasRows)
				{
					dr.Read();
					Label12.Text=dr["商品名稱"].ToString();
					Label10.Text=dr["目前出價"].ToString();
					high_money=int.Parse(dr["直接購價"].ToString());
					low_money=int.Parse(dr["起標價"].ToString());
					if(int.Parse(Label8.Text)>int.Parse(dr["商品數量"].ToString()))
					{
						Label8.Text=dr["商品數量"].ToString();
						qty=dr["商品數量"].ToString();
					}
				}
				myConnection.Close();
				if(int.Parse(Label9.Text)>=low_money && int.Parse(Label9.Text)>int.Parse(Label10.Text))
				{
					if(int.Parse(Label9.Text)>high_money)
					{
						Label9.Text=high_money.ToString();
					}
					
				}
				else
				{
					Label5.Text="您的出價不符合條件";
					Button2.Enabled=false;
				}
			}
			else
				Response.Redirect("index.aspx");
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
			this.Button3.Click += new System.EventHandler(this.Button3_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button2_Click(object sender, System.EventArgs e)
		{
			string cmd="select 密碼 from member where 帳號='"+Label3.Text+"'";

			SqlCommand sqlcmd =new SqlCommand(cmd,myConnection);
			myConnection.Open();
			SqlDataReader dr=sqlcmd.ExecuteReader();
			if(dr.HasRows)
			{
				dr.Read();
				passwd=dr["密碼"].ToString();
			}
			myConnection.Close();
			if(passwd==TextBox1.Text)
			{
				Order();
			}
			else
			{
				Label5.Text="密碼錯誤";
			}
		}
		private void Order()
		{
			
				string date=DateTime.Now.ToShortDateString()+" "+DateTime.Now.Hour.ToString()+":"+DateTime.Now.Minute.ToString();
				string cmd1 = "INSERT INTO buy values('"+ Label3.Text +"','"+ qty +"',"+Label9.Text+",'"+ date +"','"+ bidnum +"')";	
				SqlCommand myCommand1 = new SqlCommand(cmd1,myConnection);
				myCommand1.Connection.Open();
				try
				{
					myCommand1.ExecuteNonQuery();
				}
				catch
				{
					Label5.Text=" <b>出價失敗1</b>"+cmd1;
				}
				myCommand1.Connection.Close();
				string cmd = "UPDATE bid SET 最高出價者='"+Label3.Text+"', 目前出價="+Label9.Text+" where 拍賣編號="+bidnum;	
				SqlCommand myCommand = new SqlCommand(cmd,myConnection);
				myCommand.Connection.Open();
				try 
				{
					myCommand.ExecuteNonQuery();
					Label5.Text = "<b>已出價" +Label9.Text+" 於此拍賣中</b><br>";
				}
				catch
				{
					Label5.Text=" <b>出價失敗2</b>";
				}
				myCommand.Connection.Close();
		}

		private void Button3_Click(object sender, System.EventArgs e)
		{
			TextBox1.Text="";
		}
	}
}
