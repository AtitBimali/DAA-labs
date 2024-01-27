#include <stdio.h>

int main() {
    int size, target, count = 0,i;
    count++;

    // Input the array size from the user
    printf("Enter the size of the array: ");
    count++;
    scanf("%d", &size);
    count++;

    // Input array elements from the user
    int arr[size];
    printf("Enter %d elements for the array:\n", size);
    count++;
	count = count + size + 1;
	count = count + size;
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        count++;
    }

    // Input the target element to search
    printf("Enter the element to search: ");
    scanf("%d", &target);
    count+=2;

    // Sequential search algorithm with count variable
    count = count + size + 1;
	count = count + size;
    for (i = 0; i < size; i++) {
        count++; // Increment count for each comparison
        if (arr[i] == target) {
        	count+=2;
            printf("Element found at index %d\n", i);
            break; // Exit the loop if the element is found
        }
    }

    // If the loop completes and the element is not found
    if (i == size) {
    	count+=2;
        printf("Element not found in the array\n");
    }

    // Output the count
    count++;
    printf("Number of steps: %d\n", count);

    return 0; // Exit the program successfully
}

