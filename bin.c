#include <stdio.h>
#include <stdlib.h>

void without_one(int l, char tab[], int n, int k, int *idx)
{
    if (n==l){
        tab[n]='\0';
        (*idx)++;
        if (*idx==k) {
            printf("%s\n", tab);
            return;
        }
        return;
    }
    if(tab[n-1]=='1'){
        tab[n]='0';
        without_one(l,tab,n+1, k, idx);
    }
    if(tab[n-1]=='0'){
        tab[n]='0';
        without_one(l,tab,n+1, k, idx);
        tab[n]='1';
        without_one(l,tab,n+1, k,idx);
    }
    return;
}

void generate(int n, int k, int *idx)
{
    if (n<=0)
        return;
    char *tab=malloc((n)*sizeof(*tab));
    tab[0]='0';
    without_one(n,tab,1,k, idx);
    tab[0]='1';
    without_one(n,tab,1, k, idx);
}

int main()
{
    int i=0;
    int* idx = &i;
    int n, k;
    scanf("%d %d", &n, &k);
    generate(n, k, idx);
    if (k>*idx)
        printf("-1");
    return 0;
}