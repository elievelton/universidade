#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <gconio.h> //Usei para ajudar na identificação da cor ao mostrar no raiz, precisa baixar esse aquivo
#include "arv_RB.h"

#define BLACK 0
#define RED 4

struct No
{
  enum Cor cor;
  Calcados *info;
  No *esq, *dir, *pai;
};

struct Calcados
{
  int cod;
  char tipo[50];
  char marca[50];
  int qtd;
  float preco;
  int tamanho;
  int posicao_arquivo; // Deve guardar a posição de um caçado dentro do arquivo
};
// Cria um objeto calçado
Calcados *criaCal(int cod, char *tipo, char *marca, int qtd, int tamanho, int posicao_arquivo, float preco)
{
  Calcados *info = (Calcados *)malloc(sizeof(Calcados));

  info->cod = cod;
  strcpy(info->tipo, tipo);
  strcpy(info->marca, marca);
  info->qtd = qtd;
  info->preco = preco;
  info->tamanho = tamanho;
  info->posicao_arquivo = posicao_arquivo;
  return info;
}
// Essa função é usada para inserir um novo calçado
No *InsereCalcados(No **Raiz, int cod, char *tipo, char *marca, int qtd, int tam, int linha, float preco)
{
  Calcados *calcado = criaCal(cod, tipo, marca, qtd, tam, linha, preco);
  inserir(Raiz, calcado);
}
void inserir(No **raiz, Calcados *elemento)
{
  No *temp, *pai, *novo;
  temp = *raiz;
  pai = NULL;

  while (temp != NULL)
  {
    pai = temp;
    if (elemento->cod > temp->info->cod)
    {
      temp = temp->dir;
    }
    else
    {
      temp = temp->esq;
    }
  }

  novo = (No *)malloc(sizeof(struct No));
  novo->info = elemento;
  novo->esq = NULL;
  novo->dir = NULL;
  novo->cor = VERMELHO;
  novo->pai = pai;

  if (*raiz != NULL)
  {
    if (elemento->cod > pai->info->cod)
    {
      pai->dir = novo;
    }
    else
    {
      pai->esq = novo;
    }
  }
  else
  {
    *raiz = novo;
  }
  ajustar(novo, raiz);
}

// Não estou usando essa função, criammos para para testes, estamos usando a função imprimir
void preorder(No *raiz)
{
  if (raiz == NULL)
    ;
  else
  {
    if (raiz->cor == PRETO)
    {
      printf(
          "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Tamanho: %d\n Quantidade: %d\n Preço(R$): %f\n Linha no arquivo: %d\n",

          raiz->info->cod,
          raiz->info->tipo,
          raiz->info->marca,
          raiz->info->tamanho,
          raiz->info->qtd,
          raiz->info->preco,
          raiz->info->posicao_arquivo);
    }
    else
    {
      printf(
          "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Tamanho: %d\n Quantidade: %d\n Preço(R$): %f\n Linha no arquivo: %d\n",

          raiz->info->cod,
          raiz->info->tipo,
          raiz->info->marca,
          raiz->info->tamanho,
          raiz->info->qtd,
          raiz->info->preco,
          raiz->info->posicao_arquivo);
    }
    preorder(raiz->esq);
    preorder(raiz->dir);
  }
}
// usada para ccria um no nulo, para ultilizar em uma situação especifica de rotação
No *criar_nulo(No *pai)
{
  No *nulo = (No *)malloc(sizeof(No));
  nulo->info = NULL;
  nulo->cor = DUPLO_PRETO;
  nulo->pai = pai;
  nulo->esq = NULL;
  nulo->dir = NULL;
  return nulo;
}
// Verifica ca cor do Nó
Cor cor(No *no)
{
  if (no == NULL || no->cor == PRETO)
    return PRETO;
  else
    return VERMELHO;
}
// Indentificados o filho da esquerda
int eh_esquerdo(No *no)
{
  if (no == no->pai->esq)
    return 1;
  else
    return 0;
}
// indentificamos o pai
int eh_raiz(No *no)
{
  if (no->pai == NULL)
    return 1;
  else
    return 0;
}
// retornamos o imão de um nó
No *irmao(No *no)
{
  if (eh_esquerdo(no) == 1)
  {
    return no->pai->dir;
  }
  else
  {
    return no->pai->esq;
  }
}
// retornamos o tio de um no
No *tio(No *no)
{
  if (eh_esquerdo(no->pai) == 1)
    return no->pai->pai->dir;
  else
    return no->pai->pai->esq;
}
// buscamos o maio elemento
No *maior_elemento(No *raiz)
{
  if (raiz == NULL || raiz->dir == NULL)
  {
    return raiz;
  }
  else
  {
    return maior_elemento(raiz->dir);
  }
}
// fazemos ajustes de botação e cor em um nó quando ele é inserido na arvore
void ajustar(No *no, No **raiz)
{
  if (eh_raiz(no) == 1)
  {
    no->cor = PRETO;
    return;
  }
  if (cor(no->pai) == VERMELHO)
  {
    if (cor(tio(no)) == VERMELHO)
    {
      no->pai->cor = PRETO;
      tio(no)->cor = PRETO;
      no->pai->pai->cor = VERMELHO;

      ajustar(no->pai->pai, raiz);
    }
    else
    {
      if (eh_esquerdo(no) == 1 && eh_esquerdo(no->pai) == 1)
      {
        no->pai->pai->cor = VERMELHO;
        no->pai->cor = PRETO;
        rotacao_simples_direita(no->pai->pai, raiz);
        return;
      }
      if (eh_esquerdo(no) == 1 && eh_esquerdo(no->pai) == 0)
      {
        rotacao_dupla_esquerda(no->pai->pai, raiz);
        return;
      }
      if (eh_esquerdo(no) == 0 && eh_esquerdo(no->pai) == 0)
      {
        no->pai->pai->cor = VERMELHO;
        no->pai->cor = PRETO;
        rotacao_simples_esquerda(no->pai->pai, raiz);
        return;
      }
      if (eh_esquerdo(no) == 0 && eh_esquerdo(no->pai) == 1)
      {
        rotacao_dupla_direita(no->pai->pai, raiz);
        return;
      }
    }
  }
}
// fazemos a rotação simples Direita
void rotacao_simples_direita(No *pivo, No **raiz)
{
  No *u = pivo->esq;
  pivo->esq = u->dir;

  if (pivo->esq != NULL)
  {
    pivo->esq->pai = pivo;
  }
  u->pai = pivo->pai;

  if (eh_raiz(u) == 1)
  {
    *raiz = u;
  }
  else
  {
    if (eh_esquerdo(pivo) == 1)
    {
      u->pai->esq = u;
    }
    else
    {
      u->pai->dir = u;
    }
  }
  u->dir = pivo;
  pivo->pai = u;
}
// rotação simples  direita
void rotacao_simples_esquerda(No *pivo, No **raiz)
{
  No *u = pivo->dir;
  pivo->dir = u->esq;

  if (pivo->dir != NULL)
  {
    pivo->dir->pai = pivo;
  }
  u->pai = pivo->pai;

  if (eh_raiz(u) == 1)
  {
    *raiz = u;
  }
  else
  {
    if (eh_esquerdo(pivo) == 1)
    {
      u->pai->esq = u;
    }
    else
    {
      u->pai->dir = u;
    }
  }

  u->esq = pivo;
  pivo->pai = u;
}
// rotação dupla direita
void rotacao_dupla_direita(No *pivo, No **raiz)
{
  pivo->cor = VERMELHO;
  pivo->esq->dir->cor = PRETO;

  rotacao_simples_esquerda(pivo->esq, raiz);
  rotacao_simples_direita(pivo, raiz);
}

// Rotação dupla esquerda
void rotacao_dupla_esquerda(No *pivo, No **raiz)
{
  pivo->cor = VERMELHO;
  pivo->dir->esq->cor = PRETO;

  rotacao_simples_direita(pivo->dir, raiz);
  rotacao_simples_esquerda(pivo, raiz);
}
// Removendo um elemento do nó
void remover(No **raiz, int valor)
{
  No *temp = (*raiz);
  No *no = NULL;
  while (temp != NULL)
  {
    no = temp;
    if (no->info->cod == valor)
    {
      break;
    }
    if (valor > temp->info->cod)
    {
      temp = temp->dir;
    }
    else
    {
      temp = temp->esq;
    }
  }
  if (temp == NULL)
  {
    temp = NULL;
    return; // testando um problema na remoção
  }
  if (cor(no) == VERMELHO)
  {
    if (eh_esquerdo(no) == 1)
    {
      if (no->dir == NULL)
      {
        no->pai->esq = no->esq;
        if (no->esq != NULL)
        {
          no->esq->pai = no->pai;
          no->esq->cor = no->cor;
        }
        free(no);
      }
      if (no->esq == NULL)
      {
        no->pai->esq = no->dir;
        no->dir->pai = no->pai;
        no->dir->cor = no->cor;
        free(no);
      }
      else
      {
        No *m_esquerdo = maior_elemento(no->esq);
        no->info = m_esquerdo->info;
        m_esquerdo = buscar(temp, valor); // observar esse ponto, não tenho certeza se está certo
        remover(&(no->esq), valor);
      }
    }
    else
    {
      if (no->dir == NULL)
      {
        no->pai->dir = no->esq;
        if (no->esq != NULL)
        {
          no->esq->pai = no->pai;
          no->esq->cor = no->cor;
        }
        free(no);
        return;
      }
      if (no->esq == NULL)
      {
        no->pai->dir = no->dir;
        no->dir->pai = no->pai;
        no->dir->cor = no->cor;
        free(no);
        return;
      }
      else
      {
        No *m_esquerdo = maior_elemento(no->esq);
        no->info = m_esquerdo->info;
        m_esquerdo = buscar(temp, valor);
        remover(&(no->esq), valor);
        return;
      }
    }
  }
  else
  {
    if (eh_raiz(no) == 1)
    {
      if (no->dir == NULL && no->esq == NULL)
      {
        No *nulo = criar_nulo(no->pai);
        *raiz = nulo;
        reajustar(nulo, raiz);
        free(no);
        return;
      }
      else
      {
        if (no->esq != NULL)
        {
          No *m_esquerdo = maior_elemento(no->esq);
          no->info = m_esquerdo->info;
          m_esquerdo = buscar(temp, valor);
          remover(&(no->esq), valor);
          return;
        }
        else
        {
          No *m_direito = maior_elemento(no->dir);
          no->info = m_direito->info;
          m_direito = buscar(temp, valor);
          remover(&(no->dir), valor);
          return;
        }
      }
    }
    if (eh_esquerdo(no) == 1)
    {
      if (no->dir == NULL && no->esq == NULL)
      {
        No *nulo = criar_nulo(no->pai);
        no->pai->esq = nulo;
        reajustar(nulo, raiz);

        return;
      }
      if (no->dir == NULL && no->esq != NULL)
      {
        no->esq->cor = no->cor;
        no->esq->pai = no->pai;
        no->pai->esq = no->esq;
        free(no);
        return;
      }
      else
      {
        no->dir->cor = no->cor;
        no->dir->pai = no->pai;
        no->pai->esq = no->dir;
        free(no);
        return;
      }
    }
    else
    {
      if (no->dir == NULL && no->esq == NULL)
      {
        No *nulo = criar_nulo(no->pai);
        no->pai->dir = nulo;
        reajustar(nulo, raiz);
        return;
      }
      if (no->dir == NULL)
      {
        no->pai->dir = no->esq;
        no->esq->cor = no->cor;
        no->esq->pai = no->pai;

        free(no);

        return;
      }
      else
      {
        no->pai->dir = no->dir;
        no->dir->cor = no->cor;
        no->dir->pai = no->pai;
        free(no);
        return;
      }
    }
  }
}

void reajustar(No *nulo, No **raiz)
{
  if (eh_raiz(nulo) == 1)
  {
    *raiz = NULL;

    free(nulo);

    return;
  }
  if (cor(nulo->pai) == PRETO && cor(irmao(nulo)) == VERMELHO)
  {
    irmao(nulo)->cor = PRETO;
    nulo->pai->cor = VERMELHO;

    if (eh_esquerdo(nulo) == 1)
    {
      rotacao_simples_esquerda(nulo->pai, raiz);
    }
    else
    {
      rotacao_simples_direita(nulo->pai, raiz);
    }
    reajustar(nulo, raiz);
    return;
  }
  if (cor(nulo->pai) == PRETO && cor(irmao(nulo)) == PRETO && cor(irmao(nulo)->esq) == PRETO && cor(irmao(nulo)->dir) == PRETO)
  {
    irmao(nulo)->cor = VERMELHO;
    reajustar(nulo, raiz);
    return;
  }
  if (cor(nulo->pai) == VERMELHO && cor(irmao(nulo)) == PRETO && cor(irmao(nulo)->esq) == PRETO && cor(irmao(nulo)->dir) == PRETO)
  {
    if (irmao(nulo) != NULL)
    {
      irmao(nulo)->cor = VERMELHO;
    }
    nulo->pai->cor = PRETO;

    if (eh_esquerdo(nulo) == 1)
    {
      nulo->pai->esq = NULL;
    }
    else
    {
      nulo->pai->dir = NULL;
    }
    free(nulo);
    return;
  }
  if (eh_esquerdo(nulo) == 1 && cor(irmao(nulo)) == PRETO && cor(irmao(nulo)->esq) == VERMELHO && cor(irmao(nulo)->dir) == PRETO)
  {
    irmao(nulo)->cor = VERMELHO;
    irmao(nulo)->esq->cor = PRETO;

    rotacao_simples_direita(irmao(nulo), raiz);

    reajustar(nulo, raiz);

    return;
  }
  if (eh_esquerdo(nulo) == 0 && cor(irmao(nulo)) == PRETO && cor(irmao(nulo)->dir) == VERMELHO && cor(irmao(nulo)->esq) == PRETO)
  {
    irmao(nulo)->cor = VERMELHO;
    irmao(nulo)->dir->cor = PRETO;

    rotacao_simples_esquerda(irmao(nulo), raiz);

    reajustar(nulo, raiz);

    return;
  }
  if (eh_esquerdo(nulo) == 1 && cor(irmao(nulo)) == PRETO && cor(irmao(nulo)->dir) == VERMELHO)
  {
    irmao(nulo)->cor = nulo->pai->cor;
    irmao(nulo)->dir->cor = PRETO;
    nulo->pai->cor = PRETO;
    nulo->pai->esq = NULL;

    rotacao_simples_esquerda(nulo->pai, raiz);

    free(nulo);

    return;
  }
  if (eh_esquerdo(nulo) == 0 && cor(irmao(nulo)) == PRETO && cor(irmao(nulo)->esq) == VERMELHO)
  {
    irmao(nulo)->cor = nulo->pai->cor;
    irmao(nulo)->esq->cor = PRETO;
    nulo->pai->cor = PRETO;
    nulo->pai->dir = NULL;

    rotacao_simples_direita(nulo->pai, raiz);

    free(nulo);

    return;
  }
}

void calcado_atualizar_quantidade(Calcados *calcado, int qtd)
{
  calcado->qtd = qtd;
}

// Estamos imprimindo colorido para ficar mais simples de visualizar e identificar possiveis erros
void mostrar_calcado(Calcados *calcado)
{
  if (calcado != NULL)
  {
    printf(
        "\n-------Código: %d --------\n Tipo: %s\n Marca: %s\n Tamanho: %d\n Quantidade: %d\n Preço(R$): %f\n Linha no arquivo: %d\n",
        calcado->cod,
        calcado->tipo,
        calcado->marca,
        calcado->tamanho,
        calcado->qtd,
        calcado->preco,
        calcado->posicao_arquivo);
  }
}

void imprimir(No *raiz)
{
  //  Essa função imprime os elementos de forma recursiva

  if (raiz)
  { //  se a árvore não for vazia...
    //  Mostra os elementos em pré-ordem
    if (raiz->cor == VERMELHO)
    {
      // textbackground(4); // cor vermelha no nó
      mostrar_calcado(raiz->info); //  mostra a raiz
      // textbackground(0);
    }
    else
    {

      mostrar_calcado(raiz->info);
    }

    imprimir(raiz->esq); //  mostra a sae (subárvore à esquerda)
    imprimir(raiz->dir); //  mostra a sad (subárvore à direita)
  }
}

// FazerProcura na Arvore usando na função remover

No *buscar(No *raiz, int num)
{
  if (raiz)
  {
    if (num == raiz->info->cod)
      return raiz;
    else if (num < raiz->info->cod)
      return buscar(raiz->esq, num);
    else
      return buscar(raiz->dir, num);
  }
  return NULL;
}

No *busca_personalizada(No *raiz, int valor)
{
  if (raiz)
  {
    printf("---> %d\n", raiz->info->cod);
    if (valor == raiz->info->cod)
      return raiz;
    else if (valor < raiz->info->cod)
      return buscar(raiz->esq, valor);
    else
      return buscar(raiz->dir, valor);
  }
  return NULL;
}

Calcados *buscar_calcados(No *raiz, int valor)
{
  No *no = buscar(raiz, valor);
  return no->info;
}

void salvar_arvore(FILE *arq, No *Raiz)
{
  if (Raiz != NULL)
  {

    fprintf(arq, "%d %s %s %d %d %f", Raiz->info->cod, Raiz->info->tipo, Raiz->info->marca, Raiz->info->tamanho, Raiz->info->qtd, Raiz->info->preco);
    fputs("\n", arq);

    salvar_arvore(arq, Raiz->esq);
    salvar_arvore(arq, Raiz->dir);
  }
}