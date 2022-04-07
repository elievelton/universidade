#include <stdio.h>
#include <stdlib.h>
#include "arv23.h"
#include <time.h>

int menu();
int main()
{

    double t_total, t_insec_total;
    int opcao = 0;
    Arv23 *Arv23 = inicializar();

    InsereCalcados(NULL,NULL,1,"Tenis","Adidas",20,89.90,NULL);
    InsereCalcados(NULL,NULL,2,"Tenis","Adidas",20,89.90,NULL);
    mostrar(Arv23);
    
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