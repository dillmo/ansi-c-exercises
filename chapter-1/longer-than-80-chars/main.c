#include <stdio.h>
#define MAX_LENGTH  4096
#define LIMIT       80

/* copy a line to s, return length */
int getLine(char s[], int max);

int main() {
    char line[MAX_LENGTH];
    int length;

    while ((length = getLine(line, MAX_LENGTH)) > 0) {
        if (length > LIMIT) {
            printf(line);
        }
    }
    return 0;
}

int getLine(char s[], int max) {
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < max - 1) {
            s[i] = c;
        }
    }
    if (c == '\n') {
        if (i < max - 1) {
            s[i] = c;
        }
        ++i;
    }
    s[i < max ? i : max - 1] = '\0';
    return i;
}
