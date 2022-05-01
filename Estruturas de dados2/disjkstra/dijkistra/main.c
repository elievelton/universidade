#include <stdlib.h>
#include <stdio.h>
#include "dijkistra.h"

int main()
{
    int ehDigrafo = 1; // ser digrafo significa que não tem caminho de volta , só de ida
    Grafo *gr;
    gr = criaGrafo(5, 0);
    int visitados[5]; // mesmo tamanho dos vertices criados
    insereAresta(gr, 0, 1, ehDigrafo, 0);
    insereAresta(gr, 1, 3, ehDigrafo, 0);
    insereAresta(gr, 1, 2, ehDigrafo, 0);
    insereAresta(gr, 2, 4, ehDigrafo, 0);
    insereAresta(gr, 3, 0, ehDigrafo, 0);
    insereAresta(gr, 3, 4, ehDigrafo, 0);
    insereAresta(gr, 4, 1, ehDigrafo, 0);
    puts("Mostrando o Grafo");
    mostraGrafo(gr);
    puts("Busca em profundidade");
    busca_em_profundidade_grafo(gr, 0, visitados);
    puts("Busca em largura");
    busca_em_largura_grafo(gr, 0, visitados);


    liberaGrafo(gr);
    return 0;