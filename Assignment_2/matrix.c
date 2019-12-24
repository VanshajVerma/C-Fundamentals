/*
program : matrix.c.c
Author : Vanshaj Verma
*/

#include <stdio.h>
#include <stdlib.h>

int is_same_diagonals(int n, int a[]) {

  // Conversion from 1d to 2d array matrix
  int A[n][n];
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = a[count++];
    }
  }

  // Comparing values of the left side of the main diagonal
  for (int i = 0; i < n - 1; i++) {
    int j = 0;
    int i2 = i;

    while (i2 != n - 1 && j != n - 1) {
      if (A[i2][j] == A[i2 + 1][j + 1]) {
        i2++;
        j++;
        continue;
      } else {
        return 0;
      }
    }
  }

  // Comparing values of the right side of the main diagonal
  for (int j = 0; j < n - 1; j++) {
    int i = 0;
    int j2 = j;

    while (j2 != n - 1 && i != n - 1) {
      if (A[i][j2] == A[i + 1][j2 + 1]) {
        i++;
        j2++;
        continue;
      } else {
        return 0;
      }
    }
  }

  return 1;
}
