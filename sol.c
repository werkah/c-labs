#include <stdio.h>
#define size (32)

int sol(const int N, const int G, const int T[])
{
    int bits[size] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < size; j++) {
            int k = 1 << j;
            if ((T[i] & k) != 0)
                bits[j]++;
        }
    }
    unsigned int min_count = -1;
    for (int j = 0; j < size; j++) {
        int k = 1 << j;
        if ((G & k) != 0)
            min_count = (min_count < bits[j]) ? min_count : bits[j];
    }
    return min_count < 0 ? 0 : min_count;
}

int main() {
    int N, G;
    scanf("%d %d", &N, &G);
    int T[20];
    for (int i = 0; i < N; i++) {
        scanf("%d", &T[i]);
        if ((T[i] & ~G) != 0)
            T[i]=0;
    }
    int x=sol(N, G, T);
    printf("%d", x);
    return 0;
}