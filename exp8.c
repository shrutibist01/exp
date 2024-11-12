// n queen problem

#include <stdbool.h>
#include <stdio.h>
// five functions, three bool functions
#define N 4

void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

bool isSafe(int board[N][N], int row, int col) {
  int i, j;

  for (i = 0; i < row; i++) {
    if (board[i][col] == 1)
      return false;
  }

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 1)
      return false;
  }

  for (i = row, j = col; i >= 0 && j < N; i--, j++) {
    if (board[i][j] == 1)
      return false;
  }

  return true;
}

bool solveNQueensUntil(int board[N][N], int row) {
  if (row >= N)
    return true;

  for (int col = 0; col < N; col++) {
    if (isSafe(board, row, col)) {
      board[row][col] = 1;

      if (solveNQueensUntil(board, row + 1))
        return true;

      board[row][col] = 0;
    }
  }
  return false;
}
bool solveNQueens() {
  int board[N][N] = {{0}};

  if (!solveNQueensUntil(board, 0)) {
    printf("No solution exists\n");
    return false;
  }
  printBoard(board);
  return true;
}

int main() {
  solveNQueens();
  return 0;
}