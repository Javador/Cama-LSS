#include "matrizes.h"
#define LU 0
#define CHOLESKY 1
#define LDLT 2
#define QR 3
#define CROUT 4

//funçao para decompor a matriz A em L D
//retorna as matrizes L na posição [0] e D na posição [1]
Matriz** decomposicao_ldlt(Matriz * a){

    int m = a->m;
    double *vet = malloc(sizeof(double)*m-1);
    Matriz* L = aloca_matriz(a->m,a->n);
    Matriz* D = aloca_matriz(a->m,a->n);
    Matriz** retorno = (Matriz**)malloc(sizeof(Matriz*)*2);
    zera_matriz(L);
    zera_matriz(D);


    int i =0;
    for(;i < m;i++){

        int j =0;
        for(;j < i;j++){
            vet[j] =L->mat[i][j]*D->mat[j][j];
        }

        double aux =0;
        for(j =0;j<i;j++){

            aux += L->mat[i][j]*vet[j];
        }
        D->mat[i][i] = a->mat[i][i] - aux;


        for(j = i ;j < m;j++){

            int k =0;
            double aux2 =0;
            for(;k < i;k++){

                aux2 += L->mat[j][k]*vet[k];

            }
            L->mat[j][i] = 1/D->mat[i][i]*(a->mat[j][i] - aux2);
        }
    }

free(vet);
retorno[0] = L;
retorno[1] = D;

return retorno;
}

//funcao para decompor a matriz A em R
// retorna a matriz R  na posicao[0]
Matriz** decomposicao_cholesky(Matriz* a){

    int m = a->m;
    int n = a->n;

    Matriz** resultado = (Matriz**)malloc(sizeof(Matriz*)*1);
    Matriz* R = aloca_matriz(a->m,a->n);
    zera_matriz(R);
//caso trivial
     R->mat[0][0] = sqrt(a->mat[0][0]);
//---------------------------------------------
     int j =1;
     for(;j < m;j++){
        R->mat[j][0] = a->mat[j][0]/R->mat[0][0];
     }
//---------------------------------------------

    int i =1;
    double aux = 0;
    for(;i < m-1  ;i++){
          int k =0;
          for(;k < i;k++){
            aux += pow(R->mat[i][k],2);
          }
           R->mat[i][i] = sqrt(a->mat[i][i] - aux) ;

    j = i+1;
    for(;j < m;j++){

        int k =0;
        double aux2 = 0;
        for(;k < i;k++){

            aux2 += R->mat[j][k]*R->mat[i][k];
        }
        R->mat[j][i] = 1/R->mat[i][i]*(a->mat[j][i] - aux2);
    }

    }


       int k =0;
       double aux3 =0;
       double temp =0;
       for(;k < m;k++){
            aux3 += pow(R->mat[m-1][k],2);
       }
       temp = a->mat[m-1][m-1] -aux3;
       R->mat[m-1][m-1] = sqrt(temp);

resultado[0] = R;

return resultado;
}
// funcao que decompoe a matriz A em L e U
// retorna as matrizes L na posicao [0] e U na posicao[1]
Matriz** decomposicao_lu(Matriz* a){

    int n = a->m;
    Matriz* a_aux= clone(a);
    Matriz* L = aloca_matriz(a->m,a->n);
    Matriz* U = aloca_matriz(a->m,a->n);
    Matriz** resultado = (Matriz**)malloc(sizeof(Matriz*)*2);
    zera_matriz(L);
    zera_matriz(U);


    int k = 0;
    for(; k < n ;k++){

            U->mat[k][k] = a_aux->mat[k][k];

            int i = 0;
            for(i = k ; i < n; i++){

                L->mat[i][k] = a_aux->mat[i][k]/U->mat[k][k];
                U->mat[k][i] = a_aux->mat[k][i];
            }

            for(i = k;i < n;i++){

                int j =0;
                for(j =k;j < n;j++){

                        a_aux->mat[i][j] =a_aux->mat[i][j] - L->mat[i][k]*U->mat[k][j];
                }
            }
    }

libera_matriz(a_aux);
resultado[0] = L;
resultado[1] = U;

return resultado;
}
Matriz** decomposicao_crout(Matriz* a){

   int n = a->m;
   Matriz* L = aloca_matriz(a->m,a->n);
   Matriz* U = aloca_matriz(a->m,a->n);
   Matriz* Z = aloca_matriz(a->m,1);
   Matriz* X = aloca_matriz(a->m,1);
   Matriz** retorno =(Matriz**)malloc(sizeof(Matriz*)*2);

   L->mat[0][0] = a->mat[0][0];
   U->mat[0][1] = a->mat[0][1]/L->mat[0][0];

   int i;
   for(i=1 ; i<n-1 ;i++){

        L->mat[i][i-1] = a->mat[i][i-1];
        L->mat[i][i] = a->mat[i][i] - L->mat[i][i-1]*U->mat[i-1][i];
        U->mat[i][i+1] = a->mat[i][i+1]/L->mat[i][i];

   }

   for(i=0;i<n;i++)
        U->mat[i][i] =1;

    L->mat[n-1][n-2] = a->mat[n-1][n-2];
    L->mat[n-1][n-1] = a->mat[n-1][n-1] - L->mat[n-1][n-2]*U->mat[n-2][n-1];


retorno[0]=L;
retorno[1]=U;

return retorno;
}
//decompoe a matriz A em Q e R
Matriz** decomposicao_qr(Matriz* a){


}
//implementa a substituição pra trás
// retorna o vetor resultado
Matriz* substituicao_retroativa(Matriz* a,Matriz* b,Matriz* x){

    int n = a->m;
    x->mat[n-1][0];

    Matriz* retorno = clone(x);

    int i = n-1;
    for(;i > 0;i--){

        double soma =0;
        int j =i+1;
        for(;j < n ;j++){

            soma += a->mat[i][j]*retorno->mat[j][0];
        }
        retorno->mat[i][0] = (b->mat[i][0] - soma)/a->mat[i][i];

    }

return retorno;
}
//implementa a substituição para frente
// retorna o vetor resultado
Matriz* substituicao_progressiva(Matriz* a,Matriz* b,Matriz* x){

    int n = a->m;
    x->mat[n-1][0];

    Matriz * retorno = clone(x);

    int i = 0;
    for(;i < n;i++){

        double soma =0;
        int j =0;
        for(;j < i ;j++){

            soma += a->mat[i][j]*retorno->mat[j][0];
        }
        retorno->mat[i][0] = (b->mat[i][0] - soma)/a->mat[i][i];

    }

return retorno;
}
// faz as contas levando em consideração a diagonal principal
Matriz* metodo_direto(Matriz* a,Matriz* b,Matriz* x){

    Matriz* resposta = clone(x);

    int i =0;
    for(;i < a->m;i++){

        resposta->mat[i][0] = b->mat[i][0]/a->mat[i][i];

    }

return resposta;
}
// metodo que resolve os sistemas
Matriz* solver(Matriz* a,Matriz* x,Matriz* b,int metodo_decomposicao, Matriz** (*func)(Matriz* d)){

        if(metodo_decomposicao == LU){
            Matriz** matrizes = func(a);
            Matriz* L = matrizes[0];
            Matriz* U = matrizes[1];
            Matriz* Y = aloca_matriz(x->m,1);
            matriz_uns(Y);

            Matriz* aux = Y;
            Y = substituicao_progressiva(L,b,Y);
            libera_matriz(aux);
            Matriz* resposta = substituicao_retroativa(U,Y,x);

            return resposta;
        }else if(metodo_decomposicao == CHOLESKY){

            Matriz** matrizes = func(a);
            Matriz* R = matrizes[0];
            Matriz* RT = transpoe(R);

            Matriz* Y = aloca_matriz(x->m,1);
            matriz_uns(Y);

            Matriz* aux = Y;
            Y = substituicao_progressiva(R,b,Y);
            libera_matriz(aux);
            Matriz* resposta = substituicao_retroativa(RT,Y,x);

            return resposta;
        }else if(metodo_decomposicao == LDLT){

            Matriz** matrizes = func(a);
            Matriz* L = matrizes[0];
            Matriz* D = matrizes[1];
            Matriz* LT = transpoe(L);

            Matriz* W = aloca_matriz(x->m,1);
            matriz_uns(W);

            Matriz* aux = W;

            W = substituicao_progressiva(L,b,W);
            libera_matriz(aux);

            Matriz* Y = aloca_matriz(x->m,1);
            matriz_uns(Y);

            aux = Y;
            //implementar subs direta
            Y = metodo_direto(D,W,Y);

            Matriz* resposta = substituicao_retroativa(LT,Y,x);

            return resposta;
        }else  if(metodo_decomposicao == CROUT){
            Matriz** matrizes = func(a);
            Matriz* L = matrizes[0];
            Matriz* U = matrizes[1];
            Matriz* Y = aloca_matriz(x->m,1);
            matriz_uns(Y);

            Matriz* aux = Y;
            Y = substituicao_progressiva(L,b,Y);
            libera_matriz(aux);
            Matriz* resposta = substituicao_retroativa(U,Y,x);

            return resposta;
        }
}
