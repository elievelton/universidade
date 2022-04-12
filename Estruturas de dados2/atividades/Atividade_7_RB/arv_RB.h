#ifndef RB_H
#define RB_H

typedef enum Cor { VERMELHO, PRETO, DUPLO_PRETO } Cor;

typedef int tipo_dado;

typedef struct no {
    enum Cor cor;
    tipo_dado valor;
    struct no *esq, *dir, *pai;
} No;

void inserir (No** raiz, int elemento);
void preorder(No* raiz);
void ajustar(No* no, No** raiz);
void reajustar(No* nulo,No** raiz);
void rotacao_simples_direita(No* pivo, No **raiz);
void rotacao_simples_esquerda(No* pivo, No** raiz);
void rotacao_dupla_direita(No* pivo, No** raiz);
void rotacao_dupla_esquerda(No *pivo,No **raiz);
void remover(No** raiz,int valor);
void imprimir(No *raiz);

int eh_esquerdo(No* no);
int eh_raiz(No* no);

No* criar_nulo(No* pai);
No* irmao(No *no);
No* tio (No* no);
No* maior_elemento(No* raiz);

Cor cor(No* no);

#endif