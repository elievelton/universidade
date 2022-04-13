#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arv_RB.h"

int main(){
    No* arvore=NULL;

    inserir(&arvore,1);
    inserir(&arvore,2);
    inserir(&arvore,3);
    inserir(&arvore,4);
    inserir(&arvore,5);
    // inserir(&arvore,120);
    // inserir(&arvore,10);
    // inserir(&arvore,1200);



    imprimir(arvore);
    printf("\n");
    remover(&arvore, 2);
    imprimir(arvore);

    return 0;
}