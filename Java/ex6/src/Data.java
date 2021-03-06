


import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.table.*;

public class Data extends JPanel {
    Data(){
   		TableModel model=new Mytable();
		JTable table = new JTable(model);

		JScrollPane userPanelScrollPane = new JScrollPane(table);
		userPanelScrollPane.setPreferredSize(new Dimension(480,220));
		userPanelScrollPane.setViewportView(table);

		InsertButton=new JButton("新增");
        ChangeButton=new JButton("修改");
        SearchButton=new JButton("搜尋");
        DeleteButton=new JButton("刪除");


        add(userPanelScrollPane);
		add(InsertButton);
        add(ChangeButton);
        add(SearchButton);
        add(DeleteButton);

		model.addTableModelListener(new TableHandler());
        ButtonHandler handler= new ButtonHandler();
        InsertButton.addActionListener(handler);
        DeleteButton.addActionListener(handler);
        ChangeButton.addActionListener(handler);
        SearchButton.addActionListener(handler);

    }

    public static void main(String[] args) {
        JFrame myFrame = new JFrame("通 訊 錄");

		myFrame.setSize(500,300);
        myFrame.setLocation(400, 200);
		myFrame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );


		Data demo=new Data();
        myFrame.setContentPane(demo);
        myFrame.setVisible(true);


	}

    private class ButtonHandler implements ActionListener {
     Run run=new Run();
	 public void actionPerformed(ActionEvent e) {

		if(e.getSource()==InsertButton)
            run.Insertion();
        if(e.getSource()==ChangeButton)
			run.SetData();
        if(e.getSource()==SearchButton)
			run.Search();
        if(e.getSource()==DeleteButton)
			run.Deletion();
        Data test=new Data();

     }
    }
    private class TableHandler implements TableModelListener{
      public void tableChanged(TableModelEvent e){

		TableModel model=new Mytable();
		JTable table = new JTable(model);
		JOptionPane.showMessageDialog(null,"@@");
		JScrollPane userPanelScrollPane = new JScrollPane(table);
		userPanelScrollPane.setPreferredSize(new Dimension(480,220));

      }

    }


	private JButton InsertButton,DeleteButton,ChangeButton,SearchButton;

}

class Mytable extends AbstractTableModel{
    	protected LinkedList rowData;

		Mytable(){
            if(rowData==null){
			rowData=(new link()).init();
            }
		}
		private String[] headings=new String []{"學號","姓名","身份字號","電話"};

		public int getRowCount(){return rowData.size();};

        public int getColumnCount() {return headings.length;};

        public String getColumnName(int col){return headings[col];};

        public Object getValueAt(int row, int col){
			return (((Object[])rowData.get(row))[col]) ;
	    }

}
class link{

		LinkedList list ;

		LinkedList init(){
            list= new LinkedList() ;
				Object[] a1={"c09102014","簡志軒","C121184979","0918434538"} ;
				Object[] a2={"c09108030","Jzx","D145186891","0918427747"} ;
				list.add(a1);
                list.add(a2);
				a1=null;
				a2=null ;
			return list ;
		}

		LinkedList adddata(Object[] in){
			list.add(in);
            in=null;
			return list;
		}
}

 class Run extends Mytable{
	String name,num,id,tel;

    public void Insertion() {

		num=JOptionPane.showInputDialog("學號");
        name=JOptionPane.showInputDialog("姓名");
        id=JOptionPane.showInputDialog("身份字號");
        tel=JOptionPane.showInputDialog("電話");
        Object[] in= {num,name,id,tel};

		
	}

    public void Deletion() {
    }

    public void SetData() {
		String num,buff="搜尋失敗，沒有發現這個學號。";
        String[] temp=new String[3];
		num=JOptionPane.showInputDialog("學號");

        for(int i=0;i<getRowCount();i++){
	       	if(getValueAt(i,0).toString().equals(num)){
              	buff="";
				name=JOptionPane.showInputDialog("姓名");
	    	    id=JOptionPane.showInputDialog("身份字號");
		        tel=JOptionPane.showInputDialog("電話");
	    	    Object[] in= {num,name,id,tel};

        	for(int j=1;j<getColumnCount();j++){
			JOptionPane.showMessageDialog(null,in[j].toString()+i+j);
	           setValueAt(in[j],i,j);}
    	    }
    	}
        if(!buff.equals("")) JOptionPane.showMessageDialog(null,buff);



    }

    public void Search() {
		String num,buff="搜尋失敗，沒有發現這個學號。";
		num=JOptionPane.showInputDialog("學號");
		for(int i=0;i<getRowCount();i++){
	       	if(getValueAt(i,0).toString().equals(num)){
    	      buff="有找到資料如下：\n";
        	  for(int j=0;j<getColumnCount();j++)
	            buff+= getValueAt(i,j).toString()+" ";
    	    }
    	}
        JOptionPane.showMessageDialog(null,buff);
    }

    public void check() {
    }
}