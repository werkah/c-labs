#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int **tab = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        tab[i] = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &tab[i][j]);
    }
    int maxi = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int i=row;
            int j=col;
            int max=n;
            while (i<n && tab[i][j]==0){
                while (j<max && tab[i][j]==0){
                    j++;
                }
                int field=(j-col)*(i-row+1);
                if (field>maxi)
                    maxi=field;
                max=j;
                i++;
                j=col;

            }
        }
    }
    printf("%d", maxi);
    free(tab);
    return 0;
}

