// Ex 3_3:StringDemo
// Date: 2004/04/12
// Programmer:Â²§Ó°a
// class:¤G¸ê¤G¥Ò
// number:c09102014

import javax.swing.JOptionPane;


public class StringDemo {
    public static void main(String[] args) {
		StringDemo hw3_3= new StringDemo();
		hw3_3.Input();
		hw3_3.usejavastring();
        hw3_3.display();
        System.exit(0);
    }

    public void Input() {
		string1=JOptionPane.showInputDialog("Input string1: ");
        string2=JOptionPane.showInputDialog("Input string2: ");
        output="string1= "+string1+"\nstring2= "+string2;
    }

    public void usejavastring() {
        char buff[]={'1','2','3'};
        int num=54;
		output+="\n\nstartsWith( ): "+string1.startsWith(string2);
        output+="\ncopyVauleOf( ): "+string1.copyValueOf(buff);
		output+="\nvauleOf( ): "+string1.valueOf(num);
       	output+="\nlastIndexof( ): "+string1.lastIndexOf(string2);
        output+="\ntoLowCase( ): "+string1.toLowerCase();

    }

    public void display() {
        JOptionPane.showMessageDialog(null,output);
    }

    private String string1;
    private String string2;
    private String output;
}
