#include <stdio.h>

#define LOWER   0       /* lower limit of table */
#define UPPER   300     /* upper limit */
#define STEP    20      /* step size */

/* print Farenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main () {
    int fahr;

    printf("  F      C\n");

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }

    return 0;
}
