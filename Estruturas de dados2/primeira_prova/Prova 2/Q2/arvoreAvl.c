#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreAvl.h"

struct conj_n_pag
{
    int num_paginas;
    Conj_n_pag *esquerdo, *direito;
};

struct sub_termos
{
    char titulo[80];
    Conj_n_pag *con_pg;
    Sub_termos *esquerdo, *direito;
};

struct termos_principais
{
    char titulo[80];
    Sub_termos *subtermos;
    Conj_n_pag *con_pg;
    Termos_principais *esquerdo, *direito;
};

Termos_principais *inicializar()
{
    return NULL;
}

Sub_termos *inicializar2()
{
    return NULL;
}

Conj_n_pag *inicializar3()
{
    return NULL;
}

Sub_termos *inserir_no_sub(Sub_termos *raiz, char titulo[], Conj_n_pag *conj)
{

    if (raiz == NULL)
    {
        raiz = (Sub_termos *)calloc(sizeof(Sub_termos), 1);
        strcpy(raiz->titulo, titulo);
        raiz->con_pg = conj;
    }
    else
    {
        int comp;
        comp = strcmp(titulo, raiz->titulo);
        if (comp < 0)
        {
            raiz->esquerdo = inserir_no_sub(raiz->esquerdo, titulo, conj);
        }
        else
        {
            raiz->direito = inserir_no_sub(raiz->direito, titulo, conj);
        }
    }
    return raiz;
}

// função para inserir os termos principas
Termos_principais *inserir_termo(Termos_principais *raiz, char titulo[], Sub_termos *sub, Conj_n_pag *conj)
{
    if (raiz == NULL)
    {
        raiz = (Termos_principais *)calloc(sizeof(Termos_principais), 1);
        strcpy(raiz->titulo, titulo);
        raiz->subtermos = sub;
        raiz->con_pg = conj;
    }
    else
    {
        int comp;
        comp = strcmp(titulo, raiz->titulo);

        if (comp == 0)
        {
            raiz->subtermos = inserir_no_sub(raiz->subtermos, sub->titulo, conj);
        }
        else if (comp < 0)
        {
            raiz->esquerdo = inserir_termo(raiz->esquerdo, titulo, sub, conj);
        }
        else
        {
            raiz->direito = inserir_termo(raiz->direito, titulo, sub, conj);
        }
    }
    return raiz;
}

Termos_principais *inserir_sub_termo(Termos_principais *raiz, char termo[], char sub_termo[], Conj_n_pag *sub_termo_pag)
{
    if (raiz == NULL)
    {
        raiz = (Termos_principais *)calloc(sizeof(Termos_principais), 1);
        strcpy(raiz->titulo, termo);
        raiz->subtermos = (Sub_termos *)calloc(sizeof(Sub_termos), 1);
        strcpy(raiz->titulo, termo);
        strcpy(raiz->subtermos->titulo, sub_termo);
        raiz->subtermos->con_pg = sub_termo_pag;
    }
    else
    {
        int comp;
        comp = strcmp(termo, raiz->titulo);

        if (comp == 0)
        {
            raiz->subtermos = inserir_no_sub(raiz->subtermos, sub_termo, sub_termo_pag);
        }
        else if (comp < 0)
        {
            raiz->esquerdo = inserir_sub_termo(raiz->esquerdo, termo, sub_termo, sub_termo_pag);
        }
        else
        {
            raiz->direito = inserir_sub_termo(raiz->direito, termo, sub_termo, sub_termo_pag);
        }
    }
    return raiz;
}

// função para inserir os subtermos  do termo principal

// função para inserir os numeros das paginas que os termos principais ou secundarios aparecem
Conj_n_pag *inserir_paginas(Conj_n_pag *raiz, int numero)
{
    if (raiz == NULL)
    {
        raiz = (Conj_n_pag *)calloc(sizeof(Conj_n_pag), 1);
        raiz->num_paginas = numero;
    }
    else
    {
        if (numero < raiz->num_paginas)
        {
            raiz->esquerdo = inserir_paginas(raiz->esquerdo, numero);
        }
        else
        {
            raiz->direito = inserir_paginas(raiz->direito, numero);
        }
    }
    return raiz;
}

// Função para buscar termos principal
Termos_principais *buscar_termo_principal(Termos_principais *raiz, char titulo[])
{
    Termos_principais *res = raiz;
    if (raiz)
    {
        int comp;
        comp = strcmp(titulo, raiz->titulo);

        if (comp < 0)
        {
            res = buscar_termo_principal(raiz->esquerdo, titulo);
        }
        else if (comp > 0)
        {
            res = buscar_termo_principal(raiz->direito, titulo);
        }
    }
    return res;
}

Sub_termos *buscar_sub_termo(Sub_termos *raiz, char titulo[])
{
    Sub_termos *res = raiz;
    if (raiz != NULL)
    {
        int comp;
        comp = strcmp(titulo, raiz->titulo);

        if (comp < 0)
        {
            res = buscar_sub_termo(raiz->esquerdo, titulo);
        }
        else if (comp > 0)
        {
            res = buscar_sub_termo(raiz->direito, titulo);
        }
    }
    return res;
}

Sub_termos *buscar_termo_secundario(Termos_principais *raiz, char sub_termo[])
{
    Sub_termos *res = NULL;
    if (raiz != NULL)
    {
        res = buscar_sub_termo(raiz->subtermos, sub_termo);
    }
    return res;
}

// Função para buscar termos secundarios

Termos_principais *inserir_paginas_para_termo(Termos_principais *raiz, int pag)
{
    if (raiz != NULL)
    {
        raiz->con_pg = inserir_paginas(raiz->con_pg, pag);
    }
}

Sub_termos *inserir_paginas_para_sub_termo(Sub_termos *raiz, int pag)
{
    if (raiz != NULL)
    {
        raiz->con_pg = inserir_paginas(raiz->con_pg, pag);
    }
}

void mostrar_paginas(Conj_n_pag *raiz)
{
    if (raiz != NULL)
    {
        mostrar_paginas(raiz->esquerdo);
        printf("%d, ", raiz->num_paginas);
        mostrar_paginas(raiz->direito);
    }
}

void mostrar_sub_termos(Sub_termos *sub)
{
    if (sub != NULL)
    {
        mostrar_sub_termos(sub->esquerdo);
        printf("----%s ", sub->titulo);
        printf("(");
        mostrar_paginas(sub->con_pg);
        printf(")\n");
        mostrar_sub_termos(sub->direito);
    }
}

// Função para mostrar principal
void mostrar_termos(Termos_principais *termos)
{
    if (termos != NULL)
    {
        mostrar_termos(termos->esquerdo);
        printf("%s  ", termos->titulo);
        printf("(");
        mostrar_paginas(termos->con_pg);
        printf(")");
        printf("\n");
        mostrar_sub_termos(termos->subtermos);
        mostrar_termos(termos->direito);
    }
    printf("\n");
}

// Função para mostrar os numeros das paginas usada na função mostrar principal

void liberar_pag(Conj_n_pag *raiz)
{
    if (raiz != NULL)
    {
        liberar_pag(raiz->esquerdo);
        liberar_pag(raiz->direito);
        free(raiz);
    }
}

void liberar_sub_termos(Sub_termos *raiz)
{
    if (raiz != NULL)
    {
        liberar_pag(raiz->con_pg);
        liberar_sub_termos(raiz->esquerdo);
        liberar_sub_termos(raiz->direito);
        free(raiz);
    }
}

void liberar_memoria(Termos_principais *raiz)
{
    if (raiz != NULL)
    {
        liberar_sub_termos(raiz->subtermos);
        liberar_pag(raiz->con_pg);
        liberar_memoria(raiz->esquerdo);
        liberar_memoria(raiz->direito);
        free(raiz);
    }
}
