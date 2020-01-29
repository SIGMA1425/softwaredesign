#include <stdio.h>

void swap(int *a, int*b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    
    
}

void deal(int *arr, int num)
{
    int l, r, p=arr[num/2];

    for(l=0;arr[l]<p;l++);
    for(r=0;arr[r]>p;r--);
    while(l<=r)
    {
        if(l<R)
        {
            break;
        }
        swap(&arr[l], arr[r]);
        l++;
        r--;
    }   
}