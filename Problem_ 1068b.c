#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char c;
    struct No *prox;
} No;

void push(No **topo, char c) {
    No *p = (No *)malloc(sizeof(No));
    if (p == NULL) exit(1);
    p->c = c;
    p->prox = *topo;
    *topo = p;
}

int pop(No **topo) {
    No *p;
    if (*topo == NULL) return 0;
    p = *topo;
    *topo = p->prox;
    free(p);
    return 1;
}

void esvazia(No **topo) {
    No *p;
    while (*topo != NULL) {
        p = *topo;
        *topo = p->prox;
        free(p);
    }
}

int main(void) {
    char s[1200];
    No *topo;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        int ok = 1;
        topo = NULL;

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                push(&topo, '(');
            } else if (s[i] == ')') {
                if (!pop(&topo)) {
                    ok = 0;
                    break;
                }
            }
        }

        if (topo != NULL) ok = 0;  

        esvazia(&topo);

        puts(ok ? "correct" : "incorrect");
    }

    return 0;
}
