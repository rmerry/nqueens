/*
 * Title:  n-queens
 * Author: Richard Merry
 * Date:   01/04/2018
 *
 * A demonstration of an algorithm for solving the N Queens Problem
 * using backgracking
 *
 * N Queens Problem: https://en.wikipedia.org/wiki/N_queens_problem
 * Backtracking:     https://en.wikipedia.org/wiki/Backtracking
 */

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

void nqueens(int r, int n, int * count, bool cols[], bool diag1[], bool diag2[]);

int main(int argc, char * argv[]) {
  if (argc == 1) return 1;

  int count = 0;
  int n = atoi(argv[1]);
  bool cols[n], diag1[2*(n-1)+1], diag2[2*(n-1)+1];

  fill_n(cols, n, false);
  fill_n(diag1, 2*(n-1)+1, false);
  fill_n(diag2, 2*(n-1)+1, false);

  nqueens(0, n, &count, cols, diag1, diag2);

  cout << count << endl;

  return 0;
}

/**
 * Recursive n-queens backtracking algorithm; this implementation has space
 * complexity of O(n) while having time complexity of O(n^2).
 */
void nqueens(int r, int n, int * count, bool cols[], bool diag1[], bool diag2[]) {
  // if we have reached the nth row we have placed a queen
  // on every row, i.e., found a valid configuration
  if (r == n) {
    *count += 1;
    return;
  }

  // loop through each column of this row
  for (int c = 0; c < n; c++) {
    // if there is already a queen on this column and/or diagonal(s), skip
    if (cols[c] || diag1[c+r] || diag2[c-r+n-1]) continue;

    // place the queen on the column and both diagonals
    cols[c] = diag1[r+c] = diag2[c-r+n-1] = true;
    nqueens(r + 1, n, count, cols, diag1, diag2);

    // backtrack! remove the queen from the column and both diagonals
    cols[c] = diag1[r+c] = diag2[c-r+n-1] = false;
  }
}
