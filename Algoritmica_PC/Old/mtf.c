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
    new->next = head;
    return new;
}


elem* insCoda(elem *head, int key)
{
    if (head == NULL){
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

    printf("%d\t", head->key);
    printlist(head->next);
}


int cerca(elem *head, int key)
{
    int position = 0;
    while(head != NULL){
        if(head->key == key)
            return position;
        
        head = head->next;
        position++;
    }
    return -1;
}

int mtf(elem **head, int key)
{
    elem *pre_target = NULL;
    elem *target = *head;
    int position = 0;
    while (target != NULL && target->key != key){
        pre_target = target;
        target = target->next;
        position++;
    }
    if (target == NULL)
        return -1;
    else{

    
        if (pre_target == NULL)
            return position;

        pre_target->next = target->next;
        target->next = *head;
        *head = target;
        return position;
    }
}

int main()
{
    int n, key;
    scanf("%d", &n);
    elem *first = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        first = insCoda(first, key);
    }
    // printlist(first);
    // printf("\n");
    int result = 0;
    int query;
    while(result != -1)
    {
        scanf("%d", &query);
        result = mtf(&first, query);
        printf("%d\n", result);
    }
     
    return 0;
}
