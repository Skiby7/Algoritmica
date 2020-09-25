#include <stdio.h>

unsigned long long int fib_rec(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    else return (fib_rec(n-1) + fib_rec(n-2));
}

unsigned long long int fib_pd(int n)
{
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    unsigned long long int a, b, c;
    a = b = 1;
    for (int i = 3; i < n + 1; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


int main()
{
    int n;
    scanf("%d", &n);
    int choice;
    scanf(" %d", &choice);
    if(choice == 0)
        printf("%d\n", fib_rec(n));
    if(choice == 1)
        printf("%d\n", fib_pd(n));
    
    return 0;


}