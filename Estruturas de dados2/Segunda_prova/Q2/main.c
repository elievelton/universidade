#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arv_RB.h"

// int main(){
//     No* Raiz=NULL;

//     InsereCalcados(&Raiz, 1, "sapato", "Olipikus", 10, 32, 1, 34.8);
//     InsereCalcados(&Raiz, 2, "sapato_tenis", "adidas", 12, 41, 2, 74.8);
//     InsereCalcados(&Raiz, 3, "Sandalia", "Havaianas", 18, 42, 3, 24.8);
//     InsereCalcados(&Raiz, 4, "Sandalia", "Havaianas", 18, 42, 3, 24.8);
//     InsereCalcados(&Raiz, 5, "Sandalia", "Havaianas", 18, 42, 3, 24.8);
//     InsereCalcados(&Raiz, 6, "Sanda lia", "Havaianas", 18, 42, 3, 24.8);

//     imprimir(Raiz);
//     printf("\n");
//     puts("\n================================");
//     remover(&Raiz,2);
//     imprimir(Raiz);

//     return 0;
// }

int menu();
void inserir_calcado_no_arquivo(int codigo, char *tipo, char *marca, int quantidade, int tamanho, float preco);
void atualizar_arquivo(No *Raiz);

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
    No *Raiz = NULL;
    Calcados *calcado_buscado = NULL;

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
            InsereCalcados(&Raiz, codigo, tipo, marca, quantidade, tamanho, linhas, preco);
            linhas++;
        }
        fclose(arq);
    }

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
            InsereCalcados(&Raiz, codigo, tipo, marca, quantidade, tamanho, linhas, preco);
            inserir_calcado_no_arquivo(codigo, tipo, marca, quantidade, tamanho, preco);

            break;
        case 2:
            printf("Digite o codigo do Calcado: ");
            scanf(" %d", &codigo);

            calcado_buscado = buscar_calcados(Raiz, codigo);

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
                    atualizar_arquivo(Raiz);
                }
            }
            calcado_buscado = NULL;
            break;
        case 3:
            imprimir(Raiz);
            break;
        case 4:
            printf("Digite o codigo do Calcado: ");
            scanf(" %d", &codigo);

            calcado_buscado = buscar_calcados(Raiz, codigo);

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
        case 0:
            // atualizar_arquivo(Raiz);
            // Raiz = liberarArvore(Raiz);
            break;
        default:
            printf("\nEscolha uma opcao válida\n");
            break;
        }
    } while (opcao != 0);

    // ta funcionando
    // // printf("%d ",(*Raiz).esq.chaveEsq.cod);
    // // busca(Raiz,2);//ta funcionando
    // excluirElemento(&pai, &Raiz, 2); // ta dando erro de sementação, precisando averiguar
    // printf("----------------------\n");
    // mostrarTudo(Raiz);

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

void atualizar_arquivo(No *Raiz)
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
    printf("0 - Sair\n");
    printf("Escolha uma das opções: ");
    scanf(" %d", &opcao);
    return opcao;
}