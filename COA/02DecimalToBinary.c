#include <stdio.h>

int main() {
    int decimal;
    int binary = 0;
    int remainder, base = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    printf("Binary equivalent: %d\n", binary);

    return 0;
}
