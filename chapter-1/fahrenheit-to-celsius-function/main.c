#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 13

/* return a formatted table using f(x) for each x in a range */
char *buildTable(int from, int to, int step, double (*f)(int x));
/* return the celsius equivalent to a fahrenheit temperature */
double fahrToC(int fahr);

int main() {
    char *table;

    table = buildTable(0, 300, 20, fahrToC);
    printf("  F      C\n");
    printf("%s", table);
    free(table);
    return 0;
}

double fahrToC(int fahr) {
    return (9.0 / 5.0) * fahr + 32.0;
}

char *buildTable(int from, int to, int step, double (*f)(int x)) {
    int i;
    char formatted[LINE_LENGTH];
    char *table;

    table = (char *) malloc((LINE_LENGTH - 1) * (to - from) / step + 1);
    table[0] = '\0';
    for (i = from; i <= to; i = i + step) {
        sprintf(formatted, "%3d %6.1f\n", i, f(i));
        strcat(table, formatted);
    }
    return table;
}
