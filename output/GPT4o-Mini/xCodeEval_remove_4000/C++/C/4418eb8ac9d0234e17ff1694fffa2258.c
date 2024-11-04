#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 100100
#define MOD 998244353

typedef struct {
    long long first;
    long long second;
} pll;

typedef struct {
    pll time;
    long long p;
} Info;

Info all_info[MAXN][4];
Info temp_info[4];
int all_size = 0;
long long orig[MAXN][3];
int n;

long long pow_mod(long long n, long long m, long long mod) {
    if (m < 0) return 0;
    long long ans = 1;
    long long k = n;
    while (m) {
        if (m & 1) {
            ans *= k;
            if (mod) ans %= mod;
        }
        k *= k;
        if (mod) k %= mod;
        m >>= 1;
    }
    return ans;
}

void add(long long *a, long long b) {
    *a += b;
    while (*a >= MOD) *a -= MOD;
    while (*a < 0) *a += MOD;
}

bool info_less(Info a, Info b) {
    return a.time.first * b.time.second < a.time.second * b.time.first;
}

bool info_equal(Info a, Info b) {
    return a.time.first * b.time.second == a.time.second * b.time.first;
}

bool info_greater(Info a, Info b) {
    return info_less(b, a);
}

bool info_less_equal(Info a, Info b) {
    return info_less(a, b) || info_equal(a, b);
}

bool info_greater_equal(Info a, Info b) {
    return info_greater(b, a) || info_equal(a, b);
}

Info Merge(Info *a, int size_a, Info *b, int size_b) {
    Info *ans = malloc((size_a + size_b) * sizeof(Info));
    int i = 0, j = 0, k = 0;

    while (i < size_a && j < size_b) {
        if (info_equal(a[i], b[j])) {
            ans[k++] = (Info){{a[i].time.first, a[i].time.second}, (a[i].p + b[j].p) % MOD};
            i++;
            j++;
        } else if (info_greater(a[i], b[j])) {
            if (a[i].p) ans[k++] = a[i];
            i++;
        } else {
            if (b[j].p) ans[k++] = b[j];
            j++;
        }
    }

    while (i < size_a) {
        ans[k++] = a[i++];
    }
    while (j < size_b) {
        ans[k++] = b[j++];
    }

    return ans;
}

Info MergeDp(Info *a, int size_a, Info *b, int size_b) {
    Info *ra = malloc(size_a * sizeof(Info));
    Info *rb = malloc(size_b * sizeof(Info));
    for (int i = 0; i < size_a; i++) ra[i] = a[i];
    for (int j = 0; j < size_b; j++) rb[j] = b[j];

    for (long long i = 0, j = 0, sum = 0; i < size_a; i++) {
        while (j < size_b && info_greater_equal(rb[j], ra[i])) {
            add(&sum, rb[j].p);
            j++;
        }
        ra[i].p *= sum;
        ra[i].p %= MOD;
    }

    for (long long j = 0, i = 0, sum = 0; j < size_b; j++) {
        while (i < size_a && info_greater(ra[i], rb[j])) {
            add(&sum, ra[i].p);
            i++;
        }
        rb[j].p *= sum;
        rb[j].p %= MOD;
    }

    return Merge(ra, size_a, rb, size_b);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &orig[i][0], &orig[i][1], &orig[i][2]);
        orig[i][2] *= pow_mod(100, MOD - 2, MOD);
        orig[i][2] %= MOD;
    }

    for (int l = 0; l < n - 1; l++) {
        for (int cate = 0; cate < 4; cate++) {
            int r = l + 1;
            long long p = 1, dv = 0;
            p *= (cate & 1) ? orig[l][2] : MOD + 1 - orig[l][2];
            dv += (cate & 1) ? orig[l][1] : -orig[l][1];
            p *= (cate & 2) ? orig[r][2] : MOD + 1 - orig[r][2];
            dv += (cate & 2) ? -orig[r][1] : orig[r][1];
            dv = fmax(0ll, dv);
            p %= MOD;
            all_info[l][cate][0] = (Info){{orig[r][0] - orig[l][0], dv}, p};
            all_size++;
        }
    }

    for (int i = 0; (1 << i) < (n - 1); i++) {
        for (int j = 0; j * (1 << (i + 1)) < n - 1; j++) {
            int no_a = j * (1 << (i + 1)), no_b = no_a + (1 << i);
            if (no_b >= n - 1) continue;
            for (int f1 = 0; f1 < 2; f1++) {
                for (int f2 = 0; f2 < 2; f2++) {
                    Info rans1 = MergeDp(all_info[no_a][f1], all_info[no_b][f2 << 1]);
                    long long p1 = pow_mod(MOD + 1 - orig[no_b][2], MOD - 2, MOD);
                    for (int k = 0; k < sizeof(rans1) / sizeof(Info); k++) {
                        rans1[k].p *= p1;
                        rans1[k].p %= MOD;
                    }
                    Info rans2 = MergeDp(all_info[no_a][f1 + 2], all_info[no_b][(f2 << 1) + 1]);
                    long long p2 = pow_mod(orig[no_b][2], MOD - 2, MOD);
                    for (int k = 0; k < sizeof(rans2) / sizeof(Info); k++) {
                        rans2[k].p *= p2;
                        rans2[k].p %= MOD;
                    }
                    temp_info[f1 + (f2 << 1)] = Merge(rans1, sizeof(rans1) / sizeof(Info), rans2, sizeof(rans2) / sizeof(Info));
                }
            }
            for (int i = 0; i < 4; i++) {
                all_info[no_a][i] = temp_info[i];
            }
        }
    }

    long long ans = 0;
    for (int cate = 0; cate < 4; cate++) {
        for (int i = 0; i < sizeof(all_info[0][cate]) / sizeof(Info); i++) {
            if (all_info[0][cate][i].time.second) {
                ans += all_info[0][cate][i].p * all_info[0][cate][i].time.first % MOD * pow_mod(all_info[0][cate][i].time.second, MOD - 2, MOD);
                ans %= MOD;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
