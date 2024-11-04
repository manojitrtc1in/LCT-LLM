#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 100100
#define MAXNN 20100
#define INF 1000000000

typedef long long ll;

typedef struct {
    int fi, se;
} pii;

typedef struct {
    pii fi, se;
} pair_pii;

pair_pii a[MAXN];
int pref[MAXN][2];
int ha[MAXNN], haa_0[MAXNN], haa_1[MAXNN];
char ss[MAXN];
int p[MAXN];

void ms(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    ms(l, mid);
    ms(mid + 1, r);
    a[a[0].fi.fi++] = (pair_pii){{l, mid}, {mid + 1, r}};
}

void mss(int l, int r) {
    if (r <= l)
        return;
    int mid = ((l + r + 1) >> 1) - 1;
    mss(l, mid);
    mss(mid + 1, r);
    int i = l, j = mid + 1;
    int b[MAXN];
    int now = 0;

    while (i <= mid && j <= r) {
        if (p[i] < p[j])
            ss[now++] = '0', b[now] = p[i++];
        else
            ss[now++] = '1', b[now] = p[j++];
    }
    while (i <= mid)
        b[now++] = p[i++];
    while (j <= r)
        b[now++] = p[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        p[i] = b[j];
}

void solve() {
    char s[MAXN];
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0')
            pref[i][0] = pref[i - 1][0] + 1, pref[i][1] = pref[i - 1][1];
        else
            pref[i][1] = pref[i - 1][1] + 1, pref[i][0] = pref[i - 1][0];
    }

    // Function definitions for check_ans2 and check_ans1 would go here...

    int now;
    int l = 1, r = 100000;
    while (l <= r) {
        int mid = ((l + r) >> 1);
        int w = check_ans2(mid);
        if (w < n)
            l = mid + 1;
        else
            r = mid - 1, now = mid;
    }
    while (1) {
        if (check_ans1(now++))
            return;
    }
}

int main() {
    int _t = 1;
    while (_t--)
        solve();
    return 0;
}
