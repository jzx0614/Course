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
	/// see_product ���K�n�y�z�C
	/// </summary>
	public class see_product : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Image Image1;
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.HtmlControls.HtmlTable Table1;
		protected System.Web.UI.HtmlControls.HtmlTable Table2;
		protected System.Web.UI.HtmlControls.HtmlTable Table3;
		protected System.Web.UI.WebControls.Label ��a;
		protected System.Web.UI.WebControls.Label ����;
		protected System.Web.UI.WebControls.Label �I�ڤ覡;
		protected System.Web.UI.WebControls.Label ��f�覡;
		protected System.Web.UI.WebControls.Label �ӫ~�s��;
		protected System.Web.UI.WebControls.Label �B�e�O��;
		protected System.Web.UI.WebControls.Label ���s��;
		protected System.Web.UI.WebControls.Label �����ɶ�;
		protected System.Web.UI.WebControls.Label �}�l�ɶ�;
		protected System.Web.UI.WebControls.Label �Ҧb�a��;
		protected System.Web.UI.WebControls.Label �_�л���;
		protected System.Web.UI.WebControls.Label �ӫ~�ƶq;
		protected System.Web.UI.WebControls.Label �̰��X����;
		protected System.Web.UI.WebControls.Label �����ʶR��;
		protected System.Web.UI.WebControls.Label �ثe�X��;
		protected System.Web.UI.WebControls.Label Label3;
		protected System.Web.UI.WebControls.Label Label2;
		protected System.Web.UI.WebControls.ImageButton ImageButton1;
		protected System.Web.UI.HtmlControls.HtmlTable Table5;
		protected System.Web.UI.WebControls.TextBox TextBox2;
		protected System.Web.UI.WebControls.Button Button2;
		protected System.Web.UI.WebControls.TextBox TextBox3;
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
		protected System.Web.UI.HtmlControls.HtmlForm Form1;
		protected System.Data.SqlClient.SqlConnection sqlcnt;
		protected System.Web.UI.WebControls.DataGrid Datagrid1;
		protected System.Web.UI.WebControls.TextBox Textbox4;
		protected System.Web.UI.WebControls.TextBox Textbox5;
		protected System.Web.UI.WebControls.Button Button1;
		protected System.Web.UI.WebControls.Button Button4;
		protected System.Web.UI.WebControls.Button Button3;
		protected System.Web.UI.WebControls.TextBox Textbox6;
		protected System.Web.UI.WebControls.TextBox Textbox1;
		protected System.Web.UI.HtmlControls.HtmlTable Table7;
		protected System.Web.UI.WebControls.Label Label4;
		protected System.Web.UI.WebControls.Label Label5;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.HyperLink Hyperlink4;
		protected System.Web.UI.WebControls.HyperLink Hyperlink5;
		protected System.Web.UI.WebControls.DataGrid MyDataGrid;
		protected System.Web.UI.WebControls.Table Table4;
		protected System.Web.UI.WebControls.ImageButton ImageButton2;
		protected System.Web.UI.WebControls.HyperLink Hyperlink2;
		protected System.Web.UI.WebControls.TextBox TextBox1;
		string tab;
		string bidnum;
		DateTime over_time;
		private void Page_Load(object sender, System.EventArgs e)
		{
			// �b�o�̩�m�ϥΪ̵{���X�H��l�ƺ���
			
			Hyperlink5.Visible = false;
			if (Session["uname"]==null)
			{
				Table5.Visible = true;
				Table3.Visible= false;
			}
			else 
			{
				Table5.Visible = false;
				Table3.Visible= true;
			}
			bidnum=Request.QueryString["bid"];
			tab=Request.QueryString["tab"];
			if(tab==null)
				tab="0";
			
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				string cmd = "select * from product, bid where product.���s��=bid.���s�� and product.���s��='" + bidnum + "'";
				SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
				sqlcnt.Open();
				SqlDataReader dr = sqlcmd.ExecuteReader();
				
				if(dr.HasRows)
				{
					dr.Read();
					ImageButton1.ImageUrl = "image/" + dr["�ӫ~�Ϥ�"].ToString();
					Label1.Text = dr["�ӫ~���D"].ToString();
					�ӫ~�ƶq.Text = dr["�ӫ~�ƶq"].ToString();
					��a.Text = dr["��a�s��"].ToString();
					����.Text = dr["����"].ToString() + " %";
					�I�ڤ覡.Text = dr["�I�ڤ覡"].ToString();
					��f�覡.Text = dr["��f�覡"].ToString();
					if (dr["�ӫ~�s��"].ToString() == "1")
						�ӫ~�s��.Text = "���s";
					else
						�ӫ~�s��.Text = "�°ӫ~";
					�ثe�X��.Text = dr["�ثe�X��"].ToString();
					�����ʶR��.Text = dr["�����ʻ�"].ToString();
					�̰��X����.Text = dr["�̰��X����"].ToString();
					�_�л���.Text = dr["�_�л�"].ToString();
					�Ҧb�a��.Text = dr["�Ҧb�a��"].ToString();
					�}�l�ɶ�.Text = dr["�}�l�ɶ�"].ToString();
					�����ɶ�.Text = dr["�����ɶ�"].ToString();
					
					over_time=dr.GetDateTime(13);
					���s��.Text = Request.QueryString["bid"].ToString();
					�B�e�O��.Text = dr["�B�O"].ToString();
					Label3.Text=�ثe�X��.Text;
					Label4.Text=�����ʶR��.Text;
					dr.Close();
					sqlcnt.Close();	
				}
				else
					Response.Redirect("index.aspx");
				if(tab=="0")
					BindGrid1();
				else if (tab == "1")
					BindGrid();
				else
					show_image();

			}
			if(DateTime.Compare(DateTime.Now,over_time)==1 || �ثe�X��.Text==�����ʶR��.Text)
			{
				Button1.Enabled=false;
				Button4.Enabled=false;
				Button1.Text="�w�I��";
				Button4.Text="�w�I��";
			}

			if (Session["uname"]!=null && Session["uname"].ToString() == ��a.Text)
			{
				Hyperlink5.Visible = true;
				bidnum = Request.QueryString["bid"].ToString();	
				Hyperlink5.NavigateUrl = "ans.aspx?bid=" + bidnum;
			}

			if(tab=="1")
			{
				Hyperlink4.NavigateUrl="see_product.aspx?tab=0&bid=" + bidnum;
				Hyperlink2.NavigateUrl="see_product.aspx?tab=2&bid=" + bidnum;
				MyDataGrid.Visible=true;
				Datagrid1.Visible=false;
				ImageButton2.Visible = false;
				Label5.Visible = false;
				Button3.Visible=true;
			}
			else if(tab=="0")
			{
				HyperLink1.NavigateUrl="see_product.aspx?tab=1&bid=" + bidnum;
				Hyperlink2.NavigateUrl="see_product.aspx?tab=2&bid=" + bidnum;
				MyDataGrid.Visible=false;
				TextBox1.Visible=false;
				Button3.Visible=false;
				Datagrid1.Visible=true;
				ImageButton2.Visible = false;
				Label5.Visible = false;
			}
			else 
			{
				HyperLink1.NavigateUrl="see_product.aspx?tab=1&bid=" + bidnum;
				Hyperlink4.NavigateUrl="see_product.aspx?tab=0&bid=" + bidnum;
				MyDataGrid.Visible=false;
				TextBox1.Visible=false;
				Button3.Visible=false;
				Datagrid1.Visible=false;
				ImageButton2.Visible = true;
				Label5.Visible = true;
				Hyperlink4.NavigateUrl="see_product.aspx?tab=0&bid=" + bidnum;
				HyperLink1.NavigateUrl="see_product.aspx?tab=1&bid=" + bidnum;
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
			this.sqlcnt = new System.Data.SqlClient.SqlConnection();
			this.Button2.Click += new System.EventHandler(this.Button2_Click);
			this.Button1.Click += new System.EventHandler(this.Button1_Click);
			this.Button4.Click += new System.EventHandler(this.Button4_Click);
			this.Button3.Click += new System.EventHandler(this.Button3_Click);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion


		private void Button2_Click(object sender, System.EventArgs e)
		{
			string cmd = "select * from member where �b��='" + TextBox2.Text + "';";
			sqlcnt.Open();
			SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
			SqlDataReader dr = sqlcmd.ExecuteReader();
			dr.Read();
			if (dr["�K�X"].ToString() == TextBox3.Text)
			{
				Session["�ʺ�"]=dr["�ʺ�"].ToString();
				Session["uname"] = TextBox2.Text;
				Response.Redirect("see_product.aspx?bid=" + bidnum);
			}
			sqlcnt.Close();
		}

		private void Button3_Click(object sender, System.EventArgs e)
		{
			if (Session["uname"]!=null)
			{
				string date=DateTime.Now.ToShortDateString()+" "+DateTime.Now.Hour.ToString()+":"+DateTime.Now.Minute.ToString();
				string cmd = "insert QandA (���s��, �b��, ���D, ���)values ('" + bidnum + "','" + Session["uname"].ToString() + "','" + 
					TextBox1.Text + "','" + date + "');";	
				SqlCommand sqlcmd = new SqlCommand(cmd, sqlcnt);
				sqlcmd.Connection.Open();
				try 
				{
					sqlcmd.ExecuteNonQuery();
				}
				catch (SqlException E)
				{
					if (E.Number == 2627)
						TextBox1.Text = "���~: �㦳�ۦP�D�����䪺��ƿ��w�g�s�b";
					else
						TextBox1.Text = "���~: �L�k��s��ƿ��A�нT�w�U���O�_���w���T��J";
					Label2.Style["color"] = "red";
				}
				
				sqlcmd.Connection.Close();
				BindGrid();

			}
		}
		public void BindGrid()
		{

			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from QandA where ���s��="+bidnum, sqlcnt);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "product");			
			MyDataGrid.DataSource=ds1.Tables["product"].DefaultView;			
			MyDataGrid.DataBind();
		}
		public void BindGrid1()
		{

			SqlDataAdapter myCommand1 = new SqlDataAdapter("select * from buy where ���s��="+bidnum+" ORDER BY �X�� DESC", sqlcnt);		
			DataSet ds1 = new DataSet();			
			myCommand1.Fill(ds1, "product");			
			Datagrid1.DataSource=ds1.Tables["product"].DefaultView;			
			Datagrid1.DataBind();
		}

		private void Button1_Click(object sender, System.EventArgs e)
		{
			Response.Redirect("buy.aspx?money="+Textbox4.Text+"&qty="+Textbox5.Text+"&bid="+bidnum);
		}

		private void Button4_Click(object sender, System.EventArgs e)
		{
			Response.Redirect("buy.aspx?money="+Label4.Text+"&qty="+Textbox6.Text+"&bid="+bidnum);		
		}

		private void show_image()
		{
			SqlCommand cmd = new SqlCommand("select �ӫ~�ԭz, �ӫ~�Ϥ� from product where ���s��='" + bidnum + "'",sqlcnt);
			sqlcnt.Open();
			SqlDataReader dr = cmd.ExecuteReader();
			dr.Read();
			ImageButton2.ImageUrl = "image/" + dr["�ӫ~�Ϥ�"].ToString();
			Label5.Text =  dr["�ӫ~�ԭz"].ToString();
			sqlcnt.Close();
		}
	}
}
