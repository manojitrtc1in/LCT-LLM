#include <stdio.h>
#include <stdlib.h>

void solve() {
    int n;
    scanf("%d", &n);
    int *dq = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &dq[i]);
    }
    int a = dq[0];
    int b = 0;
    int pre = a;
    int now;
    int cnt = 1;
    int i = 1;
    while (i < n) {
        now = 0;
        while (now <= pre && i < n) {
            now += dq[i];
            i++;
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
            printf("%d\n", now);
        }

        if (i >= n) {
            break;
        }

        now = 0;
        while (now <= pre && i < n) {
            now += dq[n - i - 1];
            i++;
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
            printf("%d\n", now);
        }
    }
    printf("%d %d %d\n", cnt, a, b);
    free(dq);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
