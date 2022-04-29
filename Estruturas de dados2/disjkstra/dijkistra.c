#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <locale.h>
#include <limits.h>
#define vertice int

// Estrutura do grafo, Ver � a quantidade de vertices, verX e verY s�o as coordenadas de cada vertice, Ar � a quantidade de arestas e adjacencia
// é a matriz de adjacencia que representa as liga��es entre os vertices.

struct grafo{

    int Ver;
    int *VerX;
    int *VerY;
    int Ar;
    int **adjacencia;

};

// Definindo o tipo Grafo.

typedef struct grafo *Grafo;

// Alocação de matriz, as variaveis r e c determinam a quantidade de linhas e colunas enquanto a val é o valor de cada posi��o.

static int **Matriz(int r, int c, int val){

    int **matriz = malloc(r * sizeof(int *));

    for(vertice i = 0; i < r; ++i){
        matriz[i] = malloc(c * sizeof(int));
    }
    for(vertice i = 0; i < r; ++i){
        for(vertice j = 0; j < r; ++j)
            matriz[i][j] = val;
    }
    return matriz;
}

// Inicialização de um grafo com 0 arrestas e v para quantidade de vertices.

Grafo constroiGrafo(int v){

    Grafo G = malloc(sizeof *G);
    G->Ver = v;
    G->VerX = malloc(v*sizeof(int *));
    G->VerY = malloc(v*sizeof(int *));
    G->Ar = 0;
    G->adjacencia = Matriz(v,v,0);

    return G;

}

// Preenche as coordenadas do vertice com numeros aleatorios.

void preencheCoordenada(Grafo g){

    for(vertice v = 0; v < g->Ver; ++v){
        g->VerX[v] = rand() % 100;
        g->VerY[v] = rand() % 100;
    }

    for(vertice v = 0; v < g->Ver; ++v){
        printf("Coordenadas do vertice %d, x = %d, y = %d\n", v, g->VerX[v], g->VerY[v]);
    }

}

// Exibir a matriz de adjacencia por completo.

void exibeMatriz(Grafo g){
    for(vertice v = 0; v < g->Ver; ++v){
        for(vertice w = 0; w < g->Ver; ++w)
            printf("%d  ", g->adjacencia[v][w]);
        printf("\n");
    }
    printf("\n");
}

// Insere uma aresta com peso passado por parametro entre os vertices v-w no grafo caso essa aresta nao exista.

void insereAresta(Grafo g, vertice v, vertice w, int peso){

    if(g->adjacencia[v][w] == 0){
        g->adjacencia[v][w] = peso;
        g->adjacencia[w][v] = peso;
        g->Ar++;
    }
}

// remove uma aresta vw no grafo caso exista.

void removeAresta(Grafo g, vertice v, vertice w){
    if(g->adjacencia[v][w] != 0){
        g->adjacencia[v][w] = 0;
        g->Ar--;
    }
}

// imprime a adjacencia de cada vertice por linha.

void imprimeAjacenteLinha(Grafo g){

    for(vertice v = 0; v < g->Ver; ++v){
        printf("\nAdjacentes de %2d: ", v);
        for(vertice w = 0; w < g->Ver; ++w){
            if(g->adjacencia[v][w] != 0){
                printf("%2d, ", w);
            }
        }
    }
    printf("\n");
}

// imprime a adjacencia de cada vertice por coluna.

void imprimeAjacenteColuna(Grafo g){

    for(vertice w = 0; w < g->Ver; ++w){
        printf("\n%2d: ", w);
        for(vertice v = 0; v < g->Ver; ++v){
            if(g->adjacencia[v][w] != 0){
                printf("%2d", v);
            }
        }
    }
    printf("\n");
}

// Verifica se um vertice v é adjacente a um vertice w.

void isAdjacente(Grafo g, vertice v, vertice w){

    bool s = false;

    if(g->adjacencia[v][w] != 0)
        s = true;
    else if(g->adjacencia[w][v] != 0)
        s = true;

    if(s)
        printf("O vertice %d eh adjacente ao vertice %d com o peso da aresta de: %d\n", v, w, g->adjacencia[v][w]);
    else
        printf("Os vertices informados nao sao adjacentes\n");
}

// Edita as coordenadas do vertice v, recebendo as novas coordenadas x e y por parametro.

void editaCoordenada(Grafo g, vertice v, int x, int y){

    g->VerX[v] = x;
    g->VerY[v] = y;

}

// Mostra as coordenadas de todos os vertices do grafo passado por parametro

void mostraCoordenada(Grafo g){

    for(vertice w = 0; w < g->Ver; ++w){
        printf("Coordenadas do vertice %d, x = %d, y = %d\n", w, g->VerX[w], g->VerY[w]);
    }
}

// Verifica o proximo vertice adjacente de um vertice ver.

void primAdjacente(Grafo g, vertice ver){

        for(vertice w = 0; w < g->Ver; ++w){
            if(g->adjacencia[ver][w] != 0){
                printf("Primeiro adjacente de %d sera: %2d, peso: %d\n", ver, w, g->adjacencia[ver][w]);
                break;
            }
    }
}

// Verifica o proximo vertice adjacente de um vertice x adjacente a um vertice y.

void proxAdjacenteInformado(Grafo g, vertice x, vertice y){

    for(vertice w = y+1; w < g->Ver; ++w){
            if(g->adjacencia[x][w] != 0){
                printf("Proximo adjacente de %d sera: %2d, peso: %d\n", x, w, g->adjacencia[x][w]);
                break;
            }
    }

}

// Importa o grafo de um arquivo de texto.

Grafo importarGrafo(char *path){

    FILE *file;

    file = fopen(path, "r");
    int i;
    int qntVertices = 0;
    int qntArestas = 0;

    fscanf(file, "%d\n", &qntVertices);
    Grafo g = constroiGrafo(qntVertices);

    for(i = 0; i < qntVertices; i++){

        int ver = 0, verX = 0, verY = 0;
        fscanf(file, "%d %d %d\n", &ver, &verX, &verY);
        editaCoordenada(g, ver, verX, verY);
    }

    fscanf(file, "%d\n", &qntArestas);

    for(i = 0; i < qntArestas; i++){

        int v = 0, w = 0, peso = 0;
        fscanf(file, "%d %d %d\n", &v, &w, &peso);
        insereAresta(g, v, w, peso);
    }

    return g;
}

// Exporta o grafo para um arquivo de texto.

void exportarGrafo(Grafo g, char *path){


    FILE *file;

    file = fopen(path, "w");
    int i, j;
    int qntVertices = g->Ver;
    int qntArestas = g->Ar;

    fprintf(file, "%d\n", qntVertices);

    for(i = 0; i < qntVertices; i++){

        fprintf(file, "%d %d %d\n", i, g->VerX[i], g->VerY[i]);
    }

    fprintf(file, "%d\n", qntArestas);

    for(i = 0; i < qntVertices; i++){
        for( j = 0; j < qntVertices; j++){
            if(g->adjacencia[i][j] != 0)
                fprintf(file, "%d %d %d\n", i, j, g->adjacencia[i][j]);
        }
    }
}


int procuraMenorDistancia(float *dist, int *visitado, int nv){

    int i, menor = INT_MAX, primeiro = 1;

    for(i = 0; i < nv; i++){

        if(dist[i] < menor && visitado[i] == 0){
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

void menorCaminho(Grafo g, int ini, int *ant, float *dist, int v2){

    int i, cont = 0, NaoVisitado = 0, ind = 0, *visitado, vertice_processado = 0;

    cont = g->Ver;
    NaoVisitado = g->Ver;

    visitado = (int*) malloc(NaoVisitado * sizeof(int));

    for(i = 0; i < NaoVisitado; i++){

        ant[i] = -1;
        dist[i] = INT_MAX;
        visitado[i] = 0;
    }

    dist[ini] = 0;

    while(cont > 0){

        vertice_processado = procuraMenorDistancia(dist, visitado, NaoVisitado);

        visitado[vertice_processado] = 1;

        cont--;

        int vizinho;

        for(vizinho = 0; vizinho < g->Ver; vizinho++){

            if(g->adjacencia[vertice_processado][vizinho] > 0){

                ind = g->adjacencia[vertice_processado][vizinho] + dist[vertice_processado];

                if(ind < dist[vizinho]){

                    ant[vizinho] = vertice_processado;
                    dist[vizinho] = ind;
                }
                ind = 0;
            }
        }
    }

    printf("\n\n Distância de %d até %d é = %.0f \n", ini, v2, dist[v2]);

    free(visitado);

}

 // Função principal, onde fica o menu e as chamadas das funções que componhem o editor de grafo

int main(){

    setlocale(LC_ALL, "portuguese");

    int condicao = 0, escolha = 0;
    bool grafoCriado = false;
    Grafo g1;


    while(condicao == 0){

        system("cls");

        printf("    --- Editor de Grafos ---    \n");
        printf(" --- 1. Importar um grafo de um arquivo de texto --- \n");
        printf(" --- 2. Criar um grafo vazio a partir de um numero de vertices informado pelo usuario --- \n");
        printf(" --- 3. Exibir a matriz de adjacencias --- \n");
        printf(" --- 4. Consultar se um v�rtice � adjacente a outro --- \n");
        printf(" --- 5. Inserir novas arestas --- \n");
        printf(" --- 6. Remover arestas --- \n");
        printf(" --- 7. Editar a coodernada dos v�rtices --- \n");
        printf(" --- 8. Consultar o primeiro adjacente de um v�rtice --- \n");
        printf(" --- 9. Consultar o pr�ximo adjacente de um v�rtice a partir de um adjacente informado --- \n");
        printf(" --- 10. Consultar a lista completa de adjacentes --- \n");
        printf(" --- 11. Exportar grafo para um arquivo de texto --- \n");
        printf(" --- 12. Procurar menor caminho a partir de um vertice --- \n");
        printf(" --- 13. Sair --- \n");
        printf(" ---==: ");
        scanf("%d", &escolha);

        if(escolha == 1){

            char path[50];
            system("cls");
            printf("Nome do arquivo (exemplo.txt) : ");
            scanf("%s", path);
            g1 = importarGrafo(path);
            system("pause");
            grafoCriado = true;

        }
        else if(escolha == 2){

            vertice v = 0;
            system("cls");
            printf("N�mero de v�rtices : ");
            scanf("%d", &v);
            g1 = constroiGrafo(v);
            system("pause");
            preencheCoordenada(g1); // Gerando coordenadas aleatorias para o vertice, eles podem ser alterados com a funcao editaCoordenada
            grafoCriado = true;

        }
        else if(escolha == 3){

            system("cls");
            if(grafoCriado){
                exibeMatriz(g1);
                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }

        }
        else if(escolha == 4){


            if(grafoCriado){
                int v=0, w=0;
                system("cls");
                printf("Vertice 1 = ");
                scanf("%d", &v);
                printf("Vertice 2 = ");
                scanf("%d", &w);
                isAdjacente(g1, v, w);
                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }

        }
        else if(escolha == 5){
            system("cls");
            if(grafoCriado){
                int a = 0, b = 0, peso;
                printf("Vertice 1 : ");
                scanf("%d", &a);
                printf("Vertice 2 : ");
                scanf("%d", &b);
                printf("Peso : ");
                scanf("%d", &peso);

                insereAresta(g1, a, b, peso);

                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }
        }
        else if(escolha == 6){

            system("cls");
            if(grafoCriado){
                int a = 0, b = 0;
                printf("Vertice 1 : ");
                scanf("%d", &a);
                printf("Vertice 2 : ");
                scanf("%d", &b);

                removeAresta(g1, a, b);

                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }
        }
        else if(escolha == 7){
            system("cls");
            if(grafoCriado){

                int x = 0, y = 0, ver = 0;

                printf("Vertice : ");
                scanf("%d", &ver);
                printf("Coordenada X : ");
                scanf("%d", &x);
                printf("Coordebada Y : ");
                scanf("%d", &y);

                editaCoordenada(g1, ver, x, y);
                mostraCoordenada(g1);

                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }
        }
        else if(escolha == 8){
            system("cls");
            if(grafoCriado){
                int v = 0;
                printf("Vertice : ");
                scanf("%d", &v);
                primAdjacente(g1, v);

                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }
        }
        else if(escolha == 9){
            system("cls");
            if(grafoCriado){
                int v = 0, w = 0;
                printf("Vertice : ");
                scanf("%d", &v);
                printf("Adjacente : ");
                scanf("%d", &w);
                proxAdjacenteInformado(g1, v, w);

                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }

        }
        else if(escolha == 10){
            system("cls");
            if(grafoCriado){
                imprimeAjacenteLinha(g1);
                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }
        }
        else if(escolha == 11){
            system("cls");
            if(grafoCriado){
                char nome[50];
                printf("Nome do arquivo (exemplo.txt) : ");
                scanf("%s", nome);
                exportarGrafo(g1, nome);
                system("pause");
            }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }
        }
        else if(escolha == 12){

                system("cls");
                if(grafoCriado){
                    int ver = 0, ver2 = 0;
                    printf("Escolha o vertice de origem: ");
                    scanf("%d", &ver);
                    printf("Escolha o vertice final: ");
                    scanf("%d", &ver2);

                    int ant[g1->ver];
                    float dist[g1->Ver];


                    menorCaminho(g1, ver, ant, dist, ver2);
                    int i;


                    for(i = 0; i < 5; i++){

                        printf("v�rtice = %d // antecessor = %d / distancia = %.0f \n",i ,ant[i], dist[i]);

                    }
                    system("pause");
                }else{
                printf("Grafo nao iniciado\n");
                system("pause");
            }

        }
        else if(escolha == 13){
            condicao++;
        }
        else {
            system("cls");
            printf("Escolha incorreta\n");
            system("pause");
        }

    }
}