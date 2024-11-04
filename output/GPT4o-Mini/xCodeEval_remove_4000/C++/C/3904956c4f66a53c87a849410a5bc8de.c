#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(A) (A).begin(), (A).end()

typedef long long LL;
typedef double DB;

void RD(int *x) {
    scanf("%d", x);
}

void OT(const int x) {
    printf("%d\n", x);
}

int _1(int x, int i) {
    return x & (1 << i);
}

int solve() {
    int x, y, i, j, k = 0, res = 0;
    char ch = getchar();
    if (ch == '0') return 1 << 0;
    if (ch == '1') return 1 << 15;
    if (ch == '?') return (1 << 3) | (1 << 12);

    x = solve();
    ch = getchar();
    y = solve();

    for (i = 0; i < 16; i++) {
        if (!_1(x, i)) continue;
        for (j = 0; j < 16; j++) {
            if (!_1(y, j)) continue;
            if (ch == '^') k = i ^ j;
            if (ch == '&') k = i & j;
            if (ch == '|') k = i | j;
            res |= 1 << k;
        }
    }
    getchar();
    return res;
}

int main() {
    int input;
    RD(&input);
    puts((~0x8421 & solve()) ? "YES" : "NO");
}
