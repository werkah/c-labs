#include <stdio.h>

int fibb(int n)
{
    int a,b;
    a=0;
    b=1;
    int c;
    while (a*b<n)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return a*b==n;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf(fibb(n)? "YES" : "NO");
    return 0;
}
