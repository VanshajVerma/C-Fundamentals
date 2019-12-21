/*
program : staircase2.c
Author : Vanshaj Verma
*/
#include <stdio.h>

int main() {

  // Defining the variables
  unsigned int staircases, stairs, rows;

  // Taking input of the values
  printf("Enter number of: staircases, stairs, rows: ");
  scanf("%u %u %u", &staircases, &stairs, &rows);

  // some more variables required for the efficiency of the code
  unsigned int n = staircases, m = stairs, p = rows;
  int i, x, y;

  // Conditional statements to make sure the input
  // is in the required range
  if (1 <= n && n <= 100 && 1 <= m && m <= 9 && 1 <= p && p <= 100) {

    // Loop for printing the rows according to the value of staircases
    while (n >= p) {

      m = stairs;

      // Loop for printing the stairs pattern
      while (m) {

        for (i = 0; i < p; i++) {

          for (x = 0; x < m - 1; x++) {
            printf(" ");
          }

          for (y = m; y <= stairs; y++) {
            printf("%u", stairs);
          }

          printf(" ");
        }
        m -= 1;
        printf("\n");
      }

      n -= p;
    }

    m = stairs;

    if (n > 0) {
      // similar loop as above but for the remaining values
      while (m) {

        for (i = 0; i < n; i++) {

          for (x = 0; x < m - 1; x++) {
            printf(" ");
          }

          for (y = m; y <= stairs; y++) {
            printf("%u", stairs);
          }

          printf(" ");
        }
        m -= 1;
        printf("\n");
      }
    }
  }

  // required code for input being out of range
  else {
    if (n < 1 || n > 100) {
      printf("n=%u, must be in [1,100]\n", n);
    }

    if (m < 1 || m > 9) {
      printf("m=%u, must be in [1,9]\n", m);
    }

    if (p < 1 || p > 100) {
      printf("p=%u, must be in [1,100]\n", p);
    }
    printf("\n");
  }

  return 0;
}