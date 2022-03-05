typedef struct no No;
typedef struct lista_info Lista_info;
typedef struct participantes Participantes;

No *inicializar();



No *inserir_no(No *raiz, int cod, char titulo[], int qt_temp, Lista_info *lis_inf);
Participantes *inserir_participantes(Participantes *raiz, char nome[], char nome_personagem[], char descricao[]);
Lista_info *inserirLista_info(Lista_info *raiz, int numero, char titulo[], int ano, int qt_ep, Participantes *part);
No* buscar_versao_1(No *raiz, int num);
void mostrar_principal(No *raiz);
void mostrarLista(Lista_info *raiz);
void liberarMemoria(No *raiz);
void liberar_lista(Lista_info *raiz);
void mostrar_participante(Participantes *raiz);
void mostrar_obuscado(No *raiz);
