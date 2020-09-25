#include <stdlib.h>
#include <stdio.h>


int distribuzione(int a[], int sx, int dx) 
{ 
  int pivot = a[dx];
  int i = sx - 1;
  for(int j = sx; j <= dx-1; j++)
  {
    if(a[j] < pivot)
    {
      i++;
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
    }
  }
  int tmp_1 = a[i + 1];
      a[i + 1] = a[dx];
      a[dx] = tmp_1;
      return (i+1);
}

void quicksort( int a[], int sx, int dx ) 
{
  
  int perno;
  if( sx < dx ) 
  {
    perno = distribuzione(a, sx, dx); 
    quicksort(a, sx, perno-1);
    quicksort(a, perno+1, dx);
  }
}

int main()
{
    int arr_len;
    scanf("%d", &arr_len);
    int a[arr_len];
    for(int i = 0; i < arr_len; i++) scanf(" %d", &a[i]);
    quicksort(a, 0, arr_len-1);
    for(int p = 0; p < arr_len; p++) printf("%d ", a[p]);
    return 0;
}