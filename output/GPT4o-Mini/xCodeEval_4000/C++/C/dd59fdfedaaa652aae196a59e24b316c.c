#include <stdio.h>
#include <string.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define _1(x, i) ((x) & (1 << (i)))

int solve() {
    int x, y, k, res = 0;
    char ch = getchar();
    if (ch == '0') return 1 << 0;
    if (ch == '1') return 1 << 15;
    if (ch == '?') return (1 << 3) | (1 << 12);

    x = solve(), ch = getchar(), y = solve(); getchar();

    REP(i, 16) if (_1(x, i)) REP(j, 16) if (_1(y, j)) {
        if (ch == '^') k = i ^ j;
        if (ch == '&') k = i & j;
        if (ch == '|') k = i | j;
        res |= _1(k);
    }

    return res;
}

int main() {
    int T;
    scanf("%d\n", &T);
    puts((~0x8421 & solve()) ? "YES" : "NO");
}
