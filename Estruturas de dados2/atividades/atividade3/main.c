#include<stdio.h>
#include<stdlib.h>
#include"arvore.h"

int main(){

    No *no;
    Lista_info *lis_inf;
    Participantes *part;
    int teste;

    no = inicializar();
    lis_inf = inicializar_lista();
    part =inicializar_participantes();
    lis_inf = inserirLista_info(lis_inf,2,"Aviao de guerra",2015,20,part);
    no = inserir_no(no,100,"Aviao de guerra", 10,lis_inf);
    no = inserir_no(no,10,"Kemi ko Nowa", 2,lis_inf);
    no = inserir_no(no,901,"Tubarao3", 7,lis_inf);
    no = inserir_no(no,101,"Putin", 7,lis_inf);
    no = inserir_no(no,8,"Tubarao2", 6,lis_inf);
    no = inserir_no(no,4,"Godizila", 3,lis_inf);
    no = inserir_no(no,5,"Godizila2", 3,lis_inf);
    printf("----------------Series cadastras--------------\n");
    mostrar_principal(no,lis_inf);
    liberarMemoria(no);

    return 0;
}