#include <stdio.h>

int nonr_fact(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", nonr_fact(n));

    return 0;
}

int nonr_fact(int n)
{
    int dp[n+1];
    int i;
    dp[0]=1;
    for(i=1;i<n+1;i++)
    {
        dp[i] = dp[i-1] * i;
    }

    return dp[n];
}