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
	/// add_member ���K�n�y�z�C
	/// </summary>
	public class add_member : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.TextBox TextBox3;
		protected System.Web.UI.WebControls.TextBox TextBox4;
		protected System.Web.UI.WebControls.TextBox TextBox5;
		protected System.Web.UI.WebControls.TextBox TextBox6;
		protected System.Web.UI.WebControls.TextBox TextBox7;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.Label Label6;
		protected System.Web.UI.WebControls.Label Label7;
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.DropDownList DropDownList2;
		protected System.Web.UI.WebControls.DropDownList DropDownList3;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.TextBox TextBox8;
		protected System.Web.UI.WebControls.Label Label12;
		protected System.Web.UI.WebControls.TextBox TextBox9;
		protected System.Web.UI.WebControls.Label Label13;
		protected System.Web.UI.WebControls.TextBox TextBox10;
		protected System.Web.UI.WebControls.Label Label14;
		protected System.Web.UI.WebControls.TextBox TextBox11;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.Label Label15;
		protected System.Web.UI.WebControls.TextBox TextBox12;
		protected System.Web.UI.WebControls.Label Label16;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.LinkButton LinkButton1;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			if(Session["group"]==null||(Session["group"].ToString()!="member"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
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
			this.DropDownList2.SelectedIndexChanged += new System.EventHandler(this.DropDownList2_SelectedIndexChanged);
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.LinkButton1.Click += new System.EventHandler(this.LinkButton1_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button2_Click(object sender, System.EventArgs e)
		{

			if (TextBox1.Text=="" || TextBox2.Text=="" || TextBox3.Text==""||TextBox4.Text=="" || TextBox5.Text=="" || TextBox6.Text=="" 
				||TextBox7.Text=="" || TextBox8.Text=="" || TextBox9.Text==""||TextBox10.Text=="" || TextBox11.Text=="" || TextBox12.Text==""
				|| DropDownList1.ToString() == ""|| DropDownList2.ToString() == ""|| DropDownList3.ToString() == "")
			{	
				Label15.Text = "��줣��O�ŭ�!!";
			}
			else if (TextBox2.Text!=TextBox3.Text)
			{
				Label15.Text = "�K�X�]�w���ۦP!!";
			}
			else 
			{
				SqlConnection sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
				string str = "insert into member values ('";
				str +=  TextBox1.Text + "','"; 
				str +=  TextBox2.Text + "','"; 
				str +=  TextBox4.Text + "','"; 
				str +=  TextBox5.Text + "','";
				str +=  TextBox6.Text + "','"; 
				str +=  DropDownList1.SelectedValue + "','";
				str +=  int.Parse(TextBox7.Text) + "','";
				str +=  int.Parse(DropDownList2.SelectedValue) + "','" ;
				str +=  int.Parse(DropDownList3.SelectedValue) + "','" ;
				str +=  TextBox8.Text + "','";
				str +=  TextBox9.Text + "','";
				str +=  TextBox10.Text + "','";
				str +=  TextBox11.Text + "','";
				str +=  TextBox12.Text + "')";
				SqlCommand sqlcmd = new SqlCommand(str,sqlcnt);
				sqlcmd.Connection.Open();
				sqlcmd.ExecuteNonQuery();
				sqlcmd.Connection.Close();
				Label15.Text = "�s�W���\!";
			}
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
		
		}

		private void LinkButton1_Click(object sender, System.EventArgs e)
		{
			Response.Redirect("adm_member.aspx");
		}

		private void DropDownList2_SelectedIndexChanged(object sender, System.EventArgs e)
		{
		
		}
	}
}
