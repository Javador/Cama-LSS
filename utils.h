double valor_maximo(double *vet,int tamanho){

        double value = vet[0];
        int i = 0;
        for(; i < tamanho; i++){

            if(vet[i] > value){

                value = vet[i];
            }
        }

return value;
}

double abs_double(double value){

    if(value == 0){
        return 0;
    }else if(value > 0){
        return value;
    }else
        return value*-1;
}
