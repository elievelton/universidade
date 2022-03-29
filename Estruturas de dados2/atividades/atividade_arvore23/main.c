#include <stdio.h>
#include <stdlib.h>
#include "Arv23_decla.h"

int main()
{

    struct Arv23 *Raiz, *Pai;
    int valor, sobe = 0, verifica, numero, profundidade, qtdfolha;

    Raiz = NULL;
    Pai = NULL;


    insere23(Pai, &Raiz, 100, &sobe);
	insere23(Pai, &Raiz, 500, &sobe);
	insere23(Pai, &Raiz, 400, &sobe);
	insere23(Pai, &Raiz, 300, &sobe);
	insere23(Pai, &Raiz, 600, &sobe);
	insere23(Pai, &Raiz, 450, &sobe);
    mostrar(Raiz);
    puts("Digite um numero para verificar se está na arvore");
    scanf("%d", &numero);
    verifica = busca(Raiz,numero);
    if(verifica){
        printf("O Numero está na arvore\n");
    }else{
        printf("O Numero NÃO está na arvore\n");
    }
    profundidade = altura(Raiz);
    printf("A profundidade dessa raiz é de %d \n ", profundidade);

    qtdfolha =qtdnofolha(Raiz);
    printf("A quantidade de nó folha é %d \n",qtdfolha);
    



    return 0;
}