#include <stdio.h>

int fib(int);

int main(void)
{
    int x;
    printf("input->");
    scanf("%d", &x);
    printf("%d", fib(x));
    return 0;
}

int fib(int x)
{
    if((x>=0)&&(x<=1))
        return x;
    else
        return fib(x-2) + fib(x-1);
    
}