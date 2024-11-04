#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 32
#define MOD (int)(1e9) + 7

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int a[N][N];
} mat;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b) {
    return a * (li)b % MOD;
}

mat mat_mul(mat a, mat b) {
    mat c;
    int i, j, t;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            c.a[i][j] = 0;
            for (t = 0; t < N; t++) {
                c.a[i][j] = add(c.a[i][j], mul(a.a[i][t], b.a[t][j]));
            }
        }
    }
    return c;
}

mat amat[62][N];

void solve(li n, int k) {
    int i, j, d, r, sh, rem, ans;
    mat dp;
    int num[N];
    int pr[N][N];
    
    for (i = 0; i < N; i++) {
        num[i] = 0;
    }
    
    i = 0;
    while (n > 0) {
        num[i] = n % k;
        n /= k;
        i++;
    }
    
    for (d = 0; d < k; d++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                amat[0][d].a[i][j] = 0;
            }
        }
        for (i = 0; i < N; i++) {
            amat[0][d].a[i][i] = 1;
        }
        for (i = 0; i < N; i++) {
            amat[0][d].a[i][d] = 1;
        }
    }
    
    for (r = 1; r < i; r++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                pr[0][i][j] = i == j;
            }
        }
        for (i = 0; i < k; i++) {
            mat_mul(pr[0], amat[r - 1][i], pr[1]);
            for (sh = 0; sh < k; sh++) {
                mat_mul(pr[1], amat[r - 1][(i + sh) % k], amat[r][sh]);
            }
        }
    }
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            dp.a[i][j] = 0;
        }
    }
    dp.a[0][k] = 1;
    
    rem = 0;
    for (i = r - 1; i >= 0; i--) {
        while (num[i] > 0) {
            mat_mul(dp, amat[i][rem], dp);
            rem = (rem + 1) % k;
            num[i]--;
        }
    }
    
    ans = 0;
    for (i = 0; i < k + 1; i++) {
        ans = add(ans, dp.a[0][i]);
    }
    printf("%d\n", ans);
}

int main() {
    li n;
    int k, tc;
    int i;
    
    freopen("input.txt", "r", stdin);
    
    scanf("%d", &tc);
    while (tc--) {
        scanf("%lld%d", &n, &k);
        solve(n, k);
    }
    
    return 0;
}
