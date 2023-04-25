#include <stdio.h>

int prime(int x) {
    if (x == 2 || x == 3)
        return 1;
    if (x < 2 || x % 2 == 0 || x % 3 == 0)
        return 0;
    int y = 5;
    while (y <= x/y) {
        if (x % y == 0)
            return 0;
        y += 2;
        if (x % y == 0)
            return 0;
        y += 4;
    }
    return 1;
}

int pri(l)
{
    int dig = 0, sum = 0;
    while(l > 0){
        dig = l%10;
        sum = sum + (dig*dig);
        l = l/10;
    }
    if(sum==4){
        return 0;
    }
    else if(sum!=1) {
        return pri(sum);
    }
    else {
        return 1;
    }
}


int main() {
    int l, u, k, number;
    number=0;
    scanf("%d %d %d", &l, &u, &k);
    for (; k > 0 && l <= u; l += 1) {
        if (prime(l)) {
            if (pri(l) == 1) {
                number=l;
                k -= 1;
            }
        }
    }
    if (k == 0) {
        printf("%d", number);
    }
    else{
        printf("-1");
    }

}

