// A recursive solution for subset sum problem
 
#include <stdio.h>
#include <stdbool.h>
 
// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
 
    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
 
    // Else, check if sum can be obtained by any
    // of the following:
    // (a) including the last element
    // (b) excluding the last element
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
 
// Driver code

int main() {
    int n, i, target, set[100], selected[] = {0};

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    if (isSubsetSum(set, n, target) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;

    return 0;
}

