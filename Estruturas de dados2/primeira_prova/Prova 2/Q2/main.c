#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <time.h>

int menu();

int main()
{

  Termo *arvore = create_termo();
  Termo *termo_buscado = create_termo();
  Sub_Termo *sub_termo_buscado = create_sub_termo();
  int opcao = 0;
  char termo[80] = {'\0'};
  char sub_termo[80] = {'\0'};
  int num_pag = 0;

  Paginas *pag = create_paginas();

  do
  {
    opcao = menu();
    switch (opcao)
    {
    case 1:
      printf("Digite o termo que deseja inserir: ");
      scanf(" %s", termo);
      printf("Agora digite as paginas que contem esse termo(Para sair digite 0)\n");

      do
      {
        printf("numero da pagina: ");
        scanf(" %d", &num_pag);
        if (num_pag != 0)
        {
          insert_paginas(&pag, num_pag);
        }
      } while (num_pag != 0);
      insert_termo(&arvore, termo, pag);
      pag = NULL;
      termo[0] = '\0';
      break;
    case 2:
      printf("Degite o termo: ");
      scanf(" %s", termo);
      termo_buscado = search_termo(arvore, termo);
      if (termo_buscado == NULL)
      {
        printf("Termo nao encontrado.\n");
      }
      else
      {
        printf("digite o sub termo de '%s': ", termo);
        scanf(" %s", sub_termo);
        printf("Agora digite as paginas que contem esse sub_termo(Para sair digite 0)\n");
        do
        {
          printf("numero da pagina: ");
          scanf(" %d", &num_pag);
          if (num_pag != 0)
          {
            insert_paginas(&pag, num_pag);
          }
        } while (num_pag != 0);
        insert_sub_termo_to_termo(&termo_buscado, sub_termo, pag);
        pag = NULL;
        termo_buscado = NULL;
        termo[0] = '\0';
        sub_termo[0] = '\0';
      }
      break;
    case 3:
      printf("Degite o termo: ");
      scanf(" %s", termo);
      termo_buscado = search_termo(arvore, termo);
      if (termo_buscado == NULL)
      {
        printf("Termo nao encontrado.\n");
      }
      else
      {
        printf("Agora digite as paginas que contem o termo '%s'(Para sair digite 0)\n", termo);
        do
        {
          printf("numero da pagina: ");
          scanf(" %d", &num_pag);
          if (num_pag != 0)
          {
            insert_paginas_to_termo(&termo_buscado, num_pag);
          }
        } while (num_pag != 0);
        termo_buscado = NULL;
        termo[0] = '\0';
      }
      break;
    case 4:
      printf("Degite o termo: ");
      scanf(" %s", termo);
      termo_buscado = search_termo(arvore, termo);
      if (termo_buscado == NULL)
      {
        printf("Termo nao encontrado.\n");
      }
      else
      {
        printf("Degite o sub termo: ");
        scanf(" %s", sub_termo);
        sub_termo_buscado = search_sub_termo_in_termo(termo_buscado, sub_termo);
        if (termo_buscado == NULL)
        {
          printf("Sub termo nao encontrado.\n");
        }
        else
        {
          printf("Agora digite as paginas que contem o sub termo '%s'(Para sair digite 0)\n", sub_termo);
          do
          {
            printf("numero da pagina: ");
            scanf(" %d", &num_pag);
            if (num_pag != 0)
            {
              insert_paginas_to_sub_termo(&sub_termo_buscado, num_pag);
            }
          } while (num_pag != 0);

          sub_termo_buscado = NULL;
          termo_buscado = NULL;
          termo[0] = '\0';
          sub_termo[0] = '\0';
        }
      }
      break;
    case 5:
      show(arvore);
      break;
    case 6:
      printf("Degite o termo: ");
      scanf(" %s", termo);
      termo_buscado = search_termo(arvore, termo);
      if (termo_buscado == NULL)
      {
        printf("Termo nao encontrado.\n");
      }
      else
      {
        show(termo_buscado);
      }
      break;
    case 7:
      arvore = freeTree(arvore);
      break;
    default:
      break;
    }
  } while (opcao != 0);

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
  printf("5 - Mostrar todos os termos\n");
  printf("6 - Mostrar detalhes de um termo(Subtermos e Paginas)\n");
  printf("7 - Liberar arvore\n");
  printf("0 - Sair\n");
  printf("Escolha uma das opções: ");
  scanf(" %d", &opcao);
  return opcao;
}
