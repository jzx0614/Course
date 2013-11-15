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
	/// see_bid1 ���K�n�y�z�C
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
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			classnum=Request.QueryString["classnum"];
			if (!IsPostBack)
			{	
				string sqltmp="select * from product,bid where product.���s��=bid.���s�� ";
				if(classnum!=null)
					sqltmp+="and product.���O�s�� ="+ classnum ;
				else
				{ 
					if(Request.QueryString["likeword"]!=null)
						sqltmp+="and product.�ӫ~���D like '%"+Request.QueryString["likeword"]+"%'";
					if(Request.QueryString["low_money"]!=null)
						sqltmp+="and bid.�ثe�X�� >= "+Request.QueryString["low_money"];
					if(Request.QueryString["high_money"]!=null)
						sqltmp+="and bid.�ثe�X�� <= "+Request.QueryString["high_money"];
					if(Request.QueryString["l_n_money"]!=null)
						sqltmp+="and bid.�����ʻ� >= "+Request.QueryString["l_n_money"];
					if(Request.QueryString["h_n_money"]!=null)
						sqltmp+="and bid.�����ʻ� <= "+Request.QueryString["h_n_money"];
					if(Request.QueryString["place"]!=null)
						sqltmp+="and bid.�Ҧb�a�� ='"+Request.QueryString["place"]+"'";
					if(Request.QueryString["sid"]!=null)
						sqltmp+=" and bid.��a�s�� = '"+Request.QueryString["sid"]+"'";
					string init="and (";
					if(Request.QueryString["sid1"]!=null)
					{
						sqltmp+=init+" bid.��a�s�� = '"+Request.QueryString["sid1"]+"'";
						init="or";
					}
					if(Request.QueryString["sid2"]!=null)
					{
						sqltmp+=init+" bid.��a�s�� = '"+Request.QueryString["sid2"]+"'";
						init="or";
					}
					if(Request.QueryString["sid3"]!=null)
					{
						sqltmp+=init+" bid.��a�s�� = '"+Request.QueryString["sid3"]+"'";
						init="or";
					}
					if(Request.QueryString["sid4"]!=null)
					{
						sqltmp+=init+" bid.��a�s�� = '"+Request.QueryString["sid4"]+"'";
						init="or";
					}
					if(Request.QueryString["sid5"]!=null)
					{
						sqltmp+=init+" bid.��a�s�� = '"+Request.QueryString["sid5"]+"'";
						init="or";
					}
					if(init=="or")
						sqltmp+=")";

				}
				BindGrid(sqltmp);

			}
			if(classnum!=null)
			{
				SqlCommand myCommand = new SqlCommand("select * from class where �����O�s��="+classnum, myConnection);
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

		#region Web Form �]�p�u�㲣�ͪ��{���X
		override protected void OnInit(EventArgs e)
		{
			//
			// CODEGEN: ���� ASP.NET Web Form �]�p�u��һݪ��I�s�C
			//
			InitializeComponent();
			base.OnInit(e);
		}
		
		/// <summary>
		/// �����]�p�u��䴩�ҥ�������k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
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
			string sqlcmd="select * from product,bid where product.���s��=bid.���s�� ";		
			if(Text1.Value!="")
			{
				if(classnum!=null)
				{
					if(DropDownList1.SelectedIndex==0)
						sqlcmd+="and product.���O�s��="+classnum;
				}
					sqlcmd +=" and product.�ӫ~���D like '%"+Text1.Value+"%'";
			}
						
			BindGrid(sqlcmd);
		}
	}
}
