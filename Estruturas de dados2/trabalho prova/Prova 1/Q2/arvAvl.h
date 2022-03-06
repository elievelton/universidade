typedef struct noAvl No;

No *inicializar();
No *criarNo(int valor);
int altura(No *raiz);
int maior(int x, int y);
void rotacaoDireita(No **no);
void rotacaoEsquerda(No **no);
void rotacaoDirEsq(No **no);
void rotacaoEsqDir(No **no);
int fatorBalanceamento(No *raiz);
int inserirAvl(No **raiz, No *no);
void buscar(No *raiz, int valor, int *passos);
void mostrar(No *raiz);
void liberarMemoria(No *raiz);
int qtdElementos(No *raiz);
void mostrarNo(No *no);