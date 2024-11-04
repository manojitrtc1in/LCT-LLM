
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <stack>
#include <queue>
#include <deque>





using namespace std;



typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;







#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define show(a) cerr << #a <<" -> "<< a <<"\n"
#define fo(a, b, c, d) for (int (a) = (b); (a) <= (c); (a) += (d))
#define foo(a, b, c ,d) for (int (a) = (b); (a) >= (c); (a) -= (d))



const int N = 2e5 + 5;
const int oo = 1e9 + 5;

string s;
int n;
vector <int> ct;
char a[N], b[N];

bool check (char c, char d) {
    for (int i = 1; i <= n; ++i) {
        if ((c == a[i] && d == b[i]) || (c == b[i] && d == a[i])) {
            return 1;
        }
    }
    return 0;
}

void solve() {
    cin >> s;
    string t = "";
    for (int i = 0; i < sz(s); ++i) {
        int cnt = 1;
        while (i+1 < sz(s) && s[i] == s[i+1]) {
            ++cnt;
            ++i;
        }
        ct.pb(cnt);
        t.pb(s[i]);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for (int i = 0; i < sz(t)-1; ++i) {
        int ct1 = 0, ct2 = 0;
        if (check(t[i], t[i+1])) {
            while (i+1 < sz(t) && check(t[i], t[i+1])) {
                if (i & 1) ct1 += ct[i];
                else ct2 += ct[i];
                ++i;
            }
            if (i & 1) ct1 += ct[i];
            else ct2 += ct[i];
            ans += min(ct1, ct2);
        }
    }
    cout << ans;
}

 main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt = 1;
	while (tt --) {
		solve();
	}
	return 0;
}

