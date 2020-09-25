#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _queue{
    char name[101];
    struct _queue *next;
    struct _queue *prev;
} queue;

void printarray(char **patients, int counter)
{
    for (int i = 0; i < counter; i++)
        printf("%s\n", patients[i]);    
}

int compare(const void *a, const void *b)
{
    char **a1= (char **)a;    
    char **b1= (char **)b;     
    return strcmp(*a1,*b1);
}

void insCoda(queue **head, queue **tail, char *name)
{
    
    queue* new = malloc(sizeof(queue));
    strcpy(new->name, name);
    new->next = NULL; 
    new->prev = *tail; 
    
    if(*tail != NULL) {
        (*tail)->next = new;
    }
    
    *tail = new;
    
    if(*head == NULL) {
        *head = new;
    }

}

void free_patients(queue *head)
{
    if (head == NULL)
        return;
    
    free_patients(head->next);
    free(head);
}

void free_last(queue** patients_tail)
{
    if ((*patients_tail)->next == NULL && (*patients_tail)->prev == NULL){
        *patients_tail = NULL;
        return;
    }
    queue *be_free = *patients_tail;
    *patients_tail = (*patients_tail)->prev;
    (*patients_tail)->next = NULL;
    free(be_free);
}

void transfer(queue *patients, char **next_day)
{
    for (int i = 0; patients != NULL; i++){
        strcpy(next_day[i], patients->name);
        patients = patients->next;
    }    
    
}

void printlist(queue *head)
{
    if(head == NULL) return;

    printf("%s ", head->name);
    printlist(head->next);
}

int main()
{
    int e; //orario di apertura
    queue *patients_head = NULL;
    queue *patients_tail = NULL;
    char name[101];
    int counter = 0;
    while (1){
        scanf(" %d", &e);
        if (e == 1){
            scanf(" %s", name);
            insCoda(&patients_head, &patients_tail, name);
            counter++;
        }
        if (e == 2){
            free_last(&patients_tail);
            counter--;
        }
        if (e == 0)
            break;
        printf("\t\t Counter: %d", counter);
        printf("\n");
        printf("\t\t");
        printlist(patients_head);
        printf("\n");
    }
    counter++;
    char **next_day = (char **) malloc(counter*sizeof(char *));
    transfer(patients_head, next_day);
    char last = '$';
    strcpy(next_day[counter-1], &last);
    qsort(next_day, counter, sizeof(char *), compare);
    printarray(next_day, counter);
    for (int j = 0; j < counter; j++)
        free(next_day[j]);
    
    free(next_day);
    free_patients(patients_head);
    
    
}