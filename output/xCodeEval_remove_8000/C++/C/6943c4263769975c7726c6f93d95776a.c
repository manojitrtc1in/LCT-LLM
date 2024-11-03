#include <stdio.h>
#include <stdbool.h>

#define MN 300000010
#define B 100000

bool is[MN];

bool check(int x) {
    if (x == 2) {
        return true;
    }
    if (x % 4 != 1) {
        return false;
    }

    bool F = false;
    for (int d = 2; d * d <= x; ++d) {
        if (x % d == 0) {
            return false;
        }
        if (d * d != x && is[x - d * d]) {
            F = true;
        }
    }
    return F;
}

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    int ret = 0;
    int pl = l / B;
    int pr = r / B;
    for (int d = 1; d * d < MN; ++d) {
        is[d * d] = true;
    }

    if (l / B == r / B) {
        for (int i = l; i <= r; ++i) {
            ret += check(i);
        }
        printf("%d\n", ret);
        return 0;
    }
    for (int i = pl + 1; i < pr; ++i) {
        ret += prec[i];
    }
    for (int i = l; i / B == pl; ++i) {
        ret += check(i);
    }
    for (int i = r; i / B == pr; --i) {
        ret += check(i);
    }
    printf("%d\n", ret);
    return 0;
}
