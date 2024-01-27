#include <stdio.h>

int fibonacci(int n, int *count) {
    if (n <= 1) {
        (*count) += 3;  // For function entry, comparison, and return statement
        return n;
    } else {
        (*count) += 4;  // For function entry, assignment, and comparison

        int fib = 0;
        int a = 0, b = 1;

        for (int i = 2; i <= n; i++) {
            (*count) += 7;  // For loop condition, assignment, and addition
            fib = a + b;
            a = b;
            b = fib;
        }

        return fib;
    }
}

int main() {
    int terms, count = 0;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &terms);
    count += 4;  // For function entry, assignment, and scanf

    printf("Fibonacci series:\n");
    for (int i = 0; i < terms; i++) {
        count += 5;  // For loop condition, assignment, and printf
        printf("%d ", fibonacci(i, &count));
    }

    printf("\nTotal NO. of steps: %d\n", count);

    return 0;
}

