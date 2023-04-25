#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    char *tab=malloc((51)*sizeof(*tab));
    scanf("%s", tab);
    int len=strlen(tab);
    if(len == 1){
        printf("%s",tab);
        free(tab);
        return 0;
    }
    int *t=malloc((len)*sizeof(*t));
    int end=len-1;
    t[end]=1;
    for (int start=end-1; start>-1; start--)
        if (tab[end]<=tab[start]){
            t[start]=1;
            end=start;
        }
    for (int i = 0; i < len; i++)
        if (t[i] == 1)
            printf("%c", tab[i]);
    free(t);
    free(tab);
    return 0;
}
