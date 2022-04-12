#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arv_RB.h"

int main(){
    No* arvore=NULL;

    inserir(&arvore,100);
    inserir(&arvore,200);
    inserir(&arvore,300);
    inserir(&arvore,50);
    inserir(&arvore,150);
    inserir(&arvore,120);
    inserir(&arvore,10);
    inserir(&arvore,1200);



    imprimir(arvore);
    printf("\n");
    //remover(&main, 14);
    //imprimir(main);

    return 0;
}