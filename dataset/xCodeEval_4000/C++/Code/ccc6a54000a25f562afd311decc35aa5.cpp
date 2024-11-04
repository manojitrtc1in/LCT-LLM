

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1200 * 1000 + 13;

int n, m;
pt a[N];

bool read () {
	if (scanf("%d", &m) != 1)
		return false;
	forn(i, m)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

vector<pt> g[N];
bool usede[N];
int deg[N];

vector<int> path;
void dfs(int v) {
    while (!g[v].empty()) {
        int u = g[v].back().x;
        int i = g[v].back().y;
        g[v].pop_back();
        if (!usede[i]) {
        	usede[i] = true;
        	dfs(u);
        }
    }
    path.pb(v);
}

void calc_degs() {
	memset(deg, 0, sizeof(deg));
	forn(i, n) for (auto j : g[i]) if (i <= j.x) {
		++deg[j.x];
		++deg[i];
	}
}

bool find_eulerian_cycle(vector<int>& res) {
	calc_degs();
	
	int bad = 0;
	forn(i, n) bad += (deg[i] & 1);
	
	path.clear();
	memset(usede, 0, sizeof(bool) * m);
	
	if (!bad) forn(i, n) if (deg[i]) {
		dfs(i);
		break;
	}
	
	if (m != 0 && sz(path) != m + 1)
		return false;
		
	reverse(all(path));
	res = path;
	
	return true;
}

bool check(int k, bool need, vector<int> &res){
	int l = (1 << k) - 1;
	n = l + 1;
	forn(i, n) g[i].clear();
	forn(i, m){
		int v = a[i].x & l;
		int u = a[i].y & l;
		if (v > u) swap(v, u);
		g[v].pb(mp(u, i));
		g[u].pb(mp(v, i));
	}
	vector<int> tmp;
	bool fl = find_eulerian_cycle(tmp);
	if (!fl) return false;
	
	if (need){
		map<pt, vector<int>> cur;
		forn(i, m){
			int v = a[i].x & l;
			int u = a[i].y & l;
			if (v > u) swap(v, u);
			cur[mp(v, u)].pb(i);
		}
	
		res.clear();
		forn(i, sz(tmp) - 1){
			int ni = i + 1;
			int v = tmp[i];
			int u = tmp[ni];
			int j = cur[mp(min(v, u), max(v, u))].back();
			if ((a[j].x & l) == v){
				res.pb(j * 2 + 1);
				res.pb(j * 2 + 2);
			}
			else{
				res.pb(j * 2 + 2);
				res.pb(j * 2 + 1);
			}
			cur[mp(min(v, u), max(v, u))].pop_back();
		}
	}
	
	return true;
}

void solve() {
	int l = 1, r = 20;
	int res = 0;
	vector<int> ans;
	forn(i, m) ans.pb(2 * i + 1), ans.pb(2 * i + 2);
	while (l <= r){
		int m = (l + r) / 2;
		if (check(m, false, ans)){
			l = m + 1;
			res = m;
		}
		else{
			r = m - 1;
		}
	}
	check(res, true, ans);
	printf("%d\n", res);
	for (auto it : ans)
		printf("%d ", it);
	puts("");
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}