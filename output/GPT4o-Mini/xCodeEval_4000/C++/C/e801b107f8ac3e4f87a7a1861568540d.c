#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007
#define MX 200005
#define INF 1000000000000000000
#define PI 3.14159265358979323846

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

void read(long long *x) {
    scanf("%lld", x);
}

void solve() {
    long long n, s, k;
    read(&n);
    read(&s);
    read(&k);
    
    long long m[MX] = {0};
    long long ans = MOD;
    long long cnt = 0;

    for (long long i = 1; i <= n; i++) {
        read(&a[i]);
        if (i >= k) {
            m[a[i - k]]--;
            if (m[a[i - k]] == 0) cnt--;
            m[a[i]]++;
            if (m[a[i]] == 1) cnt++;
            ans = (ans < cnt) ? ans : cnt;
        } else {
            m[a[i]]++;
            if (m[a[i]] == 1) cnt++;
        }
    }
    ans = (ans < cnt) ? ans : cnt;
    printf("%lld\n", ans);
}

int main() {
    long long t = 1;
    scanf("%lld", &t);
    for (long long i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
