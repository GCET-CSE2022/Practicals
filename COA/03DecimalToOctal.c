#include <stdio.h>

int main() {
    int decimal;
    long long octal = 0;
    int remainder, base = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while (decimal > 0) {
        remainder = decimal % 8;
        octal += remainder * base;
        decimal /= 8;
        base *= 10;
    }

    printf("Octal equivalent: %lld\n", octal);

    return 0;
}
