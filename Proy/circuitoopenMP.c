#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#define EXTRACT_BIT(n,i) ((n&(1<<i))?1:0)

int check_circuit(int, int);

int main(int argc, char *argv[])
{
    int global_solutions;
    int i;
    int id;
    int hilos;
    int solutions;
    int lo, hi;
    int N = 65536;
    int check_circuit(int, int); //hilos=omp_get_num_threads( );
    global_solutions = 0;
#pragma omp parallel private(lo, hi, id, i, solutions) reduction(+ \
                                                                 : global_solutions)
    {
        hilos = omp_get_num_threads();
        id = omp_get_thread_num();
        lo = id * N / hilos;
        hi = (id + 1) * N / hilos;
        solutions = 0;
        for (i = lo; i < hi; i++)
            solutions += check_circuit(id, i);
        global_solutions += solutions;
    }

    printf("El numero de soluciones es %d\n", global_solutions);
    return 0;
}

int check_circuit(int id, int z)
{
    int v[16]; /* Each element is a bit of z */
    int i;
    for (i = 0; i < 16; i++)
        v[i] = EXTRACT_BIT(z, i);
    if ((v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3]) && (!v[3] || !v[4]) && (v[4] || !v[5]) && (v[5] || !v[6]) && (v[5] || v[6]) && (v[6] || !v[15]) && (v[7] || !v[8]) && (!v[7] || !v[13]) && (v[8] || v[9]) && (v[8] || !v[9]) && (!v[9] || !v[10]) && (v[9] || v[11]) && (v[10] || v[11]) && (v[12] || v[13]) && (v[13] || !v[14]) && (v[14] || v[15]))
    {
        printf("%d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", id, v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11], v[12], v[13], v[14], v[15]);
        fflush(stdout);
        return 1;
    }
    return 0;
}