#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T;
int N, M;
char **adj;      /* matriz de adjacência: adj[u][v] = 1 se há aresta u -> v */
char *cor;       /* 0 = não visitado, 1 = em processamento, 2 = finalizado */
int tem_ciclo;

void dfs(int u) {
    if (tem_ciclo) return;

    cor[u] = 1; /* cinza */

    for (int v = 1; v <= N; v++) {
        if (adj[u][v]) {
            if (cor[v] == 1) {
                /* encontramos uma aresta para um vértice cinza: ciclo */
                tem_ciclo = 1;
                return;
            } else if (cor[v] == 0) {
                dfs(v);
                if (tem_ciclo) return;
            }
        }
    }

    cor[u] = 2; /* preto */
}

int main(void) {
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        scanf("%d %d", &N, &M);

        /* aloca matriz N+1 x N+1 (índices 1..N) */
        adj = (char **) malloc((N + 1) * sizeof(char *));
        if (!adj) return 0;
        for (int i = 0; i <= N; i++) {
            adj[i] = (char *) calloc(N + 1, sizeof(char));
            if (!adj[i]) return 0;
        }

        cor = (char *) calloc(N + 1, sizeof(char));
        if (!cor) return 0;

        /* lê arestas A -> B */
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            if (A >= 1 && A <= N && B >= 1 && B <= N) {
                adj[A][B] = 1;  /* pode haver repetidas, não tem problema */
            }
        }

        tem_ciclo = 0;
        for (int u = 1; u <= N && !tem_ciclo; u++) {
            if (cor[u] == 0) {
                dfs(u);
            }
        }

        printf("%s\n", tem_ciclo ? "SIM" : "NAO");

        /* libera memória */
        for (int i = 0; i <= N; i++) {
            free(adj[i]);
        }
        free(adj);
        free(cor);
    }

    return 0;
}
