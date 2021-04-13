#include <stdio.h>
#include <string.h>
#include <mpi.h>

const int MAX_STRING=100;

int main(void){

    char greeting[MAX_STRING];
    int comm_sz; // numero de procesos
    int my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank( MPI_COMM_WORLD , &my_rank);

    if(my_rank != 0){
        sprintf(greeting, "Holis mundo del proceso %d de %d!", my_rank, comm_sz);
        MPI_Send(greeting, strlen(greeting)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    } else {
        printf("Holis mundo del proceso %d de %d!\n", my_rank, comm_sz);
        for(int q=1; q<comm_sz;q++){
            MPI_Recv( greeting, MAX_STRING, MPI_CHAR, q, 0 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%s\n", greeting);
        }
    }

    MPI_Finalize();
    return 0;
}

// Para compilar
/*
* mpicc -Wall -o holamundo.out holamundo.c
* * Donde:
* * * -Wall -> para que nos muestre warning
* * * -o holamundo.out -> define el nombre del archivo de salida en estra caso "holamundo.out"
* * * holamundo.c -> el nombre de archivo a compilar 
*/

// Para ejecutar 
/*
* mpiexec -n 4 ./holamundo.out
* * Donde
* * * -n 4 -> numero de procesos a generar en este caso 4
* * * ./holamundo.out -> ruta al archivo por ejecutar
*/