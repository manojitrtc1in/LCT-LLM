#include <stdio.h>

#define _1(x, i) ((x) & (1 << (i)))

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
    int t;
    scanf("%d\n", &t);
    puts((~0x8421 & solve()) ? "YES" : "NO");
}
