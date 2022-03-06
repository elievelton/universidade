#include<stdio.h>
#include<stdlib.h>

#include"arvAvl.h"

struct noAvl{
    No *esq, *dir;
    int info, altura;
};

No *inicializar(){
    return NULL;
}

No *criarNo(int valor){
    No *no = inicializar();

    no = (No *)malloc(sizeof(No));

    (*no).info = valor;
    (*no).altura = 0;
    (*no).esq = NULL;
    (*no).dir = NULL;

    return no;
}

int altura(No *raiz) {
    int alt = 0, esq, dir;

    if (raiz == NULL){
        alt = -1;
    } else {
        esq = altura((*raiz).esq);
        dir = altura((*raiz).dir);

        if (esq < dir){
            alt = dir + 1;
        }else{
            alt = esq + 1;
        }
    }
    return alt;
}

int maior(int x, int y){
    int maior = 0;

    if (x > y){
        maior = x;
    }else{
        maior = y;
    }
    return maior;
}

void rotacaoDireita(No **no){
    No *aux;

    aux = (**no).esq;
    (**no).esq = (*aux).dir;
    (*aux).dir = *no;
    (**no).altura = maior(altura((**no).esq), altura((**no).dir)) + 1;
    (*aux).altura = maior(altura((*aux).esq), altura((*aux).dir)) + 1;
    (*no) = aux;
}
void rotacaoEsquerda(No **no){
    No *aux;

    aux = (**no).dir;
    (**no).dir = (*aux).esq;
    (*aux).esq = *no;
    (**no).altura = maior(altura((**no).esq), altura((**no).dir)) + 1;
    (*aux).altura = maior(altura((*aux).esq), altura((*aux).dir)) + 1;
    (*no) = aux;
}

void rotacaoDirEsq(No **no){

    rotacaoDireita(&((**no).dir));
    rotacaoEsquerda(no);
}

void rotacaoEsqDir(No **no){
    rotacaoEsquerda(&((**no).esq));
    rotacaoDireita(no);
}

int fatorBalanceamento(No *raiz){
    int fb = 0, altEsq = 0, altDir = 0;

    altEsq = altura(raiz->esq);
    altDir = altura(raiz->dir);

    fb = altEsq - altDir;

    return fb;
}

int inserirAvl(No **raiz, No *no){
    int inseriu = 1;

    if(*raiz == NULL){
        *raiz = no;
    }else{
        if((*no).info < (**raiz).info){
            int fb;
            inseriu = inserirAvl(&((**raiz).esq), no);
            if (inseriu){
                fb = fatorBalanceamento(*raiz);
                if (fb >= 2){
                    if((*no).info < (**raiz).esq->info){
                        rotacaoDireita(raiz);
                    }else{
                        rotacaoEsqDir(raiz);
                    }
                }
            }
        }else if((*no).info > (**raiz).info){
            int fb;
            inseriu = inserirAvl(&((**raiz).dir), no);
            if (inseriu){
                fb = fatorBalanceamento(*raiz);
                if(fb <= -2){
                    if((*no).info > (**raiz).dir->info){
                        rotacaoEsquerda(raiz);
                    }else{
                        rotacaoDirEsq(raiz);
                    }     
                }
            }
        }else{
            inseriu = 0;
        }
        (**raiz).altura = maior(altura((**raiz).esq), altura((**raiz).dir)) + 1;
    }
    return inseriu;
}

void buscar(No *raiz, int valor, int *passos){
    if (raiz == NULL){
        printf("Não encontrado\n");

    }else if((*raiz).info == valor){
        printf("!(%d)!\n", (*raiz).info);

    }else if ((*raiz).info > valor){
        printf("(%d) -> ", (*raiz).info);
        buscar((*raiz).esq, valor, passos);
        (*passos)++;

    }else{
        printf("(%d) -> ", (*raiz).info);
        buscar((*raiz).dir, valor, passos);
        (*passos)++;
    }
}

void mostrar(No *raiz){
    if (raiz != NULL){
        printf("%d(", (*raiz).info);
        mostrar((*raiz).esq);
        mostrar((*raiz).dir);
        printf(")");
    }
}

void liberarMemoria(No *raiz) {
    if (raiz != NULL){
        liberarMemoria((*raiz).esq);
        liberarMemoria((*raiz).dir);
        free(raiz);
    }
}
int qtdElementos(No *raiz){
    int count = 0;

    if(raiz == NULL){
        count = 0;
    }else{
        count = qtdElementos((*raiz).dir)
                + 1
                + qtdElementos((*raiz).esq);
    }
    return count;
}


void mostrarNo(No *no){
    printf("Valor do nó: %d\n", (*no).info);
}