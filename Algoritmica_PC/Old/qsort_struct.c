#include <stdlib.h>
#include <stdio.h>

typedef struct plane
{
    int x;
    int y;
} point;

int compare(const void *a, const void *b) 
{
   point a1 = *(point *)a, b1 = *(point *)b; 
   if((b1.x - a1.x) != 0)
    return a1.x - b1.x;
    
   else
    return b1.y - a1.y;
}

int main()
{
    int size;
    scanf("%d", &size);
    point *array;
    array = (point *)malloc(size*sizeof(point));
    for(int i = 0; i < size; i++)
        scanf("%d %d", &array[i].x, &array[i].y);

    qsort(array, size, sizeof(point), compare);
    for (int j = 0; j < size; j++)
        printf("%d %d\n", array[j].x, array[j].y);
    
    free(array);
    return 0;
}