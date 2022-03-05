#include <stdio.h>
#include <stdlib.h>

/*
        Aula 160: Desenvolva uma função recursivo que calcule a soma dos números inteiros de 1 a N.

        Escrita por Wagner Gaspar
        Março de 2021
*/

int soma(int n){
    int s = 0;
    if(n > 0){
      s = n + soma(n - 1);
      return (s);
      }
        
    
}

int main () {

    int n;

    printf("Digite N: ");
    scanf("%d", &n);
    soma(n);

    printf("Soma de 1 ate %d: %d\n", n, soma(n));

    return 0;
}