#include <stdio.h>
#include <mpi.h>


int main(void){
    int comm_sz;
    int my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if(my_rank==0){

        for(int q=1; q<comm_sz; q++){
            MPI_Send(&q /*&buf*/, 1 /*count*/, MPI_INT /*MPI DataType*/, q/*dest*/, 0/*tag*/, MPI_COMM_WORLD/*MPI comm*/);
        }

        printf("\n+++++++++++++\n");
        printf("El valor de my_rank %d", my_rank);
        printf("\n+++++++++++++\n");
        
        for(int q=1; q<comm_sz; q++){
            int res;
            MPI_Recv(&res /*&buf*/, 1/*count*/, MPI_INT/*MPI DataType*/, q/*source*/, 0/*tag*/, MPI_COMM_WORLD/*MPI comm*/, MPI_STATUS_IGNORE/*&status*/);
            printf("Se imprime el resultado %d\n", res);
        }
    }
    else{
        int entero;
        printf("\n==============\n");
        printf("El valor de my_rank %d", my_rank);
        printf("\n==============\n");

        MPI_Recv(&entero, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int cuadrado = entero * entero;
        MPI_Send(&cuadrado, 1, MPI_INT , 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}