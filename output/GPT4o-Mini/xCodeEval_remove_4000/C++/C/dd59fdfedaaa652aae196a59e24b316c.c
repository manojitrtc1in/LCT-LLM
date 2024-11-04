#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REP(i, n) for(int i = 0; i < (n); i++)

typedef long long LL;
typedef double DB;

inline int _1(int x, int i) { return x & (1 << i); }
inline int _1(LL x, int i) { return x & (1LL << i); }
inline LL _1(int i) { return 1LL << i; }

inline int solve() {
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
    int input;
    scanf("%d\n", &input);
    puts(~0x8421 & solve() ? "YES" : "NO");
}
