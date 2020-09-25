#include <stdio.h>
#include <string.h>
#define MAXLEN 1001

void product(char* src, int k)
{
    for (int i = 0; i < k; i++)
        printf("%s", src);
}

int main()
{
    char src[MAXLEN];
    scanf("%s", &src);
    int k;
    scanf(" %d", &k);
    product(src, k);
    return 0;
}