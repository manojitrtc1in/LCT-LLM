#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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

long gcd(long x, long y) {
    if (y == 0) return x;
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

long modInv(long x) {
    long result = 1, power = MOD - 2;
    while (power) {
        if (power % 2) result = (result * x) % MOD;
        x = (x * x) % MOD;
        power /= 2;
    }
    return result;
}

long pow(long x, long p) {
    if (p <= 0) return 1;
    long ans = pow(x, p / 2);
    ans = (ans * ans) % MOD;
    if (p % 2 == 1) ans = (ans * x) % MOD;
    return ans;
}

void add(Fenvik *fenvik, int x, long d) {
    for (int i = x; i < fenvik->size; i = (i | (i + 1))) {
        fenvik->sum[i] += d;
    }
}

long sumFenvik(Fenvik *fenvik, int r) {
    long ans = 0;
    for (int i = r; i >= 0; i = (i & (i + 1)) - 1) {
        ans += fenvik->sum[i];
    }
    return ans;
}

long sumRange(Fenvik *fenvik, int l, int r) {
    if (l > r) return 0;
    return sumFenvik(fenvik, r) - sumFenvik(fenvik, l - 1);
}

void solve() {
    char s[MAX_SIZE];
    scanf("%s", s);
    int l = 0, r = 100001;
    while (true) {
        int sz = (l + r) >> 1;
        int *a = (int *)malloc(sz * sizeof(int));
        for (int i = 0; i < sz; i++) {
            a[i] = i;
        }
        int x = 0;
        int *b = (int *)malloc(sz * sizeof(int));
        // mergeSort function would go here
        // if (!mergeSort(s, a, 0, sz)) {
        //     r = sz;
        //     continue;
        // }
        // if (x < strlen(s)) {
        //     l = sz;
        //     continue;
        // }
        // a = rev(a);
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
