#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef long long li;
typedef long double ld;

#define MAX_N (20 * 1000 * 1000 + 13)

char s[MAX_N];
int n;

bool read() {
    if (scanf("%s", s) != 1)
        return false;
    n = strlen(s);
    return true;
}

int ord[MAX_N];
int ord_size = 0;

void gen(int n) {
    if (n == 1) {
        ord[ord_size++] = 1;
        return;
    }
    gen(n / 2);
    gen((n + 1) / 2);
    ord[ord_size++] = n;
}

int get(int t, bool ans) {
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
        bool fl = false;
        while (r < n) {
            if (s[r++] == '0') {
                ++cnt0;
                if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                    fl = true;
                    break;
                }
            } else {
                ++cnt1;
                if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                    fl = true;
                    break;
                }
            }
        }
        if (!fl) break;
        l = r;
        ++pr;
    }
    if (!ans) return ord_size - pr;

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
        bool fl = false;
        int L[x / 2], R[(x + 1) / 2];
        while (r < n) {
            if (s[r++] == '0') {
                L[cnt0] = cnt0 + cnt1;
                ++cnt0;
                if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                    fl = true;
                    break;
                }
            } else {
                R[cnt1] = cnt0 + cnt1;
                ++cnt1;
                if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                    fl = true;
                    break;
                }
            }
        }
        while (cnt0 < x / 2) L[cnt0] = cnt0 + cnt1, ++cnt0;
        while (cnt1 < (x + 1) / 2) R[cnt1] = cnt0 + cnt1, ++cnt1;

        int nw[MAX_N];
        int nw_size = 0;
        for (int j = 0; j < res[res_size - 2][0]; j++) nw[nw_size++] = L[res[res_size - 2][j + 1]];
        for (int j = 0; j < res[res_size - 1][0]; j++) nw[nw_size++] = R[res[res_size - 1][j + 1]];
        res_size -= 2;
        res[res_size][0] = nw_size;
        for (int j = 0; j < nw_size; j++) res[res_size][j + 1] = nw[j];

        if (!fl) break;
        l = r;
    }
    printf("%d\n", t);
    for (int j = 1; j <= res[0][0]; j++)
        printf("%d ", res[0][j] + 1);
    puts("");
    return true;
}

void solve() {
    int l = 1, r = n + 1;
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (get(m, false) == 0) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    get(res, true);
}

int main() {
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
