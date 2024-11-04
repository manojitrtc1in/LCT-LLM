



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
const ld EPS = 1e-13;
const ld PI = acos(-1.0);

const int N = 2000 + 7;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

void solve() {
	li ans = 0;
	forn(i, n){
		vector<ld> cur;
		forn(j, n) if (i != j)
			cur.pb(atan2l(a[j].y - a[i].y, a[j].x - a[i].x));
		sort(all(cur));
		forn(j, n - 1)
			cur.pb(cur[j] + 2 * PI);
		int l = 0;
		forn(j, n - 1){
			while (cur[l] - cur[j] < PI - EPS)
				++l;
			int cntl = l - j;
			int cntr = (n - 1) - cntl;
			cntl = max(cntl - 1, 0);
			ans += cntl * li(cntl - 1) * li(cntr) * li(cntr - 1) / 4;
		}
	}
	printf("%lld\n", ans / 2);
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