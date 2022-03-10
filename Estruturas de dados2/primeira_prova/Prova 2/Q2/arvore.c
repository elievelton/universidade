#include "arvore.h"

struct paginas
{
  int height;
  int pag;
  struct paginas *left, *right;
};

struct sub_termo
{
  int height;
  char title[80];
  struct paginas *pag;
  struct sub_termo *left,
      *right;
};

struct termo
{
  int height;
  char title[80];
  struct paginas *pag;
  struct sub_termo *sub_termos;
  struct termo *left, *right;
};

Paginas *freeTree_paginas(Paginas *tree);
Sub_Termo *freeTree_sub_termos(Sub_Termo *tree);
void show_sub_termos(Sub_Termo *root);
void show_paginas(Paginas *root);

Termo *create_termo()
{
  return NULL;
}

Sub_Termo *create_sub_termo()
{
  return NULL;
}

Paginas *create_paginas()
{
  return NULL;
}

int heightTree_termo(Termo *tree)
{
  int height = -1;
  if (tree != NULL)
  {
    int heightLeft = heightTree_termo(tree->left);
    int heightRight = heightTree_termo(tree->right);
    height = heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
  }

  return height;
}

int bigger(int num1, int num2)
{
  int biggerNum = num1;

  if (num1 < num2)
  {
    biggerNum = num2;
  }
  return biggerNum;
}

Termo *rotationRight_termo(Termo *root)
{
  if (root != NULL)
  {
    Termo *aux = root->left;

    root->left = aux->right;
    aux->right = root;
    root->height = bigger(heightTree_termo(root->left), heightTree_termo(root->right)) + 1;
    aux->height = bigger(heightTree_termo(aux->left), heightTree_termo(aux->right)) + 1;
    root = aux;
  }
  return root;
}

Termo *rotationLeft_termo(Termo *root)
{
  if (root != NULL)
  {
    Termo *aux = root->right;

    root->right = aux->left;
    aux->left = root;
    root->height = bigger(heightTree_termo(root->left), heightTree_termo(root->right)) + 1;
    aux->height = bigger(heightTree_termo(aux->left), heightTree_termo(aux->right)) + 1;
    root = aux;
  }
  return root;
}

Termo *rotationRightLeft_termo(Termo *root)
{
  root->right = rotationRight_termo(root->right);
  root = rotationLeft_termo(root);
  return root;
}

Termo *rotationLeftRight_termo(Termo *root)
{
  root->left = rotationLeft_termo(root->left);
  root = rotationRight_termo(root);
  return root;
}

int balancingFactor_termo(Termo *root)
{
  int fb = 0;
  if (root != NULL)
  {
    fb = heightTree_termo(root->left) - heightTree_termo(root->right);
  }

  return fb;
}

int insert_termo(Termo **root, char title[], Paginas *pag)
{
  int inserted = 0;
  if (*root == NULL)
  {
    (*root) = (Termo *)calloc(1, sizeof(Termo));
    strcpy((*root)->title, title);
    (*root)->height = 0;
    (*root)->pag = pag;
    inserted = 1;
  }
  else
  {
    int comp = strcmp(title, (*root)->title);
    if (comp < 0)
    {
      inserted = insert_termo(&(*root)->left, title, pag);
      if (inserted)
      {

        int fb = balancingFactor_termo(*root);
        if (fb > 1)
        {

          if (strcmp(title, (*root)->left->title) > 0)
          {
            *root = rotationLeftRight_termo(*root);
          }
          else
          {
            *root = rotationRight_termo(*root);
          }
        }
      }
    }
    else if (comp > 0)
    {
      inserted = insert_termo(&(*root)->right, title, pag);
      if (inserted)
      {
        int fb = balancingFactor_termo(*root);
        if (fb < -1)
        {
          if (strcmp(title, (*root)->right->title) < 0)
          {
            *root = rotationRightLeft_termo(*root);
          }
          else
          {
            *root = rotationLeft_termo(*root);
          }
        }
      }
    }
  }

  (*root)->height = bigger(heightTree_termo((*root)->left), heightTree_termo((*root)->right)) + 1;

  return inserted;
}

Termo *freeTree(Termo *tree)
{
  if (tree != NULL)
  {
    if (tree->left == NULL && tree->right == NULL)
    {
      freeTree_paginas(tree->pag);
      freeTree_sub_termos(tree->sub_termos);
      free(tree);
      tree = NULL;
    }
    else
    {
      tree->left = freeTree(tree->left);
      tree->right = freeTree(tree->right);
    }
  }
  return tree;
}

Termo *search_termo(Termo *tree, char termo[80])
{
  Termo *found;
  if (tree != NULL)
  {
    int comp = strcmp(termo, tree->title);
    if (comp < 0)
    {
      found = search_termo(tree->left, termo);
    }
    else if (comp > 0)
    {
      found = search_termo(tree->right, termo);
    }
    else
    {
      found = tree;
    }
  }
  return found;
}

void show(Termo *root)
{
  if (root != NULL)
  {
    show(root->left);
    printf("%s (", root->title);
    show_paginas(root->pag);
    printf(")\n");
    show_sub_termos(root->sub_termos);
    show(root->right);
  }
}

// ----------------------------------- sub termos ---------------------------------

int heightTree_sub_termo(Sub_Termo *tree)
{
  int height = -1;
  if (tree != NULL)
  {
    int heightLeft = heightTree_sub_termo(tree->left);
    int heightRight = heightTree_sub_termo(tree->right);
    height = heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
  }

  return height;
}

Sub_Termo *rotationRight_sub_termo(Sub_Termo *root)
{
  if (root != NULL)
  {
    Sub_Termo *aux = root->left;

    root->left = aux->right;
    aux->right = root;
    root->height = bigger(heightTree_sub_termo(root->left), heightTree_sub_termo(root->right)) + 1;
    aux->height = bigger(heightTree_sub_termo(aux->left), heightTree_sub_termo(aux->right)) + 1;
    root = aux;
  }
  return root;
}

Sub_Termo *rotationLeft_sub_termo(Sub_Termo *root)
{
  if (root != NULL)
  {
    Sub_Termo *aux = root->right;

    root->right = aux->left;
    aux->left = root;
    root->height = bigger(heightTree_sub_termo(root->left), heightTree_sub_termo(root->right)) + 1;
    aux->height = bigger(heightTree_sub_termo(aux->left), heightTree_sub_termo(aux->right)) + 1;
    root = aux;
  }
  return root;
}

Sub_Termo *rotationRightLeft_sub_termo(Sub_Termo *root)
{
  root->right = rotationRight_sub_termo(root->right);
  root = rotationLeft_sub_termo(root);
  return root;
}

Sub_Termo *rotationLeftRight_sub_termo(Sub_Termo *root)
{
  root->left = rotationLeft_sub_termo(root->left);
  root = rotationRight_sub_termo(root);
  return root;
}

int balancingFactor_sub_termo(Sub_Termo *root)
{
  int fb = 0;
  if (root != NULL)
  {
    fb = heightTree_sub_termo(root->left) - heightTree_sub_termo(root->right);
  }

  return fb;
}

int insert_sub_termo(Sub_Termo **root, char title[], Paginas *pag)
{
  int inserted = 0;
  if (*root == NULL)
  {

    (*root) = (Sub_Termo *)calloc(1, sizeof(Sub_Termo));
    strcpy((*root)->title, title);
    (*root)->height = 0;
    (*root)->pag = pag;
    inserted = 1;
  }
  else
  {
    int comp = strcmp(title, (*root)->title);
    if (comp < 0)
    {
      inserted = insert_sub_termo(&(*root)->left, title, pag);
      if (inserted)
      {

        int fb = balancingFactor_sub_termo(*root);
        if (fb > 1)
        {

          if (strcmp(title, (*root)->left->title) > 0)
          {
            *root = rotationLeftRight_sub_termo(*root);
          }
          else
          {
            *root = rotationRight_sub_termo(*root);
          }
        }
      }
    }
    else if (comp > 0)
    {
      inserted = insert_sub_termo(&(*root)->right, title, pag);
      if (inserted)
      {
        int fb = balancingFactor_sub_termo(*root);
        if (fb < -1)
        {
          if (strcmp(title, (*root)->right->title) < 0)
          {
            *root = rotationRightLeft_sub_termo(*root);
          }
          else
          {
            *root = rotationLeft_sub_termo(*root);
          }
        }
      }
    }
  }

  (*root)->height = bigger(heightTree_sub_termo((*root)->left), heightTree_sub_termo((*root)->right)) + 1;

  return inserted;
}

Sub_Termo *freeTree_sub_termos(Sub_Termo *tree)
{
  if (tree != NULL)
  {
    if (tree->left == NULL && tree->right == NULL)
    {
      freeTree_paginas(tree->pag);
      free(tree);
      tree = NULL;
    }
    else
    {
      tree->left = freeTree_sub_termos(tree->left);
      tree->right = freeTree_sub_termos(tree->right);
    }
  }
  return tree;
}

Sub_Termo *search_sub_termo(Sub_Termo *tree, char sub_term[80])
{
  Sub_Termo *found;
  if (tree != NULL)
  {
    int comp = strcmp(sub_term, tree->title);
    if (comp < 0)
    {
      found = search_sub_termo(tree->left, sub_term);
    }
    else if (comp > 0)
    {
      found = search_sub_termo(tree->right, sub_term);
    }
    else
    {
      found = tree;
    }
  }
  return found;
}

Sub_Termo *search_sub_termo_in_termo(Termo *termo, char sub_term[80])
{
  return search_sub_termo(termo->sub_termos, sub_term);
}

void show_sub_termos(Sub_Termo *root)
{
  if (root != NULL)
  {
    show_sub_termos(root->left);
    printf("---%s", root->title);
    printf("(");
    show_paginas(root->pag);
    printf(")\n");
    show_sub_termos(root->right);
  }
}

// ----------------------------------- paginas ---------------------------------

int heightTree_paginas(Paginas *tree)
{
  int height = -1;
  if (tree != NULL)
  {
    int heightLeft = heightTree_paginas(tree->left);
    int heightRight = heightTree_paginas(tree->right);
    height = heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
  }

  return height;
}

Paginas *rotationRight_paginas(Paginas *root)
{
  if (root != NULL)
  {
    Paginas *aux = root->left;

    root->left = aux->right;
    aux->right = root;
    root->height = bigger(heightTree_paginas(root->left), heightTree_paginas(root->right)) + 1;
    aux->height = bigger(heightTree_paginas(aux->left), heightTree_paginas(aux->right)) + 1;
    root = aux;
  }
  return root;
}

Paginas *rotationLeft_paginas(Paginas *root)
{
  if (root != NULL)
  {
    Paginas *aux = root->right;

    root->right = aux->left;
    aux->left = root;
    root->height = bigger(heightTree_paginas(root->left), heightTree_paginas(root->right)) + 1;
    aux->height = bigger(heightTree_paginas(aux->left), heightTree_paginas(aux->right)) + 1;
    root = aux;
  }
  return root;
}

Paginas *rotationRightLeft_paginas(Paginas *root)
{
  root->right = rotationRight_paginas(root->right);
  root = rotationLeft_paginas(root);
  return root;
}

Paginas *rotationLeftRight_paginas(Paginas *root)
{
  root->left = rotationLeft_paginas(root->left);
  root = rotationRight_paginas(root);
  return root;
}

int balancingFactor_paginas(Paginas *root)
{
  int fb = 0;
  if (root != NULL)
  {
    fb = heightTree_paginas(root->left) - heightTree_paginas(root->right);
  }

  return fb;
}

int insert_paginas(Paginas **root, int pag)
{
  int inserted = 0;
  if (*root == NULL)
  {

    (*root) = (Paginas *)calloc(1, sizeof(Paginas));
    (*root)->pag = pag;
    (*root)->height = 0;
    inserted = 1;
  }
  else if (pag < (*root)->pag)
  {

    inserted = insert_paginas(&(*root)->left, pag);
    if (inserted)
    {

      int fb = balancingFactor_paginas(*root);
      if (fb > 1)
      {

        if (pag > (*root)->pag)
        {
          *root = rotationLeftRight_paginas(*root);
        }
        else
        {
          *root = rotationRight_paginas(*root);
        }
      }
    }
  }
  else if (pag > (*root)->pag)
  {
    inserted = insert_paginas(&(*root)->right, pag);
    if (inserted)
    {
      int fb = balancingFactor_paginas(*root);
      if (fb < -1)
      {
        if (pag < (*root)->pag)
        {
          *root = rotationRightLeft_paginas(*root);
        }
        else
        {
          *root = rotationLeft_paginas(*root);
        }
      }
    }
  }

  (*root)->height = bigger(heightTree_paginas((*root)->left), heightTree_paginas((*root)->right)) + 1;

  return inserted;
}

Paginas *freeTree_paginas(Paginas *tree)
{
  if (tree != NULL)
  {
    if (tree->left == NULL && tree->right == NULL)
    {
      free(tree);
      tree = NULL;
    }
    else
    {
      tree->left = freeTree_paginas(tree->left);
      tree->right = freeTree_paginas(tree->right);
    }
  }
  return tree;
}

void show_paginas(Paginas *root)
{
  if (root != NULL)
  {
    show_paginas(root->left);
    printf("%d, ", root->pag);
    show_paginas(root->right);
  }
}

int insert_sub_termo_to_termo(Termo **termo, char tile_sub_termo[80], Paginas *pag)
{
  return insert_sub_termo(&(*termo)->sub_termos, tile_sub_termo, pag);
}

int insert_paginas_to_termo(Termo **termo, int pag)
{
  return insert_paginas(&(*termo)->pag, pag);
}

int insert_paginas_to_sub_termo(Sub_Termo **subTermo, int pag)
{
  return insert_paginas(&(*subTermo)->pag, pag);
}
