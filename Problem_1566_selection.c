#include <stdio.h>

#define MIN_H 20
#define MAX_H 230
#define RANGE (MAX_H + 1)

void selection_sort(int v[], int n) {
    int i, j, min, tmp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (min != i) {
            tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
    }
}

int main(void) {
    int NC;
    if (scanf("%d", &NC) != 1) {
        return 0;
    }

    while (NC--) {
        int N;
        int freq[RANGE] = {0};
        int valores[ MAX_H - MIN_H + 1 ];
        int i, qtd_distintos = 0;

        scanf("%d", &N);

        /* conta frequências das alturas */
        for (i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            freq[h]++;
        }

        /* monta vetor com as alturas distintas que apareceram */
        for (i = MIN_H; i <= MAX_H; i++) {
            if (freq[i] > 0) {
                valores[qtd_distintos++] = i;
            }
        }

        /* ordena as alturas distintas por selection sort */
        selection_sort(valores, qtd_distintos);

        /* imprime as alturas em ordem, repetindo pela frequência */
        int first = 1;
        for (i = 0; i < qtd_distintos; i++) {
            int h = valores[i];
            while (freq[h]--) {
                if (!first) {
                    printf(" ");
                }
                printf("%d", h);
                first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}
