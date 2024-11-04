#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int a[1010101];
    long long b[1010101];
    int n, k;
    scanf("%d%d", &n, &k);
    ++k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    for (int i = 0; i < n; ++i) {
        b[n - 1 - i] = a[n - 1 - i] * 1LL * (i / max(k, 1));
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
            ans = max(ans, res + cum * longest);
            sum += cum;
            cum += a[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
