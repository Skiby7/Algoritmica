#include <stdio.h>

int maxsub(int arr[], int size)
{
    int i = 0;
    int j = 0;
    int max = 0;
    int tmp;
    while(i!=size-1)
    {
        j = i;
        tmp = 0;
        while(j < size || (tmp - arr[j]) <= max)
        {
            tmp += arr[j];
            if (tmp >= max) max = tmp;
            j++;
        }
        
    }
    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    int array_1[n];
    for(int i = 0; i < n; i++)
       {
           scanf(" %d", &array_1[i]);
       } 
    int res = maxsub(array_1, n);
    printf("%d\n", res);
    return 0;
}