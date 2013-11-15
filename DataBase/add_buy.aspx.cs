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
	/// add_buy ���K�n�y�z�C
	/// </summary>
	public class add_buy : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.RequiredFieldValidator RequiredFieldValidator1;
		protected System.Web.UI.WebControls.RequiredFieldValidator RequiredFieldValidator3;
		protected System.Web.UI.WebControls.RequiredFieldValidator RequiredFieldValidator2;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.HtmlControls.HtmlInputText order;
		protected System.Web.UI.HtmlControls.HtmlInputText num;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.HtmlControls.HtmlInputText bid;
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.WebControls.RequiredFieldValidator RequiredFieldValidator4;
		protected System.Web.UI.HtmlControls.HtmlInputText id;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			
			myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
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
			Label6.Text = "";

			if (Page.IsValid)
			{

				String insertCmd = "insert into buy values (@id, @num, @order, @date, @bid)";

				SqlCommand myCommand = new SqlCommand(insertCmd, myConnection);

				myCommand.Parameters.Add(new SqlParameter("@id", SqlDbType.VarChar, 50));
				myCommand.Parameters["@id"].Value = id.Value;

				myCommand.Parameters.Add(new SqlParameter("@num", SqlDbType.Int, 4));
				myCommand.Parameters["@num"].Value = num.Value;

				myCommand.Parameters.Add(new SqlParameter("@order", SqlDbType.Money, 8));
				myCommand.Parameters["@order"].Value = order.Value;

				
				DateTime now_time=DateTime.Now;
				string show=now_time.ToLongTimeString();
				myCommand.Parameters.Add(new SqlParameter("@date", SqlDbType.DateTime,8));
				myCommand.Parameters["@date"].Value=show;
	
				myCommand.Parameters.Add(new SqlParameter("@bid", SqlDbType.Int, 4));
				myCommand.Parameters["@bid"].Value = bid.Value;

				myCommand.Connection.Open();

				try
				{
					myCommand.ExecuteNonQuery();
					Label6.Text = "<b>�w�[�J����ƿ�</b><br>" + insertCmd + "<p>";
				}
				catch (SqlException E)
				{
					if (E.Number == 2627)
						Label6.Text = "���~: �㦳�ۦP�D�����䪺��ƿ��w�g�s�b<p>";
					else
						Label6.Text = "���~: �L�k�[�J��ƿ��A�нT�w�U���O�_���w���T��J<p>";
					Label6.Style["color"] = "red";
				}

				myCommand.Connection.Close();
			}
			
		}

	}
}
