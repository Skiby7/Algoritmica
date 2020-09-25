#include <stdio.h>

void print(int a[], int n)
{
    for(int i=0; i < n; i++) printf("%d\n", a[i]);
}

void insertionSort(int a[], int n)
{
    int j;
    int k;
    for(int i = 1; i < n; i++)
    {
        k = a[i];
        j = i-1;
        while(j >= 0 && a[j] > k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = k;
    }
    
}

int main()
{
    int size1;
    scanf("%d", &size1);

    int a[size1];
    for(int i = 0; i < size1; i++) scanf(" %d", &a[i]);
    insertionSort(a, size1);
    print(a, size1);
}