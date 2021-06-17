#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <omp.h>
using namespace std;

vector<long long> primos;
long long criba = 1000;
vector<int> esPrimo(criba);

int main(void)
{
    int thread_count = omp_get_num_threads();

    for (int i = 0; i < criba; i++)
    {
        esPrimo[i] = 1;
    }

    esPrimo[0] = esPrimo[1] = 1;
    primos.clear();

    for (long long i = 2; i <= criba + 1; i++)
    {
        if (esPrimo[i])
        {
            #pragma omp parallel for num_threads(thread_count)
            for (long long j = i * i; j <= criba + 1; j += i)
            {
                esPrimo[j] = 0;
            }
            primos.push_back(i);
        }
    }

    printf("Primos menores o iguales a %lld - %ld\n", criba, primos.size());
    for(int i=0; i<primos.size(); i++){
        printf("%lld - ", primos[i]);
    }
    return 0;
}
