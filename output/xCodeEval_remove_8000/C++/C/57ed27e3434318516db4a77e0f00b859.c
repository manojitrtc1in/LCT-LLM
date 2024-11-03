#include <stdio.h>
#include <string.h>

#define N 1200

int main() {
    char str[N];
    scanf("%s", str);
    long long res = 1;
    int use[26] = {0};
    int zero = 0, all = 10;
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (str[i] >= 'A' && str[i] <= 'J') {
                res *= 9;
                all--;
                use[str[i] - 'A'] = 1;
            } else if (str[i] == '?') {
                res *= 9;
            }
        } else {
            if (str[i] >= 'A' && str[i] <= 'J') {
                if (use[str[i] - 'A']) {
                    continue;
                }
                use[str[i] - 'A'] = 1;
                res *= all;
                all--;
            } else if (str[i] == '?') {
                zero++;
            }
        }
    }

    printf("%lld", res);
    for (int i = 0; i < zero; i++) {
        printf("0");
    }
    printf("\n");

    return 0;
}
