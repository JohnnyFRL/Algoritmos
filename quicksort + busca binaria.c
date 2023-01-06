#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
// QUICKSORT

int particao(int *vet, int inicio, int final);
void quicksort(int *vet, int inicio, int final);
int buscabinaria(int *vet, int inicio, int final, int constante);

int main(){
    int n=0,busca, k=0;
    printf("digite a quantidade de numeros para o quicksort\n");
    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i<n; i++){
        printf("digite o numero da casa[%d]", i);
        scanf("%d", &vetor[i]);
    }
    printf("digite qual numero da lista deseja buscar\n");
    scanf("%d", &k);
    quicksort(vetor,0,n-1);
    for(int i = 0; i<n; i++){
        printf("%d ",vetor[i]);
    }
    busca=buscabinaria(vetor,0,n,k);
    printf("o numero encontrado foi encontrado na casa %d", busca);

    
    return 0;
}

void quicksort(int *vet, int inicio, int final){
    int l=inicio, r=final;
    int pivo;

    if(l<r){
       pivo = particao(vet, inicio, final);
        quicksort(vet,inicio,pivo-1);
        quicksort(vet,pivo+1, final);
    }
}

int particao(int *vet, int inicio, int final){
    int esquerda= inicio, direita=final;    //i=esquerda
    int pivo=vet[inicio];                   //j=direita + 1
    int aux=0;

    while (esquerda<direita){
        while (vet[esquerda]<= pivo)
        {
            esquerda++;
        }
        while (vet[direita]>pivo)
        {
            direita--;
        }
        if(esquerda<direita){
            aux=vet[esquerda];
            vet[esquerda]=vet[direita];
            vet[direita]=aux;   //swap
        }  
    }
    if(esquerda>direita){
        vet[inicio]=vet[direita];
        vet[direita]=pivo;
    }
    return direita;
}
int buscabinaria(int *vet, int inicio, int final, int constante){
    int l=inicio, r=final, metade, k=constante;
    if(r>=l){
        metade=((l+r)/2);
        if(k==vet[metade]){
            return metade;
        }else if(k<vet[metade]){
            return buscabinaria(vet,inicio, metade - 1, constante);
        }else{
            return buscabinaria(vet, metade + 1, final, constante);
        }
    } else{
        return -1;
    }
}