#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN_NAME 101
#define MAXLEN_NUMBER 21


typedef struct node
{
    char name[MAXLEN_NAME];
    char number[MAXLEN_NUMBER];
    struct node *next;
} item; // Elemento della rubrica

// Prendo in input il nome e il numero di elementi per calcolare l'hash value
unsigned int hashvalue(char *name, int n) 
{
    unsigned int hash = 0;
    for (int i = 0; name[i] != '\0'; i++)
        hash += name[i];
    
    return hash%n;
}

// Inserimento in lista di trabocco
item* insList(item* head, char* name, char* number)
{
    // Se il puntatore dell'elemento T[i] è NULL, inserisco direttamente name e number
    if (head == NULL){
        item *new = (item *)malloc(sizeof(item));
        strcpy(new->name, name);
        strcpy(new->number, number);
        new->next = NULL;
        // printf("New insertion\n");
        return new;
    } 
    if(head->next == NULL){
        if(strcmp(head->name, name) < 0){
            item *new = (item *)malloc(sizeof(item));
            strcpy(new->name, name);
            strcpy(new->number, number);
            new->next = NULL;
            head->next = new;
            // printf("New insertion\n");
            return head;
        }
        else{
            item *new = (item *)malloc(sizeof(item));
            strcpy(new->name, name);
            strcpy(new->number, number);
            new->next = head;
            head->next = NULL;
            // printf("New insertion\n");
            return new;
        }
    }
    // Se ho già un elemento nella lista lo confronto il campo number per inserirlo in ordine lessicografico
    item *scanner; // Serve per scorrere la lista
    scanner = head;
    // Finché non trovo un elemento scanner->next che è lessicograficamente maggiore del nome che voglio inserire non mi fermo
    while(scanner != NULL && strcmp(scanner->name, name) < 0) 
        scanner = scanner->next;
    
    // Creo new con i nuovi name e number
    item *new = (item *)malloc(sizeof(item));
    strcpy(new->name, name);
    strcpy(new->number, number);
    item *tmp = scanner->next;

    new->next = tmp; // new ha come successore lo stesso di scanner next
    scanner->next = new; // scanner invece ha come successore new
    // printf("Fine inserimento ordinato");
    return head; // Ritorno l'inizio della lista ordinata
}

item** insertion(item** T, char* name, char* number, int n)
{
    unsigned int i = hashvalue(name, n); // Calcolo l'hash value 
    // printf("hashvalue: %d\n", i);
    T[i] = insList(T[i], name, number); // Inserisco il nuovo elemento al posto i
    return T;
}

// Inizializzo la tabella hash
void init(item** T, int n)
{
    for (int i = 0; i < n; i++)
        T[i] = NULL;
        
}

// Funzione che stampa la lista in ordine
void printList(item *head)
{

    if(head == NULL) return;
    printf("%s %s\n", head->name, head->number);
    printList(head->next);
}

int main() 
{
    int m; // Numero di elementi da inserire
    scanf("%d", &m);
    int n = 2*m; // Dimensione della tabella hash
    item **T = (item **)malloc(n*sizeof(item *));
    init(T, n);

    char *name = (char *) malloc(MAXLEN_NAME*sizeof(char));
    char *number = (char *) malloc(MAXLEN_NUMBER*sizeof(char));

    for (int i = 0; i < m; i++){
        scanf(" %s", name);
        scanf(" %s", number);
        T = insertion(T, name, number, n);
        
    }
    int k; // K-esima lista da stampare
    scanf(" %d", &k);
    printList(T[k]);
    
    return 0;
}