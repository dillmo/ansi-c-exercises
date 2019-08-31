#include <stdio.h>

int main() {
    double blanks, tabs, newlines;
    int c;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
        }
        if (c == '\t') {
            ++tabs;
        }
        if (c == '\n') {
            ++newlines;
        }
    }
    printf("%.0f blanks, %.0f tabs, and %.0f newlines", blanks, tabs, newlines);

    return 0;
}
