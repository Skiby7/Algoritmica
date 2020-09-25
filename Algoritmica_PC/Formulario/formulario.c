#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101

//--------------Ricerca binaria---------------//

//binary search su interi
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        else if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        else 
            return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 
//binary search su stringhe
int binarySearch(char **array, int start, int size, char *target)
{
    int q;
    int comp;
    char *stringa;
    if(start > size) return -1;

    else
    {
        q = (start + size)/2;
        stringa = array[q];
        comp = strcmp(stringa, target);
        if(comp == 0) return q;
        else if(comp < 0) return binarySearch(array, q+1, size, target);
        else return binarySearch(array, start, q-1, target);
    }
}

//--------------Ordinamento---------------//

//Selection sort su interi

void selectionSort(int a[], int n)
{
    int temp;
    int min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[min])
            {
                min = j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
        
    }
    
}

//Insertion sort su interi

void insertionSort(int a[], int n)
{
    int j;
    int k;
    for(int i = 1; i < n; i++)
    {
        k = a[i];
        j = i-1;
        while(j >= 0 && a[j] > k)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = k;
    }
}

//Insertion sort su stringhe

void insStr(char **str, int n)
{
    int i;
    int j;
    char *k;
    for(i = 1; i < n; i++)
    {
        k = str[i];
        j = i-1;
        while((j >= 0) && (strcmp(str[j], k) > 0))
        {
            str[j+1]=str[j];
            j--;
        }
        str[j+1] = k;
    }
}

//Quicksort su stringhe

int partition(char **array, int min, int max)
{
    char *pi;
    pi = array[max];
    int i = (min-1);
    for (int j = min; j <= max-1; j++)
    {
        if(strcmp(array[j], pi) < 0)
        {
            i++;
            char tmp[MAXLEN];
            strcpy(tmp, array[i]);
            strcpy(array[i], array[j]);
            strcpy(array[j], tmp);
        }
    }
    char tmp_1[MAXLEN];
    strcpy(tmp_1, array[i + 1]);
    strcpy(array[i + 1], array[max]);
    strcpy(array[max], tmp_1);
    return (i+1);
}    

void quicksort(char **array, int min, int max)
{
    if(min < max)
    {
        int pivot = partition(array, min, max);
        quicksort(array, min, pivot-1);
        quicksort(array, pivot+1, max);
    }
}

//--------------Liste---------------//

// Definizione e inserimento in testa in una lista monodirezionale

typedef struct lista
{
    int key;
    struct lista *next;
} elem;

elem* insTesta(elem *head, int key)
{
    elem *new = (elem *)malloc(sizeof(elem));
    new->key = key;
    if(head == NULL) 
        new->next = NULL;
    else
        new->next = head;
    return new;
}

//Inserimento in coda in una lista monodirezionale

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

//Stampa lista in ordine

void printlist(elem *head)
{
    if(head == NULL) return;

    printf("%d\n", head->key);
    printlist(head->next);
}

//Stampa lista in ordine inverso

void printlist(elem *head)
{
    if(head == NULL) return;

    printlist(head->next);
    printf("%d\n", head->key);
}

//Definizione e inserimento in testa in una lista bidirezionale

typedef struct lista
{
    int key;
    struct lista *next;
    struct lista *prev;
} elem;

elem* insTesta(elem *head, int key)
{
    elem *new = (elem *)malloc(sizeof(elem));
    new->key = key;
    if(head == NULL) 
    {
        new->next = NULL;
        new->prev = NULL;
    } 
    else
        {
            new->next = head;
            new->prev = NULL;
        }
    return new;
}

//Ricerca in lista

int cerca(elem *head, int key)
{
    int position = 0;
    while(head != NULL)
    {
        if(head->key == key)
            return position;
        
        head = head->next;
        position++;
    }
    return -1;
}
//---------------Alberi Binari--------------//


//Definizione, ricerca (profondita') e inserimento in ABR

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

//Visita ordinata ABR

void visitaOrdinata(nodo *t)
{
    if(t != NULL)
    {
        visitaOrdinata(t->left);
        printf("%d\n", t->key);
        visitaOrdinata(t->right);
    }
}

//MaxDepth

int maxDepth (nodo *t)
{
    if(t == NULL)
        return 0;
    
    return 1 + max(maxDepth(t->left), maxDepth(t->right));
}

//Confronto fra cammini per arrivare a una chiave

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

//Algoritmo min Max path dell'esercizio d'esame

/**
 * L'algoritmo fa una visita di tipo postorder ricorsiva, accumulando la somma
 * del percorso e il minimo dopo aver effettuato le chiamate ricorsive.
 * Se l'albero è vuoto restituisce zero sia per la somma, sia per il minimo.
 * Gli indirizzi puntati da min_key e sum saranno popolati con i risultati.
 */
void min_max_path(nodo* root, int *min_key, int *sum) {
    // Caso base della ricorsione, restituiamo zero.
    // Attenzione: potremmo usare le foglie come caso base, ma questo
    // richiederebbe comunque di gestire il caso di un albero vuoto e più
    // istruzioni condizionali nei passi ricorsivi.
    if (root == NULL) {
        *sum = 0;
        *min_key = 0;
        return;
    }

    // Allocazione dello spazio per i risultati e visita postorder
    int left_min, right_min;
    int left_sum, right_sum;
    min_max_path(root->left, &left_min, &left_sum);
    min_max_path(root->right, &right_min, &right_sum);

    // Caso in cui il ramo sinistro ha un percorso maggiore o uguale a quello destro
    if (left_sum >= right_sum) {
        *sum = left_sum + root->key;
        // In generale, per l'invariante degli ABR il figlio sinistro di un
        // vertice è più piccolo del vertice stesso, ma nel caso in cui i due percorsi
        // siano uguali e non c'è alcun ramo sinistro non possiamo restituire left_min,
        // ma dobbiamo restituire la radice senza figlio sinistro.
        *min_key = root->left != NULL ? left_min : root->key;
    } else {
        *sum = right_sum + root->key;
        // In generale, per l'invariante degli ABR il figlio destro di un vertice è
        // più grande del vertice stesso, quindi restituiamo sempre il vertice.
        *min_key = root->key;
    }
}

//Libera albero

void tree_free(nodo *root) {
    if (root == NULL)
        return;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
}

//-----------------------Hash table-------------------------//
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

item** insertion(item** T, int key, int n, int a, int b)
{
    int i = hashvalue(a, b, key, n);
    T[i] = insTesta(T[i], key);
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
    result[0] = max_count;
    result[1] = count - nulls;
}

int main() //Main dell'esercizio sulla tabella hash
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
    for (int i = 0; i < m; i++)
    {
        scanf(" %d", &key);
        insertion(T, key, m, a, b);
    }
    //printHash(T, n);
    int result[] = {0, 0};
    conflict(T, n, result);
    printf("%d\n%d", result[0], result[1]);
    return 0;
}

//---------------Grafi----------------//
//Copia-incolla dalle slide

//~~~~~~~~~~Liste di adiacenza~~~~~~~~~~//
typedef struct _edge 
{
    struct _edge * next;
    int nodeid;
} edge;
//In main
int main()
{
    int N ; //Numero liste di adiacenza
    edge **E = (edge **) malloc(N*sizeof(edge *));
}
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~Liste compatte~~~~~~~~~~//
typedef struct _edges 
{
    int num_edges;
    int * edges;
} edges;

int main()
{
    int N;
    edges *E = (edges *) malloc(N*sizeof(edges));
}

//Lettura grafico da input

edges* read_graph()
{
    edges *E;
    int n, ne, i, j;

    scanf("%d", &n);
    E = (edges *)malloc(sizeof(edges)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(ne));
        E[i].num_edges = ne;
        E[i].edges = (int *)malloc(sizeof(int)*ne);
        for (int j = 0; j < ne; j++)
            scanf("%d", E[i].edges + j);
    }
    return E;
    
}

//------------------------------//


int main()
{
    printf("Hello World\n");
    return 0;
}