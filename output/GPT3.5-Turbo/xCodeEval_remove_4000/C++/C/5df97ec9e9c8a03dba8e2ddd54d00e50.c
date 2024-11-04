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
  for (int i = 0; i < bl; ++i) {
    sum += block[i];
  }

  for (int i = max(5, bl * 100000 + 1); i <= n; i += 4) {
    if (is_prime(i)) {
      sum++;
    }
  }
  return sum;
}

int main() {
  int i, j, nr = 1;
  int n = 300000000-1;

  int l, r;
  scanf("%d %d", &l, &r);
  int total = f(r) - f(l - 1);

  printf("%d\n", total);
  return 0;
}
