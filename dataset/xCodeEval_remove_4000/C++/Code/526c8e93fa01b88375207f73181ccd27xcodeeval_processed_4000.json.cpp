























using namespace std;








using namespace std::tr1;


































double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };


template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a < t2.a; else return t1.b < t2.b; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }





















































inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return (x >> 31) | (-x >> 31); }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }







template<typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i < v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i < sz; i++) cout << a[i] << " "; cout << endl; }








inline ll binpow(ll x, ll n){ ll res = 1; while (n){ if (n & 1)res *= x; x *= x; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(int a, int b){ return a / gcd(a, b)*(ll)b; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
inline ll lcm(ll a, ll b, ll c){ return lcm(lcm(a, b), c); }
inline ll lcm(int a, int b, int c){ return lcm(lcm(a, b), (ll)c); }

inline ll max(ll a, ll b){ return (a > b) ? a : b; }
inline int max(int a, int b){ return (a > b) ? a : b; }
inline double max(double a, double b){ return (a > b) ? a : b; }
inline ll max(ll a, ll b, ll c){ return max(a, max(b, c)); }
inline int max(int a, int b, int c){ return max(a, max(b, c)); }
inline double max(double a, double b, double c){ return max(a, max(b, c)); }
inline ll min(ll a, ll b){ return (a < b) ? a : b; }
inline int min(int a, int b){ return (a < b) ? a : b; }
inline double min(double a, double b){ return (a < b) ? a : b; }
inline ll min(ll a, ll b, ll c){ return min(a, min(b, c)); }
inline int min(int a, int b, int c){ return min(a, min(b, c)); }
inline double min(double a, double b, double c){ return min(a, min(b, c)); }

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }
template<class T>
inline void cinarr(T a, int n){ for (int i = 0; i < n; ++i) cin >> a[i]; }










char s[2020][2020];
bool up[2020][2020];
bool down[2020][2020];
bool lef[2020][2020];
bool rig[2020][2020];
int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	FI(n){
		cin >> s[i];
		FJ(m){
			if (s[i][j] == '.')
				s[i][j] = 0;
		}
	}
	FI(n){
		if (!s[i][0]){
			FJ(m) if (s[i][j]) break; else
				lef[i][j] = true;
		}
		if (!s[i][m - 1]){
			for (int j = m - 1; j >= 0; --j){
				if (s[i][j]) break; else
					rig[i][j] = true;
			}
		}
	}
	FJ(m){
		if (!s[0][j]){
			FI(n) if (s[i][j]) break;
			else
				up[i][j] = true;
		}
		if (!s[n - 1][j]){
			for (int i = n - 1; i >= 0; --i){
				if (s[i][j]) break;
				else down[i][j] = true;
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i < n - 1; ++i){
		for (int j = 1; j < m - 1; ++j){
			int x = lef[i][j] + rig[i][j];
			int y = up[i][j] + down[i][j];
			ans += x * y;
		}
	}

	for (int i = 1; i < n - 1; ++i){
		if (rig[i][0]){
			++ans;
		}
	}
	for (int i = 1; i < m - 1; ++i){
		if (down[0][i]){
			++ans;
		}
	}
	for (int i = 1; i < n - 1; ++i){
		for (int j = 1; j < m - 1; ++j){
			if (!s[i][j] && (s[i][j - 1] || j == 1)){
				int u = 0;
				int d = 0;
				int pu = 0;
				int pd = 0;
				for (int t = j; t < m - 1 && !s[i][t]; ++t){
					j = t + 1;
					if (up[i][t]) ans += d + pu;
					if (down[i][t]) ans += u + pd;
					pu = u;
					pd = d;
					u += up[i][t];
					d += down[i][t];
				}

			}
		}
	}

	for (int j = 1; j < m - 1; ++j){
		for (int i = 1; i < n - 1; ++i){
			if (!s[i][j] && (s[i - 1][j] || i == 1)){
				int u = 0;
				int d = 0;
				int pu = 0;
				int pd = 0;
				for (int t = i; t < n - 1 && !s[t][j]; ++t){
					i = t + 1;
					if (lef[t][j]) ans += d + pu;
					if (rig[t][j]) ans += u + pd;
					

					pu = u;
					pd = d;
					u += lef[t][j];
					d += rig[t][j];
				}

			}
		}
	}
	cout << ans << endl;
	return 0;
}
