#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int num;
    int licznik = 0;
    for (int i = 1; i < 1 << N; i++)
        if (i % M != 0)
            for (int j = 0; j < N; j++){
                num = i ^ (1 << j);
                if (num % M == 0 && num != 0){
                    licznik++;
                    break;
                }
            }
    printf("%d", licznik);
    return 0;
}
