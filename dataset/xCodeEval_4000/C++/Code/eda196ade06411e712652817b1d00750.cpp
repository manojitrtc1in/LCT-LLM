#define ONLINE_JUDGE 1

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> ii;

int n, x;
int a[100000];
ll S = 0, ans = LLONG_MAX;
map<ll, int> s;

ll pw(const ll &v, const ll &d) {
    if(d == 0) return 1LL;
    if(d == 1) return v;
    if(d == 2) return (1LL * v * v) % 1000000007LL;
    if(d % 2 == 0)
        return pw(pw(v, d / 2), 2);
    return (pw(pw(v, (d - 1) / 2), 2) * v) % 1000000007LL;
}

void solve() {
    scanf("%d %d", &n, &x);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        S += a[i];
    }
    for(int i = 0;i < n;i++)
        s[S - a[i]]++;
    for(int i = n - 1;i >= 0;i--) {
        ll p = S - a[i];
        while(s[p] >= x) {
            s[p + 1] += s[p] / x;
            s[p] %= x;
            p++;
        }
    }
    for(const pair<ll, int> &e : s) {
        if(e.Y != 0) {
            ans = e.X;
            break;
        }
    }
    printf("%I64d", pw(x, min(S, ans)));
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
