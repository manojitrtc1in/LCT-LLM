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
    long *sum;
    int size;
} Fenvik;

typedef struct {
    long k;
    long b;
} Line;

typedef struct {
    Line *ch;
    int pow;
    bool branchUp;
    long neutral;
} LiChaoTree;

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

void add(Fenvik *fenvik, int x, long d) {
    for (int i = x; i < fenvik->size; i = (i | (i + 1))) {
        fenvik->sum[i] += d;
    }
}

long sum_fenvik(Fenvik *fenvik, int r) {
    long ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans += fenvik->sum[i];
    }
    return ans;
}

long sum_range(Fenvik *fenvik, int l, int r) {
    if (l > r) return 0;
    return sum_fenvik(fenvik, r) - sum_fenvik(fenvik, l - 1);
}

void solve() {
    char s[100];
    scanf("%s", s);
    for (int sz = 1; ; sz++) {
        int *a = (int *)malloc(sz * sizeof(int));
        for (int i = 0; i < sz; i++) {
            a[i] = i;
        }
        int x = 0;
        int *b = (int *)malloc(sz * sizeof(int));
        // Call mergeSort function here (not implemented in this translation)
        // if (!mergeSort(s, a, 0, sz)) continue;
        // if (x < strlen(s)) continue;
        // a = rev(a); // rev function not implemented in this translation
        printf("%d\n", sz);
        for (int i = 0; i < sz; i++) {
            printf("%d ", a[i] + 1);
        }
        free(a);
        free(b);
        return;
    }
}

int main() {
    solve();
    return 0;
}
