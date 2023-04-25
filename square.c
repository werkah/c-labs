#include <stdlib.h>
#include <stdio.h>


int sum_sq(int **t, int size, int row, int col)
{
    int sum=0;
    int max_col, max_row;
    max_col = col + size;
    max_row = row + size;
    for (int i = col; i < max_col; i++)
        sum += t[row][i];
    for (int j = row; j < max_row; j++)
        sum += t[j][max_col];
    for (int a = max_col; col < a; a--)
        sum += t[max_row][a];
    for (int b = max_row; row < b; b--)
        sum += t[b][col];
    return sum;
}


int main()
{
    int  n, k;
    scanf("%d%d", &n, &k);
    int **t = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        t[i] = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &t[i][j]);
    }
    int *tab = (int*) malloc(n*n*sizeof(int));
    int row_c, col_c;
    int counter = 0;
    int x = 1;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int a = 2; a < n; a += 2) {
                if (row + a < n && col + a < n && sum_sq(t, a, row, col) == k) {
                    col_c = (2*col + a) / 2;
                    row_c = (2*row + a) / 2;
                    tab[x - 1] = row_c;
                    tab[x] = col_c;
                    x += 2;
                    counter += 1;
                }
            }
        }
    }
    printf("%d\n", counter);
    for (int i = 0; i < x && tab[i + 1] != 0; i = i + 2)
        printf("%d %d\n", tab[i], tab[i + 1]);
    free(t);
    free(tab);
    return 0;
}
