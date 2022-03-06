#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreAvl.h"

struct no
{
    int numero;
    No *esquerdo, *direito;
};


No *inicializar()
{
    return NULL;
}


No *inserir_no(No *raiz, int cod)
{

    if (raiz == NULL)
    {
        No *aux;
        aux = (No *)malloc(sizeof(No));
        aux->numero = cod;
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
    }
    else
    {
        if (cod < raiz->numero)
        {
            raiz->esquerdo = inserir_no(raiz->esquerdo, cod);
        }
        else
        {
            raiz->direito = inserir_no(raiz->direito, cod);
        }
    }
    return raiz;
}
int profu(No *raiz){
    int prof = 0, esq, dir;

    if (raiz == NULL){
        prof = -1;
    } else {
        esq = profu((*raiz).esquerdo);
        dir = profu((*raiz).direito);

        if (esq < dir){
            prof = dir + 1;
        }else{
            prof = esq + 1;
        }
    }
    return prof;
}
int prof_menor(No *raiz){
    int prof = 0, esq, dir;

    if (raiz == NULL){
        prof = -1;
    } else {
        esq = prof_menor((*raiz).esquerdo);
        dir = prof_menor((*raiz).direito);

        if (esq < dir && raiz->esquerdo!=NULL){
            prof = esq + 1;
        }else if(raiz->direito!=NULL){
            prof = dir + 1;
        }else if(raiz->esquerdo==NULL){
            prof = dir +1;
        }else if(raiz->direito==NULL){
            prof = esq +1;
        }
    }
    return prof;
}

void mostrar_principal(No *raiz)
{
    if (raiz != NULL)
    {
         
        printf("%d (", raiz->numero);
        mostrar_principal(raiz->esquerdo);
        mostrar_principal(raiz->direito);
        printf(")");
    }
}




void liberarMemoria(No *raiz)
{
    if (raiz != NULL)
    {
        liberarMemoria((*raiz).esquerdo);
        liberarMemoria((*raiz).direito);
        free(raiz);
    }
}


No* buscar_versao_1(No *raiz, int num){
    if(raiz){
        if(num == raiz->numero)
            return raiz;
        else if(num < raiz->numero)
            return buscar_versao_1(raiz->esquerdo, num);
        else
            return buscar_versao_1(raiz->direito, num);
    }
    return NULL;
}