

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

const int N = 1e5 + 5;

int n, m, _, k;
int a, b, len[N], lens, ne[N];
string s, ans[N], cur;

void solve(int x) {
    cur += s[x];
    if (s[x] != s[a]) ne[x] = a;
    else ne[x] = ne[a];
    b = a; a = x; 
    len[x] = cur.size();
    if (cur.size() <= 10) ans[x] = cur, reverse(all(ans[x]));
    else {
        string t = cur.substr(cur.size() - 5, 5); reverse(all(t));
        ans[x] = t + "..." + cur[1] + cur[0];
    }
}

int main() {
    IOS; cin >> s; a = lens = s.size();
    s += char(0); ne[lens] = lens; 
    per(i, lens - 1, 0) {
        if (cur.empty() || s[i] != s[i + 1]) solve(i);
        else if (i + 1 == a && s[ne[i + 1]] < s[i]) {
            a = b; cur.pop_back();
            len[i] = len[i + 2]; ans[i] = ans[i + 2];
        }
        else solve(i);
    }
    rep(i, 0, lens - 1) cout << len[i] << ' ' << ans[i] << '\n';
    return 0;
}