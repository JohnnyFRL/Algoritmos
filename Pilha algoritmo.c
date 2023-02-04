#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 100


typedef struct {
    int intens[TAMANHO];
    int toppo;

}Pilhas;

void inserir(Pilhas *p, int x);
int remover(Pilhas *p);

int main(){
    int x,remocao,opcao;

    Pilhas *p;
    p=(Pilhas*)malloc(sizeof(Pilhas));
    p->toppo=-1;
    
    printf("1-Inserir\n");
    printf("2-Remover\n");
    printf("digite a opcao\n");
    scanf("%d", &opcao);
   // inserir(p,8);
  //  inserir(p,18);
  //  inserir(p,58);
 //   inserir(p,3);


    switch (opcao)
    {
    case 1:
    printf("digite o valor que desejar inserir ou remover na pilha\n");
    scanf("%d", &x);
        inserir(p,x);
       
        break;
    case 2:
        remocao=remover(p);
         printf("saiu o valor %d da pilha\n", remocao);
        break;
    
    
    default:
        break;
    }
    
    
   
    free(p);


    return 0;
}

void inserir(Pilhas *p, int x){
    if(p->toppo==TAMANHO-1){
        printf("pilha cheia\n");
    }else{
        p->toppo++;
        p->intens[p->toppo]=x;
    }
}
int remover(Pilhas *p){
    int aux;
    if(p->toppo==-1){
        printf("pilha ja ta vazia\n");
    }else{
       aux=p->intens[p->toppo];
       p->toppo--;
       return aux;
    }
}
