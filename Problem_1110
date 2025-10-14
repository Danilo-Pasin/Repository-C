#include <stdio.h>

int main(void) {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int q[110];              // fila (circular simples via head/tail)
        int head = 0, tail = 0;  // [head, tail)
        for (int i = 1; i <= n; ++i) q[tail++] = i;

        int disc[60], dcnt = 0;

        // Enquanto houver pelo menos 2 cartas
        while (tail - head > 1) {
            // descartar topo
            disc[dcnt++] = q[head++];

            // mover próximo topo para base
            q[tail++] = q[head++];
        }

        // Saída: descartadas
        printf("Discarded cards:");
        if (dcnt > 0) {
            printf(" ");
            for (int i = 0; i < dcnt; ++i) {
                if (i) printf(", ");
                printf("%d", disc[i]);
            }
        }
        printf("\n");

        // Carta remanescente
        printf("Remaining card: %d\n", q[head]);
    }
    return 0;
}
