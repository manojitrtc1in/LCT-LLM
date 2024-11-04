



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

const int INF = int(2e9);
const li INF64 = li(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	forn(i, n)
		scanf("%d%d", &a[i].x, &a[i].y);
	return true;
}

map<pt, pair<li, li>> qs;

pair<li, li> operator +=(pair<li, li> &a, const pair<li, li> &b){
	a.x += b.x;
	a.y += b.y;
	return a;
}

pair<li, li> operator -=(pair<li, li> &a, const pair<li, li> &b){
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

void solve() {
	qs.clear();
	qs[mp(-INF, 1)] = mp(0, 0);
	qs[mp(INF, 1)] = mp(0, 0);
	forn(i, n){
		int g = __gcd(abs(a[i].x), abs(a[i].y));
		if (a[i].x == 0)
			continue;
		if (a[i].x < 0){
			qs[mp(-INF, 1)] += a[i];
			qs[mp(a[i].y/g, -a[i].x/g)] -= a[i];
		}
		else{
			qs[mp(-a[i].y/g, a[i].x/g)] += a[i];
			qs[mp(INF, 1)] -= a[i];
		}
	}
	vector<pair<pt, pair<li, li>>> res(all(qs));
	

	sort(all(res), [](const pair<pt, pair<li, li>> &a, const pair<pt, pair<li, li>> &b){
		return a.x.x * li(b.x.y) < b.x.x * li(a.x.y);
	});
	res.resize(unique(all(res), [](const pair<pt, pair<li, li>> &a, const pair<pt, pair<li, li>> &b){
		return a.y == b.y;
	}) - res.begin());
	printf("%d\n", max(0, sz(res) - 2));
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