



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

const int N = 10 * 1000 + 13;

int n;
li a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%lld", &a[i]);
	return true;
}

void solve() {
	int sum = accumulate(a, a + n, 0);
	if (sum % n != 0){
		puts("-1");
		return;
	}
	vector<pair<pt, int>> ans;
	int x = sum / n;
	fore(i, 1, n){
		int y = (((i + 1) - a[i]) % (i + 1) + (i + 1)) % (i + 1);
		ans.pb(mp(mp(0, i), y));
		a[0] -= y;
		a[i] += y;
		ans.pb(mp(mp(i, 0), a[i] / (i + 1)));
		a[0] += a[i];
		a[i] = 0;
	}
	fore(i, 1, n){
		ans.pb(mp(mp(0, i), x));
		a[0] -= x;
		a[i] = x;
	}
	

	printf("%d\n", sz(ans));
	for (auto it : ans)
		printf("%d %d %d\n", it.x.x + 1, it.x.y + 1, it.y);
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