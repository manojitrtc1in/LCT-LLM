#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 200005
#define MOD 1000000007

typedef struct {
    long long first;
    long long second;
} pii;

typedef struct {
    long long first;
    pii second;
} ver;

long long data[MAXN][MAXN];
long long sizes[MAXN];
long long ans[MAXN];
pii sol[MAXN];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long modpow(long long a, long long n, long long temp) {
    long long res = 1, y = a;
    while (n > 0) {
        if (n & 1) res = (res * y) % temp;
        y = (y * y) % temp;
        n /= 2;
    }
    return res % temp;
}

int main() {
    long long n, tot = 0;
    scanf("%lld", &n);
    
    for (long long i = 1; i <= n; i++) {
        long long k, a, x, y, m;
        scanf("%lld %lld %lld %lld %lld", &k, &a, &x, &y, &m);
        tot += k;
        data[i][0] = a;
        sizes[i] = k;
        for (long long j = 1; j < k; j++) {
            data[i][j] = (data[i][j - 1] * x + y) % m;
        }
    }

    ver q[MAXN];
    long long q_size = 0;

    for (long long i = 0; i < n; i++) {
        q[q_size++] = (ver){data[i + 1][0], (pii){i, 0}};
    }

    long long p = 0;
    while (q_size > 0 && tot > 0) {
        long long min_index = 0;
        for (long long i = 1; i < q_size; i++) {
            if (q[i].first < q[min_index].first) {
                min_index = i;
            }
        }

        long long v = q[min_index].first;
        p = v;
        pii o = q[min_index].second;
        ans[tot - 1] = v;
        sol[tot - 1] = (pii){v, o.first + 1};
        q[min_index] = q[q_size - 1];
        q_size--;

        if (o.second + 1 < sizes[o.first + 1]) {
            q[q_size++] = (ver){data[o.first + 1][o.second + 1], (pii){o.first, o.second + 1}};
        }
        tot--;
    }

    long long bad = 0;
    for (long long i = 1; i < (sizeof(ans) / sizeof(ans[0])); i++) {
        if (ans[i - 1] > ans[i]) bad++;
    }

    printf("%lld\n", bad);
    if (tot <= 200000) {
        for (long long i = 0; i < (sizeof(sol) / sizeof(sol[0])); i++) {
            printf("%lld %lld\n", sol[i].first, sol[i].second);
        }
    }

    return 0;
}
