#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int r;
    scanf("%d %d", &n, &r);
    int **tab = (int**)malloc(n*sizeof(int*));
    int **new = (int**)malloc(n*sizeof(int*));
    for (int q = 0; q < n; q++) {
        tab[q] = (int*)malloc(n*sizeof(int));
        new[q] = (int*)malloc(n*sizeof(int));
    }
    for (int w = 0; w < n; w++) {
        for (int k = 0; k < n; k++) {
            scanf("%d", &tab[w][k]);
            new[w][k] = 0;
        }
    }
    for (int w2 = 0; w2 < n; w2++) {
        for (int k2 = 0; k2 < n; k2++) {
            for (int i = w2 - r; i <= w2 + r; i++) {
                for (int j = k2 - r; j <= k2 + r; j++) {
                    if (i < n && i >= 0 && j < n && j >= 0)
                        new[w2][k2] += tab[i][j];
                }
            }
        }
    }
    for (int w3 = 0; w3 < n; w3++) {
        for (int k3 = 0; k3 < n; k3++)
            printf("%d ", new[w3][k3]);
        printf("\n");
    }
    free(tab);
    free(new);
    return 0;
}

