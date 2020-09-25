#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int key;
    struct lista *next;
} elem;

elem* insTesta(elem *head, int key)
{
    elem *new = (elem *)malloc(sizeof(elem));
    new->key = key;
    if(head == NULL) 
        new->next = NULL;
    else
        new->next = head;
    return new;
}

elem* insCoda(elem *head, int key)
{
    if (head == NULL)
    {
        elem *new = (elem *)malloc(sizeof(elem));
        new->key = key;
        new->next = NULL;
        return new;
    }
    elem *scanner;
    scanner = head;
    while(scanner->next != NULL)
        scanner = scanner->next;
    
    scanner->next = (elem *)malloc(sizeof(elem));
    scanner->next->key = key;
    scanner->next->next = NULL;

    return head;
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
    elem *second = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        first = insCoda(first, key);
    }
    printlist(first);
     
    return 0;
}
