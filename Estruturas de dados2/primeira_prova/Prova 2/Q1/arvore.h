typedef struct termos_principais Termos_principais;
typedef struct sub_termos Sub_termos;
typedef struct conj_n_pag Conj_n_pag;

Termos_principais *inicializar();
Sub_termos *inicializar2();
Conj_n_pag *inicializar3();

Termos_principais *inserir_no(Termos_principais *raiz, char titulo[], Sub_termos *sub, Conj_n_pag *conj);
Conj_n_pag *inserir_paginas(Conj_n_pag *raiz, int numero);
Sub_termos *inserir_no_sub(Sub_termos *raiz, char titulo[], Conj_n_pag *conj);

Termos_principais *buscar_termo_principal(Termos_principais *raiz, char titulo[]);
Sub_termos *buscar_termo_secundario(Sub_termos *raiz, char titulo[]);

void mostrar_termos(Termos_principais *raiz);
void liberar_memoria(Termos_principais *raiz);
void mostrar_paginas(Conj_n_pag *raiz);