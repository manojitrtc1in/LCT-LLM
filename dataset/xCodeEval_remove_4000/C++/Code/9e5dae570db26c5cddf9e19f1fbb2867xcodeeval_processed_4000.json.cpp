



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

int n, k;
set<int> g[N];
int siz[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	forn(i, n)
		g[i].clear();
	forn(i, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		--v, --u;
		g[v].insert(u);
		g[u].insert(v);
	}
	return true;
}

int cnt[N];
int val[N];
bool used[N];

void solve(){
	if (n == 1){
		puts("No");
		return;
	}
	
	memset(val, -1, sizeof(val));
	memset(cnt, 0, sizeof(cnt));
	memset(used, 0, sizeof(used));
	forn(i, n) siz[i] = sz(g[i]);
	
	int sum = 0;
	set<pt> lvs;
	forn(i, n) if (sz(g[i]) == 1){
		lvs.insert(mp(0, i));
		++sum;
		val[i] = 0;
		used[i] = true;
		cnt[i] = -INF;
	}
	
	int lst = -1;
	while (!lvs.empty()){
		int v = lvs.begin()->y;
		lvs.erase(lvs.begin());
		if (cnt[v] != -INF && cnt[v] < 3){
			puts("No");
			return;
		}
		lst = v;
		for (auto u : g[v]){
			++cnt[u];
			if (val[u] != -1 && val[u] != val[v] + 1){
				puts("No");
				return;
			}
			val[u] = val[v] + 1;
			if (siz[u] - cnt[u] <= (sum < n - 1) && !used[u]){
				lvs.insert(mp(val[u], u));
				++sum;
				used[u] = true;
			}
			g[u].erase(v);
		}
	}
	
	puts(sum == n && val[lst] == k ? "Yes" : "No");
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