#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, found = 0;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (found==0) {
        printf("Element not found\n");
    }

    return 0;
}
