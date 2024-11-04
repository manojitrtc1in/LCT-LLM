#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 50
#define MAX_M 20

typedef long long LL;

char S[MAX_N][MAX_M + 1];
LL f[1 << MAX_M];
LL ok[MAX_M + 1];
int n, m;

int count_bits(int x) {
    int count = 0;
    while (x) {
        count++;
        x &= (x - 1);
    }
    return count;
}

void solve() {
    for (int i = 0; i < n; i++) {
        scanf("%s", S[i]);
    }
    m = strlen(S[0]);

    for (int i = 0; i < n; i++) {
        for (int j = n; j < n; j++) {
            if (i != j) {
                int s = 0;
                for (int k = 0; k < m; k++) {
                    if (S[i][k] == S[j][k]) {
                        s |= (1 << k);
                    }
                }
                f[s] |= (1 << i);
            }
        }
    }

    for (int s = (1 << m) - 1; s >= 0; s--) {
        for (int i = 0; i < m; i++) {
            if (s & (1 << i)) {
                f[s ^ (1 << i)] |= f[s];
            }
        }
    }

    for (int s = 0; s < (1 << m); s++) {
        int step = count_bits(s) + 1;
        for (int i = 0; i < m; i++) {
            if (!(s & (1 << i))) {
                LL d = f[s | (1 << i)] ^ f[s];
                ok[step] += count_bits(d);
            }
        }
    }

    double ans = 0;
    for (int i = 1; i <= m; i++) {
        if (ok[i]) {
            double t = ok[i] * i;
            for (int j = 1; j <= i - 1; j++) {
                t *= j;
            }
            for (int j = m - i + 1; j <= m; j++) {
                t /= j;
            }
            ans += t;
        }
    }

    ans /= n;
    printf("%.15f\n", ans);
}

int main() {
    scanf("%d", &n);
    solve();
    return 0;
}
