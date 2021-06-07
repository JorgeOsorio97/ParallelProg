#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solver(int *arreglo);

int main(void){
    int test[16] = {
        0,1,1,1,
        1,1,1,1,
        1,1,1,1,
        1,1,1,1,
    };
    int res = solver(test);
    printf("%d\n", res);
    return 0;
}

int solver(int *arreglo){

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
    int _d_e = _d || _b;
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
    int f_gh_i = fg && h_i;
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