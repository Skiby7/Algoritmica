#include <stdio.h>
#include <stdlib.h>

int confrontaint(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

void sorting(int a[], int arr_len)
{
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
    qsort(even, len_even, sizeof(int), confrontaint);
    qsort(odd, len_odd, sizeof(int), confrontaint);
    for (int j = 0; j < len_even; j++) a[j] = even[j];
    int l = len_odd - 1;
    for (int k = len_even; k < arr_len; k++)
    {
        a[k] = odd[l];
        l--;
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int a[size];
    for (int i = 0; i < size; i++)
        scanf(" %d", &a[i]);
    
    sorting(a, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;  
}