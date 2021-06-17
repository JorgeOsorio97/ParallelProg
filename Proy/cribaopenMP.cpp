#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <omp.h>
using namespace std;

long long tamanio_criba = 1000;
vector<int> esPrimo(tamanio_criba);
vector<long long> listaPrimos;

int main(void)
{
    int thread_count = omp_get_num_threads();

    for (int i = 0; i < tamanio_criba; i++)
    {
        esPrimo[i] = 1;
    }

    esPrimo[0] = esPrimo[1] = 1;
    listaPrimos.clear();

    for (long long i = 2; i <= tamanio_criba + 1; i++)
    {
        if (esPrimo[i])
        {
            #pragma omp parallel for num_threads(thread_count)
            for (long long j = i * i; j <= tamanio_criba + 1; j += i)
            {
                esPrimo[j] = 0;
            }
            listaPrimos.push_back(i);
        }
    }

    printf("Primos menores o iguales a %lld - %ld\n", tamanio_criba, listaPrimos.size());
    return 0;
}
