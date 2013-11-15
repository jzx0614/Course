#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

struct p{
	int x;
	int y;	}
    point[20]={{19,67},{22,35},{21,59},{58,85},{87,61},{98,9},{35,45},{63,84},{54,46},{33,98},
                {46,6},{19,83},{38,63},{95,1},{76,82},{77,82},{66,14},{2,16},{51,27},{54,90}};

double R(p point [],int,int);
int main(void)
{   int t1,t2,xx;
    p temp;
    for(int j=0;j<20;j++)
	for(int i=0;i<19;i++){
			if(point[i+1].x <= point[i].x){
			    if(point[i+1].x == point[i].x && point[i+1].y < point[i].y){
			        temp= point[i+1];
                    point[i+1]=point[i];
                    point[i]=temp;
                }    
			    else if(point[i+1].x < point[i].x){
                    temp= point[i+1];
                    point[i+1]=point[i];
                    point[i]=temp;			    
				}				
			}

	}
	for(int z=0;z<20;z++){
     printf("x=%2d y=%2d\n",point[z].x,point[z].y);
	}
    cout<<"dis = "<<R(point,0,19);
    system("PAUSE");

		
    return 0;	
}

double R(p point[20], int start, int end){

	double ans,ans1,ans2,ans3,ans4,dis,buff;
	int low=end,high=start,i,j;
	int num=end-start+1;
	int mid=(start+end)/2;

	if( num > 3){
		ans1 = R(point, start, mid);        //處理前半部份
		ans2 = R(point, mid+1, end);        //處理後半部份 

		if(ans2 < ans1){
		    ans1=ans2;            
		}

		// 合拼 start
		    for(j=mid+1;j<=end;j++){
		          if(point[j].x-point[mid].x>ans1){ 
                        high=j-1;
                        break;
                  }    
            }    
		    for(i=mid-1;i>=start;i--){
		          if(point[mid].x-point[i].x>ans1){
                        low=i+1; 
                        break;
                  }
            }    
  
            for (i=low; i<=mid; i++)
			for (j = mid+1; j<=high; j++)
			{
              if(point[j].x-point[i].x>ans1) break;
	          dis=(point[j].x-point[i].x)*(point[j].x-point[i].x)+
                  (point[j].y-point[i].y)*(point[j].y-point[i].y);
	          buff=pow((double)dis,0.5);
	          if(ans1 > buff) ans1 =buff;
			}
       // 合拼 end 
             return  ans1 ;
		
	}
    else{

	// compute
	    dis=(point[start].x-point[start+1].x)*(point[start].x-point[start+1].x)+
            (point[start].y-point[start+1].y)*(point[start].y-point[start+1].y);
	    ans=pow(dis,0.5);
		for(int i = start ; i < end ;  i++){
			for( int j = start+1 ; j <= end ; j++){
				if(i > j){
					dis=(point[i].x-point[j].x)*(point[i].x-point[j].x)+
                        (point[i].y+point[j].y)*(point[i].y+point[j].y);
					if(pow(dis,0.5)<ans)  ans=pow(dis,0.5);
					}
			}
		}
		return ans;
    }	
}

