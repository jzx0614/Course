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
	/// see_bid1 的摘要描述。
	/// </summary>
	public class see_bid : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.DataGrid MyDataGrid;
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.HtmlControls.HtmlInputText Text1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.Table Table1;
		protected string classnum;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// 在這裡放置使用者程式碼以初始化網頁
			myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			classnum=Request.QueryString["classnum"];
			if (!IsPostBack)
			{	
				string sqltmp="select * from product,bid where product.拍賣編號=bid.拍賣編號 ";
				if(classnum!=null)
					sqltmp+="and product.類別編號 ="+ classnum ;
				else
				{ 
					if(Request.QueryString["likeword"]!=null)
						sqltmp+="and product.商品標題 like '%"+Request.QueryString["likeword"]+"%'";
					if(Request.QueryString["low_money"]!=null)
						sqltmp+="and bid.目前出價 >= "+Request.QueryString["low_money"];
					if(Request.QueryString["high_money"]!=null)
						sqltmp+="and bid.目前出價 <= "+Request.QueryString["high_money"];
					if(Request.QueryString["l_n_money"]!=null)
						sqltmp+="and bid.直接購價 >= "+Request.QueryString["l_n_money"];
					if(Request.QueryString["h_n_money"]!=null)
						sqltmp+="and bid.直接購價 <= "+Request.QueryString["h_n_money"];
					if(Request.QueryString["place"]!=null)
						sqltmp+="and bid.所在地區 ='"+Request.QueryString["place"]+"'";
					if(Request.QueryString["sid"]!=null)
						sqltmp+=" and bid.賣家編號 = '"+Request.QueryString["sid"]+"'";
					string init="and (";
					if(Request.QueryString["sid1"]!=null)
					{
						sqltmp+=init+" bid.賣家編號 = '"+Request.QueryString["sid1"]+"'";
						init="or";
					}
					if(Request.QueryString["sid2"]!=null)
					{
						sqltmp+=init+" bid.賣家編號 = '"+Request.QueryString["sid2"]+"'";
						init="or";
					}
					if(Request.QueryString["sid3"]!=null)
					{
						sqltmp+=init+" bid.賣家編號 = '"+Request.QueryString["sid3"]+"'";
						init="or";
					}
					if(Request.QueryString["sid4"]!=null)
					{
						sqltmp+=init+" bid.賣家編號 = '"+Request.QueryString["sid4"]+"'";
						init="or";
					}
					if(Request.QueryString["sid5"]!=null)
					{
						sqltmp+=init+" bid.賣家編號 = '"+Request.QueryString["sid5"]+"'";
						init="or";
					}
					if(init=="or")
						sqltmp+=")";

				}
				BindGrid(sqltmp);

			}
			if(classnum!=null)
			{
				SqlCommand myCommand = new SqlCommand("select * from class where 父類別編號="+classnum, myConnection);
				myConnection.Open();
				SqlDataReader dr = myCommand.ExecuteReader();
				while (dr.Read()) 
				{
					int id=dr.GetInt32(0);
				
					string classname=dr.GetString(1);
					string temp="<P align=\"center\"><a href=\"see_bid.aspx?classnum="+id+"\">"+classname+"</a></p>";
					TableCell buf_td=new TableCell();
					buf_td.Text=temp;
					Table1.Rows[0].Cells.Add(buf_td);
				}
				myConnection.Close();
			}
			else
				DropDownList1.Visible=false;

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

		public void BindGrid(string sqlcmd)
		{

			SqlDataAdapter myCommand1 = new SqlDataAdapter(sqlcmd, myConnection);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "product");			
			MyDataGrid.DataSource=ds1.Tables["product"].DefaultView;			
			MyDataGrid.DataBind();
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			string sqlcmd="select * from product,bid where product.拍賣編號=bid.拍賣編號 ";		
			if(Text1.Value!="")
			{
				if(classnum!=null)
				{
					if(DropDownList1.SelectedIndex==0)
						sqlcmd+="and product.類別編號="+classnum;
				}
					sqlcmd +=" and product.商品標題 like '%"+Text1.Value+"%'";
			}
						
			BindGrid(sqlcmd);
		}
	}
}
