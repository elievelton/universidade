#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <time.h>

int main()
{

    Termos_principais *termos_principais;
    Sub_termos *subtermos, *subtermos2;
    Conj_n_pag *pag, *pag2, *pag3,*pag1;
    // FILE *file;
    // file = fopen("conj_pag","r");

    termos_principais = inicializar();
    subtermos = inicializar2();
    subtermos2 = inicializar2();
    pag = inicializar3();
    pag2 = inicializar3();
    pag3 = inicializar3();
    pag1 = inicializar3();


    pag = inserir_paginas(pag, 12);
    pag = inserir_paginas(pag, 19);
    pag = inserir_paginas(pag, 21);

    pag1 = inserir_paginas(pag1, 13);
    pag1 = inserir_paginas(pag1, 15);
    pag1 = inserir_paginas(pag1, 7);

    pag2 = inserir_paginas(pag2, 87);
    pag2 = inserir_paginas(pag2, 192);
    pag2 = inserir_paginas(pag2, 211);

    pag3 = inserir_paginas(pag3, 135);
    pag3 = inserir_paginas(pag3, 159);
    pag3 = inserir_paginas(pag3, 77);

    subtermos = inserir_no_sub(subtermos, "motor", pag1);
    subtermos2 = inserir_no_sub(subtermos2, "telhado", pag);
    
    termos_principais = inserir_no(termos_principais, "carro", subtermos, pag2);
    termos_principais = inserir_no(termos_principais, "casa", subtermos2, pag3);

    mostrar_principal(termos_principais);
    mostrar_principal2(pag);
    printf("\n");
    liberarMemoria(termos_principais);

    return 0;
}