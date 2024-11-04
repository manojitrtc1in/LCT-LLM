



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

const int N = 100 * 1000 + 13;

int n, k;
int a[N], b[N];

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	k = min(k, 2);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	return true;
}

void solve() {	
	li ans = 0;
	
	if (k == 0){
		li sum = 0;
		for (int i = n - 1; i >= 0; --i){
			sum += a[i];
			ans = max(ans, sum - b[i]);
		}
		printf("%lld\n", ans);
		return;
	}
	
	if (k == 1){
		li tmp = accumulate(a, a + n, 0ll) - b[0];
		fore(i, 1, n - 1)
			ans = max(ans, max(0, a[i] - b[i]) + (tmp - a[i]));
		li sum = 0;
		for (int i = n - 1; i >= 1; --i){
			sum += a[i];
			ans = max(ans, sum - b[i]);
		}
		int prmn = INF;
		li prval = 0, suval = accumulate(a, a + n, 0ll);
		forn(i, n - 1){
			prmn = min(prmn, b[i]);
			prval += a[i];
			suval -= a[i];
			if (i > 0)
				ans = max(ans, max(0ll, prval - prmn) + max(0ll, suval - b[i + 1]));
		}
		printf("%lld\n", ans);
		return;
	}
	
	ans = max(ans, li(a[n - 1]) - b[n - 1]);
	ans = max(ans, accumulate(a, a + n, 0ll) - *min_element(b, b + n - 1));
	
	printf("%lld\n", ans);
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