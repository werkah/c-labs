#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int **t1 = (int **) malloc(n * sizeof(int *));
    for (int x = 0; x < n; x++) {
        t1[x] = (int *) malloc(n * sizeof(int));
    }
    int nrow=n;
    int ncol=n;
    int row=0;
    int col=0;
    int liczba=1;
    while(row<nrow && col<ncol){
        for(int i=col; i>=col && i<ncol; i++){
            t1[row][i] = liczba;
            liczba += 1;
        }
        row+=1;
        for(int j=row; j>=row && j<nrow; j++){
            t1[j][ncol-1]=liczba;
            liczba+=1;
        }
        ncol-=1;
        for(int p=ncol-1; p<=ncol-1 && p>col-1; p--){
            t1[nrow-1][p]=liczba;
            liczba+=1;
        }
        nrow-=1;
        for(int q=nrow-1; q<=nrow-1 && q>row-1; q--){
            t1[q][col]=liczba;
            liczba+=1;
        }
        col+=1;

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", t1[i][j]);
        printf("\n");
    }
    free(t1);
    return 0;


}


