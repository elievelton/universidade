#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

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
// função para inserir os termos principas
Termos_principais *inserir_no(Termos_principais *raiz, char titulo[], Sub_termos *sub, Conj_n_pag *conj)
{
    /*Termos_principais *aux;

    aux = buscar_termo_principal(raiz,raiz->titulo);
    if(aux->titulo ==raiz->titulo){
       raiz = inserir_no_sub(aux,sub->titulo,conj);
    }*/


    if (raiz == NULL)
    {

        Termos_principais *aux;
        aux = (Termos_principais *)malloc(sizeof(Termos_principais));
        strcpy(aux->titulo, titulo);
        aux->subtermos = sub;
        aux->con_pg = conj;
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
    }
    else
    {
        int comp;
        comp = strcmp(titulo, raiz->titulo);
        if (comp < 0)
        {
            raiz->esquerdo = inserir_no(raiz->esquerdo, titulo, sub, conj);
        }
        else
        {
            raiz->direito = inserir_no(raiz->direito, titulo, sub, conj);
        }
    }
    return raiz;
}
// função para inserir os subtermos  do termo principal
Sub_termos *inserir_no_sub(Sub_termos *raiz, char titulo[], Conj_n_pag *conj)
{

    if (raiz == NULL)
    {

        Sub_termos *aux;
        aux = (Sub_termos *)malloc(sizeof(Sub_termos));
        strcpy(aux->titulo, titulo);
        aux->con_pg = conj;
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
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
// função para inserir os numeros das paginas que os termos principais ou secundarios aparecem
Conj_n_pag *inserir_paginas(Conj_n_pag *raiz, int numero)
{

    if (raiz == NULL)
    {

        Conj_n_pag *aux;
        aux = (Conj_n_pag *)malloc(sizeof(Conj_n_pag));
        aux->num_paginas = numero;
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
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
Conj_n_pag *inserir_paginas_sub(Conj_n_pag *raiz, int numero)
{

    if (raiz == NULL)
    {

        Conj_n_pag *aux;
        aux = (Conj_n_pag *)malloc(sizeof(Conj_n_pag));
        aux->num_paginas = numero;
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
    }
    else
    {

        if (numero < raiz->num_paginas)
        {
            raiz->esquerdo = inserir_paginas_sub(raiz->esquerdo, numero);
        }
        else
        {
            raiz->direito = inserir_paginas_sub(raiz->direito, numero);
        }
    }
    return raiz;
}
// Função para buscar termos principal
Termos_principais *buscar_termo_principal(Termos_principais *raiz, char titulo[])
{
    if (raiz)
    {
        int comp;
        comp = strcmp(titulo, raiz->titulo);
        if (comp == 0)

            return raiz;

        else if (comp < 0)
            return buscar_termo_principal(raiz->esquerdo, titulo);
        else
            return buscar_termo_principal(raiz->direito, titulo);
    }
    return NULL;
}
// Função para buscar termos secundarios
Sub_termos *buscar_termo_secundario(Sub_termos *raiz, char titulo[])
{
    if (raiz)
    {
        int comp;
        comp = strcmp(titulo, raiz->titulo);
        if (comp == 0)

            return raiz;

        else if (comp < 0)
            return buscar_termo_secundario(raiz->esquerdo, titulo);
        else
            return buscar_termo_secundario(raiz->direito, titulo);
    }
    return NULL;
}
//Função para mostrar principal
void mostrar_principal(Termos_principais *prin)
{
    if (prin!=NULL)
    {
        
        mostrar_principal(prin->esquerdo);
        printf("%s  ", prin->titulo);     
        printf("(");
        mostrar_principal2(prin->con_pg);
        printf(")"); 
        printf("\n");
        printf("----%s ", prin->subtermos->titulo);
        printf("(");
        mostrar_principal2(prin->subtermos->con_pg);
        printf(")\n");
        
        mostrar_principal(prin->direito);
    }
    printf("\n");
}
void liberarMemoria(Termos_principais *raiz)
{
    if (raiz != NULL)
    {
        liberarMemoria((*raiz).esquerdo);
        liberarMemoria((*raiz).direito);
        free(raiz);
    }
}
//Função para mostrar os numeros das paginas usada na função mostrar principal
void mostrar_principal2(Conj_n_pag *raiz)
{
    if (raiz != NULL)
    {
        mostrar_principal2(raiz->esquerdo);
        printf("%d, ", raiz->num_paginas);
        
        mostrar_principal2(raiz->direito);
        //printf("\n");
    }
}