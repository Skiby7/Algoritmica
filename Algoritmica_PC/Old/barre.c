#include <stdio.h>
#include <stdlib.h>

// In input ho a lunghezza della barra e i prezzi relativi alla lunghezza dei pezzi
// Questo e' un analogo del problema dello zaino 0-1

typedef struct lista
{
    int length;
    struct lista *next;
} length;

void printarray(int arr[], int len)
{
    for (int p = 0; p < len; p++)
        printf("%d ", arr[p]);
    printf("\n");
}

length* insCoda(length *head, int key)
{
    if (head == NULL){
        length *new = (length *)malloc(sizeof(length));
        new->length = key;
        new->next = NULL;
        return new;
    }
    length *scanner;
    scanner = head;
    while(scanner->next != NULL)
        scanner = scanner->next;
    
    scanner->next = (length *)malloc(sizeof(length));
    scanner->next->length = key;
    scanner->next->next = NULL;

    return head;
}

int revenue(int len, int pol[], int prices[], int len_1)
{
    return 0;
}

int main()
{
    int len;
    scanf("%d", &len);
    int prices[len];
    int prices_over_length[len];
    length *lunghezze = NULL;
    for (int i = 0; i < len; i++)
        scanf(" %d", &prices[i]);
    
    for(int j = 0; j < len; j++)
        prices_over_length[j] = prices[j]/(j+1);
    
    printarray(prices, len);
    printarray(prices_over_length, len);


    return 0;

     
    
    

    

    

}