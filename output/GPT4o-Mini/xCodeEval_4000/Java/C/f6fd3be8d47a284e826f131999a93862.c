#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX_N 100

typedef struct {
    int first, second;
} Pair;

long gcd(long a, long b) {
    if (a < b) {
        long temp = b;
        b = a;
        a = temp;
    }
    while (b > 0) {
        long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int n;
long ans;
long check[MAX_N + 1];

void getInput() {
    scanf("%d", &n);
}

void printOutput() {
    printf("%ld\n", ans);
}

void solve() {
    long primeFactors[MAX_N + 1][MAX_N + 1];
    int primeCount[MAX_N + 1] = {0};

    for (int i = 2; i <= n; i++) {
        if (primeCount[i] == 0) {
            primeFactors[i][0] = i;
            primeCount[i] = 1;
            for (int j = i * i; j <= n; j += i) {
                if (primeCount[j] == 0) {
                    primeFactors[j][0] = i;
                    primeCount[j] = 1;
                }
            }
        } else {
            int prime = primeFactors[i][0];
            int rest = i / prime;
            while (rest % prime == 0) {
                rest /= prime;
            }
            if (rest > 1) {
                for (int k = 0; k < primeCount[rest]; k++) {
                    primeFactors[i][primeCount[i]++] = primeFactors[rest][k];
                }
            }
        }
    }

    ans = 0;
    for (long g = 1; g <= n; g++) {
        if (g * 2 + 1 > n) break;
        long cnt = 0;
        long sum = 0;

        for (int ap = 2; ap <= n; ap++) {
            if (g * (ap + 1) + 1 > n) break;

            long maxBp = (ap - 1 < (n - 1) / g - ap) ? ap - 1 : (n - 1) / g - ap;
            long currCnt = maxBp;
            sum += maxBp * (maxBp + 1) / 2 % MOD;

            int k = primeCount[ap];
            for (int mask = 1; mask < (1 << k); mask++) {
                long curr = 1;
                int sign = 1;
                for (int pos = 0; pos < k; pos++) {
                    if ((mask & (1 << pos)) > 0) {
                        curr *= primeFactors[ap][pos];
                        sign *= -1;
                    }
                }

                long s = (ap - 1) / curr < (n - 1 - g * ap) / curr / g ? (ap - 1) / curr : (n - 1 - g * ap) / curr / g;

                currCnt += s * sign;
                sum += curr * s * (s + 1) / 2 * sign;
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
        if (sum < 0) sum += MOD;

        check[(int)g] -= ans;
        long k = gcd(g, n);
        ans += g * n / k * cnt % MOD;
        ans -= g / k * sum % MOD;
        check[(int)g] += ans;
    }
    ans %= MOD;
    if (ans < 0) ans += MOD;
}

int main() {
    int t = 1; // Change this if multiple test cases are needed
    for (int i = 1; i <= t; ++i) {
        getInput();
        solve();
        printOutput();
    }
    return 0;
}
