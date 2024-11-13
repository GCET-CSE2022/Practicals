#include <stdio.h>
#include <math.h>

int main() {
    int octal, decimal = 0, base = 0, remainder;

    printf("Enter an octal number: ");
    scanf("%d", &octal);

    while (octal > 0) {
        remainder = octal % 10;
        decimal += remainder * pow(8, base);
        octal /= 10;
        base++;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
