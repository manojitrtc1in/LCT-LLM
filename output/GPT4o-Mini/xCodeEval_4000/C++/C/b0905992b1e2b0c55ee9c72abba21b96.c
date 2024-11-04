#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N (20 * 1000 * 1000 + 13)

char s[N];
int n;

int ord[N];
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

int get(int t, int ans) {
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
    if (!ans) return ord_size - pr;
    if (l != n || pr != ord_size) {
        return -1; // Assertion failure
    }
    int res[N][N];
    l = 0;
    for (int i = 0; i < ord_size; i++) {
        int x = ord[i];
        if (x == 1) {
            res[i][0] = 0;
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
        while (cnt0 < x / 2) L[cnt0++] = cnt0 + cnt1;
        while (cnt1 < (x + 1) / 2) R[cnt1++] = cnt0 + cnt1;
        int nw[N];
        int nw_size = 0;
        for (int j = 0; j < ord_size - 2; j++) {
            nw[nw_size++] = L[res[j][0]];
        }
        for (int j = 0; j < ord_size - 1; j++) {
            nw[nw_size++] = R[res[j][0]];
        }
        if (!fl) break;
        l = r;
    }
    printf("%d\n", t);
    for (int i = 0; i < res[0][0]; i++)
        printf("%d ", res[0][i] + 1);
    puts("");
    return 1;
}

void solve() {
    int l = 1, r = n + 1;
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (get(m, 0) == 0) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    get(res, 1);
}

int main() {
    while (scanf("%s", s) == 1) {
        n = strlen(s);
        solve();
    }
    return 0;
}
