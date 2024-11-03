#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        int M = n / 4 + 1;
        long long m = M;
        if (n % 4 <= 1) {
            printf("%lld\n", (m * m) % 1000000007);
        } else {
            printf("%lld\n", (m * (m + 1)) % 1000000007);
