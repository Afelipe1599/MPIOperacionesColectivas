#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


int main(int argc, char** argv) {

        int tamano = atoi(argv[1]);

        MPI_Init(NULL, NULL);
        int rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        int size;
        MPI_Comm_size(MPI_COMM_WORLD, &size);        
        int *nums_rand = NULL;
        if (rank == 0) {
            nums_rand = crearNumAle(tamano * size);
            for(int i = 0; i< (tamano * size); i++){
                printf("array[%d] == %d\n", i, nums_rand[i]);
            }
        }

        int *sub_rand_nums = (int *)malloc(sizeof(int) * tamano);
        MPI_Scatter(nums_rand, tamano, MPI_FLOAT, sub_rand_nums, tamano, MPI_FLOAT, 0, MPI_COMM_WORLD);  

        float sub_avg = promedio(sub_rand_nums, tamano);
        float *sub_avgs = NULL;
        if (rank == 0) {
            sub_avgs = (float *)malloc(sizeof(float) * size);
        }
        MPI_Gather(&sub_avg, 1, MPI_FLOAT, sub_avgs, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);

        if (rank == 0) {
        float avg = promedio(sub_avgs, size);
        printf("Promedio de todos los elementos %f\n", avg);
        
        float original_data_avg = promedio(nums_rand, tamano * size);
        printf("Promedio con los nodos %f\n", original_data_avg);
        }
        if (rank == 0) {
        free(nums_rand);
        free(sub_avgs);
        }
        free(sub_rand_nums);

        MPI_Barrier(MPI_COMM_WORLD);
        MPI_Finalize();        

}

float promedio(float *array, int num_elementos) {
  float suma = 0.f;
  for (int i = 0; i < num_elementos; i++) {
    suma += array[i];
  }
  return suma / num_elementos;
}

float *crearNumAle(int num_elementos) {
  float *nums_rand = (float *)malloc(sizeof(float) * num_elementos);
  for (int i = 0; i < num_elementos; i++){
      nums_rand[i] = (rand() * 0.0000001);
  }
  return nums_rand;
}



