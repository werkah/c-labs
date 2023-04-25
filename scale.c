#include <stdio.h>
#include <stdlib.h>

int scale(int t[],int len,int weight,int p)
{
    if(weight==0)
        return 1;
    if(p==len)
        return 0;
    return scale(t,len,weight,p+1) || scale(t,len, weight-t[p],p+1) || scale(t,len,weight+t[p], p+1);
}

int main()
{
    int n,w;
    int sum=0;
    int i=0;
    scanf("%d %d", &n, &w);
    int *tab=malloc(n*sizeof(*tab));
    while (i<n) {
        scanf("%d", &tab[i]);
        sum += tab[i];
        i++;
    }
    if (sum<w) {
        printf("NO");
        return 0;
    }
    if(scale(tab, n, w, 0))
        printf("YES");
    else
        printf("NO");

    return 0;
}
