//LCS algorithm

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int length = L[m][n];
    char lcs[length + 1];
    lcs[length] = '\0'; 
    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1];
            i--;
            j--;
            length--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[MAX_LEN], Y[MAX_LEN];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}
        

