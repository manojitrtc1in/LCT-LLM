#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MOD 1000000007
#define MX 200005
#define INF 1000000000000000000LL
#define PI acos(-1.0)

long long a[MX];

long long nod(long long a, long long b) {
    if (b > a) {
        long long temp = a;
        a = b;
        b = temp;
    }
    while (b > 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long nok(long long a, long long b) {
    return a * b / nod(a, b);
}

long long binpow(long long a, long long n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 1) {
        return binpow(a, n - 1) * a;
    } else {
        long long b = binpow(a, n / 2);
        return b * b;
    }
}

void read(long long *x) {
    scanf("%lld", x);
}

void read_double(double *d) {
    char t[50];
    scanf("%s", t);
    *d = atof(t);
}

void print(long long x) {
    printf("%lld\n", x);
}

void solve() {
    long long m[MX] = {0};
    long long n, s, k;
    read(&n);
    read(&s);
    read(&k);
    long long ans = MOD;
    long long cnt = 0;

    for (long long i = 1; i <= n; i++) {
        read(&a[i]);
        if (i >= k) {
            m[a[i - k]]--;
            if (m[a[i - k]] == 0) cnt--;
            m[a[i]]++;
            if (m[a[i]] == 1) cnt++;
            ans = fmin(ans, cnt);
        } else {
            m[a[i]]++;
            if (m[a[i]] == 1) cnt++;
        }
    }
    ans = fmin(ans, cnt);
    print(ans);
}

int main() {
    long long t = 1;
    scanf("%lld", &t);
    for (long long i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
