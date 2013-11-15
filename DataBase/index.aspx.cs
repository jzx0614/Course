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

namespace C09102014
{
	/// <summary>
	/// index ���K�n�y�z�C
	/// </summary>
	public class index : System.Web.UI.Page
	{
		protected System.Web.UI.HtmlControls.HtmlTable Table1;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.Image Image2;
		protected System.Web.UI.WebControls.Image Image3;
		protected System.Web.UI.WebControls.Image Image4;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.DropDownList DropDownList1;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
		protected System.Web.UI.WebControls.HyperLink HyperLink3;
		protected System.Web.UI.WebControls.HyperLink HyperLink4;
		protected System.Web.UI.WebControls.HyperLink HyperLink5;
		protected System.Web.UI.WebControls.HyperLink HyperLink6;
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.HyperLink HyperLink7;
		protected System.Web.UI.WebControls.HyperLink HyperLink8;
		protected System.Web.UI.WebControls.HyperLink HyperLink9;
		protected System.Web.UI.WebControls.HyperLink HyperLink10;
		protected System.Web.UI.WebControls.HyperLink HyperLink11;
		protected System.Web.UI.WebControls.Image Image5;
		protected System.Web.UI.WebControls.Image Image6;
		protected System.Web.UI.WebControls.Image Image7;
		protected System.Web.UI.WebControls.Image Image8;
		protected System.Web.UI.WebControls.Label Label1;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			if (Session["uname"]==null)
			{
				Label1.Text = "�w����{! <a href=user_login.aspx>�|���n�J</a>-<a href=user_add_member.aspx>�ڭn���U</a>";
			}
			else 
			{
				Label1.Text = Session["�ʺ�"].ToString() + "(" + Session["uname"].ToString() + 
					"�n�J��) <a href=user_logout.aspx>�|���n�X</a>-<a href=user_modify.aspx>�ק�ڪ����</a>";
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
			string str_url="see_bid.aspx?";
			if(TextBox1.Text!=""&&DropDownList1.SelectedIndex!=2)
			{
				if(DropDownList1.SelectedIndex==0)
					str_url+="likeword="+TextBox1.Text;
				else if(DropDownList1.SelectedIndex==1)
					str_url+="sid="+TextBox1.Text;
				Response.Redirect(str_url);	
			}
			else if(TextBox1.Text!="")
			{

				Response.Redirect("see_product.aspx?bid="+TextBox1.Text);
			}
		}


	}
}
