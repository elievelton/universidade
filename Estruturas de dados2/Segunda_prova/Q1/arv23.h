typedef struct Arv23 Arv23;
typedef struct Calcados Calcados;

void mostrar(Arv23 *Raiz);

Arv23 *InsereCalcados(Arv23 *pai, Arv23 **Raiz, int cod, char tipo, char marca, int qtd, float preco, Calcados *infoMeio);

Calcados *criaCal(int cod, char tipo, char marca, int qtd, float preco);

Arv23 *criaNO(Calcados *info, Arv23 *noEsq, Arv23 *noCentro);

Arv23 *adicionaNo(Arv23 *No, Calcados *info, Arv23 *Novo);

int folha(Arv23 *No);

Arv23 *quebraNo(Arv23 **Raiz, Arv23 *NovoNo, Calcados *info, Calcados *infoMeio);

Arv23 *insere23(Arv23 *pai, Arv23 **Raiz, Calcados *info, Calcados *infoMeio);

int excluirElemento(Arv23 **pai, Arv23 **Raiz, int info);

int altura(Arv23 *raiz);

int busca(Arv23 *Raiz, int Valor);

int qtdnofolha(Arv23 *Raiz);

int estaContido(Arv23 *Raiz, int info);

Arv23 *inicializar();