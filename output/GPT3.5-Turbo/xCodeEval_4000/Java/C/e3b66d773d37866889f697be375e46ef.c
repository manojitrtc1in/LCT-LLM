#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int n;
int a[MAXN];
int notmemo[MAXN][2];

int dp(int idx, int state) {
    if (idx == n) {
        return 0;
    }
    if (notmemo[idx][state] != -1) {
        return notmemo[idx][state];
    }
    int take = 0, leave = 0, leaveall = 0;
    if (a[idx] == 1 && (state == 1 || state == 0)) {
        take = 1 + dp(idx + 1, 1);
    }
    if (a[idx] == 0 && state == 0) {
        leave = 1 + dp(idx + 1, state);
    }
    leaveall = dp(idx + 1, state);
    return notmemo[idx][state] = max(take, max(leaveall, leave));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            notmemo[i][j] = -1;
        }
    }
    printf("%d\n", dp(0, 0));
    return 0;
}
