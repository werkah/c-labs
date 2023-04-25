#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,l;
    scanf("%d %d %d", &n, &k, &l);
    int **tab=malloc(n*sizeof(int*));
    int **rec=malloc(k*sizeof(int*));
    for (int i=0; i<n; i++)
        tab[i]=malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++)
            scanf("%d", &tab[i][j]);
    }
    for (int i=0; i<k; i++)
        rec[i]=malloc(l*sizeof(int));
    for (int i=0; i<k; i++){
        for (int j=0; j<l; j++)
            scanf("%d", &rec[i][j]);
    }
    int max=0;
    for (int i=0; i<n-k; i++) {
        for (int j = 0; j < n - l; j++) {
            int wynik = 0;
            for (int p = 0; p < k; p++) {
                for (int q = 0; q < l; q++) {
                    if (rec[p][q] == 1)
                        wynik += tab[i+p][j+q];
                }
            }
            if (wynik > max)
                max = wynik;
        }
    }
    printf("%d", max);
    for (int i=0; i<n; i++)
        free(tab[i]);
    free(tab);
    for (int i=0; i<k; i++)
        free(rec[i]);
    free(rec);
    return 0;
}
