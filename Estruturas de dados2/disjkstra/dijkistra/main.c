#include <stdlib.h>
#include <stdio.h>
#include "dijkistra.h"

int main()
{
    int ehDigrafo = 1; // ser digrafo significa que não tem caminho de volta , só de ida
    Grafo *gr;
    gr = criaGrafo(10, 0);
    int ant[10]; // mostra quem é o anterior de um vertice
    float dist[10]; // grava a distanvia do vertice inicial para os proximos vertices
    /*
    Substituimos letras por numeros, ficaram da seguinte maneira
    A = 1
    B = 2
    C = 3
    D = 4
    E = 5
    F = 6
    G = 7
    H = 8
    I = 9
    J = 10
*/
    insereAresta(gr, 1, 2, ehDigrafo, 60);
    insereAresta(gr, 1, 3, ehDigrafo, 54);
    insereAresta(gr, 1, 4, ehDigrafo, 42);
    insereAresta(gr, 2, 6, ehDigrafo, 29);
    insereAresta(gr, 2, 4, ehDigrafo, 71);
    insereAresta(gr, 3, 4, ehDigrafo, 56);
    insereAresta(gr, 3, 5, ehDigrafo, 67);
    insereAresta(gr, 4, 6, ehDigrafo, 52);
    insereAresta(gr, 4, 5, ehDigrafo, 26);
    insereAresta(gr, 4, 7, ehDigrafo, 87);
    insereAresta(gr, 6, 8, ehDigrafo, 25);
    insereAresta(gr, 6, 7, ehDigrafo, 20);
    insereAresta(gr, 5, 7, ehDigrafo, 70);
    insereAresta(gr, 5, 9, ehDigrafo, 73);
    insereAresta(gr, 7, 8, ehDigrafo, 36);
    insereAresta(gr, 7, 9, ehDigrafo, 59);
    insereAresta(gr, 7, 10, ehDigrafo, 32);
    insereAresta(gr, 8, 10, ehDigrafo, 25);
    insereAresta(gr, 9, 10, ehDigrafo, 26);
    puts("Mostrando o Grafo");
    mostraGrafo(gr);
    puts("Busca em profundidade");
    menorCaminho_Grafo(gr,0,ant,dist);


    liberaGrafo(gr);
    return 0;