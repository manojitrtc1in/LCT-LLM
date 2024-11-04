

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

const int N = 800 * 1000 + 13;

struct query{
	int t, l, r;
};

int n, m;
int a[N];
query q[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	forn(i, m){
		scanf("%d%d", &q[i].t, &q[i].l);
		if (q[i].t == 1){
			scanf("%d", &q[i].r);
			--q[i].l;
		}
		else if (q[i].t == 2){
			--q[i].l;
		}
		else{
			scanf("%d", &q[i].r);
		}
	}
	return true;
}

set<int> cur[N];
map<int, int> clr;
int p[N];
int val[N];
int pos[N];

void merge(int a, int b, int nclr){
	a = p[a], b = p[b];
	if (sz(cur[a]) < sz(cur[b]))
		swap(a, b);
	for (int x : cur[b]){
		cur[a].insert(x);
		p[x] = a;
	}
	cur[b].clear();
	val[a] = nclr;
	clr[nclr] = a;
}

void add(int nw, int c){
	if (val[nw] != -1)
		clr.erase(val[nw]);
	val[nw] = c;
	if (clr.count(c))
		merge(nw, clr[c], c);
	else
		clr[c] = nw;
}

void solve() {
	forn(i, n + m) cur[i].clear(), val[i] = -1;
	clr.clear();
	
	forn(i, n){
		p[i] = i;
		cur[i].insert(i);
		pos[i] = i;
		add(i, a[i]);
	}
	int nw = n;
	
	forn(i, m){
		if (q[i].t == 1){
			p[nw] = nw;
			cur[nw].insert(nw);
			pos[q[i].l] = nw;
			add(nw, q[i].r);
			++nw;
		}
		else if (q[i].t == 2){
			printf("%d\n", val[p[pos[q[i].l]]]);
		}
		else{
			int l = q[i].l, r = q[i].r;
			vector<int> tol, tor;
			for (auto it = clr.lower_bound(l); it != clr.end() && it->x <= r; ++it){
				if (abs(it->x - l) < abs(it->x - r))
					tol.pb(it->y);
				else
					tor.pb(it->y);
			}
			for (int x : tol){
				add(x, l - 1);
			}
			for (int x : tor){
				add(x, r + 1);
			}
		}
	}
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