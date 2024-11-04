#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007

typedef struct {
    long x;
    long y;
} Fraction;

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int x1, y1, x2, y2;
} Rect;

typedef struct {
    int x, y, r;
} Circle;

typedef struct {
    long k, b;
} Line;

long pow_mod(long x, long p, long mod) {
    if (p <= 0) return 1;
    long th = pow_mod(x, p / 2, mod);
    th = (th * th) % mod;
    if (p % 2 == 1) th = (th * x) % mod;
    return th;
}

void norm(Fraction *f) {
    long gcd = gcd(f->x, f->y);
    f->x /= gcd;
    f->y /= gcd;
}

int compare_fractions(const void *a, const void *b) {
    Fraction *f1 = (Fraction *)a;
    Fraction *f2 = (Fraction *)b;
    if (f1->x > f2->x) return 1;
    if (f1->x < f2->x) return -1;
    if (f1->y > f2->y) return 1;
    if (f1->y < f2->y) return -1;
    return 0;
}

Fraction sum(Fraction a, Fraction b) {
    Fraction c;
    c.x = a.x * b.y + a.y * b.x;
    c.y = a.y * b.y;
    norm(&c);
    return c;
}

long gcd(long x, long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void merge_sort(char *s, int *a, int l, int r, int *x, int *b) {
    if (r - l <= 1) return;
    int m = (l + r) >> 1;
    merge_sort(s, a, l, m, x, b);
    merge_sort(s, a, m, r, x, b);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (*x == strlen(s)) return;
        if (s[(*x)++] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i < m) b[k++] = a[i++];
    while (j < r) b[k++] = a[j++];
    for (int p = l; p < r; p++) a[p] = b[p];
}

int *rev(int *a, int len) {
    int *res = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; ++i) {
        res[a[i]] = i;
    }
    return res;
}

void solve() {
    char s[100000];
    scanf("%s", s);
    for (int sz = 1; ; sz++) {
        int *a = (int *)malloc(sz * sizeof(int));
        for (int i = 0; i < sz; i++) {
            a[i] = i;
        }
        int x = 0;
        int *b = (int *)malloc(sz * sizeof(int));
        if (!merge_sort(s, a, 0, sz, &x, b)) {
            free(a);
            free(b);
            continue;
        }
        if (x < strlen(s)) {
            free(a);
            free(b);
            continue;
        }
        int *rev_a = rev(a, sz);
        printf("%d\n", sz);
        for (int i = 0; i < sz; i++) {
            printf("%d ", rev_a[i] + 1);
        }
        free(a);
        free(b);
        free(rev_a);
        return;
    }
}

int main() {
    solve();
    return 0;
}
