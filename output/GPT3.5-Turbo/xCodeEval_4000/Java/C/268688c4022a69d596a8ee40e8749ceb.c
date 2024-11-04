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
    int dq_size = n;
    int dq_index = 1;
    while (dq_index < dq_size) {
        now = 0;
        while (now <= pre && dq_index < dq_size) {
            now += dq[dq_size - dq_index];
            dq_index++;
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
        }

        if (dq_index >= dq_size) {
            break;
        }

        now = 0;
        while (now <= pre && dq_index < dq_size) {
            now += dq[dq_index];
            dq_index++;
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
