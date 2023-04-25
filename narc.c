
#include <stdio.h>
#include <stdlib.h>

long power(long x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int main()
{
    int m,b;
    int found=0;
    scanf("%d %d", &m, &b);
    char *tab=malloc((m+1)*sizeof(*tab));
    for(long i=power(b,m-1); i<power(b,m); i++){
        int sum=0;
        long new=i;
        int pos=m-1;
        while(new>0){
            int num=new%b;
            sum+=power(num,m);
            if(num<10)
                tab[pos]='0'+num;
            else{
                num-=10;
                tab[pos]='A'+num;
            }
            pos--;
            new/=b;
        }
        if(sum==i){
            tab[m]='\0';
            printf("%s ",tab);
            found=1;
        }
    }
    if(found==0){
        printf("NO");
    }
    return 0;
}
