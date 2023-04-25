#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, min, min_i;
    scanf("%d", &n);
    int **t1 = (int **) malloc(n * sizeof(int *));
    int *t2 = (int *) malloc(n * n * sizeof(int));
    int *t3 = (int *) malloc(n * sizeof(int));
    for (int x = 0; x < n; x++) {
        t1[x] = (int *) malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j=0; j < n; j++)
            scanf("%d", &t1[i][j]);
        t3[i] = 0;
    }
    int place = 0;
    for (int count = 0; count < n * n; count++) {
        min = -1;
        min_i = -1;
        for (int i = 0; i < n; i++) {
            if (t3[i] >= n)
                continue;
            if (min == -1 || t1[i][t3[i]] < min) {
                min = t1[i][t3[i]];
                min_i = i;
            }
        }
        t3[min_i] += 1;
        if (min == t2[place - 1])
            continue;
        t2[place] = min;
        place += 1;
    }
    for (int j = 0; j < place; j++)
        printf("%d ",t2[j]);
    free(t1);
    free(t2);
    free(t3);
    return 0;
}

