






















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
template<class T> std::ostream& id1(T x, int n, int m) { FI(n) { FJ(m) cout << x[i][j] << (j == m - 1 ? '\n' : ' '); } return cout; }
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


ll id0(ll a, ll b, ll&x, ll&y){ if (!b) { x = 1; y = 0; return a; }	ll x1, y1, g;	g = id0(b, a%b, x1, y1); x = y1;	y = x1 - a / b*y1; return g; }


vll fact; void fact_prec(int n = 20){ fact.resize(n + 1); fact[0] = 1; FI1(n) { fact[i] = fact[i - 1] * i; } }
vector<ld> factd; void id2(int n = 146){ factd.resize(n + 1); factd[0] = 1; FI1(n) { factd[i] = factd[i - 1] * i; } }
string str(ll a) { string r = ""; for (; a; a /= 10) r += a % 10 + '0'; rev(r); return r; }
template <class T>int bitc(T x) { int r = 0;  for (T d = x; d > 0; d >>= 1) { r += d & 1; } return r; }

int sum_num(ll n) { int d = 0; for (; n; n /= 10) d += n % 10; return d; }


const int N = 200005;

typedef pair<string, int> psi;

string road[N];
int to[N];
map<char, int> mp[N];
int roadCount = 0;

int addRoad(int v, string d, int rC = 0) {
	

	if (!rC) {
		roadCount++;
		rC = roadCount;
		to[rC] = true;
	}

	char t = d[0];
	road[rC] = d;
	mp[v][t] = rC;
	

	return rC;
}

string w;
int stw = 0;
int add(int v = 0) {
	

	if (!w.length()) return 0;

	char t = w[stw];

	if (!mp[v].count(t)) {
		to[v] = false;			


		addRoad(v, w.substr(stw));
		return w.length()-stw;
	}
	else {
		int toR = mp[v][t];

		string& roadS = road[toR];

		int id = 0;
		while (id < roadS.length() && id+stw < w.length() && w[id+stw] == roadS[id]) {
			id++;
		}
		
		if (id+stw == w.length() && roadS.length() == id) {
			return to[toR] ? min(id, 2) : id;
		} else if (id == roadS.length()) {
			stw += roadS.length();
			return (to[toR]?min((int)roadS.length(), 2):roadS.length()) + add(toR);
		}
		else {
		
			string mrg = roadS.substr(0, id);
			int nw = addRoad(v, mrg);
			to[nw] = false;
			addRoad(nw, roadS.substr(id), toR);
			if (id + stw != w.length()) {
				addRoad(nw, w.substr(stw + id));
			}
			return w.length() - stw;
		}

		
	}

}



int main() {


	

	
	string s;
	int res = 0;
	while (getline(cin, s)) {
		w = "";
		for (char c : s) {
			if (isalpha(c)) {
				w += c;
			}
			else {
				stw = 0;

				int down = add();
				res += down;


				w = "";
				res++;;
			}
		}
		stw = 0;

		int down = add();
		res += down;
	

		res++;
	}

	ln(res);
	

	return 0;
}