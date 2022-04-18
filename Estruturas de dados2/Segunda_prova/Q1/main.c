#include <stdio.h>
#include <stdlib.h>
#include "arv23.h"
#include <time.h>

int menu();
void inserir_calcado_no_arquivo(int codigo, char *tipo, char *marca, int quantidade, int tamanho, float preco);
void atualizar_arquivo(Arv23 *Raiz);

int main()
{
    double t_total, t_insec_total;
    int codigo;
    int tamanho;
    int quantidade;
    float preco;
    int linha;
    char tipo[50];
    char marca[50];
    int opcao = 0;
    int codigo_buscado;
    double tempo_in[30], busca_tempo[30];
    clock_t t_ini, t_fim;
    Arv23 *Arv23, *pai;
    Calcados *sobe = NULL, *calcado_buscado = NULL;
    pai = NULL;
    Arv23 = NULL;

    FILE *arq;
    arq = fopen("sapatos_store.txt", "rt");
    int linhas = 1;
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
    }
    else
    {
        while (!feof(arq))
        {
            int codigo;
            int tamanho;
            int quantidade;
            float preco;
            char tipo[50];
            char marca[50];
            fscanf(arq, "%d %s %s %d %d %f\n", &codigo, tipo, marca, &tamanho, &quantidade, &preco);
            InsereCalcados(pai, &Arv23, codigo, tipo, marca, quantidade, tamanho, linhas, preco, &sobe);
            linhas++;
        }
    }
    fclose(arq);

    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("Digite o codigo do Calcado: ");
            scanf(" %d", &codigo);
            printf("Digite o tipo do Calcado: ");
            scanf(" %s", tipo);
            printf("Digite o marca do Calcado: ");
            scanf(" %s", marca);
            printf("Digite o tamanho do Calcado: ");
            scanf(" %d", &tamanho);
            printf("Digite a quantidade do Calcado: ");
            scanf(" %d", &quantidade);
            printf("Digite o preco do Calcado: ");
            scanf(" %f", &preco);
            linhas++;
            InsereCalcados(pai, &Arv23, codigo, tipo, marca, quantidade, tamanho, linhas, preco, &sobe);
            inserir_calcado_no_arquivo(codigo, tipo, marca, quantidade, tamanho, preco);
            // atualizar_arquivo(Arv23);

            break;
        case 2:
            printf("Digite o codigo do Calcado: ");
            scanf(" %d", &codigo);

            calcado_buscado = busca(Arv23, codigo);

            if (calcado_buscado == NULL)
            {
                printf("Calcado nao encontrado\n");
            }
            else
            {
                printf("Digite a nova quantidade em estoque: ");
                scanf(" %d", &quantidade);
                if (quantidade < 0)
                {
                    printf("Nao e possivel definir uma quantidade menor que 0\n");
                }
                else
                {
                    calcado_atualizar_quantidade(calcado_buscado, quantidade);
                    atualizar_arquivo(Arv23);
                }
            }
            calcado_buscado = NULL;
            break;
        case 3:
            mostrar_arv(Arv23);
            break;
        case 4:
            printf("Digite o codigo do Calcado: ");
            scanf(" %d", &codigo);

            calcado_buscado = busca(Arv23, codigo);

            if (calcado_buscado == NULL)
            {
                printf("Calcado nao encontrado\n");
            }
            else
            {
                mostrar_calcado(calcado_buscado);
            }
            calcado_buscado = NULL;
            break;
        case 5:
            /* code */
            break;
        case 6:
            t_ini = clock();
            for (int i = 0; i < 30; i++)
            {
                codigo_buscado = (rand() % 1000);
                printf("------< Codigo: %d >------\n", codigo_buscado);
                if (busca_personalizada(Arv23, 2) == NULL)
                {
                    printf("Codigo não encontrado\n");
                }
                else
                {
                    printf("Codigo encontrado\n");
                }
            }
            t_fim = clock();
            printf("Tempo para buscar os 30 items: %lf", (double)(t_fim - t_ini) / CLOCKS_PER_SEC);
            break;
        default:
            atualizar_arquivo(Arv23);
            Arv23 = liberarArvore(Arv23);
            printf("\nEscolha uma opcao válida\n");
            break;
        }
    } while (opcao != 0);

    // ta funcionando
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
    //     switch (opcao)if (arq == NULL)

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

void inserir_calcado_no_arquivo(int codigo, char *tipo, char *marca, int quantidade, int tamanho, float preco)
{
    FILE *arq;
    arq = fopen("sapatos_store.txt", "ab+");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
    }

    fputs("\n", arq);
    fprintf(arq, "%d %s %s %d %d %.2f", codigo, tipo, marca, tamanho, quantidade, preco);

    fclose(arq);
}

void atualizar_arquivo(Arv23 *Raiz)
{
    FILE *arq;
    arq = fopen("sapatos_store.txt", "w");
    if (arq == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
    }
    salvar_arvore(arq, Raiz);

    fclose(arq);
}

int menu()
{
    int opcao;
    printf("\n\n-------------------MENU-------------------\n");
    printf("1 - Inserir Novo Calçado\n");
    printf("2 - Atualizar a quantidade de um Calcado\n");
    printf("3 - Mostrar todos os calcados\n");
    printf("4 - Mostrar delalhes de um calcados\n");
    printf("5 - Deletar um calcado\n");
    printf("6 - Executar testes de busca\n");
    printf("0 - Sair\n");
    printf("Escolha uma das opções: ");
    scanf(" %d", &opcao);
    return opcao;
}