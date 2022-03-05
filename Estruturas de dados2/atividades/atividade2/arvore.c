#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct no
{
    int valor;
    No *esquerdo, *direito;
    
    
};
// inicializa
No *inicializar()
{
    return NULL;
}
// Cria

No *inserir(No *raiz, No *no)
{

    if (raiz == NULL)
    {
        raiz = no;
    }
    else if ((*no).valor < (*raiz).valor)
    {
        (*raiz).esquerdo = inserir((*raiz).esquerdo, no);
    }
    else if ((*no).valor > (*raiz).valor)
    {
        (*raiz).direito = inserir((*raiz).direito, no);
    }

    return raiz;
}
// libera a memoria
void liberarMemoria(No *raiz)
{
    if (raiz != NULL)
    {
        liberarMemoria((*raiz).esquerdo);
        liberarMemoria((*raiz).direito);
        free(raiz);
    }
}
// Calcula a altura
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
// Imprimir
void mostrar(No *raiz)
{
    if (raiz)
    {

        printf("%d(", (*raiz).valor);
        mostrar((*raiz).esquerdo);
        mostrar((*raiz).direito);
        printf(")");
    }
}
void mostrarPai(No *pai)
{
    if (pai)
    {

        printf("O Pai do número selecionado é :%d\n", (*pai).valor);
        
    }else{
        printf("Não possui Pai\n");
    }
}
// Faz a multiplicação ou soma só trocar os sinais
int buscar_numero_produto(No *raiz)
{
    if (raiz == NULL)
    {
        return 1;
    }

    if (((*raiz).valor % 5 == 0) && ((*raiz).valor > 20))
    {
        return raiz->valor * buscar_numero_produto(raiz->direito) * buscar_numero_produto(raiz->esquerdo);
    }
    return buscar_numero_produto(raiz->direito) * buscar_numero_produto(raiz->esquerdo);
}
// conta a quantidade de nós folha
int qtdnofolha(No *raiz)
{

    if (raiz == NULL)
    {
        return 0;
    }
    if (raiz->esquerdo == NULL && raiz->direito == NULL)
    {
        return 1;
    }
    else
    {

        return qtdnofolha(raiz->direito) + qtdnofolha(raiz->esquerdo);
    }
}

No *devolverPai(No *raiz, int num)
{
    No *aux;
    if (raiz == NULL) // árvore vazia
        return NULL;
    else if (raiz->esquerdo == NULL && raiz->direito == NULL) // só tem raiz
        return NULL;
    else if ((raiz->esquerdo != NULL) && (raiz->esquerdo->valor == num))
        return (raiz);
    else if ((raiz->direito != NULL) && (raiz->direito->valor == num))
        return (raiz);
    else
    {
        aux = devolverPai(raiz->esquerdo, num);
        if (aux ==NULL)
            aux = devolverPai(raiz->direito, num);
        return (aux);
    }
}
No *buscar(No *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar(raiz->esquerdo, num);
        else
            return buscar(raiz->direito, num);
    }
    return NULL;
}

/*
      função para remover nós da Árvore binária
*/
No *remover(No *raiz, int num) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->valor == num) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", num);
                return NULL;
            }
            else{
                // remover nós que possuem 1 ou 2 filhos
            }
        } else {
            if(num < raiz->valor)
                raiz->esquerdo = remover(raiz->esquerdo, num);
            else
                raiz->direito = remover(raiz->direito, num);
            return raiz;
        }
    }
}