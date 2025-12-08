#include <stdio.h>

#define MIN_H 20
#define MAX_H 230
#define RANGE (MAX_H + 1)

void insertion_sort(int v[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
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

        /* ordena as alturas distintas por insertion sort */
        insertion_sort(valores, qtd_distintos);

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
