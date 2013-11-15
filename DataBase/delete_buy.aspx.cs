using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Web;
using System.Web.SessionState;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;

namespace C09102014
{
	/// <summary>
	/// delete_product ���K�n�y�z�C
	/// </summary>
	public class delete_buy : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.WebControls.DataGrid MyDataGrid;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			
			myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");

			if (!IsPostBack)
				BindGrid();
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
			this.MyDataGrid.DeleteCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.MyDataGrid_DeleteCommand);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void MyDataGrid_DeleteCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			String deleteCmd = "DELETE from buy where ���s�� = @Id and �R��b�� = @bid";

			SqlCommand myCommand = new SqlCommand(deleteCmd, myConnection);
			myCommand.Parameters.Add(new SqlParameter("@bid", SqlDbType.VarChar,50));
			myCommand.Parameters.Add(new SqlParameter("@Id",SqlDbType.Int,4));

			myCommand.Parameters["@bid"].Value = MyDataGrid.DataKeys[e.Item.ItemIndex];				
			myCommand.Parameters["@Id"].Value=e.Item.Cells[5].Text;
		
			myCommand.Connection.Open();

			try
			{
				myCommand.ExecuteNonQuery();
				Label2.Text = "<b>�w�R����ƿ�</b><br>" + deleteCmd;
			}
			catch (SqlException)
			{
				Label2.Text = "���~: �L�k�R����ƿ�";
				Label2.Style["color"] = "red";
			}

			myCommand.Connection.Close();

			BindGrid();		
		}
		public void BindGrid()
		{
			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from buy ", myConnection);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "product");			
			MyDataGrid.DataSource=ds1.Tables["product"].DefaultView;			
			MyDataGrid.DataBind();
		}
	}
}
