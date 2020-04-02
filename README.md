# MPIOperacionesColectivas

### 1667639 Andrés Felipe Valencia Montes
### 1631430 Santiago Quintero Pizarro
### 1626057 Miguel Angel Gutierrez Prieto

1)Implementar con las funciones MPI_Send() y MPI_Recv() la funcionalidad de las siguientes funciones:
    
[MPI_Bcast.c](https://github.com/Afelipe1599/MPIOperacionesColectivas/blob/master/MPI_Bcast.c)   

[MPI_Scatter.c](https://github.com/Afelipe1599/MPIOperacionesColectivas/blob/master/MPI_Scatter.c)
    

    
3)Usando la función MPI_Scatter() y MPI_Gather() calcule de manera distribuida el promedio de un vector de tamaño N. A continuación el algoritmo:
	-Genere un arreglo de tamaño N con N números aleatorios.
	-Distribuya el contenido del vector entre todos los procesos que forman parte de la ejecución de la aplicación de modo que a cada proceso le toque la misma cantidad de elementos del vector.
	-Cada proceso calcula su promedio.
	-Se reúne el promedio de cada proceso y se calcula el promedio de esos promedios parciales.
    
[punto3.c](https://github.com/Afelipe1599/MPIOperacionesColectivas/blob/master/punto3.c) 
