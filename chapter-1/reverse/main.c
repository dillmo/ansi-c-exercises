#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 1024

/* return a reversed copy of s */
char *reverse(char *s);
/* return the next line of input without '\n', or NULL if there is none */
char *getLine(void);

int main() {
    char *line, *reversed;

    while ((line = getLine()) != NULL) {
        reversed = reverse(line);
        free(line);
        printf("%s\n", reversed);
        free(reversed);
    }
    return 0;
}

char *reverse(char *s) {
    char *buffer;
    int i, length;

    length = strlen(s);
    buffer = malloc(length + 1);
    for (i = 0; i < length; ++i) {
        buffer[i] = s[length - 1 - i];
    }
    buffer[i] = '\0';
    return buffer;
}

char *getLine(void) {
    char *buffer;
    int blocks, i, c;

    buffer = malloc(BLOCK_SIZE);
    blocks = 1;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i >= blocks * BLOCK_SIZE - 1) {
            buffer = realloc(buffer, ++blocks * BLOCK_SIZE);
        }
        buffer[i] = c;
    }
    if (!i && c == EOF) {
        free(buffer);
        return NULL;
    }
    buffer[i] = '\0';
    return buffer;
}
