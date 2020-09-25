#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101

// Scopo del programma: preso un array di stringhe al massimo di 101 caratteri 
// che possono ripetersi (NB ogni stringa diversa si ripete un numero diverso di volte), stampa in ordine lessicografico le K stringe piu frequenti.
// Esempio input: 6 (N elementi) minnie pluto paperino pluto paperino pluto. Output: paperino\n pluto

typedef struct string{
    char stringa[MAXLEN];
    int freq; 
}string; //Struttura in cui salvo la frequenza con cui si presentano le stringhe (Per gulo: se hai visto le classi ==> struct ~= classe)

// Inzio funzioni compare per il qsort (quicksort di <stdlib>)
int compare(const void *a, const void *b)
{
    char **a1= (char **)a;    
    char **b1= (char **)b;     
    return strcmp(*a1,*b1);
} // Ordino l'array di stringhe lessicograficamente


int compare2(const void *a, const void *b)

{
    string a1= *(string *)a;    
    string b1= *(string *)b;      
    return b1.freq - a1.freq;
} // Ordino l'array di struct stringhe per frequenza

int compare3(const void *a, const void *b)
{
    string a1= *(string *)a;    
    string b1= *(string *)b;          
    return strcmp(a1.stringa, b1.stringa);
} // Ordino l'array di struct stringhe lessicograficamente
// Fine funzioni per il qsort

//---------------Inizio algoritmo dell'esercizio-------------//


//Idea: ordino lessicograficamente l'array di stringhe, aggiungo la prima stringa nell'array di struct e incremento la frequenza 
//finche' non cambia stringa (essendo ordinate, vuol dire che non ce ne sono piu di stringhe uguali)

void checkfreq(string* freq, char **array, int n, int* count)
{
    int i = 1;
    int j = 0;
    while (i < n){
        strcpy(freq[j].stringa, array[i-1]); //Copio la stringa i-esima nell'array di struct
        freq[j].freq = 1; //La frequenza per ora e' 1
        // prinf("Here\n");
        // Finche' non trovo una stringa diversa incremento freq
        while(i < n && strcmp(array[i-1], array[i]) == 0){ 
            freq[j].freq++;
            i++;
            // prinf("Now here\n");
        }
        i++;
        j++; //Ho trovato la striga diversa, incremento j e ricomincia la festa
    }
    *count = j; // Salvo il numero di elementi distinti
}


void printarray(string* freq, int size)
{
    for (int i = 0; i < size; i++)
        printf("%s -> %d\n", freq[i].stringa,freq[i].freq);
    
}


int main()
{
    int size; //N elementi
    scanf("%d", &size);
    int k; // I primi K che voglio ordinati
    scanf(" %d", &k);


    char **array; // Array di stringhe
    array = (char **)malloc(size*sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        array[i] = (char *) malloc(MAXLEN*sizeof(char));
        scanf(" %s", array[i]);
    }
    qsort(array, size, sizeof(char *), compare); // Ordino l'array lessicograficamente


    /*for (int h = 0; h < size; h++)
        printf("%s\t", array[h]);
    printf("\n");*/ //Stampo semplicemente l'array per vedere che sia tutto ok
    
    int count = 0;
    int *c = &count; // Numero di elementi distinti
    string *freq = (string *)malloc(size*sizeof(string)); // Array di struct
    checkfreq(freq, array, size, c);
    // printarray(freq, count); check dell'array di struct
    qsort(freq, count, sizeof(string), compare2); // Ordino per frequenza
    qsort(freq, k, sizeof(string), compare3); // Ordino lessicograficamente i primi K elementi per poi stamparli
    for (int p = 0; p < k; p++)
        printf("%s\n", freq[p].stringa); // Output
    
    // Libero la memoria allocata
    for (int j = 0; j < size; j++)
        free(array[j]);
        
    free(freq);
    free(array);

    return 0;

}

