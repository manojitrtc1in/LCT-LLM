#include <stdio.h>

typedef long long LL;

int is_prime(int x) {
  for (LL i = 3; i * i <= x; i+=2) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int f(int n) {
  if (n <= 1) {
    return 0;
  }
  if (n <= 4) {
    return 1;
  }
  int sum = 1;
  int bl = n / 100000;
  int block[] = {
