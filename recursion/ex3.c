#include <stdio.h>

int bin(int, int);

int main(void)
{
    int n, k;
    int i, j;
    for(i=0;i<=30;i++)
    {
        for(j=0;j<=30;j++)
        {
            if(bin(i, j) % 2 == 0)
                putchar(' ');
            else
                putchar('*');
        }
        putchar('\n');
    }
    return 0;
}

int bin(int n, int k)
{
    if(k == 0)
        return 1;
    else if (n == k)
        return 1;
    else if(k > n)
        return 0;
    else
        return bin(n-1, k-1) + bin(n-1, k);  
}