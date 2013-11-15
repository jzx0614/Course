#include "mpi.h" 
#include <stdio.h> 
#include <math.h> 

#define DEBUG 1

int main( int argc, char *argv[] ) 
{ 
    int n, myid, numprocs, i; 
    double PI25DT = 3.141592653589793238462643; 
    double mypi, pi, h, sum, x, start_time; 
    MPI_Status status;
    MPI_Init(&argc,&argv); 
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs); 
    MPI_Comm_rank(MPI_COMM_WORLD,&myid); 
    while(1){
    	if (myid == 0) { 
        	printf("Enter the number of intervals: (0 quits) "); 
        	scanf("%d",&n); 
    		start_time=MPI_Wtime();
		for(i=1;i<numprocs;i++)
		    	MPI_Send(&n,1,MPI_INT,i,0,MPI_COMM_WORLD);
    	} 
    	else 
		MPI_Recv(&n,1,MPI_INT,0,0,MPI_COMM_WORLD,&status);
	
    	if (n==0)	break;

        h   = 1.0 / (double) n; 
        sum = 0.0; 
        for (i = myid + 1; i <= n; i += numprocs) { 
            x = h * ((double)i - 0.5); 
            sum += (4.0 / (1.0 + x*x)); 
        } 
        mypi = h * sum; 
	pi=0;
	if (myid !=0)
	    MPI_Send(&mypi,1,MPI_DOUBLE,0,0,MPI_COMM_WORLD);
	else{
	    for(i=1;i<numprocs;i++){
		double tmp;
	    	MPI_Recv(&tmp,1,MPI_DOUBLE,i,0,MPI_COMM_WORLD,&status);
		pi+=tmp;
	    }
	    pi+=mypi;
            printf("pi is approximately %.16f, Error is %.16f\n", 
                       pi, fabs(pi - PI25DT)); 
	    printf("cost time: %fs\n",MPI_Wtime()-start_time);
	}
    } 
    MPI_Finalize(); 
    return 0; 
} 
