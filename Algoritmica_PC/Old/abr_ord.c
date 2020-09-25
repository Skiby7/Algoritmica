#include <stdio.h>
#include <stdlib.h>


typedef struct _nodo{
    int key;
    struct _nodo *p;
    struct _nodo *left;
    struct _nodo *right;
} nodo;

int cerca(nodo* t, int key)
{
    int depth = 0;
    nodo* current = t;
    while (current != NULL)
    {
        if(key == current->key) return depth;
        if(key > current->key)
            current = current->right;
        
        else
            current = current->left;
        depth++;     
    }
    return -1;
    
}
int max(int a, int b)
{
    if(a >= b)
        return a;
    else
        return b;
}

void visitaOrdinata(nodo *t)
{
    if(t != NULL)
    {
        visitaOrdinata(t->left);
        printf("%d\n", t->key);
        visitaOrdinata(t->right);
    }
}

int maxDepth (nodo *t)
{
    if(t == NULL)
        return 0;
    
    return 1 + max(maxDepth(t->left), maxDepth(t->right));
}

nodo* insert_ricorsiva(nodo *t, int key)
{
    if (t==NULL)
    {
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
int main()
{
    int n;
    scanf("%d", &n);
    nodo *tree = NULL;
    int key;
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &key);
        tree = insert_ricorsiva(tree, key);
    }
    visitaOrdinata(tree);
    return 0;    
}