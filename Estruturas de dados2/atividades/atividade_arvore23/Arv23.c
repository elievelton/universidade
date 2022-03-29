#include <stdio.h>
#include <stdlib.h>
#include "Arv23_decla.h"

struct Arv23
{
    int chaveEsq, chaveDir, nChaves;
    Arv23 *esq, *centro, *dir;
};

// Está função é usada para verificar se um numero existe na Raiz da Arv23 ela pode ser usada para busca com pequenas alterações
int busca(Arv23 *Raiz, int Valor)
{
    int find = -1;
    if (Raiz)
    {

        if (Raiz->chaveEsq == Valor)
        {
            find = 1;
        }
        else if (Raiz->chaveDir == Valor)
        {
            find = 1;
        }
        else if (Raiz->chaveEsq != Valor)
        {
            find = 0;
        }
        else if (Raiz->chaveDir != Valor){
            find = 0;
        }
        if(Raiz == NULL){
            find = 0;
        }

        if (Valor < Raiz->chaveEsq)
        {
            find = busca(Raiz->esq, Valor);
        }
        else if ((Raiz->nChaves == 2) && Valor < Raiz->chaveDir)
        {
            find = busca(Raiz->centro, Valor);
        }
        else if ((Raiz->nChaves == 2) && Valor > Raiz->chaveDir)
        {
            find = busca(Raiz->dir, Valor);
        }
    }

    return find;
}

// Função para mostrar os elemento de uma arvore o parametro Raiz->nChaves mostra quantas infos tem no No
void mostrar(Arv23 *Raiz)
{
    if (Raiz != NULL)
    {
        printf("[%d] [%d] --- Quantidade de infos é [%d]\n", Raiz->chaveEsq, Raiz->chaveDir, Raiz->nChaves);
        mostrar(Raiz->esq);
        mostrar(Raiz->centro);
        mostrar(Raiz->dir);
    }
}

// Essa função é usada para criar um novo nó na Arv23

Arv23 *criaNO(int info1, Arv23 *noEsq, Arv23 *noCentro)
{
    Arv23 *no = (Arv23 *)malloc(sizeof(Arv23));

    (*no).chaveEsq = info1;
    (*no).chaveDir = 0;
    (*no).nChaves = 1;
    (*no).esq = noEsq;
    (*no).centro = noCentro;
    (*no).dir = NULL;

    return no;
}
// Função usada pela insere23 para adicionar um novo nó
Arv23 *adicionaNo(Arv23 *Raiz, int info, Arv23 *Novo)
{
    if (info > (*Raiz).chaveEsq)
    {
        (*Raiz).chaveDir = info;
        (*Raiz).dir = Novo;
    }
    else
    {
        (*Raiz).chaveDir = (*Raiz).chaveEsq;
        (*Raiz).chaveEsq = info;
        (*Raiz).dir = (*Raiz).centro;
        (*Raiz).centro = Novo;
    }

    (*Raiz).nChaves = 2;

    return Raiz;
}
// Função usada para verificar se é folha ou não o no atual
int folha(Arv23 *Raiz)
{
    int folha = 0;

    if ((*Raiz).esq == NULL && (*Raiz).centro == NULL && (*Raiz).dir == NULL)
        folha = 1;

    return folha;
}
// Função usada para verificar a quantidade de nos folhas em uma arvore 2 3
int qtdnofolha(Arv23 *Raiz)
{

    if (Raiz == NULL)
    {
        return 0;
    }
    if (folha(Raiz))
    {
        return 1;
    }
    else
    {

        return qtdnofolha(Raiz->dir) + qtdnofolha(Raiz->centro) + qtdnofolha(Raiz->esq) + 1;
    }
}
// Função usanda quando vai inserir um elemento e não tem espaço entao quebra-se o nó
Arv23 *quebraNo(Arv23 **Raiz, Arv23 *NovoNo, int info, int *infoMeio)
{
    Arv23 *Novo;

    if (info > (**Raiz).chaveDir)
    {
        *infoMeio = (**Raiz).chaveDir;
        Novo = criaNO(info, (**Raiz).dir, NovoNo);
    }

    else if (info < (**Raiz).chaveEsq)
    {
        *infoMeio = (**Raiz).chaveEsq;
        Novo = criaNO((**Raiz).chaveDir, (**Raiz).centro, (**Raiz).dir);

        (**Raiz).chaveEsq = info;
        (**Raiz).centro = NovoNo;
    }

    else
    {
        *infoMeio = info;
        Novo = criaNO((**Raiz).chaveDir, NovoNo, (**Raiz).dir);
    }

    (**Raiz).chaveDir = 0;
    (**Raiz).nChaves = 1;
    (**Raiz).dir = NULL;

    return Novo;
}
// Função de inserir  na Arv23
Arv23 *insere23(Arv23 *pai, Arv23 **Raiz, int info, int *infoMeio)
{
    Arv23 *novo;

    if (*Raiz == NULL)
        *Raiz = criaNO(info, NULL, NULL);
    else
    {
        if (folha(*Raiz))
        {
            if ((**Raiz).nChaves == 1)
            {
                *Raiz = adicionaNo(*Raiz, info, NULL);
                novo = NULL;
            }
            else
            {
                novo = quebraNo(Raiz, NULL, info, infoMeio);

                if (pai == NULL)
                {
                    *Raiz = criaNO(*infoMeio, *Raiz, novo);
                    novo = NULL;
                }
            }
        }
        else
        {
            if (info < (**Raiz).chaveEsq)
                novo = insere23(*Raiz, &(**Raiz).esq, info, infoMeio);

            else if ((**Raiz).nChaves == 1)
                novo = insere23(*Raiz, &(**Raiz).centro, info, infoMeio);

            else if (info < (**Raiz).chaveDir)
                novo = insere23(*Raiz, &(**Raiz).centro, info, infoMeio);

            else
                novo = insere23(*Raiz, &(**Raiz).dir, info, infoMeio);

            if (novo != NULL)
            {
                if ((**Raiz).nChaves == 1)
                {
                    (*Raiz) = adicionaNo(*Raiz, *infoMeio, novo);
                    novo = NULL;
                }
                else
                {
                    novo = quebraNo(Raiz, novo, *infoMeio, infoMeio);

                    if (pai == NULL)
                    {
                        *Raiz = criaNO(*infoMeio, *Raiz, novo);
                        novo = NULL;
                    }
                }
            }
        }
    }

    return novo;
}

// Verificar a profundidade de um nó, não tenho certeza, mas acho que se verificar só um lado ja funciona, pois a arvore é balanceada
int altura(Arv23 *raiz)
{
    int alt = 0, esq, dir;

    if (raiz == NULL)
    {
        alt = -1;
    }
    else
    {
        esq = altura((*raiz).esq);
        dir = altura((*raiz).dir);

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