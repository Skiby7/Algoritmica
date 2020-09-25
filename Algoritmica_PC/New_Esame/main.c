#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _nodo{
    int key;
    struct _nodo *left;
    struct _nodo *right;
} nodo;

// Funzioni per trovare il minimo e il massimo fra due numeri. T(n) = Theta(1)
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Funzione che calcola la dimensione di un albero T(n) = Theta(n)

int prova;

    nodo* insert_ricorsiva(nodo *t, int key, int prova)
{
    if (t==NULL)
    {
        printf("%d\n", prova);
        nodo* new = (nodo *) malloc(sizeof(nodo));
        new->key = key;
        new->left=NULL; 
        new->right=NULL;          
        return new;
    }
    if(t->key >= key){ // Se due chiavi sono uguali, inserisco a sinistra
        if (t->left == NULL)
            prova++;
        t->left = insert_ricorsiva(t->left,key, prova);
    }
    else{
        if(t->right == NULL)
        t->right = insert_ricorsiva(t->right, key, prova);
    }
    
    return t;
}

void tree_free(nodo *root) {
    if (root == NULL)
        return;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

int main()
{
    int n; // Numero di elementi da inserire
    scanf("%d", &n);
    prova = 0;
    // int *prov = &prova;
    int key;
    nodo* tree = NULL;
    for (int i = 0; i < n; i++){
        scanf(" %d", &key);
        tree = insert_ricorsiva(tree, key, prova);
    }
    int res = prova;
    printf("%d\n", res);
    tree_free(tree);
    
    return 0;
} 