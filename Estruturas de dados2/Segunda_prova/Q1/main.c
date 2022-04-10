#include <stdio.h>
#include <stdlib.h>
#include "arv23.h"
#include <time.h>

int menu();
int carregar_arquivo(Arv23 **pai, Arv23 **arvore, Calcados **sobe);

int main()
{

    Calcados *linhas;
    char t[5] = {'1', '2'};
    double t_total, t_insec_total;
    int opcao = 0;
    Arv23 *Arv23, *pai;
    Calcados *sobe = NULL;
    pai = NULL;
    Arv23 = NULL;

    carregar_arquivo(&pai, &Arv23, &sobe);

    // InsereCalcados(pai, &Arv23, 1, "Tenis", "Adidas", 20, 89.90, 10, 1000, &sobe);
    // InsereCalcados(pai, &Arv23, 2, "Sapato_Tenis", "Olimpicus", 222, 59.90, 10, 1000, &sobe);
    // InsereCalcados(pai, &Arv23, 3, "Sapato_Tenis", "Olimpicus", 228, 89.90, 10, 1000, &sobe); // Ta dando erro na hora de inserir mais 1 informação na hora que precisa quebrar o nó
    // InsereCalcados(pai, &Arv23, 4, "Sapato_Tenis", "Olimpicus", 228, 89.90, 10, 1000, &sobe); // Ta dando erro na hora de inserir mais 1 informação na hora que precisa quebrar o nó
    // InsereCalcados(pai, &Arv23, 5, "Sapato_Tenis", "Olimpicus", 228, 89.90, 10, 1000, &sobe); // Ta dando erro na hora de inserir mais 1 informação na hora que precisa quebrar o nó

    mostrar(Arv23); // ta funcionando
    // // printf("%d ",(*Arv23).esq.chaveEsq.cod);
    // // busca(Arv23,2);//ta funcionando
    // excluirElemento(&pai, &Arv23, 2); // ta dando erro de sementação, precisando averiguar
    // printf("----------------------\n");
    // mostrarTudo(Arv23);

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

/*Retorna a quantidade de linhas do arquivo*/
int carregar_arquivo(Arv23 **pai, Arv23 **arvore, Calcados **sobe)
{
    FILE *arq;
    arq = fopen("sapatos_store.txt", "rt");
    int linhas;
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
    }
    else
    {

        while (!feof(arq))
        {
            char load[300];
            int codigo;
            int tamanho;
            int quantidade;
            float preco;
            char tipo[50];
            char marca[50];
            fscanf(arq, "%d %s %s %d %d %f", &codigo, tipo, marca, &tamanho, &quantidade, &preco);
            // printf("%d %s %s %d %d %f linha: %d\n", codigo, tipo, marca, tamanho, quantidade, preco, linhas);
            // Calcados *calcado = criaCal(codigo, tipo, marca, quantidade, tamanho, linhas, preco);
            InsereCalcados(*pai, arvore, codigo, tipo, marca, quantidade, tamanho, linhas, preco, sobe);

            // mostrarCalcado(calcado);
            // insere23(*pai, arvore, calcado, sobe);
            linhas++;
        }
    }
    fclose(arq);
    // mostrarTudo(*arvore);
    return linhas;
}

int menu()
{
    int opcao;
    printf("\n\n-------------------MENU-------------------\n");
    puts("1 - Inserir Calçado\n");
    puts("1 - Inserir Calçado\n");
    puts("1 - Inserir Calçado\n");
    puts("1 - Inserir Calçado\n");
    puts("1 - Inserir Calçado\n");
    puts("Escolha uma das opções: ");
    scanf(" %d", &opcao);
    return opcao;
}