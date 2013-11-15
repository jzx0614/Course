// Ex 3_1: Big5 to Unicode
// Date: 2004/04/12
// Programmer:簡志軒
// class:二資二甲
// number:c09102014

import javax.swing.JOptionPane;

public class Big5_to_Unicode {
    public static void main(String[] args) {
		Big5_to_Unicode hw3;
        hw3 = new Big5_to_Unicode();
        hw3.Inputword();
        hw3.convert_unicode();
        hw3.displaymessage();
        System.exit(0);
    }

    public void Inputword() {
        String string;
        string=JOptionPane.showInputDialog("請輸入一個中文: ");
        word=string.charAt(0);
    }

    public void convert_unicode() {
        int code;
        code=(int)word;
		output=Integer.toHexString(code);
        output=output.toUpperCase();
    }

    public void displaymessage() {
        JOptionPane.showMessageDialog(null,
        "'"+word+"' 的 unicode為： "+output);
    }
	private char word;
    private String output;
}
