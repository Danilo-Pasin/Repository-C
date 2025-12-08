#include <stdio.h>
#include <stdlib.h>

#define MAXC 10000
#define MAXV (2 * MAXC)       /* cada cidade vira 2 estados (par/ímpar) */
#define MAXE 50000
#define MAXEDIR (4 * MAXE)    /* cada estrada vira 4 arestas dirigidas */
#define INFLL (1LL << 60)

typedef struct {
    int to;
    int w;
    int next;
} Edge;

Edge edges[MAXEDIR];
int head[MAXV];
int edge_cnt;

long long distv[MAXV];

/* heap simples para Dijkstra (lazy, sem decrease-key) */
int heap_node[MAXEDIR + MAXV + 5];
long long heap_dist[MAXEDIR + MAXV + 5];
int heap_size;

/* funções de heap */
void heap_swap(int i, int j) {
    int tn = heap_node[i];
    long long td = heap_dist[i];
    heap_node[i] = heap_node[j];
    heap_dist[i] = heap_dist[j];
    heap_node[j] = tn;
    heap_dist[j] = td;
}

void heap_push(int node, long long d) {
    int i = ++heap_size;
    heap_node[i] = node;
    heap_dist[i] = d;
    while (i > 1) {
        int p = i / 2;
        if (heap_dist[p] <= heap_dist[i]) break;
        heap_swap(p, i);
        i = p;
    }
}

int heap_pop(int *node, long long *d) {
    if (heap_size == 0) return 0;
    *node = heap_node[1];
    *d    = heap_dist[1];

    heap_node[1] = heap_node[heap_size];
    heap_dist[1] = heap_dist[heap_size];
    heap_size--;

    int i = 1;
    while (1) {
        int l = 2 * i;
        int r = 2 * i + 1;
        int smallest = i;

        if (l <= heap_size && heap_dist[l] < heap_dist[smallest]) smallest = l;
        if (r <= heap_size && heap_dist[r] < heap_dist[smallest]) smallest = r;
        if (smallest == i) break;
        heap_swap(i, smallest);
        i = smallest;
    }
    return 1;
}

/* adiciona aresta u -> v */
void add_edge(int u, int v, int w) {
    edges[edge_cnt].to = v;
    edges[edge_cnt].w  = w;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt++;
}

/* Dijkstra a partir de src em grafo com n_nodes vértices (0..n_nodes-1) */
void dijkstra(int src, int n_nodes) {
    for (int i = 0; i < n_nodes; i++) {
        distv[i] = INFLL;
    }
    distv[src] = 0;

    heap_size = 0;
    heap_push(src, 0);

    int u;
    long long d;

    while (heap_pop(&u, &d)) {
        if (d != distv[u]) continue;  /* entrada velha no heap */

        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v   = edges[e].to;
            long long nd = d + edges[e].w;
            if (nd < distv[v]) {
                distv[v] = nd;
                heap_push(v, nd);
            }
        }
    }
}

int main(void) {
    int C, V;

    /* lê até EOF */
    while (scanf("%d %d", &C, &V) == 2) {
        /* inicializa grafo */
        for (int i = 0; i < 2 * C; i++) {
            head[i] = -1;
        }
        edge_cnt = 0;

        for (int i = 0; i < V; i++) {
            int c1, c2, g;
            scanf("%d %d %d", &c1, &c2, &g);
            /* converter para 0-based */
            c1--; 
            c2--;

            int u_even = c1 * 2;
            int u_odd  = c1 * 2 + 1;
            int v_even = c2 * 2;
            int v_odd  = c2 * 2 + 1;

            /* cada estrada: 4 arestas no grafo expandido */
            add_edge(u_even, v_odd, g);
            add_edge(v_even, u_odd, g);
            add_edge(u_odd,  v_even, g);
            add_edge(v_odd,  u_even, g);
        }

        int total_nodes = 2 * C;
        int start  = 0 * 2 + 0;         /* cidade 1 (índice 0), par */
        int target = (C - 1) * 2 + 0;   /* cidade C (índice C-1), par */

        dijkstra(start, total_nodes);

        if (distv[target] == INFLL) {
            printf("-1\n");
        } else {
            printf("%lld\n", distv[target]);
        }
    }

    return 0;
}
