#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "utils.h"

// estrutura que define o tipo matriz que será utilizado
typedef struct matriz {
    int n;
    int m;
    double **mat;

}Matriz;
//--------------------------------------------------------
//cabeçalhos das funções, necessário para que as funções funcionem em qualquer ponto do código
Matriz* aloca_matriz(int m,int n );
double valor_maximo_vet_col(double **mat,int linhas);
int criterio_das_linhas(Matriz* a);
void zera_matriz(Matriz *a);
int contains(int* vet,int m, int needle);
void gauss(Matriz* a,int* index);
double norma_2(Matriz* a);
//--------------------------------------------------------


//funçao que implementa o criterio das linhas
//para descobrir se uma matriz converge ou não
int criterio_das_linhas(Matriz* a){

    int matriz_invalida[a->m];
    int i = 0;
    for(;i < a->m ; i++){

        int elem_princ =a->mat[i][i] ;
        int somatorio_linha=0;

        int j =0;
        for(;j < a->n;j++){

            if(i != j){

                somatorio_linha +=a->mat[i][j];

            }

        }

        if(somatorio_linha < elem_princ){

            matriz_invalida[i] = 0;

        }
        else{
            matriz_invalida[i] = 1;
        }

    }

return contains(matriz_invalida,a->m,1);

}

//verifica se o elemento needle pertence a um determinado vetor
// retorna 1 se é verdadeiro e 0 se for falso
int contains(int* vet,int m, int needle){

    int i = 0;
    for(; i < m ;i++){
        if(vet[i] == needle){
            return 1;
        }
    }
return 0;
}

//retorna valor maximo do vetor coluna
double valor_maximo_vet_col(double** mat,int linhas){

       int i =0;
       double value  = mat[0][0];
       for(;i < linhas;i++){
            if(mat[i][0] > value){
                 value = mat[i][0];
            }
       }
return value;
}

// preenche a matriz criada com zeros
void zera_matriz(Matriz* a){

    int i = 0;
    for(;i<a->m;i++){
        int j = 0;
        for(;j<a->n;j++){
            a->mat[i][j] = 0;
        }
    }
}

// preenche a matriz criada com uns
void matriz_uns(Matriz* a){

    int i = 0;
    for(;i<a->m;i++){
        int j = 0;
        for(;j<a->n;j++){
            a->mat[i][j] = 1;
        }
    }
}

// cria uma matriz triangular inferior preenchida com uns
void gera_triangular_inferior(Matriz* a){
    int aux = a->n -1;
    int i ;
    for(i = 0;i < a->m;i++){
        int j;
        for(j=0;j < a->m -aux;j++){

            a->mat[i][j] =1 ;

        }
        aux--;

    }

}
int is_triangular_superior(Matriz* a){

    int aux = a->n -1;
    int i ;
    for(i = 0;i < a->m;i++){
        int j;
        for(j=0;j < a->m -aux;j++){

            if(i!=j && a->mat[i][j] !=0){
               return 0;
            }
        }
        aux--;
    }

return 1;
}
//imprime a matriz
void imprime_matriz(Matriz* a){
    int i = 0;
    for(;i< a->m; i++){

    int j =0;
    for(; j< a->n ;j++){
        printf("%.2f ",a->mat[i][j]);
    }
    printf("\n");
    }
    printf("\n");

}

// aloca a memoria necessaria para o uso da matriz
//entradas M numero de linhas e N numero de colunas
Matriz* aloca_matriz(int m,int n ){

        Matriz* aux = (Matriz*) malloc(sizeof(Matriz));

        aux->n = n;
        aux->m = m;
        double ** aux_mat =  malloc(sizeof(double*)*m);

       int i =0;
       for(; i< m ;i++){
           aux_mat[i] = malloc(sizeof(double)*n);
       }

       aux->mat = aux_mat;

return aux;
}

//clona o objeto matriz
Matriz* clone(Matriz* a){

   Matriz* b = aloca_matriz(a->m,a->n);

   int i =0;
   for(i=0;i < a->m;i++){

        int j = 0;
        for(j=0;j < a->n;j++){

            b->mat[i][j] = a->mat[i][j];

       }

    }
return b;
}

//libera a memória do objeto matriz
int  libera_matriz(Matriz* a){

    int i =0;
    for(;i < a->m;i++){
       free(a->mat[i]);
    }

    free(a->mat);
    free(a);

return 1;
}

// realiza a multiplicação de matrizes e retorna um objeto Matriz com o resultado
Matriz* multiplica_matriz(Matriz* a, Matriz* b){


    if(a->m != b->n){
     return NULL;
    }

    double** resultado = malloc(sizeof(double*)*a->m);

    int aux = 0;
    for(aux = 0 ; aux < a->m ;aux++){
        resultado[aux] = malloc(sizeof(double)*b->n);
    }

    int i,j,k;
    i = j = k = 0;

    for(i = 0; i < a->m ; i++){

        for(j = 0; j < b->n; j++){

                resultado[i][j] = 0;
                for(k = 0; k < a->n; k++){

                      resultado[i][j] += a->mat[i][k] * b->mat[k][j];

                }
        }
   }

        Matriz* aux_mat  = aloca_matriz(a->m,b->n);

        aux_mat->mat = resultado;

        return aux_mat;

}

// exponencia o objeto matriz elevado ao numero inserido
Matriz* exponencia(Matriz* a, int numero){

	Matriz * result = clone(a);

	int i = 0;
	for(;i < numero-1 ; i++){
            Matriz* aux = result;
	        result = multiplica_matriz(result,a);
            libera_matriz(aux);
	}

	return result;
}

// retorna o traço de uma matriz
double traco(Matriz* a){

    double aux_traco = 0;

    int i=0;
    for(; i < a->m ;i++){
        int j=0;
        for(; j < a->n ;j++){

            if(i == j){

                aux_traco += a->mat[i][j];
            }
        }
    }
return aux_traco;
}

// função para transpor uma matriz
//retorna a matriz transposta
Matriz* transpoe(Matriz* a){

    Matriz* aux = aloca_matriz(a->n,a->m);
    int i = 0;
    for(;i < a->m;i++){
        int j=0;
        for(;j< a->n;j++){

            aux->mat[j][i] = a->mat[i][j];
        }
    }

    return aux;
}

//calcula a matriz inversa dado uma matriz A
 Matriz* inverte(Matriz* a) {
    int n = a->m;
    Matriz* x = aloca_matriz(n,n);
    Matriz* b = aloca_matriz(n,n);
    int index[n];
    int i;
    for (i=0; i<n; ++i) b->mat[i][i] = 1;

 // aplicando a eliminação de gauss
    gauss(a, index);

    for ( i=0; i<n-1; ++i){
      int j;
      for (j=i+1; j<n; ++j){
        int k;
        for (k=0; k<n; ++k){
          b->mat[index[j]][k]-= a->mat[index[j]][i]*b->mat[index[i]][k];
        }
      }
    }
 // substituição para tras
    for (i=0; i<n; ++i) {
      x->mat[n-1][i] = b->mat[index[n-1]][i]/a->mat[index[n-1]][n-1];
      int j;
      for (j=n-2; j>=0; --j) {
        x->mat[j][i] = b->mat[index[j]][i];
        int k;
        for (k=j+1; k<n; ++k) {
          x->mat[j][i] -= a->mat[index[j]][k]*x->mat[k][i];
        }
        x->mat[j][i] /= a->mat[index[j]][j];
      }
    }
  return x;
  }

// Method to carry out the partial-pivoting Gaussian
// elimination.  Here index[] stores pivoting order.

void gauss(Matriz* a,int* index) {
    int n = a->m;
    double c[n];

 // Initialize the index
    int i;
    for (i=0; i<n; ++i) index[i] = i;

 // Find the rescaling factors, one from each row
    for (i=0; i<n; ++i) {
      double c1 = 0;
      int j;
      for (j=0; j<n; ++j) {
        double c0 = abs_double(a->mat[i][j]);
        if (c0 > c1) c1 = c0;
      }
      c[i] = c1;
    }

 // Search the pivoting element from each column
    int k = 0;
    int j;
    for (j=0; j<n-1; ++j) {
      double pi1 = 0;
      for (i=j; i<n; ++i) {
        double pi0 = abs_double(a->mat[index[i]][j]);
        pi0 /= c[index[i]];
        if (pi0 > pi1) {
          pi1 = pi0;
          k = i;
        }
      }

   // Interchange rows according to the pivoting order
      int itmp = index[j];
      index[j] = index[k];
      index[k] = itmp;
      for (i=j+1; i<n; ++i) {
        double pj = a->mat[index[i]][j]/a->mat[index[j]][j];

     // Record pivoting ratios below the diagonal
        a->mat[index[i]][j] = pj;

     // Modify other elements accordingly
        int l;
        for (l=j+1; l<n; ++l)
          a->mat[index[i]][l] -= pj*a->mat[index[j]][l];
      }
    }
  }

//calcula o numero condicao da matriz a
double numero_condicao(Matriz* a){

   Matriz* inversa = inverte(a);

   return norma_2(inversa)*norma_2(a);
}

//calcula a norma 2 da matriz a
double norma_2(Matriz* a){

    int m = a->m;
    int n = a->n;
    double soma = 0;

    int i;
    for(i=0; i < m; i++){

        int j;
        for(j=0;j < n; j++){

            soma += pow(a->mat[i][j],2);

        }
    }

return sqrt(soma);
}

//calcula o determinante da matriz a
double det(Matriz* a) {
    int n = a->m;
    int index[n];


 // Transform the matrix into an upper triangle
    gauss(a, index);

 // Take the product of the diagonal elements
    double d = 1;
    int i;
    for (i=0; i<n; ++i) d = d*a->mat[index[i]][i];

 // Find the sign of the determinant
    int sgn = 1;
    for (i=0; i<n; ++i) {
      if (i != index[i]) {
        sgn = -sgn;
        int j = index[i];
        index[i] = index[j];
        index[j] = j;
      }
    }
    return sgn*d;
}

// função para gerar uma matriz identidade
Matriz* identidade(Matriz* a){

    Matriz* aux = aloca_matriz(a->n,a->m);
    int i = 0;
    for(;i < a->m;i++){
        int j=0;
        for(;j< a->n;j++){
            if(i==j){
                aux->mat[i][j] = 1;
            }else{
                aux->mat[i][j] = 0;
            }
        }
    }

    return aux;
}

//Compara 2 matrizes a e b
Matriz* compara(Matriz* a, Matriz *b){
    int i = 0;
    for(;i < a->m;i++){
        int j=0;
        for(;j< a->n;j++){
            if(a->mat[i][j] != b->mat[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

// Verifica se a matriz eh de hankel
Matriz* eh_hankel(Matriz* a){

    Matriz* aux = aloca_matriz(a->n,a->m);
    int i = 0;
    for(;i < a->m;i++){
        int j=0;
        for(;j< a->n;j++){
            if(aux->mat[i][j] != a->mat[i-1][j+1]){
                return 0;
            }
        }
    }
    return 1;
}

