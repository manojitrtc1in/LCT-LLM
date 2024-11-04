



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
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 1000 * 1000 + 13;

int n, m;
int a[N];
pt q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

bool pr[N];
vector<int> prs;

void sieve(){
	memset(pr, 0, sizeof(pr));
	prs.clear();
	fore(i, 2, N){
		if (pr[i]) continue;
		prs.pb(i);
		for (li j = i * li(i); j < N; j += i)
			pr[j] = true;
	}
	fore(i, 2, N) pr[i] ^= 1;
}

int p[N], rk[N];

int getp(int a){
	return a == p[a] ? a : p[a] = getp(p[a]);
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
}

int pos[N];
int ans[N];
vector<int> divs[N];

map<pt, vector<int>> sv;

void solve() {
	forn(i, N) rk[i] = 1, p[i] = i;
	memset(pos, -1, sizeof(pos));
	forn(i, n) pos[a[i]] = i;
	forn(i, N) if (pr[i]){
		for (int j = i; j < N; j += i) if (pos[j] != -1)
			unite(j, i);
	}
	sv.clear();
	forn(i, m){
		q[i].x = getp(a[q[i].x]);
		q[i].y = getp(a[q[i].y]);
		if (q[i].x > q[i].y)
			swap(q[i].x, q[i].y);
		if (q[i].x == q[i].y)
			ans[i] = 0;
		else{
			ans[i] = 2;
			sv[q[i]].pb(i);
		}
	}
	forn(i, N) divs[i].clear();
	forn(i, N) if (pr[i]){
		for (int j = i; j < N; j += i)
			divs[j].pb(i);
	}
	forn(i, N) if (pr[i]){
		for (int j = i; j < N; j += i) if (pos[j - 1] != -1){
			int x = getp(i);
			int y = getp(j - 1);
			if (x > y) swap(x, y);
			auto it = sv.find(mp(x, y));
			if (it == sv.end()) continue;
			while (!it->y.empty()){
				ans[it->y.back()] = 1;
				it->y.pop_back();
			}
			sv.erase(it);
		}
	}
	forn(i, N) if (pos[i] != -1){
		forn(j, sz(divs[i + 1])) forn(k, j){
			int x = getp(divs[i + 1][j]);
			int y = getp(divs[i + 1][k]);
			if (x > y) swap(x, y);
			auto it = sv.find(mp(x, y));
			if (it == sv.end()) continue;
			while (!it->y.empty()){
				ans[it->y.back()] = 1;
				it->y.pop_back();
			}
			sv.erase(it);
		}
	}
	forn(i, m) printf("%d\n", ans[i]);
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	sieve();

	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	while(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}