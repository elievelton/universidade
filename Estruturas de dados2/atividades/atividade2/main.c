#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"arvore.h"

int main(){

No *raiz, *no;
srand(time(NULL));
int alt, valor,B_pai, M_pai,remove1,remove2;
int produto, qtd_folhas;

No *remove, *pai;

raiz = inicializar();
pai = inicializar();


    
    no = criarNo(10);
    raiz = inserir(raiz, no);
    no = criarNo(9);
    raiz = inserir(raiz, no);
    no = criarNo(32);
    raiz = inserir(raiz, no);
    no = criarNo(15);
    raiz = inserir(raiz, no);
    no = criarNo(87);
    raiz = inserir(raiz, no);
    no = criarNo(55);
    raiz = inserir(raiz, no);


mostrar(raiz);
produto=buscar_numero_produto(raiz);
if(produto==1){
    printf("Não tem nenhum nunero para calculo\n");
}else{
    printf("Valor do produto dos numos maiores que 20 e mult de 5 é:%d\n",produto);
}

qtd_folhas = qtdnofolha(raiz);
printf("A quantidade de nós folhas é de : %d\n", qtd_folhas);
printf("Digite um numero da arvore para devolcer seu pai\n");
scanf("%d",&B_pai);
pai=devolverPai(raiz,B_pai);
mostrarPai(pai);
printf("Digite um numero para remover da arvore\n");
scanf("%d",&remove1);
remove= remover(raiz,remove1);
mostrar(remove);

printf("\n");
liberarMemoria(raiz);

return 0;   



}