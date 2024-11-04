#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007
#define maxn 100100

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pll;

typedef struct {
    pll time;
    ll p;
} Info;

Info all_info[maxn][4];
Info temp_info[4];
int all_size = 0;

ll pow_func(ll n, ll m, ll mod) {
    if (m < 0) return 0;
    ll ans = 1;
    ll k = n;
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

void add(ll *a, ll b, int mod) {
    *a += b;
    while (*a >= mod) *a -= mod;
    while (*a < 0) *a += mod;
}

int jud(double a, double b) {
    const double eps = 1e-10;
    if (fabs(a) < eps && fabs(b) < eps)
        return 0;
    else if (fabs(a - b) / fmax(fabs(a), fabs(b)) < eps)
        return 0;
    return (a < b) ? -1 : 1;
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

Info Merge(const Info* a, int size_a, const Info* b, int size_b) {
    Info ans[maxn];
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
    while (i < size_a) ans[k++] = a[i++];
    while (j < size_b) ans[k++] = b[j++];

    return ans;
}

Info MergeDp(const Info* a, int size_a, const Info* b, int size_b) {
    Info ra[maxn], rb[maxn];
    for (int i = 0; i < size_a; i++) ra[i] = a[i];
    for (int j = 0; j < size_b; j++) rb[j] = b[j];

    for (ll i = 0, j = 0, sum = 0; i < size_a; i++) {
        while (j < size_b && info_greater_equal(rb[j], ra[i])) {
            add(&sum, rb[j].p, MOD);
            j++;
        }
        ra[i].p *= sum;
        ra[i].p %= MOD;
    }
    for (ll j = 0, i = 0, sum = 0; j < size_b; j++) {
        while (i < size_a && info_greater(a[i], rb[j])) {
            add(&sum, a[i].p, MOD);
            i++;
        }
        rb[j].p *= sum;
        rb[j].p %= MOD;
    }
    return Merge(ra, size_a, rb, size_b);
}

int main() {
    int n;
    scanf("%d", &n);
    pair<ll, pll> orig[maxn];

    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &orig[i].first, &orig[i].second.first, &orig[i].second.second);
        orig[i].second.second *= pow_func(100, MOD - 2, MOD);
        orig[i].second.second %= MOD;
    }

    for (int l = 0; l < n - 1; l++) {
        for (int cate = 0; cate < 4; cate++) {
            int r = l + 1;
            ll p = 1, dv = 0;
            p *= (cate & 1) ? orig[l].second.second : MOD + 1 - orig[l].second.second;
            dv += (cate & 1) ? orig[l].second.first : -orig[l].second.first;
            p *= (cate & 2) ? orig[r].second.second : MOD + 1 - orig[r].second.second;
            dv += (cate & 2) ? -orig[r].second.first : orig[r].second.first;
            dv = fmax(0ll, dv);
            p %= MOD;
            all_info[l][cate] = (Info){{orig[r].first - orig[l].first, dv}, p};
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
                    ll p1 = pow_func(MOD + 1 - orig[no_b].second.second, MOD - 2, MOD);
                    for (int k = 0; k < sizeof(rans1) / sizeof(rans1[0]); k++) {
                        rans1[k].p *= p1;
                        rans1[k].p %= MOD;
                    }
                    Info rans2 = MergeDp(all_info[no_a][f1 + 2], all_info[no_b][(f2 << 1) + 1]);
                    ll p2 = pow_func(orig[no_b].second.second, MOD - 2, MOD);
                    for (int k = 0; k < sizeof(rans2) / sizeof(rans2[0]); k++) {
                        rans2[k].p *= p2;
                        rans2[k].p %= MOD;
                    }
                    temp_info[f1 + (f2 << 1)] = Merge(rans1, sizeof(rans1) / sizeof(rans1[0]), rans2, sizeof(rans2) / sizeof(rans2[0]));
                }
            }
            for (int i = 0; i < 4; i++) {
                all_info[no_a][i] = temp_info[i];
            }
        }
    }

    ll ans = 0;
    for (int cate = 0; cate < 4; cate++) {
        for (int i = 0; i < sizeof(all_info[0][cate]) / sizeof(all_info[0][cate][0]); i++) {
            if (all_info[0][cate][i].time.second) {
                ans += all_info[0][cate][i].p * all_info[0][cate][i].time.first % MOD * pow_func(all_info[0][cate][i].time.second, MOD - 2, MOD);
                ans %= MOD;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
