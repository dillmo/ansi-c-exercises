#include <stdio.h>
#define TABSTOP 4

int main() {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++i;
        } else {
            while (i > 0) {
                if (i >= TABSTOP) {
                    i = i - TABSTOP;
                    putchar('\t');
                } else {
                    --i;
                    putchar(' ');
                }
            }
            putchar(c);
        }
    }

    return 0;
}
