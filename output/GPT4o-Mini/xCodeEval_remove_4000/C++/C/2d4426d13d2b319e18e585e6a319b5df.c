#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Mask(x) ((1 << (x)) - 1)
#define Full(x) ((1 << (x)) - 1)
#define circ(i, j, n) for (int i = (j + 1) % (n); i != (j + 1) % (n); i = (i + 1) % (n))
#define loop(i, n) for (int i = 0; i < (n); ++i)
#define pool(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;
typedef long double lf;

char s[55][25];
ll dy[Mask(20) + 5];
lf dp[Mask(20) + 5];

int main() {
    int n, m;
    scanf("%d", &n);
    loop(i, n) {
        scanf("%s", s[i]);
    }
    m = strlen(s[0]);
    loop(i, n) {
        circ(j, i + 1, n - 1) {
            int num = 0;
            loop(k, m) {
                num |= (s[i][k] == s[j][k]) << k;
            }
            dy[num] |= (1LL << i) | (1LL << j);
        }
    }
    pool(i, Mask(m)) {
        for (int j = i; j & -j; j -= j & -j) {
            int lst = j & -j;
            dy[i ^ lst] |= dy[i];
        }
    }
    dp[0] = 1;
    lf ans = 0;
    loop(i, Mask(m)) {
        lf v = dp[i] / (m - __builtin_popcount(i));
        for (int j = Full(m) ^ i; j & -j; j -= j & -j) {
            dp[i | (j & -j)] += v;
        }
        ans += dp[i] * __builtin_popcountll(dy[i]);
    }
    printf("%.10Lf\n", ans / n);
    return 0;
}
