#include <stdio.h>

#define MAXN 1024
#define MAXM 1024
#define MAXCELLS (MAXN * MAXM)

char grid[MAXN][MAXM + 1];  /* +1 para o '\0' no fim da string */
char vis[MAXN][MAXM];       /* 0 = não visitado, 1 = visitado */

typedef struct {
    int r, c;
} Ponto;

Ponto pilha[MAXCELLS];

int main(void) {
    int N, M;
    int i, j;

    if (scanf("%d %d", &N, &M) != 2) {
        return 0;
    }

    for (i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int cliques = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                /* nova componente branca -> novo clique */
                cliques++;

                /* DFS iterativa a partir de (i,j) */
                int topo = 0;
                pilha[topo].r = i;
                pilha[topo].c = j;
                topo++;
                vis[i][j] = 1;

                while (topo > 0) {
                    topo--;
                    int r = pilha[topo].r;
                    int c = pilha[topo].c;

                    /* vizinho acima */
                    if (r > 0 && grid[r - 1][c] == '.' && !vis[r - 1][c]) {
                        vis[r - 1][c] = 1;
                        pilha[topo].r = r - 1;
                        pilha[topo].c = c;
                        topo++;
                    }

                    /* vizinho abaixo */
                    if (r + 1 < N && grid[r + 1][c] == '.' && !vis[r + 1][c]) {
                        vis[r + 1][c] = 1;
                        pilha[topo].r = r + 1;
                        pilha[topo].c = c;
                        topo++;
                    }

                    /* vizinho à esquerda */
                    if (c > 0 && grid[r][c - 1] == '.' && !vis[r][c - 1]) {
                        vis[r][c - 1] = 1;
                        pilha[topo].r = r;
                        pilha[topo].c = c - 1;
                        topo++;
                    }

                    /* vizinho à direita */
                    if (c + 1 < M && grid[r][c + 1] == '.' && !vis[r][c + 1]) {
                        vis[r][c + 1] = 1;
                        pilha[topo].r = r;
                        pilha[topo].c = c + 1;
                        topo++;
                    }
                }
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
