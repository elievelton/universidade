#include <stdio.h>
#include <stdlib.h>
#include "Arv23_decla.h"

int main()
{

    struct Arv23 *Raiz, *Pai;
    int valor, sobe = 0, verifica, numero, profundidade, qtdfolha, excluir;

    Raiz = NULL;
    Pai = NULL;


    insere23(Pai, &Raiz, 1, &sobe);
	insere23(Pai, &Raiz, 2, &sobe);
	insere23(Pai, &Raiz, 3, &sobe);
	
	

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