#include <stdio.h>
#include <stdlib.h>

void quick_sort(int v[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = v[(left + right) / 2];
    int tmp;

    while (i <= j) {
        while (v[i] < pivot) i++;
        while (v[j] > pivot) j--;
        if (i <= j) {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)  quick_sort(v, left, j);
    if (i < right) quick_sort(v, i, right);
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
        if (h == NULL) return 0;

        for (int i = 0; i < N; i++) {
            scanf("%d", &h[i]);
        }

        quick_sort(h, 0, N - 1);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", h[i]);
        }
        printf("\n");

        free(h);
    }

    return 0;
}
