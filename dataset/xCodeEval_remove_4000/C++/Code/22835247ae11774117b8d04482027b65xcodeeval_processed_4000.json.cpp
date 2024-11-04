



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

const int N = 5000 + 7;
const int M = 100 + 7;

int n, m;
int a[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	return true;
}

int cnt[M];

void solve() {
	memset(cnt, 0, sizeof(cnt));
	forn(i, n) ++cnt[a[i]];
	vector<pt> cur;
	forn(i, m) cur.pb(mp(cnt[i], i));
	sort(all(cur));
	vector<int> ord;
	for (auto it : cur) forn(_, it.x)
		ord.pb(it.y);
	int cnt = 0;
	forn(i, n)
		cnt += ord[i] != ord[(i + n / 2) % n];
	printf("%d\n", cnt);
	forn(i, n)
		printf("%d %d\n", ord[i] + 1, ord[(i + n / 2) % n] + 1);
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