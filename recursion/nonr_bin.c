#include <stdio.h>

int nonr_bin(int n, int k);

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", nonr_bin(n, k));

    return 0;
}

int nonr_bin(int n, int k)
{
    int bin[n+1][k+1];
    int i, j;
    
    for(i=1; i<k+1; i++)
        bin[0][i] = 0;
    for(i=0; i<n+1; i++)
        bin[i][0] = 1;

    for(i=1; i<n+1; i++)
    {
        for(j=1; j<k+1; j++)
        {
            bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
        }
    }

    return bin[n][k];
}