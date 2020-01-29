#include <stdio.h>

int nonr_sum(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", nonr_sum(n));

    return 0;
}

int nonr_sum(int n)
{
    int dp[n+1];
    dp[0] = 0;
    int i;

    for(i=1; i<n+1; i++)
    {
        dp[i] = dp[i-1] + i;
    }

    return dp[n];
}