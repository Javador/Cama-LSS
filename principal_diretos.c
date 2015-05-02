#include "metodos_diretos.h"
int main(void){

           Matriz* a = aloca_matriz(3,3);
           Matriz* b = aloca_matriz(3,1);
           Matriz* x = aloca_matriz(3,1);

           a->mat[0][0] = 1;
           a->mat[0][1] = 0;
           a->mat[0][2] = 0;
           a->mat[1][0] = 1;
           a->mat[1][1] = 1;
           a->mat[1][2] = 0;
           a->mat[2][0] = 1;
           a->mat[2][1] = 1;
           a->mat[2][2] = 1;

           imprime_matriz(a);

           printf("%d",is_triangular_inferior(a));

//           a->mat[0][0] = 1;
//           a->mat[0][1] = 1;
//           a->mat[0][2] = 0;
//           a->mat[1][0] = 1;
//           a->mat[1][1] = 2;
//           a->mat[1][2] = -1;
//           a->mat[2][0] = 0;
//           a->mat[2][1] = -1;
//           a->mat[2][2] = 3;


//           b->mat[0][0] = 2;
//           b->mat[1][0] = 1;
//           b->mat[2][0] = 5;
//
//           x->mat[0][0] = 1;
//           x->mat[1][0] = 1;
//           x->mat[2][0] = 1;

//---------------------------------------------------------

//           Matriz* a = aloca_matriz(4,4);
//           Matriz* b = aloca_matriz(4,1);
//           Matriz* x = aloca_matriz(4,1);
//
//           a->mat[0][0] = 2;
//           a->mat[0][1] = -1;
//           a->mat[0][2] = 0;
//           a->mat[0][3] = 0;
//           a->mat[1][0] = -1;
//           a->mat[1][1] = 2;
//           a->mat[1][2] = -1;
//           a->mat[1][3] = 0;
//           a->mat[2][0] = 0;
//           a->mat[2][1] = -1;
//           a->mat[2][2] = 2;
//           a->mat[2][3] = -1;
//           a->mat[3][0] = 0;
//           a->mat[3][1] = 0;
//           a->mat[3][2] = -1;
//           a->mat[3][3] = 2;
//
//
//           b->mat[0][0] = 1;
//           b->mat[1][0] = 0;
//           b->mat[2][0] = 0;
//           b->mat[3][0] = 1;
//
//           x->mat[0][0] = 1;
//           x->mat[1][0] = 1;
//           x->mat[2][0] = 1;
//           x->mat[3][0] = 1;


//           printf("solucao CROUT \n");
//           imprime_matriz(solver(a,x,b,CROUT,decomposicao_crout));
//           printf("\n");
//
//
//           printf("solucao LU \n");
//           imprime_matriz(solver(a,x,b,LU,decomposicao_lu));
//           printf("\n");
//
//
//           printf("solucao CHOLESKY \n");
//           imprime_matriz(solver(a,x,b,CHOLESKY,decomposicao_cholesky));
//           printf("\n");
//
//           printf("solucao LDLT \n");
//           imprime_matriz(solver(a,x,b,LDLT,decomposicao_ldlt));
//           printf("\n");


return 0;

}
