
```c
#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    int ans = 0;
    int fre = -1;

    {
        int cnt[MAXV] = {0};
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        int ma = 0;
        for (int i = 0; i < MAXV; i++) {
            ma = max(ma, cnt[i]);
        }
        int mac = 0;
        for (int i = 0; i < MAXV; i++) {
            if (cnt[i] == ma) {
                mac++;
                fre = i;
            }
        }
        if (mac > 1) {
            ans = n;
        }
    }

    for (int i = 0; i < MAXV; i++) {
        if (i == fre) {
            continue;
        }
        int* b = (int*)malloc((n + 1) * sizeof(int));
        b[0] = 0;
        for (int j = 0; j < n; j++) {
            int pb = b[j];
            if (a[j] == fre) {
                pb--;
            }
            else if (a[j] == i) {
                pb++;
            }
            b[j + 1] = pb;
        }
        int mi[2 * n + 1];
        int ma[2 * n + 1];
        for (int j = 0; j <= 2 * n; j++) {
            mi[j] = n + 1;
            ma[j] = -1;
        }
        for (int j = 0; j <= n; j++) {
            int va = n + b[j];
            mi[va] = min(mi[va], j);
            ma[va] = max(ma[va], j);
        }
        int j = n + 1;
        for (int i = 0; i <= 2 * n; i++) {
            j = min(j, mi[i]);
            ans = max(ans, ma[i] - j);
        }

        free(b);
    }

    printf("%d\n", ans);

    free(a);

    return 0;
}
