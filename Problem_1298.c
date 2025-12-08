#include <stdio.h>
#include <string.h>

#define MAXN 605  /* 2*300 + 5 de folga */

/* bloqueios de movimento entre células (grid de 2N x (2N+1)) */
static unsigned char up[MAXN][MAXN];
static unsigned char down[MAXN][MAXN];
static unsigned char leftb[MAXN][MAXN];
static unsigned char rightb[MAXN][MAXN];
static unsigned char vis[MAXN][MAXN];

typedef struct {
    int x, y;
} P;

int N;

void bfs(int sx, int sy) {
    /* pilha para DFS iterativa (até 2N * (2N+1) células) */
    static P stack[MAXN * MAXN];
    int top = 0;

    stack[top++] = (P){sx, sy};

    while (top > 0) {
        P cur = stack[--top];
        int x = cur.x;
        int y = cur.y;

        if (x < 0 || x >= 2 * N || y < 0 || y >= 2 * N + 1) continue;
        if (vis[x][y]) continue;
        vis[x][y] = 1;

        /* vizinhos, checando borda + barreira */
        if (x > 0 && !up[x][y])
            stack[top++] = (P){x - 1, y};
        if (x + 1 < 2 * N && !down[x][y])
            stack[top++] = (P){x + 1, y};
        if (y > 0 && !leftb[x][y])
            stack[top++] = (P){x, y - 1};
        if (y + 1 < 2 * N + 1 && !rightb[x][y])
            stack[top++] = (P){x, y + 1};
    }
}

int main(void) {
    char row[610];

    while (1) {
        if (scanf("%d", &N) != 1)
            return 0;
        if (N == 0)
            break;

        int rows = 2 * N;
        int cols = 2 * N + 1;

        /* limpa apenas a área usada */
        for (int i = 0; i < rows; ++i) {
            memset(up[i],     0, cols * sizeof(unsigned char));
            memset(down[i],   0, cols * sizeof(unsigned char));
            memset(leftb[i],  0, cols * sizeof(unsigned char));
            memset(rightb[i], 0, cols * sizeof(unsigned char));
            memset(vis[i],    0, cols * sizeof(unsigned char));
        }

        /* lê as 2N-1 linhas de barreiras */
        for (int i = 0; i < 2 * N - 1; ++i) {
            scanf("%s", row);  /* N caracteres 'H' ou 'V' */

            for (int j = 0; j < N; ++j) {
                char c = row[j];

                if (i % 2 == 0) {
                    /* linha de barreiras "par" (0-based) */
                    if (c == 'H') {
                        /* barreira horizontal entre linhas i e i+1,
                           cobrindo colunas 2j e 2j+1 */
                        down[i][2 * j]       = 1;
                        down[i][2 * j + 1]   = 1;
                        up[i + 1][2 * j]     = 1;
                        up[i + 1][2 * j + 1] = 1;
                    } else { /* 'V' */
                        /* barreira vertical entre colunas 2j e 2j+1,
                           cobrindo linhas i e i+1 */
                        rightb[i][2 * j]       = 1;
                        rightb[i + 1][2 * j]   = 1;
                        leftb[i][2 * j + 1]    = 1;
                        leftb[i + 1][2 * j + 1]= 1;
                    }
                } else {
                    /* linha de barreiras "ímpar" (0-based) */
                    if (c == 'H') {
                        /* horizontal entre linhas i e i+1,
                           cobrindo colunas 2j+1 e 2j+2 */
                        down[i][2 * j + 1]     = 1;
                        down[i][2 * j + 2]     = 1;
                        up[i + 1][2 * j + 1]   = 1;
                        up[i + 1][2 * j + 2]   = 1;
                    } else { /* 'V' */
                        /* vertical entre colunas 2j+1 e 2j+2,
                           cobrindo linhas i e i+1 */
                        rightb[i][2 * j + 1]     = 1;
                        rightb[i + 1][2 * j + 1] = 1;
                        leftb[i][2 * j + 2]      = 1;
                        leftb[i + 1][2 * j + 2]  = 1;
                    }
                }
            }
        }

        /* conta componentes conexos das células */
        int comp = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!vis[i][j]) {
                    bfs(i, j);
                    ++comp;
                }
            }
        }

        /* número mínimo de barreiras a girar
           (de acordo com a construção clássica do problema) */
        printf("%d\n", comp - 1);
    }

    return 0;
}
