#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101

int partition(char **array, int min, int max)
{
    char *pi;
    pi = array[max];
    int i = (min-1);
    for (int j = min; j <= max-1; j++)
    {
        if(strcmp(array[j], pi) < 0)
        {
            i++;
            char tmp[MAXLEN];
            strcpy(tmp, array[i]);
            strcpy(array[i], array[j]);
            strcpy(array[j], tmp);
        }
    }
    char tmp_1[MAXLEN];
    strcpy(tmp_1, array[i + 1]);
    strcpy(array[i + 1], array[max]);
    strcpy(array[max], tmp_1);
    return (i+1);
}    

void quicksort(char **array, int min, int max)
{
    if(min < max)
    {
        int pivot = partition(array, min, max);
        quicksort(array, min, pivot-1);
        quicksort(array, pivot+1, max);
    }
}

void printarr(char **array, int size)
{
    for(int i = 0; i < size; i++) printf("%s\n", array[i]);
}


int main()
{
    int arr_len;
    scanf("%d", &arr_len);
    char **array;
    array = (char **) malloc(arr_len*sizeof(char *));
    for (int i = 0; i < arr_len; i++)
    {
        array[i] = (char *) malloc(MAXLEN*sizeof(char));
        scanf(" %s", array[i]);
        /*array[i] = realloc(array[i], (strlen(array[i])+1)*sizeof(char));*/   
    }
    //chiamata quicksort
    quicksort(array, 0, arr_len-1);
    //stampa array
    printarr(array, arr_len);
    //libera memoria
    for(int j = 0; j < arr_len; j++) free(array[j]);
    free(array);
}