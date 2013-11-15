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
	/// update_bid ���K�n�y�z�C
	/// </summary>
	public class update_bid : System.Web.UI.Page
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
			SqlDataAdapter myCommand = new SqlDataAdapter("select * from bid;", sqlcnt);

			DataSet ds = new DataSet();
			myCommand.Fill(ds, "bid");
			DataGrid1.DataSource=ds.Tables["bid"].DefaultView;
			DataGrid1.DataBind();
		}

		private void DataGrid1_UpdateComand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			string updateCmd = "UPDATE bid SET  �ӫ~�s�� = @newold, �_�л� = @leastprice, �����ʻ� = @directprice, ";
			updateCmd+=" �ثe�X�� = @currentprice,�}�l�ɶ� = @starttime , �����ɶ� = @endtime, �̰��X���� = @highestid, ��a�s�� = @seller, ���� = @comment, ";
			updateCmd+=" �B�O = @bidcost, �I�ڤ覡 = @paytype, �Ҧb�a�� = @zone, ��f�覡 = @givenway, �ӫ~�¦W�� = @blacklist, ����u�h = @rules  where ���s�� = @sellid";
			SqlCommand myCommand = new SqlCommand(updateCmd, sqlcnt);
			myCommand.Parameters.Add(new SqlParameter("@sellid", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@newold", SqlDbType.Bit, 1));
			myCommand.Parameters.Add(new SqlParameter("@leastprice", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@directprice", SqlDbType.Int,4));
			myCommand.Parameters.Add(new SqlParameter("@currentprice", SqlDbType.Int,4));
			myCommand.Parameters.Add(new SqlParameter("@starttime", SqlDbType.DateTime, 8));
			myCommand.Parameters.Add(new SqlParameter("@endtime", SqlDbType.DateTime, 8));
			myCommand.Parameters.Add(new SqlParameter("@highestid", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@seller", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@comment", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@bidcost", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@paytype", SqlDbType.Text, 16));
			myCommand.Parameters.Add(new SqlParameter("@zone", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@givenway", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@blacklist", SqlDbType.Bit, 1));
			myCommand.Parameters.Add(new SqlParameter("@rules", SqlDbType.VarChar, 50));
			myCommand.Parameters["@sellid"].Value = DataGrid1.DataKeys[(int)e.Item.ItemIndex];
			string[] cols = {"@sellid","@newold","@leastprice","@directprice","@currentprice","@starttime","@endtime","@highestid","@seller","@comment","@bidcost","@paytype","@zone","@givenway","@blacklist","@rules"};
			int numcols = e.Item.Cells.Count;
			for (int i=2; i< numcols; i++) //skip first, second and last column
			{
				string colvalue = ((TextBox)e.Item.Cells[i].Controls[0]).Text;
				myCommand.Parameters[cols[i-1]].Value = colvalue;
			}
			Label1.Text=updateCmd;
			
			myCommand.Connection.Open();
			try 
			{
				Label1.Text=updateCmd;
				myCommand.ExecuteNonQuery();
				Label1.Text = "<b>�w��s��ƿ�</b><br>" + updateCmd;
				DataGrid1.EditItemIndex = -1;
			}
			catch (SqlException E)
			{
				if (E.Number == 2627)
					Label1.Text = "���~: �㦳�ۦP�D�����䪺��ƿ��w�g�s�b";
				else
					Label1.Text = "���~: �L�k��s��ƿ��A�нT�w�U���O�_���w���T��J";
				Label1.Style["color"] = "red";
			}
			myCommand.Connection.Close();
			
			reflesh();
		}
	}
}
