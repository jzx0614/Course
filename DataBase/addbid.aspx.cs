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
using System.IO;

namespace C09102014
{
	/// <summary>
	/// addbid ���K�n�y�z�C
	/// </summary>
	public class addbid : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Button btnUpload;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.Label Label12;
		protected System.Web.UI.WebControls.Label Label13;
		protected System.Web.UI.WebControls.Label Label14;
		protected System.Web.UI.WebControls.Label Label15;
		protected System.Web.UI.WebControls.Label Label16;
		protected System.Web.UI.WebControls.Label Label17;
		protected System.Web.UI.WebControls.Label Label18;
		protected System.Web.UI.WebControls.Label Label19;
		protected System.Web.UI.WebControls.TextBox �ӫ~���D;
		protected System.Web.UI.WebControls.TextBox �ӫ~�W��;
		protected System.Web.UI.WebControls.TextBox �Ҧb�a��;
		protected System.Web.UI.WebControls.TextBox �B�O;
		protected System.Web.UI.WebControls.DropDownList �I�ڤ覡;
		protected System.Web.UI.WebControls.DropDownList ��f�覡;
		protected System.Web.UI.WebControls.DropDownList �ӫ~�s��;
		protected System.Web.UI.WebControls.TextBox �����ʶR��;
		protected System.Web.UI.WebControls.TextBox �_�л�;
		protected System.Web.UI.WebControls.TextBox ����u�h;
		protected System.Web.UI.WebControls.TextBox �ӫ~�ƶq;
		protected System.Web.UI.WebControls.Label error;
		protected System.Web.UI.HtmlControls.HtmlInputFile File1;
		protected System.Web.UI.WebControls.TextBox y1;
		protected System.Web.UI.WebControls.TextBox m1;
		protected System.Web.UI.WebControls.TextBox TextBox4;
		protected System.Web.UI.WebControls.Label Label20;
		protected System.Web.UI.WebControls.Label Label21;
		protected System.Web.UI.WebControls.Label Label22;
		protected System.Web.UI.WebControls.Label Label23;
		protected System.Web.UI.WebControls.Label Label24;
		protected System.Web.UI.WebControls.Label Label25;
		protected System.Web.UI.WebControls.TextBox d1;
		protected System.Web.UI.WebControls.TextBox TextBox6;
		protected System.Web.UI.WebControls.TextBox y2;
		protected System.Web.UI.WebControls.Label Label26;
		protected System.Web.UI.WebControls.TextBox m2;
		protected System.Web.UI.WebControls.Label Label27;
		protected System.Web.UI.WebControls.TextBox d2;
		protected System.Web.UI.WebControls.Label Label28;
		protected System.Web.UI.WebControls.TextBox �ӫ~�ԭz;
		protected System.Web.UI.WebControls.Label error1;
		protected System.Web.UI.WebControls.ListBox ListBox1;
		protected System.Web.UI.WebControls.ListBox ListBox2;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Button Button2;
		SqlConnection sqlcnt;
		protected System.Web.UI.WebControls.ListBox ListBox3;
		protected System.Web.UI.WebControls.Button Button3;
		protected System.Web.UI.WebControls.Label Label29;
		protected System.Web.UI.WebControls.Label Label30;
		protected System.Web.UI.WebControls.Label Label31;
		protected System.Web.UI.WebControls.Label Label32;
		protected System.Web.UI.WebControls.Label Label33;
		string classnum;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			if (Session["uname"]==null)
			{
				error1.Text = "�Х��n�J";
				btnUpload.Visible = false;
				ListBox2.Visible = false;
				Button2.Visible = false;
				ListBox3.Visible = false;
				Button3.Visible = false;
				Label30.Visible = false;
				Label31.Visible = false;
				return;
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				sqlcnt.Open();
				SqlCommand sqlcmd = new SqlCommand("select ���O�W�� from class where �����O�s��='0'",sqlcnt);
				SqlDataReader dr = sqlcmd.ExecuteReader();
				while (dr.Read())
				{
					ListBox1.Items.Add(dr["���O�W��"].ToString());
				}
				sqlcnt.Close();
				ListBox2.Visible = false;
				Button2.Visible = false;
				ListBox3.Visible = false;
				Button3.Visible = false;
				Label30.Visible = false;
				Label31.Visible = false;
				ListBox2.Items.Clear();
				ListBox3.Items.Clear();
			}
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
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.btnUpload.Click += new System.EventHandler(this.btnUpload_Click);
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Button3.Click += new System.EventHandler(this.Button3_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void btnUpload_Click(object sender, System.EventArgs e)
		{
			if (�ӫ~�W��.Text==null || �ӫ~���D.Text==null || �Ҧb�a��.Text==null || �B�O.Text==null || �����ʶR��.Text==null ||
				�_�л�.Text==null || �ӫ~�ƶq.Text==null || File1.PostedFile.FileName==null)
			{
				error.Text = "�����S����g�T��!!";
			}
			else
			{
				sqlcnt.Open();
				string strFileName = File1.PostedFile.FileName;
				strFileName = System.IO.Path.GetFileName(strFileName);
				File1.PostedFile.SaveAs(Server.MapPath("image/") + strFileName);
				string cmd1 = "insert bid (�ӫ~�s��,�_�л�,�����ʻ�,�}�l�ɶ�,�����ɶ�,��a�s��,����,�B�O,�I�ڤ覡,�Ҧb�a��,��f�覡,�ӫ~�¦W��, ����u�h)" 
					+ "values ('" + 
					int.Parse(�ӫ~�s��.SelectedValue.ToString()) + "', '" +
					int.Parse(�_�л�.Text) + "', '" +
					int.Parse(�����ʶR��.Text) + "', '" +
					y1.Text+"/"+m1.Text+"/"+d1.Text + "', '" +
					y2.Text+"/"+m2.Text+"/"+d2.Text + "', '" +
					Session["uname"].ToString() + "', '100', '" +
					int.Parse(�B�O.Text) + "', '" +
					�I�ڤ覡.SelectedValue.ToString() + "', '" +
					�Ҧb�a��.Text + "', '" +
					��f�覡.SelectedValue.ToString() + "', '0', '" +
					����u�h.Text 
					+"')";
				SqlCommand sqlcmd = new SqlCommand(cmd1,sqlcnt);
				sqlcmd.ExecuteNonQuery();
				string cmd2 = "insert product (�ӫ~�W��, �ӫ~���D, �ӫ~�ƶq, �ӫ~�Ϥ�, ���O�s��, �ӫ~�ԭz)values ('" + �ӫ~�W��.Text + "', '" + �ӫ~���D.Text + "', '" + �ӫ~�ƶq.Text + "', '" + 
					strFileName + "', '" + error.Text + "', '" + �ӫ~�ԭz.Text + "')";  
				sqlcmd = new SqlCommand(cmd2, sqlcnt);
				sqlcmd.ExecuteNonQuery();
				sqlcnt.Close();
				error.Text = "";
				Response.Redirect("index.aspx");
			}
		}


		private void Button1_Click(object sender, System.EventArgs e)
		{
			string b = ListBox1.SelectedValue.ToString();
			string getclass = "select ���O�s�� from class where ���O�W��='" + b + "'";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(getclass, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			classnum = dr["���O�s��"].ToString();
			dr.Close();
			string cmd = "select A.���O�W�� from class A, class B where A.�����O�s��=B.���O�s�� AND B.���O�W��='" + b + "'";
			sqlcmd = new SqlCommand(cmd, sqlcnt);
			dr = sqlcmd.ExecuteReader();
			ListBox2.Items.Clear();
			ListBox3.Items.Clear();
			ListBox2.Visible = false;
			ListBox3.Visible = false;
			Label30.Visible = false;
			Label31.Visible = false;
			Button2.Visible = false;
			Button3.Visible = false;
			while(dr.Read())
			{
				ListBox2.Items.Add(dr["���O�W��"].ToString());
				ListBox2.Visible = true;
				Button2.Visible = true;
				Label30.Visible = true;
			}
			error.Text = classnum;
			error.Visible = false;
		}

		private void Button2_Click(object sender, System.EventArgs e)
		{
			string b = ListBox2.SelectedValue.ToString();
			string getclass = "select ���O�s�� from class where ���O�W��='" + b + "'";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(getclass, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			classnum = dr["���O�s��"].ToString();
			dr.Close();
			string cmd = "select A.���O�W�� from class A, class B where A.�����O�s��=B.���O�s�� AND B.���O�W��='" + b + "'";
			sqlcmd = new SqlCommand(cmd, sqlcnt);
			dr = sqlcmd.ExecuteReader();
			ListBox3.Items.Clear();
			ListBox3.Visible = false;
			Label31.Visible = false;
			Button3.Visible = false;
			while(dr.Read())
			{
				ListBox3.Items.Add(dr["���O�W��"].ToString());
				ListBox3.Visible = true;
				Button3.Visible = true;
				Label31.Visible = true;
			}
			error.Text = classnum;
			error.Visible = false;
		}

		private void Button3_Click(object sender, System.EventArgs e)
		{
			string b = ListBox3.SelectedValue.ToString();
			string getclass = "select ���O�s�� from class where ���O�W��='" + b + "'";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(getclass, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			classnum = dr["���O�s��"].ToString();
			dr.Close();
			error.Text = classnum;
			error.Visible = false;
		}

	}
}
