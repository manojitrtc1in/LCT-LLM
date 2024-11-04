#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXL 301000000
#define LEN 100000

bool p[20000];
int pp[20000];

int get(int l, int r) {
  int ans = 0;
  for (int i = l; i <= r; ++i) {
    bool flag = true;
    for (int j = 0; j < sizeof(pp) / sizeof(pp[0]) && pp[j]*pp[j] <= i; ++j)
      if (i % pp[j] == 0) {
        flag = false;
        break;
      }
    if (flag) {
      bool f2 = false;
      for (int f = 1; f*f + f*f <= i; ++f) {
        int s = sqrt(i-f*f);
        if (s*s + f*f == i || (s+1)*(s+1) + f*f == i) {
          f2 = true;
          break;
        }
      }
      if (f2)
        ++ans;
    }
  }
  return ans;
}

int main() {
  memset(p, true, sizeof(p));
  int count = 0;
  for (int i = 2; i < 20000; ++i) {
    if (p[i]) {
      pp[count] = i;
      int j = i+i;
      while (j < 20000) {
        p[j] = false;
        j += i;
      }
      count++;
    }
  }
  
  int l, r;
  int ans = 0, cl = 0, ul = 0;
  scanf("%d %d", &l, &r);
  while (l > cl) {
    ++ul;
    cl += LEN;
  }
  if (cl <= r)
    ans += get(l, cl-1);
  else
    ans += get(l, r);
  while (cl+LEN-1 <= r) {
    ans += pr[ul];
    cl += LEN;
    ++ul;
  }
  
  ans += get(cl, r);

  printf("%d\n", ans);
  
  return 0;
}
