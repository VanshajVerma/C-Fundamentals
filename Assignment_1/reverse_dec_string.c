/*
program : reverse_dec_string.c
Author : Vanshaj Verma
*/
#include <stdio.h>
#define A " "

int main() {

  // Defining variables
  char dec_str[100];
  int a = 0, b = 0, i;

  // Taking inputs as string
  printf("Enter a decimal string: ");
  scanf("%s", &dec_str[0]);

  // Loop to find the ommiting point of zeros from front
  for (i = 0; i <= 19; i++) {
    if (dec_str[i] > '0') {
      a = i;
      break;
    }
  }

  // Loop to find the omitting point of zeros from rear
  for (i = 19; i >= 0; i--) {
    if (dec_str[i] > '0') {
      b = i;
      break;
    }
  }

  // Conditional statement to check if the input is not all zeros
  if (a != b) {
    for (i = b; i >= a; i--) {
      printf("%c", dec_str[i]);
    }
  }
  // if it is all zeros
  else {
    printf(A);
  }
  printf("\n");

  return 0;
}