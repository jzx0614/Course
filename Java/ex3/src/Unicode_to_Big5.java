// Ex 3_2:Unicode to Big5
// Date: 2004/04/12
// Programmer:²�Ӱa
// class:�G��G��
// number:c09102014

import javax.swing.JOptionPane;

public class Unicode_to_Big5 {

    public static void main(String[] args) {
		Unicode_to_Big5 hw3_2;
        hw3_2 = new Unicode_to_Big5();
        hw3_2.Inputunicode();
        hw3_2.convert_big5();
        hw3_2.displaymessage();
        System.exit(0);
    }

    public void Inputunicode() {
        string=JOptionPane.showInputDialog("�п�J�@�� unicode��: ");
		big5num=Integer.parseInt(string,16);
    }

    public void convert_big5() {
		output=(char)big5num;
    }

    public void displaymessage() {
        JOptionPane.showMessageDialog(null,
        "'"+string+"' �� Big5���G "+output);
    }
	private String string;
    private int big5num;
    private char output;
}
