typedef struct Arv23 Arv23;

void mostrar(Arv23 *Raiz);

Arv23 *criaNO(int info1, Arv23 *noEsq, Arv23 *noCentro);

Arv23 *adicionaNo(Arv23 *No, int info, Arv23 *Novo);

int folha(Arv23 *No);

Arv23 *quebraNo(Arv23 **Raiz, Arv23 *NovoNo, int info, int *infomeio);

Arv23 *insere23(Arv23 *pai, Arv23 **raiz, int info, int *infoMeio);

int altura(Arv23 *raiz);

int busca(Arv23 *Raiz,int Valor);

int qtdnofolha(Arv23 *Raiz);