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
	/// user_login ���K�n�y�z�C
	/// </summary>
	public class user_login : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.HtmlControls.HtmlTableCell TD1;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.HtmlControls.HtmlTable Table3;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Button Button1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
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
			string cmd="select �K�X, �ʺ�, Enable from member where �b��='"+TextBox1.Text+"'";
			SqlConnection myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			SqlCommand myCommand = new SqlCommand(cmd, myConnection);

			myConnection.Open();

			SqlDataReader dr = myCommand.ExecuteReader();
			if(dr.Read())
			{
				if(dr["�K�X"].ToString()==TextBox2.Text && dr["Enable"].ToString()=="True")
				{
					Session["uname"] = TextBox1.Text;
					Session["�ʺ�"] = dr["�ʺ�"].ToString();
					Response.Redirect("index.aspx");
				}
				else if (dr["Enable"].ToString()=="False")
				{
					Label1.Text="���b���w�g�Q�ᵲ�F!!<br>�Ь��ߺ޲z��";
				}
				else
				{
					Label1.Text="�K�X���~";
				}
			}
			else
			{
				Label1.Text="���b�����s�b";
			}
	
			dr.Close();
			myConnection.Close();	
		}
	}
}
