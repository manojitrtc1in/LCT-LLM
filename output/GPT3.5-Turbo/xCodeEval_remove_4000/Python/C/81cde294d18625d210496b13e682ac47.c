#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    if (n >= 100) {
        printf("1\n");
        return 0;
    }
    int ans = n * n;
    int cur[n + 1];
    cur[0] = 0;
    for (int i = 1; i <= n; i++) {
        cur[i] = cur[i - 1] ^ l[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if ((cur[j] ^ cur[i - 1]) > (cur[k] ^ cur[j])) {
                    ans = (k - i - 1) < ans ? (k - i - 1) : ans;
                }
            }
        }
    }
    if (ans == n * n) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}
