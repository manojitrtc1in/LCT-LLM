























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

















const int INF = 1000001000;
const ll INFLL = INF * 1LL * INF;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const int modr = 99990001;
const ld PI = 3.1415926535897932385;












































































template<class T> void zero(T val, T & x) { x = val; }
template<class T, class... Targs> void zero(T val, T& x, Targs& ... Fargs) { x = val; zero(val, Fargs...); }


template<class T, class T2> std::istream& operator>> (std::istream& is, pair<T, T2>& p) { return is >> p.x >> p.y; }
template<class T> std::istream& readN(T& x, int n, int st = 0) { F(i, st, st + n - 1) cin >> x[i]; return cin; }
template<class T> std::istream& readS(set<T> & x, int n) { T y = *x.rbegin(); FI(n) { cin >> y; x.insert(y); } return cin; }
template<class T> std::istream& read(T & x) { return cin >> x; }
template<class T, class... Targs> std::istream& read(T & x, Targs & ... Fargs) { return read(x), read(Fargs...); }









template<class T, class T2> std::ostream& operator<< (std::ostream & os, pair<T, T2> p) { return os << p.x << " " << p.y; }
template<class T> std::ostream& operator<< (std::ostream & os, vector<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T> std::ostream& operator<< (std::ostream & os, set<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T> std::ostream& operator<< (std::ostream & os, multiset<T> v) { bool f = true; for (auto y : v) { if (!f) os << ' '; os << y;  f = false; } return os; }
template<class T, class T2> std::ostream& operator<< (std::ostream & os, map<T, T2> v) { bool f = true; for (pair<T, T2> y : v) { if (!f) os << ' '; os << y.x << "=>" << y.y;  f = false; } return os; }
template<class T> std::ostream& outV(T x, char del = ' ') { bool f = true; for (auto y : x) { if (!f) cout << del; cout << y;  f = false; } return cout; }
template<class T> std::ostream& outN(T x, int n = -1, int st = 0) { F(i, st, n == -1 ? (int)x.size() - 1 : st + n - 1) { cout << x[i]; if (i < iend) cout << ' '; } return cout; }
template<class T> std::ostream& outAN(T x, int n = -1, int st = 0) { F(i, st, n - 1) { cout << x[i]; if (i < iend) cout << ' '; } return cout; }
template<class T> std::ostream& id3(T x, int n, int m) { FI(n) { FJ(m) cout << x[i][j] << (j == m - 1 ? '\n' : ' '); } return cout; }
template<class T> std::ostream& out(T x) { return cout << x; }
template<class T, class... Targs> std::ostream& out(T x, Targs... Fargs) { return out(x) << " ", out(Fargs...); }

template<typename T> void srt(T & a, int st, int fn, bool isArr) { sort(a + st, a + fn + 1); }
template<class T> void srt(T & a, int st = 0, int fn = 0) { sort(a.begin() + st, fn ? a.begin() + fn + 1 : a.end()); }

template<typename T> T rev_num(T a) { T r = 0; for (; a; a /= 10) r = r * 10 + a % 10; return r; }
template<typename T> T sum_num(T a) { T r = 0; for (; a; a /= 10) r += a % 10; return r; }
template<typename T> void rev(T & a, int st, int fn, bool isArr) { reverse(a + st, a + fn + 1); }
template<class T> void rev(T & a, int st = 0, int fn = 0) { reverse(a.begin() + st, fn ? a.begin() + fn + 1 : a.end()); }

ll sqr(ll a) { return a * a; };
ll sqr(int a) { return a * 1LL * a; };
ld sqr(ld a) { return a * a; };

ll phi(int n) { int res = n; for (ll i = 2; i * i <= n; i++) if (n % i == 0) { while (n % i == 0) n /= i; res -= res / i; } if (n > 1) res -= res / n; return res; }
ll bpm(ll a, ll n = -2, ll m = mod) { n = n < 0 ? n + m : n; ll r = 1; while (n) { if (n & 1) r = (r * a) % m; a = (a * a) % m; n >>= 1; } return r; }
ull gcd(ull a, ull b) { while (b) { a %= b; swap(a, b); } return a; }


vi ero_p, ero_l; void ero(int n) { ero_l.resize(n + 1); ero_l[0] = -1; F(i, 2, n) if (!ero_l[i]) { ero_p.push_back(i); ero_l[i] = i; for (ll j = i * 1LL * i; j <= n; j += i) { ero_l[j] = i; } } }


ll id1(ll a, ll b, ll & x, ll & y) { if (!b) { x = 1; y = 0; return a; }	ll x1, y1, g;	g = id1(b, a % b, x1, y1); x = y1;	y = x1 - a / b * y1; return g; }


vll fact; void fact_prec(int n = 20) { fact.resize(n + 1); fact[0] = 1; FI1(n) { fact[i] = fact[i - 1] * i; } }
vector<ld> factd; void id5(int n = 146) { factd.resize(n + 1); factd[0] = 1; FI1(n) { factd[i] = factd[i - 1] * i; } }
string str(ll a) { string r = ""; for (; a; a /= 10) r += a % 10 + '0'; rev(r); return r; }


template<typename T, typename T2> T dup(T a, T2 b) { return (a / b) + (a % b != 0); }
ll fromM(string s, int delIndex = 0, int M = 16) { ll res = 0;	for (auto a : s) { a = toupper(a); if (a < '0' || a > '9') { a -= delIndex; if (a < 'A') a = '9' - 'A' + a + 1; } else { a -= delIndex; }; res = res * M + (a > '9' || a < '0' ? a - 'A' + 10 : a - '0'); } return res; };
string toM(ll n, int delIndex = 0, int M = 16) { string res = "";  while (n) { int m = n % M + delIndex; n /= M; res += (m < 10 ? '0' + m : 'A' + (m - 10)); } rev(res); return res; }
ll castLL(string s) { ll res = 0;	for (auto a : s) { res = res * 10 + a - '0'; } return res; }
template<typename T> string castString(T n) { string res = "";  while (n) { int m = n % 10; n /= 10; res += '0' + m; } rev(res); return res; }

typedef pair<ld, ld> pnt2;
ld dist(pnt2 from, pnt2 to) { return sqrt(sqr(from.x - to.x) + sqr(from.y - to.y)); }
pii operator+ (const pii & f, const pii & s) { return { f.x + s.x, f.y + s.y }; }


const int N = 200005;

int a[N];
int b[N];
int c[N];
int curd[N];

void solution() {

		DI(k1, k2, k3);
		
		
		RA(a, k1);
		RA(b, k2);
		RA(c, k3);
		
		sort(a, a+k1);
		
		sort(b, b+k2);
		
		sort(c, c+k3);
		
		c[k3++] = k1 + k2 + k3;

		int n = k1 + k2 + k3;
		int mn = n;

		
		FI(k1) {
			curd[a[i]]--;
		}
		
		FI(k2) {
			curd[b[i]]++;
		}
		
		FI1(n) {
			curd[i] += curd[i-1];
		}
		
		int cura = 0, curb = 0, curc = 0;
		
		
		int id0 = k1, id2 = k2, id4 = k3;
		int dmn = 0;
		
		F(r, 1, n) {
			
			int cnst = k1 + id2 + k3 - id4;
			
			if (cura < k1) {
				if (r == a[cura]) {
					id0--;
					cura++;
				}
			}

			if (curb < k2) {
				if (r == b[curb]) {
					id2--;
					curb++;
				}
			}

			if (curc < k3) {
				if (r == c[curc]) {
					id4--;
					curc++;
				}
			}

			int rs = curd[r-1];
			
			dmn = min(dmn, rs);
			
			mn = min(mn, cnst + dmn);
		}
		
		ln(mn);
		
		

}


int main() {
	


	


	solution();

	

	return 0;
}