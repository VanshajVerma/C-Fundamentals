/*
program : reverse_long.c
Author : Vanshaj Verma
*/
#include <stdio.h>

int main() {

  // Defining the variable
  unsigned long int a, digit;

  // Taking the input
  printf("Enter an integer: ");
  scanf("%lu", &a);

  // While loop to print the input in reverse
  while (a > 0) {
    digit = a % 10;
    printf("%lu", digit);
    a /= 10;
  }
  printf("\n");
  return 0;
}