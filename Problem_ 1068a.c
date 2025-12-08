#include <stdio.h>

#define MAX 1100

int main(void) {
    char s[MAX];
    char pilha[MAX];
    int topo;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        topo = 0;
        int ok = 1;

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                pilha[topo++] = '(';          
            } else if (s[i] == ')') {
                if (topo == 0) {             
                    ok = 0;
                    break;
                }
                topo--;                     
            }
        }

        if (topo != 0) {                     
            ok = 0;
        }

        puts(ok ? "correct" : "incorrect");
    }

    return 0;
}
