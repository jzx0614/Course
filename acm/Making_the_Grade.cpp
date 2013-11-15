//381
//¤G¸ê¤T¥Ò  Â²§Ó°a  
#include <iostream>
using namespace std;
#include <math.h>
#include <stdio.h>
int main () {
	
	int N,t,x=0;
	int t_point[32][12];
	int bns[12]={0};
	int abst[12]={0};
	double avg[12]={0},adjavg[12]={0},ttt[12];
	int Grade[12]={0},adjGrade[12]={0};
	
	cin>>N;
	for(t=0;t<N;t++)
	{
		int S,T,i,j;
		double mean=0,sd=0;
		cin >> S >> T;

		for(i=0;i<S;i++){
			for(j=0;j<T;j++){
				cin >>t_point[i][j];
			}
			cin>>bns[i];
			cin>>abst[i];
		}

		if(T>2){
			for(i=0;i<S;i++){
				int sum=101;
				for(j=0;j<T;j++){
					if(t_point[i][j]<sum){sum=t_point[i][j];}
					avg[i]+=t_point[i][j];
				}
				avg[i]-=sum;
				avg[i]/=(T-1);
			}
		}
		else{
			for(i=0;i<S;i++){
			for(j=0;j<T;j++){
				avg[i]+=t_point[i][j];
			}
				avg[i]/=T;
			}
		}
		
		for(i=0;i<S;i++){
			mean+=avg[i];
			adjavg[i]=(bns[i]/2)*3+avg[i];
		}	
			mean/=S;

		for(i=0;i<S;i++){
			sd+=pow(avg[i]-mean,2);
		}
		sd/=S;
		sd=pow(sd,0.5);
			
		for(i=0;i<S;i++){
			if(adjavg[i]>=(sd+mean))		
				Grade[i]=4;
			else if((sd+mean)>adjavg[i]&&adjavg[i]>=mean)
				Grade[i]=3;
			else if(mean>adjavg[i]&&adjavg[i]>=(mean-sd))
				Grade[i]=2;
			else if((mean-sd)>adjavg[i])
				Grade[i]=1;
		}
		
		for(i=0;i<S;i++){
			if(abst[i]==0){
				if(Grade[i]!=4)
					adjGrade[i]=Grade[i]+1;
				else
					adjGrade[i]=Grade[i];
			}
			else{
				adjGrade[i]=Grade[i]-(abst[i]/4);
				if(adjGrade[i]<0)
					adjGrade[i]=0;
			}
		}
		double temp=0;
		for(i=0;i<S;i++){
			temp+=adjGrade[i];
		}	temp/=S;
			ttt[x++]=temp;

/* showTable
		cout<<endl;
		for(i=0;i<S;i++){
			for(j=0;j<T;j++){
				cout <<t_point[i][j]<<" ";
			}
			cout<<bns[i]<<" ";
			cout<<abst[i]<<"  ";
			cout<<avg[i]<<" ";
			cout<<adjavg[i]<<" ";
			cout<<Grade[i]<<" "<<adjGrade[i]<<" \n";
			
		}	
		cout <<temp<<" "<<mean<<" "<<sd<<"\n";
*/
                for(i=0;i<S;i++){
                        for(j=0;j<T;j++){
                                t_point[i][j]=0;
                        }
                        bns[i]=0;
                        abst[i]=0;
                        avg[i]=0;
                        adjavg[i]=0;
                        Grade[i]=0;
                        adjGrade[i]=0;
                }


	}
	int i;
	cout<<"MAKING THE GRADE OUTPUT\n";
	for(i=0;i<N;i++){
		printf("%.1lf\n",ttt[i]);		
	}
	cout<<"END OF OUTPUT";
	return 0;
}
