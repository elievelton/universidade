typedef struct no No;

No *inicializar();
No *criarNo(int valor);
No *inserir_no(No *raiz, int cod);
void mostrar_principal(No *raiz);
void liberarMemoria(No *raiz);
int profu(No *raiz);
int prof_menor(No *raiz);
No *buscar_versao_1(No *raiz, int num);
int inserirAvl(No **raiz, No *no);
