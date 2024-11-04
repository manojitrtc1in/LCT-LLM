#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAXN 100

int gcd(int a, int b) {
    if (a < b) {
        int temp = b;
        b = a;
        a = temp;
    }

    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    int n;
    scanf("%d", &n);

    long long ans = 0;
    long long check[MAXN + 1] = {0};

    int primeFactors[MAXN + 1][MAXN + 1] = {0};

    for (int i = 2; i <= n; i++) {
        if (primeFactors[i][0] == 0) {
            primeFactors[i][0] = i;

            if (n / i >= i) {
                for (int j = i * i; j <= n; j += i) {
                    if (primeFactors[j][0] == 0) {
                        primeFactors[j][0] = i;
                    }
                }
            }
        } else {
            int prime = primeFactors[i][0];
            int rest = i / prime;
            while (rest % prime == 0) {
                rest /= prime;
            }
            if (rest > 1) {
                for (int k = 0; k < MAXN + 1; k++) {
                    if (primeFactors[rest][k] == 0) {
                        primeFactors[i][k] = prime;
                        break;
                    }
                }
            }
        }
    }

    for (long long g = 1; g <= n; g++) {
        if (g * 2 + 1 > n) {
            break;
        }
        long long cnt = 0;
        long long sum = 0;

        for (int ap = 2; ap <= n; ap++) {
            if (g * (ap + 1) + 1 > n) {
                break;
            }

            long long maxBp = (ap - 1) < ((n - 1) / g - ap) ? (ap - 1) : ((n - 1) / g - ap);
            long long currCnt = maxBp;
            sum += (maxBp * (maxBp + 1) / 2) % MOD;

            int k = 0;
            while (primeFactors[ap][k] != 0) {
                long long curr = 1;
                int sign = 1;
                for (int pos = 0; pos < MAXN + 1; pos++) {
                    if (primeFactors[ap][pos] == 0) {
                        break;
                    }
                    if ((k & (1 << pos)) > 0) {
                        curr *= primeFactors[ap][pos];
                        sign *= -1;
                    }
                }

                long long s = (ap - 1) / curr < (n - 1 - g * ap) / curr / g ? (ap - 1) / curr : (n - 1 - g * ap) / curr / g;

                currCnt += s * sign;
                sum += curr * s * (s + 1) / 2 * sign;

                k++;
            }

            cnt += currCnt;
            sum += currCnt * ap;
            sum %= MOD;
        }

        cnt *= 2;
        sum *= g * 2;

        cnt++;
        sum += g * 2;

        cnt %= MOD;
        sum %= MOD;
        if (sum < 0) {
            sum += MOD;
        }

        check[g] -= ans;
        long long k = gcd(g, n);
        ans += g * n / k * cnt % MOD;
        ans -= g / k * sum % MOD;
        check[g] += ans;
    }

    ans %= MOD;
    if (ans < 0) {
        ans += MOD;
    }

    printf("%lld\n", ans);
}

int main() {
    int t = 1;

    for (int i = 1; i <= t; ++i) {
        solve();
    }

    return 0;
}
