#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int aux[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }

    while (i <= mid) {
        aux[k++] = v[i++];
    }

    while (j <= right) {
        aux[k++] = v[j++];
    }

    for (i = left; i <= right; i++) {
        v[i] = aux[i];
    }
}

void merge_sort_rec(int v[], int aux[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    merge_sort_rec(v, aux, left, mid);
    merge_sort_rec(v, aux, mid + 1, right);
    merge(v, aux, left, mid, right);
}

int main(void) {
    int NC;
    if (scanf("%d", &NC) != 1) {
        return 0;
    }

    while (NC--) {
        int N;
        scanf("%d", &N);

        int *h = (int *) malloc(N * sizeof(int));
        int *aux = (int *) malloc(N * sizeof(int));
        if (h == NULL || aux == NULL) return 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &h[i]);
        }

        merge_sort_rec(h, aux, 0, N - 1);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", h[i]);
        }
        printf("\n");

        free(h);
        free(aux);
    }

    return 0;
}
