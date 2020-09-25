#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101
// Scopo del programma: ho un array di stringhe al massimo di 101 caratteri. 
// Le stringhe possono ripetersi (NB ogni stringa diversa si ripete un numero diverso di volte).
// Esempio input: 6 (N elementi) minnie pluto paperino pluto paperino pluto.
// Una volta preso l'input, devo creare un array di struct in cui sono contenute le stringhe e la frequenza con cui si ripetono.
typedef struct string{
    char *stringa;
    int freq; 
}string;

int compare(const void *a, const void *b)
{
    char **a1= (char **)a;    
    char **b1= (char **)b;     
    return strcmp(*a1,*b1);
}

/*int compare2(const void *a, const void *b)
{
    string a1= *(string *)a;    
    string b1= *(string *)b;      
    return b1.freq - a1.freq;
}*/

//Idea: ordino lessicogra(fica)mente l'array di stringhe, aggiungo la prima stringa e incremento la frequenza finche' non cambia stringa 
void checkfreq(string** freq, char **array, int n)
{
    int j = 0;
    for (int i = 1; i < n; i++){
        strcpy(freq[j]->stringa, array[i]);
        freq[j]->freq++;
        if(strcmp(array[i-1], array[i]) == 0){
            /*while(strcmp(array[i], array[i+1]) == 0){
                freq[j].freq++;
                i++;
            }*/
            printf("here");
        }
        j++;
    }
}
//Mi da' segmentation fault qui.

void printarray(string** freq, int size)
{
    for (int i = 0; i < size; i++)
        printf("%s -> %d\n", freq[i]->stringa,freq[i]->freq);
    
}

int main()
{
    int size; //N elementi
    scanf("%d", &size);
    int k;
    scanf(" %d", &k);
    char **array;
    array = (char **)malloc(size*sizeof(char *));
    for (int i = 0; i < size; i++)
    {
        array[i] = (char *) malloc(MAXLEN*sizeof(char));
        scanf(" %s", array[i]);
    }
    qsort(array, size, sizeof(char *), compare); // Ordino l'array lessicogra(fica)mente


    for (int h = 0; h < size; h++)
        printf("%s\t", array[h]);
    printf("\n"); //Stampo semplicemente l'array per vedere che sia tutto ok


    string **freq = (string **)malloc(size*sizeof(string *)); // Array di struct
    for (int s = 0; s < size; s++)
        freq[s] = (string *)malloc(MAXLEN*sizeof(string));
    
    checkfreq(freq, array, size);
    printarray(freq, size);
    /*qsort(freq, size, sizeof(string), compare2);
    for (int l = 0; l < k; l++)
        printf("%s\n", freq[l].stringa);*/
    // Libero la memoria allocata
    for (int j = 0; j < size; j++)
        free(array[j]);

    free(array);
    return 0;
}
