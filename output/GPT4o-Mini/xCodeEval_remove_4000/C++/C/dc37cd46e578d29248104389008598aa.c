#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef long long ll;
typedef unsigned int uint;
typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int p, q;
} F;

typedef struct {
    int tr[202020];
} Fenw;

int w;
int x[101010];
int a[101010];
pii v[2][101010];

void add(Fenw *fenw, int pos) {
    for (int i = pos; i <= 200020; i |= i + 1) {
        fenw->tr[i]++;
    }
}

int sum(Fenw *fenw, int pos) {
    int res = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        res += fenw->tr[i];
    }
    return res;
}

int sum_range(Fenw *fenw, int l, int r) {
    return sum(fenw, r) - sum(fenw, l - 1);
}

long long solve1(pii *v, int size) {
    F allF[202020];
    int allF_size = 0;

    for (int i = 0; i < size; i++) {
        allF[allF_size++] = (F){v[i].first, v[i].second + w};
        allF[allF_size++] = (F){v[i].first, v[i].second - w};
    }
    allF[allF_size++] = (F){0, 1};

    // Sort allF (not implemented here)
    // reunique(allF); // Not implemented here

    for (int i = 0; i < size; i++) {
        F from = {v[i].first, v[i].second + w};
        F to = {v[i].first, v[i].second - w};
        // v[i] = {lower_bound(allF, allF_size, from), lower_bound(allF, allF_size, to)};
    }

    // Sort v (not implemented here)

    long long res = 0;
    Fenw f1 = {0};
    for (int i = 0; i < size; i++) {
        res += i - sum(&f1, v[i].second - 1);
        add(&f1, v[i].second);
    }
    return res;
}

long long solve2(pii v[2][101010], int sizes[2]) {
    F allF[202020];
    int allF_size = 0;
    Fenw f[2] = {0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            allF[allF_size++] = (F){v[i][j].first, v[i][j].second + w};
            allF[allF_size++] = (F){v[i][j].first, v[i][j].second - w};
        }
    }
    allF[allF_size++] = (F){0, 1};

    // Sort allF (not implemented here)
    // reunique(allF); // Not implemented here

    long long res = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            F from = {v[i][j].first, v[i][j].second + w};
            F to = {v[i][j].first, v[i][j].second - w};
            // v[i][j] = {lower_bound(allF, allF_size, from), lower_bound(allF, allF_size, to)};
            add(&f[i], v[i][j].first);
        }
    }

    for (int i = 0; i < sizes[0]; i++) {
        res += sum_range(&f[1], v[0][i].first, v[0][i].second);
    }
    for (int i = 0; i < sizes[1]; i++) {
        res += sum_range(&f[0], v[1][i].first + 1, v[1][i].second);
    }
    return res;
}

int solve() {
    int n;
    scanf("%d", &n);
    scanf("%d", &w);
    int sizes[2] = {0, 0};

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &a[i]);
        v[x[i] < 0][sizes[x[i] < 0]++] = (pii){abs(x[i]), abs(a[i])};
    }

    long long ans = 0;
    ans += solve1(v[0], sizes[0]);
    ans += solve1(v[1], sizes[1]);
    ans += solve2(v, sizes);
    printf("%lld\n", ans);

    return 0;
}

int main() {
    solve();
    return 0;
}
