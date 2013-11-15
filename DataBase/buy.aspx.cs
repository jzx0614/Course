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
	/// buy ���K�n�y�z�C
	/// </summary>
	public class buy : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.Label Label8;
		protected System.Web.UI.WebControls.Label Label9;
		protected System.Web.UI.WebControls.Label Label10;
		protected System.Web.UI.WebControls.Label Label11;
		protected System.Web.UI.WebControls.Label Label12;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.Button Button3;
		protected System.Web.UI.WebControls.Image Image1;
		protected string money;
		protected string qty;
		protected string bidnum;
		protected int high_money;
		protected int low_money;
		protected string passwd;
		protected System.Data.SqlClient.SqlConnection myConnection;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;

	
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			money=Request.QueryString["money"];
			qty=Request.QueryString["qty"];
			bidnum=Request.QueryString["bid"];
			if (Session["uname"]==null)
			{
				Label1.Text = "�w����{!";
				HyperLink1.Text="�n�J";
				HyperLink1.NavigateUrl="user_login.aspx";
				
			}
			else 
			{
				Label1.Text = "�w����{! "+Session["�ʺ�"].ToString()+" ("+Session["uname"].ToString()+")";
				HyperLink1.Text="�n�X";
				HyperLink1.NavigateUrl="user_logout.aspx";
				Label3.Text=Session["uname"].ToString();
			}
			if(bidnum!=null)
			{
				Label11.Text=bidnum;
				Label9.Text=money;
				Label8.Text=qty;
				HyperLink2.NavigateUrl="see_product.aspx?bid="+bidnum;
				myConnection = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
				string cmd = "select * from product, bid where product.���s��=bid.���s�� and product.���s��='" + bidnum + "'";
				SqlCommand sqlcmd = new SqlCommand(cmd, myConnection);
				myConnection.Open();
				SqlDataReader dr = sqlcmd.ExecuteReader();
				if(dr.HasRows)
				{
					dr.Read();
					Label12.Text=dr["�ӫ~�W��"].ToString();
					Label10.Text=dr["�ثe�X��"].ToString();
					high_money=int.Parse(dr["�����ʻ�"].ToString());
					low_money=int.Parse(dr["�_�л�"].ToString());
					if(int.Parse(Label8.Text)>int.Parse(dr["�ӫ~�ƶq"].ToString()))
					{
						Label8.Text=dr["�ӫ~�ƶq"].ToString();
						qty=dr["�ӫ~�ƶq"].ToString();
					}
				}
				myConnection.Close();
				if(int.Parse(Label9.Text)>=low_money && int.Parse(Label9.Text)>int.Parse(Label10.Text))
				{
					if(int.Parse(Label9.Text)>high_money)
					{
						Label9.Text=high_money.ToString();
					}
					
				}
				else
				{
					Label5.Text="�z���X�����ŦX����";
					Button2.Enabled=false;
				}
			}
			else
				Response.Redirect("index.aspx");
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
			this.myConnection = new System.Data.SqlClient.SqlConnection();
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.Button3.Click += new System.EventHandler(this.Button3_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion

		private void Button2_Click(object sender, System.EventArgs e)
		{
			string cmd="select �K�X from member where �b��='"+Label3.Text+"'";

			SqlCommand sqlcmd =new SqlCommand(cmd,myConnection);
			myConnection.Open();
			SqlDataReader dr=sqlcmd.ExecuteReader();
			if(dr.HasRows)
			{
				dr.Read();
				passwd=dr["�K�X"].ToString();
			}
			myConnection.Close();
			if(passwd==TextBox1.Text)
			{
				Order();
			}
			else
			{
				Label5.Text="�K�X���~";
			}
		}
		private void Order()
		{
			
				string date=DateTime.Now.ToShortDateString()+" "+DateTime.Now.Hour.ToString()+":"+DateTime.Now.Minute.ToString();
				string cmd1 = "INSERT INTO buy values('"+ Label3.Text +"','"+ qty +"',"+Label9.Text+",'"+ date +"','"+ bidnum +"')";	
				SqlCommand myCommand1 = new SqlCommand(cmd1,myConnection);
				myCommand1.Connection.Open();
				try
				{
					myCommand1.ExecuteNonQuery();
				}
				catch
				{
					Label5.Text=" <b>�X������1</b>"+cmd1;
				}
				myCommand1.Connection.Close();
				string cmd = "UPDATE bid SET �̰��X����='"+Label3.Text+"', �ثe�X��="+Label9.Text+" where ���s��="+bidnum;	
				SqlCommand myCommand = new SqlCommand(cmd,myConnection);
				myCommand.Connection.Open();
				try 
				{
					myCommand.ExecuteNonQuery();
					Label5.Text = "<b>�w�X��" +Label9.Text+" �󦹩�椤</b><br>";
				}
				catch
				{
					Label5.Text=" <b>�X������2</b>";
				}
				myCommand.Connection.Close();
		}

		private void Button3_Click(object sender, System.EventArgs e)
		{
			TextBox1.Text="";
		}
	}
}
