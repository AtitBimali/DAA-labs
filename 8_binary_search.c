#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    int mid, result = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            result = mid;
            break;
        } else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return result;
}

int main() {
    int n, arr[100], key, left = 0, right, result = -1, i;
    
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in ascending order:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    right = n - 1;

    result = binarySearch(arr, left, right, key);

    if (result != 0)
        printf("Element %d is present at index %d.\n", key, result);
    else
        printf("Element %d is not present in the array.\n", key);

    return 0;
}

