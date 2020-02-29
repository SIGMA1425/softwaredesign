#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int*, int, int);
int exchange_sort(int*, int, int);
int insertion_sort(int*, int, int);

int is_sorted(int*, int, int);

int main() {
  int n = 33;
  int *ary;
  int i;
  int asc = 0;

  clock_t start, end;

  FILE *fp = fopen("./clock_select.csv", "w+");
  if(fp == NULL)
  {
    printf("fileopen error\n");
    exit(0);
  } 
  else
  {
    printf("fileopen success\n");
  }
  fprintf(fp, "index, time[ms], \n");
  
  while (n <= 40000)
  {
    ary = malloc(n * sizeof(int));
    srand((unsigned int)time(NULL));
    for(i=0; i<n; ++i) {
      ary[i] = rand() % 1000;
    }

    start = clock();
    
    selection_sort(ary, n, asc);
    //exchange_sort(ary, n, asc);
    //insertion_sort(ary, n, asc);

    end = clock();

    fprintf(fp, "%d, %lf, \n", n, (double)(end-start)/(double)(CLOCKS_PER_SEC));
    free(ary);

    n *= 2;
  }

  fclose(fp);
  return 0;
}

void selection_sort(int *ary, int anum, int asc) {
  int i, j, tmp, mi;
  for(i=0; i<anum-1; ++i) {
    //printf("i:%d\n", i);
    mi = i;//暫定的な最大(小)値の位置
    for(j=i+1; j<anum; ++j) {
      //printf("j:%d\n", j);
      if(( asc && ary[j] < ary[mi]) ||
         (!asc && ary[j] > ary[mi])) {
        mi = j;
      }
    }
    //printf("ary[%d] <--> ary[%d]\n", i, mi);
    tmp = ary[i];
    ary[i] = ary[mi];
    ary[mi] = tmp;
  }
}

int exchange_sort(int *ary, int anum, int asc) {
  int i, j, tmp;
  for(i=anum-1; i>=0; --i) {
    for(j=0; j<i; ++j) {
      if(( asc && ary[j] > ary[j+1]) ||
         (!asc && ary[j] < ary[j+1])) {
        tmp = ary[j];
        ary[j] = ary[j+1];
        ary[j+1] = tmp;
      }
    }
  }
}

int insertion_sort(int *ary, int anum, int asc) {
  int i, j, tmp;
  for(i=1; i<anum; ++i) {
    for(j=i; j>=1; --j) {
      if(( asc && ary[j-1] > ary[j]) ||
         (!asc && ary[j-1] < ary[j])){
        tmp = ary[j-1];
        ary[j-1] = ary[j];
        ary[j] = tmp;
      }
      else
        break;
    }
  }
}




int is_sorted(int *ary, int anum, int asc) {
  int i;
  for(i=0; i<anum-1; ++i) {
    if(( asc && ary[i] > ary[i+1]) ||
       (!asc && ary[i] < ary[i+1]))  {
      return 0;
    }
  }
  return 1;
}