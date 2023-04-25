#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int l=0;
    int p=0;
    int *tab=malloc(n*sizeof(*tab));

    for (int i=0; i<n; i++) {
        scanf("%d", &tab[i]);
        p += tab[i];
    }

    int index= -1;
    for (int i=0; i<n; i++) {
        if (i - 1 >= 0) {
            l += tab[i - 1];
        }
        p -= tab[i];
        if (l == p) {
            index = i;
            break;
        }


    }
    printf("%d\n", index);
}



