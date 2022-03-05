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


No *inserir_no(No *raiz, int cod, char titulo[], int qt_temp, Lista_info *lis_inf)
{

    if (raiz == NULL)
    {
        No *aux;
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

Lista_info *inserirLista_info(Lista_info *lista, int numero, char titulo[], int ano, int qt_ep, Participantes *part)
{

    Lista_info *novo;
    novo = (Lista_info *)malloc(sizeof(Lista_info));

    novo->numero = numero;
    strcpy(novo->titulo, titulo);
    novo->ano =ano;
    novo->qt_episodios = qt_ep;
    novo->part=part;

    if(lista ==NULL){
        lista = novo;
        novo->proximo = NULL;
    }else{
        novo->proximo = lista;
        lista = novo;
    }
    
    //printf("teste %d",lista->ano);
    return lista;


    
}

Participantes *inserir_participantes(Participantes *raiz, char nome[], char nome_personagem[], char descricao[])
{
    int comp;
    if (raiz == NULL)
    {
        Participantes *aux;
        aux = (Participantes *)malloc(sizeof(Participantes));

        strcpy(aux->Nome, nome);
        strcpy(aux->nome_personagem, nome_personagem);
        strcpy(aux->descricao, descricao);
        aux->esquerdo = NULL;
        aux->direito = NULL;
        return aux;
        
    }
    else
    {
        comp = strcmp(nome_personagem, raiz->nome_personagem);
        
        if (comp < 0)
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

void mostrar_principal(No *raiz)
{
    if (raiz != NULL)
    {
         mostrar_principal(raiz->esquerdo);
        printf("Código:[%d] --- ", raiz->cod);
        printf("Título :[%s] --- ", raiz->titulo);
        printf("Quantidade de temporada(s) :[%d] --- ", raiz->qt_temp);
        printf("\n");
       
        mostrar_principal(raiz->direito);
    }
}
void mostrar_obuscado(No *raiz)
{
    if (raiz != NULL)
    {
        printf("Código:[%d] --- ", raiz->cod);
        printf("Título :[%s] --- ", raiz->titulo);
        printf("Quantidade de temporada(s) :[%d] --- ", raiz->qt_temp);
        printf("\n");
    }
}

void mostrarLista(Lista_info *raiz)
{
    Lista_info *aux = raiz;
    printf("---------Lista de temporadas----------\n");
    while(aux!=NULL)
    {

        printf("Numeros de temporda:[%d]", aux->numero);
        printf("Título: [%s]", aux->titulo);
        printf("Ano :[%d]", aux->ano);
        printf("Quantidade de episodios: [%d]", aux->qt_episodios);
        printf("\n");
        aux=aux->proximo;
    }
}

void mostrar_participante(Participantes *part)
{
    
    if (part != NULL)
    {
        mostrar_participante(part->esquerdo);
        printf("Nome do Ator:[%s] --- ", part->Nome);
        printf("Nome do Personagem :[%s] --- ", part->nome_personagem);
        printf("Descrição do Filme :[%s] --- ", part->descricao);
        printf("\n");
        
        mostrar_participante(part->direito);
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
void liberar_lista(Lista_info *raiz)
{
    free(raiz);
}

No* buscar_versao_1(No *raiz, int num){
    if(raiz){
        if(num == raiz->cod)
            return raiz;
        else if(num < raiz->cod)
            return buscar_versao_1(raiz->esquerdo, num);
        else
            return buscar_versao_1(raiz->direito, num);
    }
    return NULL;
}