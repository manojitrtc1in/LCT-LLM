



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

const int N = 50 + 7;

int n;
vector<string> a;

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[N];
	a.resize(n);
	forn(i, n){
		scanf("%s", buf);
		a[i] = buf;
	}
	return true;
}

int pr[N][N];

int get(int x1, int y1, int x2, int y2){
	return pr[x2 + 1][y2 + 1] - pr[x1][y2 + 1] - pr[x2 + 1][y1] + pr[x1][y1];
}

int dp[N][N][N][N];

int calc(int x1, int y1, int x2, int y2){
	if (x1 > x2 || y1 > y2)
		return 0;
	
	int &d = dp[x1][y1][x2][y2];
	if (d != -1) 
		return d;
	if (get(x1, y1, x2, y2) == 0)
		return d = 0;
	
	while (get(x1, y1, x2, y1) == 0)
		++y1;
	while (get(x1, y1, x1, y2) == 0)
		++x1;
	while (get(x1, y2, x2, y2) == 0)
		--y2;
	while (get(x2, y1, x2, y2) == 0)
		--x2;
	
	if (x2 - x1 > y2 - y1){
		d = x2 - x1 + 1;
		fore(x, x1 + 1, x2) if (get(x, y1, x, y2) == 0)
			d = min(d, calc(x1, y1, x - 1, y2) + calc(x + 1, y1, x2, y2));
	}
	else{
		d = y2 - y1 + 1;
		fore(y, y1 + 1, y2) if (get(x1, y, x2, y) == 0)
			d = min(d, calc(x1, y1, x2, y - 1) + calc(x1, y + 1, x2, y2));
	}
	return d;
}

void solve() {
	forn(i, n) forn(j, n)
		pr[i + 1][j + 1] = pr[i + 1][j] + pr[i][j + 1] - pr[i][j] + (a[i][j] == '
	memset(dp, -1, sizeof(dp));
	printf("%d\n", calc(0, 0, n - 1, n - 1));
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