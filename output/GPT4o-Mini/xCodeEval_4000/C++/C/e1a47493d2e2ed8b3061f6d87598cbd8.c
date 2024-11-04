#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1010101

int a[MAX_SIZE];
long long b[MAX_SIZE];

int compare(const void *p1, const void *p2) {
    return (*(int *)p2 - *(int *)p1);
}

int solve() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    ++k;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    qsort(a, n, sizeof(int), compare);

    for (int i = 0; i < n; ++i) {
        b[n - 1 - i] = a[n - 1 - i] * 1LL * (i / (k > 0 ? k : 1));
    }

    for (int i = n - 1; i >= 0; --i) {
        b[i] += b[i + 1];
    }

    long long cum = 0;
    long long sum = 0;
    long long ans = b[0];

    if (k > 0) {
        for (int i = 0; i < n; ++i) {
            long long res = sum + b[i];
            int longest = (n - i - 1) / k + 1;
            if (res + cum * longest > ans) {
                ans = res + cum * longest;
            }
            sum += cum;
            cum += a[i];
        }
    }

    printf("%lld\n", ans);
    return 0;
}

int main(int argc, char **argv) {
    return solve();
}
