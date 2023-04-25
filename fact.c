//
// Created by wehil on 11.04.2021.
//
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n,i;
    int x,count=0;
    scanf("%d",&n);
    int*tab=calloc(200, sizeof(int));
    tab[0]=1;
    for (;n >= 2; n--) {
        x=0;
        i=0;
        while (i <= count) {
            x=tab[i] * n + x;
            tab[i] = x % 10;
            x = x / 10;
            i++;
        }
        while (x > 0) {
            count++;
            tab[count] = x % 10;
            x = x / 10;
        }
    }
    for (int j = count; j >= 0;) {
        printf("%d", tab[j]);
        j--;
    }
    free(tab);
}

