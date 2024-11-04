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
    int n, ans = 1;
    scanf("%d", &n);
    pair<long double, int> v[n];
    for(int i = 0;i < n;i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);
        v[i] = {arg(complex<long double>(x, y)), i + 1};
    }
    sort(v, v + n);
    for(int i = 2;i < n;i++) {
        if(v[i].X - v[i - 1].X < v[ans].X - v[ans - 1].X)
            ans = i;
    }
    if(8.0 * atan(1.0) - (v[n - 1].X - v[0].X) < v[ans].X - v[ans - 1].X)
        ans = 0;
    printf("%d %d", v[ans].Y, v[(ans - 1 + n) % n].Y);
}

int main() {
    if(ONLINE_JUDGE) { 





    } else {
        freopen("input.txt", "r", stdin);
    }
    solve();
    return 0;
}