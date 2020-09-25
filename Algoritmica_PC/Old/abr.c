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
    int j;
    int result;
    while (j >= 0)
    {
        scanf(" %d", &j);
        result = cerca(tree, j);
        if(result >= 0)
            printf("%d\n", result);

        else if(result < 0 && j >= 0)
            printf("NO\n");        
    }
    return 0;    
}