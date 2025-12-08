#include <stdio.h>
#include <string.h>

#define MAXN 2005
#define MAXM 400000   /* espaço para arestas (direções) */

int head[MAXN], to[MAXM], nxt[MAXM], edge_count;
int headR[MAXN], toR[MAXM], nxtR[MAXM], edgeR_count;
int vis[MAXN];
int N, M;

void add_edge(int u, int v) {
    /* grafo original */
    to[edge_count] = v;
    nxt[edge_count] = head[u];
    head[u] = edge_count++;

    /* grafo transposto */
    toR[edgeR_count] = u;
    nxtR[edgeR_count] = headR[v];
    headR[v] = edgeR_count++;
}

void dfs(int u) {
    vis[u] = 1;
    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = to[e];
        if (!vis[v]) dfs(v);
    }
}

void dfsR(int u) {
    vis[u] = 1;
    for (int e = headR[u]; e != -1; e = nxtR[e]) {
        int v = toR[e];
        if (!vis[v]) dfsR(v);
    }
}

int main(void) {
    while (scanf("%d %d", &N, &M) == 2 && (N || M)) {
        int i;

        /* inicializa listas de adjacência */
        for (i = 1; i <= N; i++) {
            head[i] = -1;
            headR[i] = -1;
        }
        edge_count = edgeR_count = 0;

        for (i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            /* u e v já são 1..N no enunciado */
            add_edge(u, v);
            if (p == 2) {
                add_edge(v, u);
            }
        }

        /* DFS no grafo original a partir do vértice 1 */
        memset(vis, 0, sizeof(vis));
        dfs(1);
        int ok = 1;
        for (i = 1; i <= N; i++) {
            if (!vis[i]) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            /* DFS no grafo transposto */
            memset(vis, 0, sizeof(vis));
            dfsR(1);
            for (i = 1; i <= N; i++) {
                if (!vis[i]) {
                    ok = 0;
                    break;
                }
            }
        }

        printf("%d\n", ok ? 1 : 0);
    }

    return 0;
}
