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
	/// delete_bid ���K�n�y�z�C
	/// </summary>
	public class delete_bid : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		SqlConnection sqlcnt;

		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
				BindGrid();
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
		}
		private void DataGrid1_DeleteCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			String deleteCmd = "DELETE from bid where ���s�� = @pnum";

			SqlCommand myCommand = new SqlCommand(deleteCmd, sqlcnt);
			myCommand.Parameters.Add(new SqlParameter("@pnum", SqlDbType.Int, 4));

			myCommand.Parameters["@pnum"].Value = DataGrid1.DataKeys[(int)e.Item.ItemIndex];

			myCommand.Connection.Open();

			try
			{
				myCommand.ExecuteNonQuery();
				Label1.Text = "<b>�w�R����ƿ�</b><br>" + deleteCmd;
			}
			catch (SqlException)
			{
				Label1.Text = "���~: �L�k�R����ƿ�";
				Label1.Style["color"] = "red";
			}

			myCommand.Connection.Close();

			BindGrid();		
		}
		public void BindGrid()
		{
			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from bid", sqlcnt);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "member");			
			DataGrid1.DataSource=ds1.Tables["member"].DefaultView;			
			DataGrid1.DataBind();
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
			this.DataGrid1.DeleteCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_DeleteCommand);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion
	}
}