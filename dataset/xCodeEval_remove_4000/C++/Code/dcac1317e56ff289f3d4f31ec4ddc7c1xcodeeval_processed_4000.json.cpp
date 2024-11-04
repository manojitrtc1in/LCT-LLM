



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

int n, m;
int a[N];
pt q[N];

bool read () {
	if (scanf("%d%d", &n, &m) != 2)
		return false;
	forn(i, n){
		scanf("%d", &a[i]);
		--a[i];
	}
	forn(i, m){
		scanf("%d%d", &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
	}
	return true;
}

ld ls[N][N];

void solve() {
	forn(i, n) forn(j, n) ls[i][j] = (a[i] < a[j]);
	forn(i, m){
		int x = q[i].x;
		int y = q[i].y;
		forn(j, n) if (j != x && j != y) ls[x][j] = ls[y][j] = (ls[x][j] + ls[y][j]) / 2;
		forn(j, n) if (j != x && j != y) ls[j][x] = 1 - ls[x][j], ls[j][y] = 1 - ls[y][j];
		ls[x][y] = ls[y][x] = 0.5;
	}
	ld sum = 0;
	forn(i, n) forn(j, i) sum += ls[i][j];
	printf("%.15Lf\n", sum);
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