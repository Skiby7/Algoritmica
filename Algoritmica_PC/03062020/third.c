#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
    int value;
    char name[101];
    struct _node* next;
} item;

void init(item** T, int n)
{
    for (int i = 0; i < n; i++)
        T[i] = NULL;
}

void printList(item *head)
{
    if(head == NULL) return;

    printf("%s -> %d ", head->name, head->value);
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

unsigned int hashvalue(char *name, int n)
{
    unsigned int hashval = 0;
    for (int i = 0; name[i] != '\0'; i++)
        hashval += name[i];
    return hashval%n;  
}

int searchanddestroy(item *head, char *name, int value)
{
    if (head == NULL) return -1;

    if ((strcmp(head->name, name) == 0 && head->value < value)){
        head->value = value;
        return 1;
    }
    else if ((strcmp(head->name, name) == 0 && head->value > value))
        return 1;
    searchanddestroy(head->next, name, value);
}

item* insTesta(item *head, char *name, int key)
{
    item *new = (item *)malloc(sizeof(item));
    strcpy(new->name, name);
    new->value = key;
    if(head == NULL) 
        new->next = NULL;
    else
        new->next = head;
    return new;
}

item* insert(item* T, char *name, int key)
{
    if (searchanddestroy(T, name, key) == 1)
        return T;
    
    else
        T = insTesta(T, name, key);

    return T;
    

}
item** insertion(item** T, int n, char *name, int key)
{
    unsigned int i = hashvalue(name, n);
    T[i] = insert(T[i], name, key);
    return T;
}
int compare(const void *a, const void *b) 
{
   item a1 = *(item *)a, b1 = *(item *)b; 
   if((b1.value - a1.value) == 0)
    return strcmp(a1.name, b1.name);
    
   else
    return b1.value - a1.value;
}
void transfer(item** hashtable, item* all, int n)
{
    int j = 0;
    for (int i = 0; i < n && j < n/2; i++)
    {
        if (hashtable[i] == NULL)
            continue;
        
        while (hashtable[i] != NULL){
            strcpy(all[j].name, hashtable[i]->name);
            all[j].value = hashtable[i]->value;
            hashtable[i] = hashtable[i]->next;
            j++;
        }
    }
    qsort(all, n/2, sizeof(item), compare);
}

int main()
{
    int m; // number of elements
    scanf("%d", &m);
    int n = 2*m; // number of hash cells
    item** hashtable = (item**) malloc(n*sizeof(item*));
    init(hashtable, n);
    item* all = (item *) malloc(m*sizeof(item));
    int value; 
    char name[101];
    for (int i = 0; i < m; i++){
        scanf(" %s", name);
        scanf(" %d", &value);
        hashtable = insertion(hashtable, n, name, value);
    }
    printHash(hashtable, n);
    transfer(hashtable, all, n);
    for (int j = 0; j < 15; j++)
        printf("%s\n", all[j].name);
    

    return 0;

}