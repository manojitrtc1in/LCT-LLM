#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N (20 * 1000 * 1000 + 13)

char s[N];
int n;

typedef struct {
    int x;
    int y;
} pt;

typedef long long li;
typedef long double ld;

pt make_pair(int x, int y) {
    pt p;
    p.x = x;
    p.y = y;
    return p;
}

void push_back(int* arr, int* size, int value) {
    arr[*size] = value;
    (*size)++;
}

int sqr(int a) {
    return a * a;
}

int size(int* arr) {
    return *arr;
}

void gen(int n, int* ord, int* size) {
    if (n == 1) {
        push_back(ord, size, 1);
        return;
    }
    gen(n / 2, ord, size);
    gen((n + 1) / 2, ord, size);
    push_back(ord, size, n);
}

void solve() {
    int t;
    for (t = n + 1; t >= 1; --t) {
        int ord[N];
        int ord_size = 0;
        gen(t, ord, &ord_size);
        int l = 0;
        int pr = 0;
        int i;
        for (i = 0; i < ord_size; i++) {
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
                }
                else {
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
        int res[N][N];
        int res_size = 0;
        l = 0;
        for (i = 0; i < ord_size; i++) {
            int x = ord[i];
            if (x == 1) {
                res[res_size][0] = 0;
                res_size++;
                continue;
            }
            int cnt0 = 0, cnt1 = 0;
            int r = l;
            int fl = 0;
            int L[N], R[N];
            while (r < n) {
                if (s[r++] == '0') {
                    L[cnt0] = cnt0 + cnt1;
                    ++cnt0;
                    if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                        fl = 1;
                        break;
                    }
                }
                else {
                    R[cnt1] = cnt0 + cnt1;
                    ++cnt1;
                    if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                        fl = 1;
                        break;
                    }
                }
            }
            while (cnt0 < x / 2) {
                L[cnt0] = cnt0 + cnt1;
                ++cnt0;
            }
            while (cnt1 < (x + 1) / 2) {
                R[cnt1] = cnt0 + cnt1;
                ++cnt1;
            }
            int nw[N];
            int nw_size = 0;
            int j;
            for (j = 0; j < size(res[res_size - 2]); j++) {
                push_back(nw, &nw_size, L[res[res_size - 2][j]]);
            }
            for (j = 0; j < size(res[res_size - 1]); j++) {
                push_back(nw, &nw_size, R[res[res_size - 1][j]]);
            }
            res_size -= 2;
            memcpy(res[res_size], nw, nw_size * sizeof(int));
            res_size++;
            if (!fl) break;
            l = r;
        }
        printf("%d\n", t);
        for (i = 0; i < size(res[0]); i++) {
            printf("%d ", res[0][i] + 1);
        }
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
