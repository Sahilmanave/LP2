#include <iostream>
using namespace std;

#define MAX 20
int board[MAX][MAX];

// Function to print the board
void printBoard(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Check if a queen can be placed safely
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check left side of the current row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal
    for (i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Backtracking function
bool solveNQueens(int col, int n) {
    if (col >= n)
        return true; // all queens placed

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1; // place queen

            if (solveNQueens(col + 1, n))
                return true;

            board[i][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    int n, row;
    cout << "Enter the size of board (N): ";
    cin >> n;

    // Initialize board with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    cout << "Enter row number (0 to " << n - 1 << ") for first queen in column 0: ";
    cin >> row;

    // Place first queen
    board[row][0] = 1;

    // Solve for remaining queens
    if (solveNQueens(1, n))
        printBoard(n);
    else
        cout << "No solution exists for " << n << " queens." << endl;

    return 0;
}
