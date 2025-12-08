#include <stdio.h>
#include <stdlib.h>

int valido(int **grid) {
    int i, j, k, l;

    /* verificar linhas */
    for (i = 0; i < 9; i++) {
        int seen[10] = {0};
        for (j = 0; j < 9; j++) {
            int num = grid[i][j];
            if (seen[num]) return 0;
            seen[num] = 1;
        }
    }

    /* verificar colunas */
    for (j = 0; j < 9; j++) {
        int seen[10] = {0};
        for (i = 0; i < 9; i++) {
            int num = grid[i][j];
            if (seen[num]) return 0;
            seen[num] = 1;
        }
    }

    /* verificar submatrizes 3x3 */
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            int seen[10] = {0};
            for (k = 0; k < 3; k++) {
                for (l = 0; l < 3; l++) {
                    int num = grid[i + k][j + l];
                    if (seen[num]) return 0;
                    seen[num] = 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, inst = 1;
    int i, j;

    if (scanf("%d", &n) != 1) {
        return 0;
    }

    while (n--) {
        /* aloca matriz 9x9 dinamicamente */
        int **grid = malloc(9 * sizeof(int *));
        if (grid == NULL) return 0;

        for (i = 0; i < 9; i++) {
            grid[i] = malloc(9 * sizeof(int));
            if (grid[i] == NULL) return 0;
        }

        /* leitura da matriz */
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        printf("Instancia %d\n", inst++);

        if (valido(grid)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }

        /* libera memória */
        for (i = 0; i < 9; i++) {
            free(grid[i]);
        }
        free(grid);
    }

    return 0;
}
