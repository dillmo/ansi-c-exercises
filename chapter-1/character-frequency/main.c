#include <stdio.h>

#define ASCII_CHARS 255 /* number of ASCII character codes */
#define FALSE       0
#define TRUE        1

/* print a histogram of the frequencies of different characters */
int main() {
    int c;
    int i, j;
    int didNewline;
    int chars[ASCII_CHARS];

    for (i = 0; i < ASCII_CHARS; ++i) {
        chars[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (0 <= c && c < ASCII_CHARS) {
            ++chars[c];
        }
    }

    didNewline = FALSE;
    for (i = 0; i < ASCII_CHARS; ++i) {
        if (chars[i] > 0) {
            if (i == ' ') {
                printf("' ' |");
            } else if (i == '\t') {
                printf("\\t  |");
            } else if (i == '\n') {
                printf("\\n  |");
            } else {
                printf("%c   |", i);
            }
            for (j = 0; j < chars[i]; ++j) {
                putchar('X');
            }
            putchar('\n');
            didNewline = TRUE;
        }
    }

    if (!didNewline) {
        putchar('\n');
    }

    return 0;
}
