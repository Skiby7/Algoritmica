#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct punti_colorati{
    int x;
    int y;
    int c;
} point;

typedef struct query_colorate{
    int x1;
    int x2;
    int y1;
    int y2;
} query;

int confrontaint(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a);
}

int compare(const void *a, const void *b) 
{
    point a1 = *(point *)a, b1 = *(point *)b; 
        return b1.c - a1.c;
}

void search(point* r, query* q, int result[], int n, int m)
{
    int help[n];
    for (int h = 0; h < n; h++)
        help[h] = -1;
    int count;
    int help_last;
    int l;
    qsort(r, n, sizeof(point), compare);
    for (int i = 0; i < m; i++){
        count = 0;
        for(int j = 0; j < n; j++){
            if(r[j].x <= q[i].x2 && r[j].x >= q[i].x1){
                if(r[j].y <= q[i].y2 && r[j].y >= q[i].y1){
                    help[j] = r[j].c;
                    // printf("Here\n");
                }
            }
        }
        // printf("Now Here\n");
        // qsort(help, n, sizeof(int), confrontaint);
        // for (int q = 0; q < n; q++)
            // printf("%d\t", help[q]);
        
        // printf("\n");
        
        l = 0;
        help_last = -1;
        while(l < n){
            if(help[l] == -1){
                l++;
                continue;
            }
            if(help[l] != help_last){
                count++;
                // printf("\t\tcount\t\t\t");
                help_last = help[l];
                // printf("help_last -> %d help[l] -> %d\n", help_last, help[l]);
                l++;
                continue;
                }
                help_last = help[l];
                l++;
            
        }
        result[i] = count;
        for (int g = 0; g < n; g++)
            help[g] = -1; 
    }
    
    
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    point* r = (point* )malloc(n*sizeof(point));
    query* q = (query* )malloc(m*sizeof(query));
    for (int i = 0; i < n; i++)
        scanf(" %d %d %d", &r[i].x, &r[i].y, &r[i].c);
    
    for (int j = 0; j < m; j++)
        scanf(" %d %d %d %d", &q[j].x1, &q[j].y1, &q[j].x2, &q[j].y2);
    int result[m];
    for (int k = 0; k < m; k++)
        result[k] = 0;

    search(r, q, result, n, m);
    
    for (int p = 0; p < m; p++)
        printf("%d\n", result[p]);
    
    free(r);
    free(q);
    return 0;

    

}