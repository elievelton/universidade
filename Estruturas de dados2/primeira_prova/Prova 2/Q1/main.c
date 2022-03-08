#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <time.h>

int menu();

int main()
{

    Termos_principais *arvore;

    return 0;
}

int menu()
{
    int opcao;
    printf("MENU\n");
    printf("1 - Inserir um novo termo\n");
    printf("2 - Inserir um novo sub termo a um termo\n");
    printf("3 - Inserir uma pagina para um termo\n");
    printf("4 - Inserir uma pagina para um sub termo de um termo\n");
    printf("5 - Mostrar detalhes de um termo(Subtermos e Paginas)\n");
    printf("6 - Mostrar todos os termos\n");
    printf("7 - Liberar arvore\n");
    printf("Escolha uma das opções: ");
    scanf(" %d", &opcao);

    return opcao;
}
