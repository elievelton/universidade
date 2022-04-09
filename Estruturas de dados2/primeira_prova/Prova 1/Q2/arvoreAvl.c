#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoreAvl.h"

struct no
{
    int numero, altura;
    No *esquerdo, *direito;
};

No *inicializar()
{
    return NULL;
}
//não está sendo usada
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
int profu(No *raiz)
{
    int prof = 0, esq, dir;

    if (raiz == NULL)
    {
        prof = -1;
    }
    else
    {
        esq = profu((*raiz).esquerdo);
        dir = profu((*raiz).direito);

        if (esq < dir)
        {
            prof = dir + 1;
        }
        else
        {
            prof = esq + 1;
        }
    }
    return prof;
}
int prof_menor(No *raiz)
{
    int prof = 0, esq, dir;

    if (raiz == NULL)
    {
        prof = -1;
    }
    else
    {
        esq = prof_menor((*raiz).esquerdo);
        dir = prof_menor((*raiz).direito);

        if (esq < dir && raiz->esquerdo != NULL)
        {
            prof = esq + 1;
        }
        else if (raiz->direito != NULL)
        {
            prof = dir + 1;
        }
        else if (raiz->esquerdo == NULL)
        {
            prof = dir + 1;
        }
        else if (raiz->direito == NULL)
        {
            prof = esq + 1;
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

No *buscar_versao_1(No *raiz, int num)
{
    if (raiz)
    {
        if (num == raiz->numero)
            return raiz;
        else if (num < raiz->numero)
            return buscar_versao_1(raiz->esquerdo, num);
        else
            return buscar_versao_1(raiz->direito, num);
    }
    return NULL;
}

int altura(No *raiz)
{
    int alt = 0, esq, dir;

    if (raiz == NULL)
    {
        alt = -1;
    }
    else
    {
        esq = altura((*raiz).esquerdo);
        dir = altura((*raiz).direito);

        if (esq < dir)
        {
            alt = dir + 1;
        }
        else
        {
            alt = esq + 1;
        }
    }
    return alt;
}

int maior(int x, int y)
{
    int maior = 0;

    if (x > y)
    {
        maior = x;
    }
    else
    {
        maior = y;
    }
    return maior;
}

void rotacaoDireita(No **no)
{
    No *aux;

    aux = (**no).esquerdo;
    (**no).esquerdo = (*aux).direito;
    (*aux).direito = *no;
    (**no).altura = maior(altura((**no).esquerdo), altura((**no).direito)) + 1;
    (*aux).altura = maior(altura((*aux).esquerdo), altura((*aux).direito)) + 1;
    (*no) = aux;
}
void rotacaoEsquerda(No **no)
{
    No *aux;

    aux = (**no).direito;
    (**no).direito = (*aux).esquerdo;
    (*aux).esquerdo = *no;
    (**no).altura = maior(altura((**no).esquerdo), altura((**no).direito)) + 1;
    (*aux).altura = maior(altura((*aux).esquerdo), altura((*aux).direito)) + 1;
    (*no) = aux;
}

void rotacaoDirEsq(No **no)
{

    rotacaoDireita(&((**no).direito));
    rotacaoEsquerda(no);
}

void rotacaoEsqDir(No **no)
{

    rotacaoEsquerda(&((**no).esquerdo));
    rotacaoDireita(no);
}

int fatorBalanceamento(No *raiz)
{
    int fb = 0, altEsq = 0, altDir = 0;

    altEsq = altura(raiz->esquerdo);
    altDir = altura(raiz->direito);

    fb = altEsq - altDir;

    return fb;
}

int inserirAvl(No **raiz, No *no)
{
    int inseriu = 1;

    if (*raiz == NULL)
    {
        *raiz = no;
    }
    else
    {
        if ((*no).numero < (**raiz).numero)
        {
            int fb;
            inseriu = inserirAvl(&((**raiz).esquerdo), no);
            if (inseriu)
            {
                fb = fatorBalanceamento(*raiz);
                if (fb >= 2)
                {
                    if ((*no).numero < (**raiz).esquerdo->numero)
                    {
                        rotacaoDireita(raiz);
                    }
                    else
                    {
                        rotacaoEsqDir(raiz);
                    }
                }
            }
        }
        else if ((*no).numero > (**raiz).numero)
        {
            int fb;
            inseriu = inserirAvl(&((**raiz).direito), no);
            if (inseriu)
            {
                fb = fatorBalanceamento(*raiz);
                if (fb <= -2)
                {
                    if ((*no).numero > (**raiz).direito->numero)
                    {
                        rotacaoEsquerda(raiz);
                    }
                    else
                    {
                        rotacaoDirEsq(raiz);
                    }
                }
            }
        }
        else
        {
            inseriu = 0;
        }
        (**raiz).altura = maior(altura((**raiz).esquerdo), altura((**raiz).direito)) + 1;
    }
    return inseriu;
}
No *criarNo(int valor)
{
    No *no = inicializar();

    no = (No *)malloc(sizeof(No));

    (*no).numero = valor;
    (*no).altura = 0;
    (*no).esquerdo = NULL;
    (*no).direito = NULL;

    return no;
}