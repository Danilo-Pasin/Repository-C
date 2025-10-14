#include <stdio.h>

int valido(int grid[9][9]) {
    int i, j, k, l;

    // Verificar linhas
    for (i = 0; i < 9; i++) {
        int seen[10] = {0};
        for (j = 0; j < 9; j++) {
            int num = grid[i][j];
            if (seen[num]) return 0;
            seen[num] = 1;
        }
    }

    // Verificar colunas
    for (j = 0; j < 9; j++) {
        int seen[10] = {0};
        for (i = 0; i < 9; i++) {
            int num = grid[i][j];
            if (seen[num]) return 0;
            seen[num] = 1;
        }
    }

    // Verificar submatrizes 3x3
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
    scanf("%d", &n);

    while (n--) {
        int grid[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        printf("Instancia %d\n", inst++);
        if (valido(grid)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
