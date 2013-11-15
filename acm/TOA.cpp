//10333
//¤G¸ê¤T¥Ò  Â²§Ó°a 
#include <iostream>
using namespace std;

int main(){
	int H,T=1;
	while(cin>>H){
		cout<<"Tower #"<<T<<endl;
		int right,v_right=0,left,v_left;
		int temp=H;
		
		for(left=0;temp>left;left++){
			temp-=left+1;
		}
		if(temp==0)	v_left=left;
		else  v_left=temp+left;

		right=left-1;
		v_right=H-((1+(left-2))*(left-2)/2);
		
		int x=0,l_sharp=1,l_b_sharp=0,r_sharp=1,r_b_sharp=0;
		int i,j,k,y;
		if(right==1) {r_sharp=v_right;}
		for(i=0;i<H;){
//left

			for(k=0;k<l_sharp;k++){
				for(j=0;j<(left-l_sharp)*2;j++)	cout<<" ";
				if(k==0){
					cout<<"#**";
					j=2;
				}
				else{
					cout<<"#";
					j=0;
				}
				for(;j<(2*l_b_sharp)+2;j++)	cout<<".";
				
				if(x>=r_sharp){	
					x=0;
		                        r_b_sharp=r_sharp;
	        	                if(right==r_sharp+1) r_sharp=v_right;
                		        else    r_sharp++;
				}
                                        if(x==0) y=2;
                                        else y=0;
                                        for(;y<(2*r_b_sharp)+2;y++)
                                                cout<<".";

                                        if(x==0)        cout<<"**#";
                                        else    cout<<"#";
                                        x++;
				cout<<endl; i++;
			}	

			l_b_sharp=l_sharp;
			if(left==l_sharp+1) l_sharp=v_left;
			else	l_sharp++;
//left end
		}
		cout<<endl;
		T++;
	}
	return 0;
}
