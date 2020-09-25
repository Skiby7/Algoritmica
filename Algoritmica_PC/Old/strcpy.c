#include <stdio.h>
#include <string.h>
#define MAXLEN 1001
char* my_strcopy(char* dest, char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    return dest;

}
int main()
{
    char src[MAXLEN];
    scanf("%s", src);
    char dest[MAXLEN];
    my_strcopy(dest, src);
    printf("%s\n", dest);
    return 0;
}