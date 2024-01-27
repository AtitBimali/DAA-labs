#include <stdio.h>
int pivot, left, right, arr[100], n;

int partition(int arr[], int left, int right) {
	
	int i, j, temp;
    pivot = arr[right];
    i = left - 1;

    for (j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;

}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        pivot = partition(arr, left, right);

        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
	int i;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}

