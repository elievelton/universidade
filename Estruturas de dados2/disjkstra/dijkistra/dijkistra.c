#include <stdio.h>
#include <stdlib.h>
#include "dijkistra.h"

struct grafos
{
    int ehPonderado; // se ele é podenrado ele será atribuído peso, se não , não terá pesos
    int nVertices;   // tenho que definir antes de criar o grafo o numero de vertices
    int **arestas;   // guarda as conexões que é uma matriz
    float **pesos;   // usado apenas em graficos ponderados
    int *grau;       // numeros de arestas que chegam ou partem dele
};

Grafo *criaGrafo(int Vertices, int ehPonderado)
{
    Grafo *gr;
    gr = (Grafo *)malloc(sizeof(struct grafos));
    if (gr != NULL)
    {
        gr->nVertices = Vertices;
        gr->ehPonderado = (ehPonderado != 0) ? 1 : 0;    // comando ternario equivalente ao if e else
        gr->grau = (int *)calloc(Vertices, sizeof(int)); // inserindo zero para marca todos inicialemnte como não visitados, sem aresta
        gr->arestas = (int **)malloc(Vertices * sizeof(int *));

        for (int i = 0; i < Vertices; i++) // Matriz de arestas
        {
            gr->arestas[i] = (int *)malloc(Vertices * sizeof(int));
        }
        if (gr->ehPonderado) // Matriz de pesos
        {
            gr->pesos = (float **)malloc(Vertices * sizeof(float *));
            for (int i = 0; i < Vertices; i++)
            {
                gr->pesos[i] = (float *)malloc(Vertices * sizeof(float));
            }
        }
    }
    return gr;
}
void liberaGrafo(Grafo *gr)
{
    if (gr != NULL)
    {
        int i;
        for (int i = 0; i < gr->nVertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);
        if (gr->ehPonderado)
        {
            for (int i = 0; i < gr->nVertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}
int insereAresta(Grafo *gr, int origem, int destino, int digrafo, float peso)
{
    int criou = 0;
    if (gr != NULL)
    {
        if (origem >= 0 && origem < gr->nVertices)
        {
            if (destino >= 0 && destino < gr->nVertices)
            {
                gr->arestas[origem][gr->grau[origem]] = destino;
                if (gr->ehPonderado)
                    gr->pesos[origem][gr->grau[origem]] = peso;
                (gr->grau[origem])++;
                if (digrafo == 0)
                    insereAresta(gr, destino, origem, 1, peso);
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

void busca_em_largura_grafo(Grafo *gr, int ini, int *visitado)
{
    int i, vert, Novo_Vertice, cont = 1;
    int *fila, Inicial_fila = 0, Final_fila = 0;
    for (i = 0; i < gr->nVertices; i++) // preenchendo todos os vertices como não visitados
        visitado[i] = 0;

    // criando fila e inserindo ini na fila
    Novo_Vertice = gr->nVertices;
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
        for (i = 0; i < gr->grau[vert]; i++)
        {
            if (!visitado[gr->arestas[vert][i]]) // Ele já foi visitado ?
            {
                // colocando todos os vertices não visitados dentro da fila
                Final_fila = (Final_fila + 1) % Novo_Vertice;
                fila[Final_fila] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free(fila);
    // mostrando o grafo
    for (i = 0; i < gr->nVertices; i++)
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

void busca_em_profundidade_grafo(Grafo *gr, int ini, int *visitado)
{
    int i, cont = 1;
    for (size_t i = 0; i < gr->nVertices; i++)
        visitado[i] = 0; // para marca todos como não visitados inicialmente

    func_aux_busca_profundidade(gr, ini, visitado, cont);

    for (i = 0; i < gr->nVertices; i++)
        printf("%d -> %d\n", i, visitado[i]);
}

// função auxiliar da busca em profundidade
void func_aux_busca_profundidade(Grafo *gr, int ini, int *visitado, int cont)
{
    int i;
    visitado[ini] = cont;

    for (size_t i = 0; i < gr->grau[ini]; i++)
    {
        if (!visitado[gr->arestas[ini][i]]) // ele ja foi visitado?
        {
            func_aux_busca_profundidade(gr, gr->arestas[ini][i], visitado, cont + 1); // chamada recursiva para verificar o próximo vertice
        }
    };
}

// Função auxiliar da funão dijkistra
int procuraMenorDistancia(float *dist, int *visitado, int NV)
{
    int i, menor = -1, primeiro = 1;
    for (i = 0; i < NV; i++)
    {
        if (dist[i] >= 0 && visitado[i] == 0)
        {
            if (primeiro)
            {
                menor = i;
                primeiro = 0;
            }
            else
            {
                if (dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}
//Função Dijkistra para procurar o menor caminho
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist)
{
    int i, cont, NV, ind, *visitado, vert;
    cont = NV = gr->nVertices;
    visitado = (int *)malloc(NV * sizeof(int));
    for (i = 0; i < NV; i++)
    {
        ant[i] = -1; // -1 siginifica que ninguém tem anterior
        dist[i] = -1; // -1 siginifica que ninguém tem distancia
        visitado[i] = 0;
    }
    dist[ini] = 0;
    while (cont > 0)
    {
        vert = procuraMenorDistancia(dist, visitado, NV);
       
        if (vert == -1)
            break;

        visitado[vert] = 1;
        cont--;
        for (i = 0; i < gr->grau[vert]; i++)
        {
            ind = gr->arestas[vert][i];
            if (dist[ind] < 0)
            {
                dist[ind] = dist[vert] + gr->pesos[vert][i]; // se não tiver peso -> dist[ind] = dist[vert] + 1;
                ant[ind] = vert;
            }
            else
            {
                if (dist[ind] = dist[vert] + gr->pesos[vert][i])// se não tiver peso -> dist[ind] = dist[vert] + 1;
                {
                    dist[ind] = dist[vert] + gr->pesos[vert][i]; // se não tiver peso -> dist[ind] = dist[vert] + 1;
                    ant[ind] = vert;
                }
            }
        }
    }
    for (i = 0; i < gr->nVertices; i++)
        printf("%d -> %d\n", i, visitado[i]);
    free(visitado);
}

void mostraGrafo(Grafo *gr)
{
    printf("origem \t\t destino \n");
    for (int i = 0; i < gr->nVertices; i++)
        for (int d = 0; d < gr->grau[i]; d++)
            if (gr->arestas[i][d] != 0)
                printf("%d \t\t %d \n", i, gr->arestas[i][d]);
}
