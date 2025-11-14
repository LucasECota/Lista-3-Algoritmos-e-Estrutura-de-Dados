#ifndef TIPOS_H
#define TIPOS_H

typedef struct item
{
    int codigo;
} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula *prox;
} TCelula;

#endif
