#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "mpi.h"

#define MAX 1000000
#define DEBUG 1
int Compare(const void *a, const void *b) //由小到大
{
  return *(int *)a - *(int *)b;
}

int main(int argc, char *argv[])
{
        int list[MAX],sample[MAX],Pivots[8],send_byte[8],recv_byte[8],local[MAX];
        int myid,n_size,i,j,N,start_list,num,total_recv=0;
        double start_time;
        MPI_Status status;
        MPI_Init(&argc,&argv);
        MPI_Comm_rank(MPI_COMM_WORLD,&myid);
        MPI_Comm_size(MPI_COMM_WORLD,&n_size);
        if(myid==0)
        {
                printf("Input N:\n");
                scanf("%d",&N);
                printf("Input %d list number:\n",N);
                for(i=0;i<N;i++)
                        scanf("%d",&list[i]);
                start_time=MPI_Wtime();
        }
        MPI_Bcast(&N,1,MPI_INT, 0 ,MPI_COMM_WORLD);
        num= (N/n_size);
        start_list = myid * (N /n_size);

	if(myid==0){
                for(i=1;i<n_size;i++)
                         MPI_Send(&list[i* num],num,MPI_INT,i,0,MPI_COMM_WORLD);
        }
        else{
                MPI_Recv(&list[start_list],num,MPI_INT,0,0,MPI_COMM_WORLD,&status);
        }
	qsort(&list[start_list],num,sizeof(int), Compare);

	if(DEBUG){
        	printf("Procsee %d:\n",myid);
        	for(i=start_list;i<start_list+num;i++){
                        printf("%2d ",list[i]);
                }
                printf("\n");
	}

	if(myid!=0)
	{
		int buf[n_size];
		if((num/n_size)==0) 
			buf[0]=list[0];
		else{
			for(i=start_list,j=0;i<start_list+num;i+=(num/n_size))
				buf[j++]=list[i];
		}
		MPI_Send(buf,n_size,MPI_INT,0,0,MPI_COMM_WORLD);
	}
	else{
                if((num/n_size)==0)
                        sample[0]=list[0];
                else{
			for(i=0,j=0;i<num;i+=(num/n_size))
				sample[j++]=list[i];
		}
		for(i=1;i<n_size;i++)
			MPI_Recv(&sample[i*n_size],n_size,MPI_INT,i,0,MPI_COMM_WORLD,&status);
		if(DEBUG){
			printf("Sample:\n");
			for(i=0;i<n_size*n_size;i++){
				printf("%2d ",sample[i]);
			}
			printf("\n");
		}
		
	 	qsort(sample,n_size*n_size,sizeof(int), Compare);
                if(DEBUG){
                        printf("Sort Sample:\n");
                        for(i=0;i<n_size*n_size;i++){
                                printf("%2d ",sample[i]);
                        }
                        printf("\n");
                }		
		for(i=n_size,j=0;i<n_size*n_size;i+=n_size)
		{
			Pivots[j++]=sample[i];
		}
                if(DEBUG){
                        printf("Pivots:\n");
                        for(i=0;i<n_size-1;i++){
                                printf("%2d ",Pivots[i]);
                        }
                        printf("\n");
                }
		
	}

	MPI_Bcast(Pivots,n_size-1,MPI_INT, 0 ,MPI_COMM_WORLD);

	for(i=0;i<n_size;i++) send_byte[i]=0;
	
	for(i=0,j=start_list; j < start_list+num ;j++){

	    if(i < n_size-1){
		if(list[j]<=Pivots[i])
			send_byte[i]++;
		else
			send_byte[++i]++;
	    }
	    else
		send_byte[n_size-1]++;
	}

	for(i=0;i< n_size ;i++){
	    	MPI_Send(&send_byte[i],1,MPI_INT,i,0,MPI_COMM_WORLD);	
	}
	for(i=0;i< n_size ;i++){
        	MPI_Recv(&recv_byte[i],1,MPI_INT,i,0,MPI_COMM_WORLD,&status);
		total_recv+=recv_byte[i];
	}
        if(DEBUG){
	        printf("Process %d: recv\n",myid);
                for(i=0;i<n_size;i++){
                        printf("%2d ",recv_byte[i]);
                }
                printf("\n");
        }

	for(j=0,i=0;i<n_size;i++){
		MPI_Send(&list[j],send_byte[i],MPI_INT,i,0,MPI_COMM_WORLD);
		j+=send_byte[i];
	}

        for(j=0,i=0;i<n_size;i++){
                MPI_Recv(&local[j],recv_byte[i],MPI_INT,i,0,MPI_COMM_WORLD,&status);
                j+=recv_byte[i];
        }

	qsort(local,total_recv,sizeof(int), Compare);

	if(myid==0){
		double end_time=MPI_Wtime();
		printf("Total time: %lf s\n",end_time-start_time);
	}
	if(DEBUG){
		printf("Procsee %d\n",myid);
                for(i=0;i<total_recv;i++){
                        if(i%20==0) printf("\n");
                        printf("%2d ",local[i]);
                }
               printf("\n\n");
	}
	MPI_Finalize();
	return 0;
}
	
