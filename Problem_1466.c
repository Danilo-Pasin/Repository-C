#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    unsigned numero;
    struct No *esquerda;
    struct No *direita;
} No;

/* insere em árvore binária de busca */
No* inserir(No *raiz, unsigned valor) {
    if (raiz == NULL) {
        No *novo = (No *) malloc(sizeof(No));
        if (!novo) exit(1);
        novo->numero = valor;
        novo->esquerda = novo->direita = NULL;
        return novo;
    }
    if (valor < raiz->numero) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

/* BFS (percurso por nível) usando fila de ponteiros */
void bfs(No *raiz, unsigned n) {
    if (raiz == NULL) return;

    No **fila = (No **) malloc(n * sizeof(No *));
    if (!fila) exit(1);

    unsigned ini = 0, fim = 0;
    int first = 1;

    fila[fim++] = raiz;

    while (ini < fim) {
        No *atual = fila[ini++];

        if (first) {
            printf("%u", atual->numero);
            first = 0;
        } else {
            printf(" %u", atual->numero);
        }

        if (atual->esquerda != NULL) {
            fila[fim++] = atual->esquerda;
        }
        if (atual->direita != NULL) {
            fila[fim++] = atual->direita;
        }
    }

    free(fila);
}

/* (opcional) liberar memória da árvore */
void destruir(No *raiz) {
    if (raiz == NULL) return;
    destruir(raiz->esquerda);
    destruir(raiz->direita);
    free(raiz);
}

int main(void) {
    unsigned C;   /* número de casos */
    if (scanf("%u", &C) != 1) return 0;

    for (unsigned caso = 1; caso <= C; caso++) {
        unsigned N;
        scanf("%u", &N);

        No *raiz = NULL;
        for (unsigned i = 0; i < N; i++) {
            unsigned x;
            scanf("%u", &x);
            raiz = inserir(raiz, x);
        }

        printf("Case %u:\n", caso);
        bfs(raiz, N);
        printf("\n\n");

        destruir(raiz);  /* não é obrigatório pro beecrowd, mas é bonito :) */
    }

    return 0;
}
