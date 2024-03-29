#include <stdlib.h>
#include <stdio.h>
#include "dijkistra.h"

int main()
{
    int ehDigrafo = 1; // ser digrafo significa que não tem caminho de volta , só de ida
    Grafo* gr = cria_Grafo(10, 10, 1);
    int anterior[10]; // mostra quem é o anterior do peso de um vertice
    float distancia[10]; // grava o peso das distancias

    /*
    Substituimos letras por numeros, ficaram da seguinte maneira
    A = 0
    B = 1
    C = 2
    D = 3
    E = 4
    F = 5
    G = 6
    H = 7
    I = 8
    J = 9
*/
//Inserindo conforme o exemplo passado para este trabalho
    insereAresta(gr, 0, 1, ehDigrafo, 60);
    insereAresta(gr, 0, 2, ehDigrafo, 54);
    insereAresta(gr, 0, 3, ehDigrafo, 42);
    insereAresta(gr, 1, 5, ehDigrafo, 29);
    insereAresta(gr, 1, 3, ehDigrafo, 71);
    insereAresta(gr, 2, 3, ehDigrafo, 56);
    insereAresta(gr, 2, 4, ehDigrafo, 67);
    insereAresta(gr, 3, 5, ehDigrafo, 52);
    insereAresta(gr, 3, 4, ehDigrafo, 26);
    insereAresta(gr, 3, 6, ehDigrafo, 87);
    insereAresta(gr, 5, 7, ehDigrafo, 25);
    insereAresta(gr, 5, 6, ehDigrafo, 20);
    insereAresta(gr, 4, 6, ehDigrafo, 70);
    insereAresta(gr, 4, 8, ehDigrafo, 73);
    insereAresta(gr, 6, 7, ehDigrafo, 36);
    insereAresta(gr, 6, 8, ehDigrafo, 59);
    insereAresta(gr, 6, 9, ehDigrafo, 32);
    insereAresta(gr, 7, 9, ehDigrafo, 25);
    insereAresta(gr, 8, 9, ehDigrafo, 26);

    imprime_Grafo(gr);
    printf("\nBusca menor caminho \n");

    calcula_Menor_Caminho_noGrato(gr, 0, anterior, distancia);
    printf("ID  ant  peso\n");
    for(int i=0; i<10; i++)
        if(i!=0) //apenas para não mostrar o anterio a primeira verificação
            printf("%d: %d -> %.2f\n",i,anterior[i],distancia[i]);

    libera_Grafo(gr);
    return 0;
}