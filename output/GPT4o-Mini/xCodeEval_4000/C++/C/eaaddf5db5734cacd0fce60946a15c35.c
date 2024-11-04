#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 200200

typedef unsigned int ui;
typedef long long Long;

typedef struct {
    ui v;
} Field;

Field createField(Long x, unsigned int N) {
    Field f;
    f.v = (ui)(x % N);
    return f;
}

Field fieldAdd(Field a, Field b, unsigned int N) {
    if ((Long)a.v + b.v >= N) a.v += b.v - N;
    else a.v += b.v;
    return a;
}

Field fieldSub(Field a, Field b, unsigned int N) {
    if (a.v < b.v) a.v -= b.v - N;
    else a.v -= b.v;
    return a;
}

Field fieldMul(Field a, Field b, unsigned int N) {
    a.v = (ui)((Long)a.v * b.v % N);
    return a;
}

Field fieldPow(Field a, ui p, unsigned int N) {
    Field r = createField(1, N);
    Field e = a;
    while (p) {
        if (p & 1) r = fieldMul(r, e, N);
        e = fieldMul(e, e, N);
        p >>= 1;
    }
    return r;
}

Field fieldInv(Field a, unsigned int N) {
    return fieldPow(a, N - 2, N);
}

Field fieldDiv(Field a, Field b, unsigned int N) {
    return fieldMul(a, fieldInv(b, N), N);
}

Field h1[MAXN], h2[MAXN];
int st[MAXN], p[MAXN], f[MAXN];
char s[MAXN], t[MAXN];

void buildHash(unsigned int p1, unsigned int p2, int tLen) {
    Field cp = createField(p1, 1000000007);
    h1[0] = createField(t[0], 1000000007);
    for (int i = 1; i < tLen; i++) {
        h1[i] = fieldAdd(h1[i - 1], fieldMul(createField(t[i], 1000000007), cp, 1000000007), 1000000007);
        cp = fieldMul(cp, createField(p1, 1000000007), 1000000007);
    }

    cp = createField(p2, 987656927);
    h2[0] = createField(t[0], 987656927);
    for (int i = 1; i < tLen; i++) {
        h2[i] = fieldAdd(h2[i - 1], fieldMul(createField(t[i], 987656927), cp, 987656927), 987656927);
        cp = fieldMul(cp, createField(p2, 987656927), 987656927);
    }
}

void getH(int l, int r, int *len, Field *hm1, Field *hm2) {
    if (l + f[l] - 1 >= r) {
        *len = -1;
        return;
    }

    int b = st[l + f[l]];
    int e = st[r - p[r]];

    *len = e - b + 1;

    *hm1 = fieldDiv(fieldSub(h1[e], h1[b - 1], 1000000007), fieldPow(createField(p1, 1000000007), b, 1000000007), 1000000007);
    if (p[r] % 2 == 1) {
        (*len)++;
        *hm1 = fieldAdd(*hm1, fieldPow(createField(1, 1000000007), e - b + 1, 1000000007), 1000000007);
    }

    if (f[l] % 2 == 1) {
        (*len)++;
        *hm1 = fieldAdd(*hm1, createField(1, 1000000007), 1000000007);
    }

    *hm2 = fieldDiv(fieldSub(h2[e], h2[b - 1], 987656927), fieldPow(createField(p2, 987656927), b, 987656927), 987656927);
    if (p[r] % 2 == 1) {
        *hm2 = fieldAdd(*hm2, fieldPow(createField(1, 987656927), e - b + 1, 987656927), 987656927);
    }

    if (f[l] % 2 == 1) {
        *hm2 = fieldAdd(*hm2, createField(1, 987656927), 987656927);
    }
}

void solve() {
    int n;
    scanf("%d %s", &n, s);
    n = strlen(s);

    s[0] = '0';
    s[n + 1] = '0';
    s[n + 2] = '\0';
    n += 2;

    int tLen = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && s[i + 1] == '1') {
            i++;
            continue;
        }
        t[tLen++] = s[i];
        st[i] = tLen - 1;
    }
    t[tLen] = '\0';

    p[0] = (s[0] == '1') ? 1 : 0;
    for (int i = 1; i < n; i++) {
        p[i] = (s[i] == '0') ? 0 : p[i - 1] + 1;
    }

    f[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        f[i] = (s[i] == '0') ? 0 : f[i + 1] + 1;
    }

    buildHash(7, 13, tLen);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        Field hm1_a, hm1_b, hm2_a, hm2_b;
        int len_a, len_b;

        getH(a, a + c - 1, &len_a, &hm1_a, &hm2_a);
        getH(b, b + c - 1, &len_b, &hm1_b, &hm2_b);

        if (len_a == len_b && hm1_a.v == hm1_b.v && hm2_a.v == hm2_b.v) {
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
