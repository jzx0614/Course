//hw2.1_�P�_�ƪ��d��
//data: 2004/03/21
//Programmer: �G��G�� C09102014 ²�Ӱa

import javax.swing.JOptionPane; //program uses JOptionPane
public class Area {
    public static void main(String args[]) {
        Area homework2_1;		//�ŧi�@�� homework2_1������
        homework2_1=new Area();	//�_�l homework2_1����
        homework2_1.inputnum(); //��J�Q�P�_����

        if(homework2_1.judgebyte())		 //�P�_�O�_�� byte
			homework2_1.Output("Byte");	 //show�X byte�T��
        else if(homework2_1.judgeshort())//�P�_�O�_�� short
			homework2_1.Output("Short"); //show�X shot�T��
        else if(homework2_1.judgeint())	 //�P�_�O�_�� int
			homework2_1.Output("Int");	 //show�X int�T��
        else							 //����Ҭ� long
			homework2_1.Output("Long");	 //show�X long�T��
		System.exit(0);
    }

    public void inputnum() {			 //��J�P�_����
		string=JOptionPane.showInputDialog("Enter a integer");
        number=Long.parseLong(string);	 //string�ন long
    }

    public boolean judgebyte() {
        if(-128<=number&&127>=number)	 //byte���d��
            return true;
        else
            return false;
    }

    public boolean judgeshort() {
        if(-32768<=number&&32767>=number)//short���d��
        	return true;
        else
            return false;
    }

    public boolean judgeint() {
        if(-2147483648<=number&&2147483647>=number)//int���d��
            return true;
        else
            return false;
    }
    public void Output(String data) {			   //show�X��ƫ��A
        	JOptionPane.showMessageDialog(null,
            "This number is in "+data+" of area.\n");
    }

    private String string;	  					   // �Ȧs������J����
    private long number;

}
