#include <stdio.h>
#include <stdlib.h>
#include "dijkistra.h" //inclui os Protótipos

    /* O objetivo desse algoritomo e calcular a menor distancia entre diversas rotas
        Conhecido tambem como dijkstra essa solução visa simplicar diversos trabalhos
        que se ultilizam dos grafos
     */

//Definições do tipo Grafo
struct grafo{
    int eh_ponderado; // um gradfo é podenrado quando suas arestas possuem peso
    int nro_vertices;// numero de vertices
    int grau_max; //o maior tamnho do grafo
    int** arestas; //As arestas são consideradas as uniões entre os vértices
    float** pesos;// pesos das rotas
    int* grau; //grau de um vértice de um grafo é o número de arestas incidentes para com o vértice
};

// função para cirar o Grafo, recebe numero de vertices, Grau Máximo e se ele é ponderado ou não
Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0; // operador ternario so para garantir se é ponderado ou não
        gr->grau = (int*) calloc(nro_vertices,sizeof(int)); // o vetor está sendo setado tudo com zero que idica que ninguem passou por ele

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}
// Funão para libera_Grafo
void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}
// Função para inserir arestas: recebe o grafo, ponto de origem, destino se é digrafo e o peso
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}


//função para imprimir o grafo com seus respectivos pesos
void imprime_Grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    puts("Imprimindo as rotas com seus pesos...");
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

// função retorna um menor caminho em pontos nao visitados
int procurarDistancia(float *dist, int *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    for(i=0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}
// Busca o menor caminho: recebe o grafo, o inicial, o anterior e uma lista para armazenar os pesos
void calcula_Menor_Caminho_noGrato(Grafo *gr, int ini, int *ant, float *dist){
    int i, cont, NV, ind, *visitado, temp_vertice;
    cont = NV = gr->nro_vertices;
    visitado = (int*) malloc(NV * sizeof(int));
    for(i=0; i < NV; i++){
        ant[i] = -1; // usando para mostrar que o anterior não foi visitado
        dist[i] = -1; // seta -1 par aindicar que não temos pesos adicionados
        visitado[i] = 0; // quando for visitado ele sera setado 1
    }
    dist[ini] = 0;
    while(cont > 0){
        temp_vertice = procurarDistancia(dist, visitado, NV);
        if(temp_vertice == -1)// se receber -1 ele sai fora do while
            break;

        visitado[temp_vertice] = 1;
        cont--;
        for(i=0; i<gr->grau[temp_vertice]; i++){
            ind = gr->arestas[temp_vertice][i];
            if(dist[ind] < 0){
               dist[ind] = dist[temp_vertice] + gr->pesos[temp_vertice][i];//fazendo a soma dos pesos
               ant[ind] = temp_vertice;
            }else{
                
                    /* Se o calculo não houver pesos basta troca 
                        + gr->pesos[temp_vertice][i] da linha 137, 145 e 146 por +1                    
                     */                
                
                if(dist[ind] > dist[temp_vertice] + gr->pesos[temp_vertice][i]){
                    dist[ind] = dist[temp_vertice] + gr->pesos[temp_vertice][i];//fazendo a soma dos pesos
                    ant[ind] = temp_vertice;
                }
            }
        }
    }

    free(visitado);
}