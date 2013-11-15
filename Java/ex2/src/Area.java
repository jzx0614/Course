//hw2.1_判斷數的範圍
//data: 2004/03/21
//Programmer: 二資二甲 C09102014 簡志軒

import javax.swing.JOptionPane; //program uses JOptionPane
public class Area {
    public static void main(String args[]) {
        Area homework2_1;		//宣告一個 homework2_1的物件
        homework2_1=new Area();	//起始 homework2_1物件
        homework2_1.inputnum(); //輸入被判斷的值

        if(homework2_1.judgebyte())		 //判斷是否為 byte
			homework2_1.Output("Byte");	 //show出 byte訊息
        else if(homework2_1.judgeshort())//判斷是否為 short
			homework2_1.Output("Short"); //show出 shot訊息
        else if(homework2_1.judgeint())	 //判斷是否為 int
			homework2_1.Output("Int");	 //show出 int訊息
        else							 //之後皆為 long
			homework2_1.Output("Long");	 //show出 long訊息
		System.exit(0);
    }

    public void inputnum() {			 //輸入判斷的數
		string=JOptionPane.showInputDialog("Enter a integer");
        number=Long.parseLong(string);	 //string轉成 long
    }

    public boolean judgebyte() {
        if(-128<=number&&127>=number)	 //byte的範圍
            return true;
        else
            return false;
    }

    public boolean judgeshort() {
        if(-32768<=number&&32767>=number)//short的範圍
        	return true;
        else
            return false;
    }

    public boolean judgeint() {
        if(-2147483648<=number&&2147483647>=number)//int的範圍
            return true;
        else
            return false;
    }
    public void Output(String data) {			   //show出資料型態
        	JOptionPane.showMessageDialog(null,
            "This number is in "+data+" of area.\n");
    }

    private String string;	  					   // 暫存視窗輸入之用
    private long number;

}
