#include<stdio.h>
#include<math.h>
#include "mpi.h"

#define MAX 10000000
int main(int argc, char *argv[])
{
	unsigned long i,j,p,max=0,num,total;
	int myid,n_size;
	double start_time;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	MPI_Comm_size(MPI_COMM_WORLD,&n_size);
	start_time=MPI_Wtime();
        unsigned long list[MAX/n_size];
        for(i=0;i<MAX/n_size;i++)
	    list[i]=myid*MAX/n_size+i;
	if(myid==0){
	    printf("MAX: %ld\n",MAX);
	    list[0]=-1;list[1]=-1;
	}
	for(i=2;i*i<MAX;i++){
	    if(myid==i*n_size/MAX){
		if(list[i-(myid*MAX/n_size)]!=-1)	p=i;
		else 					p=-1;
	    }
	    MPI_Bcast(&p, 1, MPI_INT, i*n_size/MAX, MPI_COMM_WORLD);
	    if(p==-1) continue;
	    for(j=0;j<MAX/n_size;j++){
	    	if(list[j]!=-1&&list[j]!=p)
		if(list[j]%p==0) list[j]=-1;
	    }
	}
	num=0;
	
        for(i=0;i<MAX/n_size;i++)
	    if(list[i]!=-1) {
		num++;
		if(myid==n_size-1&&max<list[i]) max=list[i];
	   }
	MPI_Reduce(&num, &total, 1, MPI_INT, MPI_SUM, n_size-1,MPI_COMM_WORLD);
	if(myid==n_size-1) 
		printf("MAXPrime=%d number= %d time=%fs\n"
			,max,total,start_time-MPI_Wtime());
	MPI_Finalize();
	return 0;
}
