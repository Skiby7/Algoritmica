#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[101];
    int key;
    struct node *next;
} item;

int compare(const void *a, const void *b)
{
    char **a1= (char **)a;    
    char **b1= (char **)b;     
    return strcmp(*a1,*b1);
}

int hashvalue(int key, int size)
{
    int hash = (key % 109)%(size);
    return hash;
}

item* insCoda(item *head, int key, char* name)
{
    if (head == NULL)
    {
        item *new = (item *)malloc(sizeof(item));
        new->key = key;
        strcpy(new->name, name);
        new->next = NULL;
        return new;
    }
    item *scanner;
    scanner = head;
    while(scanner->next != NULL){
        if (scanner->key == key){
            strcpy(scanner->name, name);
            return head;
        }
        scanner = scanner->next;
    }
    if (scanner->next == NULL && scanner->key == key){
        strcpy(scanner->name, name);
        return head;
    }
        
    if (scanner->next == NULL){
        scanner->next = (item *)malloc(sizeof(item));
        scanner->next->key = key;
        strcpy(scanner->next->name, name);
        scanner->next->next = NULL;
    }
    return head;
}

item** insertion(item** T, int size, int key, char *name)
{
    int i = hashvalue(key, size);
    T[i] = insCoda(T[i], key, name);
    return T;
}

void init(item** T, int n)
{
    for (int i = 0; i < n; i++)
        T[i] = NULL;
}
void printList(item *head)
{
    if(head == NULL) return;

    printf("%s -> %d ", head->name, head->key);
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

int transfer(item* head, char** array){
    int i = 0;
    while (head != NULL){
        array[i] = (char *) malloc(101*sizeof(char));
        strcpy(array[i], head->name);
        head = head->next;
        i++;
    }
    return i;
}
void freelist(item* head)
{
    while(head != NULL){
        item* befree = head;
        head = head->next;
        free(befree);
    }
}
int main() 
{
    int n; // Numero elementi
    scanf("%d", &n);
    int m = 2*n; // Size tabella hash
    item **T = (item **)malloc(m*sizeof(item *));
    init(T, m);
    int key;
    char name[101];
    for (int i = 0; i < n; i++){
        scanf(" %d", &key);
        scanf(" %s", name);
        insertion(T, m, key, name);
    }
    int k;
    scanf(" %d", &k);
    // printHash(T, n);
    char **array = (char **)malloc(m*sizeof(char*));
    
    int size_array = transfer(T[k], array);
    qsort(array, size_array, sizeof(char *), compare);
    if (size_array == 0)
        printf("vuota\n");
    for (int j = 0; j < size_array; j++)
        printf("%s\n", array[j]);
    
    for (int l = 0; l < m; l++)
        free(array[l]);
    free(array);
    for (int c = 0; c < m; c++)
        freelist(T[c]);
    
    free(T);
    
    return 0;
}