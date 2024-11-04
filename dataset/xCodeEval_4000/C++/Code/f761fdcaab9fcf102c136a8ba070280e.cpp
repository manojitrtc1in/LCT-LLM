
 
#include <bits/stdc++.h>
#define all(n) (n).begin(), (n).end()
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define sqr(n) (n)*(n)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef double db;

template<class T1, class T2> bool umin(T1& a, T2 b) { return a > b ? (a = b, true) : false; }
template<class T1, class T2> bool umax(T1& a, T2 b) { return a < b ? (a = b, true) : false; }
template<class T> void clear(T& a) { T().swap(a); }

const int N = 1e5 + 5, inf = 1e9;

int n, m, _, k;
int f[N];

struct node {
    int x, y, t;
};

int main() {
    IOS; cin >> n >> k;
    rep (i, 1, k) f[i] = -inf;
    vector<node> a; a.pb({ 1, 1, 0 });
    rep (i, 1, k) {
        int x, y, t; cin >> t >> x >> y;
        a.pb({ x, y, t });

        per (j, i - 1, max(i - (n << 2), 0))
            if (abs(a[j].x - x) + abs(a[j].y - y) <= t - a[j].t) umax(f[i], f[j] + 1);
        umax(m, f[i]);
    }
    cout << m; 
    return 0;
}