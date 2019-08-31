#include <stdio.h>

int main() {
    int c, wasBlank, isBlank;

    wasBlank = 0;

    while ((c = getchar()) != EOF) {
        isBlank = c == ' ';
        if (!wasBlank || !isBlank) {
            putchar(c);
        }
        wasBlank = isBlank;
    }

    return 0;
}
