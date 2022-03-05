#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{

    No *no, *busca;
    Lista_info *lis_inf, *lis_inf2;
    Participantes *part;
     int opcao, valor;

    no = inicializar();
    lis_inf = inicializar();
    part = inicializar();
    part = inserir_participantes(part,"Tomcruize","Vingador", "Filme de guerra e ação");
    part = inserir_participantes(part,"Bradpite","Senho e senhora smith", "Filme de aventura");
    part = inserir_participantes(part,"Carlos aguiar","Menino do chão", "Filme de luta");

    lis_inf = inserirLista_info(lis_inf, 2, "Aviao de guerra", 2015, 20, part);
    lis_inf = inserirLista_info(lis_inf, 33, "Toguro", 2019, 19, part);
    lis_inf = inserirLista_info(lis_inf, 12, "Kemi ko Nowa", 2017, 5, part);

    no = inserir_no(no, 100, "Aviao de guerra", 10, lis_inf);
    lis_inf = inserirLista_info(lis_inf, 3, "Kemi ko Nowa", 2017, 21, part);
    no = inserir_no(no, 10, "Kemi ko Nowa", 2, lis_inf);
    no = inserir_no(no, 901, "Tubarao3", 7, lis_inf);
    no = inserir_no(no, 101, "Putin", 7, lis_inf);
    no = inserir_no(no, 8, "Tubarao2", 6, lis_inf);
    no = inserir_no(no, 4, "Godizila", 3, lis_inf);
    no = inserir_no(no, 5, "Godizila2", 3, lis_inf);
    
    printf("----------------Series cadastras--------------\n");
    mostrar_principal(no);
    mostrarLista(lis_inf);
     printf("----------------Detalhes do Personagem--------------\n");
    mostrar_participante(part);
    do{
        printf("\n\t0 - Sair\n\t1 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        
        case 1:
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            busca = buscar_versao_1(no, valor);
            if(busca)
                mostrar_obuscado(busca);
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);
    liberarMemoria(no);
    liberarMemoria(part);    
    liberar_lista(lis_inf);

    return 0;
}