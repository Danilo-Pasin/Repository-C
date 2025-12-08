#include <stdio.h>

int main() {
    int N;
    int i;
    int x;
    int menor;
    int pos;

    if (scanf("%d", &N) != 1) {
        return 0;
    }

    /* lê o primeiro elemento e inicializa */
    scanf("%d", &x);
    menor = x;
    pos = 0;

    /* lê do segundo até o N-ésimo, atualizando o menor */
    for (i = 1; i < N; i++) {
        scanf("%d", &x);
        if (x < menor) {
            menor = x;
            pos = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);

    return 0;
}
