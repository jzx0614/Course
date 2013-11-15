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
	/// update_bid 的摘要描述。
	/// </summary>
	public class update_bid : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.Label Label1;
		protected System.Web.UI.WebControls.DataGrid DataGrid1;
		SqlConnection sqlcnt;
		private void Page_Load(object sender, System.EventArgs e)
		{
			if(Session["group"]==null||(Session["group"].ToString()!="bid"&&Session["group"].ToString()!="root"))
			{
				Response.Redirect("login.aspx");
			}
			sqlcnt = new SqlConnection("server=140.126.11.152;uid=project;pwd=project;database=C09102014");
			if (!IsPostBack)
			{
				reflesh();
			}
			// 在這裡放置使用者程式碼以初始化網頁
		}
		
		#region Web Form 設計工具產生的程式碼
		override protected void OnInit(EventArgs e)
		{
			//
			// CODEGEN: 此為 ASP.NET Web Form 設計工具所需的呼叫。
			//
			InitializeComponent();
			base.OnInit(e);
		}
		
		/// <summary>
		/// 此為設計工具支援所必須的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		private void InitializeComponent()
		{    
			this.DataGrid1.CancelCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_CancelCommand);
			this.DataGrid1.EditCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_EditCommand);
			this.DataGrid1.UpdateCommand += new System.Web.UI.WebControls.DataGridCommandEventHandler(this.DataGrid1_UpdateComand);
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion
		private void DataGrid1_EditCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			DataGrid1.EditItemIndex = (int)e.Item.ItemIndex;
			reflesh();
		}

		private void DataGrid1_CancelCommand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			DataGrid1.EditItemIndex = -1;
			reflesh();
		}

		public void reflesh()
		{
			SqlDataAdapter myCommand = new SqlDataAdapter("select * from bid;", sqlcnt);

			DataSet ds = new DataSet();
			myCommand.Fill(ds, "bid");
			DataGrid1.DataSource=ds.Tables["bid"].DefaultView;
			DataGrid1.DataBind();
		}

		private void DataGrid1_UpdateComand(object source, System.Web.UI.WebControls.DataGridCommandEventArgs e)
		{
			string updateCmd = "UPDATE bid SET  商品新舊 = @newold, 起標價 = @leastprice, 直接購價 = @directprice, ";
			updateCmd+=" 目前出價 = @currentprice,開始時間 = @starttime , 結束時間 = @endtime, 最高出價者 = @highestid, 賣家編號 = @seller, 評價 = @comment, ";
			updateCmd+=" 運費 = @bidcost, 付款方式 = @paytype, 所在地區 = @zone, 交貨方式 = @givenway, 商品黑名單 = @blacklist, 交易守則 = @rules  where 拍賣編號 = @sellid";
			SqlCommand myCommand = new SqlCommand(updateCmd, sqlcnt);
			myCommand.Parameters.Add(new SqlParameter("@sellid", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@newold", SqlDbType.Bit, 1));
			myCommand.Parameters.Add(new SqlParameter("@leastprice", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@directprice", SqlDbType.Int,4));
			myCommand.Parameters.Add(new SqlParameter("@currentprice", SqlDbType.Int,4));
			myCommand.Parameters.Add(new SqlParameter("@starttime", SqlDbType.DateTime, 8));
			myCommand.Parameters.Add(new SqlParameter("@endtime", SqlDbType.DateTime, 8));
			myCommand.Parameters.Add(new SqlParameter("@highestid", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@seller", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@comment", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@bidcost", SqlDbType.Int, 4));
			myCommand.Parameters.Add(new SqlParameter("@paytype", SqlDbType.Text, 16));
			myCommand.Parameters.Add(new SqlParameter("@zone", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@givenway", SqlDbType.VarChar, 50));
			myCommand.Parameters.Add(new SqlParameter("@blacklist", SqlDbType.Bit, 1));
			myCommand.Parameters.Add(new SqlParameter("@rules", SqlDbType.VarChar, 50));
			myCommand.Parameters["@sellid"].Value = DataGrid1.DataKeys[(int)e.Item.ItemIndex];
			string[] cols = {"@sellid","@newold","@leastprice","@directprice","@currentprice","@starttime","@endtime","@highestid","@seller","@comment","@bidcost","@paytype","@zone","@givenway","@blacklist","@rules"};
			int numcols = e.Item.Cells.Count;
			for (int i=2; i< numcols; i++) //skip first, second and last column
			{
				string colvalue = ((TextBox)e.Item.Cells[i].Controls[0]).Text;
				myCommand.Parameters[cols[i-1]].Value = colvalue;
			}
			Label1.Text=updateCmd;
			
			myCommand.Connection.Open();
			try 
			{
				Label1.Text=updateCmd;
				myCommand.ExecuteNonQuery();
				Label1.Text = "<b>已更新資料錄</b><br>" + updateCmd;
				DataGrid1.EditItemIndex = -1;
			}
			catch (SqlException E)
			{
				if (E.Number == 2627)
					Label1.Text = "錯誤: 具有相同主索引鍵的資料錄已經存在";
				else
					Label1.Text = "錯誤: 無法更新資料錄，請確定各欄位是否都已正確填入";
				Label1.Style["color"] = "red";
			}
			myCommand.Connection.Close();
			
			reflesh();
		}
	}
}
