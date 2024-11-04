
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
#define show(a) cerr << #a <<" -> "<< a <<" "
#define fo(a, b, c, d) for(int (a) = (b); (a) <= (c); (a) += (d))
#define foo(a, b, c ,d) for(int (a) = (b); (a) >= (c); (a) -= (d))



const int N = (1 << 17) - 1;
const int oo = 1e9 + 5;

string s;
int n, q, t[27][N*4];
int add[27][N*4];

void push (int x, int v, int tl, int tr) {
    if (add[x][v] == 1) {
        t[x][v] = tr - tl + 1;
        if (tl < tr) {
            add[x][v*2] = 1;
            add[x][v*2+1] = 1;
        }
        add[x][v] = 0;
    }
    else if (add[x][v] == -1) {
        t[x][v] = 0;
        if (tl < tr) {
            add[x][v*2] = -1;
            add[x][v*2+1] = -1;
        }
        add[x][v] = 0;
    }
}

void upd (int x, int l, int r, int nv, int v=1, int tl=1, int tr=n) {
    push(x, v, tl, tr);
    if (r < tl || tr < l) { return; }
    if (l <= tl && tr <= r) { add[x][v] = nv; push(x, v, tl, tr); return; }
    int tm = (tl + tr) / 2;
    upd (x, l, r, nv, v*2, tl, tm);
    upd (x, l, r, nv, v*2+1, tm+1, tr);
    t[x][v] = t[x][v*2] + t[x][v*2+1];
}

int cnt (int x, int l, int r, int v=1, int tl=1, int tr=n) {
    push(x, v, tl, tr);
    if (r < tl || tr < l) { return 0; }
    if (l <= tl && tr <= r) { return t[x][v]; }
    int tm = (tl + tr) / 2;
    return cnt(x, l, r, v*2, tl, tm) + cnt(x, l, r, v*2+1, tm+1, tr);
}

bool get (int x, int pos, int v=1, int tl=1, int tr=n) {
    push(x, v, tl, tr);
    if (tl == tr) {
        if (t[x][v]) return 1;
        else return 0;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) { return get(x, pos, v*2, tl, tm); }
    else { return get(x, pos, v*2+1, tm+1, tr); }
    return 0;
}

void solve() {
    cin >> n >> q;
    cin >> s;
    s = '#' + s;
    for (int i = 1; i <= n; ++i) {
        upd(s[i] - 'a' + 1, i, i, 1);
    }
    for  (int it = 1; it <= q; ++it) {
        int l, r; bool type;
        cin >> l >> r >> type;
        vector < pair <int,pii> > later;
        if (type == 1) {
            int pos = l;
            for (int i = 1; i <= 26; ++i) {
                int cur = cnt(i, l, r);
                upd(i, l, r, -1);
                if (cur) {
                    later.pb(mkp(i, mkp(pos, pos + cur - 1)));
                    pos += cur;
                }
            }
        }
        else {
            int pos = l;
            for (int i = 26; i >= 1; --i) {
                int cur = cnt(i, l, r);
                upd(i, l, r, -1);
                if (cur) {
                    later.pb(mkp(i, mkp(pos, pos + cur - 1)));
                    pos += cur;
                }
            }
        }
        for (int i = 0; i < sz(later); ++i) {
            int x = later[i].F, l = later[i].S.F, r = later[i].S.S;
            

            upd(x, l, r, 1);
        }
        later.clear();
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 26; ++j) {
            if (get(j, i)) {
                cout << char('a' + j - 1);
                break;
            }
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

