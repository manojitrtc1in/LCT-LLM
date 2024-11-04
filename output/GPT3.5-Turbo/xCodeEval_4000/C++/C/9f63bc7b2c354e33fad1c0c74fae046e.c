#include <stdio.h>
#include <stdbool.h>

typedef unsigned int mint;

unsigned int l1;
unsigned int r1;

int get(int i, int z) {
    l1 = (unsigned int)1U * i * z;
    r1 = (unsigned int)1U * (i + i) * z;

    unsigned int ans = l1;

    while (l1 <= r1) {
        unsigned int m = (l1 + r1) / 2;
        if (m / z > i) {
            r1 = m - 1;
        } else {
            ans = (ans > m) ? ans : m;
            l1 = m + 1;
        }
    }

    return ans;
}

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    mint dp[n + 1];
    mint p[n + 1];

    dp[n] = 1;
    p[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        dp[i] += p[i + 1];

        for (int z = 2; z * i <= n; z++) {
            int r = get(i, z) + 1;
            int l = z * i;
            dp[i] += p[l];
            if (r <= n) dp[i] -= p[r];
        }

        p[i] = p[i + 1] + dp[i];
    }

    printf("%u", dp[1]);
}

int main() {
    int _t = 1;

    while (_t--) solve();
    return 0;
}
