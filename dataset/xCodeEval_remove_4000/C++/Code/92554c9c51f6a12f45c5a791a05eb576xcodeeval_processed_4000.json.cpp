



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

const int N = 100 + 7;

int n, k;
vector<int> a, b;

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	a.resize(n);
	b.resize(n);
	forn(i, n){
		scanf("%d", &b[i]);
		--b[i];
	}
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

void solve() {
	vector<vector<int>> up, dw;
	set<vector<int>> used;
	vector<int> cur(n);
	iota(all(cur), 0);
	while (true){
		if (used.count(cur) || sz(used) == 120)
			break;
		used.insert(cur);
		up.pb(cur);
		vector<int> nw(n);
		forn(i, n) nw[i] = cur[b[i]];
		cur = nw;
	}
	
	vector<int> rb(n);
	forn(i, n) rb[b[i]] = i;
	iota(all(cur), 0);
	used.clear();
	while (true){
		if (used.count(cur) || sz(used) == 120)
			break;
		used.insert(cur);
		dw.pb(cur);
		vector<int> nw(n);
		forn(i, n) nw[i] = cur[rb[i]];
		cur = nw;
	}
	
	if (sz(up) == 1){
		puts("NO");
		return;
	}
	if (sz(up) == 2){
		puts(k == 1 && a == up[1] ? "YES" : "NO");
		return;
	}
	forn(i, sz(up)) if (up[i] == a){
		if (i == 0){
			puts("NO");
			return;
		}
		if (i % 2 == k % 2 && i <= k){
			puts("YES");
			return;
		}
	}
	forn(i, sz(dw)) if (dw[i] == a){
		if (i % 2 == k % 2 && i <= k){
			puts("YES");
			return;
		}
	}
	puts("NO");
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


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