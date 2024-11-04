



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

struct circle{
	pt c;
	int r;
};

circle a, b;

bool read () {
	if (scanf("%d%d%d", &a.c.x, &a.c.y, &a.r) != 3)
		return false;
	scanf("%d%d%d", &b.c.x, &b.c.y, &b.r);
	return true;
}

li dist(const pt &a, const pt &b){
	return sqr(li(a.x - b.x)) + sqr(li(a.y - b.y));
}

void solve() {
	if (dist(a.c, b.c) >= sqr(li(a.r + b.r)))
		printf("%.15Lf\n", (sqrtl(dist(a.c, b.c)) - a.r - b.r) / 2);
	else
		printf("%.15Lf\n", max(ld(0), max(a.r, b.r) - min(a.r, b.r) - sqrtl(dist(a.c, b.c))) / 2);
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