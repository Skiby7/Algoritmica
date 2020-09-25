#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *right;
    struct node *center;
    struct node *left;
} nodo;

nodo* insTern(nodo* t, int key)
{
    if(t == NULL)
    {
        nodo *new = (nodo *)malloc(sizeof(nodo));
        new->key = key;
        new->right = NULL;
        new->center = NULL;
        new->left = NULL;
        return new;
    }
    else if(t->key > key)
        t->left = insTern(t->left, key);
    
    else if(key % t->key == 0)
        t->center = insTern(t->center, key);
    
    else
        t->right = insTern(t->right, key);
    
    return t;
}

int verify(nodo *t)
{
    int curr, r, l, c;
    curr = c = r = l = 0;
    if(t == NULL)
        return 0;
    if(t->right != NULL)
    {
        r = verify(t->right);
        curr++;
    }
    if(t->center != NULL)
    {
        c = verify(t->center);
        curr++;
    }
    if(t->left != NULL)
    {
        l = verify(t->left);
        curr++;
    }
    if(curr == 3)
        return r + l + c + 1; // controlla se il primo nodo ha tre figli
    
    else
        return r + l + c; // r, l e c assumono il valore che ha curr a ogni iterazione sui loro figli fono alle foglie, i cui left center e right hanno valore null

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
        tree = insTern(tree, key);
    }
    printf("%d\n", verify(tree));
    return 0;

}