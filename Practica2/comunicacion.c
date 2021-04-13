#include <stdio.h>
#include <mpi.h>

void presentar_rank(int rank){
    printf("\n+++++++++++++\n");
    printf("El valor de my_rank %d", rank);
    printf("\n+++++++++++++\n");
}

int main(void){
    int comm_sz;
    int my_rank;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);


    if(my_rank==0){

        int n;
        printf("Inserta un número entero para calcular\n");
        scanf("%d", &n);
        printf("\n n=%d\n", n);

        presentar_rank(my_rank);

        MPI_Send(&n, 1 , MPI_INT , 1, 0, MPI_COMM_WORLD);        

        int new_n;
        MPI_Recv(&new_n, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("\n+++++++++++++\n");
        printf("Cuando my_rank = %d, el valor final de n = n + 8 = %d", my_rank, new_n);
        printf("\n+++++++++++++\n");
        
    } else if(my_rank==1){

        
        
        int new_n;
        MPI_Recv(&new_n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        presentar_rank(my_rank);
        printf("\n+++++++++++++\n");
        printf("Cuando my_rank = %d, el valor de n = %d", my_rank, new_n);
        printf("\n+++++++++++++\n");

        int n_squared = new_n*new_n;
        MPI_Send(&n_squared, 1 , MPI_INT, 2, 0, MPI_COMM_WORLD);
        
    } else if(my_rank==2){

        
        
        int new_n;
        MPI_Recv(&new_n, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        presentar_rank(my_rank);
        printf("\n+++++++++++++\n");
        printf("Cuando my_rank = %d, el valor de n = n * n = %d", my_rank, new_n);
        printf("\n+++++++++++++\n");

        int n_plus_2 = new_n +2;
        MPI_Send(&n_plus_2, 1 , MPI_INT, 3, 0, MPI_COMM_WORLD);
        
    }else if(my_rank==3){
        
        int new_n;
        MPI_Recv(&new_n, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        presentar_rank(my_rank);
        printf("\n+++++++++++++\n");
        printf("Cuando my_rank = %d, el valor de n = n + 2 = %d", my_rank, new_n);
        printf("\n+++++++++++++\n");

        int n_plus_8 = new_n + 8;
        MPI_Send(&n_plus_8, 1 , MPI_INT, 0, 0, MPI_COMM_WORLD);
        
    }


    MPI_Finalize();
    return 0;
}