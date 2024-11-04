



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

const int N = 1 << 9;

int k;

bool read () {
	if (scanf("%d", &k) != 1)
		return false;
	return true;
}

bitset<N> ans[N];

void solve() {
	ans[0][0] = 0;
	forn(i, k){
		forn(x, 1 << i) forn(y, 1 << i){
			ans[x + (1 << i)][y + (1 << i)] = ans[x][y];
			ans[x + (1 << i)][y] = ans[x][y];
			ans[x][y + (1 << i)] = !ans[x][y];
		}
	}
	forn(i, 1 << k){
		forn(j, 1 << k)
			printf("%c", ans[i][j] ? '+' : '*');
		puts("");
	}
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