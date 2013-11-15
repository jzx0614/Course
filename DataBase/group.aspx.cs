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
	/// group 的摘要描述。
	/// </summary>
	public class group : System.Web.UI.Page
	{
		protected System.Web.UI.WebControls.HyperLink member;
		protected System.Web.UI.WebControls.HyperLink HyperLink4;
		protected System.Web.UI.WebControls.HyperLink HyperLink1;
		protected System.Web.UI.WebControls.HyperLink HyperLink2;
		protected System.Web.UI.WebControls.HyperLink product;
		protected System.Web.UI.WebControls.HyperLink HyperLink3;
		protected System.Web.UI.WebControls.HyperLink HyperLink6;
		protected System.Web.UI.WebControls.HyperLink HyperLink5;
	
		private void Page_Load(object sender, System.EventArgs e)
		{
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
			this.Load += new System.EventHandler(this.Page_Load);

		}
		#endregion


	}
}
