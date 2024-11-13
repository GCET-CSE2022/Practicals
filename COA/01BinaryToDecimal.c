#include <stdio.h>
#include <math.h>

int main() {
    int binary, decimal = 0, base = 1, remainder;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while (binary > 0) {
        remainder = binary % 10;
        decimal += remainder * base;
        binary /= 10;
        base *= 2;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
