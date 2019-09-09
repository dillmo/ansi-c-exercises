#include <stdio.h>

enum states { NORMAL, COMMENT, SINGLE_QUOTE, DOUBLE_QUOTE, ESCAPED_SINGLE,
              ESCAPED_DOUBLE, SLASHED, UNSLASHED };

int main() {
    int c;
    int state;
    int parens, brackets, braces;

    state = NORMAL;
    parens = brackets = braces = 0;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case NORMAL:
                if (c == '(') {
                    ++parens;
                } else if (c == ')') {
                    --parens;
                } else if (c == '[') {
                    ++brackets;
                } else if (c == ']') {
                    --brackets;
                } else if (c == '{') {
                    ++braces;
                } else if (c == '}') {
                    --braces;
                } else if (c == '\'') {
                    state = SINGLE_QUOTE;
                } else if (c == '"') {
                    state = DOUBLE_QUOTE;
                } else if (c == '/') {
                    state = SLASHED;
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
                break;
            case DOUBLE_QUOTE:
                if (c == '\\') {
                    state = ESCAPED_DOUBLE;
                } else if (c == '"') {
                    state = NORMAL;
                }
                break;
            case ESCAPED_SINGLE:
                state = SINGLE_QUOTE;
                break;
            case ESCAPED_DOUBLE:
                state = DOUBLE_QUOTE;
                break;
            case SLASHED:
                if (c == '*') {
                    state = COMMENT;
                } else {
                    state = NORMAL;
                }
                break;
            case UNSLASHED:
                if (c == '/') {
                    state = NORMAL;
                }
                break;
        }
    }
    if (parens > 0) {
        printf("Missing closing \").\"\n");
    } else if (parens < 0) {
        printf("Extra closing \").\"\n");
    }
    if (brackets > 0) {
        printf("Missing closing \"].\"\n");
    } else if (brackets < 0) {
        printf("Extra closing \"].\"\n");
    }
    if (braces > 0) {
        printf("Missing closing \"}.\"\n");
    } else if (braces < 0) {
        printf("Extra closing \"}.\"\n");
    }
    return 0;
}
