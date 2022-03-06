#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"arvAvl.h"

int main(){
    No *raiz, *no;
    int valor, qtd, alt, inseriu, x = 0, y = 0, passos = 0;
    double tempos[10][10];

    double t_total;

    clock_t t_ini, t_fim;

    FILE *arq, *arq2;

    arq = fopen("buscasAVL.txt", "w");
    arq2 = fopen("Nro-nos-AVL.txt", "w");

    srand(time(NULL));

    printf("Digite a altura das árvores: ");
    scanf("%d", &alt);
    int valores[] = {33775, 39301, 38750, 87388, 3517, 66382, 55361, 9059, 59792, 43905}, i = 0;
    int count=0;
    int qtdno = 0, alt2=0;

    printf("---------Realizar buscas---------\n");
    for (int j = 0; j < 10; j++){

        raiz = inicializar();

        do{
            valor = (rand()%1050000);
            no = criarNo(valor);
            //mostrarNo(no);
            printf("Quantidade de nós: %d\n", qtdno);
            printf("Altura da arvore (%d): %d\n",j, alt2);
            printf("\n---------------\n");
            inseriu = inserirAvl(&raiz, no);
            //mostrar(raiz);
            alt2 = altura(raiz);
            qtdno++;
            count++;
        }while (alt2 != alt);
        qtdno = 0;
        count = 0;
        //mostrar(raiz);

        y = 0;
        for (i = 0; i < 10; i++) {
            //getchar();
            printf("Realizando busca %d\n", i);

            printf("\nValor a ser buscado: %d\n", valores[i]);
            printf("Caminho percorrido: ");
            
            t_ini = clock();
            buscar(raiz, valores[i], &passos);
            t_fim = clock();
            printf("\n");
            
            t_total = (t_fim - t_ini);
            fprintf(arq, "%d  %lf  %d\n", valores[i], t_total, passos);

            printf("Passos: %d\n", passos);
            passos = 0;

            printf("Tempo de execução: %lf\n", t_total);
            tempos[x][y] = t_total;
            y++;
        }
        x++;
        fprintf(arq2, "QtdElementos árvore %d: %d\n", j, qtdElementos(raiz));
        liberarMemoria(raiz);
    

    }
    printf("Resultados salvos no arquivo 'buscasAVL.txt'!\n");

    fclose(arq);
    fclose(arq2);
    return 0;
}
