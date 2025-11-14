#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void FPVazia(TPilha *pilha)
{
    pilha->topo = (TCelula *)malloc(sizeof(TCelula));
    pilha->topo->prox = NULL;
    pilha->fundo = pilha->topo;
    pilha->tamanho = 0;
}

int PVazia(TPilha *pilha)
{
    return (pilha->fundo == pilha->topo);
}

void PEmpilhar(TProduto x, TPilha *pilha)
{
    TCelula *aux = (TCelula *)malloc(sizeof(TCelula));
    pilha->topo->item = x;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
}

void PImprimir(TPilha *Pilha)
{

    TCelula *aux = Pilha->topo->prox;
    printf("[topo] ");
    while (aux != NULL)
    {
        printf("%d", aux->item.codigo);
        aux = aux->prox;
        printf(" -> ");
    }
    printf(" [fundo]\n");
}

int PPesquisar(TPilha *Pilha, TProduto x)
{
    if (PVazia(Pilha))
    {
        printf("Pilha vazia.\n");
        return 0;
    }
    TCelula *aux = Pilha->topo->prox;
    int pos = 1;
    while (aux != Pilha->fundo)
    {
        if (aux->item.codigo == x.codigo)
        {
            printf("Item %d encontrado na posicao %d (a partir do topo).\n", x.codigo, pos);
            return 1;
        }
        aux = aux->prox;
        pos++;
    }
    printf("Item %d nao encontrado.\n", x.codigo);
    return 0;
}

void PDesempilhar(TPilha *Pilha, TProduto *Item)
{
    TCelula *aux;
    if (PVazia(Pilha))
    {
        printf("Aviso: tentativa de desempilhar em pilha vazia.\n");
        return;
    }

    aux = Pilha->topo;
    Pilha->topo = aux->prox;
    *Item = aux->prox->item;
    free(aux);
    Pilha->tamanho--;
}

void PLiberar(TPilha *Pilha)
{

    TProduto tmp;
    while (!PVazia(Pilha))
    {
        PDesempilhar(Pilha, &tmp);
    }
    free(Pilha->fundo);
    Pilha->fundo = Pilha->topo = NULL;
    Pilha->tamanho = 0;
}

static TProduto Pmake_prod(int codigo)
{
    TProduto p;
    p.codigo = codigo;
    return p;
}