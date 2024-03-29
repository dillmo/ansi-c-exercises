#include <stdio.h>

int main() {
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 150;
    step = 10;

    printf("  C      F\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
