#include <stdio.h>
#define MAX_ITEMS 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int capacity, int weights[], int values[], int no_items) {
    int i, w;
    int dp[no_items + 1][capacity + 1];

    for (i = 0; i <= no_items; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int result = dp[no_items][capacity];
    
    printf("\n\nMaximum value in knapsack: %d\n", result);

    int included[MAX_ITEMS];
    for (i = no_items, w = capacity; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            included[i - 1] = 1;
            w -= weights[i - 1];
        } else {
            included[i - 1] = 0;
        }
    }

    // Display the selected items
    printf("\n\nSelected items:\n");
    for (i = 0; i < no_items; i++) {
        if (included[i]) {
            printf("Item %d - Weight: %d, Value: %d\n", i + 1, weights[i], values[i]);
        }
    }
}

int main() {
    int capacity, no_items, i;

    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    int weights[MAX_ITEMS], values[MAX_ITEMS];

    printf("Enter the weight and value of %d items:\n", no_items);
    for (i = 0; i < no_items; i++) {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weights[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &values[i]);
    }

    knapsack(capacity, weights, values, no_items);

    return 0;
}

