



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

const int N = 10 * 1000 + 7;

int n, m;
bitset<N> a[N];

bool read () {
	if (scanf("%d%d", &m, &n) != 2)
		return false;
	forn(i, m){
		int k;
		scanf("%d", &k);
		a[i].reset();
		forn(j, k){
			int x;
			scanf("%d", &x);
			--x;
			a[i][x] = 1;
		}
	}
	return true;
}

void solve() {
	forn(i, m) forn(j, m) if (i != j && !(a[i] & a[j]).count()){
		puts("impossible");
		return;
	}
	
	puts("possible");
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