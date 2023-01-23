#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

int main(){

    long long int n,soma=0;
    int k=0;
    scanf("%lld ", &n);
     scanf("%d", &k);

    int vetor[n];

    if(n<=100000){
        for(int i = 0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    mergesort(vetor, n);
// busca binaria
    for(int i = 0; i<n;i++)
    {
        int metade, flag = 0;
        int inicio=0,final=n-1;
        while(inicio<=final){
            metade=(inicio+final)/2;
            if(vetor[metade] == vetor[i]+k){
                flag=1;
                break;
            }
            else if(vetor[metade]>vetor[i]+k ){
                final=metade-1;
            }   
            else{ 
                 inicio=(metade+1);
            }  
        }
        if(flag==1){
            soma+=1;
        }
                    
    }
    printf("%lld\n",soma);
    }
        
    return 0;
}


void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}

void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}