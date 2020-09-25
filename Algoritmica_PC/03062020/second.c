#include <stdio.h>
#include <stdlib.h>


typedef struct _nodo{
    int key;
    struct _nodo *left;
    struct _nodo *right;
} nodo;

typedef struct lista
{
    int key;
    struct lista *next;
} elem;

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

nodo* insert_ricorsiva(nodo *t, int key)
{
    if (t==NULL){
        nodo* new = (nodo *) malloc(sizeof(nodo));
        new->key = key;
        new->left=NULL; 
        new->right=NULL;          
        return new;
    }
    if(t->key < key)
        t->right = insert_ricorsiva(t->right,key);
    
    else
        t->left = insert_ricorsiva(t->left, key);
    
    return t;
}

int L, R;


void result(nodo* t, elem* res, int L, int R)
{
    if (t == NULL)
        return;

    result(t->left, res, L, R);
    if (t->left != NULL)
        L++;

    if (t->right != NULL)
        R++;
    if (L > R)
        res = insCoda(res, t->key);
    result(t->right, res, L, R);

    
    
    printf("%d %d\n", L, R);

}

void printlist(elem *head)
{
    if(head == NULL) return;

    printf("%d\n", head->key);
    printlist(head->next);
    
}

int main()
{
    int n;
    scanf("%d", &n);
    nodo *tree = NULL;
    elem *res = NULL;
    L = R = 0;
    int key;
    for (int i = 0; i < n; i++){
        scanf(" %d", &key);
        tree = insert_ricorsiva(tree, key);
    }
    result(tree, res, L, R);
    printlist(res);
    return 0;    
}