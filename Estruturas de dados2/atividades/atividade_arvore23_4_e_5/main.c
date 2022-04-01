#include <stdio.h>
#include <stdlib.h>
#include "Arv23_decla.h"

int main()
{

    struct Arv23 *Raiz, *Pai;
    int valor, sobe = 0, verifica, numero, profundidade, qtdfolha, excluir;

    Raiz = NULL;
    Pai = NULL;


    insere23(Pai, &Raiz, 1000, &sobe);
	insere23(Pai, &Raiz, 500, &sobe);
	insere23(Pai, &Raiz, 600, &sobe);
	insere23(Pai, &Raiz, 2000, &sobe);
	insere23(Pai, &Raiz, 1500, &sobe);
	insere23(Pai, &Raiz, 200, &sobe);
    insere23(Pai, &Raiz, 1300, &sobe);
    insere23(Pai, &Raiz, 900, &sobe);
    insere23(Pai, &Raiz, 4000, &sobe);

    mostrar(Raiz);

    puts("Digite um numero para verificar se está na arvore");
    scanf("%d", &numero);
    verifica = busca(Raiz,numero);
    if(verifica==1){
        printf("O Numero está na arvore\n");
    }else{
        printf("O Numero NÃO está na arvore\n");
    }
    profundidade = altura(Raiz);
    printf("A profundidade dessa raiz é de %d \n ", profundidade);

    qtdfolha =qtdnofolha(Raiz);
    printf("A quantidade de nó folha é %d \n",qtdfolha);


    puts("Digite um numero para excluir da Arv23");
    scanf("%d",&excluir);
    excluirElemento(NULL,&Raiz,excluir);
    mostrar(Raiz);



    return 0;
}