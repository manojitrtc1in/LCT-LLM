#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long long li;
typedef long double ld;

#define MAX_N 20000013
#define INF (int)(1e9)
#define INF64 (li)(1e18)
#define MOD ((int)(1e9) + 7)
#define EPS 1e-9
#define PI acos(-1.0)

char s[MAX_N];
int n;

int read() {
    if (scanf("%s", s) != 1)
        return 0;
    n = strlen(s);
    return 1;
}

int ord[MAX_N];
int ord_size;

void gen(int n) {
    if (n == 1) {
        ord[ord_size++] = 1;
        return;
    }
    gen(n / 2);
    gen((n + 1) / 2);
    ord[ord_size++] = n;
}

void solve() {
    for (int t = n + 1; t >= 1; --t) {
        ord_size = 0;
        gen(t);
        int l = 0;
        int pr = 0;
        for (int i = 0; i < ord_size; i++) {
            int x = ord[i];
            if (x == 1) {
                ++pr;
                continue;
            }
            int cnt0 = 0, cnt1 = 0;
            int r = l;
            int fl = 0;
            while (r < n) {
                if (s[r++] == '0') {
                    ++cnt0;
                    if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                        fl = 1;
                        break;
                    }
                } else {
                    ++cnt1;
                    if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                        fl = 1;
                        break;
                    }
                }
            }
            if (!fl) break;
            l = r;
            ++pr;
        }
        if (l != n || pr != ord_size) continue;

        int res[MAX_N][MAX_N];
        int res_size = 0;
        l = 0;
        for (int i = 0; i < ord_size; i++) {
            int x = ord[i];
            if (x == 1) {
                res[res_size][0] = 0;
                res_size++;
                continue;
            }
            int cnt0 = 0, cnt1 = 0;
            int r = l;
            int fl = 0;
            int L[x / 2], R[(x + 1) / 2];
            while (r < n) {
                if (s[r++] == '0') {
                    L[cnt0] = cnt0 + cnt1;
                    ++cnt0;
                    if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                        fl = 1;
                        break;
                    }
                } else {
                    R[cnt1] = cnt0 + cnt1;
                    ++cnt1;
                    if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                        fl = 1;
                        break;
                    }
                }
            }
            while (cnt0 < x / 2) L[cnt0] = cnt0 + cnt1, ++cnt0;
            while (cnt1 < (x + 1) / 2) R[cnt1] = cnt0 + cnt1, ++cnt1;

            int nw[MAX_N];
            int nw_size = 0;
            for (int j = 0; j < res[res_size - 2][0]; j++) nw[nw_size++] = L[res[res_size - 2][j]];
            for (int j = 0; j < res[res_size - 1][0]; j++) nw[nw_size++] = R[res[res_size - 1][j]];
            res_size -= 2;
            memcpy(res[res_size], nw, sizeof(int) * nw_size);
            res[res_size][0] = nw_size;
            res_size++;
            if (!fl) break;
            l = r;
        }
        printf("%d\n", t);
        for (int j = 1; j <= res[0][0]; j++)
            printf("%d ", res[0][j] + 1);
        puts("");
        break;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        read();
        while (read()) {
            solve();
        }
    }
    return 0;
}
