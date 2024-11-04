#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define MAXN 100100
#define MAXW (1 << 20) + 5
#define INF 1000000000
#define LG 18
#define MD 998244353

typedef long long ll;
typedef struct {
    int fr, sc;
} Pair;

char s[MAXN];
int o[2][MAXN];
int ind[MAXN];
int nxt[MAXN][2];
int it;
int id[MAXN];
int mas[MAXN];

bool can(int n);
void gen(int l, int r);
bool go(int n, bool cert);
void solve();

bool can(int n) {
    if (n == 1)
        return true;

    int IT = it;
    int x = n / 2, y = (n + 1) / 2;
    if (!can(x) || !can(y))
        return false;

    int p0 = nxt[it][0], p1 = nxt[it][1];
    if (p0 == strlen(s) || ind[p0] + x - 1 >= o[0][0])
        p0 = strlen(s);
    else
        p0 = o[0][ind[p0] + x - 1];

    if (p1 == strlen(s) || ind[p1] + y - 1 >= o[1][0])
        p1 = strlen(s);
    else
        p1 = o[1][ind[p1] + y - 1];

    p0 = p0 < p1 ? p0 : p1;
    if (p0 == strlen(s)) {
        return false;
    }
    it = p0 + 1;

    return true;
}

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
    }
}

bool go(int n, bool cert) {
    it = 0;
    if (!cert)
        return can(n);
    it = 0;
    can(n);
    assert(it == strlen(s));

    it = 0;
    for (int i = 0; i < n; i++)
        id[i] = i;
    gen(0, n - 1);
    assert(it == strlen(s));
    int p[n];
    for (int i = 0; i < n; i++)
        p[id[i]] = i;
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", p[i] + 1);
    printf("\n");
    exit(0);
}

Pair len[MAXN];
int seg[MAXN][2];

void solve() {
    for (int i = 2; i < MAXN; i++) {
        int x = i / 2, y = i - x;
        len[i].fr = len[x].fr + len[y].fr + x;
        len[i].sc = len[x].sc + len[y].sc + x + y - 1;
        for (int t = 0; t < 2; t++) {
            seg[i][t] = seg[x][t] + seg[y][t];
        }
        seg[i][0] += x;
        seg[i][1] += y;
    }
    scanf("%s", s);
    int counter[2] = {0};
    memset(nxt, 0, sizeof(nxt));
    memset(o, 0, sizeof(o));
    for (int i = 0; i < strlen(s); i++) {
        int c = s[i] - '0';
        counter[c]++;
        ind[i] = o[c][0]++;
        o[c][ind[i]] = i;
    }
    nxt[strlen(s)][0] = nxt[strlen(s)][1] = strlen(s);
    for (int i = strlen(s) - 1; i >= 0; i--) {
        for (int t = 0; t < 2; t++)
            nxt[i][t] = nxt[i + 1][t];
        nxt[i][s[i] - '0'] = i;
    }
    int l = 0, r = 100010;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (go(m, false))
            l = m;
        else
            r = m;
    }
    go(l, true);
}

int main() {
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
