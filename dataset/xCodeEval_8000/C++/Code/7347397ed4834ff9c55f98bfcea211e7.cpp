#define ONLINE_JUDGE 0

#include <bits/stdc++.h>

using namespace std;

int n, a[1000000], t1[4000000], t2[4000000], b[1000000];
long long ans = 0;

void update(int *t, const int &v, const int &tl, const int &tr, const int &pos, const int &val) {
    if(tl == pos && tr == tl + 1) {
        t[v] = val;
        return;
    }
    if(pos < tl || pos >= tr)
        return;
    int tm = (tl + tr) / 2;
    update(t, v * 2, tl, tm, pos, val);
    update(t, v * 2 + 1, tm, tr, pos, val);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int get(int *t, const int &v, const int &tl, const int &tr, const int &l, const int &r) {
    if(l <= tl && r >= tr)
        return t[v];
    if(r <= tl || l >= tr)
        return 0;
    int tm = (tl + tr) / 2;
    return get(t, v * 2, tl, tm, l, r) +
           get(t, v * 2 + 1, tm, tr, l, r);
}

void solve() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for(int i = 0;i < n;i++) {
        a[i] = lower_bound(b, b + n, a[i]) - b;
        update(t2, 1, 0, n, a[i], 1);
    }
    for(int i = 0;i < n;i++) {
        update(t2, 1, 0, n, a[i], 0);
        ans += 1LL * get(t1, 1, 0, n, a[i] + 1, n) * get(t2, 1, 0, n, 0, a[i]);
        update(t1, 1, 0, n, a[i], 1);
    }
    printf("%I64d", ans);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
