#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007

typedef long long ll;

ll inverse(ll a, ll m) {
  ll u = 0, v = 1;
  while (a != 0) {
    ll t = m / a;
    m -= t * a; 
    ll temp = a;
    a = m;
    m = temp;
    u -= t * v; 
    temp = u;
    u = v;
    v = temp;
  }
  return u;
}

typedef struct {
  ll value;
} Modular;

Modular createModular(ll x) {
  Modular m;
  m.value = x % MOD;
  if (m.value < 0) {
    m.value += MOD;
  }
  return m;
}

Modular add(Modular a, Modular b) {
  return createModular((a.value + b.value) % MOD);
}

Modular subtract(Modular a, Modular b) {
  return createModular((a.value - b.value + MOD) % MOD);
}

Modular multiply(Modular a, Modular b) {
  return createModular((a.value * b.value) % MOD);
}

Modular divide(Modular a, Modular b) {
  return multiply(a, createModular(inverse(b.value, MOD)));
}

Modular power(Modular a, ll b) {
  Modular x = a, res = createModular(1);
  while (b > 0) {
    if (b & 1) {
      res = multiply(res, x);
    }
    x = multiply(x, x);
    b >>= 1;
  }
  return res;
}

bool isZero(Modular number) {
  return number.value == 0;
}

Modular dp[7];
Modular new_dp[7];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll m;
    scanf("%lld", &m);
    int len = 0;
    while (m > 0) {
      d[len++] = (m & 1);
      m >>= 1;
    }
    for (int i = 0; i <= 6; i++) {
      dp[i] = new_dp[i] = createModular(0);
    }
    dp[0] = createModular(1);
    for (int it = len - 1; it >= 0; it--) {
      if (d[it] == 0) {
        new_dp[0] = add(add(add(dp[0], dp[1]), dp[2]), dp[3]);
        new_dp[1] = new_dp[2] = add(add(add(dp[1], dp[2]), dp[3]), dp[4]);
        new_dp[3] = new_dp[4] = add(add(add(dp[2], dp[3]), dp[4]), dp[5]);
        new_dp[5] = new_dp[6] = add(add(add(dp[3], dp[4]), dp[5]), dp[6]);
      } else {
        new_dp[0] = new_dp[1] = add(add(add(dp[0], dp[1]), dp[2]), dp[3]);
        new_dp[2] = new_dp[3] = add(add(add(dp[1], dp[2]), dp[3]), dp[4]);
        new_dp[4] = new_dp[5] = add(add(add(dp[2], dp[3]), dp[4]), dp[5]);
        new_dp[6] = add(add(add(dp[3], dp[4]), dp[5]), dp[6]);
      }
      for (int i = 0; i <= 6; i++) {
        dp[i] = new_dp[i];
      }
    }
    printf("%lld\n", dp[0].value);
  }
  return 0;
}
