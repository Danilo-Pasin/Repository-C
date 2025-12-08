#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXV 26  /* no máximo 26 vértices: 'a'..'z' */

int V, E;
char adj[MAXV][MAXV];   /* matriz de adjacência */
char vis[MAXV];         /* visitados */
int comp_vertices[MAXV];
int comp_size;

/* DFS para coletar vértices de um componente */
void dfs(int u) {
    vis[u] = 1;
    comp_vertices[comp_size++] = u;

    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !vis[v]) {
            dfs(v);
        }
    }
}

/* comparator para qsort (ordena pelos índices, que viram letras) */
int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    for (int caso = 1; caso <= T; caso++) {
        scanf("%d %d", &V, &E);

        /* zera matriz e visitados para este caso */
        memset(adj, 0, sizeof(adj));
        memset(vis, 0, sizeof(vis));

        /* lê arestas */
        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int u = a - 'a';
            int v = b - 'a';
            adj[u][v] = 1;
            adj[v][u] = 1;  /* grafo não direcionado */
        }

        printf("Case #%d:\n", caso);

        int componentes = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                comp_size = 0;
                dfs(i);

                /* ordena os vértices do componente */
                qsort(comp_vertices, comp_size, sizeof(int), cmp_int);

                /* imprime como 'a,b,c,' etc. */
                for (int j = 0; j < comp_size; j++) {
                    char letra = (char)(comp_vertices[j] + 'a');
                    printf("%c,", letra);
                }
                printf("\n");

                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}
