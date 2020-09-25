#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int key;
    struct lista *next;
    struct lista *prev;
} elem;

elem* insTesta(elem *head, int key)
{
    elem *new = (elem *)malloc(sizeof(elem));
    new->key = key;
    if(head == NULL) 
    {
        new->next = NULL;
        new->prev = NULL;
    } 
    else
        {
            new->next = head;
            new->prev = NULL;
        }
    return new;
}

void printlist(elem *head)
{
    if(head == NULL) return;

    printf("%d\n", head->key);
    printlist(head->next);
}

int main()
{
    int n, key;
    scanf("%d", &n);
    elem *first = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        first = insTesta(first, key);
    }
    printlist(first);
    
    
    return 0;
}
