#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 1000005
#define MAX_TOTAL_LEN 1000005

char buffer[1000005];   /* buffer só pra leitura temporária */
char *joias[MAX_STRINGS];

int cmp_str(const void *a, const void *b) {
    char * const *sa = (char * const *)a;
    char * const *sb = (char * const *)b;
    return strcmp(*sa, *sb);
}

int main(void) {
    int count = 0;

    /* lê até EOF: cada linha é uma string sem espaços */
    while (scanf("%s", buffer) == 1) {
        size_t len = strlen(buffer);
        char *s = (char *) malloc((len + 1) * sizeof(char));
        if (!s) exit(1);
        strcpy(s, buffer);
        joias[count++] = s;
    }

    if (count == 0) {
        printf("0\n");
        return 0;
    }

    /* ordena as strings */
    qsort(joias, count, sizeof(char *), cmp_str);

    /* conta quantas são distintas */
    int tipos = 1;
    for (int i = 1; i < count; i++) {
        if (strcmp(joias[i], joias[i - 1]) != 0) {
            tipos++;
        }
    }

    printf("%d\n", tipos);

    /* opcional: liberar memória
    for (int i = 0; i < count; i++) {
        free(joias[i]);
    }
    */

    return 0;
}
