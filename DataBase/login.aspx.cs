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
	/// login ���K�n�y�z�C
	/// </summary>
	public class login : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.TextBox username;
		protected System.Web.UI.WebControls.TextBox passwd;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Button Button1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			Session.RemoveAll();
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
			string cmd="select �K�X,�s�� from admin where �b��='"+username.Text+"'";
			Label4.Text=cmd;
			SqlConnection myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			SqlCommand myCommand = new SqlCommand(cmd, myConnection);

			myConnection.Open();

			SqlDataReader dr = myCommand.ExecuteReader();
			if(dr.Read())
			{
				if(dr["�K�X"].ToString()==passwd.Text)
				{
					Session["group"]=dr["�s��"].ToString();
					if(Session["group"].ToString()=="product")
						Response.Redirect("adm_product.aspx");
					else if(Session["group"].ToString()=="bid")
						Response.Redirect("adm_bid.aspx");
					else
						Response.Redirect("adm_member.aspx");
				}
				else
					Label4.Text="�K�X���~"+dr["�K�X"];
			}
			else{
				Label4.Text="���b�����s�b";
			}
	
			dr.Close();
			myConnection.Close();			
		}
	}
}
