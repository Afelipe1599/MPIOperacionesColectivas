#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
        int size, rank;
        char inmsg;
        char outmsg[5]={'h','o','l','a','!'};
        MPI_Status Status;

        MPI_Init(&argc,&argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (rank != 0){            
            
            MPI_Send(&outmsg[rank-1], 1, MPI_CHAR, 0, 0,MPI_COMM_WORLD);
                
        }else{
            for(int i; i< size; i++){
                        if(rank != i){
                                MPI_Recv(&inmsg, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &Status);
                                printf("Proceso %d recibió el char %c del root %d\n", rank, inmsg, Status.MPI_SOURCE);
                        }
                }
        }

        MPI_Finalize();
}