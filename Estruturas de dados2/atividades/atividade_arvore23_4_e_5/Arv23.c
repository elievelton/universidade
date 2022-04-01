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
    
        if ((Raiz->nChaves == 1) && Valor < Raiz->chaveEsq)
        {
            find = busca(Raiz->esq, Valor);
        }
        else if ((Raiz->nChaves == 1) && Valor > Raiz->chaveEsq)
        {
            find = busca(Raiz->centro, Valor);
        }

        else if ((Raiz->nChaves == 2) && Valor < Raiz->chaveDir )
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
   
    else if(folha(Raiz))
    {
        return 1;
    }
    else
    {

        return 1 + (qtdnofolha(Raiz->dir) + qtdnofolha(Raiz->centro) + qtdnofolha(Raiz->esq));
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

//Fução para remover um elemento de uma arvore 2 3 

//Função para verificar se o elemento está na info 1 ou info 2
int estaContido(Arv23 *Raiz, int info)
{
    if (info == Raiz->chaveEsq)
        return 1;
    if (info == Raiz->chaveDir)
        return 2;
    return 0;
}

int excluirElemento(Arv23 **pai, Arv23 **Raiz, int info)
{
    if (*Raiz != NULL)
    {
        if (estaContido(*Raiz, info) != 0)
        {

            if (*pai == NULL && folha(*Raiz)) // Verifica se a Raiz da Árvore é um nó Folha.
            {
                if (estaContido(*Raiz, info) == 1)
                    (**Raiz).chaveEsq = (**Raiz).chaveDir;
                (**Raiz).chaveDir = 0;

                if ((**Raiz).nChaves == 2)
                    (**Raiz).nChaves = 1;
                else
                    *Raiz = NULL;
            }

            else if (*pai == NULL)
            {
                if ((**Raiz).nChaves == 2)
                {
                    if (estaContido(*Raiz, info) == 2 && (**Raiz).dir->nChaves == 2)
                    {
                        (**Raiz).chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).dir->chaveEsq = (**Raiz).dir->chaveDir;
                        (**Raiz).dir->chaveDir = 0;
                        (**Raiz).dir->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 2 && (**Raiz).centro->nChaves == 2)
                    {
                        (**Raiz).chaveDir = (**Raiz).centro->chaveDir;
                        (**Raiz).centro->chaveDir = 0;
                        (**Raiz).dir->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 2 && (**Raiz).esq->nChaves == 2)
                    {
                        (**Raiz).chaveDir = 0;
                        (**Raiz).nChaves = 1;
                        (**Raiz).centro->chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).centro->nChaves = 2;
                        (**Raiz).dir = NULL;
                    }

                    else if (estaContido(*Raiz, info) == 2 && (**Raiz).esq->nChaves == 1)
                    {
                        (**Raiz).chaveDir = 0;
                        (**Raiz).nChaves = 1;
                        (**Raiz).centro->chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).centro->nChaves = 2;
                        (**Raiz).dir = NULL;
                    }

                    else if (estaContido(*Raiz, info) == 1 && (**Raiz).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**Raiz).centro->chaveEsq;
                        (**Raiz).centro->chaveEsq = (**Raiz).centro->chaveDir;
                        (**Raiz).centro->chaveDir = 0;
                        (**Raiz).centro->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 1 && (**Raiz).esq->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**Raiz).esq->chaveDir;
                        (**Raiz).esq->chaveDir = 0;
                        (**Raiz).esq->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 1 && (**Raiz).centro->nChaves == 1)
                    {
                        (**Raiz).chaveEsq = (**Raiz).chaveDir;
                        (**Raiz).chaveDir = 0;
                        (**Raiz).nChaves = 1;
                        (**Raiz).esq->chaveDir = (**Raiz).centro->chaveEsq;
                        (**Raiz).esq->nChaves = 2;
                        (**Raiz).centro = NULL;
                    }

                    else if ((**Raiz).nChaves == 1)
                    {
                        if ((**Raiz).centro->nChaves == 2)
                        {
                            (**Raiz).chaveEsq = (**Raiz).centro->chaveEsq;
                            (**Raiz).centro->chaveEsq = (**Raiz).centro->chaveDir;
                            (**Raiz).centro->chaveDir = 0;
                            (**Raiz).centro->nChaves = 1;
                        }

                        else if ((**Raiz).esq->nChaves == 2)
                        {
                            (**Raiz).chaveEsq = (**Raiz).esq->chaveDir;
                            (**Raiz).esq->chaveDir = 0;
                            (**Raiz).esq->nChaves = 1;
                        }

                        else
                        {
                            (**Raiz).esq->chaveDir = (**Raiz).centro->chaveEsq;
                            (**Raiz).esq->nChaves = 2;
                            (**Raiz).dir = NULL;
                            *Raiz = (**Raiz).esq;
                        }
                    }
                }
            }

            else if (*pai != NULL && folha(*Raiz))
            {

                if ((**Raiz).nChaves == 2)
                {
                    if (estaContido(*Raiz, info) == 1)
                        (**Raiz).chaveEsq = (**Raiz).chaveDir;
                    (**Raiz).chaveDir = 0;
                    (**Raiz).nChaves = 1;
                }

                else if ((**pai).nChaves == 2)
                {
                    if (info > (**pai).chaveDir && (**pai).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveDir;
                        (**pai).chaveDir = (**pai).centro->chaveDir;
                        (**pai).centro->chaveDir = 0;
                        (**pai).centro->nChaves = 1;
                    }

                    else if (info > (**pai).chaveDir && (**pai).centro->nChaves == 1)
                    {
                        (**pai).centro->chaveDir = (**pai).chaveDir;
                        (**pai).centro->nChaves = 2;
                        (**pai).chaveDir = 0;
                        (**pai).nChaves = 1;
                        *Raiz = NULL;
                    }

                    else if (info > (**pai).chaveEsq && (**pai).dir->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveDir;
                        (**pai).chaveDir = (**pai).dir->chaveEsq;
                        (**pai).dir->chaveEsq = (**pai).dir->chaveDir;
                        (**pai).dir->chaveDir = 0;
                        (**pai).dir->nChaves = 1;
                    }

                    else if (info > (**pai).chaveEsq && (**pai).dir->nChaves == 1)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveDir;
                        (**Raiz).chaveDir = (**pai).dir->chaveEsq;
                        (**Raiz).nChaves = 2;
                        (**pai).chaveDir = 0;
                        (**pai).nChaves = 1;
                        (**pai).dir = NULL;
                    }

                    else if (info < (**pai).chaveEsq && (**pai).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).centro->chaveDir;
                        (**pai).centro->chaveDir = 0;
                        (**pai).centro->nChaves = 1;
                    }

                    else if (info < (**pai).chaveEsq && (**pai).dir->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).chaveDir;

                        (**pai).chaveDir = (**pai).dir->chaveEsq;
                        (**pai).dir->chaveEsq = (**pai).dir->chaveDir;
                        (**pai).dir->chaveDir = 0;
                        (**pai).dir->nChaves = 1;
                    }

                    else
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).chaveDir;
                        (**pai).chaveDir = 0;
                        (**pai).nChaves = 1;
                        (**pai).centro->chaveDir = (**pai).dir->chaveEsq;
                        (**pai).centro->nChaves = 2;
                        (**pai).dir = NULL;
                    }
                }

                else
                {
                    if (info > (**pai).chaveEsq && (**pai).esq->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).esq->chaveDir;
                        (**pai).esq->chaveDir = 0;
                        (**pai).esq->nChaves = 1;
                    }

                    else if (info < (**pai).chaveEsq && (**pai).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).centro->chaveDir;
                        (**pai).centro->chaveDir = 0;
                        (**pai).centro->nChaves = 1;
                    }

                    else if (info < (**pai).chaveEsq)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**Raiz).chaveDir = (**pai).centro->chaveEsq;
                        (**Raiz).nChaves = 2;
                        *pai = *Raiz;
                    }

                    else
                    {
                        (**pai).esq->chaveDir = (**pai).chaveEsq;
                        (**pai).esq->nChaves = 2;
                        *pai = (**pai).esq;
                    }
                }
            }

            else if (*pai != NULL && folha(*Raiz) == 0)
            {
                if (estaContido(*Raiz, info) == 2)
                {
                    if ((**Raiz).dir->nChaves == 2)
                    {
                        (**Raiz).chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).dir->chaveEsq = (**Raiz).dir->chaveDir;
                        (**Raiz).dir->chaveDir = 0;
                        (**Raiz).dir->nChaves = 1;
                    }

                    else if ((**Raiz).centro->nChaves == 2)
                    {
                        (**Raiz).chaveDir = (**Raiz).centro->chaveDir;
                        (**Raiz).centro->chaveDir = 0;
                        (**Raiz).centro->nChaves = 1;
                    }

                    else
                    {
                        (**Raiz).centro->chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).centro->nChaves = 2;
                        (**Raiz).chaveDir = 0;
                        (**Raiz).nChaves = 2;
                        (**Raiz).dir = NULL;
                    }
                }

                else if (estaContido(*Raiz, info) == 1)
                {
                    if ((**Raiz).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**Raiz).centro->chaveEsq;
                        (**Raiz).centro->chaveEsq = (**Raiz).centro->chaveDir;
                        (**Raiz).centro->chaveDir = 0;
                        (**Raiz).centro->nChaves = 1;
                    }

                    else if ((**Raiz).esq->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**Raiz).esq->chaveDir;
                        (**Raiz).esq->chaveDir = 0;
                        (**Raiz).esq->nChaves = 1;
                    }

                    else
                    {
                        (**Raiz).chaveEsq = (**Raiz).centro->chaveEsq;
                        (**Raiz).centro->chaveEsq = (**Raiz).chaveDir;
                        (**Raiz).chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).dir->chaveEsq = (**Raiz).dir->chaveDir;
                        (**Raiz).dir->chaveDir = 0;
                        (**Raiz).dir->nChaves = 1;
                    }
                }
            }
        }

        else if (info < (**Raiz).chaveEsq)
            excluirElemento(Raiz, &(**Raiz).esq, info);

        else if ((**Raiz).nChaves == 1)
            excluirElemento(Raiz, &(**Raiz).centro, info);

        else if (info < (**Raiz).chaveDir)
            excluirElemento(Raiz, &(**Raiz).centro, info);

        else
            excluirElemento(Raiz, &(**Raiz).dir, info);
    }
}