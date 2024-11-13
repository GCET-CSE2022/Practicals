#include <stdio.h>
#include <math.h>

int hexToDecimal(char hex[]) {
    int length = 0;
    while (hex[length] != '\0') {
        length++;
    }
    int decimal = 0;
    for (int i = 0; i < length; i++) {
        int value;
        if (hex[i] >= '0' && hex[i] <= '9') {
            value = hex[i] - '0';  // Convert '0'-'9' to 0-9
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            value = hex[i] - 'A' + 10;  // Convert 'A'-'F' to 10-15
        }
        decimal += value * pow(16, length - i - 1);
    }

    return decimal;
}

int main() {
    char hex[32];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal = hexToDecimal(hex);
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
