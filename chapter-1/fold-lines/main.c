#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 1024
#define MAX_LINE 80

/* Return a line of input, sans \n. Returns NULL if no input. */
char* getLine();

int main() {
    char* line;
    int i, c, length, start;

    while ((line = getLine()) != NULL) {
        start = 0;
        length = strlen(line);
        while (length - start > MAX_LINE) {
            /* look backwards for whitespace */
            for (i = start + 80; i > start && (c = line[i]) != ' ' && c != '\t'; --i)
                ;
            if (i > start) {
                line[i] = '\n';
            } else {
                /* look forwards for whitespace */
                for (i = start + 81; i < length && (c = line[i]) != ' ' && c != '\t'; ++i)
                    ;
                if (i < length) {
                    line[i] = '\n';
                }
                /* otherwise give up */
            }
            if (line[i] == '\n') {
                start = i;
            } else {
                break;
            }
        }

        printf("%s\n", line);
    }

    return 0;
}

char* getLine() {
    int c, i, blocks;
    char* buffer;

    /* get the line string sans \0 */
    buffer = malloc(BLOCK_SIZE);
    blocks = 1;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i >= BLOCK_SIZE) {
            buffer = realloc(buffer, ++blocks * BLOCK_SIZE);
        }
        buffer[i] = c;
    }

    /* return null if no line */
    if (c == EOF && i == 0) {
        return NULL;
    }

    /* trim the buffer */
    buffer = realloc(buffer, i + 1);

    /* append \0 */
    buffer[i] = '\0';

    return buffer;
}
