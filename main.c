#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=5;
    int i, j;
    for(i=0; i<n;i++ ){
        for(j=2*(n-1); j>=0; j--){
            printf(" ");
        }
        for(j=0; j<=i; j++){
            printf("*");
        }
    }
}