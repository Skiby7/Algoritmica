#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int key;
    int count;
    struct lista *next;
    struct lista *prev;
} elem;

elem* insCoda(elem *head, int key)
{
    elem *new = (elem *)malloc(sizeof(elem));
    new->key = key;
    new->count = 0;
    if(head == NULL) {
        new->next = NULL;
        new->prev = NULL;
        return new;
    }
    elem *scanner = head;
    while(scanner->next != NULL)
        scanner = scanner->next;
    
    scanner->next = new;
    new->prev = scanner;
    new->next = NULL;

    return head;
}

int counter(elem **head, int key)
{
    elem* target = *head;
    int position = 0;
    while (target != NULL && target->key != key){
        target = target->next;
        position++;
    }
    if (target == NULL)
        return -1;

    (target->count)++;
    
       
        
    while (target->prev != NULL && target->prev->count < target->count){
        elem* pre_target = target->prev;
        target->prev = pre_target->prev;
        pre_target->next = target->next;
        pre_target->prev = target;
        if (target->next != NULL)
            target->next->prev = pre_target;

        if (target->prev != NULL)
            target->prev->next = target;
        
        target->next = pre_target;
        // ---------------- //
        /*
        pre_target->next = target->next;
        target->next->prev = pre_target;
        target->prev->prev->next = target;
        target->prev = target->prev->prev;
        target->next = pre_target;
        pre_target->prev = target;
        pre_target = target->prev;
        */
    }
    if (target->prev == NULL)
            *head = target;
    return position;


}

void printlist(elem *head)
{
    if(head == NULL) return;

    printf("%d\t", head->key);
    printlist(head->next);
}

int main()
{
    int n, key;
    scanf("%d", &n);
    elem *list = NULL;
    int query;
    int result = 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &key);
        list = insCoda(list, key);
    }

    while(result != -1){
        scanf("%d", &query);
        result = counter(&list, query);
        printf("%d\n", result);
        // printf("----------\n");
        // printlist(list);
        // printf("\n----------\n");
    }
     
    return 0;
}
