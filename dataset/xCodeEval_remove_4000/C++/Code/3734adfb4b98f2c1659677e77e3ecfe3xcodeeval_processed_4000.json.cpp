



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

const int N = 3000 + 7;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

bitset<N> d[N];

void solve() {
	forn(i, n){
		d[i].reset();
		forn(j, n) d[i][j] = (j != i);
	}
	
	vector<pair<int, pt>> e;
	forn(i, n) forn(j, i)
		e.pb(mp(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y), mp(i, j)));
	sort(all(e));
	
	int ans = 0;
	for (auto it : e){		
		int x = it.y.x, y = it.y.y;
		if ((d[x] & d[y]).count())
			ans = it.x;
		d[x][y] = 0;
		d[y][x] = 0;
	}
	printf("%.15Lf\n", sqrtl(ans) / 2);
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