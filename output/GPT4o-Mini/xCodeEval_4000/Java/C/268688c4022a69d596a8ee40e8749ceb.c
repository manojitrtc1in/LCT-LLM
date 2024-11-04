#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long repow(long b, long p) {
    long a = b;
    long res = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            res *= a;
        }
        a *= a;
        p /= 2;
    }
    return res;
}

long gcd(long c, long d) {
    while (true) {
        long f = c % d;
        if (f == 0) {
            return d;
        }
        c = d;
        d = f;
    }
}

long lcm(long c, long d) {
    return c / gcd(c, d) * d;
}

int* divList(int n, int* size) {
    int* div = (int*)malloc(100 * sizeof(int)); // Assuming a maximum of 100 divisors
    *size = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div[(*size)++] = i;
            if (i * i != n) {
                div[(*size)++] = n / i;
            }
        }
    }
    return div;
}

bool isPrime(long n) {
    if (n == 2) {
        return true;
    }
    if ((n & 1) == 0 || n == 1) {
        return false;
    }
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    scanf("%d", &n);
    int* dq = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &dq[i]);
    }
    
    int a = dq[0];
    int b = 0;
    int pre = a;
    int now;
    int cnt = 1;
    int front = 1, back = n - 1;

    while (front <= back) {
        now = 0;
        while (now <= pre && back >= front) {
            now += dq[back--];
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
        }

        if (front > back) {
            break;
        }

        now = 0;
        while (now <= pre && back >= front) {
            now += dq[front++];
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
        }
    }

    printf("%d %d %d\n", cnt, a, b);
    free(dq);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
