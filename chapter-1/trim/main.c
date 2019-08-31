#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 1024

/* return the next line of input without '\n', or NULL if there is none */
char *getLine();
/* return line without trailing spaces or tabs */
char *removeTrailing(char *line);

int main() {
    char *line, *trimmedLine;

    while ((line = getLine()) != NULL) {
        if (strlen(line) > 0) {
            trimmedLine = removeTrailing(line);
            free(line);
            printf("%s\n", trimmedLine);
            free(trimmedLine);
        }
    }
    return 0;
}

char *getLine() {
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

char *removeTrailing(char *line) {
    int i;
    char *buffer;

    for (i = strlen(line); line[i - 1] == ' ' || line[i - 1] == '\t'; --i)
        ;
    buffer = malloc(i + 1);
    strncpy(buffer, line, i + 1);
    return buffer;
}
