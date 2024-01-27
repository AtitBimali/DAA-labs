#include <stdio.h>

void merge(int arr[], int B[], int left, int mid, int right);
void mergeSort(int arr[], int B[], int left, int right);

int main() {
    int i;
    int arr[100], B[100], n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, B, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}

void merge(int arr[], int B[], int left, int mid, int right) {
    int x, y, k, i;
    x = left;
    y = mid + 1;
    k = left;

    while (x <= mid && y <= right) {
        if (arr[x] < arr[y]) {
            B[k] = arr[x];
            k++;
            x++;
        } else {
            B[k] = arr[y];
            k++;
            y++;
        }
    }

    while (x <= mid) {
        B[k] = arr[x];
        k++;
        x++;
    }
    while (y <= right) {
        B[k] = arr[y];
        k++;
        y++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = B[i];
    }
}

void mergeSort(int arr[], int B[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, B, left, mid);
        mergeSort(arr, B, mid + 1, right);
        merge(arr, B, left, mid, right);
    }
}

