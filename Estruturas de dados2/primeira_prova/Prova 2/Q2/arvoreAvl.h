typedef struct termos_principais Termos_principais;
typedef struct sub_termos Sub_termos;
typedef struct conj_n_pag Conj_n_pag;

Termos_principais *inicializar();
Sub_termos *inicializar2();
Conj_n_pag *inicializar3();

Termos_principais *inserir_termo(Termos_principais *raiz, char titulo[], Sub_termos *sub, Conj_n_pag *conj);
Termos_principais *inserir_paginas_para_termo(Termos_principais *raiz, int pag);
Sub_termos *inserir_paginas_para_sub_termo(Sub_termos *raiz, int pag);

Conj_n_pag *inserir_paginas(Conj_n_pag *raiz, int numero);
Termos_principais *inserir_sub_termo(Termos_principais *raiz, char termo[], char sub_termo[], Conj_n_pag *sub_termo_pag);

Termos_principais *buscar_termo_principal(Termos_principais *raiz, char titulo[]);
Sub_termos *buscar_termo_secundario(Termos_principais *raiz, char sub_termo[]);

void mostrar_termos(Termos_principais *raiz);
void liberar_memoria(Termos_principais *raiz);
void mostrar_paginas(Conj_n_pag *raiz);