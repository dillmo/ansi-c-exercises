#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len;                /* current line length */
    int max;                /* maximum line length */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {  /* there was a line */
        printf("%s", longest);
    }
    return 0;
}

/* read a line into s, return length */
int getline(char s[], int lim) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[i] = c;
        }
    }
    if (c == '\n') {
        if (i < lim - 1) {
            s[i] = c;
        }
        ++i;
    }
    s[i < lim ? i : lim - 1] = '\0';
    return i;
}

/* copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    for (i = 0; (to[i] = from[i]) != '\0'; ++i)
        ;
}
