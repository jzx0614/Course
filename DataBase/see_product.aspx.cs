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
	/// see_product 的摘要描述。
	/// </summary>
	public class see_product : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.HtmlControls.HtmlTable Table1;
		protected System.Web.UI.HtmlControls.HtmlTable Table2;
		protected System.Web.UI.HtmlControls.HtmlTable Table3;
		protected System.Web.UI.WebControls.Label 賣家;
		protected System.Web.UI.WebControls.Label 評價;
		protected System.Web.UI.WebControls.Label 付款方式;
		protected System.Web.UI.WebControls.Label 交貨方式;
		protected System.Web.UI.WebControls.Label 商品新舊;
		protected System.Web.UI.WebControls.Label 運送費用;
		protected System.Web.UI.WebControls.Label 拍賣編號;
		protected System.Web.UI.WebControls.Label 結束時間;
		protected System.Web.UI.WebControls.Label 開始時間;
		protected System.Web.UI.WebControls.Label 所在地區;
		protected System.Web.UI.WebControls.Label 起標價格;
		protected System.Web.UI.WebControls.Label 商品數量;
		protected System.Web.UI.WebControls.Label 最高出價者;
		protected System.Web.UI.WebControls.Label 直接購買價;
		protected System.Web.UI.WebControls.Label 目前出價;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.ImageButton ImageButton1;
		protected System.Web.UI.HtmlControls.HtmlTable Table5;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.TextBox TextBox3;
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
		protected System.Web.UI.HtmlControls.HtmlForm Form1;
		protected System.Data.SqlClient.SqlConnection sqlcnt;
		protected System.Web.UI.WebControls.DataGrid Datagrid1;
		protected System.Web.UI.WebControls.TextBox Textbox4;
		protected System.Web.UI.WebControls.TextBox Textbox5;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Button Button4;
		protected System.Web.UI.WebControls.Button Button3;
		protected System.Web.UI.WebControls.TextBox Textbox6;
		protected System.Web.UI.WebControls.TextBox Textbox1;
		protected System.Web.UI.HtmlControls.HtmlTable Table7;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.HyperLink Hyperlink4;
		protected System.Web.UI.WebControls.HyperLink Hyperlink5;
		protected System.Web.UI.WebControls.DataGrid MyDataGrid;
		protected System.Web.UI.WebControls.Table Table4;
		protected System.Web.UI.WebControls.ImageButton ImageButton2;
		protected System.Web.UI.WebControls.HyperLink Hyperlink2;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		string tab;
		string bidnum;
		DateTime over_time;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			
			Hyperlink5.Visible = false;
			if (Session["uname"]==null)
			{
				Table5.Visible = true;
				Table3.Visible= false;
			}
			else 
			{
				Table5.Visible = false;
				Table3.Visible= true;
			}
			bidnum=Request.QueryString["bid"];
			tab=Request.QueryString["tab"];
			if(tab==null)
				tab="0";
			
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				string cmd = "select * from product, bid where product.拍賣編號=bid.拍賣編號 and product.拍賣編號='" + bidnum + "'";
				SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
				sqlcnt.Open();
				SqlDataReader dr = sqlcmd.ExecuteReader();
				
				if(dr.HasRows)
				{
					dr.Read();
					ImageButton1.ImageUrl = "image/" + dr["商品圖片"].ToString();
					Label1.Text = dr["商品標題"].ToString();
					商品數量.Text = dr["商品數量"].ToString();
					賣家.Text = dr["賣家編號"].ToString();
					評價.Text = dr["評價"].ToString() + " %";
					付款方式.Text = dr["付款方式"].ToString();
					交貨方式.Text = dr["交貨方式"].ToString();
					if (dr["商品新舊"].ToString() == "1")
						商品新舊.Text = "全新";
					else
						商品新舊.Text = "舊商品";
					目前出價.Text = dr["目前出價"].ToString();
					直接購買價.Text = dr["直接購價"].ToString();
					最高出價者.Text = dr["最高出價者"].ToString();
					起標價格.Text = dr["起標價"].ToString();
					所在地區.Text = dr["所在地區"].ToString();
					開始時間.Text = dr["開始時間"].ToString();
					結束時間.Text = dr["結束時間"].ToString();
					
					over_time=dr.GetDateTime(13);
					拍賣編號.Text = Request.QueryString["bid"].ToString();
					運送費用.Text = dr["運費"].ToString();
					Label3.Text=目前出價.Text;
					Label4.Text=直接購買價.Text;
					dr.Close();
					sqlcnt.Close();	
				}
				else
					Response.Redirect("index.aspx");
				if(tab=="0")
					BindGrid1();
				else if (tab == "1")
					BindGrid();
				else
					show_image();

			}
			if(DateTime.Compare(DateTime.Now,over_time)==1 || 目前出價.Text==直接購買價.Text)
			{
				Button1.Enabled=false;
				Button4.Enabled=false;
				Button1.Text="已截止";
				Button4.Text="已截止";
			}

			if (Session["uname"]!=null && Session["uname"].ToString() == 賣家.Text)
			{
				Hyperlink5.Visible = true;
				bidnum = Request.QueryString["bid"].ToString();	
				Hyperlink5.NavigateUrl = "ans.aspx?bid=" + bidnum;
			}

			if(tab=="1")
			{
				Hyperlink4.NavigateUrl="see_product.aspx?tab=0&bid=" + bidnum;
				Hyperlink2.NavigateUrl="see_product.aspx?tab=2&bid=" + bidnum;
				MyDataGrid.Visible=true;
				Datagrid1.Visible=false;
				ImageButton2.Visible = false;
				Label5.Visible = false;
				Button3.Visible=true;
			}
			else if(tab=="0")
			{
				HyperLink1.NavigateUrl="see_product.aspx?tab=1&bid=" + bidnum;
				Hyperlink2.NavigateUrl="see_product.aspx?tab=2&bid=" + bidnum;
				MyDataGrid.Visible=false;
				TextBox1.Visible=false;
				Button3.Visible=false;
				Datagrid1.Visible=true;
				ImageButton2.Visible = false;
				Label5.Visible = false;
			}
			else 
			{
				HyperLink1.NavigateUrl="see_product.aspx?tab=1&bid=" + bidnum;
				Hyperlink4.NavigateUrl="see_product.aspx?tab=0&bid=" + bidnum;
				MyDataGrid.Visible=false;
				TextBox1.Visible=false;
				Button3.Visible=false;
				Datagrid1.Visible=false;
				ImageButton2.Visible = true;
				Label5.Visible = true;
				Hyperlink4.NavigateUrl="see_product.aspx?tab=0&bid=" + bidnum;
				HyperLink1.NavigateUrl="see_product.aspx?tab=1&bid=" + bidnum;
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
			this.sqlcnt = new System.Data.SqlClient.SqlConnection();
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Button4.Click += new System.EventHandler(this.Button4_Click);
			this.Button3.Click += new System.EventHandler(this.Button3_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion


		private void Button2_Click(object sender, System.EventArgs e)
		{
			string cmd = "select * from member where 帳號='" + TextBox2.Text + "';";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			if (dr["密碼"].ToString() == TextBox3.Text)
			{
				Session["暱稱"]=dr["暱稱"].ToString();
				Session["uname"] = TextBox2.Text;
				Response.Redirect("see_product.aspx?bid=" + bidnum);
			}
			sqlcnt.Close();
		}

		private void Button3_Click(object sender, System.EventArgs e)
		{
			if (Session["uname"]!=null)
			{
				string date=DateTime.Now.ToShortDateString()+" "+DateTime.Now.Hour.ToString()+":"+DateTime.Now.Minute.ToString();
				string cmd = "insert QandA (拍賣編號, 帳號, 問題, 日期)values ('" + bidnum + "','" + Session["uname"].ToString() + "','" + 
					TextBox1.Text + "','" + date + "');";	
				SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
				sqlcmd.Connection.Open();
				try 
				{
					sqlcmd.ExecuteNonQuery();
				}
				catch (SqlException E)
				{
					if (E.Number == 2627)
						TextBox1.Text = "錯誤: 具有相同主索引鍵的資料錄已經存在";
					else
						TextBox1.Text = "錯誤: 無法更新資料錄，請確定各欄位是否都已正確填入";
					Label2.Style["color"] = "red";
				}
				
				sqlcmd.Connection.Close();
				BindGrid();

			}
		}
		public void BindGrid()
		{

			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from QandA where 拍賣編號="+bidnum, sqlcnt);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "product");			
			MyDataGrid.DataSource=ds1.Tables["product"].DefaultView;			
			MyDataGrid.DataBind();
		}
		public void BindGrid1()
		{

			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from buy where 拍賣編號="+bidnum+" ORDER BY 出價 DESC", sqlcnt);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "product");			
			Datagrid1.DataSource=ds1.Tables["product"].DefaultView;			
			Datagrid1.DataBind();
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			Response.Redirect("buy.aspx?money="+Textbox4.Text+"&qty="+Textbox5.Text+"&bid="+bidnum);
		}

		private void Button4_Click(object sender, System.EventArgs e)
		{
			Response.Redirect("buy.aspx?money="+Label4.Text+"&qty="+Textbox6.Text+"&bid="+bidnum);		
		}

		private void show_image()
		{
			SqlCommand cmd = new SqlCommand("select 商品敘述, 商品圖片 from product where 拍賣編號='" + bidnum + "'",sqlcnt);
			sqlcnt.Open();
			SqlDataReader dr = cmd.ExecuteReader();
			dr.Read();
			ImageButton2.ImageUrl = "image/" + dr["商品圖片"].ToString();
			Label5.Text =  dr["商品敘述"].ToString();
			sqlcnt.Close();
		}
	}
}
