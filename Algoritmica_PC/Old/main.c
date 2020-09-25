/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct lista        //Ok
{
    int key;
    struct lista *next;
} elem;

elem* insTesta(elem *head, int key)             //la funzione è giusta, però non ti serve, ti serve quella che aggiunge in coda
{                                               //Questa è meglio se la integri nella funzione che mette in testa l'emento una volta trovato (quindi nella mtf)
    elem *new = (elem *)malloc(sizeof(elem));
    new->key = key; 
    
    //Ridondante, basterebbe un "new->next = head;""
    //---------------
    if(head == NULL)           
        new-> next = NULL;
    else
        new-> next = head;
    //---------------
        
    return new;
}

//Invece dello swap ti conviene utilizzare  utilizzare una funzione di inserimento in coda che
// percorre tutta la lista e quando incotnra null inserisce l'elemento: in questo modo avrai
//bisogno soltanto di un puntatore (quello alal testa della lista)
elem* insCoda(elem* head, int key){     
    
    if(head == NULL){                           //questo è il caso del primo elemento della lista
            elem *new = (elem *)malloc(sizeof(elem));
            new-> key = key; 
            head = new;
          return head;                          //Qui ritorno il puntatore perchè non so come mai non me lo modificava quando lo passavo, quindi non è pulitissima come soluzione
                                                //la funzione ins coda dovrebbe essere void e mantenere il puntatore alla na cred odovrai cercarti da oslo come ahah
    }
    elem* scanner = head;               //questo mi serve per scorrere la lista senza modificare il puntatore alla testa delal lista
    
    while(scanner -> next != NULL){     //Questo ciclo fa scorrere la lista. NOTA BENE: viene controllato il valo del campo "puntatore al successivo"
        scanner = scanner -> next;      //anzichè il puntatore stesso, in questo modo posso garantire di star attaccando il nuovo elemtno alla lista;
                                        //Se facessi il controllo sul puntatore stesso (scanne!=null) arriverei nel vuoto ed assegneri l'elemento ad una roba fuori dalla lista
    }                               //Quest'ultimo concetto è importante perchè è quello che genera più confusione con le liste
      
    //Una volta usciti dal ciclo, scanner sarà l'ultimo elemneto della lista  , a questo punto gli assegno il nuovbo elemento
      
    scanner -> next = (elem *)malloc(sizeof(elem));
    scanner -> next -> key = key;       //questo è un po' critptico, ma vorrebbe dire "assegna la chiave all'elemento puntato da scanner"
    scanner -> next -> next = NULL; 
    
    return head;        //Come detto prima, qeusto ritorno non dovrebbe esserci ma la funzione deve poter modificare il puntatore alla testa
}


void swap(elem *a, elem* b)     
{
    //Questa funzione la chiami nel main subito dopo aver creato la lista ma quello che fa è prendere 
    // "second" (che è null) ed inserirlo in testa con la stessa key dell'elemento che hai in testa 
    //e cosi via per tutti i successivi elementi della lista.
    while(a->next != NULL)      
    {
        insTesta(b, a->key);
        a = a->next;
    }
}

void printlist(elem *head)  //Ok, anche sen on ti serve per l'esercizio ti può servire per vedere se hai fatto cagate
{
    if(head == NULL) return;  

    printf("%d\n", head->key);      //Ricorda che se metti la stampa prima della chiamata ricorsiva stamperà la lista 
    printlist(head->next);          //dal primo elemnto all'ultimo, se invece metti la stampa dopo userà l'ordine inverso
}

int cerca(elem *head, int key)
{
    //Questa funzione non fa altro che trovare l'indice della lista 
    //che ha l'elemtno ma non fa operazion su di esso
    int position = 0;
    while(head != NULL)     //Ok, ma non salvo l'elemento che mi serve,
    {
        if(head->key == key){
            //Qui, prima di chiamare il ritorno sarebbe comodo utilizzare una ndell
            //funzione che hai implementato per poter riportare l'elemento in testa alla lista
            return position;
        }
        head = head->next;
        position++;
    }
    return -1;
}
void mtf(elem *head, int key)
{
   elem *pre_target = NULL;
   elem *target = head;
   while(key != 0)
   {
       target = target->next;
        if (key == 1)
            pre_target = target;
        
        key--;       
   }
   pre_target->next = target->next;
   target->next = head;
   head = target;
}

int main()
{
    int n, key;             
    scanf("%d", &n);
    
    //Anzichè questi due puntatori per due liste differenti, ti conviene avere due puntatori sulla stessa lista,
    // uno "head" che punta sempre al primo elemento per poter fare la mtf che mette l'elemento trovato come primo
    //e dunto "end" che è il puntatore a null dell'ultimo elemento della lista, in modo che per aggiungere un
    //elemento ti basta assegnarlo al puntatore e poi assegnare ad "end" il puntaatore del nuovo elemento
    elem *first = NULL;
    elem *second = NULL;    //Questo puntatore è utile quanto un buco del culo sul gomito
    for (int i = 0; i < n; i++)     //Ciclo per input degli elementi da tastiera: Ok
    {
        scanf("%d", &key);
        //first = insCoda(first, key);            //Non dovrebbe esserci l'assegnamento al puntatore di testa ma non funzionava la modifica al parametro nel passaggio
        first = insTesta(first, key);   //Ok
    }
    
  
    swap(first, second);    //lascia perdere la swap, è inutile creare una seconda lista inversa alla prima
                            // è solo spreco di memoria e codice ed è opù complesso, per inserire in coda basta salvarti nel ciclo 
                            //il puntatore all'ultimo elemento insreito e ogni volta che aggiungi lo cambi:
    
    int result = 0;
    int query;
    while(result != -1)
    {
        scanf("%d", &query);
        result = cerca(second, query);      //ok ma qui nessuno chiama la mtf
        printf("%d\n", result);
    }
    
    return 0;
}
