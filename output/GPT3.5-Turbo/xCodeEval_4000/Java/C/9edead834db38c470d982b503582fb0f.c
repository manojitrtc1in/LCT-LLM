#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define mod (int)pow(10, 9) + 7

int main() {
    long long n;
    int m;
    scanf("%lld %d", &n, &m);
    long long a[m];

    for (int i = 0; i < m; i++)
        a[i] = n / m;
    for (int i = 1; i <= n % m; i++)
        a[i]++;

    long long b[m];
    for (int i = 0; i < m; i++) {
        int t = ((i) % m * (i) % m) % m;
        b[t] += a[i];
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            ans += (b[i] * (b[i]));
        } else {
            ans += b[i] * b[m - i];
        }
    }
    printf("%lld\n", ans);

    return 0;
}
