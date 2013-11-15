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
	/// update_member ���K�n�y�z�C
	/// </summary>
	public class update_member : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		protected System.Web.UI.WebControls.Label Label2;
		SqlConnection sqlcnt;
		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="member"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				reflesh();
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
			this.DataGrid1.CancelCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_CancelCommand);
			this.DataGrid1.EditCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_EditCommand);
			this.DataGrid1.UpdateCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_UpdateComand);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion


		private void DataGrid1_EditCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			DataGrid1.EditItemIndex = (int)e.Item.ItemIndex;
			reflesh();
		}

		private void DataGrid1_CancelCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			DataGrid1.EditItemIndex = -1;
			reflesh();
		}

		public void reflesh()
		{
			SqlDataAdapter myCommand = new SqlDataAdapter("select * from member;", sqlcnt);

			DataSet ds = new DataSet();
			myCommand.Fill(ds, "member");
			DataGrid1.DataSource=ds.Tables["member"].DefaultView;
			DataGrid1.DataBind();
		}

		private void DataGrid1_UpdateComand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			string updateCmd = "UPDATE member SET �b�� = @Id, �K�X = @Pwd, �m�� = @Name1, �W�r = @Name2, "+ 
				" �ʺ� = @Nick, �m�O = @Sex , �褸 = @Year, �� = @Month, �� = @Day, �����Ҧr�� = @Idnum, "
				+ "�p���H�c = @Mail, �q�T�a�} = @Addr, �q�T�q�� = @Tel, ��ʹq�� = @Mtel where �b�� = @Id";
			SqlCommand myCommand = new SqlCommand(updateCmd, sqlcnt);
			myCommand.Parameters.Add(new SqlParameter("@Id", SqlDbType.VarChar, 20));
			myCommand.Parameters.Add(new SqlParameter("@Pwd", SqlDbType.VarChar, 20));
			myCommand.Parameters.Add(new SqlParameter("@Name1", SqlDbType.VarChar, 10));
			myCommand.Parameters.Add(new SqlParameter("@Name2", SqlDbType.VarChar, 10));
			myCommand.Parameters.Add(new SqlParameter("@Nick", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Sex", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Year", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@Month", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@Day", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@Idnum", SqlDbType.VarChar, 10));
			myCommand.Parameters.Add(new SqlParameter("@Mail", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Addr", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@Tel", SqlDbType.VarChar, 20));
			myCommand.Parameters.Add(new SqlParameter("@Mtel", SqlDbType.VarChar, 20));
			myCommand.Parameters["@Id"].Value = DataGrid1.DataKeys[(int)e.Item.ItemIndex];
			string[] cols = {"@Id","@Pwd","@Name1","@Name2","@Nick","@Sex","@Year","@Month","@Day","@Idnum","@Mail","@Addr","@Tel","@Mtel"};
			int numcols = e.Item.Cells.Count;
			for (int i=2; i< numcols; i++) //skip first, second and last column
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
				DataGrid1.EditItemIndex = -1;
			}
			catch (SqlException E)
			{
				if (E.Number == 2627)
					Label2.Text = "���~: �㦳�ۦP�D�����䪺��ƿ��w�g�s�b";
				else
					Label2.Text = "���~: �L�k��s��ƿ��A�нT�w�U���O�_���w���T��J"+updateCmd;
				Label2.Style["color"] = "red";
			}

			myCommand.Connection.Close();

			reflesh();
		}
	}
}
