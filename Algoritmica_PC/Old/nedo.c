#include <stdio.h>

void nedofunky(int a[], int n)
{
    int temp;
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[min])
            {
                min = j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}


int main()
{
    int arr[3];
    printf("Mi dica, mi dica: ");
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    nedofunky(arr, 3);
    printf("Ecco qui i tre nani in ordine:\n%d %d %d", arr[0], arr[1], arr[2]);
    return 0;
}