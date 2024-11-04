#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 200005
#define MOD 998244353

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int n;
    int m;
    int fW;
    int hW;
    int inv[MAXN * 2 + 1];
    int f[MAXN + 1][MAXN + 1];
    int h[MAXN + 1][MAXN + 1];
} Task;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int mul(int a, int b) {
    return (int)(((long long)a * b) % MOD);
}

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int powMod(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inverse(int a) {
    return powMod(a, MOD - 2);
}

void solve(Task *task) {
    int n = task->n;
    int m = task->m;
    int a[MAXN];
    int count[2] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i] % 2]++;
    }
    int w[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        if (a[i] % 2 == 0) {
            task->hW += w[i];
        } else {
            task->fW += w[i];
        }
    }

    for (int i = 0; i <= m * 2; i++) {
        task->inv[i] = inverse(task->hW + task->fW + i - m);
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            task->f[i][j] = -1;
            task->h[i][j] = -1;
        }
    }

    for (int i = 0; i <= m; i++) {
        task->f[i][0] = 1;
        task->h[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            printf("%d\n", mul(w[i], task->f[0][m]));
        } else {
            printf("%d\n", mul(w[i], task->h[0][m]));
        }
    }
}

int main() {
    Task task;
    scanf("%d %d", &task.n, &task.m);
    task.fW = 0;
    task.hW = 0;
    solve(&task);
    return 0;
}
