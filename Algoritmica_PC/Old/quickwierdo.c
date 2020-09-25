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

void strambezze(int a[], int arr_len)
{   //calcolo il numero di elementi pari e dispari e li inserisco negli array
    int len_even = 0;
    int len_odd = 0;
    for(int i = 0; i < arr_len; i++)
    {
        if(a[i]%2 == 0) len_even++;
        else len_odd++;
    }
    int even[len_even], odd[len_odd];
    int b = 0;
    int c = 0;
    for (int m = 0; m < arr_len; m++)
    {
        if(a[m]%2 == 0) 
        {
            even[b] = a[m];
            b++;
        }
        else
        {
            odd[c] = a[m];
            c++;
        }
        
    }
    //ordino i due array di numeri pari e dispari
    quicksort(even, 0, len_even-1);
    quicksort(odd, 0, len_odd-1);
    //scrivo a ordinato 
    for (int j = 0; j < len_even; j++) a[j] = even[j];
    int l = 0;
    for (int k = len_even; k < arr_len; k++)
    {
        a[k] = odd[l];
        l++;
    }
}

int main()
{
    int arr_len;
    scanf("%d", &arr_len);
    int a[arr_len];
    for(int i = 0; i < arr_len; i++) scanf(" %d", &a[i]);
    strambezze(a, arr_len);
    for(int p = 0; p < arr_len; p++) printf("%d ", a[p]);
    return 0;
}