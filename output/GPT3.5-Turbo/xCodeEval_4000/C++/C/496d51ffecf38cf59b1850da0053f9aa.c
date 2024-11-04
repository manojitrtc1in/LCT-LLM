#include <stdio.h>
#include <stdlib.h>

#define N 101

int powcnt[N];
int ans;

void preprocess(int num) {
    for (int i = 30; i >= 0; i--) {
        if (num >= (1 << i)) {
            num -= (1 << i);
            powcnt[i]++;
        }
    }
}

void solve(int curp) {
    for (int i = curp; i <= 30; i++) {
        if (powcnt[i] > 0) {
            powcnt[i]--;
            ans++;
            for (int j = curp; j < i; j++) {
                powcnt[j]++;
            }
            break;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *v = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        preprocess(x);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < m; i++) {
        solve(v[i]);
    }
    printf("%d\n", ans);
    free(v);
    return 0;
}
