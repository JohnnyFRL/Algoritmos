#include <stdio.h>
#include <stdlib.h>
#define arraySize(ARR) (sizeof(ARR)/sizeof(ARR[0]))

int main()
{
    
    int arr[] = {51,1,110,54,13,222,18,94,421,22,17,59};
    int i = 0;
   
    merger(arr, arraySize(arr)+1);
 
    return 0;
}

void inserSortArray(int arr[],int arrLength)
{   
    
   
    int j,i,key;
   
    for(j=1; j<arrLength; j++)
    {
        
        i = j-1;
        key = arr[j];
         
        while(i>=0 && arr[i] < key)
        {
            
            arr[i+1] = arr[i];
            i = i-1;
        }

        arr[i+1] = key;
        
    }
    
    int t;
    for(t=0; t<arrLength; t++)
    {
        printf(" %d \n ", arr[t]);
    }

}

void mergerSort(int *a, int first, int last)
{
    int n = last - first;
    int l = first,
    metade = ((first+last)%2 == 0) ? (first+last)/2 : (first+last+1)/2,
    r = last;

    if(n<2)
        return;
    else if(n == 2)
        mergersort(a, l, metade, r);
    else
    {
        if(metade-l > 1)
            mergerSort(a, l, metade);
        if(r-metade > 1)
            mergerSort(a, metade, r);
        mergersort(a, l, metade, r);
    }

}


void mergersort(int *a, int l, int metade, int r)
{
    int i = l, j = metade, k = 0;
    int total = r-l;
    int *temp=NULL;

    temp = (int *)realloc(temp,sizeof(int) * total); // alocao dinamica da array temporaria

    if(temp == NULL)
        return;
    while(i < metade && j <r)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    if(i == metade)
    {
        while(j < r)
            temp[k++] = a[j++];
    }
    else if(j == r)
    {
        while(i < metade)
            temp[k++] = a[i++];
    }

    for(i = 0, k = l; i < total; k++, i++)
    {
        a[k] = temp[i];
    }

    free(temp);
}


void merger(int a[], int b)
{
    int i,j, temp;

    for(i=0; i<b; i++)
    {
        for(j=0; j<b-i; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(i=0; i<b; i++)
        printf("%d ", a[i]);
}