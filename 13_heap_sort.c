#include <stdio.h>

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void buildHeap(int arr[], int n);

int main() {
    int i, arr[100], n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    buildHeap(arr, n);
    heapSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i, temp;
    for (i = n - 1; i > 0; i--) {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void buildHeap(int arr[], int n) {
	int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}


