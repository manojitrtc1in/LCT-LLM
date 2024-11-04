#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX_SIZE 100001

typedef struct {
    long x;
    long y;
} Fraction;

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    long k;
    long b;
} Line;

long pow_mod(long x, long p, long mod) {
    if (p <= 0) {
        return 1;
    }
    long th = pow_mod(x, p / 2, mod);
    th = (th * th) % mod;
    if (p % 2 == 1) {
        th = (th * x) % mod;
    }
    return th;
}

long gcd(long x, long y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

void norm(Fraction *f) {
    long g = gcd(f->x, f->y);
    f->x /= g;
    f->y /= g;
}

Fraction sum(Fraction a, Fraction b) {
    Fraction c;
    c.x = a.x * b.y + a.y * b.x;
    c.y = a.y * b.y;
    norm(&c);
    return c;
}

long* mult1(long* a, long* b, int n) {
    long* c = (long*)calloc(n, sizeof(long));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            c[i] = (c[i] + a[i ^ k] * b[k]) % MOD;
        }
    }
    return c;
}

long** mult(long** a, long** b, int n) {
    long** c = (long**)malloc(n * sizeof(long*));
    for (int i = 0; i < n; i++) {
        c[i] = (long*)calloc(n, sizeof(long));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

long** pow_matrix(long** x, long p, int size) {
    if (p == 0) {
        long** e = (long**)malloc(size * sizeof(long*));
        for (int i = 0; i < size; i++) {
            e[i] = (long*)calloc(size, sizeof(long));
            e[i][i] = 1;
        }
        return e;
    }
    long** ans = pow_matrix(x, p / 2, size);
    ans = mult(ans, ans, size);
    if (p % 2 == 1) {
        ans = mult(ans, x, size);
    }
    return ans;
}

long* mult_array(long* a, long* b, int n) {
    long* c = (long*)calloc(n, sizeof(long));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            c[i] = (c[i] + a[k] * b[k ^ i]) % MOD;
        }
    }
    return c;
}

long* pow_array(long* x, long p, int size) {
    if (p == 0) {
        long* e = (long*)calloc(size, sizeof(long));
        e[0] = 1;
        return e;
    }
    long* ans = pow_array(x, p / 2, size);
    ans = mult_array(ans, ans, size);
    if (p % 2 == 1) {
        ans = mult_array(ans, x, size);
    }
    return ans;
}

long mod_inv(long x) {
    return pow_mod(x, MOD - 2, MOD);
}

int mergeSort(char* s, int* a, int l, int r, int* x, int* b) {
    if (r - l <= 1) {
        return 1;
    }
    int m = (l + r) >> 1;
    if (!mergeSort(s, a, l, m, x, b)) {
        return 0;
    }
    if (!mergeSort(s, a, m, r, x, b)) {
        return 0;
    }
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (*x == strlen(s)) {
            return 0;
        }
        if (s[(*x)++] == '0') {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i < m) {
        b[k++] = a[i++];
    }
    while (j < r) {
        b[k++] = a[j++];
    }
    for (int p = l; p < r; p++) {
        a[p] = b[p];
    }
    return 1;
}

int* rev(int* a, int size) {
    int* res = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        res[a[i]] = i;
    }
    return res;
}

void solve() {
    char s[MAX_SIZE];
    scanf("%s", s);
    int l = 0, r = 100001;
    while (1) {
        int sz = (l + r) >> 1;
        int* a = (int*)malloc(sz * sizeof(int));
        for (int i = 0; i < sz; i++) {
            a[i] = i;
        }
        int x = 0;
        int* b = (int*)malloc(sz * sizeof(int));
        if (!mergeSort(s, a, 0, sz, &x, b)) {
            r = sz;
            continue;
        }
        if (x < strlen(s)) {
            l = sz;
            continue;
        }
        int* rev_a = rev(a, sz);
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
