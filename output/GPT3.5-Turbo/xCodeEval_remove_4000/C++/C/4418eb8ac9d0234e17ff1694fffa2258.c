#include <stdio.h>
#include <stdlib.h>

#define MOD 998244353

typedef long long ll;

typedef struct {
    ll first;
    ll second;
} pll;

typedef struct {
    pll time;
    ll p;
} Info;

int n;
pll orig[100100];

Info all_info[100100][4];
Info temp_info[4];
int all_size = 0;

ll pow(ll n, ll m, ll mod) {
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

void add(ll* a, ll b, int mod) {
    if (mod == -1) mod = MOD;
    *a += b;
    while (*a >= mod) *a -= mod;
    while (*a < 0) *a += mod;
}

int jud(double a, double b) {
    if (abs(a) < 1e-10 && abs(b) < 1e-10)
        return 0;
    else if (abs(a - b) / max(abs(a), abs(b)) < 1e-10)
        return 0;
    if (a < b) return -1;
    return 1;
}

int find(ll val, ll* a, int na, int f_small, int f_lb) {
    if (na == 0) return 0;
    int be = 0, en = na - 1;
    if (*a <= *(a + na - 1)) {
        if (f_lb == 0)
            while (be < en) {
                int mid = (be + en + 1) / 2;
                if (jud(*(a + mid), val) != 1)
                    be = mid;
                else
                    en = mid - 1;
            }
        else
            while (be < en) {
                int mid = (be + en) / 2;
                if (jud(*(a + mid), val) != -1)
                    en = mid;
                else
                    be = mid + 1;
            }
        if (f_small && jud(*(a + be), val) == 1) be--;
        if (!f_small && jud(*(a + be), val) == -1) be++;
    } else {
        if (f_lb)
            while (be < en) {
                int mid = (be + en + 1) / 2;
                if (jud(*(a + mid), val) != -1)
                    be = mid;
                else
                    en = mid - 1;
            }
        else
            while (be < en) {
                int mid = (be + en) / 2;
                if (jud(*(a + mid), val) != 1)
                    en = mid;
                else
                    be = mid + 1;
            }
        if (!f_small && jud(*(a + be), val) == -1) be--;
        if (f_small && jud(*(a + be), val) == 1) be++;
    }
    return be;
}

int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
int bitnum(int nValue) { return __builtin_popcount(nValue); }
int bitnum(unsigned long long nValue) {
    return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
int bitnum(ll nValue) {
    return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
int id0(unsigned int a) {
    if (a == 0) return 0;
    return 32 - __builtin_clz(a);
}
int id0(int a) {
    if (a == 0) return 0;
    return 32 - __builtin_clz(a);
}
int id0(unsigned long long a) {
    int temp = a >> 32;
    if (temp) return 32 - __builtin_clz(temp) + 32;
    return id0((int)a);
}
int id0(ll a) {
    int temp = a >> 32;
    if (temp) return 32 - __builtin_clz(temp) + 32;
    return id0((int)a);
}

ll min1(ll a, ll b) {
    return a < b ? a : b;
}

ll max1(ll a, ll b) {
    return b < a ? a : b;
}

Info* Merge(Info* a, int na, Info* b, int nb) {
    Info* ans = (Info*)malloc((na + nb) * sizeof(Info));
    int i = 0, j = 0, k = 0;
    for (; i < na && j < nb; ) {
        if (a[i].time.first * b[j].time.second == a[i].time.second * b[j].time.first) {
            ans[k].time = a[i].time;
            ans[k].p = (a[i].p + b[j].p) % MOD;
            i++;
            j++;
            k++;
        } else if (a[i].time.first * b[j].time.second < a[i].time.second * b[j].time.first) {
            if (a[i].p) {
                ans[k].time = a[i].time;
                ans[k].p = a[i].p;
                k++;
            }
            i++;
        } else {
            if (b[j].p) {
                ans[k].time = b[j].time;
                ans[k].p = b[j].p;
                k++;
            }
            j++;
        }
    }
    while (i < na) {
        ans[k].time = a[i].time;
        ans[k].p = a[i].p;
        i++;
        k++;
    }
    while (j < nb) {
        ans[k].time = b[j].time;
        ans[k].p = b[j].p;
        j++;
        k++;
    }
    return ans;
}

Info* MergeDp(Info* a, int na, Info* b, int nb) {
    Info* ra = a;
    Info* rb = b;
    for (ll i = 0, j = 0, sum = 0; i < na; i++) {
        while (j < nb && b[j].time.first * a[i].time.second >= b[j].time.second * a[i].time.first) {
            add(&sum, b[j].p, MOD);
            j++;
        }
        ra[i].p *= sum;
        ra[i].p %= MOD;
    }
    for (ll i = 0, j = 0, sum = 0; j < nb; j++) {
        while (i < na && a[i].time.first * b[j].time.second > a[i].time.second * b[j].time.first) {
            add(&sum, a[i].p, MOD);
            i++;
        }
        rb[j].p *= sum;
        rb[j].p %= MOD;
    }
    return Merge(ra, na, rb, nb);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &orig[i].first, &orig[i].second.first, &orig[i].second.second);
        orig[i].second.second *= pow(100, MOD - 2, MOD);
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
            dv = max1(0ll, dv);
            p %= MOD;
            all_info[l][cate].time.first = orig[r].first - orig[l].first;
            all_info[l][cate].time.second = dv;
            all_info[l][cate].p = p;
            all_size++;
        }
    }
    for (int i = 0; (1 << i) < (n - 1); i++) {
        for (int j = 0; j * (1 << (i + 1)) < n - 1; j++) {
            int no_a = j * (1 << (i + 1)), no_b = no_a + (1 << i);
            if (no_b >= n - 1) continue;
            for (int f1 = 0; f1 < 2; f1++) {
                for (int f2 = 0; f2 < 2; f2++) {
                    Info* rans1 = MergeDp(all_info[no_a] + f1, 2, all_info[no_b] + (f2 << 1), 2);
                    ll p1 = pow(MOD + 1 - orig[no_b].second.second, MOD - 2, MOD);
                    for (int k = 0; k < 2; k++) {
                        rans1[k].p *= p1;
                        rans1[k].p %= MOD;
                    }
                    Info* rans2 = MergeDp(all_info[no_a] + f1 + 2, 2, all_info[no_b] + (f2 << 1) + 1, 2);
                    ll p2 = pow(orig[no_b].second.second, MOD - 2, MOD);
                    for (int k = 0; k < 2; k++) {
                        rans2[k].p *= p2;
                        rans2[k].p %= MOD;
                    }
                    temp_info[f1 + (f2 << 1)] = Merge(rans1, 2, rans2, 2);
                }
            }
            for (int i = 0; i < 4; i++) {
                all_info[no_a][i] = temp_info[i];
            }
        }
    }

    ll ans = 0;
    for (int cate = 0; cate < 4; cate++) {
        for (int i = 0; i < 2; i++) {
            if (all_info[0][cate].time.second) {
                add(&ans, all_info[0][cate].p * all_info[0][cate].time.first % MOD * pow(all_info[0][cate].time.second, MOD - 2, MOD), MOD);
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
