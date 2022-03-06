typedef struct no No;

No *inicializar();



No *inserir_no(No *raiz, int cod);
//No* buscar_versao_1(No *raiz, int num);
void mostrar_principal(No *raiz);
//void mostrarLista(Lista_info *raiz);
void liberarMemoria(No *raiz);
int profu(No *raiz);
int prof_menor(No *raiz);
//void liberar_lista(Lista_info *raiz);
//void mostrar_participante(Participantes *raiz);
//void mostrar_obuscado(No *raiz);
No* buscar_versao_1(No *raiz, int num);
int inserirAvl(No **raiz, No *no);
No *criarNo(int valor);