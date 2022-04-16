#ifndef RB_H
#define RB_H
#include <stdio.h>

typedef enum Cor
{
  VERMELHO,
  PRETO,
  DUPLO_PRETO
} Cor;

typedef struct Calcados Calcados;
typedef struct No No;

No *InsereCalcados(No **Raiz, int cod, char *tipo, char *marca, int qtd, int tam, int linha, float preco);

void inserir(No **raiz, Calcados *elemento);
void preorder(No *raiz);
void ajustar(No *no, No **raiz);
void reajustar(No *nulo, No **raiz);
void rotacao_simples_direita(No *pivo, No **raiz);
void rotacao_simples_esquerda(No *pivo, No **raiz);
void rotacao_dupla_direita(No *pivo, No **raiz);
void rotacao_dupla_esquerda(No *pivo, No **raiz);
void remover(No **raiz, int valor);
void imprimir(No *raiz);

int eh_esquerdo(No *no);
int eh_raiz(No *no);

No *criar_nulo(No *pai);
No *irmao(No *no);
No *tio(No *no);
No *maior_elemento(No *raiz);
No *buscar(No *raiz, int valor);
Calcados *buscar_calcados(No *raiz, int valor);
void calcado_atualizar_quantidade(Calcados *calcado, int qtd);
void salvar_arvore(FILE *arq, No *Raiz);
void mostrar_calcado(Calcados *calcado);
Cor cor(No *no);

#endif