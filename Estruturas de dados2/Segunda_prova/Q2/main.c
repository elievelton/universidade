#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arv_RB.h"

int main(){
    No* Raiz=NULL;

    InsereCalcados(&Raiz, 1, "sapato", "Olipikus", 10, 32, 1, 34.8);
    InsereCalcados(&Raiz, 2, "sapato_tenis", "adidas", 12, 41, 2, 74.8);
    InsereCalcados(&Raiz, 3, "Sandalia", "Havaianas", 18, 42, 3, 24.8);
    InsereCalcados(&Raiz, 4, "Sandalia", "Havaianas", 18, 42, 3, 24.8);
    InsereCalcados(&Raiz, 5, "Sandalia", "Havaianas", 18, 42, 3, 24.8);
    InsereCalcados(&Raiz, 6, "Sandalia", "Havaianas", 18, 42, 3, 24.8);


    imprimir(Raiz);
    printf("\n");
    puts("\n================================");
    remover(&Raiz,2);
    imprimir(Raiz);

    return 0;
}