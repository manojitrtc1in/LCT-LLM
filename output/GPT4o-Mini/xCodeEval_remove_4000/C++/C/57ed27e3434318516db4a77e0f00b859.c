#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SZ(x) ((int)(x).size())

typedef long long LL;

char str[1200];
int use[1200];

int main() {
    scanf("%s", str);
    LL res = 1;
    memset(use, 0, sizeof(use));
    LL zero = 0, all = 10;
    int n = strlen(str);

    REP(i, n) {
        if (i == 0) {
            if (str[i] >= 'A' && str[i] <= 'J') {
                res *= 9;
                all--;
                use[str[i]] = 1;
            } else if (str[i] == '?') {
                res *= 9;
            }
        } else {
            if (str[i] >= 'A' && str[i] <= 'J') {
                if (use[str[i]]) continue;
                use[str[i]] = 1;
                res *= all;
                all--;
            } else if (str[i] == '?') {
                ++zero;
            }
        }
    }
    
    printf("%lld", res);
    while (zero--) putchar('0');
    puts("");
    
    return 0;
}
