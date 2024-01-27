#include <stdio.h>

struct MinMaxPair {
    int min;
    int max;
};

struct MinMaxPair MinMax(int a[], int l, int r) {
    struct MinMaxPair result;
    int mid;

    if (l == r) {
        result.min = result.max = a[l];
    }
	else if (l == r - 1) {
        if (a[l] < a[r]) {
            result.min = a[l];
            result.max = a[r];
        } else {
            result.min = a[r];
            result.max = a[l];
        }
    }
	else {
    	mid = (l + r) / 2;
        struct MinMaxPair leftPair = MinMax(a, l, mid);
        struct MinMaxPair rightPair = MinMax(a, mid + 1, r);

       	if(leftPair.min < rightPair.min)
		    result.min = leftPair.min;
		else
		    result.min = rightPair.min;
		
		if (leftPair.max > rightPair.max)
		    result.max = leftPair.max;
		else
		    result.max = rightPair.max;
    }

    return result;
}

int main() {
    int n, arr[100], i, l, r;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    l = 0;
    r = n - 1;

    struct MinMaxPair result = MinMax(arr, l, r);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);

    return 0;
}

