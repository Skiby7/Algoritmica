#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int key;
    int color;
    struct _nodo *left;
    struct _nodo *right;
} nodo;

nodo* insert_ricorsiva(nodo *t, int key, int color)
{
    if (t==NULL)
    {
        nodo* new = (nodo *) malloc(sizeof(nodo));
        new->key = key;
        new->color = color;
        new->left=NULL; 
        new->right=NULL;          
        return new;
    }
    if(t->key < key)
        t->right = insert_ricorsiva(t->right,key, color);
    
    else
        t->left = insert_ricorsiva(t->left, key, color);
    
    return t;
}

//Ritorno 1 se la condizione e' TRUE, 0 altrimenti

int max(int a, int b)
{
    if(a > b)
        return a;

    return b;
}
int maxred(nodo *t)
{
    if(t == NULL)
        return 0;
    
    else if(t->color == 0)
        return 1 + max(maxred(t->left), maxred(t->right));
    
    else
        return max(maxred(t->left), maxred(t->right));
    
}

int check(nodo *t)
{
    if(maxred(t->left)-maxred(t->right) > 1)
        return 0;

    return 1;

}


int main()
{
    int N;
    scanf("%d", &N);
    if (N == 0) 
    {
       printf("TRUE\n");
       return 0;
    }
    nodo *tree = NULL;
    int value;
    int color;
    for (int i = 0; i < 2*N; i++)
    {
        scanf(" %d", &value);
        scanf(" %d", &color);
        tree = insert_ricorsiva(tree, value, color);
    }

    
    if (check(tree) == 1)
        printf("TRUE\n");
    
    else
        printf("FALSE\n");

    return 0;

    


    


}