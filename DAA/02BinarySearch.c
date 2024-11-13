#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, left = 0, right = size - 1, mid, found = 0;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    while (left <= right) {
        mid = (left + right ) / 2;

        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}
