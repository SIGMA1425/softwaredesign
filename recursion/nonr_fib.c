#include <stdio.h>

int nonr_fib(int n);

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", nonr_fib(n));

    return 0;
}

int nonr_fib(int n)
{
    int fib[n+1];
    int i;
    fib[0] = 0;
    fib[1] = 1;

    for(i=2; i<n+1; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}