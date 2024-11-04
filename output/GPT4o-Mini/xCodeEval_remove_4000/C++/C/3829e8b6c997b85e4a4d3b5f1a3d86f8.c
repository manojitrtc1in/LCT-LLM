#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef long long li;
typedef long double ld;
typedef struct {
    int x, y;
} pt;

#define N 32
#define MOD (1000000007)
#define INF (1000000000)
#define INF64 (1000000000000000000LL)
#define EPS (1e-9)
#define PI (acos(-1.0))

li n;
int k;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (a * (li)b) % MOD;
}

typedef int mat[N][N];

void mat_mult(mat a, mat b, mat c) {
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            c[i][j] = 0;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            for (int t = 0; t <= k; t++)
                c[i][j] = add(c[i][j], mul(a[i][t], b[t][j]));
}

mat amat[62][N];

void solve() {
    int num[N], size = 0;
    while (n > 0) {
        num[size++] = n % k;
        n /= k;
    }

    for (int d = 0; d < k; d++) {
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++)
                amat[0][d][i][j] = 0;
        for (int i = 0; i <= k; i++)
            amat[0][d][i][i] = 1;
        for (int i = 0; i <= k; i++)
            amat[0][d][i][d] = 1;
    }

    for (int r = 1; r < size; r++) {
        mat pr[N];
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++)
                pr[0][i][j] = (i == j) ? 1 : 0;

        for (int i = 0; i < k; i++) {
            mat_mult(pr[i], amat[r - 1][i], pr[i + 1]);
        }

        for (int sh = 0; sh < k; sh++) {
            mat_mult(pr[0], amat[r - 1][sh], amat[r][sh]);
            for (int i = 0; i < k - sh; i++) {
                mat temp;
                mat_mult(amat[r][sh], amat[r - 1][(i + sh) % k], temp);
                for (int ii = 0; ii <= k; ii++)
                    for (int jj = 0; jj <= k; jj++)
                        amat[r][sh][ii][jj] = temp[ii][jj];
            }
            mat_mult(amat[r][sh], pr[sh], amat[r][sh]);
        }
    }

    mat dp;
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = 0;
    dp[0][k] = 1;

    int rem = 0;
    for (int i = size - 1; i >= 0; --i) {
        while (num[i] > 0) {
            mat_mult(dp, amat[i][rem], dp);
            rem = (rem + 1) % k;
            --num[i];
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = add(ans, dp[0][i]);
    printf("%d\n", ans);
}

int read() {
    return scanf("%lld%d", &n, &k) == 2;
}

int main() {
    freopen("input.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        if (read()) {
            solve();
        }
    }
    return 0;
}
