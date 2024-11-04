

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

int n;
vector<int> a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n - 2){
		a[i].resize(3);
		forn(j, 3){
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}
	return true;
}

vector<int> g[N];
set<int> pos[N];
bool used[N];

void solve() {
	if (n == 3){
		puts("1 2 3\n1");
		return;
	}
	forn(i, n)
		pos[i].clear();
	forn(i, n - 2) for (int x : a[i])
		pos[x].insert(i);
	forn(i, n - 2)
		used[i] = false;
	forn(i, n)
		g[i].clear();
	queue<int> q;
	forn(i, n) if (sz(pos[i]) == 1)
		q.push(i);
	vector<int> ord;
	set<pt> no;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		if (pos[v].empty()) continue;
		int i = *pos[v].begin();
		if (!used[i]){
			used[i] = true;
			ord.pb(i + 1);
			for (int x : a[i]) if (x != v){
				pos[x].erase(i);
				if (sz(pos[x]) == 1)
					q.push(x);
			}
		}
		int v1 = -1, v2 = -1;
		for (int x : a[i]) if (x != v){
			if (v1 == -1)
				v1 = x;
			else
				v2 = x;
		}
		if (!no.count(mp(v1, v))){
			g[v1].pb(v);
			g[v].pb(v1);
		}
		if (!no.count(mp(v2, v))){
			g[v2].pb(v);
			g[v].pb(v2);
		}
		no.insert(mp(v1, v2));
		no.insert(mp(v2, v1));
	}
	forn(i, n) used[i] = false;
	vector<int> res;
	int v = 0;
	forn(_, n){
		res.pb(v + 1);
		used[v] = true;
		for (int u : g[v]) if (!used[u]){
			v = u;
			break;
		}
	}
	for (auto it : res)
		printf("%d ", it);
	puts("");
	for (auto it : ord)
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