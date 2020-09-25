#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStr(char **a, int n)
{
    for(int i=0; i < n; i++) printf("%s\n", a[i]);
}

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

int main()
{
    int n;
    scanf("%d", &n);
    char **str;
    str = (char **) malloc(n*sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        str[i] = (char *) malloc(101*sizeof(char));
        scanf("%s", str[i]);
    }
    insStr(str, n);
    printStr(str, n);
    for(int i=0; i < n; i++) free(str[i]); 
    free(str);
    return 0;
}