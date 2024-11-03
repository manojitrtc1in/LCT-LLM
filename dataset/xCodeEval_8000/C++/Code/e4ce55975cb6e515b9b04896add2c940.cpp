#define ONLINE_JUDGE 1

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define trace(x) cout << #x << ": " << x << '\n';

typedef long long ll;
typedef pair<int, int> ii;

void solve() {
    int n, ans = 0;
    scanf("%d", &n);
    pair<long double, int> v[n];
    for(int i = 0;i < n;i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        v[i] = {arg(complex<long double>(x, y)), i + 1};
    }
    sort(v, v + n);
    auto angle = [](const pair<long double, int> &v1, const pair<long double, int> &v2) {
        return min(8.0 * atan(1.0) - abs(v1.X - v2.X), abs(v1.X - v2.X));
    };
    for(int i = 1;i < n;i++) {
        if(angle(v[i], v[(i + 1) % n]) < angle(v[ans], v[(ans + 1) % n]))
            ans = i;
    }
    printf("%d %d", v[ans].Y, v[(ans + 1) % n].Y);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}
