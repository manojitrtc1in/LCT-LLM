#include <stdio.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REP_C(i, n) for (int i = 1; i <= n; i++)
#define REP_2(i, j, n, m) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
#define DWN(i, n, m) for (int i = n; i >= m; i--)
#define FOR_1(i, n, m) for (int i = m; i <= n; i++)
#define ALL(x) x.begin(), x.end()

#define MOD (int)(1e9) + 7
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
#define OO 1e20
#define PI acos(-1.0)

#define _1(x) (1LL << (x))
#define _U(x) (_1(x) - 1)

typedef long long LL;
typedef double DB;

LL f[_1(20)], ok[21];
int n, m;

int count_bits(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x &= (x - 1);
    }
    return cnt;
}

void solve() {
    REP_2(i, j, n, n) {
        if (i != j) {
            int s = 0;
            REP(k, m) {
                if (S[i][k] == S[j][k]) {
                    s |= _1(k);
                }
            }
            f[s] |= _1(i);
        }
    }

    for (int s = _1(m) - 1; s >= 0; s--) {
        REP(i, m) {
            if (!_1(s, i)) {
                f[s ^ _1(i)] |= f[s];
            }
        }
    }

    REP(s, _1(m)) {
        int step = count_bits(s) + 1;
        REP(i, m) {
            if (!_1(s, i)) {
                LL d = f[s | _1(i)] ^ f[s];
                ok[step] += count_bits(d);
            }
        }
    }

    DB ans = 0;
    for (int i = 0; i < m; i++) {
        if (ok[i]) {
            DB t = ok[i] * i;
            for (int j = i - 1; j >= 0; j--) {
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
    char S[50][20];
    for (int i = 0; i < n; i++) {
        scanf("%s", S[i]);
    }
    m = strlen(S[0]);
    solve();
    return 0;
}
