#include <stdio.h>
typedef struct grafos Grafo;
Grafo *criaGrafo(int Vertices, int ehPonderado);
void liberaGrafo(Grafo *g);
int insereAresta(Grafo *g, int origem, int destino, int digrafo, float peso);
void busca_em_largura_grafo(Grafo *g, int ini, int *visitado);
void busca_em_profundidade_grafo(Grafo *g, int ini, int *visitado);
void func_aux_busca_profundidade(Grafo *g, int ini, int *visitado, int cont);
void mostraGrafo(Grafo *g);