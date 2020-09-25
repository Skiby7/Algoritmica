#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1001

typedef struct object
{
    int value;
    char name[MAX];
    struct object* next;
} oggetto;

void init(oggetto** T, int n)
{
    for (int i = 0; i < n; i++)
        T[i] = NULL;
}
int hashValue(char *string)
{
    int len = strlen(string);
    unsigned int hashvalue = 0;
    for (int i = 0; i < len; i++)
        hashvalue += string[i];
    return hashvalue;
    
}
int check(oggetto** hash, int n, char *name, int value)
{
    for(int i = 0; i < n; i++)
    {
        if(hash[i] == NULL)
            continue;
        
        else
        {
            while (hash[i] != NULL)
            {
                if(strcmp(name, hash[i]->name) == 0)
                    return 1;
                else if(strcmp(name, hash[i]->name) == 0 && hash[i]->value <= value)
                    return 2;
                else if(strcmp(name, hash[i]->name) == 0 && hash[i]->value > value)
                {
                    hash[i]->value = value;
                    return 0;
                }
                hash[i] = hash[i]->next;
            }
        }
        
    }
    return -1;
}
oggetto* insTesta(oggetto* head, const char *name, int value)
{
    oggetto *new = (oggetto *)malloc(sizeof(oggetto));
    new->value = value;
    strcpy(new->name, name);
    new->next = head;
    return new;
}

void insertion(oggetto** hash, int n, char *name, int value)
{
    //Qui n è il numero di celle disponibili in tabella (2*n)
    unsigned int i = hashValue(name)%n;
    if(check(hash, n, name, value) < 0)
        hash[i] = insTesta(hash[i], name, value);
}

void printlist(oggetto *hash)
{
    if(hash == NULL)
        return;

    printf("%s -> %d", hash->name, hash->value);
    printlist(hash->next);
}

void printhash(oggetto** hash, int n)
{
    for (int i = 0; i < n; i++)
    {
        printlist(hash[i]);
        printf("\n");
    }
    
}
int main()
{
    //Qui n è il numero di elementi presenti in tabella
    int n;
    scanf("%d", &n);
    oggetto **hash = (oggetto **)malloc(2*n*sizeof(oggetto*));
    init(hash, 2*n);
    char *name = (char *)malloc(MAX*sizeof(char));
    int value;
    for (int i = 0; i < n; i++)
    {
        scanf(" %s", name);
        scanf(" %d", &value);
        insertion(hash, 2*n, name, value);
    }
    printhash(hash, n);
    return 0;
}