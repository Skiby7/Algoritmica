#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101

int compare(const void *a, const void *b)
{
    char **a1= (char **)a;    
    char **b1= (char **)b;     
    return strcmp(*a1,*b1);
}

int main()
{
    int size;
    scanf("%d", &size);
    char **array;
    array = (char **)malloc(size*sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        array[i] = (char *) malloc(MAXLEN*sizeof(char));
        scanf(" %s", array[i]);
    }
    qsort(array, size, sizeof(char *), compare);
    for (int j = size - 1; j != -1; j--)
    {
        printf("%s\n", array[j]);
        free(array[j]);
    }
    free(array);
    return 0;
}