#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pll;

typedef struct {
    pll time;
    ll p;
} Info;

Info Merge(const Info* a, int a_size, const Info* b, int b_size) {
    Info* ans = malloc((a_size + b_size) * sizeof(Info));
    int i = 0, j = 0, k = 0;
    for (; i < a_size && j < b_size; ) {
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
    while (i < a_size) {
        ans[k].time = a[i].time;
        ans[k].p = a[i].p;
        i++;
        k++;
    }
    while (j < b_size) {
        ans[k].time = b[j].time;
        ans[k].p = b[j].p;
        j++;
        k++;
    }
    return ans;
}

Info MergeDp(const Info* a, int a_size, const Info* b, int b_size) {
    Info* ra = malloc(a_size * sizeof(Info));
    Info* rb = malloc(b_size * sizeof(Info));
    for (ll i = 0, j = 0, sum = 0; i < a_size; i++) {
        while (j < b_size && b[j].time.first * a[i].time.second >= b[j].time.second * a[i].time.first) {
            sum = (sum + b[j].p) % MOD;
            j++;
        }
        ra[i].time = a[i].time;
        ra[i].p = (a[i].p * sum) % MOD;
    }
    for (ll i = 0, j = 0, sum = 0; j < b_size; j++) {
        while (i < a_size && a[i].time.first * b[j].time.second > a[i].time.second * b[j].time.first) {
            sum = (sum + a[i].p) % MOD;
            i++;
        }
        rb[j].time = b[j].time;
        rb[j].p = (b[j].p * sum) % MOD;
    }
    Info ans = Merge(ra, a_size, rb, b_size);
    free(ra);
    free(rb);
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    pll* orig = malloc(n * sizeof(pll));
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &orig[i].first, &orig[i].second, &orig[i].second);
        orig[i].second = (orig[i].second * pow(100, MOD - 2)) % MOD;
    }

    Info** all_info = malloc((n - 1) * sizeof(Info*));
    for (int i = 0; i < n - 1; i++) {
        all_info[i] = malloc(4 * sizeof(Info));
    }

    for (int l = 0; l < n - 1; l++) {
        for (int cate = 0; cate < 4; cate++) {
            int r = l + 1;
            ll p = 1, dv = 0;
            p *= (cate & 1) ? orig[l].second : MOD + 1 - orig[l].second;
            dv += (cate & 1) ? orig[l].first : -orig[l].first;
            p *= (cate & 2) ? orig[r].second : MOD + 1 - orig[r].second;
            dv += (cate & 2) ? -orig[r].first : orig[r].first;
            dv = (dv > 0) ? dv : 0;
            p %= MOD;
            all_info[l][cate].time.first = orig[r].first - orig[l].first;
            all_info[l][cate].time.second = dv;
            all_info[l][cate].p = p;
        }
    }

    for (int i = 0; (1 << i) < (n - 1); i++) {
        for (int j = 0; j * (1 << (i + 1)) < n - 1; j++) {
            int no_a = j * (1 << (i + 1)), no_b = no_a + (1 << i);
            if (no_b >= n - 1) continue;
            for (int f1 = 0; f1 < 2; f1++) {
                for (int f2 = 0; f2 < 2; f2++) {
                    Info rans1 = MergeDp(all_info[no_a] + f1, 2, all_info[no_b] + (f2 << 1), 2);
                    ll p1 = pow(MOD + 1 - orig[no_b].second, MOD - 2, MOD);
                    rans1.p = (rans1.p * p1) % MOD;
                    Info rans2 = MergeDp(all_info[no_a] + f1 + 2, 2, all_info[no_b] + (f2 << 1) + 1, 2);
                    ll p2 = pow(orig[no_b].second, MOD - 2, MOD);
                    rans2.p = (rans2.p * p2) % MOD;
                    Info* temp_info = malloc(4 * sizeof(Info));
                    temp_info[0] = rans1;
                    temp_info[1] = rans2;
                    Info ans = Merge(temp_info, 2, temp_info + 2, 2);
                    free(temp_info);
                    for (int i = 0; i < 4; i++) {
                        all_info[no_a][i] = ans[i];
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int cate = 0; cate < 4; cate++) {
        for (int i = 0; i < 4; i++) {
            if (all_info[0][cate].time.second) {
                ans = (ans + all_info[0][cate].p * all_info[0][cate].time.first % MOD * pow(all_info[0][cate].time.second, MOD - 2, MOD)) % MOD;
            }
        }
    }
    printf("%lld\n", ans);

    for (int i = 0; i < n - 1; i++) {
        free(all_info[i]);
    }
    free(all_info);
    free(orig);

    return 0;
}
