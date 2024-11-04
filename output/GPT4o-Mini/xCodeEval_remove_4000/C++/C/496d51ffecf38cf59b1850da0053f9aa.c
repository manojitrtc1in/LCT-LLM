#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 101
#define eps 0.0000001

long powcnt[N];
long ans;

long fastpower(long b, long p) {
    long ans = 1;
    while (p) {
        if (p % 2) {
            ans = (ans * b);
        }
        b = b * b;
        p /= 2;
    }
    return ans;
}

long id0(long b, long p, long m) {
    long ans = 1;
    while (p) {
        if (p % 2) {
            ans = ((ans % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p /= 2;
    }
    return ans % m;
}

char* id1(long n) {
    static char ans[20];
    int index = 0;
    bool ch = false;
    if (n < 0) {
        n *= -1;
        ch = true;
    }
    if (n == 0) {
        ans[index++] = '0';
    }
    while (n) {
        long mo = n % 10;
        mo += 48;
        ans[index++] = (char)mo;
        n /= 10;
    }
    if (ch) {
        ans[index++] = '-';
    }
    ans[index] = '\0';

    // Reverse the string
    for (int i = 0; i < index / 2; i++) {
        char temp = ans[i];
        ans[i] = ans[index - i - 1];
        ans[index - i - 1] = temp;
    }
    return ans;
}

bool compare(double f, double s) {
    return (fabs(f - s) < eps);
}

long gcd(long a, long b) {
    while (b != 0) {
        long a2 = a;
        a = b;
        b = a2 % b;
    }
    return a;
}

void preprocess(long num) {
    for (long i = 30; i >= 0; i--) {
        if (num >= (1 << i)) {
            num -= (1 << i);
            powcnt[i]++;
        }
    }
}

void solve(long curp) {
    for (long i = curp; i <= 30; i++) {
        if (powcnt[i] > 0) {
            powcnt[i]--;
            ans++;
            for (long j = curp; j < i; j++) {
                powcnt[j]++;
            }
            break;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long x;
    for (int i = 0; i < n; i++) {
        scanf("%ld", &x);
        preprocess(x);
    }
    long* v = (long*)malloc(m * sizeof(long));
    for (int i = 0; i < m; i++) {
        scanf("%ld", &v[i]);
    }
    // Sort the array v
    qsort(v, m, sizeof(long), (int (*)(const void*, const void*))compare);
    for (int i = 0; i < m; i++) {
        solve(v[i]);
    }
    printf("%ld\n", ans);
    free(v);
    return 0;
}
