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
	/// user_modify ���K�n�y�z�C
	/// </summary>
	public class user_modify : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label Label12;
		protected System.Web.UI.WebControls.Label Label13;
		protected System.Web.UI.WebControls.Label Label14;
		protected System.Web.UI.WebControls.Label Label16;
		protected System.Web.UI.WebControls.TextBox �p���H�c;
		protected System.Web.UI.WebControls.TextBox �q�T�q��;
		protected System.Web.UI.WebControls.TextBox ��ʹq��;
		protected System.Web.UI.WebControls.TextBox �q�T�a�};
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.DropDownList ��;
		protected System.Web.UI.WebControls.DropDownList �ʧO;
		protected System.Web.UI.WebControls.TextBox �K�X;
		protected System.Web.UI.WebControls.TextBox ���ұK�X;
		protected System.Web.UI.WebControls.TextBox �m��;
		protected System.Web.UI.WebControls.TextBox �W�r;
		protected System.Web.UI.WebControls.TextBox �ʺ�;
		protected System.Web.UI.WebControls.TextBox �~;
		protected System.Web.UI.WebControls.DropDownList ��;
		protected System.Web.UI.WebControls.Button ���s��g;
		protected System.Web.UI.WebControls.Button �T�w�e�X;
		protected System.Web.UI.WebControls.Label Label15;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Image Image1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			
			if (! IsPostBack)
			{
				Label1.Text += "(" + Session["uname"].ToString() + ")";
				reflesh();
			}
		}
		private void reflesh()
		{
			string cmd="select * from member where �b��='"+Session["uname"].ToString()+"'";
			SqlConnection myConnection = new SqlConnection("server=127.0.0.1;uid=project;pwd=project;database=C09102014");
			SqlCommand myCommand = new SqlCommand(cmd, myConnection);
			myConnection.Open();
			SqlDataReader dr = myCommand.ExecuteReader();
			if(dr.Read())
			{
				�m��.Text = dr["�m��"].ToString();
				�W�r.Text = dr["�W�r"].ToString();
				�ʺ�.Text = dr["�ʺ�"].ToString();
				�p���H�c.Text = dr["�p���H�c"].ToString();
				�W�r.Text = dr["�W�r"].ToString();
				�q�T�q��.Text = dr["�q�T�q��"].ToString();
				��ʹq��.Text = dr["��ʹq��"].ToString();
				�q�T�a�}.Text = dr["�q�T�a�}"].ToString();
			}
				
			dr.Close();
			myConnection.Close();	
			Label15.Text="�Y�����K�X�A�Цb�K�X��d�ťաI";
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
			this.�T�w�e�X.Click += new System.EventHandler(this.�T�w�e�X_Click);
			this.���s��g.Click += new System.EventHandler(this.���s��g_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void ���s��g_Click(object sender, System.EventArgs e)
		{
			Label15.Text="�Y�����K�X�A�Цb�K�X��d�ťաI";
			reflesh();
		}

		private void �T�w�e�X_Click(object sender, System.EventArgs e)
		{
			Label15.Text="";
			bool go = true;
			bool setpwd = true;
			if (�K�X.Text!=���ұK�X.Text)
			{
				Label15.Text += "�K�X��J���P<br>";
				go =false;
			}
			if (�K�X.Text=="" && ���ұK�X.Text=="")
			{
				setpwd = false;
			}
			if (�m��.Text=="")
			{
				Label15.Text += "�m�󤣥i���ť�<br>";
				go = false;
			}
			if (�W�r.Text=="")
			{
				Label15.Text += "�W�r���i���ť�<br>";
				go = false;
			}
			if (�~.Text=="")
			{
				Label15.Text += "�X�ͦ~�����i���ť�<br>";
				go = false;
			}
			if (�p���H�c.Text=="")
			{
				Label15.Text += "�p���H�c���i���ť�<br>";
				go = false;
			}
			if (�q�T�q��.Text=="")
			{
				Label15.Text += "�q�T�q�ܤ��i���ť�<br>";
				go = false;
			}
			if (��ʹq��.Text=="")
			{
				Label15.Text += "��ʹq�ܤ��i���ť�<br>";
				go = false;
			}
			if (�q�T�a�}.Text=="")
			{
				Label15.Text += "�q�T�a�}���i���ť�<br>";
				go = false;
			}
			if (go)
			{
				string cmd = "update member set ";
				if (setpwd)
				{
					cmd += "�K�X='" + �K�X.Text + "', ";
				}
				cmd += " �m��='" + �m��.Text + "', " +
					"�W�r='" + �W�r.Text + "', " +
					"�ʺ�='" + �ʺ�.Text + "', " +
					"�m�O='" + �ʧO.SelectedValue.ToString() + "', "+
					"�褸='" + �~.Text + "', " +
					"��='" + ��.SelectedValue.ToString() + "', "+
					"��='" + ��.SelectedValue.ToString() + "', " +
					"�p���H�c='" + �p���H�c.Text + "', "+
					"�q�T�q��='" + �q�T�q��.Text + "', "+
					"��ʹq��='" + ��ʹq��.Text + "', " +
					"�q�T�a�}='" + �q�T�a�}.Text + "' " +
					"where �b��='" + Session["uname"].ToString() + "'";
				SqlConnection myConnection = new SqlConnection("server=127.0.0.1;uid=project;pwd=project;database=C09102014");
				SqlCommand myCommand = new SqlCommand(cmd, myConnection);
				myConnection.Open();
				myCommand.ExecuteNonQuery();
				myCommand.Connection.Close();
				Response.Redirect("index.aspx");
			}
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			Response.Redirect("index.aspx");
		}
	}
}
