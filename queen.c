#include <stdio.h>
#include <stdlib.h>

#define size 8

void attack(int board[][size], int row, int col) {
    board[row][col] = 10; // Place queen

    // Row
    for (int j = 0; j < size; j++)
        if (board[row][j] != 10)
            board[row][j] = 1;

    // Column
    for (int i = 0; i < size; i++)
        if (board[i][col] != 10)
            board[i][col] = 1;

    // ↖
    for (int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
        if (board[i][j] != 10)
            board[i][j] = 1;

    // ↘
    for (int i = row+1, j = col+1; i<size && j<size; i++, j++)
        if (board[i][j] != 10)
            board[i][j] = 1;

    // ↗
    for (int i = row-1, j = col+1; i>=0 && j<size; i--, j++)
        if (board[i][j] != 10)
            board[i][j] = 1;

    // ↙
    for (int i = row+1, j = col-1; i<size && j>=0; i++, j--)
        if (board[i][j] != 10)
            board[i][j] = 1;
}

int elimination(int row, int col) {
    int count = 0;

    count += size;       // row
    count += size - 1;   // column

    // ↖
    for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
        count++;

    // ↘
    for (int i=row+1, j=col+1; i<size && j<size; i++, j++)
        count++;

    // ↗
    for (int i=row-1, j=col+1; i>=0 && j<size; i--, j++)
        count++;

    // ↙
    for (int i=row+1, j=col-1; i<size && j>=0; i++, j--)
        count++;

    return count;
}

int main() {
    int chess[size][size] = {0};
    int access[size][size];
    int queens = 0;

    while (1) {
        // Recompute access[][] each time
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                access[i][j] = elimination(i, j);

        int minAccess = 9999;
        int bestR = -1, bestC = -1;

        // Find the cell with MINIMUM access that is EMPTY (== 0)
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (chess[i][j] == 0) {
                    if (access[i][j] < minAccess) {
                        minAccess = access[i][j];
                        bestR = i;
                        bestC = j;
                    }
                }

            }
        }

        // If no valid cell found → stop
        if (bestR == -1)
            break;

        // Place queen
        attack(chess, bestR, bestC);
        queens++;
    }

    printf("\nTotal queens placed = %d\n\n", queens);

    // Print final board
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%4d", chess[i][j]);
        printf("\n");
    }

    return 0;
}