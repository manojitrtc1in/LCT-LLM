#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INPUT "100000000000"

int is[1024];
int lenbuf = 0, ptrbuf = 0;

int readByte() {
    if (lenbuf == -1) {
        return -1;
    }
    if (ptrbuf >= lenbuf) {
        ptrbuf = 0;
        lenbuf = fread(is, sizeof(char), 1024, stdin);
        if (lenbuf <= 0) {
            return -1;
        }
    }
    return is[ptrbuf++];
}

bool isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while ((b = readByte()) != -1 && isSpaceChar(b));
    return b;
}

double nd() {
    return atof(ns());
}

char nc() {
    return (char) skip();
}

char* ns() {
    int b = skip();
    int p = 0;
    static char buf[1024];
    while (!(isSpaceChar(b))) {
        buf[p++] = (char) b;
        b = readByte();
    }
    buf[p] = '\0';
    return buf;
}

char** nm(int n, int m) {
    char** map = (char**) malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        map[i] = ns();
    }
    return map;
}

int* na(int n) {
    int* a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = ni();
    }
    return a;
}

int ni() {
    int num = 0, b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

long nl() {
    long num = 0;
    int b;
    bool minus = false;
    while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = true;
        b = readByte();
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte();
    }
}

long long int picache[1000000];
long long int phicache[1000000];
int primes[1000000];
int primesSize = 0;

int sieveEratosthenes(int n) {
    if (n <= 32) {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = 0; i < sizeof(primes) / sizeof(primes[0]); i++) {
            if (n < primes[i]) {
                return i;
            }
        }
        return sizeof(primes) / sizeof(primes[0]);
    }

    int u = n + 32;
    double lu = log(u);
    int ret[(int) (u / lu + u / lu / lu * 1.5)];
    ret[0] = 2;
    int pos = 1;

    int isnp[(n + 1) / 32 / 2 + 1];
    int sup = (n + 1) / 32 / 2 + 1;

    int tprimes[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    for (int tp : tprimes) {
        ret[pos++] = tp;
        int ptn[tp];
        for (int i = (tp - 3) / 2; i < tp << 5; i += tp) {
            ptn[i >> 5] |= 1 << (i & 31);
        }
        for (int j = 0; j < sup; j += tp) {
            for (int i = 0; i < tp && i + j < sup; i++) {
                isnp[j + i] |= ptn[i];
            }
        }
    }

    int magic[] = {0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4, 13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14};
    int h = n / 2;
    for (int i = 0; i < sup; i++) {
        for (int j = ~isnp[i]; j != 0; j &= j - 1) {
            int pp = i << 5 | magic[(j & -j) * 0x076be629 >> 27];
            int p = 2 * pp + 3;
            if (p > n) {
                break;
            }
            ret[pos++] = p;
            if ((long) p * p > n) {
                continue;
            }
            for (int q = (p * p - 3) / 2; q <= h; q += p) {
                isnp[q >> 5] |= 1 << q;
            }
        }
    }

    for (int i = 0; i < pos; i++) {
        primes[i] = ret[i];
    }
    return pos;
}

long long int pi(long long int x) {
    if (x <= 1000000) {
        return picache[x];
    }
    if (picache[x] != -1) {
        return picache[x];
    }

    int A = (int) pi(sqrt(sqrt(x)));
    long long int ret = A + phi(x, A) - P2(x, A) - P3(x, A) - 1;
    picache[x] = ret;
    return ret;
}

long long int phi(long long int x, int A) {
    if (A > 0 && A - 1 < primesSize) {
        return phicache[A - 1] * (x / primes[A - 1]) + phicache[A - 1 + 1 + (x % primes[A - 1] != 0)];
    }
    if (A > 0 && x <= (long long int) primes[A - 1] * primes[A - 1]) {
        return pi(x) - A + 1;
    }

    long long int ret = x;
    for (int i = A - 1; i >= 0; i--) {
        ret -= phi(x / primes[i], i);
    }
    return ret;
}

long long int P2(long long int x, int A) {
    int B = (int) pi(sqrt(x));
    long long int ret = 0;
    for (int i = A; i < B; i++) {
        ret += pi(x / primes[i]);
    }
    ret -= (long long int) (B - A) * (B + A - 1) / 2;
    return ret;
}

long long int P3(long long int x, int A) {
    int C = (int) pi(cbrt(x));
    long long int ret = 0;
    for (int i = A; i < C; i++) {
        long long int xi = x / primes[i];
        int B = (int) pi(sqrt(xi));
        for (int j = i; j < B; j++) {
            ret += pi(xi / primes[j]) - j;
        }
    }
    return ret;
}

void solve() {
    long long int n = nl();
    long long int ans = 0;
    for (int i = 0; i < primesSize; i++) {
        long long int plus = pi(n / primes[i]) - (i + 1);
        if (plus <= 0) {
            break;
        }
        ans += plus;
    }

    for (int i = 0; i < primesSize; i++) {
        if ((long long int) primes[i] * primes[i] * primes[i] <= n) {
            ans++;
        } else {
            break;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 1000000; i++) {
        picache[i] = -1;
        phicache[i] = -1;
    }
    primesSize = sieveEratosthenes(400000);
    for (int i = 0; i < primesSize; i++) {
        phicache[i] = primes[i] - 1;
    }

    solve();

    return 0;
}
