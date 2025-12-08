#include <stdio.h>

int main(void) {
    int n;

    while (scanf("%d", &n) == 1 && n) {
        while (1) {
            int first;
            if (scanf("%d", &first) != 1) {
                return 0;
            }

            if (first == 0) {
                printf("\n");
                break;
            }

            int seq[1005];
            int stack[1005];
            int top = 0;
            int curr = 0;

            seq[0] = first;
            for (int i = 1; i < n; i++) {
                scanf("%d", &seq[i]);
            }

            for (int i = 1; i <= n; i++) {
                stack[top++] = i;

                while (top > 0 && stack[top - 1] == seq[curr]) {
                    top--;
                    curr++;
                }
            }

            if (top == 0)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
