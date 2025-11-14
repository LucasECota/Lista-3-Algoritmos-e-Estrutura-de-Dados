#include <stdio.h>
#include <stdlib.h>
#include "Fila.c"
#include "Pilha.c"

// Atividade 1
int verificarFila(TFila *fila1, TFila *fila2)
{
    TCelula *aux1 = fila1->frente->prox;
    TCelula *aux2;
    int encontrado;

    while (aux1 != NULL)
    {
        encontrado = 0;
        aux2 = fila2->frente->prox;
        while (aux2 != NULL)
        {
            if (aux1->item.codigo == aux2->item.codigo)
            {
                encontrado = 1;
                break;
            }
            aux2 = aux2->prox;
        }
        if (!encontrado)
        {
            return 0;
        }
        aux1 = aux1->prox;
    }

    return 1;
}

// Atividade 2
void removerElemento(TFila *fila, int n)
{
    if (n <= 0)
    {
        printf("Indice invalido: %d\n", n);
        return;
    }

    if (fila->frente->prox == NULL)
    {
        printf("A fila está vazia.\n");
        return;
    }

    TCelula *anterior = fila->frente;
    TCelula *atual = anterior->prox;

    for (int i = 1; i < n; i++)
    {

        if (atual == NULL)
        {
            printf("A fila tem menos de %d elementos.\n", n);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("A fila tem menos de %d elementos.\n", n);
        return;
    }

    anterior->prox = atual->prox;

    if (atual == fila->tras)
    {
        fila->tras = anterior;
    }

    free(atual);
    fila->tamanho--;
}

// Aticidade 3
void intersecaoFila(TFila *fila1, TFila *fila2, TFila *fila3)
{

    TCelula *aux1 = fila1->frente->prox;
    TCelula *aux2;

    while (aux1 != NULL)
    {
        aux2 = fila2->frente->prox;
        while (aux2 != NULL)
        {
            if (aux1->item.codigo == aux2->item.codigo)
            {
                Enfileirar(make_prod(aux1->item.codigo), fila3);
            }
            aux2 = aux2->prox;
        }
        aux1 = aux1->prox;
    }
}

// Atividade 4
void diferencaFila(TFila *fila1, TFila *fila2, TFila *fila3)
{

    TCelula *aux1 = fila1->frente->prox;
    TCelula *aux2;

    while (aux1 != NULL)
    {
        int encontrou = 0;
        aux2 = fila2->frente->prox;
        while (aux2 != NULL)
        {
            if (aux1->item.codigo == aux2->item.codigo)
            {
                encontrou = 1;
                break;
            }
            aux2 = aux2->prox;
        }

        if (!encontrou)
        {
            Enfileirar(make_prod(aux1->item.codigo), fila3);
        }

        aux1 = aux1->prox;
    }
}

// Atividade 5
void inverterElementos(TFila *fila, int k)
{
    TPilha pilha;
    TProduto item;

    FPVazia(&pilha);

    for (int i = 0; i < k; i++)
    {
        Desenfileirar(fila, &item);
        PEmpilhar(item, &pilha);
    }

    for (int i = 0; i < k; i++)
    {
        PDesempilhar(&pilha, &item);
        Enfileirar(item, fila);
    }

    int resto = fila->tamanho - k;
    for (int i = 0; i < resto; i++)
    {
        Desenfileirar(fila, &item);
        Enfileirar(item, fila);
    }
}

int main()
{

    while (1)
    {
        int x;

        printf("\n=== MENU PRINCIPAL ===\n");
        printf("[1]: Atividade 1 - Verificar se duas filas apresentam os mesmos elementos\n");
        printf("[2]: Atividade 2 - Remover o n-esimo item de uma fila\n");
        printf("[3]: Atividade 3 - Realizar a intersecao entre duas filas\n");
        printf("[4]: Atividade 4 - Operacao de diferenca entre os elementos de duas filas\n");
        printf("[5]: Atividade 5 - Colocar na ordem reversa os primeiros k elementos da fila\n");
        printf("[0]: Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &x);
        printf("\n");

        if (x == 1)
        {
            TFila fila1;
            TFila fila2;

            FFVazia(&fila1);
            FFVazia(&fila2);

            Enfileirar(make_prod(10), &fila1);
            Enfileirar(make_prod(40), &fila1);
            Enfileirar(make_prod(30), &fila1);

            Enfileirar(make_prod(30), &fila2);
            Enfileirar(make_prod(10), &fila2);
            Enfileirar(make_prod(40), &fila2);

            printf("Fila 1: ");
            Imprimir(&fila1);
            printf("Fila 2: ");
            Imprimir(&fila2);

            int igual = verificarFila(&fila1, &fila2);

            if (igual == 1)
            {
                printf("As filas sao iguais\n");
            }
            else
            {
                printf("As filas nao sao iguais\n");
            }

            Liberar(&fila1);
            Liberar(&fila2);
        }
        else if (x == 2)
        {
            TFila fila;
            int n;

            FFVazia(&fila);

            Enfileirar(make_prod(10), &fila);
            Enfileirar(make_prod(40), &fila);
            Enfileirar(make_prod(30), &fila);

            printf("Fila: ");
            Imprimir(&fila);

            printf("Digite o indice a ser removido: ");
            scanf("%d", &n);

            make_prod(n);

            removerElemento(&fila, n);

            printf("Fila: ");
            Imprimir(&fila);

            Liberar(&fila);
        }
        else if (x == 0)
        {
            printf("Saindo...");
            break;
        }
        else if (x == 3)
        {
            TFila fila1;
            TFila fila2;
            TFila fila3;

            FFVazia(&fila1);
            FFVazia(&fila2);
            FFVazia(&fila3);

            Enfileirar(make_prod(10), &fila1);
            Enfileirar(make_prod(20), &fila1);
            Enfileirar(make_prod(30), &fila1);

            Enfileirar(make_prod(30), &fila2);
            Enfileirar(make_prod(10), &fila2);
            Enfileirar(make_prod(40), &fila2);

            printf("Fila 1: ");
            Imprimir(&fila1);
            printf("Fila 2: ");
            Imprimir(&fila2);

            intersecaoFila(&fila1, &fila2, &fila3);

            printf("Fila 3: ");
            Imprimir(&fila3);

            Liberar(&fila1);
            Liberar(&fila2);
            Liberar(&fila3);
        }
        else if (x == 4)
        {
            TFila fila1;
            TFila fila2;
            TFila fila3;

            FFVazia(&fila1);
            FFVazia(&fila2);
            FFVazia(&fila3);

            Enfileirar(make_prod(10), &fila1);
            Enfileirar(make_prod(20), &fila1);
            Enfileirar(make_prod(30), &fila1);

            Enfileirar(make_prod(30), &fila2);
            Enfileirar(make_prod(10), &fila2);
            Enfileirar(make_prod(40), &fila2);

            printf("Fila 1: ");
            Imprimir(&fila1);
            printf("Fila 2: ");
            Imprimir(&fila2);

            diferencaFila(&fila1, &fila2, &fila3);

            printf("Fila 3: ");
            Imprimir(&fila3);

            Liberar(&fila1);
            Liberar(&fila2);
            Liberar(&fila3);
        }
        else if (x == 5)
        {
            TFila fila;
            int k = 3;

            FFVazia(&fila);

            Enfileirar(make_prod(10), &fila);
            Enfileirar(make_prod(20), &fila);
            Enfileirar(make_prod(30), &fila);
            Enfileirar(make_prod(40), &fila);
            Enfileirar(make_prod(50), &fila);

            printf("Fila: ");
            Imprimir(&fila);

            inverterElementos(&fila, k);

            printf("Fila invertida: ");
            Imprimir(&fila);

            Liberar(&fila);
        }
    }

    return 0;
}
