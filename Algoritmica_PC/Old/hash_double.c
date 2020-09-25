#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define p 999149

typedef struct node
{
    int value;
    struct node *next;
} item;
int hashvalue(int a, int b, int key, int n)
{
    int hash = ((a*key + b) % p) % (2*n);
    return hash;
}

item* insTesta(item* head, int key)
{
    item *new = (item *)malloc(sizeof(item));
    new->value = key;
    if(head == NULL) 
        new->next = NULL;
    else
        new->next = head;
    return new;
}
int check(item* T, int key)
{
    while(T != NULL)
    {
        if(T->value == key)
            return 0;
        
        T = T->next;
    }
    return 1;
}
item** insertion(item** T, int key, int n, int a, int b, int result[])
{
    int i = hashvalue(a, b, key, n);
    if(check(T[i], key) != 0)
        T[i] = insTesta(T[i], key);
    else
        result[2]++;
        
}

void init(item** T, int n)
{
    for (int i = 0; i < n; i++)
        T[i] = NULL;
}
void printList(item *head)
{
    if(head == NULL) return;

    printf("%d ", head->value);
    printList(head->next);
}
void printHash(item **T, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(T[i] == NULL)
            printf("NULL\n");
        printList(T[i]);
        printf("\n");
    }
}

void conflict(item **T, int n, int result[])
{
    int count = 0;
    int temp = 0;
    int max_count = 0;
    int nulls = 0;
    for (int i = 0; i < n; i++)
    {
        if(temp > max_count)
            max_count = temp;
        
        temp = 0;
        if(T[i] != NULL)
            nulls++;
        while(T[i] != NULL)
        {            
            count++;
            temp++;
            T[i] = T[i]->next;
        }
    }
    result[1] = max_count;
    result[0] = count - nulls;
}

int main()
{
    int m;
    scanf("%d", &m);
    int n = 2*m;
    int a, b;
    scanf(" %d", &a);
    scanf(" %d", &b);
    item **T = (item **)malloc(n*sizeof(item *));
    init(T, n);
    int key;
    int result[] = {0, 0, 0};
    for (int i = 0; i < m; i++)
    {
        scanf(" %d", &key);
        insertion(T, key, m, a, b, result);
    }
    //printHash(T, n);
    conflict(T, n, result);
    printf("%d\n%d\n%d", result[0], result[1], m-result[2]);
    return 0;
}