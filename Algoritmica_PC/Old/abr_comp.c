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

int searchComparison(nodo* t, nodo* u, int key)
{
    nodo* current_1 = t;
    nodo* current_2 = u;
    if(current_1->key!=current_2->key)
        return 0;
    while (current_1 != NULL && current_2 != NULL)
    {
        if(key == current_1->key && key == current_2->key) return 1;
        else if(key > current_1->key && key > current_2->key)
        {   
            current_1 = current_1->right;
            current_2 = current_2->right;
            if(current_1->key!=current_2->key)
                return 0;
        }

        else if(key < current_1->key && key > current_2->key)
        { 
            current_1 = current_1->left;
            current_2 = current_2->right;
            if(current_1->key!=current_2->key)
                return 0;
        }

        else if(key < current_1->key && key < current_2->key)
        { 
            current_1 = current_1->left;
            current_2 = current_2->left;
            if(current_1->key!=current_2->key)
                return 0;
        }
        else if(key > current_1->key && key < current_2->key)
        { 
            current_1 = current_1->right;
            current_2 = current_2->left;
            if(current_1->key!=current_2->key)
                return 0;
        }
    }

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
        visitaOrdinata(t->left);
    printf("%d", t->key);
    visitaOrdinata(t->right);
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
    int k;
    scanf("%d %d", &n, &k);
    nodo *tree_1 = NULL;
    nodo *tree_2 = NULL;
    int key;
    //insert elements in tree one
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &key);
        tree_1 = insert_ricorsiva(tree_1, key);
    }
    // insert elements in tree two
    for (int j = 0; j < n; j++)
    {
        scanf(" %d", &key);
        tree_2 = insert_ricorsiva(tree_2, key);
    }
    printf("%d", searchComparison(tree_1, tree_2, k));
    return 0;    
}