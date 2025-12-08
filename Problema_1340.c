#include <stdio.h>

#define MAXN 1000

int main(void) {
    int n;

    while (scanf("%d", &n) == 1) {
        int isStack = 1, isQueue = 1, isPq = 1;

        int stack[MAXN];
        int topS = 0;

        int queue[MAXN];
        int frontQ = 0, backQ = 0;

        int pq[MAXN];
        int sizePQ = 0;

        for (int i = 0; i < n; i++) {
            int cmd, x;
            scanf("%d %d", &cmd, &x);

            if (cmd == 1) {
                /* inserção nas possíveis estruturas */
                if (isStack) {
                    stack[topS++] = x;
                }
                if (isQueue) {
                    queue[backQ++] = x;
                }
                if (isPq) {
                    pq[sizePQ++] = x;
                }
            } else { 
                /* remoção: comando tipo 2, deve retornar x */

                /* pilha */
                if (isStack) {
                    if (topS == 0 || stack[topS - 1] != x) {
                        isStack = 0;
                    } else {
                        topS--;
                    }
                }

                /* fila */
                if (isQueue) {
                    if (frontQ == backQ || queue[frontQ] != x) {
                        isQueue = 0;
                    } else {
                        frontQ++;
                    }
                }

                /* fila de prioridade (máximo primeiro) */
                if (isPq) {
                    if (sizePQ == 0) {
                        isPq = 0;
                    } else {
                        int idxMax = 0;
                        for (int j = 1; j < sizePQ; j++) {
                            if (pq[j] > pq[idxMax]) {
                                idxMax = j;
                            }
                        }

                        if (pq[idxMax] != x) {
                            isPq = 0;
                        } else {
                            /* remove o máximo: troca com o último e diminui tamanho */
                            pq[idxMax] = pq[sizePQ - 1];
                            sizePQ--;
                        }
                    }
                }
            }
        }

        int cnt = isStack + isQueue + isPq;

        if (cnt == 0) {
            printf("impossible\n");
        } else if (cnt > 1) {
            printf("not sure\n");
        } else if (isStack) {
            printf("stack\n");
        } else if (isQueue) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }

    return 0;
}
