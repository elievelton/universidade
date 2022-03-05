typedef struct no No;

No *criarNo(int valor);
No *inserir(No *raiz, No *no);
No *buscar(No *raiz, int num);
No *remover(No *raiz, int num);
void mostrar(No *raiz);
void liberarMemoria(No *raiz);
int altura(No *raiz) ;
int buscar_numero_produto(No *raiz);
int qtdnofolha(No *raiz);
No *devolverPai(No *raiz, int num);
void mostrarPai(No *pai);
