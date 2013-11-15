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
using System.IO;

namespace C09102014
{
	/// <summary>
	/// addbid 的摘要描述。
	/// </summary>
	public class addbid : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Button btnUpload;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.Label Label12;
		protected System.Web.UI.WebControls.Label Label13;
		protected System.Web.UI.WebControls.Label Label14;
		protected System.Web.UI.WebControls.Label Label15;
		protected System.Web.UI.WebControls.Label Label16;
		protected System.Web.UI.WebControls.Label Label17;
		protected System.Web.UI.WebControls.Label Label18;
		protected System.Web.UI.WebControls.Label Label19;
		protected System.Web.UI.WebControls.TextBox 商品標題;
		protected System.Web.UI.WebControls.TextBox 商品名稱;
		protected System.Web.UI.WebControls.TextBox 所在地區;
		protected System.Web.UI.WebControls.TextBox 運費;
		protected System.Web.UI.WebControls.DropDownList 付款方式;
		protected System.Web.UI.WebControls.DropDownList 交貨方式;
		protected System.Web.UI.WebControls.DropDownList 商品新舊;
		protected System.Web.UI.WebControls.TextBox 直接購買價;
		protected System.Web.UI.WebControls.TextBox 起標價;
		protected System.Web.UI.WebControls.TextBox 交易守則;
		protected System.Web.UI.WebControls.TextBox 商品數量;
		protected System.Web.UI.WebControls.Label error;
		protected System.Web.UI.HtmlControls.HtmlInputFile File1;
		protected System.Web.UI.WebControls.TextBox y1;
		protected System.Web.UI.WebControls.TextBox m1;
		protected System.Web.UI.WebControls.TextBox TextBox4;
		protected System.Web.UI.WebControls.Label Label20;
		protected System.Web.UI.WebControls.Label Label21;
		protected System.Web.UI.WebControls.Label Label22;
		protected System.Web.UI.WebControls.Label Label23;
		protected System.Web.UI.WebControls.Label Label24;
		protected System.Web.UI.WebControls.Label Label25;
		protected System.Web.UI.WebControls.TextBox d1;
		protected System.Web.UI.WebControls.TextBox TextBox6;
		protected System.Web.UI.WebControls.TextBox y2;
		protected System.Web.UI.WebControls.Label Label26;
		protected System.Web.UI.WebControls.TextBox m2;
		protected System.Web.UI.WebControls.Label Label27;
		protected System.Web.UI.WebControls.TextBox d2;
		protected System.Web.UI.WebControls.Label Label28;
		protected System.Web.UI.WebControls.TextBox 商品敘述;
		protected System.Web.UI.WebControls.Label error1;
		protected System.Web.UI.WebControls.ListBox ListBox1;
		protected System.Web.UI.WebControls.ListBox ListBox2;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Button Button2;
		SqlConnection sqlcnt;
		protected System.Web.UI.WebControls.ListBox ListBox3;
		protected System.Web.UI.WebControls.Button Button3;
		protected System.Web.UI.WebControls.Label Label29;
		protected System.Web.UI.WebControls.Label Label30;
		protected System.Web.UI.WebControls.Label Label31;
		protected System.Web.UI.WebControls.Label Label32;
		protected System.Web.UI.WebControls.Label Label33;
		string classnum;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			if (Session["uname"]==null)
			{
				error1.Text = "請先登入";
				btnUpload.Visible = false;
				ListBox2.Visible = false;
				Button2.Visible = false;
				ListBox3.Visible = false;
				Button3.Visible = false;
				Label30.Visible = false;
				Label31.Visible = false;
				return;
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				sqlcnt.Open();
				SqlCommand sqlcmd = new SqlCommand("select 類別名稱 from class where 父類別編號='0'",sqlcnt);
				SqlDataReader dr = sqlcmd.ExecuteReader();
				while (dr.Read())
				{
					ListBox1.Items.Add(dr["類別名稱"].ToString());
				}
				sqlcnt.Close();
				ListBox2.Visible = false;
				Button2.Visible = false;
				ListBox3.Visible = false;
				Button3.Visible = false;
				Label30.Visible = false;
				Label31.Visible = false;
				ListBox2.Items.Clear();
				ListBox3.Items.Clear();
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
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.btnUpload.Click += new System.EventHandler(this.btnUpload_Click);
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Button3.Click += new System.EventHandler(this.Button3_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void btnUpload_Click(object sender, System.EventArgs e)
		{
			if (商品名稱.Text==null || 商品標題.Text==null || 所在地區.Text==null || 運費.Text==null || 直接購買價.Text==null ||
				起標價.Text==null || 商品數量.Text==null || File1.PostedFile.FileName==null)
			{
				error.Text = "有欄位沒有填寫確實!!";
			}
			else
			{
				sqlcnt.Open();
				string strFileName = File1.PostedFile.FileName;
				strFileName = System.IO.Path.GetFileName(strFileName);
				File1.PostedFile.SaveAs(Server.MapPath("image/") + strFileName);
				string cmd1 = "insert bid (商品新舊,起標價,直接購價,開始時間,結束時間,賣家編號,評價,運費,付款方式,所在地區,交貨方式,商品黑名單, 交易守則)" 
					+ "values ('" + 
					int.Parse(商品新舊.SelectedValue.ToString()) + "', '" +
					int.Parse(起標價.Text) + "', '" +
					int.Parse(直接購買價.Text) + "', '" +
					y1.Text+"/"+m1.Text+"/"+d1.Text + "', '" +
					y2.Text+"/"+m2.Text+"/"+d2.Text + "', '" +
					Session["uname"].ToString() + "', '100', '" +
					int.Parse(運費.Text) + "', '" +
					付款方式.SelectedValue.ToString() + "', '" +
					所在地區.Text + "', '" +
					交貨方式.SelectedValue.ToString() + "', '0', '" +
					交易守則.Text 
					+"')";
				SqlCommand sqlcmd = new SqlCommand(cmd1,sqlcnt);
				sqlcmd.ExecuteNonQuery();
				string cmd2 = "insert product (商品名稱, 商品標題, 商品數量, 商品圖片, 類別編號, 商品敘述)values ('" + 商品名稱.Text + "', '" + 商品標題.Text + "', '" + 商品數量.Text + "', '" + 
					strFileName + "', '" + error.Text + "', '" + 商品敘述.Text + "')";  
				sqlcmd = new SqlCommand(cmd2, sqlcnt);
				sqlcmd.ExecuteNonQuery();
				sqlcnt.Close();
				error.Text = "";
				Response.Redirect("index.aspx");
			}
		}


		private void Button1_Click(object sender, System.EventArgs e)
		{
			string b = ListBox1.SelectedValue.ToString();
			string getclass = "select 類別編號 from class where 類別名稱='" + b + "'";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(getclass, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			classnum = dr["類別編號"].ToString();
			dr.Close();
			string cmd = "select A.類別名稱 from class A, class B where A.父類別編號=B.類別編號 AND B.類別名稱='" + b + "'";
			sqlcmd = new SqlCommand(cmd, sqlcnt);
			dr = sqlcmd.ExecuteReader();
			ListBox2.Items.Clear();
			ListBox3.Items.Clear();
			ListBox2.Visible = false;
			ListBox3.Visible = false;
			Label30.Visible = false;
			Label31.Visible = false;
			Button2.Visible = false;
			Button3.Visible = false;
			while(dr.Read())
			{
				ListBox2.Items.Add(dr["類別名稱"].ToString());
				ListBox2.Visible = true;
				Button2.Visible = true;
				Label30.Visible = true;
			}
			error.Text = classnum;
			error.Visible = false;
		}

		private void Button2_Click(object sender, System.EventArgs e)
		{
			string b = ListBox2.SelectedValue.ToString();
			string getclass = "select 類別編號 from class where 類別名稱='" + b + "'";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(getclass, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			classnum = dr["類別編號"].ToString();
			dr.Close();
			string cmd = "select A.類別名稱 from class A, class B where A.父類別編號=B.類別編號 AND B.類別名稱='" + b + "'";
			sqlcmd = new SqlCommand(cmd, sqlcnt);
			dr = sqlcmd.ExecuteReader();
			ListBox3.Items.Clear();
			ListBox3.Visible = false;
			Label31.Visible = false;
			Button3.Visible = false;
			while(dr.Read())
			{
				ListBox3.Items.Add(dr["類別名稱"].ToString());
				ListBox3.Visible = true;
				Button3.Visible = true;
				Label31.Visible = true;
			}
			error.Text = classnum;
			error.Visible = false;
		}

		private void Button3_Click(object sender, System.EventArgs e)
		{
			string b = ListBox3.SelectedValue.ToString();
			string getclass = "select 類別編號 from class where 類別名稱='" + b + "'";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(getclass, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			classnum = dr["類別編號"].ToString();
			dr.Close();
			error.Text = classnum;
			error.Visible = false;
		}

	}
}
