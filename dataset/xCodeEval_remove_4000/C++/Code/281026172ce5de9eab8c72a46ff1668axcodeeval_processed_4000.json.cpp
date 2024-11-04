



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

const int N = 1000 + 7;

int n;
int a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

void solve() {
	vector<pt> p;
	forn(i, n) p.pb(mp(a[i], i));
	vector<pt> invs;
	forn(i, n) forn(j, i) if (p[j] > p[i])
		invs.pb(mp(j, i));
	sort(all(invs), [&](const pt &x, const pt &y){
		if (x.y != y.y)
			return x.y > y.y;
		return p[x.x] < p[y.x];
	});
	printf("%d\n", sz(invs));
	for (auto it : invs){
		swap(p[it.x], p[it.y]);
		printf("%d %d\n", it.x + 1, it.y + 1);
	}
	cerr << p << endl;
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