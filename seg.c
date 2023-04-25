#include <stdio.h>
#include <stdlib.h>

int seg(int n,int k,int i,int j,int **tab)
{
    int max=0;
    int suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[(i+a+n)%n][j];
    max=suma;
    suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[(i-a+n)%n][j];
    if(suma>max)
        max=suma;
    suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[i][(j+a+n)%n];
    if(suma>max)
        max=suma;
    suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[i][(j+n-a)%n];
    if(suma>max)
        max=suma;
    suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[(i-a+n)%n][(j-a+n)%n];
    if(suma>max)
        max=suma;
    suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[(i+a+n)%n][(j+a+n)%n];
    if(suma>max)
        max=suma;
    suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[(i-a+n)%n][(j-a+n)%n];
    if(suma>max)
        max=suma;
    suma=0;
    for(int a=0; a<k; a++)
        suma+=tab[(i-a+n)%n][(j+a+n)%n];
    if(suma>max)
        max=suma;
    return max;
}



int main() {
    int n, k, odc;
    scanf("%d %d", &n, &k);
    int **tab = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        tab[i] = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &tab[i][j]);
    }
    int max=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            odc=seg(n,k,i,j, tab);
            if(odc>max)
                max=odc;
        }
    }
    printf("%d", max);
    for (int i=0; i<n; i++)
        free(tab[i]);
    free(tab);
    return 0;
}

