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
	/// select_qanda ���K�n�y�z�C
	/// </summary>
	public class select_qanda : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		protected System.Web.UI.WebControls.Label Label1;
		SqlConnection sqlcnt;
		protected System.Web.UI.WebControls.Label Label2;
		string cmd;
		bool run = true;
		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				Label1.Text = "�Ш̷өʽ�d��!!";
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
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button1_Click(object sender, System.EventArgs e)
		{
			if (DropDownList1.SelectedValue.ToString() != "all")
			{
				if (TextBox1.Text=="")
				{
					Label1.Text = "�d�߱��󤣨�!";
					run = false;
				}
				else if (DropDownList1.SelectedValue.ToString() != "���D")
					cmd += "select * from QandA where " + DropDownList1.SelectedValue.ToString() + "= '" + TextBox1.Text + "';";
				else cmd += "select * from QandA where " + DropDownList1.SelectedValue.ToString() + " like '%" + TextBox1.Text + "%';";
			}
			else cmd = "select * from QandA;";
			if (run)
			{
				SqlDataAdapter da = new SqlDataAdapter(cmd,sqlcnt);
				try 
				{
					DataSet ds = new DataSet();
					da.Fill(ds,"QandA");
					DataGrid1.DataSource = ds.Tables["QandA"].DefaultView;
					DataGrid1.DataBind();
				}
				catch (SqlException)
				{
				}
				Label1.Text = cmd;
			}
			TextBox1.Text = "";
			cmd = "";
			run = true;
		}
	}
}
