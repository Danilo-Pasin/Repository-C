#include <stdio.h>
#include <stdlib.h>

#define MAXE 200000   /* número máximo de arestas */
#define MAXV 200000   /* número máximo de vértices */

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAXE];
int parentUF[MAXV];
int rankUF[MAXV];

/* find com path compression */
int find_set(int x) {
    if (parentUF[x] != x)
        parentUF[x] = find_set(parentUF[x]);
    return parentUF[x];
}

/* union por rank */
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;

    if (rankUF[a] < rankUF[b]) {
        parentUF[a] = b;
    } else if (rankUF[a] > rankUF[b]) {
        parentUF[b] = a;
    } else {
        parentUF[b] = a;
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
    int m, n;

    while (scanf("%d %d", &m, &n) == 2 && (m || n)) {
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edges[i].u = x;
            edges[i].v = y;
            edges[i].w = z;
            total += z;
        }

        /* inicializa union-find para vértices 0..m-1 */
        for (int i = 0; i < m; i++) {
            parentUF[i] = i;
            rankUF[i] = 0;
        }

        /* ordena arestas por peso */
        qsort(edges, n, sizeof(Edge), cmp_edges);

        long long mst = 0;
        int used = 0;

        /* Kruskal */
        for (int i = 0; i < n && used < m - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            if (find_set(u) != find_set(v)) {
                union_set(u, v);
                mst += edges[i].w;
                used++;
            }
        }

        /* economia = total - custo da MST */
        printf("%lld\n", total - mst);
    }

    return 0;
}
