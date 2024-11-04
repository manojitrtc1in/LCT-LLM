#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MOD 1000000007
#define MOD2 998244353

long *fact;
long *invFact;

void init(int n);
long nCr(int n, int r);
long add(long a, long b);
long mul(long a, long b);
long power(long x, long y);
long gcd(long a, long b);
long gcd_int(int a, int b);
void input_long(long *a, int n);
void input_int(int *a, int n);
void input_string(char **s, int n);
void input_int_matrix(int **a, int n, int m);
void input_long_matrix(long **a, int n, int m);
void sort_long(long *a, int n);
void print_long(long *a, int n);
void print_int(int *a, int n);

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    long *a = (long *)malloc(n * sizeof(long));
    input_long(a, n);
    sort_long(a, n);
    
    for (int i = 0; i < n / 2; i++) {
        long temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    
    long *pq = (long *)malloc((k + 1) * sizeof(long));
    for (int i = 0; i <= k; i++) {
        pq[i] = 0;
    }
    
    long gg = 0;
    for (int i = 0; i < n; i++) {
        long cur = pq[0];
        for (int j = 0; j < k; j++) {
            pq[j] = pq[j + 1];
        }
        gg += cur;
        cur += a[i];
        pq[k] = cur;
    }
    
    printf("%ld\n", gg);
    
    free(a);
    free(pq);
    return 0;
}

void sort_long(long *a, int n) {
    qsort(a, n, sizeof(long), (int (*)(const void *, const void *))compare_long);
}

int compare_long(const long *a, const long *b) {
    return (*a > *b) - (*a < *b);
}

void input_long(long *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
}

void input_int(int *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void input_string(char **s, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
}

void input_int_matrix(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void input_long_matrix(long **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%ld", &a[i][j]);
        }
    }
}

void print_long(long *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%ld ", a[i]);
    }
    printf("\n");
}

void print_int(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void init(int n) {
    fact = (long *)malloc((n + 1) * sizeof(long));
    invFact = (long *)malloc((n + 1) * sizeof(long));
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(i, fact[i - 1]);
    }
    invFact[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = mul(invFact[i + 1], i + 1);
    }
}

long nCr(int n, int r) {
    if (n < r || r < 0) return 0;
    return mul(fact[n], mul(invFact[r], invFact[n - r]));
}

long add(long a, long b) {
    return (a + b) % MOD;
}

long mul(long a, long b) {
    return a * b % MOD;
}

long power(long x, long y) {
    long gg = 1;
    while (y > 0) {
        if (y % 2 == 1) gg = mul(gg, x);
        x = mul(x, x);
        y /= 2;
    }
    return gg;
}

long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int gcd_int(int a, int b) {
    return b == 0 ? a : gcd_int(b, a % b);
}
