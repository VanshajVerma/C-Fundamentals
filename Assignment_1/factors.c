/*
program : factors.c
Author : Vanshaj Verma
*/
#include <stdio.h>

int main() {

  // Declaring variables
  unsigned int a, b;
  unsigned long int small_no, i;
  unsigned long int max = 0;
  unsigned long int sum = 0;
  unsigned long int lcm = 0;

  // Taking input
  printf("Enter two positive integers: ");
  scanf("%u %u", &a, &b);

  printf("Common factors of (%u, %u): ", a, b);

  // Finding the smaller number, to make the loop smaller and quicker.
  if (a <= b) {
    small_no = a;
  } else if (b < a) {
    small_no = b;
  }

  // For loop to go through the common factors and finding the GCF and SUM
  for (i = 1; i <= small_no; i++) {
    if ((unsigned long int)b % i == 0 && (unsigned long int)a % i == 0) {
      printf("%lu ", i);
      sum += i;
      if (i > max) {
        max = i;
      }
    }
  }

  // Calculations to compute LCM and SUM
  lcm = ((unsigned long int)a * (unsigned long int)b) / max;
  sum += lcm + max;

  // Printing out the values
  printf("\n");
  printf("GCF: %lu\n", max);
  printf("LCM: %lu\n", lcm);
  printf("sum: %lu\n", sum);
  return 0;
}