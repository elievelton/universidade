#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

int main()
{
    int profu_maior, profu_menor, diferenca, busca[] = {56, 90, 568, 5902, 10023, 467, 50000, 80458, 1234};
    double tempo_in[30], busca_tempo[30];
    clock_t t_ini, t_fim;
    No *no;
    srand(time(NULL));
    FILE *arq, *arq2;
    arq = fopen("tempo_de_busca.txt", "w");
    arq2 = fopen("tempo_de_insercao.txt", "w");

    int *vet_dif = (int *)calloc(1001, sizeof(int));
    for (size_t i = 0; i < 30; i++)
    {
        no = inicializar();
        t_ini = clock();
        for (size_t j = 0; j < 1000; j++)
        {
            no = inserir_no(no, (rand() % 505000));
        }
        t_fim = clock();
        tempo_in[i] = (double)(t_fim - t_ini) / CLOCKS_PER_SEC;
        fprintf(arq2, "  %lf  \n", tempo_in[i]);

        t_ini = clock();
        for (size_t j = 0; j < 9; j++)
        {

            buscar_versao_1(no, busca[j]);
        }
        t_fim = clock();
        busca_tempo[i] = (double)(t_fim - t_ini) / CLOCKS_PER_SEC;
        fprintf(arq, "  %lf  \n", busca_tempo[i]);
        profu_maior = profu(no);
        profu_menor = prof_menor(no);
        printf("Maior :%d Menor :%d\n", profu_maior, profu_menor);
        diferenca = profu_maior - profu_menor;
        vet_dif[diferenca] += 1;
        liberarMemoria(no);
    }
    for (size_t i = 0; i < 1001; i++)
    {
        if (vet_dif[i] != 0)
        {
            printf("A difereça %d ocorreu %d vezes\n", i, vet_dif[i]);
        }
    }
    for (size_t i = 0; i < 30; i++)
    {

        printf("Inserção %d demorou :%lf segundos\n", i + 1, tempo_in[i]);
    }
    for (size_t i = 0; i < 30; i++)
    {

        printf("Busca %d demorou :%lf segundos\n", i + 1, busca_tempo[i]);
    }
    printf("Resultados salvos no arquivo 'tempo_de_busca.txt'!\n");
    printf("Resultados salvos no arquivo 'tempo_de_insercao.txt'!\n");
    printf("\n");
    fclose(arq);
    fclose(arq2);

    return 0;
}