#include <stdio.h>
#include <string.h>

#define MAXV 50   /* máximo de vértices (7x7 = 49) */

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        int start;
        int V, A;
        int i;

        scanf("%d", &start);      /* nó inicial (não influencia no resultado) */
        scanf("%d %d", &V, &A);

        /* matriz para marcar arestas já contadas */
        int used[MAXV][MAXV];
        memset(used, 0, sizeof(used));

        int unique_edges = 0;

        for (i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            if (!used[u][v]) {          /* ainda não contamos essa aresta */
                used[u][v] = used[v][u] = 1;
                unique_edges++;
            }
        }

        printf("%d\n", unique_edges * 2);
    }

    return 0;
}
