#include <stdio.h>

#define MAX_LENGTH  30  /* maximum allowed word length */

/* print a histogram of the lengths of words in input */
int main() {
    int c, len;
    int i, j;
    int lengths[MAX_LENGTH];

    for (i = 0; i < MAX_LENGTH; ++i) {
        lengths[i] = 0;
    }

    len = 0;
    while ((c = getchar()) != EOF) {
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            ++len;
        } else {
            if (len > 0) {
                ++lengths[len];
                len = 0;
            }
        }
    }

    for (i = 0; i < MAX_LENGTH; ++i) {
        printf("%2d | ", i);
        for (j = 0; j < lengths[i]; ++j) {
            putchar('X');
        }
        putchar('\n');
    }

    return 0;
}