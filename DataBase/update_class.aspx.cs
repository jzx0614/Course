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
	/// WebForm1 ���K�n�y�z�C
	/// </summary>
	public class update_class : System.Web.UI.Page
	{
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.DataGrid MyDataGrid1;
		protected System.Web.UI.WebControls.DataGrid MyDataGrid;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			
			if(Session["group"]==null||(Session["group"].ToString()!="product"&&Session["group"].ToString()!="root"))
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
			this.MyDataGrid.CancelCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.MyDataGrid_CancelCommand);
			this.MyDataGrid.EditCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.MyDataGrid_EditCommand);
			this.MyDataGrid.UpdateCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.MyDataGrid_UpdateCommand);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		public void BindGrid()
		{
			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from class", myConnection);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "class");			
			MyDataGrid.DataSource=ds1.Tables["class"].DefaultView;			
			MyDataGrid.DataBind();
		}

		private void MyDataGrid_EditCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			MyDataGrid.EditItemIndex = (int)e.Item.ItemIndex;
			BindGrid();
		}

		private void MyDataGrid_CancelCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			MyDataGrid.EditItemIndex = -1;
			BindGrid();		
		}



		private void MyDataGrid_UpdateCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			string updateCmd = "UPDATE class SET ���O�s�� = @Id,  ���O�W�� = @name, �����O�s�� = @Pclass where  ���O�s�� = @Id";
			SqlCommand myCommand = new SqlCommand(updateCmd, myConnection);
			myCommand.Parameters.Add(new SqlParameter("@Id",SqlDbType.Int,4));
			myCommand.Parameters.Add(new SqlParameter("@name",SqlDbType.VarChar,50));
			myCommand.Parameters.Add(new SqlParameter("@Pclass",SqlDbType.Int,4));
			myCommand.Parameters["@Id"].Value = MyDataGrid.DataKeys[(int)e.Item.ItemIndex];

			string[] cols = {"@Id","@name","@Pclass"};

			int numCols = e.Item.Cells.Count;
	
			for (int i=2; i< numCols; i++) //skip first, second and last column
			{
				string colvalue = ((TextBox)e.Item.Cells[i].Controls[0]).Text;

				// check for null values in required fields
				if (colvalue == "") 
				{
					Label2.Text = "�����\ Null ��"+cols[i-1];
					Label2.Style["color"] = "red";
					return;
				}
				
				myCommand.Parameters[cols[i-1]].Value = colvalue;
			}



			myCommand.Connection.Open();

			try 
			{
				Label2.Text=updateCmd;
				myCommand.ExecuteNonQuery();
				Label2.Text = "<b>�w��s��ƿ�</b><br>" + updateCmd;
				MyDataGrid.EditItemIndex = -1;
			}
			catch (SqlException E)
			{
				if (E.Number == 2627)
					Label2.Text = "���~: �㦳�ۦP�D�����䪺��ƿ��w�g�s�b";
				else
					Label2.Text = "���~: �L�k��s��ƿ��A�нT�w�U���O�_���w���T��J";
				Label2.Style["color"] = "red";
			}

			myCommand.Connection.Close();

			BindGrid();
		

	
		}


	}
}
