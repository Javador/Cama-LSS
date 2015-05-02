#include "matrizes.h"



int main(void){


    Matriz *a = aloca_matriz(2,2);
    a->mat[0][0] =2;
    a->mat[0][1] =1;
    a->mat[1][0] =0;
    a->mat[1][1] =0;
    int exp = 2, ortogonal, hankel;

    // imprime matriz
    printf("Matriz A: \n\n");
    imprime_matriz(a);

    // exercicio 1-a ----------------------------------------------------
     printf("O traco da matriz A vale : %.2lf \n",traco(exponencia(a,exp)));
     double flops =(((3*a->m*a->n*a->n)*exp) + (1 * a->m * a->n));
     printf("Numero de flops          : %.2lf",flops);
    //-------------------------------------------------------------------

    // exercicio 1-b ----------------------------------------------------
    printf("\n");
    Matriz *at = transpoe(a); //matriz transposta at
    Matriz *ai = identidade(a); //matriz identidade ai
    Matriz *multiplicada = multiplica_matriz(a, at); //M*M^t

    //Verificando se M * M^t == In, se for eh ortogonal e retorna valor 1
    ortogonal = compara(multiplicada, ai);

    if(ortogonal == 1){
        printf("\nEsta matriz eh ortogonal.\n");
    }else{
        printf("\nEsta matriz nao eh ortogonal.\n");
    }

    printf("\n\nMatriz Transposta: \n\n");
    imprime_matriz(at);
    printf("Matriz M * M ^t: \n\n");
    imprime_matriz(multiplicada);
    printf("Matriz Identidade: \n\n");
    imprime_matriz(ai);
    //-------------------------------------------------------------------

    // exercicio 1-c ------------------FUNCAO eh_HANKEL AINDA N FUNCIONA-
    hankel = eh_hankel(a);
    if(hankel == 1){
        printf("\nEsta matriz eh de Hankel.\n");
    }else{
        printf("\nEsta matriz nao eh de Hankel.\n");
    }
    //-------------------------------------------------------------------

}
