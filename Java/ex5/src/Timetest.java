/* Generated by Together */

import javax.swing.JOptionPane;
import java.util.*;

public class Timetest{
    public static void main(String[] args) {
		Timetest hw5_1=new Timetest();
		hw5_1.testadd();
        hw5_1.show();
        System.exit(0);
    }

    public Timetest() {
        long1=12345;
        long2=45678;
        double1=12345.0;
        double2=45678.0;

    }

    public void show() {
        JOptionPane.showMessageDialog(null,output);
    }

    public void testadd() {
		Timer t=new Timer();
        output="";
		for(int i=0;i<4;i++){
			t.restart();
		    for(int j=0;j<10000000;j++){
//				switch(i){
//                case 0:
                    long1+=long2;break;
/*				case 1: long1-=long2;break;
                case 2: long1*=2;break;
                case 3: long1/=100;break;*/
//                default: break;
//                }
            }
            output+=long1+" "+long2+" "+t.elapsed()+"\n";
        }
    }

    private String output;
    private long long1;
    private long long2;
    private double double1;
    private double double2;
}
