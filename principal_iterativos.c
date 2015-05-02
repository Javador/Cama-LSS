#include "metodos_iterativos.h"
int main(void){

           Matriz* a = aloca_matriz(3,3);
           Matriz* b = aloca_matriz(3,1);
           Matriz* x = aloca_matriz(3,1);
           double erro =0.0000000001;
           double w = 1.058823529;

           a->mat[0][0] = 9;
           a->mat[0][1] = 4;
           a->mat[0][2] = 0;
           a->mat[1][0] = 4;
           a->mat[1][1] = 9;
           a->mat[1][2] = -1;
           a->mat[2][0] = 0;
           a->mat[2][1] = -1;
           a->mat[2][2] = 9;


           b->mat[0][0] = 20;
           b->mat[1][0] = 12;
           b->mat[2][0] = 51;

           x->mat[0][0] = 1;
           x->mat[1][0] = 1;
           x->mat[2][0] = 1;

          imprime_matriz(jacobi(a,b,erro));
          imprime_matriz(gauss_seidel(a,b,erro));

          //falta implementar como achar o w ótimo
          imprime_matriz(sor(a,b,erro,w));

return 0;

}
