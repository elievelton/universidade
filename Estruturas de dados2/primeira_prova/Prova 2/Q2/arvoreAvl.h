#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct termo Termo;
typedef struct sub_termo Sub_Termo;
typedef struct paginas Paginas;

Termo *create_termo();
Sub_Termo *create_sub_termo();
Paginas *create_paginas();

int insert_termo(Termo **root, char title[80], Paginas *pag);
int insert_paginas_to_termo(Termo **termo, int pag);

int insert_sub_termo_to_termo(Termo **termo, char tile_sub_termo[80], Paginas *pag);
int insert_paginas_to_sub_termo(Sub_Termo **subTermo, int pag);

int insert_paginas(Paginas **root, int pag);

Termo *search_termo(Termo *tree, char termo[80]);
Sub_Termo *search_sub_termo_in_termo(Termo *termo, char sub_term[80]);

Termo *freeTree(Termo *tree);

void show(Termo *root);

#endif