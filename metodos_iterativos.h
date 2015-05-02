#include "matrizes.h"

/*
* Método de jacobi para a aproximação de soluções para sistemas lineares
* entradas matriz A com as variaveis do sistema, matriz B com os valores do sistema e o erro admitido
*/
Matriz* jacobi(Matriz* A, Matriz* b, double erro){

    int counter =0;
    Matriz *resp = aloca_matriz(A->m,1);
    zera_matriz(resp);

    double erro_aux = 0;
    double diferencas[b->m];

   do{

      int i = 0;
      Matriz * aux = clone(resp);
      for(; i < A->m ; i++){

            double resp_ant = aux->mat[i][0];
            double temp=0;
            int j = 0;

            for(;j < A->n ; j++){

                if(i != j){
                  temp += ((A->mat[i][j]*resp->mat[j][0])*-1);
                }

            }
            aux->mat[i][0] = temp + b->mat[i][0];
            temp =0;
            aux->mat[i][0] = aux->mat[i][0]/A->mat[i][i];

            diferencas[i] = abs_double(aux->mat[i][0] - resp_ant);

      }
      libera_matriz(resp);
      resp = aux;

       //calculo do erro, utilizei o erro relativo como métrica
      erro_aux = abs_double(valor_maximo(diferencas,A->m))/abs_double(valor_maximo_vet_col(resp->mat,resp->m));
      counter++;
    } while(erro_aux > erro);

    printf("jacobi utilizou %d it \n",counter);

  return resp;

}


/*
* Método de gauss seidel para a aproximação de soluções para sistemas lineares
* entradas matriz A com as variaveis do sistema, matriz B com os valores do sistema e o erro admitido
*/
Matriz* gauss_seidel(Matriz* A,Matriz* b, double erro){

    Matriz *resp = aloca_matriz(A->m,1);
    zera_matriz(resp);

    int counter = 0;
    double erro_aux = 0;
    double diferencas[b->m];

   do{

     int i = 0;
      for(; i < A->m ; i++){

            double resp_ant = resp->mat[i][0];
            double temp=0;
            int j = 0;

            for(;j < A->n ; j++){
                if(i != j){
                  temp += ((A->mat[i][j]*resp->mat[j][0])*-1);
                }
            }
            resp->mat[i][0] = temp + b->mat[i][0];
            temp = 0;
            resp->mat[i][0] = resp->mat[i][0] / A->mat[i][i];

            diferencas[i] = abs_double(resp->mat[i][0] - resp_ant);

      }
      //calculo do erro, utilizei o erro relativo como métrica
      erro_aux = abs_double(valor_maximo(diferencas,A->m))/abs_double(valor_maximo_vet_col(resp->mat,resp->m));
      counter++;
    } while(erro_aux > erro);

    printf("o gauss seidel utilizou %d it \n",counter);
  return resp;

}

Matriz* sor(Matriz* A,Matriz* b, double erro,double w){

   Matriz *resp = aloca_matriz(A->m,1);
    zera_matriz(resp);

    int counter = 0;
    double erro_aux = 0;
    double diferencas[b->m];

   do{

     int i = 0;
      for(; i < A->m ; i++){

            double resp_ant = resp->mat[i][0];
            double temp=0;
            int j = 0;

            for(;j < A->n ; j++){
                if(i != j){
                  temp += ((A->mat[i][j]*resp->mat[j][0])*-1);
                }
            }
            resp->mat[i][0] = temp + b->mat[i][0];
            temp = 0;
            resp->mat[i][0] = (1-w)*resp->mat[i][0]+(resp->mat[i][0] * w/A->mat[i][i]);

            diferencas[i] = abs_double(resp->mat[i][0] - resp_ant);

      }
      //calculo do erro, utilizei o erro relativo como métrica
      erro_aux = abs_double(valor_maximo(diferencas,A->m))/abs_double(valor_maximo_vet_col(resp->mat,resp->m));
      counter++;
    } while(erro_aux > erro);

    printf("o SOR utilizou %d it \n",counter);
  return resp;
}
