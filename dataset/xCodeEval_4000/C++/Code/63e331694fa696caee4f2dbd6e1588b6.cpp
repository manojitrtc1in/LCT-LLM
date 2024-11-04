
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
#define fo(a, b, c, d) for(int (a) = (b); (a) <= (c); (a) += (d))
#define foo(a, b, c ,d) for(int (a) = (b); (a) >= (c); (a) -= (d))



const int N = 2e5 + 5;
const int oo = 1e9 + 5;

int n, h, a[N];
pair <int, int> b[N];

void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i].F;
        b[i].S = i;
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) a[i] = b[i].F;
    

    

    int all = (a[n]+a[n-1]) - (a[2]+a[1]);

    int mx = max(a[n]+a[n-1], a[n]+a[1]+h);
    int mn = a[1]+a[2]+h; if (n >= 3) { mn = min(mn, a[2]+a[3]); }
    int b1 = mx - mn;

    if (all <= b1) {
        cout << all <<'\n';
        for (int i = 1; i <= n; ++i) { cout << 1 <<' '; }
    }
    else {
        cout << b1 <<'\n';
        for (int i = 1; i <= n; ++i) {
            if (b[1].S == i) cout << 1 <<' ';
            else cout << 2 <<' ';
        }
    }
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

