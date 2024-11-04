#include <stdio.h>

long long a, b;

int win(long long a, long long b) {
    if (a % 2) {
        long long cnt = 0;
        while (b) {
            cnt += b % a;
            b /= a;
        }
        return cnt % 2 == 0;
    } else {
        return b % (a + 1) % 2 == 0;
    }
}

int ss(long long a, long long b) {
    if (!a) {
        return 0;
    }
    if (!ss(b % a, a)) {
        return 1;
    }
    return win(a, b / a);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &a, &b);
        if (ss(a < b ? a : b, a > b ? a : b)) {
            puts("First");
        } else {
            puts("Second");
        }
    }
    return 0;
}