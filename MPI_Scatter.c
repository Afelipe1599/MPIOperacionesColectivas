#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
        int size, rank;
        MPI_Status Stat;
        char inmsg;
        char outmsg[5]={'h','o','l','a','!'};

        MPI_Init(&argc,&argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        if (rank == 0){            
                for(int i; i< size; i++){
                        if(rank != i){
                                MPI_Send(&outmsg[i-1], 1, MPI_CHAR, i, 0,MPI_COMM_WORLD);
                        }
                }
        }else{
                MPI_Recv(&inmsg, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, &Stat);
                printf("Proceso %d recibió el char %c del proceso %d\n", rank, inmsg, Stat.MPI_SOURCE);
        }

        MPI_Finalize();
}
