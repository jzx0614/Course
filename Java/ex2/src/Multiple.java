//hw2.2_�P�_�O�_������
//data: 2004/03/21
//Programmer: �G��G�� C09102014 ²�Ӱa

import javax.swing.JOptionPane;//programmer use JOptionPane.

public class Multiple {
    public static void main(String[] args) {
    	Multiple homework2_2;			//�ŧi�@�� homework2_2����
        homework2_2 =new Multiple();	//�_�l homework2_2����
		homework2_2.initvalue();		//��J��ӭ�
        homework2_2.Output();			//show�O�_�����ƪ��T��
        System.exit(0);
    }

    public void initvalue() {
		string1=JOptionPane.showInputDialog("Enter first number.");
		string2=JOptionPane.showInputDialog("Enter second number.");
		number1=Integer.parseInt(string1);
		number2=Integer.parseInt(string2);
    }

    public boolean checkmultiple() {	//number1���H number2���l�Ƭ�0
        return (number1%number2==0) ? true : false ;
    }

    public void Output() {
        if(checkmultiple())				//�P�_�O�_������
            JOptionPane.showMessageDialog(null,	//�����ƪ��T��
           number1+" �� "+number2+"������.");
        else
            JOptionPane.showMessageDialog(null, //���O���ƪ��T��
            number1+" ���O "+number2+"������.");
    }

    private int number1;				//�Ȧs������J����
    private int number2;
    private String string1;
    private String string2;
}
