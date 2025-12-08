#include <stdio.h>

#define MAXG 105   /* máximo de GPs */
#define MAXP 105   /* máximo de pilotos */
#define MAXK 105   /* máximo de posições pontuadas */

int pos[MAXG][MAXP];   /* pos[g][p] = posição do piloto p na corrida g */
int pontos[MAXK];
int total[MAXP];

int main(void) {
    int G, P;

    while (scanf("%d %d", &G, &P) == 2 && (G || P)) {
        int i, j;

        /* lê as G corridas; para cada piloto j, lê a posição dele */
        for (i = 0; i < G; i++) {
            for (j = 0; j < P; j++) {
                scanf("%d", &pos[i][j]);
            }
        }

        int S;
        scanf("%d", &S);

        while (S--) {
            int K;
            scanf("%d", &K);

            for (i = 1; i <= K; i++) {
                scanf("%d", &pontos[i]);
            }

            /* zera pontuação dos pilotos para este sistema */
            for (i = 0; i < P; i++)
                total[i] = 0;

            /* acumula pontuação */
            for (i = 0; i < G; i++) {            /* para cada corrida   */
                for (j = 0; j < P; j++) {        /* para cada piloto j  */
                    int posicao = pos[i][j];     /* posição do piloto j */
                    if (posicao <= K) {
                        total[j] += pontos[posicao];
                    }
                }
            }

            /* encontra maior pontuação */
            int max = 0;
            for (i = 0; i < P; i++) {
                if (total[i] > max)
                    max = total[i];
            }

            /* imprime todos pilotos com pontuação máxima (índices 1..P) */
            int first = 1;
            for (i = 0; i < P; i++) {
                if (total[i] == max) {
                    if (!first) printf(" ");
                    printf("%d", i + 1);
                    first = 0;
                }
            }
            printf("\n");
        }
    }

    return 0;
}
