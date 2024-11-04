

#include <bits/stdc++.h>

using namespace std;

#define MULTITEST

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

const int N = 100 * 1000 + 13;

int n, m, k;
vector<int> g[N];

bool read () {
	if (scanf("%d%d%d", &n, &m, &k) != 3)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, m){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].pb(u);
		g[u].pb(v);
	}
	forn(i, n){
		sort(all(g[i]));
	}
	return true;
}

bool tk[N];
int cur[N];

vector<int> process(int k){
	memset(tk, 0, sizeof(bool) * n);
	memset(cur, 0, sizeof(int) * n);
	forn(v, n){
		int cnt = 0;
		for (int u : g[v]) cnt += sz(g[u]) >= k;
		tk[v] = cnt >= k;
	}
	forn(v, n) if (tk[v]){
		for (int u : g[v]) cur[v] += tk[u];
	}
	queue<int> q;
	forn(v, n) if (tk[v] && cur[v] < k) q.push(v);
	while (!q.empty()){
		int v = q.front();
		q.pop();
		tk[v] = false;
		for (int u : g[v]) if (tk[u]){
			--cur[u];
			if (cur[u] == k - 1) q.push(u);
		}
	}
	vector<int> lft;
	forn(v, n) if (tk[v]) lft.pb(v);
	return lft;
}

void solve() {
	vector<int> ans = process(k);
	if (!ans.empty()){
		printf("1 %d\n", sz(ans));
		for (int v : ans) printf("%d ", v + 1);
		puts("");
		return;
	}
	ans = process(k - 1);
	if (!ans.empty()){
		queue<int> q;
		for (int v : ans) if (cur[v] == k - 1) q.push(v);
		while (!q.empty()){
			int v = q.front();
			q.pop();
			if (cur[v] == k - 1){
				vector<int> res;
				res.reserve(k);
				for (int u : g[v]) if (tk[u]) res.pb(u);
				res.pb(v);
				bool ok = true;
				forn(i, sz(res)){
					forn(j, i){
						ok &= binary_search(all(g[res[i]]), res[j]);
						if (!ok) break;
					}
					if (!ok) break;
				}
				if (ok){
					printf("2\n");
					for (int v : res) printf("%d ", v + 1);
					puts("");
					return;
				}
			}
			tk[v] = false;
			for (int u : g[v]) if (tk[u]){
				--cur[u];
				if (cur[u] == k - 1) q.push(u);
			}
		}
	}
	puts("-1");
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

#ifdef MULTITEST
	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();
#else
	while(read()) {	
#endif
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}