#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>

#define MAXN 1100
#define INF 1000000000

char s[MAXN];
int it;

bool can(int n) {
    if (n == 1)
        return true;
    int x = n / 2, y = (n + 1) / 2;
    if (!can(x) || !can(y))
        return false;
    int a = 0, b = 0;
    while (it < strlen(s)) {
        if (s[it] == '0')
            a++;
        else
            b++;
        it++;
        if (a == x || b == y)
            break;
    }
    if (a != x && b != y)
        return false;
    return true;
}

int e[MAXN][MAXN];
int id[MAXN];
int mas[MAXN];
int deg[MAXN];

void gen(int l, int r) {
    if (l == r)
        return;
    int m = (l + r - 1) / 2;
    gen(l, m);
    gen(m + 1, r);
    int a = l, b = m + 1, c = l;
    while (a <= m && b <= r) {
        if (s[it] == '0') {
            mas[c++] = id[a];
            a++;
        } else {
            mas[c++] = id[b];
            b++;
        }
        it++;
    }
    while (a <= m) {
        mas[c++] = id[a];
        a++;
    }
    while (b <= r) {
        mas[c++] = id[b];
        b++;
    }
    for (int i = l; i <= r; i++) {
        id[i] = mas[i];
        if (i > l) {
            e[id[i - 1]][deg[id[i - 1]]++] = id[i];
        }
    }
}

void go(int n) {
    it = 0;
    if (!can(n) || it != strlen(s))
        return;

    it = 0;
    for (int i = 0; i < n; i++)
        id[i] = i;
    gen(0, n - 1);
    assert(it == strlen(s));
    int p[MAXN];
    for (int i = 0; i < n; i++)
        p[id[i]] = i;
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", p[i] + 1);
    printf("\n");
    exit(0);
}

int seg[MAXN][2];

void solve() {
    for (int i = 2; i < MAXN; i++) {
        int x = (i + 1) / 2, y = i - x;
        for (int t = 0; t < 2; t++) {
            seg[i][t] = seg[x][t] + seg[y][t];
        }
        seg[i][0] += x;
        seg[i][1] += y;
    }
    scanf("%s", s);
    int counter[2] = {0};
    for (int j = 0; j < strlen(s); j++)
        counter[s[j] - '0']++;
    for (int n = MAXN - 1; n > 0; n--)
        if (seg[n][0] >= counter[0] && seg[n][1] >= counter[1]) {
            go(n);
        }
}

int main() {
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);

    ios_sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    printf("%.20f\n", 0.0);

    int ts = 1;
    for (int its = 1; its <= ts; its++) {
        solve();
    }

    return 0;
}
