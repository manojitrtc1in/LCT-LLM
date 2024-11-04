



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
const int NP = 700;

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

li f[N];

void upd(int x, li val){
	for (int i = x; i < N; i |= i + 1)
		f[i] += val;
}

li get(int x){
	li sum = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		sum += f[i];
	return sum;
}

void solve(){
	iota(a, a + n, 0);
	
	memset(numhv, -1, sizeof(numhv));
	hv.clear();
	forn(v, n) if (sz(g[v]) >= P){
		numhv[v] = sz(hv);
		hv.pb(v);
	}
	memset(nb, 0, sizeof(nb));
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
	
	memset(f, 0, sizeof(f));
	
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
			
			int lst = 0;
			for (auto x : pos[v]){
				while (!cur.empty() && cur.begin()->x < x){
					int y = cur.begin()->x;
					int u = cur.begin()->y;
					cur.erase(cur.begin());
					
					upd(lst, lsv * li(mrv));
					upd(y + 1, -lsv * li(mrv));
					lst = y + 1;
					--lsv, ++mrv;
					
					auto it = lower_bound(all(pos[u]), x);
					if (it != pos[u].end())
						cur.insert(mp(*it, u));
				}
				
				upd(lst, lsv * li(mrv));
				upd(x + 1, -lsv * li(mrv));
				lst = x + 1;
				
				lsv = sz(g[v]), mrv = 0;
			}
			
			pos[v].pop_back();
		}
		else{
			int lsv = ls[v];
			int mrv = mr[v];
			
			upd(0, lsv * li(mrv));
			upd(1, -lsv * li(mrv));
		
			forn(j, k){
				int u = q[j];
				if (u == v)
					lsv = sz(g[v]), mrv = 0;
				else if (nb[u][numhv[v]] && a[u] < a[v])
					--lsv, ++mrv;
				a[u] = n + j;
				upd(j + 1, lsv * li(mrv));
				upd(j + 2, -lsv * li(mrv));
			}
			
			iota(a, a + n, 0);
		}
	}
	
	forn(i, k + 1)
		printf("%lld\n", get(i));
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