#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, x1, x2, y1, y2;
    int len=201;
    int suma=0;
    scanf("%d", &n);
    int tab[201][201];
    for (int i=0; i<len;i++) {
        for (int j=0; j<len; j++)
            tab[i][j] = 0;
    }
    for (int i=0; i<n; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1+=100;
        y1+=100;
        x2+=100;
        y2+=100;
        int odl_x=abs(x1-x2);
        int odl_y=abs(y1-y2);
        for (int a=0; a<odl_y; a++){
            int tmp=x1;
            for (int b=0; b<odl_x; b++){
                if(tab[y1][tmp]==0)
                    tab[y1][tmp]=1;
                else
                    tab[y1][tmp]=0;
                tmp++;
            }
            y1++;
        }

    }
    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            if (tab[i][j]== 1)
                suma++;
        }
    }
    printf("%d", suma);
    return 0;
}
