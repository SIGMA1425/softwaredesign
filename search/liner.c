#include <stdio.h>

int search(int arr[], int index, int key);

int main(void)
{

}

int search(int arr[], int index, int key)
{
    int i;
    int hit = -1;
    for(i=0; i < index; i++)
    {
        if(arr[i] == key)
        {
            hit = i;
            break;
        }
    }
    if(i >= index)
        return -1;
    else
        return hit;
    
}