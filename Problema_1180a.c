#include <stdio.h>

int main() {
    int N, i, pos = 0;
    scanf("%d", &N);

    int X[N];
    for (i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    int menor = X[0];
    for (i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            pos = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);

    return 0;
}
