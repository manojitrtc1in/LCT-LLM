






















using namespace std;



typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pii> vpll;

















const int INF = 1000001000;
const ll INFLL = INF * 1LL * INF;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const int modr = 99990001;
const ld PI = 3.1415926535897932385;










































































template<class T> void zero(T val, T& x) { x = val; }
template<class T, class... Targs> void zero(T val, T& x, Targs&... Fargs) { x = val; zero(val, Fargs...); }


template<class T, class T2> std::istream& operator>> (std::istream& is, pair<T, T2>& p) { return is >> p.x >> p.y; }
template<class T> std::istream& readN(T& x, int n, int st = 0) { F(i, st, st + n - 1) cin >> x[i]; return cin; }
template<class T> std::istream& readS(set<T>& x, int n) { T y = *x.rbegin(); FI(n) { cin >> y; x.insert(y); } return cin; }
template<class T> std::istream& read(T& x) { return cin >> x; }
template<class T, class... Targs> std::istream& read(T& x, Targs&... Fargs) { return read(x), read(Fargs...); }












template<class T, class T2> std::ostream& operator<< (std::ostream& os, pair<T, T2> p) { return os << p.x << " " << p.y; }
template<class T> std::ostream& operator<< (std::ostream& os, vector<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T> std::ostream& operator<< (std::ostream& os, set<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T> std::ostream& operator<< (std::ostream& os, multiset<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T, class T2> std::ostream& operator<< (std::ostream& os, map<T, T2> v) { bool f = true; for (pair<T, T2> y : v) { if (!f) os << ' '; os << y.x << "=>" << y.y;  f = false; } return os; }
template<class T> std::ostream& outV(T x, char del = ' ') { bool f = true; for (auto y : x) { if (!f) cout << del; cout << y;  f = false; } return cout; }
template<class T> std::ostream& outN(T x, int n = -1, int st = 0) { F(i, st, n == -1 ? (int)x.size() - 1 : st + n - 1) { cout << x[i]; if (i < iend) cout << ' '; } return cout; }
template<class T> std::ostream& outAN(T x, int n = -1, int st = 0) { F(i, st, n - 1) { cout << x[i]; if (i < iend) cout << ' '; } return cout; }
template<class T> std::ostream& id0(T x, int n, int m) { FI(n) { FJ(m) cout << x[i][j] << (j == m - 1 ? '\n' : ' '); } return cout; }
template<class T> std::ostream& out(T x) { return cout << x; }
template<class T, class... Targs> std::ostream& out(T x, Targs... Fargs) { return out(x) << " ", out(Fargs...); }

template<typename T> void srt(T& a, int st, int fn, bool isArr) { sort(a + st, a + fn + 1); }
template<class T> void srt(T& a, int st = 0, int fn = 0) { sort(a.begin() + st, fn ? a.begin() + fn + 1 : a.end()); }

template<typename T> T rev_num(T a) { T r = 0; for (; a; a /= 10) r = r * 10 + a % 10; return r; }
template<typename T> void rev(T& a, int st, int fn, bool isArr) { reverse(a + st, a + fn + 1); }
template<class T> void rev(T& a, int st = 0, int fn = 0) { reverse(a.begin() + st, fn ? a.begin() + fn + 1 : a.end()); }

ll sqr(ll a) { return a*a; };
ll sqr(int a) { return a * 1LL * a; };
ld sqr(ld a) { return a*a; };
ll sqDist(pll x, pll y) { return sqr(x.x - y.x) + sqr(x.y - y.y); }
ld dist(pll x, pll y) { return sqrtl(sqDist(x, y)); }

ll phi(int n) { int res = n; for (ll i = 2; i*i <= n; i++) if (n%i == 0) { while (n%i == 0) n /= i; res -= res / i; } if (n > 1) res -= res / n; return res; }
ll bpm(ll a, ll n = -2, ll m = mod) { n = n < 0 ? n + m : n; ll r = 1; while (n) { if (n & 1) r = (r*a) % m; a = (a*a) % m; n >>= 1; } return r; }
ull gcd(ull a, ull b) { while (b) { a %= b; swap(a, b); } return a; }
vi ero_p, ero_l; void ero(int n) { ero_l.resize(n + 1); ero_l[0] = -1; F(i, 2, n) if (!ero_l[i]) { ero_p.push_back(i); ero_l[i] = i; for (ll j = i * 1LL * i; j <= n; j += i) { ero_l[j] = i; } } }


ll id2(ll a, ll b, ll&x, ll&y){ if (!b) { x = 1; y = 0; return a; }	ll x1, y1, g;	g = id2(b, a%b, x1, y1); x = y1;	y = x1 - a / b*y1; return g; }


vll fact; void fact_prec(int n = 20){ fact.resize(n + 1); fact[0] = 1; FI1(n) { fact[i] = fact[i - 1] * i; } }
vector<ld> factd; void id1(int n = 146){ factd.resize(n + 1); factd[0] = 1; FI1(n) { factd[i] = factd[i - 1] * i; } }
string str(ll a) { string r = ""; for (; a; a /= 10) r += a % 10 + '0'; rev(r); return r; }
template <class T>int bitc(T x) { int r = 0;  for (T d = x; d > 0; d >>= 1) { r += d & 1; } return r; }

int sum_num(ll n) { int d = 0; for (; n; n /= 10) d += n % 10; return d; }


const int N = 100005;


int cost[N], cnt[N];
int p[N], tme[N];
bool del[N];
int path[N], ps = 0;
vi g[N];
ll ans = 0, cntr = 1;

int get(int v) {
	return p[v] = (p[v] == v ? v : get(p[v]));
}

void merge(int v1, int v2) {
	v1 = get(v1);
	v2 = get(v2);
	if (v1 != v2) {

		if (rand() % 2) swap(v1, v2);

		p[v2] = v1;

		int pv = v1;
		int pthv = v2;
		cnt[pv] = cost[pv] == cost[pthv] ? cnt[pv] + cnt[pthv] : cost[pv] < cost[pthv] ? cnt[pv] : cnt[pthv];
		cost[pv] = min(cost[pv], cost[pthv]);
		tme[pv] = min(tme[pv], tme[pthv]);
		tme[pthv] = INF;
	}
}

void dfs(int v, int t=0) {
	path[ps++] = v;
	

	int pv = get(v);

	if (del[v]) {
		ps--;
		return;
	}
	del[v] = true;

	tme[v] = t;

	for (int x : g[v]) {
		if (get(x) != get(v)) {
	

			dfs(x, t + 1);
	

			if (tme[get(x)] != INF) {
	

				merge(x, v);
			}
		}
	}

	int tv = get(v);
	if (tme[get(v)] == t ) {
		ans += cost[tv];
		cntr = (cntr * cnt[tv]) % mod;
		tme[tv] = INF;
	}
	ps--;

}


int main() {
	

	


	int n; scanf("%d", &n);

	ll f = 0;

	FI1(n) {
		scanf("%d", &cost[i]);

		tme[i] = INF;
		cnt[i] = 1;
		p[i] = i;
	}

	int m;
	scanf("%d ", &m);

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x].push_back(y);
	}


	FI1(n) {
		if (!del[i]) {
			dfs(i);
		}
	}



	ln(ans, cntr);
	

	return 0;
}
