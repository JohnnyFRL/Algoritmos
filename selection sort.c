#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//selection sort ordenacao encontrar menor valor

void selecao(int vet[], int n){

    int menor_numero,aux;
    
    for(int i = 0; i<n-1; i++){ // não pode ir até a ultima posicao do vetor por isso o -1

        menor_numero=i; // menor posicao é o i

        for(int j=i+1; j<n; j++){

            if(vet[menor_numero]>vet[j]){
                menor_numero=j;

            }
        }
        if(i!=menor_numero){  // pra n repetir o numero caso diferente
            aux=vet[i];
            vet[i]=vet[menor_numero];
            vet[menor_numero]=aux;
        }
    }
}

int main(){
    int n;
    printf("digite a quantidade elementos para o sort\n");
    scanf("%d", &n);
    int vetor[n];

    
    for(int i = 0; i <n; i++){
        printf("digite o numero da casa[%d]: \n", i);
        scanf("%d", &vetor[i]);
    }
    selecao(vetor,n);
    
    for(int i = 0; i<n; i++){
        printf("%d-", vetor[i]);
    }


    return 0;
}