#include <stdio.h>
typedef struct grafos Grafo;
Grafo *criaGrafo(int Vertices, int ehPonderado);
void liberaGrafo(Grafo *gr);
int insereAresta(Grafo *gr, int origem, int destino, int digrafo, float peso);
void busca_em_largura_grafo(Grafo *gr, int ini, int *visitado);
void busca_em_profundidade_grafo(Grafo *gr, int ini, int *visitado);
void func_aux_busca_profundidade(Grafo *gr, int ini, int *visitado, int cont);
int procuraMenorDistancia(float *dist, int *visitado, int NV);
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist);
void mostraGrafo(Grafo *gr);