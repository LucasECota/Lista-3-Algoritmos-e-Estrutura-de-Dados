#ifndef PILHA_H
#define PILHA_H
#include "Tipos.h"

typedef struct pilha
{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *);
int PVazia(TPilha *);
void PEmpilhar(TProduto, TPilha *);
void PImprimir(TPilha *);
int PPesquisar(TPilha *, TProduto);
void PDesempilhar(TPilha *, TProduto *);
void PLiberar(TPilha *);

#endif
