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
	/// ans ���K�n�y�z�C
	/// </summary>
	public class ans : System.Web.UI.Page
	{
		string bidnum;
		string qnum;
		protected System.Web.UI.WebControls.Label Label1;
		string seller;
		protected System.Web.UI.WebControls.Table Table1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		SqlConnection sqlcnt;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			bidnum = Request.QueryString["bid"];
			qnum = Request.QueryString["qnum"];
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			string cmd = "select ��a�s�� from bid where ���s��='" + bidnum + "';";
			SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
			sqlcnt.Open();
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			seller = dr["��a�s��"].ToString();
			sqlcnt.Close();
			
			Label2.Visible = false;
			TextBox1.Visible=false;
			Button1.Visible=false;

			if (Session["uname"]==null)
			{
				Label1.Text = "�z�D��a�A�������a�ѵ����D�C";
			}
			else if (Session["uname"]!=null && Session["uname"].ToString() != seller)
			{
				Label1.Text = "�z�D��a�A�������a�^�����D�C";
			}
			else
			{
				
				string cmd2 = "select Qnum,���D from QandA where ���� is null and ���s��='"+bidnum + "'";
				SqlCommand sqlcmd2 = new SqlCommand(cmd2, sqlcnt);
				sqlcnt.Open();
				SqlDataReader dr2 = sqlcmd2.ExecuteReader();
				int i = 1;
				Label1.Text = "�z�ݭn�^�������D��: ";
				while (dr2.Read())
				{
					TableRow r = new TableRow();
					Table1.Rows.Add(r);
					TableCell c0 = new TableCell();
					c0.Text = "���D " + i.ToString();
					r.Cells.Add(c0);
					TableCell c1 = new TableCell();
					c1.Text = "<a href=ans.aspx?qnum=" + dr2["Qnum"].ToString() + "&bid=" + bidnum + ">" + dr2["���D"].ToString() + "</a>";
					r.Cells.Add(c1);
					i++;
				}
				sqlcnt.Close();
				if(qnum!=null)
				{
					Label2.Visible = true;
					TextBox1.Visible=true;
					Button1.Visible= true;
					SqlCommand sqlcmd3 = new SqlCommand("select ���D from QandA where Qnum ='"+qnum+"'",sqlcnt);
					sqlcnt.Open();
					SqlDataReader dr1 = sqlcmd3.ExecuteReader();
					dr1.Read();
					Label3.Text = dr1["���D"].ToString();
				}
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
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button1_Click(object sender, System.EventArgs e)
		{
			SqlConnection sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			SqlCommand sqlcmd = new SqlCommand("update QandA set ����='" + TextBox1.Text +"' where Qnum='" + qnum +"';",sqlcnt);
			sqlcnt.Open();
			sqlcmd.ExecuteNonQuery();
			Label2.Visible = false;
			Label1.Text = "��s���\!";
			TextBox1.Visible = false;
			Button1.Visible = false;		
		}
	}
}
