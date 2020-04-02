#include <stdio.h>
#include <ctype.h>
#include "mpi.h"

int main(int argc,char *argv[]){
        int size, rank;
        char inmsg;
        char outmsg='x';
        MPI_Status Status;

        MPI_Init(&argc,&argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        if (rank == 0){
                for(int i; i< size; i++){
                        if (i != rank){
                                MPI_Send(&outmsg,1,MPI_CHAR,i,0,MPI_COMM_WORLD);
                                //printf("Soy el root %d y estoy enviando %c a todos los procesos\n",rank, inmsg);
                        }
                }
        }else {
                MPI_Recv(&inmsg, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD,
             &Status);
             printf("Soy un el proceso %d: y recibi %c de root %d\n",
                   rank, outmsg, Status.MPI_SOURCE);
        }

        MPI_Finalize();
}
