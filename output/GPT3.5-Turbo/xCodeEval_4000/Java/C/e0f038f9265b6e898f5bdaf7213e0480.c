#include <stdio.h>
#include <stdlib.h>

void solve() {
    int n;
    scanf("%d", &n);
    int* dq = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &dq[i]);
    }
    int a = dq[0];
    int b = 0;
    int pre = a;
    int now;
    int cnt = 1;
    while (n > 1) {
        now = 0;
        while (now <= pre && n > 1) {
            now += dq[--n];
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
        }
        if (n <= 1) {
            break;
        }
        now = 0;
        while (now <= pre && n > 1) {
            now += dq[0];
            for (int i = 0; i < n - 1; i++) {
                dq[i] = dq[i + 1];
            }
            n--;
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
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
