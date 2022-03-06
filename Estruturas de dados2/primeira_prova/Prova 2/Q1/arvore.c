#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct termos_principais
{
    char titulo [80];
    int n_paginas;
    Termos_principais *esquerdo, *direito;
    Sub_termos *subtermos;
    Conj_n_pag *raiz;
};
struct sub_termos
{
    char titulo [80];
    int n_paginas;
    Sub_termos *esquerdo, *direito;
    Conj_n_pag *raiz;
};
struct conj_n_pag
{
    int num_paginas;
    Conj_n_pag *esquerdo, *direito;
};
