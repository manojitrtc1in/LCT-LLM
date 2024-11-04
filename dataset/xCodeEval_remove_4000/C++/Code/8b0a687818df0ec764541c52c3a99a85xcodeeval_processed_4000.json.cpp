



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

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	return true;
}

int ask(int l, int r){
	printf("? %d %d\n", l + 1, r);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}

int val[N], a[N];

void solve() {
	forn(i, n - 1) val[i] = ask(i, i + 2);
	int sum = ask(0, 3);
	a[0] = sum - val[1];
	fore(i, 1, n) a[i] = val[i - 1] - a[i - 1];
	printf("!");
	forn(i, n) printf(" %d", a[i]);
	puts("");
	fflush(stdout);
}

int main() {





	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;


	int tc;
	scanf("%d", &tc);
	while(tc--){
		read();

	if(read()) {	

		solve();
		

	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();


	}
}