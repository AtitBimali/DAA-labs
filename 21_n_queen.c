//N-Queen problem 

#include <stdio.h>
#include <stdbool.h>

#define N 4 // size of chessboard

void printSolution(int board[N][N]) {
	int i, j;
    static int solutionCount = 0;
    printf("Solution %d:\n", ++solutionCount);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
	int i;
    if (col >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            res = solveNQUtil(board, col + 1) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

bool solveNQ() {
    int board[N][N] = {0};

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    return true;
}

int main() {
    solveNQ();
    return 0;
}


