#include <stdio.h>
#include <string.h>

#define N 1200

char str[N];
int use[1200];

int main() {
    scanf("%s", str);
    long long res = 1;
    memset(use, 0, sizeof(use));
    long long zero = 0, all = 10;
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        if (!i) {
            if (str[i] >= 'A' && str[i] <= 'J') {
                res *= 9;
                all--;
                use[str[i]] = 1;
            } else if (str[i] == '?') {
                res *= 9;
            }
        } else {
            if (str[i] >= 'A' && str[i] <= 'J') {
                if (use[str[i]]) {
                    continue;
                }
                use[str[i]] = 1;
                res *= all;
                all--;
            } else if (str[i] == '?') {
                zero++;
            }
        }
    }

    printf("%lld", res);
    for (int i = 0; i < zero; i++) {
        putchar('0');
    }
    puts("");

    return 0;
}
