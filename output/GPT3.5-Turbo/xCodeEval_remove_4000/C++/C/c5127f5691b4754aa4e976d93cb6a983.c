#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100010

typedef struct {
    int fr;
    int sc;
} Pair;

char s[MAXN];
int o[2][MAXN];
int ind[MAXN];
Pair nxt[MAXN];
int it;

typedef struct {
    int value;
} Modular;

Modular inverse(Modular a, Modular m) {
    Modular u = {0};
    Modular v = {1};
    while (a.value != 0) {
        Modular t = {m.value / a.value};
        m.value -= t.value * a.value;
        int temp = a.value;
        a.value = m.value;
        m.value = temp;
        u.value -= t.value * v.value;
        int temp2 = u.value;
        u.value = v.value;
        v.value = temp2;
    }
    return u;
}

Modular Modular_add(Modular lhs, Modular rhs, Modular mod) {
    Modular result = {lhs.value + rhs.value};
    if (result.value >= mod.value) {
        result.value -= mod.value;
    }
    return result;
}

Modular Modular_sub(Modular lhs, Modular rhs, Modular mod) {
    Modular result = {lhs.value - rhs.value};
    if (result.value < 0) {
        result.value += mod.value;
    }
    return result;
}

Modular Modular_mul(Modular lhs, Modular rhs, Modular mod) {
    Modular result = {lhs.value * rhs.value % mod.value};
    return result;
}

Modular Modular_div(Modular lhs, Modular rhs, Modular mod) {
    Modular inv = inverse(rhs, mod);
    return Modular_mul(lhs, inv, mod);
}

Modular power(Modular a, int b, Modular mod) {
    Modular x = a;
    Modular res = {1};
    int p = b;
    while (p > 0) {
        if (p & 1) {
            res = Modular_mul(res, x, mod);
        }
        x = Modular_mul(x, x, mod);
        p >>= 1;
    }
    return res;
}

Modular normalize(int x, Modular mod) {
    int v;
    if (-mod.value <= x && x < mod.value) {
        v = x;
    } else {
        v = x % mod.value;
    }
    if (v < 0) {
        v += mod.value;
    }
    Modular result = {v};
    return result;
}

Modular mod = {998244353};

int can(int n) {
    if (n == 1) {
        return 1;
    }
    
    int IT = it;
    int x = n / 2, y = (n + 1) / 2;
    if (!can(x) || !can(y)) {
        return 0;
    }
    int p0 = nxt[it].fr, p1 = nxt[it].sc;
    if (p0 == strlen(s) || ind[p0] + x - 1 >= o[0][0]) {
        p0 = strlen(s);
    } else {
        p0 = o[0][ind[p0] + x - 1];
    }
    if (p1 == strlen(s) || ind[p1] + y - 1 >= o[1][0]) {
        p1 = strlen(s);
    } else {
        p1 = o[1][ind[p1] + y - 1];
    }
    p0 = p0 < p1 ? p0 : p1;
    if (p0 == strlen(s)) {
        return 0;
    }
    it = p0 + 1;
    
    return 1;
}

void gen(int l, int r) {
    if (l == r) {
        return;
    }
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

void go(int n, int cert) {
    it = 0;
    if (!cert) {
        if (!can(n)) {
            printf("0\n");
        } else {
            printf("1\n");
        }
        return;
    }
    it = 0;
    can(n);
    if (it == strlen(s)) {
        it = 0;
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
        gen(0, n - 1);
        for (int i = 0; i < n; i++) {
            printf("%d ", id[i] + 1);
        }
        printf("\n");
        exit(0);
    }
}

void solve() {
    for (int i = 2; i < MAXN; i++) {
        int x = i / 2, y = i - x;
        len[i].fr = len[x].fr + len[y].fr + x;
        len[i].sc = len[x].sc + len[y].sc + x + y - 1;
        seg[i][0] = seg[x][0] + seg[y][0];
        seg[i][1] = seg[x][1] + seg[y][1];
        seg[i][0] += x;
        seg[i][1] += y;
    }
    scanf("%s", s);
    int counter[2] = {0};
    int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        int c = s[i] - 48;
        counter[c]++;
        ind[i] = o[c][0];
        o[c][0]++;
    }
    nxt[len_s].fr = nxt[len_s].sc = len_s;
    for (int i = len_s - 1; i >= 0; i--) {
        nxt[i].fr = nxt[i + 1].fr;
        nxt[i].sc = nxt[i + 1].sc;
        nxt[i].value = i;
    }
    int l = 0, r = 100010;
    while (r - l > 1) {
        int m = (l + r) / 2;
        go(m, 0);
        if (it == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    go(l, 1);
}

int main() {
    freopen("../a.in", "r", stdin);
    freopen("../a.out", "w", stdout);

    int ts;
    ts = 1;
    
    for (int its = 1; its <= ts; its++) {
        solve();
    }

    return 0;
}
