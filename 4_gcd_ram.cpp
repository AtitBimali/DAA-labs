#include <stdio.h>

int main() {
    int num1, num2, count = 0;

    // Input two numbers from the user
    printf("Enter first number: ");
    scanf("%d", &num1);
    count+=4;

    printf("Enter second number: ");
    scanf("%d", &num2);
	count+=3;
    // Ensure both numbers are positive
    if (num1 < 0 || num2 < 0) {
        printf("Please enter positive numbers.\n");
        count+=3;
        return 1; // Exit the program with an error code
    }

    // Iterative GCD algorithm with count variable
    while (num1 != num2) {
        count++; // Increment count for each step
		count+=2;
		if (num1 > num2) {
            num1 = num1 - num2;
        } else {
            num2 = num2 - num1;
        }
    }

    // Output the GCD and count
    printf("GCD: %d\n", num1);
    count+=2;
    printf("Number of steps: %d\n", count);

    return 0; // Exit the program successfully
}

