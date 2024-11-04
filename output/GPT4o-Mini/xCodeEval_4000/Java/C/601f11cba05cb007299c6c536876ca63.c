#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

long gcd(long a, long b) {
    if (a < b) {
        long c = b;
        b = a;
        a = c;
    }
    while (a % b != 0) {
        a = a % b;
        if (a < b) {
            long c = b;
            b = a;
            a = c;
        }
    }
    return b;
}

void solve() {
    int w;
    scanf("%d", &w);
    if (w == 2) {
        printf("NO\n");
        return;
    }
    if (w % 2 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    solve();
    return 0;
}
