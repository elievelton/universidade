#include <stdio.h>
#include <stdlib.h>
#include "busca_larg_prof_grafos.h"

struct grafos
{
    int ehPonderado; // se ele é podenrado ele será atribuído peso, se não , não terá pesos
    int nVertices;   // tenho que definir antes de criar o grafo o numero de vertices
    int **arestas;   // guarda as conexões que é uma matriz
    float **pesos;   // usado apenas em graficos ponderados
    int *grau;       // numeros de arestas que chegam ou partem dele
};
// funcao de criar o grafo
Grafo *criaGrafo(int Vertices, int ehPonderado)
{
    Grafo *g;
    g = (Grafo *)malloc(sizeof(struct grafos));
    if (g != NULL)
    {
        g->nVertices = Vertices;
        g->ehPonderado = (ehPonderado != 0) ? 1 : 0;    // comando ternário equivalente ao if e else
        g->grau = (int *)calloc(Vertices, sizeof(int)); // inserindo zero para marca todos inicialemnte como não visitados, sem aresta
        g->arestas = (int **)malloc(Vertices * sizeof(int *));

        for (int i = 0; i < Vertices; i++) // Matriz de arestas
        {
            g->arestas[i] = (int *)malloc(Vertices * sizeof(int));
        }
        if (g->ehPonderado) // Matriz de pesos 
        {
            g->pesos = (float **)malloc(Vertices * sizeof(float *));
            for (int i = 0; i < Vertices; i++)
            {
                g->pesos[i] = (float *)malloc(Vertices * sizeof(float));
            }
        }
    }
    return g;
}
// função para liberar o grafo
void liberaGrafo(Grafo *g)
{
    if (g != NULL)
    {
        int i;
        for (int i = 0; i < g->nVertices; i++)
            free(g->arestas[i]);
        free(g->arestas);
        if (g->ehPonderado)
        {
            for (int i = 0; i < g->nVertices; i++)
                free(g->pesos[i]);
            free(g->pesos);
        }
        free(g->grau);
        free(g);
    }
}
// função para inserir aresta
int insereAresta(Grafo *g, int origem, int destino, int digrafo, float peso)
{
    int criou = 0;
    if (g != NULL)
    {
        if (origem >= 0 && origem < g->nVertices)
        {
            if (destino >= 0 && destino < g->nVertices)
            {
                g->arestas[origem][g->grau[origem]] = destino;
                if (g->ehPonderado)
                    g->pesos[origem][g->grau[origem]] = peso;
                (g->grau[origem])++;
                if (digrafo == 0)
                    insereAresta(g, destino, origem, 1, peso);
                criou = 1;
            }
        }
    }
    return criou;
}

/*
Partindo de um vertice inicial, ela consegu explorar todos os vertices vizinhos.
Em seguida, para cada vertice vizinho ela repete esse processo, visitando os vertices inesplorados.
Pode ser usado para :
    achar todos vertices conectados a um componente

*/

void busca_em_largura_grafo(Grafo *g, int ini, int *visitado)
{
    int i, vert, Novo_Vertice, cont = 1;
    int *fila, Inicial_fila = 0, Final_fila = 0;
    for (i = 0; i < g->nVertices; i++) // preenchendo todos os vertices como não visitados
        visitado[i] = 0;

    //criando fila e inserindo ini na fila
    Novo_Vertice = g->nVertices;
    fila = (int *)malloc(Novo_Vertice * sizeof(int)); 
    Final_fila++;
    fila[Final_fila] = ini;
    visitado[ini] = cont;
    // while pega o primeiro da fila
    while (Inicial_fila != Final_fila) // A fila está vazia?
    {
        // Recuperando o vertice que ta no inicio da fila        
        Inicial_fila = (Inicial_fila + 1) % Novo_Vertice;
        vert = fila[Inicial_fila];
        cont++;

        // visita visinhos ainda não visitados e coloca na fila
        for (i = 0; i < g->grau[vert]; i++)
        {
            if (!visitado[g->arestas[vert][i]])// Ele já foi visitado ?
            {
                //colocando todos os vertices não visitados dentro da fila
                Final_fila = (Final_fila + 1) % Novo_Vertice;
                fila[Final_fila] = g->arestas[vert][i];
                visitado[g->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
    //mostrando o grafo 
    for (i = 0; i < g->nVertices; i++)
        printf("%d -> %d\n", i, visitado[i]);
}

/*
    Partindo de um vertice inicial, ela explora o máximo possível os seus ramos antes de retroceder.
    Em seguida, para cada vertice vizinho ela repete esse processo, visitando os vertices inesplorados.
    Pode ser usado para :
        encontrar componentes conecatos em um labirinto, onde alguns vertices podem ser vistos
        apenas de determinados vertices.
*/
// Função principal de busca em profundidade

void busca_em_profundidade_grafo(Grafo *g, int ini, int *visitado)
{
    int i, cont = 1;
    for (size_t i = 0; i < g->nVertices; i++)
        visitado[i] = 0; // para marca todos como não visitados inicialmente

    func_aux_busca_profundidade(g, ini, visitado, cont);

    for (i = 0; i < g->nVertices; i++)
        printf("%d -> %d\n", i, visitado[i]);
}

// função auxiliar da busca em profundidade
void func_aux_busca_profundidade(Grafo *g, int ini, int *visitado, int cont)
{
    int i;
    visitado[ini] = cont;

    for (size_t i = 0; i < g->grau[ini]; i++)
    {
        if (!visitado[g->arestas[ini][i]]) // O vertice já foi visitado?
        {
            func_aux_busca_profundidade(g, g->arestas[ini][i], visitado, cont + 1); // chamada recursiva para verificar o próximo vertice
        }
    };
}
// função para mostrar o grafo
void mostraGrafo(Grafo *g)
{
    printf("origem \t\t destino \n");
    for (int i = 0; i < g->nVertices; i++)
        for (int d = 0; d < g->grau[i]; d++)
            if (g->arestas[i][d] != 0)
                printf("%d \t\t %d \n", i, g->arestas[i][d]);
}
