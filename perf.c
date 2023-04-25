#include <stdio.h>
#include <math.h>

int perf(int n)
{
    int s=1;
    int p=(int) sqrt(n);
    for(int i=2; i<=p; i++)
        if(n%i==0)
            s+=i+(n/i);
    if(p*p==n)
        s-=p;
    return s==n;
}

int main()
{
    int a,b,c;
    c=0;
    scanf("%d %d",&a,&b);
    int tab [100];
    while(a<=b) {
        if (perf(a)) {
            tab[c]=a;
            c+=1;
        }
        a+=1;
    }
    printf("%d\n",c);
    for (int i=0;i<c;i++){
        printf("%d\t",tab[i]);
    }
    return 0;
}