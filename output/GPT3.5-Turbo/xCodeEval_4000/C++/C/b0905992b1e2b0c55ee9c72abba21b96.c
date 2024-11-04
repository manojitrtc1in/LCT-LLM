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

void push_back(int *arr, int *size, int value) {
    arr[*size] = value;
    (*size)++;
}

int sqr(int a) {
    return a * a;
}

int size(int a) {
    return (int)(sizeof(a) / sizeof(a[0]));
}

void gen(int n, int *ord, int *size) {
    if (n == 1) {
        push_back(ord, size, 1);
        return;
    }
    gen(n / 2, ord, size);
    gen((n + 1) / 2, ord, size);
    push_back(ord, size, n);
}

int get(int t, int ans) {
    int ord[N];
    int ord_size = 0;
    gen(t, ord, &ord_size);
    int l = 0;
    int pr = 0;
    for (int i = 0; i < ord_size; i++) {
        int x = ord[i];
        if (x == 1) {
            pr++;
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        int r = l;
        int fl = 0;
        while (r < n) {
            if (s[r++] == '0') {
                cnt0++;
                if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                    fl = 1;
                    break;
                }
            } else {
                cnt1++;
                if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                    fl = 1;
                    break;
                }
            }
        }
        if (!fl) break;
        l = r;
        pr++;
    }
    if (!ans) return ord_size - pr;
    if (l != n || pr != ord_size) {
        printf("Error: l = %d, n = %d, pr = %d, ord_size = %d\n", l, n, pr, ord_size);
        exit(1);
    }
    int res[N][N];
    int res_size = 0;
    l = 0;
    for (int i = 0; i < ord_size; i++) {
        int x = ord[i];
        if (x == 1) {
            push_back(res[res_size], &res[res_size][0], 0);
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
                cnt0++;
                if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                    fl = 1;
                    break;
                }
            } else {
                R[cnt1] = cnt0 + cnt1;
                cnt1++;
                if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                    fl = 1;
                    break;
                }
            }
        }
        while (cnt0 < x / 2) {
            L[cnt0] = cnt0 + cnt1;
            cnt0++;
        }
        while (cnt1 < (x + 1) / 2) {
            R[cnt1] = cnt0 + cnt1;
            cnt1++;
        }
        int nw[N];
        int nw_size = 0;
        for (int j = 0; j < res_size - 2; j++) {
            push_back(nw, &nw_size, res[res_size - 2][j]);
        }
        for (int j = 0; j < res_size - 1; j++) {
            push_back(nw, &nw_size, res[res_size - 1][j]);
        }
        res_size -= 2;
        for (int j = 0; j < nw_size; j++) {
            res[res_size][j] = nw[j];
        }
        res_size++;
        if (!fl) break;
        l = r;
    }
    printf("%d\n", t);
    for (int j = 0; j < res_size; j++) {
        for (int k = 0; k < size(res[j]); k++) {
            printf("%d ", res[j][k] + 1);
        }
    }
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
