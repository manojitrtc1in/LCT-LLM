#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100010

char s[MAXN];

int o[2][MAXN];
int ind[MAXN];
int nxt[MAXN][2];

int it;

int seg[MAXN][2];
int len[MAXN][2];

void gen(int l, int r, int id[]) {
    if (l == r)
        return;
    int m = (l + r - 1) / 2;
    gen(l, m, id);
    gen(m + 1, r, id);
    int a = l, b = m + 1, c = l;
    while (a <= m && b <= r) {
        if (s[it] == '0') {
            id[c++] = id[a];
            a++;
        } else {
            id[c++] = id[b];
            b++;
        }
        it++;
    }
    while (a <= m) {
        id[c++] = id[a];
        a++;
    }
    while (b <= r) {
        id[c++] = id[b];
        b++;
    }
    for (int i = l; i <= r; i++) {
        id[i] = id[i];
    }
}

int can(int n) {
    if (n == 1)
        return 1;
    
    int IT = it;
    int x = n / 2, y = (n + 1) / 2;
    if (!can(x) || !can(y))
        return 0;
    int p0 = nxt[it][0], p1 = nxt[it][1];
    if (p0 == strlen(s) || ind[p0] + x - 1 >= o[0][0])
        p0 = strlen(s);
    else
        p0 = o[0][ind[p0] + x - 1];
    if (p1 == strlen(s) || ind[p1] + y - 1 >= o[1][0])
        p1 = strlen(s);
    else
        p1 = o[1][ind[p1] + y - 1];
    p0 = (p0 < p1) ? p0 : p1;
    if (p0 == strlen(s)) {
        return 0;
    }
    it = p0 + 1;
    return 1;
}

void go(int n, int cert) {
    it = 0;
    if (!cert) {
        if (can(n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        return;
    }
    it = 0;
    can(n);
    if (it == strlen(s)) {
        it = 0;
        int id[MAXN];
        for (int i = 0; i < n; i++)
            id[i] = i;
        gen(0, n - 1, id);
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", id[i] + 1);
        }
        printf("\n");
        exit(0);
    } else {
        printf("NO\n");
        return;
    }
}

int main() {
    scanf("%s", s);
    int counter[2] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 48;
        counter[c]++;
        ind[i] = o[c][0];
        o[c][0]++;
    }
    nxt[n][0] = nxt[n][1] = n;
    for (int i = n - 1; i >= 0; i--) {
        for (int t = 0; t < 2; t++)
            nxt[i][t] = nxt[i + 1][t];
        nxt[i][s[i] - 48] = i;
    }
    int l = 0, r = 100010;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (can(m))
            l = m;
        else
            r = m;
    }
    go(l, 1);
    return 0;
}
