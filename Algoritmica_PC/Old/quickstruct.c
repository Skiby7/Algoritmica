#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101
#define max(a, b) ((a > b) ? a : b)

typedef struct stringa{
    char str[MAXLEN];
    int len;
} stri;

int compare(const void *a, const void *b)
{
    stri a1= *(stri *)a;    
    stri b1= *(stri *)b;     
    if(a1.len == b1.len)
        return strcmp(a1.str, b1.str);
    
    return (a1.len - b1.len);
}

int main()
{
    int size;
    scanf("%d", &size);
    stri *array;
    array = (stri *)malloc(size*sizeof(stri));
    for (int i = 0; i < size; i++)
    {
        scanf(" %s", &array[i].str);
        array[i].len = strlen(array[i].str);
    }
    qsort(array, size, sizeof(stri), compare);
    for (int j = 0; j < size; j++)
        printf("%s\n", array[j].str);
    free(array);
    return 0;
}