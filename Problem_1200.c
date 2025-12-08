#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char letra;
    struct No *esq;
    struct No *dir;
} No;

/* insere na BST */
No* inserir(No *raiz, char c) {
    if (raiz == NULL) {
        No *novo = (No *) malloc(sizeof(No));
        if (!novo) exit(1);
        novo->letra = c;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (c < raiz->letra) {
        raiz->esq = inserir(raiz->esq, c);
    } else if (c > raiz->letra) {
        raiz->dir = inserir(raiz->dir, c);
    }
    /* problema garante que não há elementos repetidos */
    return raiz;
}

/* busca na BST */
int busca(No *raiz, char c) {
    while (raiz != NULL) {
        if (c == raiz->letra) return 1;
        if (c < raiz->letra)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }
    return 0;
}

/* percursos com controle de espaço para não ter espaço no final */
void infixa(No *raiz, int *first) {
    if (raiz == NULL) return;
    infixa(raiz->esq, first);
    if (!*first) printf(" ");
    printf("%c", raiz->letra);
    *first = 0;
    infixa(raiz->dir, first);
}

void prefixa(No *raiz, int *first) {
    if (raiz == NULL) return;
    if (!*first) printf(" ");
    printf("%c", raiz->letra);
    *first = 0;
    prefixa(raiz->esq, first);
    prefixa(raiz->dir, first);
}

void posfixa(No *raiz, int *first) {
    if (raiz == NULL) return;
    posfixa(raiz->esq, first);
    posfixa(raiz->dir, first);
    if (!*first) printf(" ");
    printf("%c", raiz->letra);
    *first = 0;
}

/* (opcional) liberar memória da árvore – não é obrigatório pro beecrowd */
void destruir(No *raiz) {
    if (raiz == NULL) return;
    destruir(raiz->esq);
    destruir(raiz->dir);
    free(raiz);
}

int main(void) {
    char comando[20];
    char letra;
    No *raiz = NULL;

    /* lê até EOF */
    while (scanf("%s", comando) == 1) {

        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &letra);   /* espaço antes de %c ignora '\n' e espaços */
            raiz = inserir(raiz, letra);
        }
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &letra);
            if (busca(raiz, letra))
                printf("%c existe\n", letra);
            else
                printf("%c nao existe\n", letra);
        }
        else if (strcmp(comando, "INFIXA") == 0) {
            int first = 1;
            infixa(raiz, &first);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0) {
            int first = 1;
            prefixa(raiz, &first);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0) {
            int first = 1;
            posfixa(raiz, &first);
            printf("\n");
        }
    }

    /* destruir(raiz);  // opcional */
    return 0;
}
