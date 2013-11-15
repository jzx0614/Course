//hw2.2_耞琌计
//data: 2004/03/21
//Programmer: 戈ヒ C09102014 虏в癮

import javax.swing.JOptionPane;//programmer use JOptionPane.

public class Multiple {
    public static void main(String[] args) {
    	Multiple homework2_2;			// homework2_2ン
        homework2_2 =new Multiple();	//癬﹍ homework2_2ン
		homework2_2.initvalue();		//块ㄢ
        homework2_2.Output();			//show琌计癟
        System.exit(0);
    }

    public void initvalue() {
		string1=JOptionPane.showInputDialog("Enter first number.");
		string2=JOptionPane.showInputDialog("Enter second number.");
		number1=Integer.parseInt(string1);
		number2=Integer.parseInt(string2);
    }

    public boolean checkmultiple() {	//number1埃 number2緇计0
        return (number1%number2==0) ? true : false ;
    }

    public void Output() {
        if(checkmultiple())				//耞琌计
            JOptionPane.showMessageDialog(null,	//计癟
           number1+"  "+number2+"计.");
        else
            JOptionPane.showMessageDialog(null, //ぃ琌计癟
            number1+" ぃ琌 "+number2+"计.");
    }

    private int number1;				//既跌怠块ぇノ
    private int number2;
    private String string1;
    private String string2;
}
