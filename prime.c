#include <stdio.h>
#include <math.h>

int prime(int x)
{
    if(x==2 || x==3)
        return 1;
    if(x<2 || x%2==0 || x%3==0)
        return 0;
    int y=5;
    while(y<=sqrt(x)) {
        if (x % y == 0)
            return 0;
        y += 2;
        if (x % y == 0)
            return 0;
        y += 4;
    }
    return 1;
}

int seq(int x)
{
    int y;
    while(x>0) {
        y=x%10;
        x=x/10;
        if((x%10)>y)
            return 0;
    }
    return 1;
}



int main()
{
    int n;
    scanf("%d",&n);
    for (int i=2; i<n; i++)
        if (prime(i)&&seq(i))
            printf("%d\n", i);
    return 0;
}