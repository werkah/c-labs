#include <stdio.h>
#include <stdlib.h>

int max_value(int *tab,int n)
{
    int max=0;
    for(int i=0; i<n; i++){
        if(tab[i]>tab[max])
            max=i;
    }
    if(tab[max]!=1){
        tab[max]=tab[max]/2;
        return max;
    }
    else
        return 1;
}


int main()
{
    int n, k;
    int j = 0;
    scanf("%d %d", &n, &k);
    int *tab = malloc(n * sizeof(*tab));
    for (int i=0; i < n; i++)
        scanf("%d", &tab[i]);
    for(;j<k;j++){
        if(tab[max_value(tab,n)]==1)
            return 0;
    }
    int sum=0;
    for (int i=0; i < n; i++)
        sum += tab[i];
    printf("%d", sum);
    free(tab);
}
