#include <stdio.h>
#include <stdlib.h>
void Convert(int n)
{
    int rem, i = 0;
    char *arr = (char *)calloc(1, sizeof(char));
    while (n != 0)
    {

        rem = n % 16;
        if (rem < 10)
        {
            rem += '0';
        }
        else
        {
            rem += ('A' - 10);
        }
        arr[i] = rem;
        arr = (char *)realloc(arr, i + 1);
        i++;
        n = n / 16;
    }
    printf("The Hexadecimal Number is: ");
    for (i; i >= 0; i--)
    {
        printf("%c", arr[i]);
    }
}

int main()
{
    int num;
    printf("Enter The Decimal Number: ");
    scanf("%d", &num);
    Convert(num);
}