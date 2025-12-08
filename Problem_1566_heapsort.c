#include <stdio.h>
#include <stdlib.h>

void heapify(int v[], int n, int i) {
    int largest = i;
    int left  = 2 * i + 1;
    int right = 2 * i + 2;
    int tmp;

    if (left < n && v[left] > v[largest]) {
        largest = left;
    }
    if (right < n && v[right] > v[largest]) {
        largest = right;
    }

    if (largest != i) {
        tmp = v[i];
        v[i] = v[largest];
        v[largest] = tmp;
        heapify(v, n, largest);
    }
}

void heap_sort(int v[], int n) {
    int i, tmp;

    /* build max-heap */
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    /* extract elements */
    for (i = n - 1; i > 0; i--) {
        tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        heapify(v, i, 0);
    }
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

        heap_sort(h, N);

        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", h[i]);
        }
        printf("\n");

        free(h);
    }

    return 0;
}
