



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

int n;
li k;
pt a[N];
pair<li, li> p;

bool read () {
	if (scanf("%d%lld", &n, &k) != 2)
		return false;
	scanf("%lld%lld", &p.x, &p.y);
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

void solve() {
	k %= 2 * n;
	forn(i, k) p = mp(2 * a[i % n].x - p.x, 2 * a[i % n].y - p.y);
	printf("%lld %lld\n", p.x, p.y);
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