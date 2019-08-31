#include<stdio.h>

#define OUT 0 /* not in a word */
#define IN  1 /* in a word */

int main() {
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            state = IN;
            putchar(c);
        } else {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        }
    }

    return 0;
}
