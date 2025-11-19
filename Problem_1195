#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq, *dir;
} No;

No* inserir(No *raiz, int x) {
    if (!raiz) {
        raiz = malloc(sizeof(No));
        raiz->valor = x;
        raiz->esq = raiz->dir = NULL;
    } else if (x < raiz->valor)
        raiz->esq = inserir(raiz->esq, x);
    else
        raiz->dir = inserir(raiz->dir, x);
    return raiz;
}

void pre(No *raiz, int *primeiro) {
    if (!raiz) return;
    if (*primeiro) { printf("%d", raiz->valor); *primeiro = 0; }
    else printf(" %d", raiz->valor);
    pre(raiz->esq, primeiro);
    pre(raiz->dir, primeiro);
}

void in(No *raiz, int *primeiro) {
    if (!raiz) return;
    in(raiz->esq, primeiro);
    if (*primeiro) { printf("%d", raiz->valor); *primeiro = 0; }
    else printf(" %d", raiz->valor);
    in(raiz->dir, primeiro);
}

void post(No *raiz, int *primeiro) {
    if (!raiz) return;
    post(raiz->esq, primeiro);
    post(raiz->dir, primeiro);
    if (*primeiro) { printf("%d", raiz->valor); *primeiro = 0; }
    else printf(" %d", raiz->valor);
}

void liberar(No *raiz) {
    if (!raiz) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main(void) {
    int C;
    scanf("%d", &C);
    for (int caso = 1; caso <= C; caso++) {
        int N, x;
        scanf("%d", &N);
        No *raiz = NULL;
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            raiz = inserir(raiz, x);
        }

        printf("Case %d:\n", caso);
        int primeiro;

        primeiro = 1;
        printf("Pre.: ");
        pre(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        in(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        post(raiz, &primeiro);
        printf("\n\n");

        liberar(raiz);
    }
    return 0;
}
