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
	/// select_bid ���K�n�y�z�C
	/// </summary>
	public class select_bid : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.TextBox Textpnum;
		protected System.Web.UI.WebControls.TextBox Textzone;
		protected System.Web.UI.WebControls.TextBox Textsnum;
		protected System.Web.UI.WebControls.Label newold;
		protected System.Web.UI.WebControls.Label black;
		protected System.Web.UI.WebControls.Label snum;
		protected System.Web.UI.WebControls.Label zone;
		protected System.Web.UI.WebControls.DropDownList Dropnewold;
		protected System.Web.UI.WebControls.DropDownList Dropblack;
		protected System.Web.UI.WebControls.Label pay;
		protected System.Web.UI.WebControls.TextBox Textpay;
		protected System.Web.UI.WebControls.Label pnum;
		SqlConnection sqlcnt;
		bool first = true;
		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack) 
			{
				Label1.Text = "�p�G����ťմN�N�����줣�b�d�ߪ�����d��!!";
			}
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
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
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button2_Click(object sender, System.EventArgs e)
		{
			string sqlcmd = "select * from bid";
			draw(sqlcmd);
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			Label1.Text = "";
			first = true;
			string sqlcmd = "select * from bid ";
			if (Textpnum.Text != "")
			{
				if (first)
				{
					sqlcmd += "where " + pnum.Text + " = '" + Textpnum.Text +"' ";
					first = false;
				}
				else if (!first)
				{
					sqlcmd += " and " + pnum.Text + " = '" + Textpnum.Text +"' ";
				}
			}
			if (Textsnum.Text != "")
			{
				if (first)
				{
					sqlcmd += "where " + snum.Text + " = '" + Textsnum.Text +"' ";
					first = false;
				}
				else if (!first)
				{
					sqlcmd += " AND " + snum.Text + " = '" + Textsnum.Text +"' ";
				}
			}
			if (Textzone.Text != "")
			{
				if (first)
				{
					sqlcmd += "where " + zone.Text + " like '%" + Textzone.Text +"%' ";
					first = false;
				}
				else if (!first)
				{
					sqlcmd += " and " + zone.Text + " like '%" + Textzone.Text +"%' ";
				}
			}
			if (Textpay.Text != "")
			{
				if (first)
				{
					sqlcmd += "where " + pay.Text + " like '%" + Textpay.Text +"%' ";
					first = false;
				}
				else if (!first)
				{
					sqlcmd += " and " + pay.Text + " like '%" + Textpay.Text +"%' ";
				}
			}
			if (Dropblack.SelectedValue.ToString() != "-1")
			{
				if (first)
				{
					sqlcmd += "where " + black.Text + " = '" + Dropblack.SelectedValue.ToString() +"' ";
					first = false;
				}
				else if (!first)
				{
					sqlcmd += " and " + black.Text + " = '" + Dropblack.SelectedValue.ToString() +"' ";
				}
			}
			if (Dropnewold.SelectedValue.ToString() != "-1")
			{
				if (first)
				{
					sqlcmd += "where " + newold.Text + " = '" + Dropnewold.SelectedValue.ToString() +"' ";
					first = false;
				}
				else if (!first)
				{
					sqlcmd += " and " + newold.Text + " = '" + Dropnewold.SelectedValue.ToString() +"' ";
				}
			}
			Label1.Text = "SQL COMMAND: <br><br>    " + sqlcmd;
			draw(sqlcmd);
			Textpnum.Text = Textsnum.Text = Textzone.Text = Textpay.Text = "";
		}
		public void draw(string abc)
		{
			SqlDataAdapter da = new SqlDataAdapter(abc,sqlcnt);
			DataSet ds = new DataSet();
			da.Fill(ds,"bid");
			DataGrid1.DataSource = ds.Tables["bid"].DefaultView;
			DataGrid1.DataBind();
		}
	}
}
