#include <stdio.h>
#include <stdlib.h>


void swap(int* first, int* second)
{
    int temp=*first;
    *first=*second;
    *second=temp;
}

int partition(int *tab, int l, int h)
{
    int p=tab[h];
    int i=(l-1);
    for (int j=l; j<=h-1; j++){
        if (tab[j]<p){
            i++;
            swap(&tab[i],&tab[j]);
        }
    }
    swap(&tab[i+1], &tab[h]);
    return (i+1);
}

void quicksort(int *tab, int l, int h)
{
    if (l<h){
        int p_index = partition(tab, l, h);
        quicksort(tab, l, p_index - 1);
        quicksort(tab, p_index + 1, h);
    }
}

int main()
{
    int n, k;
    int j=0;
    scanf("%d %d",&n, &k );
    int *tab = malloc(n * sizeof(*tab));
    for (int i=0; i < n; i++)
        scanf("%d", &tab[i]);
    int count=0;
    quicksort(tab, 0, n-1);
    while(j<n) {
        int check=0;
        int l =j-1;
        int r =j+1;

        if(l>=0 && tab[l]>=tab[j]-k){
            check=1;
        }
        while(r<n && tab[r]==tab[j]){
            r++;
        }
        if(r<n && tab[r]<=tab[j]+k){
            check=1;
        }
        if(check==1)
            count+= r-j;
        j=r;
    }
    printf("%d", count);
    free(tab);
}
