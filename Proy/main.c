#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <mpi.h>
#include <math.h>

int solver(int *arreglo);

int main(void)
{
    // MPI
    // int comm_sz;
    // int my_rank;
    // MPI_Init(NULL, NULL);
    // MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    // MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // if (comm_sz != 4)
    // {
    //     printf("Por ahora el programa solo se paraleliza en 4");
    //     return 1;
    // }

    int big_size = pow(2, 16);
    printf("big_size: %d", big_size);
    int all_options[big_size][16];
    int counter = 0;

    for (int a = 0; a <= 1; a++)
    { //1
        int aux[16];
        aux[0] = a;
        for (int b = 0; b <= 1; b++)
        { //2
            aux[1] = b;
            for (int c = 0; c <= 1; c++)
            { //3
                aux[2] = c;
                for (int d = 0; d <= 1; d++)
                { //4
                    aux[3] = d;
                    for (int e = 0; e <= 1; e++)
                    { //5
                        aux[4] = e;
                        for (int f = 0; f <= 1; f++)
                        { //6
                            aux[5] = f;
                            for (int g = 0; g <= 1; g++)
                            { //7
                                aux[6] = g;
                                for (int h = 0; h <= 1; h++)
                                { //8
                                    aux[7] = h;
                                    for (int i = 0; i <= 1; i++)
                                    { //9
                                        aux[8] = i;
                                        for (int j = 0; j <= 1; j++)
                                        { //10
                                            aux[9] = j;
                                            for (int k = 0; k <= 1; k++)
                                            { //11
                                                aux[10] = k;
                                                for (int l = 0; l <= 1; l++)
                                                { //12
                                                    aux[11] = l;
                                                    for (int m = 0; m <= 1; m++)
                                                    { //13
                                                        aux[12] = m;
                                                        for (int n = 0; n <= 1; n++)
                                                        { //14
                                                            aux[13] = n;
                                                            for (int o = 0; o <= 1; o++)
                                                            { //15
                                                                aux[14] = o;
                                                                for (int p = 0; p <= 1; p++)
                                                                { //16
                                                                    aux[15] = p;
                                                                    for (int z = 0; z < 16; z++)
                                                                    {
                                                                        all_options[counter][z] = aux[z];
                                                                    }

                                                                    counter++;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    printf("counter: %d\n", counter);

    for (int i = 0; i < big_size; i++)
    {
        if (solver(all_options[i]))
        {
            printf("index: %d, is_good: %d \n", i, solver(all_options[i]));
        }
    }

    // for (int j = 0; j < 15; j++)
    // {
    //     printf('%d - ', all_options[0][j]);
    // }

    // for(int i=0; i<big_size; i++){
    //     if(i<10 || i>= big_size-10){
    //         for(int j=0; j<16; j++){
    //             printf('%d - ', all_options[i][j]);
    //         }
    //         printf('\n');
    //     }
    // }

    // if (my_rank == 0)
    // {
    // }
    // int test[16] = {
    //     0,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    //     1,
    // };
    // int res = solver(test);
    // printf("%d\n", res);

    return 0;
}

int solver(int *arreglo)
{

    // longitud 1
    int a = arreglo[0];
    int b = arreglo[1];
    int c = arreglo[2];
    int d = arreglo[3];
    int e = arreglo[4];
    int f = arreglo[5];
    int g = arreglo[6];
    int h = arreglo[7];
    int i = arreglo[8];
    int j = arreglo[9];
    int k = arreglo[10];
    int l = arreglo[11];
    int m = arreglo[12];
    int n = arreglo[13];
    int o = arreglo[14];
    int p = arreglo[15];

    // negaciones longitud 1
    int _b = !b;
    int _d = !d;
    int _e = !e;
    int _f = !f;
    int _g = !g;
    int _h = !h;
    int _i = !i;
    int _j = !j;
    int _k = !k;
    int _n = !n;
    int _o = !o;
    int _p = !p;

    // longitud 2
    int ab = a || b;
    int cd = c || d;
    int _b_d = _b || _d;
    int _d_e = _d || _e;
    int e_f = e || _f;
    int fg = f || g;
    int f_g = f || _g;
    int h_i = h || _i;
    int _h_n = _h || _n;
    int ij = i || j;
    int i_j = i || _j;
    int _j_k = _j || _k;
    int kl = k || l;
    int lj = l || j;
    int mn = m || n;
    int n_o = n || _o;
    int op = o || p;
    int _pg = _p || g;

    // longitud 4
    int ab_b_d = ab && _b_d;
    int cd_d_e = cd && _d_e;
    int e_ffg = e_f && fg;
    int f_gh_i = f_g && h_i;
    int iji_j = ij && i_j;
    int _j_kkl = _j_k && kl;
    int ljmn = lj && mn;
    int op_pg = op && _pg;

    // longitud 6
    int n_oop_pg = n_o && op_pg;

    // longitud 8
    int ab_b_dcd_d_e = ab_b_d && cd_d_e;
    int e_ffgf_gh_i = e_ffg && f_gh_i;
    int iji_j_j_kkl = iji_j && _j_kkl;
    int _h_nn_oop_pg = _h_n && n_oop_pg;

    // longitud 12
    int ljmn_h_nn_oop_pg = ljmn && _h_nn_oop_pg;

    // longitud 16
    int ab_b_dcd_d_ee_ffgf_gh_i = ab_b_dcd_d_e && e_ffgf_gh_i;

    // longitud 20
    int iji_j_j_kklljmn_h_nn_oop_pg = iji_j_j_kkl && ljmn_h_nn_oop_pg;

    // resultado
    int res = ab_b_dcd_d_ee_ffgf_gh_i && iji_j_j_kklljmn_h_nn_oop_pg;
    return res;
}