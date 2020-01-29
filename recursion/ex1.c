#include <stdio.h>

int sum(int);

int main(void)
{
    int x;
    printf("input->");
    scanf("%d", &x);
    printf("%d", sum(x));
    return 0;
}

int sum(int x)
{
    if(x<0)
        return 0;
    else
        return x + sum(x-1);
}