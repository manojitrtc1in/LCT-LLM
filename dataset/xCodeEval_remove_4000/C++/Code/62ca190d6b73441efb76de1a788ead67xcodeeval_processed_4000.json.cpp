



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

const int N = 200 * 1000 + 13;

int n, v;
int a[N], t[N];

bool read () {
	if (scanf("%d%d", &n, &v) != 2)
		return false;
	forn(i, n)
		scanf("%d", &t[i]);
	forn(i, n)
		scanf("%d", &a[i]);
	return true;
}

void solve() {
	vector<pair<li, li>> nw;
	forn(i, n) if (abs(a[i]) <= v * li(t[i])){
		li x = v * li(t[i]) - a[i];
		li y = v * li(t[i]) + a[i];
		nw.pb(mp(x, y));
	}
	sort(all(nw));
	vector<li> lis;
	for (auto it : nw){
		li x = it.y;
		auto jt = upper_bound(all(lis), x);
		if (jt == lis.end())
			lis.pb(x);
		else
			*jt = x;
	}
	printf("%d\n", sz(lis));
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