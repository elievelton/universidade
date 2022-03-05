#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct no
{
    int cod;
    char titulo[50];
    int qt_temp;
    Lista_info *lis_info;
    No *esquerdo, *direito;
};
struct lista_info
{
    int numero;
    char titulo[50];
    int ano;
    int qt_episodios;
    Participantes *part;
    Lista_info *proximo;
};
struct participantes
{
    char Nome[50];
    char nome_personagem[50];
    char descricao[200];
    Participantes *esquerdo, *direito;
};

No *inicializar()
{
    return NULL;
}
Lista_info *inicializar_lista()
{
    return NULL;
}
Participantes *inicializar_participantes()
{
    return NULL;
}



No *inserir_no(No *raiz, int cod, char titulo[], int qt_temp,Lista_info *lis_inf)
{

    if (raiz== NULL)
    {
        No *aux ;
        aux = (No *)malloc(sizeof(No));
        aux->cod = cod;
        strcpy(aux->titulo, titulo);
        aux->qt_temp = qt_temp;
        aux->lis_info = lis_inf;
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
    }
    else
    {
        if (cod < raiz->cod)
        {
            raiz->esquerdo = inserir_no(raiz->esquerdo, cod, titulo, qt_temp, lis_inf);
        }
        else
        {
            raiz->direito = inserir_no(raiz->direito, cod, titulo, qt_temp, lis_inf);
        }
        
    }
    return raiz;
}

Lista_info *inserirLista_info(Lista_info *raiz, int numero, char titulo[], int ano, int qt_ep, Participantes *part)
{

    Lista_info *novaLista;
    novaLista = (Lista_info *)malloc(sizeof(Lista_info));
    novaLista->numero = numero;
    strcpy(novaLista->titulo, titulo);
    novaLista->ano = ano;
    novaLista->qt_episodios = qt_ep;
    novaLista->part = part;
    novaLista->proximo = raiz;

    return novaLista;

}

Participantes *inserir_participantes(Participantes *raiz, char nome[], char nome_personagem[], char descricao[])
{
    int comp;
    if (raiz == NULL)
    {
        Participantes *aux = (Participantes *)malloc(sizeof(Participantes));

        strcpy(aux->Nome, nome);
        strcpy(aux->nome_personagem, nome_personagem);
        strcpy(aux->descricao, descricao);
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return raiz;
    }
    else
    {
        comp = strcmp(nome_personagem, raiz->nome_personagem);
        if (comp<0)
        {
            raiz->esquerdo = inserir_participantes(raiz->esquerdo, nome, nome_personagem, descricao);
        }
        else
        {
            raiz->direito = inserir_participantes(raiz->direito, nome, nome_personagem, descricao);
        }
        return raiz;
    }
}

void mostrar_principal(No *raiz,Lista_info *lis_inf ){
    if (raiz != NULL){
        printf("Código:[%d] --- ", raiz->cod);
        printf("Título :[%s] --- ", raiz->titulo);
        printf("Quantidade de temporada(s) :[%d] --- ", raiz->qt_temp);
        printf("\n");
        printf("Lista de temporadas");
        printf("Numeros de temporda:[%d]",lis_inf->numero);
        printf("Título: [%s]",lis_inf->titulo);
        printf("Ano :[%d]",lis_inf->ano);
        printf("Quantidade de episodios: [%d]",lis_inf->qt_episodios);
         printf("\n");
        mostrar_principal(raiz->esquerdo,lis_inf);
        mostrar_principal(raiz->direito,lis_inf);
    }
}
void liberarMemoria(No *raiz){
    if (raiz != NULL){
        liberarMemoria((*raiz).esquerdo);
        liberarMemoria((*raiz).direito);
        free(raiz);
    }
}