#include <stdio.h>
#include <stdlib.h>

int maxprice(int n, int price[], int pieces[])
{
    int max = 0;
    int resto = 0;
    int pezzi = 0;
    int guadagno = 0;
    int j = n;
    for (int i = n - 1; i != 0; i--)
    {   if(n == 0)
            break;

        resto = n%j;
        pezzi = n/j;
        guadagno = pezzi*price[i] + maxprice(resto, price, pieces);
        if(guadagno > max)
        {    
            max = guadagno;
            pieces[n/j]++;
        }
        j--;
    }
    return max;
    
}

void convert(int pieces[], int n, int converted[])
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if(pieces[i] != 0)
        {
            while(pieces[i] != 0)
            {
                converted[j] = i + 1;
                j++; 
                pieces[i]--;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int price[n];
    for (int i = 0; i < n; i++)
        scanf(" %d", &price[i]);

    //Inizializzo il vettore che conta la lunghezza dei pezzi
    int pieces[n];
    for (int j = 0; j < n; j++)
        pieces[j] = 0;
    
    int result = maxprice(n, price, pieces);
    //Converto il vettore che conta i pezzi nel formato output voluto
   /* int count = 0;
    for (int i = 0; i < n; i++)
        count += pieces[i];
    int converted[count];
    convert(pieces, n, converted);*/
    //Risultato
    printf("%d\n", result);
    for (int p = 0; p < n; p++)
        printf("%d ", pieces[p]);
    
    return 0;
    

}