



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

int n, m;

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	return true;
}

void solve() {
	vector<pt> a;
	forn(dx, 2) forn(dy, 2) if (dx <= n && dy <= m){
		a.pb(mp(dx, dy));
		a.pb(mp(n - dx, m - dy));
	}
	a.pb(mp(0, m));
	a.pb(mp(n, 0));
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	
	int n = sz(a);
	ld res = 0;
	vector<pt> bst;
	forn(i, n) forn(j, n) forn(k, n) forn(t, n){
		if (sz(set<pt>({a[i], a[j], a[k], a[t]})) != 4) continue;
		ld dist = sqrtl(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y)) +
				  sqrtl(sqr(a[j].x - a[k].x) + sqr(a[j].y - a[k].y)) +
				  sqrtl(sqr(a[k].x - a[t].x) + sqr(a[k].y - a[t].y));
		if (dist > res){
			res = dist;
			bst = {a[i], a[j], a[k], a[t]};
		}
	}
	for (auto it : bst)
		printf("%d %d\n", it.x, it.y);
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