#include <stdio.h>
#define TABSTOP 4

int main() {
    int c, i, j;

    for(i = 0; (c = getchar()) != EOF; i = c == '\n' ? 0 : i + 1) {
        if (c == '\t') {
            for (j = i % TABSTOP; j < TABSTOP; ++j) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
