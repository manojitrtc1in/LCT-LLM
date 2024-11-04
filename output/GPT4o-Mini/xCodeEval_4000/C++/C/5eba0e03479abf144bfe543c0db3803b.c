#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N (20 * 1000 * 1000 + 13)

char s[N];
int n;

void gen(int n, int* ord, int* size) {
    if (n == 1) {
        ord[(*size)++] = 1;
        return;
    }
    gen(n / 2, ord, size);
    gen((n + 1) / 2, ord, size);
    ord[(*size)++] = n;
}

void solve() {
    int ord[N], size = 0;
    for (int t = n + 1; t >= 1; --t) {
        size = 0;
        gen(t, ord, &size);
        int l = 0, pr = 0;
        for (int i = 0; i < size; i++) {
            int x = ord[i];
            if (x == 1) {
                ++pr;
                continue;
            }
            int cnt0 = 0, cnt1 = 0, r = l;
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
        if (l != n || pr != size) continue;

        int res[N][N], res_size = 0;
        l = 0;
        for (int i = 0; i < size; i++) {
            int x = ord[i];
            if (x == 1) {
                res[res_size][0] = 0;
                res_size++;
                continue;
            }
            int cnt0 = 0, cnt1 = 0, r = l;
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

            int nw[N], nw_size = 0;
            for (int j = 0; j < res[res_size - 2][0]; j++) nw[nw_size++] = L[res[res_size - 2][j]];
            for (int j = 0; j < res[res_size - 1][0]; j++) nw[nw_size++] = R[res[res_size - 1][j]];
            res_size -= 2;
            res[res_size][0] = nw_size;
            for (int j = 0; j < nw_size; j++) res[res_size][j + 1] = nw[j];
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
    while (scanf("%s", s) == 1) {
        n = strlen(s);
        solve();
    }
    return 0;
}
