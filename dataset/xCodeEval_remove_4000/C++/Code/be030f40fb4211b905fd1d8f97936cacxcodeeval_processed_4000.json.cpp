



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

mt19937 rnd(42);

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 100 * 1000 + 13;

int n;
pt a[N];

bool read () {
	if (scanf("%d", &n) != 1)
		return false;
	static char buf[10];
	forn(i, n){
		scanf("%s", buf);
		a[i].x = buf[0] == 'W' ? 1 : (buf[0] == 'B' ? 0 : -1);
		a[i].y = buf[1] == 'B' ? 1 : (buf[1] == 'W' ? 0 : -1);
	}
	return true;
}

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * li(b) % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int ans;

void brute(int x, int wi, int wo, int w, int bi, int bo, int b){
	if (x == n){
		if (wi != wo || bi != bo) return;
		if (wi == w && bi == b && wi != 0 && bi != 0) return;
		++ans;
		return;
	}
	forn(i, 2) forn(j, 2) if ((a[x].x == i || a[x].x == -1) && (a[x].y == j || a[x].y == -1)){
		brute(x + 1, wi + i, wo + j, w + (i && j), bi + (!i), bo + (!j), b + (!i && !j));
	}
}

int pw[N];
int fact[N], rfact[N];

int cnk(int n, int k){
	if (n < 0 || k < 0 || k > n) return 0;
	return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void solve() {
	if (n <= 2){
		ans = 0;
		brute(0, 0, 0, 0, 0, 0, 0);
		printf("%d\n", ans);
		return;
	}
	int wi = 0, wo = 0, w = 0;
	int bi = 0, bo = 0, b = 0;
	int posw = -1, posb = -1;
	int nw = 0, nb = 0;
	int bw = 0;
	forn(i, n){
		wi += a[i].x == 1;
		wo += a[i].y == 1;
		bi += a[i].x == 0;
		bo += a[i].y == 0;
		w += a[i].x == 1 && a[i].y == 1;
		b += a[i].x == 0 && a[i].y == 0;
		if (a[i].x == 1 || a[i].y == 1) posw = i;
		if (a[i].x == 0 || a[i].y == 0) posb = i;
		if (a[i].x != 1 && a[i].y != 1) ++nw;
		if (a[i].x != 0 && a[i].y != 0) ++nb;
		if (a[i].x == 0 && a[i].y == 1) ++bw;
		if (a[i].x == 1 && a[i].y == 0) ++bw;
	}
	int ans = 0;
	forn(W, n + 1){
		int B = n - W;
		if (W < max(wi, wo)) continue;
		if (B < max(bi, bo)) continue;
		ans = add(ans, mul(cnk(n - wi - bi, W - wi), cnk(n - wo - bo, W - wo)));
		if (W != 0 && B != 0 && bw == 0){
			int bb = bi + bo - b;
			int ww = wi + wo - w;
			int id1 = W - ww;
			int id0 = B - bb;
			int lft = n - bb - ww;
			if (id1 + id0 <= lft)
				ans = add(ans, -cnk(lft, id1));
		}
	}
	printf("%d\n", ans);
}

void init(){
	pw[0] = 1;
	fore(i, 1, N) pw[i] = mul(pw[i - 1], 2);
	fact[0] = 1;
	fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	rfact[N - 1] = binpow(fact[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; --i)
		rfact[i] = mul(rfact[i + 1], i + 1);
}

int main() {

	freopen("input.txt", "r", stdin);


	
	int tt = clock();
	

	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	init();

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