#include <stdio.h>

typedef unsigned long long num;

num odddivisor(int n)
{
    if(n==1)
        return 1;
    if(n%2==1)
        return n+odddivisor(n-1);
    else
        return odddivisor(n/2)+n*n/4;
}
int main() {
    int n;
    scanf("%d", &n);
    num suma = odddivisor(n);
    printf("%llu", suma);
    return 0;
}
