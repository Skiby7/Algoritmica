/* hanoi.c : file sorgente di un programma che scrive una soluzione
             del problema delle "torri di Hanoi".
	     Per quanto riguarda l'introduzione al suddetto problema e
	     la spiegazione della soluzione seguente, si rimanda al
	     testo dell'esercizio 5.39 del libro "C corso completo di
	     programmazione" di Deitel & Deitel. */

#include<stdio.h>

/* Definizione dei prototipi delle funzioni */
void muovi_dischi(int n, int a, int b, int c);

/* ### */
int main()
{
  int n, a, b, c;
  do {
    printf("Numero n dei dischi che vuoi considerare? (n>0)\n");
    scanf("%d", &n);
  } while(n <= 0);
  muovi_dischi(n, 1, 3, 2);
}
/* ### */
void muovi_dischi(n, a, b, c)
     int n, a, b, c;
{
  /* Questa funzione (ricorsiva) descrive le mosse da fare per poter
     trasferire n dischi dal piolo a al piolo c, usando eventualmente
     b come piolo per gli spostamenti intermedi.
     Ovviamente, questi spostamenti vengono fatti tenendo conto del
     vincolo espresso nel problema delle "torri di Hanoi": ciascun
     disco non puo' mai essere poggiato su un disco piu' piccolo. */
  if(n == 1) {
    // printf("Muovi un disco dal piolo %d al piolo %d\n", a, c);
  }
  else {
    muovi_dischi(n-1, a, c, b);
    // printf("Muovi un disco dal piolo %d al piolo %d\n", a, c);
    muovi_dischi(n-1, b, a, c);
  }
}
