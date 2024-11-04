#include <stdio.h>
#include <stdlib.h>

void solve() {
    int n;
    scanf("%d", &n);
    
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int *idx = (int *)malloc(n * sizeof(int));
    int idx_count = 0;

    for (int f = 0; f < n; f++) {
        for (int s = 0; s < n; s++) {
            if (f == s || f == n - 1 - s || f == n / 2 || s == n / 2) {
                idx[idx_count++] = f;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < idx_count; i++) {
        sum += a[idx[i]];
    }

    printf("%d\n", sum);

    free(a);
    free(idx);
}

int main() {
    solve();
    return 0;
}
