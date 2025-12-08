#include <stdio.h>

#define MAX 1000

int indice_menor(int v[], int n) {
    int i;
    int im = 0; /* índice do menor */

    for (i = 1; i < n; i++) {
        if (v[i] < v[im]) {
            im = i;
        }
    }

    return im;
}

int main() {
    int N;
    int i;
    int X[MAX];
    int pos;
    int menor;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    pos = indice_menor(X, N);
    menor = X[pos];

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);

    return 0;
}
