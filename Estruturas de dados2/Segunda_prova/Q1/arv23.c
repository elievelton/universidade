#include <stdio.h>
#include <stdlib.h>
#include "arv23.h"

struct Arv23
{
    Calcados *chaveEsq, *chaveDir;
    int nChaves;
    Arv23 *esq, *centro, *dir;
};

struct Calcados
{
    int cod;
    char *tipo;
    char *marca;
    int qtd;
    float preco;
    int tamanho;
    int posicao_arquivo; // Deve guardar a posição de um caçado dentro do arquivo
};

// Alocando e criando um novo Calçado
Calcados *criaCal(int cod, char *tipo, char *marca, int qtd, int tamanho, int posicao_arquivo, float preco)
{
    Calcados *info = (Calcados *)malloc(sizeof(Calcados));

    info->cod = cod;
    info->tipo = tipo;
    info->marca = marca;
    info->qtd = qtd;
    info->preco = preco;
    info->tamanho = tamanho;
    info->posicao_arquivo = posicao_arquivo;
    return info;
}

void mostrarCalcado(Calcados *calcado)
{
    printf(
        "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Tamanho: %d\n Quantidade: %d\n Preço(R$): %f\n",

        calcado->cod,
        calcado->tipo,
        calcado->marca,
        calcado->tamanho,
        calcado->qtd,
        calcado->preco);
}

// Fazendo uma busca pelo Id do calçado
int busca(Arv23 *Raiz, int Valor)
{
    int find = -1;
    if (Raiz)
    {

        if (Raiz->chaveEsq->cod == Valor)
        {
            find = 1;
            printf("--------Calçado encontrado com sucesso!----------\n");
            mostrar(Raiz);
        }

        else if (Raiz->chaveDir->cod == Valor)
        {
            find = 1;
            printf("----------Calçado encontrado com sucesso!-----------\n");
            mostrar(Raiz);
        }
        else if (Raiz->chaveEsq->cod != Valor)
        {
            find = 0;
            printf("Produto Não encontrado\n");
        }
        else if (Raiz->chaveDir->cod != Valor)
        {
            find = 0;
            printf("Produto Não encontrado\n");
        }
        if (Raiz == NULL)
        {
            find = 0;
            printf("Produto Não encontrado\n");
        }

        if ((Raiz->nChaves == 1) && Valor < Raiz->chaveEsq->cod)
        {
            find = busca(Raiz->esq, Valor);
        }
        else if ((Raiz->nChaves == 1) && Valor > Raiz->chaveEsq->cod)
        {
            find = busca(Raiz->centro, Valor);
        }

        else if ((Raiz->nChaves == 2) && Valor < Raiz->chaveDir->cod)
        {
            find = busca(Raiz->centro, Valor);
        }
        else if ((Raiz->nChaves == 2) && Valor > Raiz->chaveDir->cod)
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
        if (Raiz->nChaves == 1)
        {
            printf(
                "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Quantidade: %d\n Preço(R$): %f\n Numero de elementos : %d\n",

                Raiz->chaveEsq->cod,
                Raiz->chaveEsq->tipo,
                Raiz->chaveEsq->marca,
                Raiz->chaveEsq->qtd,
                Raiz->chaveEsq->preco,
                Raiz->nChaves);
        }

        else if (Raiz->nChaves == 2)
        {

            printf(
                "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Quantidade: %d\n Preço(R$): %f\n Numero de elementos : %d\n",

                Raiz->chaveEsq->cod,
                Raiz->chaveEsq->tipo,
                Raiz->chaveEsq->marca,
                Raiz->chaveEsq->qtd,
                Raiz->chaveEsq->preco,
                Raiz->nChaves);

            printf(

                "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Quantidade: %d\n Preço(R$): %f\n Numero de elementos : %d\n",

                Raiz->chaveDir->cod,
                Raiz->chaveDir->tipo,
                Raiz->chaveDir->marca,
                Raiz->chaveDir->qtd,
                Raiz->chaveDir->preco,
                Raiz->nChaves);
        }

        mostrar(Raiz->esq);
        mostrar(Raiz->centro);
        mostrar(Raiz->dir);
    }
}

void mostrarTudo(Arv23 *Raiz)
{
    if (Raiz != NULL)
    {
        if (Raiz->nChaves == 1)
        {
            printf(

                "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Quantidade: %d\n Preço(R$): %f\n Numero de elementos : %d\n",

                Raiz->chaveEsq->cod,
                Raiz->chaveEsq->tipo,
                Raiz->chaveEsq->marca,
                Raiz->chaveEsq->qtd,
                Raiz->chaveEsq->preco,
                Raiz->nChaves);
        }
        else if (Raiz->nChaves == 2)
        {
            printf("printando direita\n");
            printf(

                "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Quantidade: %d\n Preço(R$): %f\n Numero de elementos : %d\n",

                Raiz->chaveEsq->cod,
                Raiz->chaveEsq->tipo,
                Raiz->chaveEsq->marca,
                Raiz->chaveEsq->qtd,
                Raiz->chaveEsq->preco,
                Raiz->nChaves);
            printf(

                "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Quantidade: %d\n Preço(R$): %f\n Numero de elementos : %d\n",

                Raiz->chaveDir->cod,
                Raiz->chaveDir->tipo,
                Raiz->chaveDir->marca,
                Raiz->chaveDir->qtd,
                Raiz->chaveDir->preco,
                Raiz->nChaves);
        }
    }

    mostrarTudo(Raiz->esq);
    printf("finalizou esquerda");
    mostrarTudo(Raiz->centro);
    mostrarTudo(Raiz->dir);
}

// Essa função é usada para criar um novo nó na Arv23

Arv23 *criaNO(Calcados *info, Arv23 *noEsq, Arv23 *noCentro)
{
    Arv23 *no = (Arv23 *)calloc(sizeof(Arv23), 1);

    (*no).chaveEsq = info;
    (*no).chaveDir = NULL;
    (*no).nChaves = 1;
    (*no).esq = noEsq;
    (*no).centro = noCentro;
    (*no).dir = NULL;

    return no;
}

// Função usada pela insere23 para adicionar um novo nó
Arv23 *adicionaNo(Arv23 *Raiz, Calcados *info, Arv23 *Novo)
{
    if (info->cod > (*Raiz).chaveEsq->cod)
    {
        (*Raiz).chaveDir = info;
        (*Raiz).dir = Novo;
    }
    else // Faço apenas a troca de posição
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
// Função usanda quando vai inserir um elemento e não tem espaço entao quebra-se o nó
Arv23 *quebraNo(Arv23 **Raiz, Arv23 *NovoNo, Calcados *info, Calcados **infoMeio)
{
    Arv23 *Novo;

    if (info->cod < (**Raiz).chaveEsq->cod) // novoNo == MaiorNó, Info==Struct , infoMeio==Sobe
    {
        *infoMeio = (**Raiz).chaveEsq;
        Novo = criaNO((**Raiz).chaveDir, (**Raiz).centro, (**Raiz).dir);

        (**Raiz).chaveEsq = info;
        (**Raiz).centro = NovoNo;
    }

    else if (info->cod < (**Raiz).chaveDir->cod)
    {
        *infoMeio = info;
        Novo = criaNO((**Raiz).chaveDir, NovoNo, (**Raiz).dir);
    }

    else
    {
        *infoMeio = (**Raiz).chaveDir;
        Novo = criaNO(info, (**Raiz).dir, NovoNo);
    }

    (**Raiz).chaveDir = NULL;
    (**Raiz).nChaves = 1;
    (**Raiz).dir = NULL;

    return Novo;
}
// chamar essa função no lugar da insere23 para inserir
Arv23 *InsereCalcados(Arv23 *pai, Arv23 **Raiz, int cod, char *tipo, char *marca, int qtd, int tam, int linha, float preco, Calcados **infoMeio)
{
    Calcados *calcado = criaCal(cod, tipo, marca, qtd, tam, linha, preco);
    insere23(pai, Raiz, calcado, infoMeio);
}

// Complemento da Insere Calcados
Arv23 *insere23(Arv23 *pai, Arv23 **Raiz, Calcados *info, Calcados **infoMeio)
{
    Arv23 *novo; // Novo == MaiorNó

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
            if (info->cod < (**Raiz).chaveEsq->cod)
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

// Fução para remover um elemento de uma arvore 2 3

// Função para verificar se o elemento está na info 1 ou info 2 usado ela função de excluir
int estaContido(Arv23 *Raiz, int info)
{
    printf("ESTACONTIDO\n");
    if (info == Raiz->chaveEsq->cod)
        return 1;
    if (Raiz->nChaves == 2)
    {

        if (info == Raiz->chaveDir->cod)
            return 2;
    }
    return 0;
}

int excluirElemento(Arv23 **pai, Arv23 **Raiz, int info)
{
    if (*Raiz != NULL)
    {
        printf("ANtes do estacontido");
        if (estaContido(*Raiz, info) != 0)
        {
            printf("Depois do estacontido");

            if (*pai == NULL && folha(*Raiz)) // Verifica se a Raiz da Árvore é um nó Folha.
            {
                if (estaContido(*Raiz, info) == 1)
                    (**Raiz).chaveEsq = (**Raiz).chaveDir;
                ((**Raiz).chaveDir) = NULL;

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
                        (**Raiz).chaveDir = NULL;
                        (**Raiz).dir->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 2 && (**Raiz).centro->nChaves == 2)
                    {
                        (**Raiz).chaveDir = (**Raiz).centro->chaveDir;
                        (**Raiz).centro->chaveDir = NULL;
                        (**Raiz).dir->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 2 && (**Raiz).esq->nChaves == 2)
                    {
                        (**Raiz).chaveDir = NULL;
                        (**Raiz).nChaves = 1;
                        (**Raiz).centro->chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).centro->nChaves = 2;
                        (**Raiz).dir = NULL;
                    }

                    else if (estaContido(*Raiz, info) == 2 && (**Raiz).esq->nChaves == 1)
                    {
                        (**Raiz).chaveDir = NULL;
                        (**Raiz).nChaves = 1;
                        (**Raiz).centro->chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).centro->nChaves = 2;
                        (**Raiz).dir = NULL;
                    }

                    else if (estaContido(*Raiz, info) == 1 && (**Raiz).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**Raiz).centro->chaveEsq;
                        (**Raiz).centro->chaveEsq = (**Raiz).centro->chaveDir;
                        (**Raiz).centro->chaveDir = NULL;
                        (**Raiz).centro->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 1 && (**Raiz).esq->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**Raiz).esq->chaveDir;
                        (**Raiz).esq->chaveDir = NULL;
                        (**Raiz).esq->nChaves = 1;
                    }

                    else if (estaContido(*Raiz, info) == 1 && (**Raiz).centro->nChaves == 1)
                    {
                        (**Raiz).chaveEsq = (**Raiz).chaveDir;
                        (**Raiz).chaveDir = NULL;
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
                            (**Raiz).centro->chaveDir = NULL;
                            (**Raiz).centro->nChaves = 1;
                        }

                        else if ((**Raiz).esq->nChaves == 2)
                        {
                            (**Raiz).chaveEsq = (**Raiz).esq->chaveDir;
                            (**Raiz).esq->chaveDir = NULL;
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
                else
                {
                    Calcados *aux = (*Raiz)->chaveEsq;
                    (**Raiz).chaveEsq = (**Raiz).centro->chaveEsq;
                    (**Raiz).centro->chaveEsq = (**Raiz).centro->chaveDir;
                    (**Raiz).centro->nChaves = 1;
                    (**Raiz).centro->chaveDir = NULL;
                    free(aux);
                }
            }

            else if (*pai != NULL && folha(*Raiz))
            {

                if ((**Raiz).nChaves == 2)
                {
                    if (estaContido(*Raiz, info) == 1)
                        (**Raiz).chaveEsq = (**Raiz).chaveDir;
                    (**Raiz).chaveDir = NULL;
                    (**Raiz).nChaves = 1;
                }

                else if ((**pai).nChaves == 2)
                {
                    if (info > (**pai).chaveDir->cod && (**pai).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveDir;
                        (**pai).chaveDir = (**pai).centro->chaveDir;
                        (**pai).centro->chaveDir = NULL;
                        (**pai).centro->nChaves = 1;
                    }

                    else if (info > (**pai).chaveDir->cod && (**pai).centro->nChaves == 1)
                    {
                        (**pai).centro->chaveDir = (**pai).chaveDir;
                        (**pai).centro->nChaves = 2;
                        (**pai).chaveDir = NULL;
                        (**pai).nChaves = 1;
                        *Raiz = NULL;
                    }

                    else if (info > (**pai).chaveEsq->cod && (**pai).dir->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveDir;
                        (**pai).chaveDir = (**pai).dir->chaveEsq;
                        (**pai).dir->chaveEsq = (**pai).dir->chaveDir;
                        (**pai).dir->chaveDir = NULL;
                        (**pai).dir->nChaves = 1;
                    }

                    else if (info > (**pai).chaveEsq->cod && (**pai).dir->nChaves == 1)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveDir;
                        (**Raiz).chaveDir = (**pai).dir->chaveEsq;
                        (**Raiz).nChaves = 2;
                        (**pai).chaveDir = NULL;
                        (**pai).nChaves = 1;
                        (**pai).dir = NULL;
                    }

                    else if (info < (**pai).chaveEsq->cod && (**pai).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).centro->chaveDir;
                        (**pai).centro->chaveDir = NULL;
                        (**pai).centro->nChaves = 1;
                    }

                    else if (info < (**pai).chaveEsq->cod && (**pai).dir->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).chaveDir;

                        (**pai).chaveDir = (**pai).dir->chaveEsq;
                        (**pai).dir->chaveEsq = (**pai).dir->chaveDir;
                        (**pai).dir->chaveDir = NULL;
                        (**pai).dir->nChaves = 1;
                    }

                    else
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).chaveDir;
                        (**pai).chaveDir = NULL;
                        (**pai).nChaves = 1;
                        (**pai).centro->chaveDir = (**pai).dir->chaveEsq;
                        (**pai).centro->nChaves = 2;
                        (**pai).dir = NULL;
                    }
                }

                else
                {
                    if (info > (**pai).chaveEsq->cod && (**pai).esq->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).esq->chaveDir;
                        (**pai).esq->chaveDir = NULL;
                        (**pai).esq->nChaves = 1;
                    }

                    else if (info < (**pai).chaveEsq->cod && (**pai).centro->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**pai).chaveEsq;
                        (**pai).chaveEsq = (**pai).centro->chaveEsq;
                        (**pai).centro->chaveEsq = (**pai).centro->chaveDir;
                        (**pai).centro->chaveDir = NULL;
                        (**pai).centro->nChaves = 1;
                    }

                    else if (info < (**pai).chaveEsq->cod)
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
                        (**Raiz).dir->chaveDir = NULL;
                        (**Raiz).dir->nChaves = 1;
                    }

                    else if ((**Raiz).centro->nChaves == 2)
                    {
                        (**Raiz).chaveDir = (**Raiz).centro->chaveDir;
                        (**Raiz).centro->chaveDir = NULL;
                        (**Raiz).centro->nChaves = 1;
                    }

                    else
                    {
                        (**Raiz).centro->chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).centro->nChaves = 2;
                        (**Raiz).chaveDir = NULL;
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
                        (**Raiz).centro->chaveDir = NULL;
                        (**Raiz).centro->nChaves = 1;
                    }

                    else if ((**Raiz).esq->nChaves == 2)
                    {
                        (**Raiz).chaveEsq = (**Raiz).esq->chaveDir;
                        (**Raiz).esq->chaveDir = NULL;
                        (**Raiz).esq->nChaves = 1;
                    }

                    else
                    {
                        (**Raiz).chaveEsq = (**Raiz).centro->chaveEsq;
                        (**Raiz).centro->chaveEsq = (**Raiz).chaveDir;
                        (**Raiz).chaveDir = (**Raiz).dir->chaveEsq;
                        (**Raiz).dir->chaveEsq = (**Raiz).dir->chaveDir;
                        (**Raiz).dir->chaveDir = NULL;
                        (**Raiz).dir->nChaves = 1;
                    }
                }
            }
        }

        else if (info < (**Raiz).chaveEsq->cod)
        {
            printf("ANtes de excluir");
            excluirElemento(Raiz, &(**Raiz).esq, info);
            printf("Depois de excluir");
        }

        else if ((**Raiz).nChaves == 1)
            excluirElemento(Raiz, &(**Raiz).centro, info);

        else if (info < (**Raiz).chaveDir->cod)
            excluirElemento(Raiz, &(**Raiz).centro, info);

        else
            excluirElemento(Raiz, &(**Raiz).dir, info);
    }
}
// Função usada para verificar a quantidade de nos folhas em uma arvore 2 3, mas não esta sendo usada nessa tarefa
// int qtdnofolha(Arv23 *Raiz)
// {

//     if (Raiz == NULL)
//     {
//         return 0;
//     }

//     else if (folha(Raiz))
//     {
//         return 1;
//     }
//     else
//     {

//         return 1 + (qtdnofolha(Raiz->dir) + qtdnofolha(Raiz->centro) + qtdnofolha(Raiz->esq));
//     }
// }