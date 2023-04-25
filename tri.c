#include <stdio.h>
#include <malloc.h>

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    int *tab = calloc(2*m, sizeof(int));
    for (int i = 0; i <2*m; i++)
        scanf("%d", &tab[i]);
    int wynik=0;
    for (int i=1; i <= n; i++){
        int count=0;
        for (int j=0; j<2*m; j++) {
            if (tab[j] == i)
                count++;
        }
        wynik += count*(n-1-count);
    }
    int res = n*(n-1)*(n-2)/6-wynik/2;
    printf("%d",res);
    free(tab);
    return 0;
}