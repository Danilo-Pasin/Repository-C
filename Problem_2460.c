#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    int fila[50000];
    int M;
    int i;

    if (scanf("%d", &N) != 1) {
        return 0;
    }

    for (i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);

    /* identificadores vão até 100000 */
    static int saiu[100001];
    memset(saiu, 0, sizeof(saiu));

    for (i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        if (id >= 0 && id <= 100000) {
            saiu[id] = 1;
        }
    }

    int first = 1;
    for (i = 0; i < N; i++) {
        int id = fila[i];
        if (!saiu[id]) {
            if (!first) {
                printf(" ");
            }
            printf("%d", id);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
