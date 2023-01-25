#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(int ini, int m, int final, long long int v[]){
	int i, j, k;
	int tam1 = m - ini + 1;
	int tam2 = final - m;

	int vet1[tam1], vet2[tam2];

	for(i=0;i<tam1;i++){
		vet1[i] = v[ini+i];
	}
	for(j=0;j<tam2;j++){
		vet2[j] = v[m+1+j];
	}

	i=0, j=0,k=ini;

	while(i<tam1 && j<tam2){
		if(vet1[i]>=vet2[j]){
			v[k] = vet1[i];
			i++;
		}else{
			v[k] = vet2[j];
			j++;
		}
		k++;
	}

	while(i<tam1){
		v[k]=vet1[i];
		i++;
		k++;
	}
	while(j<tam2){
		v[k]=vet2[j];
		j++;
		k++;
	}
}

void mergesort(int ini, int final, long long int v[]){

	 if(ini < final){
		
		int m = ini+(final-ini)/2;
		mergesort(ini,m,v);
		mergesort(m+1,final,v);
		merge(ini,m,final,v);
	}
}

int main(){

      int n_barras,n_cupons,cupons,cases=0;
      long long int *vet,soma_total=0;

     scanf("%lld", &n_barras);

      vet = (long long int *)malloc(n_barras*sizeof(long long int));
     
        
          for(int i = 0; i<n_barras; i++){
        scanf("%lld", &vet[i]);

        soma_total=soma_total+vet[i]; // calculando total de elementos
        
    }
   
  //  printf("%d\n", soma_total);
    // ordenando em ordem decrescente
   mergesort(0,n_barras-1,vet);
    
    scanf("%d", &n_cupons);

    while(cases < n_cupons){

		scanf("%d", &cupons);

		printf("%lld\n",soma_total-vet[cupons-1]);
		cases++;
	}
   
    

    return 0;
}

