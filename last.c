#include <stdio.h>
#include <malloc.h>


int xor(int ex, int bot_n[], int **T ) {
if (ex < 0)
return bot_n[(ex * -1) - 1];
return xor(T[ex - 1][0], bot_n, T) ^ xor(T[ex - 1][1], bot_n, T);
}

void plus(int bot_n[], int n)
{
    int i = n - 1;
    bot_n[n - 1]++;
    while (1) {
        if (bot_n[i] > 1)
        {
            bot_n[i] = 0;
            bot_n[i - 1]++;
        }
        else return;
        i--;
    }
}
int equal(int bot_n[], int top_n[], int n)
{
    for (int i = 0; i < n; i++)
        if (bot_n[i] != top_n[i])
            return 1;
    return 0;
}
int main()
{
    int n, m, ex;
    scanf("%d %d %d", &n, &m, &ex);
    char *top = (char *) malloc((n+1) * sizeof(char));
    char *bot = (char *) malloc((n+1) * sizeof(char));
    bot[n]='\0';
    top[n]='\0';
    int **T = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        T[i] = (int *) malloc(2 * sizeof(int));
        scanf("%d %d", &T[i][0], &T[i][1]);
    }
    scanf("%s", bot);
    scanf("%s", top);
    int *bot_n = (int *) malloc(n * sizeof(int));
    int *top_n = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        bot_n[i] = ((int) bot[i]) - 48;
        top_n[i] = ((int) top[i]) - 48;
    }
    int counter=0;
    while (equal(bot_n,top_n,n)) {
        counter+=xor(ex, bot_n, T);
        plus(bot_n,n);
    }
    counter+=xor(ex, bot_n, T);
    printf("%d", counter);
    for (int i=0; i<m; i++)
        free(T[i]);
    free(T);
    free(bot_n);
    free(top_n);
    return 0;
}
