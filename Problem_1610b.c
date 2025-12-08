#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10000

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node *adj[MAXN + 1];  /* lista de adjacência 1..N */
char cor[MAXN + 1];   /* 0 = não visitado, 1 = em processamento, 2 = finalizado */
int tem_ciclo;

void add_edge(int u, int v) {
    Node *no = (Node *) malloc(sizeof(Node));
    if (!no) exit(1);
    no->v = v;
    no->next = adj[u];
    adj[u] = no;
}

void dfs(int u) {
    cor[u] = 1; /* cinza */

    for (Node *p = adj[u]; p != NULL; p = p->next) {
        int v = p->v;
        if (cor[v] == 1) {
            /* volta para vértice cinza -> ciclo */
            tem_ciclo = 1;
            return;
        } else if (cor[v] == 0) {
            dfs(v);
            if (tem_ciclo) return;
        }
    }

    cor[u] = 2; /* preto */
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        /* inicializa listas e cores */
        for (int i = 1; i <= N; i++) {
            adj[i] = NULL;
            cor[i] = 0;
        }

        /* lê arestas A -> B */
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            if (A >= 1 && A <= N && B >= 1 && B <= N) {
                add_edge(A, B);
            }
        }

        tem_ciclo = 0;
        for (int u = 1; u <= N && !tem_ciclo; u++) {
            if (cor[u] == 0) {
                dfs(u);
            }
        }

        printf("%s\n", tem_ciclo ? "SIM" : "NAO");

        /* libera memória das listas (pra não acumular entre casos) */
        for (int i = 1; i <= N; i++) {
            Node *p = adj[i];
            while (p) {
                Node *tmp = p->next;
                free(p);
                p = tmp;
            }
            adj[i] = NULL;
        }
    }

    return 0;
}
