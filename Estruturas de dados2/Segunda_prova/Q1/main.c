#include <stdio.h>
#include <stdlib.h>
#include "arv23.h"
#include <time.h>

int menu();
int main()
{

    double t_total, t_insec_total;
    int opcao = 0;
    Arv23 *Arv23,*pai ;
    Calcados *sobe = NULL;
    pai =NULL;;
    Arv23 = NULL;

    InsereCalcados(pai,&Arv23,1,"Tenis","Adidas",20,89.90,&sobe);
    InsereCalcados(pai,&Arv23,2,"Sapato_Tenis","Olimpicus",222,59.90,&sobe);
    InsereCalcados(pai,&Arv23,3,"Sapato_Tenis","Olimpicus",228,89.90,&sobe); //Ta dando erro na hora de inserir mais 1 informação na hora que precisa quebrar o nó

    mostrarTudo(Arv23);//ta funcionando
    //printf("%d ",(*Arv23).esq.chaveEsq.cod);
    //busca(Arv23,2);//ta funcionando
    excluirElemento(&pai,&Arv23,2); //ta dando erro de sementação, precisando averiguar
    printf("----------------------\n");
    mostrarTudo(Arv23);
    
    // clock_t t_ini, t_fim;
    // FILE *arq, *arq2;
    // srand(time(NULL));
    // arq = fopen("tempo_de_busca.txt", "w");;
    // do
    // {
    //     opcao = menu();
    //     switch (opcao)
    //     {
    //     case 1:
    //     ;  
    
    //     default:
    //         break;
    //     }
    // } while (opcao != 0);
    // puts("Resultados salvos no arquivo");
    // printf("Resultados salvos no arquivo 'tempo_de_insercao.txt'!\n");
    // fclose(arq);

    return 0;
}

// int menu()
// {
//     int opcao;
//     puts("MENU");
//     puts("1 - Inserir Calçado");

//     puts("Escolha uma das opções: ");
//     scanf(" %d", &opcao);
//     return opcao;
// }