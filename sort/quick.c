#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int*b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void deal(int *arr, int num);
void deal2(int *arr, int start, int end, int* lr);
void quick_sort(int *arr, int num, int left, int right);
int* ary_cre(int x);
void shell_sort(int* array, size_t size);

int main(void)
{
    int i, n=10;
    int *ary = ary_cre(n);
    int lr[2];

    for(i=0; i<n; i++)
    {
        printf("%d, ", ary[i]);
    }
    putchar('\n');

    quick_sort(ary, n, 0, 4);

    for(i=0; i<n; i++)
    {
        printf("%d, ", ary[i]);
    }

    free(ary);

    return 0;

}

void deal(int *arr, int num)
{
    int l = 0, r = num - 1, p=arr[num/2];

    while(l<=r)
    {
        for(;arr[l]<p;l++);
        for(;arr[r]>p;r--);
        if(l>r)
        {
            break;
        }
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }   
}

int* ary_cre(int x)
{
    int i;
    int *ary = malloc(x *sizeof(int));
    srand(time(NULL));

    for(i=0; i < x; i++)
    {
        ary[i] = rand()%10;
    }

    return ary;
}

void deal2(int *arr, int start, int end, int* lr)
{
    int l , r , p;
    l = start;
    r = end;
    p = arr[(end+start)/2];

    while(l<=r)
    {
        for(;arr[l]<p;l++);
        for(;arr[r]>p;r--);
        if(l>r)
        {
            break;
        }
        swap(&arr[l], &arr[r]);
        l++;
        r--;
    }
    lr[0] = l;
    lr[1] = r; 
    printf("p:%d\n", p);
}

void shell_sort(int* array, size_t size)
{
    // 最初の間隔 h を決める
    // 1,4,13,40,121... のように、1 から始めて h=h*3+1 を満たす値を使う。
    // これらの値の中で、size / 9 を超えない一番大きい値を最初の h とする。
    size_t h = 1;
    for( size_t h_tmp = 1; h_tmp < size / 9; h_tmp = h_tmp * 3 + 1 ){
        h = h_tmp;
    }

    while( h > 0 ){
        for( size_t i = h; i < size; ++i ){
            int tmp = array[i];

            if( array[i-h] > tmp ){  // 挿入が必要か先に調べる
                size_t j = i;

                do {
                    array[j] = array[j-h];
                    j -= h;
                } while( j >= h && array[j-h] > tmp );

                array[j] = tmp;
            }
        }
        h /= 3;  // 間隔を縮める
    }
}

void quick_sort(int *arr, int num, int left, int right)
{
    int l , r , p;
    int lr[2];
    if(l >= r)
    {
        return;
    }
    deal2(arr, left, right, lr);
    quick_sort(arr, num, left, lr[1]);
    quick_sort(arr, num, lr[0], right);
}