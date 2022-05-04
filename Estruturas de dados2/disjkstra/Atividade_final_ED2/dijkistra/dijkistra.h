
typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);

void calcula_Menor_Caminho_noGrato(Grafo *gr, int ini, int *antecessor, float *distancia);
int procurarDistancia(float *dist, int *visitado, int NV);

void imprime_Grafo(Grafo *gr);
