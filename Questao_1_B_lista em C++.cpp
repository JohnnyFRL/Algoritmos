#include <algorithm>
#include <cstdio>

bool buscabinaria(int* inicio, int* final, int num){
    while (inicio < final){
        int* metade = inicio + (final - inicio) / 2;
        
        if (*metade == num)
            return true;
        else if (*metade > num)
            final = metade;
        else
            inicio = metade + 1;
    }
    
    return false;
}

int main()
{
    int n, k;
    std::scanf("%d%d", &n, &k);
    
    int vetor[100001];
    
    for (int i = 0; i < n; ++i)
        std::scanf("%d", &vetor[i]);
    
    std::sort(vetor, vetor + n);
     
    int res = 0;
    
    for (int i = 0; i < n; ++i)
        if (buscabinaria(vetor + i, vetor + n, vetor[i] + k))
            ++res;
    
    std::printf("%d\n", res);
    
    return 0;
}
