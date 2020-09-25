#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 101
#define max(a, b) ((a > b) ? a : b)

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", max(a,b));
    return 0;
}