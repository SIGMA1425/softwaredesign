#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int*, int, int);
int is_sorted(int*, int, int);

int main()
{
  int n = 10;
  int *ary = malloc(n * sizeof(int));
  int i;
  
  srand((unsigned int)time(NULL));
  for(i=0; i<n; ++i) 
  {
    ary[i] = rand() % 10;
  }
  for(i=0; i<n; ++i) 
  {
    printf("%d, ", ary[i]);
  }
  printf("\n");
  
  selection_sort(ary, n, 1);
  
  for(i=0; i<n; ++i) 
  {
    printf("%d, ", ary[i]);
  }
  printf("\n");
  printf("%d\n", is_sorted(ary, 10, 1));
  
  free(ary);
  return 0;
}

void selection_sort(int *ary, int anum, int asc) 
{
  int i, j, tmp, mi;
  for(i=0; i<anum-1; ++i) {
    //printf("i:%d\n", i);
    mi = i;//暫定的な最大(小)値の位置
    for(j=i+1; j<anum; ++j) {
      //printf("j:%d\n", j);
      if(ary[j] < ary[mi]) {
        mi = j;
      }
    }
    printf("ary[%d] <--> ary[%d]\n", i, mi);
    tmp = ary[i];
    ary[i] = ary[mi];
    ary[mi] = tmp;
  }
}

int is_sorted(int *ary, int anum, int asc) 
{
  int i;
  for(i=0; i<anum-1; ++i) 
  {
    if(( asc && ary[i] > ary[i+1]) || (!asc && ary[i] < ary[i+1]))  
       {
      return 0;
    }
  }
  return 1;
}