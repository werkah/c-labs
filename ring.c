#include <stdio.h>
#include <string.h>
#include <malloc.h>


int prime(int x)
{
    if(x==2 || x==3)
        return 1;
    if(x<2 || x%2==0 || x%3==0)
        return 0;
    int y=5;
    while(y*y<x) {
        if (x % y == 0)
            return 0;
        y += 2;
        if (x % y == 0)
            return 0;
        y += 4;
    }
    return 1;
}


int main()
{
    char s[51];
    scanf("%str", s);
    int n = strlen(s);
    char * wynik = malloc((n+1)* sizeof(char));
    wynik[n]='\0';
    strncpy(wynik, s, n+1);
    int p;
    char * curr = malloc((n+1)* sizeof(char));
    curr[n]='\0';
    for (int o = 0; o < n; o++)
        for (int i = 0; i < n; i++)
            if (o != i)
            {
                if (i > o)
                    p = i - o;
                else
                    p = n - o + i;
                if (prime(p))
                {
                    int a = 0;
                    for (int k = 0; k < n; k++)
                    {
                        //int b=(i+x*p)%n;
                        //curr[k]=s[b];
                        curr[k] = s[(i + a * p) % n];
                        a++;
                    }
                    if (strncmp(wynik,curr, n)>0)
                        strncpy(wynik, curr, n+1);
                }
            }
    printf("%s",wynik);
    free(wynik);
    free(curr);
    return 0;
}