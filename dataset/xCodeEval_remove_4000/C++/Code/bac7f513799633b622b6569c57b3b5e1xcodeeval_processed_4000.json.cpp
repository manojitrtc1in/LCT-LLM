



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

const int N = 500 * 1000 + 13;
const int M = 2 * N;

int n, m;
li k;
int a[N], b[N];

bool read () {
	if (scanf("%d%d%lld", &n, &m, &k) != 3)
		return false;
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m)
		scanf("%d", &b[i]);
	return true;
}

li gcd(li a, li b, li& x, li& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    li x1, y1;
    li d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool id0(li a, li b, li c, li &x0, li &y0, li &g) {
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

struct sol{
	bool fl;
	li x0, y0, g;
};

sol q[M];
int pos[M];

inline li down(li a, li b){
	if (a > 0) return a / b;
	return (a - b + 1) / b;
}

li coef;
li base;

pair<int, li> c[N];
int siz;

li get(li d){
	li cnt = d - base;
	forn(z, siz) cnt += down(c[z].x + c[z].y * n - d, coef);
	return cnt;
}

void solve() {
	li x, y;
	li g = gcd(n, m, x, y);
	fore(i, -(n - 1), m){
		li x0 = x, y0 = y, g0 = g;
		q[i + N].fl = id0(n, -m, i, x0, y0, g0);
		q[i + N].x0 = x0;
		q[i + N].y0 = y0;
		q[i + N].g = g;
	}
	coef = m / g * n;
	memset(pos, -1, sizeof(pos));
	forn(i, m) pos[b[i]] = i;
	
	siz = 0;
	forn(x, n) if (pos[a[x]] != -1){
		int y = pos[a[x]];
		int i = y - x + N;
		if (!q[i].fl) continue;
		c[siz++] = {x, q[i].x0};
	}
	
	base = 0;
	forn(x, n) if (pos[a[x]] != -1){
		int y = pos[a[x]];
		int i = y - x + N;
		if (!q[i].fl) continue;
		li c = x + q[i].x0 * n;
		base += down(c, coef);
	}
	
	li l = 1, r = INF64;
	li res = -1;
	while (l <= r){
		li m = (l + r) / 2;
		if (get(m) >= k){
			res = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	
	printf("%lld\n", res);
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