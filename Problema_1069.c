#include <stdio.h>

int main(void) {
    int T;
    char s[1005];

    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        int i;
        int abertos = 0;
        int diamantes = 0;

        scanf("%s", s);   

        for (i = 0; s[i] != '\0'; i++) {
            if (s[i] == '<') {
                abertos++;
            } else if (s[i] == '>') {
                if (abertos > 0) {
                    abertos--;
                    diamantes++;
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}
