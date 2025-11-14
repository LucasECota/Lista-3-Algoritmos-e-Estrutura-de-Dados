#ifndef FILA_H
#define FILA_H
#include "Tipos.h"

typedef struct fila
{
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void FFVazia(TFila *);
int Vazia(TFila *);
void Enfileirar(TProduto, TFila *);
void Imprimir(TFila *);
int Pesquisar(TFila *, TProduto);
void Desenfileirar(TFila *, TProduto *);
void Liberar(TFila *);

#endif
