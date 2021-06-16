
#include <mpi.h>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
	// Utils vars
	long long contador = 0;
	long long criba = 1000;
	vector<long long> primos;

	// MPI
	int comm_sz;
	int my_rank;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	// Definimos cuantos elementos trabajar en cada proceso
	long long rest = (criba) - (sqrt(criba)) + 1;
	long long elemens = rest / comm_sz;
	long long i_inf = (my_rank * elemens) + sqrt(criba) + 1;
	if (my_rank == comm_sz - 1) // elementos sobrantes para el último proceso
	{
		elemens += rest % comm_sz;
	}

	long long i_sup = i_inf + elemens - 1;

	vector<long long> esprimo(sqrt(criba + 1), 1);
	long long esprimo2[1000010LL];

	for (long long i = 0; i < 1000010LL; ++i)
	{
		esprimo2[i] = 1;
	}

	esprimo[0] = esprimo[1] = 0;
	esprimo2[0] = esprimo2[1] = 0;

	for (long long i = 2; i <= sqrt(criba + 1); ++i)
	{
		if (esprimo[i])
		{
			for (long long j = i * i; j <= sqrt(criba); j += i)
			{
				esprimo[j] = 0;
			}
			primos.push_back(i);

			for (long long j = i_inf; j <= i_sup; j++)
			{
				if (j % i == 0)
				{
					esprimo2[j - i_inf] = 0;
				}
			}
		}
	}

	if (my_rank == 0)
	{
		long long ci;
		long long cs;

		for (long long i = i_inf; i <= i_sup; i++)
		{
			if (esprimo2[i - i_inf])
			{
				// cout << "Del proceso 0 encontramos el primo " << i << endl;
				contador++;
			}
		}

		for (int proceso = 1; proceso < comm_sz; proceso++)
		{

			MPI_Recv(&ci, 1, MPI_LONG_LONG, proceso, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			MPI_Recv(&cs, 1, MPI_LONG_LONG, proceso, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			if (proceso == comm_sz - 1)
			{
				elemens += (rest % comm_sz);
			}

			MPI_Recv(&esprimo2, elemens, MPI_LONG_LONG, proceso, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			for (long long iterador = ci; iterador <= cs; iterador++)
			{
				if (esprimo2[iterador - ci])
				{
					contador++;
					// cout << "Del proceso " << proceso << "encontramos el primo " << iterador << endl;
				}
			}
		}

		for (long long i = 0; i < (int)primos.size(); ++i)
		{
			cout << primos[i] << endl;
			contador++;
		}
		printf("Primos menores a %lld = %lld\n", criba, contador);
	}

	else
	{
		MPI_Send(&i_inf, 1, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD);
		MPI_Send(&i_sup, 1, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD);
		MPI_Send(&esprimo2, elemens, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}