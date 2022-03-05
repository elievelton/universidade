typedef struct no No;
typedef struct lista_info Lista_info;
typedef struct participantes Participantes;

No *inicializar();
Lista_info *inicializar_lista();
Participantes *inicializar_participantes();


No *inserir_no(No *raiz, int cod, char titulo[], int qt_temp, Lista_info *lis_inf);
Participantes *inserir_participantes(Participantes *raiz, char nome[], char nome_personagem[], char descricao[]);
Lista_info *inserirLista_info(Lista_info *raiz, int numero, char titulo[], int ano, int qt_ep, Participantes *part);
void mostrar_principal(No *raiz, Lista_info *lis_inf);
void liberarMemoria(No *raiz);
