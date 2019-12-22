/*
program : calc.c
Author : Vanshaj Verma
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    ADD
*/

void add(const char a[], const char b[], char res[]) {

  // Defining Variables
  int max, min, carry = 0;

  int x = strlen(a);
  int y = strlen(b);

  if (x >= y) {
    max = x;
    min = y;
  } else {
    max = y;
    min = x;
  }

  // Adding the same amount of numbers
  for (int i = 0; i < min; i++) {
    int m = a[x - i - 1] - '0';
    int n = b[y - i - 1] - '0';

    int ans = m + n + carry;

    carry = 0;

    if (ans > 9) {
      ans = ans % 10;
      carry = 1;
    }

    char cans = ans + '0';

    res[max - i - 1] = cans;
  }

  // if first number is larger than the other
  if (x > y) {

    for (int i = max - min - 1; i >= 0; i--) {
      int result = 0;
      result = a[i] - '0' + carry;

      if (result > 9) {
        result = result % 10;
        carry = 1;
      } else {
        carry = 0;
      }
      res[i] = result + '0';
    }

  }

  // if the other number is larger than the first
  else {

    for (int i = max - min - 1; i >= 0; i--) {
      int result = 0;
      result = b[i] - '0' + carry;

      if (result > 9) {
        result = result % 10;
        carry = 1;
      } else {
        carry = 0;
      }
      res[i] = result + '0';
    }
  }

  // eliminating if there are any zeros before
  int start_pt = 0;
  for (int i = 0; i <= max; i++) {
    if (res[i] > '0') {
      start_pt = i;
      break;
    }
  }

  // aligning the output to ignore the zeros preceding the number
  for (int i = 0; i <= max; i++) {
    res[i] = res[i + start_pt];
  }

  // incase there are any carry forwards
  if (carry == 1) {
    for (int i = max; i >= 0; i--) {
      res[i] = res[i - 1];
    }
    res[0] = '1';
    carry = 0;
  }
}

/*
    SUB
*/

void sub(const char a[], const char b[], char res[]) {

  // Defining the variables
  int max, min;

  int x = strlen(a);
  int y = strlen(b);
  int borrow = 0;

  if (x >= y) {
    max = x;
    min = y;
  } else {
    max = y;
    min = x;
  }

  // if the number of digits are the same
  if (x == y) {
    borrow = 0;

    int i = 0;
    int j = 0;

  repeat_loop_1:

    // First number is greater
    if (a[i] > b[j]) {
      for (int i = 0; i < max; i++) {
        int m = a[x - i - 1] - '0';
        int n = b[y - i - 1] - '0';
        int ans = 0;

        if (m - borrow >= n) {
          ans = m - n - borrow;
          borrow = 0;
        } else {
          ans = 10 + m - n - borrow;
          borrow = 1;
        }

        char cans = ans + '0';

        res[max - i - 1] = cans;
      }

      int start_pt = 0;
      for (int i = 0; i <= max; i++) {
        if (res[i] > '0') {
          start_pt = i;
          break;
        }
      }

      for (int i = 0; i <= max; i++) {
        res[i] = res[i + start_pt];
      }
    }

    // Second number is greater
    else if (a[i++] < b[j++]) {
      for (int i = 0; i < max; i++) {
        int m = a[x - i - 1] - '0';
        int n = b[y - i - 1] - '0';
        int ans = 0;

        if (n - borrow >= m) {
          ans = n - m - borrow;
          borrow = 0;
        } else {
          ans = 10 + n - m - borrow;
          borrow = 1;
        }

        char cans = ans + '0';

        res[max - i - 1] = cans;
      }

      int start_pt = 0;
      for (int i = 0; i <= max; i++) {
        if (res[i] > '0') {
          start_pt = i;
          break;
        }
      }

      for (int i = 0; i <= max; i++) {
        res[i] = res[i + start_pt];
      }

      for (int i = max; i >= 0; i--) {
        res[i] = res[i - 1];
      }
      res[0] = '-';

    } else {
      goto repeat_loop_1;
    }
  }

  // If the first number is greater than the other one
  else if (x > y) {
    borrow = 0;

    for (int i = 0; i < min; i++) {
      int m = a[x - i - 1] - '0';
      int n = b[y - i - 1] - '0';
      int ans = 0;

      if (m - borrow >= n) {
        ans = m - n - borrow;
        borrow = 0;
      } else {
        ans = 10 + m - n - borrow;
        borrow = 1;
      }

      char cans = ans + '0';

      res[max - i - 1] = cans;
    }

    for (int i = max - min - 1; i >= 0; i--) {
      if (a[i] == '0' && borrow == 1) {
        res[i] = '9';
      } else {
        res[i] = a[i] - borrow;
        borrow = 0;
      }
    }

    // to eliminate the zeros preceding the number
    int start_pt = 0;
    for (int i = 0; i <= max; i++) {
      if (res[i] > '0') {
        start_pt = i;
        break;
      }
    }

    for (int i = 0; i <= max; i++) {
      res[i] = res[i + start_pt];
    }
  }

  // If the second number is greater than the first one
  else {
    borrow = 0;
    for (int i = 0; i < min; i++) {
      int m = a[x - i - 1] - '0';
      int n = b[y - i - 1] - '0';
      int ans = 0;

      if (n - borrow >= m) {
        ans = n - m - borrow;
        borrow = 0;
      } else {
        ans = 10 + n - m - borrow;
        borrow = 1;
      }

      char cans = ans + '0';

      res[max - i - 1] = cans;
    }

    for (int i = max - min - 1; i >= 0; i--) {
      if (b[i] == '0' && borrow == 1) {
        res[i] = '9';
      } else {
        res[i] = b[i] - borrow;
        borrow = 0;
      }
    }

    int start_pt = 0;
    for (int i = 0; i <= max; i++) {
      if (res[i] > '0') {
        start_pt = i;
        break;
      }
    }

    for (int i = 0; i <= max; i++) {
      res[i] = res[i + start_pt];
    }

    for (int i = max; i >= 0; i--) {
      res[i] = res[i - 1];
    }
    res[0] = '-';
  }
}