



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

int n, k;
int c0, c1;

bool read () {
	if (scanf("%d%d", &n, &k) != 2)
		return false;
	c0 = c1 = 0;
	forn(i, n){
		int x;
		scanf("%d", &x);
		if (x & 1)
			++c1;
		else
			++c0;
	}
	return true;
}

void solve() {
	int ans;
	if (n == k)
		ans = c1 & 1;
	else if (n % 2 == k % 2){
		if (n & 1)
			ans = (k + c0 * 2 <= n);
		else
			ans = 0;
	}
	else{
		if (n & 1)
			ans = (min(c0, c1) * 2 + k >= n + 1);
		else
			ans = (c1 * 2 + k > n);
	}
	puts(ans ? "Stannis" : "Daenerys");
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