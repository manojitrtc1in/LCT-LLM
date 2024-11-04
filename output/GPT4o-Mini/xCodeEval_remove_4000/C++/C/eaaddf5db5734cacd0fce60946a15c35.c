#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 200200
#define MOD1 987655723
#define MOD2 987656927

typedef unsigned int ui;
typedef long long ll;

typedef struct {
    ui v;
} Field;

Field createField(Long x) {
    Field f;
    f.v = (ui)(x % MOD1);
    return f;
}

Field addField(Field a, Field b) {
    Field r = a;
    if ((ll)a.v + b.v >= MOD1) r.v += b.v - MOD1;
    else r.v += b.v;
    return r;
}

Field subField(Field a, Field b) {
    Field r = a;
    if (a.v < b.v) r.v -= b.v - MOD1;
    else r.v -= b.v;
    return r;
}

Field mulField(Field a, Field b) {
    Field r;
    r.v = (ui)((ll)a.v * b.v % MOD1);
    return r;
}

Field powField(Field a, ui p) {
    Field r = createField(1);
    Field e = a;
    while (p) {
        if (p & 1) r = mulField(r, e);
        e = mulField(e, e);
        p >>= 1;
    }
    return r;
}

Field invField(Field a) {
    return powField(a, MOD1 - 2);
}

Field h1[MAXN], h2[MAXN];
int st[MAXN], p[MAXN], f[MAXN];
char s[MAXN], t[MAXN];

void buildHash() {
    Field cp = createField(7);
    h1[0] = createField(t[0]);
    for (int i = 1; i < strlen(t); i++) {
        h1[i] = addField(h1[i - 1], mulField(createField(t[i]), cp));
        cp = mulField(cp, createField(7));
    }

    cp = createField(13);
    h2[0] = createField(t[0]);
    for (int i = 1; i < strlen(t); i++) {
        h2[i] = addField(h2[i - 1], mulField(createField(t[i]), cp));
        cp = mulField(cp, createField(13));
    }
}

bool getH(int l, int r, Field *hm1, Field *hm2, int *len) {
    if (l + f[l] - 1 >= r) return false;

    int b = st[l + f[l]];
    int e = st[r - p[r]];

    *len = e - b + 1;

    *hm1 = subField(h1[e], h1[b - 1]);
    *hm1 = mulField(*hm1, invField(powField(createField(7), b)));

    if (p[r] % 2 == 1) {
        (*len)++;
        *hm1 = addField(*hm1, powField(createField(7), e - b + 1));
    }

    if (f[l] % 2 == 1) {
        (*len)++;
        *hm1 = addField(createField(1), mulField(*hm1, createField(7)));
    }

    *hm2 = subField(h2[e], h2[b - 1]);
    *hm2 = mulField(*hm2, invField(powField(createField(13), b)));

    if (p[r] % 2 == 1) {
        *hm2 = addField(*hm2, powField(createField(13), e - b + 1));
    }

    if (f[l] % 2 == 1) {
        *hm2 = addField(createField(1), mulField(*hm2, createField(13)));
    }

    return true;
}

void solve() {
    int n;
    scanf("%d %s", &n, s);
    n = strlen(s);

    s[0] = '0';
    s[n + 1] = '0';
    s[n + 2] = '\0';
    n += 2;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && s[i + 1] == '1') {
            i++;
            continue;
        }
        t[strlen(t)] = s[i];
        st[strlen(t) - 1] = strlen(t) - 1;
    }

    p[0] = (s[0] == '1') ? 1 : 0;

    for (int i = 1; i < n; i++) {
        p[i] = (s[i] == '0') ? 0 : p[i - 1] + 1;
    }

    f[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        f[i] = (s[i] == '0') ? 0 : f[i + 1] + 1;
    }

    buildHash();

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        Field hm1, hm2;
        int len;
        if (getH(a, a + c - 1, &hm1, &hm2, &len) && getH(b, b + c - 1, &hm1, &hm2, &len)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}

int main() {
    solve();
    return 0;
}
