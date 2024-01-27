#include <stdio.h>

int main() {
    int num, count = 0;
    int result = 1;

    printf("Enter a number: ");
    scanf("%d", &num);
    count += 6;  // For function entry and scanf

    for (int i = 1; i <= num; ++i) {
        result *= i;
        count += 4;  
    }

    printf("Factorial of %d: %d\n", num, result);
    count += 3;  
    printf("Total NO. of steps: %d\n", count);

    return 0;
}

