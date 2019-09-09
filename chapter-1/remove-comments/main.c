#include <stdio.h>

enum booleans { FALSE, TRUE };
enum states { NORMAL, COMMENT, SINGLE_QUOTE, DOUBLE_QUOTE, ESCAPED_SINGLE,
              ESCAPED_DOUBLE, SLASHED, UNSLASHED };

int main() {
    int c;
    int state;

    state = NORMAL;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case NORMAL:
                if (c == '/') {
                    state = SLASHED;
                } else {
                    if (c == '\'') {
                        state = SINGLE_QUOTE;
                    } else if (c == '"') {
                        state = DOUBLE_QUOTE;
                    }
                    putchar(c);
                }
                break;
            case COMMENT:
                if (c == '*') {
                    state = UNSLASHED;
                }
                break;
            case SINGLE_QUOTE:
                if (c == '\\') {
                    state = ESCAPED_SINGLE;
                } else if (c == '\'') {
                    state = NORMAL;
                }
                putchar(c);
                break;
            case DOUBLE_QUOTE:
                if (c == '\\') {
                    state = ESCAPED_DOUBLE;
                } else if (c == '"') {
                    state = NORMAL;
                }
                putchar(c);
                break;
            case ESCAPED_SINGLE:
                state = SINGLE_QUOTE;
                putchar(c);
                break;
            case ESCAPED_DOUBLE:
                state = DOUBLE_QUOTE;
                putchar(c);
                break;
            case SLASHED:
                if (c == '*') {
                    state = COMMENT;
                } else {
                    state = NORMAL;
                    putchar('/');
                }
                break;
            case UNSLASHED:
                if (c == '/') {
                    state = NORMAL;
                }
                break;
        }
    }
    return 0;
}
