#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define WALL -1
#define EMPTY -2
#define VISITED 1
#define FULL 2
#define START 1
#define END 0
#define UNVISITED -2

long cnt(long v, long n);
long pow(long v, long p);
long inv(long v);
long gcd(long x, long y);
long max(long a, long b);
long min(long a, long b);
void build_pow2_function(int n);
void build_fac_function(int n);
void build_ifac_function(int n);
void build_sieve_function(int n);
void build_mobius_function(int n);
void fill(char *a, int lo, int c, char letter);
int cntBitOne(const char *s);
void swap(char *a, int i, int j);
void reverse(char *a, int i, int j);
int nBit1(int v);
long abs(long v);
int abs_int(int v);
int common(int v);
int mul(int x, int y);
int max_int(int a, int b);
int min_int(int a, int b);
void fastReader(long *n, long *k);

int main() {
    long n, k;
    fastReader(&n, &k);

    if (k == 1) {
        printf("%ld\n", n);
        return 0;
    }

    long lo = 1, hi = n / 2;

    while (lo <= hi) {
        long mid = (hi + lo) / 2;
        long val = mid * 2 - 1;

        if (cnt(val, n) >= k) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    long cand = hi * 2 - 1;
    if (cnt(cand, n) < k) cand = 0;

    lo = 1;
    hi = n / 2;

    while (lo <= hi) {
        long mid = (hi + lo) / 2;
        long val = mid * 2;
        if (cnt(val, n) >= k)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    cand = max(cand, hi * 2);
    printf("%ld\n", cand);

    return 0;
}

long cnt(long v, long n) {
    if (v > n) return 0;

    long cnt = 0;
    if (v % 2 == 1) {
        long segSize = 1;
        long start = v;
        while (start <= n) {
            long end = fmin(n, start + segSize - 1);
            cnt += end - start + 1;

            segSize *= 2;
            start *= 2;
        }
    } else {
        long segSize = 2;
        long start = v;
        while (start <= n) {
            long end = fmin(n, start + segSize - 1);
            cnt += end - start + 1;

            segSize *= 2;
            start *= 2;
        }
    }

    return cnt;
}

void fastReader(long *n, long *k) {
    scanf("%ld %ld", n, k);
}

long pow(long v, long p) {
    long ans = 1;
    while (p > 0) {
        if (p % 2 == 1)
            ans = ans * v % MOD;
        v = v * v % MOD;
        p /= 2;
    }
    return ans;
}

long inv(long v) {
    return pow(v, MOD - 2);
}

long gcd(long x, long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

long max(long a, long b) {
    return a > b ? a : b;
}

long min(long a, long b) {
    return a > b ? b : a;
}

void fill(char *a, int lo, int c, char letter) {
    for (int i = lo; i < lo + c; i++) a[i] = letter;
}

int cntBitOne(const char *s) {
    int c = 0, n = strlen(s);
    for (int i = 0; i < n; i++)
        if (s[i] == '1') c++;
    return c;
}

void swap(char *a, int i, int j) {
    char t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void reverse(char *a, int i, int j) {
    while (i < j) {
        swap(a, i++, j--);
    }
}

int nBit1(int v) {
    int v0 = v;
    int c = 0;
    while (v != 0) {
        ++c;
        v = v & (v - 1);
    }
    return c;
}

long abs(long v) {
    return v > 0 ? v : -v;
}

int abs_int(int v) {
    return v > 0 ? v : -v;
}

int common(int v) {
    int c = 0;
    while (v != 1) {
        v = (v >> 1);
        ++c;
    }
    return c;
}

int mul(int x, int y) {
    return (int)(1L * x * y % MOD);
}

int max_int(int a, int b) {
    return a > b ? a : b;
}

int min_int(int a, int b) {
    return a > b ? b : a;
}
