



using namespace std;











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
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;
const int P = 350;
const int NP = 550;

int n, m, k;
vector<int> g[N];
int q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
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
	scanf("%d", &k);
	forn(i, k){
		scanf("%d", &q[i]);
		--q[i];
	}
	return true;
}

int numhv[N];
vector<int> hv;
bool nb[N][NP];

int a[N];
int ls[N], mr[N];
li ans[N];

vector<int> pos[N];

void solve(){
	iota(a, a + n, 0);
	
	memset(numhv, -1, sizeof(numhv));
	hv.clear();
	forn(v, n) if (sz(g[v]) >= P){
		numhv[v] = sz(hv);
		hv.pb(v);
	}
	for (auto v : hv) for (auto u : g[v]){
		nb[u][numhv[v]] = true;
	}
	
	memset(ls, 0, sizeof(ls));
	memset(mr, 0, sizeof(mr));
	forn(v, n) for (auto u : g[v]){
		ls[v] += (a[u] < a[v]);
		mr[v] += (a[u] > a[v]);
	}
	
	forn(i, n) pos[i].clear();
	forn(i, k) pos[q[i]].pb(i);
	
	memset(ans, 0, sizeof(ans));
	
	forn(v, n){
		ans[0] += mr[v] * li(ls[v]);
		ans[1] -= mr[v] * li(ls[v]);
	}
	
	forn(v, n){
		if (numhv[v] == -1){
			pos[v].pb(k);
			
			set<pt> cur;
			for (auto u : g[v]){
				if (a[u] > a[v]){
					auto it = lower_bound(all(pos[u]), pos[v][0]);
					if (it != pos[u].end())
						cur.insert(mp(*it, u));
				}
				else{
					auto it = lower_bound(all(pos[u]), 0);
					if (it != pos[u].end())
						cur.insert(mp(*it, u));
				}
			}
			
			int lsv = ls[v];
			int mrv = mr[v];
			
			int lst = 1;
			for (auto x : pos[v]){
				while (!cur.empty() && cur.begin()->x < x){
					int y = cur.begin()->x;
					int u = cur.begin()->y;
					cur.erase(cur.begin());
					
					ans[lst] += lsv * li(mrv);
					ans[y + 1] -= lsv * li(mrv);
					lst = y + 1;
					--lsv, ++mrv;
					
					auto it = lower_bound(all(pos[u]), x);
					if (it != pos[u].end())
						cur.insert(mp(*it, u));
				}
				
				ans[lst] += lsv * li(mrv);
				ans[x + 1] -= lsv * li(mrv);
				lst = x + 1;
				
				lsv = sz(g[v]), mrv = 0;
			}
			
			pos[v].pop_back();
		}
		else{
			int lsv = ls[v];
			int mrv = mr[v];
			forn(j, k){
				int u = q[j];
				if (u == v)
					lsv = sz(g[v]), mrv = 0;
				else if (nb[u][numhv[v]] && a[u] < a[v])
					--lsv, ++mrv;
				a[u] = n + j;
				ans[j + 1] += mrv * li(lsv);
				ans[j + 2] -= mrv * li(lsv);
			}
			iota(a, a + n, 0);
		}
	}
	
	forn(i, k)
		ans[i + 1] += ans[i];
	
	forn(i, k + 1)
		printf("%lld\n", ans[i]);
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}