#include <stdio.h>

int solve() {
    int x, y, k, res = 0;
    char ch = getchar();
    if(ch == '0') return 1 << 0;
    if(ch == '1') return 1 << 15;
    if(ch == '?') return (1 << 3) | (1 << 12);

    x = solve(), ch = getchar(), y = solve(); getchar();

    for(int i = 0; i < 16; i++) {
        if((x & (1 << i)) != 0) {
            for(int j = 0; j < 16; j++) {
                if((y & (1 << j)) != 0) {
                    if(ch == '^') k = i ^ j;
                    if(ch == '&') k = i & j;
                    if(ch == '|') k = i | j;
                    res |= (1 << k);
                }
            }
        }
    }

    return res;
}

int main() {
    int n;
    scanf("%d\n", &n);
    puts((~0x8421 & solve()) ? "YES" : "NO");
    return 0;
}
