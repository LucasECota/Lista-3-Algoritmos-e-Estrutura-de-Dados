#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void FFVazia(TFila *Fila)
{
    Fila->frente = (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila *Fila)
{
    return (Fila->frente == Fila->tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    Fila->tras->prox = (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Imprimir(TFila *Fila)
{

    TCelula *aux = Fila->frente->prox;

    printf("[ ");
    while (aux != NULL)
    {
        printf("%d, ", aux->item.codigo);
        aux = aux->prox;
    }
    printf("]\n");
}

int Pesquisar(TFila *Fila, TProduto x)
{
    if (Fila->frente == Fila->tras)
    {
        printf("Fila vazia.\n");
        return 0;
    }

    TCelula *aux = Fila->frente->prox;
    int posicao = 1; // comeca na primeira celula

    while (aux != NULL)
    {
        if (aux->item.codigo == x.codigo)
        {
            printf("Item encontrado na posicao %d.\n", posicao);
            return 1;
        }
        aux = aux->prox;
        posicao++;
    }

    printf("Item nao encontrado.\n");
    return 0;
}

void Desenfileirar(TFila *Fila, TProduto *Item)
{
    TCelula *aux;
    if (!Vazia(Fila))
    {
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}

void Liberar(TFila *Fila)
{
    int i;
    TProduto Item;
    for (i = 0; i < Fila->tamanho; i++)
    {
        Desenfileirar(Fila, &Item);
    }
    free(Fila->frente);
}

TProduto make_prod(int codigo)
{
    TProduto p;
    p.codigo = codigo;
    return p;
}
