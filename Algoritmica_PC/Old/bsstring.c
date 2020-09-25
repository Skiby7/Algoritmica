#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101

int binarySearch(char **array, int start, int size, char *target)
{
    int q;
    int comp;
    char *stringa;
    if(start > size) return -1;

    else
    {
        q = (start + size)/2;
        stringa = array[q];
        comp = strcmp(stringa, target);
        if(comp == 0) return q;
        else if(comp < 0) return binarySearch(array, q+1, size, target);
        else return binarySearch(array, start, q-1, target);
    }
}

int main()
{
    int size;
    int start = 0;
    scanf("%d", &size);
    char **array;
    array = (char **) malloc(size*sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        array[i] = (char *) malloc(MAXLEN*sizeof(char));
        scanf(" %s", array[i]); //non uso & perche' sto gia' usando un puntatore che punta alla cella in cui voglio salvare le mie stringhe
    }
    int choice;
    char target[MAXLEN];
    char *k = target;
    int result = 0;
    while (1)
    {
        scanf(" %d", &choice);
        if(choice == 0) break;
        else{
            scanf(" %s", &target);
            result = binarySearch(array, start, size, k);
            printf("%d\n", result);
        }
    }
    for(int j = 0; j < size; j++) free(array[j]);
    free(array);
}