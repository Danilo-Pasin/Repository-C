#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int altura;
    int freq;               /* quantas vezes essa altura aparece */
    struct No *esq;
    struct No *dir;
} No;

No* novo_no(int h) {
    No *p = (No *) malloc(sizeof(No));
    if (!p) exit(1);
    p->altura = h;
    p->freq = 1;
    p->esq = p->dir = NULL;
    return p;
}

/* insere altura na BST, incrementando frequência se já existir */
No* inserir(No *raiz, int h) {
    if (raiz == NULL) {
        return novo_no(h);
    }
    if (h < raiz->altura) {
        raiz->esq = inserir(raiz->esq, h);
    } else if (h > raiz->altura) {
        raiz->dir = inserir(raiz->dir, h);
    } else {
        raiz->freq++;   /* altura repetida */
    }
    return raiz;
}

/* percurso em ordem para imprimir em ordem crescente */
void em_ordem(No *raiz, int *primeiro) {
    int i;
    if (raiz == NULL) return;

    em_ordem(raiz->esq, primeiro);

    for (i = 0; i < raiz->freq; i++) {
        if (*primeiro) {
            printf("%d", raiz->altura);
            *primeiro = 0;
        } else {
            printf(" %d", raiz->altura);
        }
    }

    em_ordem(raiz->dir, primeiro);
}

/* libera memória da árvore */
void destruir(No *raiz) {
    if (raiz == NULL) return;
    destruir(raiz->esq);
    destruir(raiz->dir);
    free(raiz);
}

int main(void) {
    int NC;

    if (scanf("%d", &NC) != 1) {
        return 0;
    }

    while (NC--) {
        int N;
        int i;
        No *raiz = NULL;

        scanf("%d", &N);

        for (i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            raiz = inserir(raiz, h);
        }

        int primeiro = 1;
        em_ordem(raiz, &primeiro);
        printf("\n");

        destruir(raiz);
    }

    return 0;
}
