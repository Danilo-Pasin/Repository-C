#include <stdio.h>
#include <stdlib.h>

#define MAXE 50000   /* máximo de arestas */
#define MAXV 40000   /* máximo de vértices (cidades) */

typedef struct {
    int u, v, w;     /* u --w-- v */
} Edge;

Edge edges[MAXE];
int parent[MAXV];
int rankUF[MAXV];

/* find com path compression */
int find_set(int x) {
    if (parent[x] != x)
        parent[x] = find_set(parent[x]);
    return parent[x];
}

/* union por rank */
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;

    if (rankUF[a] < rankUF[b]) {
        parent[a] = b;
    } else if (rankUF[a] > rankUF[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rankUF[a]++;
    }
}

/* comparação para qsort: ordena por peso crescente */
int cmp_edges(const void *p1, const void *p2) {
    const Edge *a = (const Edge *)p1;
    const Edge *b = (const Edge *)p2;
    return a->w - b->w;
}

int main(void) {
    int M, N;

    while (1) {
        if (scanf("%d %d", &M, &N) != 2)
            return 0;

        if (M == 0 && N == 0)
            break;

        /* lê as arestas */
        for (int i = 0; i < N; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges[i].u = x;
            edges[i].v = y;
            edges[i].w = z;
        }

        /* inicializa union-find (vértices 0..M-1) */
        for (int i = 0; i < M; i++) {
            parent[i] = i;
            rankUF[i] = 0;
        }

        /* ordena arestas pelo peso (Kruskal) */
        qsort(edges, N, sizeof(Edge), cmp_edges);

        long long mst = 0;
        int edges_used = 0;

        for (int i = 0; i < N && edges_used < M - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            if (find_set(u) != find_set(v)) {
                union_set(u, v);
                mst += edges[i].w;
                edges_used++;
            }
        }

        printf("%lld\n", mst);
    }

    return 0;
}
