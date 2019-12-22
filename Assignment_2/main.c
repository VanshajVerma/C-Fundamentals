#include "calc.c"
#include <stdio.h>
#include <string.h>
#define N 80

char a[N], b[N], res[N + 1];
int main() {

  char op;
  scanf("%s %s %c", a, b, &op);
  switch (op) {
  case '+':
    add(a, b, res);
    break;
  case '-':
    sub(a, b, res);
  }

  char buf[20];
  int l1 = strlen(a), l2 = strlen(b), l3 = strlen(res);
  int m = l1 > l2 ? l1 : l2;
  m = m > l3 ? m : l3;
  sprintf(buf, "%% %ds\n%% %ds\n%% %ds\n", m, m, m);
  printf(buf, a, b, res);
}