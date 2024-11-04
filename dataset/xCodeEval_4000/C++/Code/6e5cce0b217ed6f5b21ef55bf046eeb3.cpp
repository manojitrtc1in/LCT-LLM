#include <bits/stdc++.h>

static struct FASTIO {

  char READ_CHARACTER; bool REMAINING_CHARACTER = false;

  inline void ignore(); inline void flush();

  template <typename T> inline bool READ_INT(T &x); template <typename T> inline bool READ_STRING(T &x);
  
  template<size_t N> inline bool READ_CHAR_ARRAY(char (&x)[N]); template<size_t N> inline bool READ_VAR(char (&x)[N]);
  
  template <typename T> inline bool READ_CHAR(T &x); inline bool READ_CHAR_ARRAY(char*& x); inline bool READ_GETLINE(std::string &x);
  
  template <typename T> inline bool READ_FLOAT(T &x); template <typename T> inline bool READ_DOUBLE(T &x);
  
  template<std::size_t N> inline bool READ_BITSET(std::bitset<N> &bit); template<std::size_t N> inline bool READ_VAR(std::bitset<N> &bit);
  inline bool READ_VAR(bool &x); inline bool READ_VAR(short int &x); inline bool READ_VAR(int &x); 
  inline bool READ_VAR(long int &x); inline bool READ_VAR(long long int &x); inline bool READ_VAR(unsigned short int &x);
  inline bool READ_VAR(unsigned int &x); inline bool READ_VAR(unsigned long &x); inline bool READ_VAR(unsigned long long &x);
  inline bool READ_VAR(std::string &x); inline bool READ_VAR(char &x); inline bool READ_VAR(char*& x); inline bool READ_VAR(float &x);
  inline bool READ_VAR(double &x); inline bool READ_VAR(long double &x); template <typename T> inline void WRITE_INT(T x);
  inline void WRITE_STRING(std::string &x); inline void WRITE_CHAR(char x); inline void WRITE_CHAR_ARRAY(const char *x);
  inline void WRITE_FLOAT(float x); template <typename T> inline void WRITE_DOUBLE(T x); inline void WRITE_VAR(bool x);
  inline void WRITE_VAR(short int x); inline void WRITE_VAR(int x); inline void WRITE_VAR(long int x); inline void WRITE_VAR(long long int x);
  inline void WRITE_VAR(unsigned short int x); inline void WRITE_VAR(unsigned int x); inline void WRITE_VAR(unsigned long x);
  inline void WRITE_VAR(unsigned long long x); inline void WRITE_VAR(char x); inline void WRITE_VAR(const char *x); 
  inline void WRITE_VAR(std::string &x); inline void WRITE_VAR(float x); inline void WRITE_VAR(double x); inline void WRITE_VAR(long double x);
  template<std::size_t N> inline void WRITE_VAR(std::bitset<N> &bit); template<std::size_t N> inline void WRITE_BITSET(std::bitset<N> &bit);

} __FIO__;


#include "bits/stdc++.h"  
using namespace std;  
 
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using ull = unsigned ll;
 
using pi = pair<ll, ll>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using pld = pair<ld, ld>;
 
using vi = vector<ll>;
using vd = vector<db>;
using vl = vector<ll>;
using vld = vector<ld>;
using vs = vector<str>;
using vb = vector<bool>;
using vc = vector<char>;
using vpi = vector<pl>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vl>;
using vvl = vector<vl>;
using vvc = vector<vc>;
 
#define pb push_back
#define eb emplace_back
#define mp(a, b) make_pair(a, b)
#define f first
#define s second
#define si(a) ((int)(a).size())
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define rs resize
#define ins insert
#define nl "\n"
#define sor(a) sort(all(a))
#define res(a, n) a.rs(n); re(a)
#define int long long
#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; } )
 
#define rep(i, a, b) for(auto i = (a); i < (b); ++i)
#define rop(i, a) rep(i, 0, a)
#define per(i, a, b) for(auto i = (b) - 1; i >= (a); --i)
#define por(i, a) per(i, 0, a)
#define trav(i, a) for(auto& i: a)
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void uni(vector<T>& v) { sor(v); v.erase(unique(all(v)), end(v)); }
int cdiv(const ll& a, const ll& b) { return a / b + ((a ^ b) > 0 && a % b); }  
int fdiv(const ll& a, const ll& b) { return a / b - ((a ^ b) < 0 && a % b); }  
int fstTrue(function<bool(int)> f, int lo, int hi) { for(hi++; lo < hi;) { int mid = fdiv((lo + hi), 2); f(mid) ? hi = mid : lo = mid + 1; } return lo; }
int lstTrue(function<bool(int)> f, int lo, int hi) { for(lo--; lo < hi;) { int mid = fdiv((lo + hi + 1), 2); f(mid) ? lo = mid : hi = mid - 1; } return lo; }
int power(ll a, ll b, ll c) { ll res = 1; a %= c; while(b > 0) { if(b & 1) res = res * a % c; a = a * a % c; b >>= 1; } return res; }
int power(ll a, ll b) { ll res = 1; while(b > 0) { if(b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
ull modmul(ull a, ull b, const ull mod) { ll ret = a * b - mod * (ull)((ld)a * b / mod); return ret + ((ret < 0) - (ret >= (ll)mod)) * mod; }
ull modpow(ull a, ull b, const ull mod) { if(b == 0) { return 1; } ull res = modpow(a, b / 2, mod); res = modmul(res, res, mod); return b & 1 ? modmul(res, a, mod) : res; }
bool prime(ull n) { if(n < 2 || n % 6 % 4 != 1) { return n - 2 < 2; } ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022}, s = __builtin_ctzll(n - 1), d = n >> s; trav(i, A) { ull p = modpow(i, d, n), a = s; while(p != 1 && p != n - 1 && i % n && a--) { p = modmul(p, p, n); } if(p != n - 1 && a != s) { return false; } } return true; }
int pct(int x) { x = (x & 0x5555555555555555LL) + ((x >> 1) & 0x5555555555555555LL); x = (x & 0x3333333333333333LL) + ((x >> 2) & 0x3333333333333333LL); x = (x & 0x0F0F0F0F0F0F0F0FLL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FLL); return (x * 0x0101010101010101LL) >> 56; }
 
 
 
#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A> string ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
string ts(vector<bool> v) { string res = "{"; for(int i = 0; i < si(v); i++) { res += char('0' + v[i]); } res += "}"; return res; }
template<size_t SZ> string ts(bitset<SZ> b) { string res = ""; for(int i = 0; i < (ll)SZ; i++) { res += char('0' + b[i]); } return res; }
template<class A, class B> string ts(pair<A, B> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
template<class T> string ts(T v) { bool fst = 1; string res = "{"; for(const auto& x: v) { if(!fst) { res += ", "; } fst = 0; res += ts(x); } res += "}"; return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) { cerr << ts(h); if(sizeof...(t)) { cerr << ", "; } DBG(t...); }
void EDBG(string names) { names = names; }
template<class H, class... T> void EDBG(string names, H h, T... t) { auto pos = names.find(','); auto first_name = names.substr(0, pos); auto rest = names.substr(pos + 1); while(rest.front() == ' ') { rest = rest.substr(1); } cerr << "[" << first_name << "]: [" << ts(h) << "]" << nl; EDBG(rest, t...); }
 
#ifdef LOCAL  
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#define edbg(...) 7
#endif
 
 
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { 0; 0; 0, 0; }
void setIO(string s = "") { unsyncIO(); if(si(s)) { setIn(s + ".in"); setOut(s + ".out"); } }
 
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;  
const long double PI = acos((ld)-1);
const long double EPS = 1e-18;
 
struct custom_hash {  
	static uint64_t splitmix64(uint64_t x) {
		 
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(a + FIXED_RANDOM);
	}
	template<class T> size_t operator()(T a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		hash<T> x;
		return splitmix64(x(a) + FIXED_RANDOM);
	}
	template<class T, class H> size_t operator()(pair<T, H> a) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		hash<T> x;
		hash<H> y;
		return splitmix64(x(a.f) * 37 + y(a.s) + FIXED_RANDOM);
	}
};
template<class T, class H> using umap = unordered_map<T, H, custom_hash>;
template<class T> using uset = unordered_set<T, custom_hash>;
 
int n;
vi a, hld1;
vpi hld;
umap<int, vi> cnt;
umap<int, int> cnt1;
 
bool check(vi& x, int y) {
	assert(is_sorted(all(x)));
	for(int i = 1; i < si(x); ++i) {
		if((x[i] - x[i - 1]) > y) {
			return false;
		}
	}
	return true;
}
 
void solve() {
	__FIO__.READ_VAR(n);
	a.rs(n);
	trav(i, a) {
		__FIO__.READ_VAR(i);
	}
	cnt.clear();
	hld.clear();
	cnt1.clear();
	hld1.clear();
	for(int i = 0; i < si(a); ++i) {
		if(cnt[a[i]].empty()) {
			cnt[a[i]].eb(-1);
		}
		cnt[a[i]].eb(i);
	}
	trav(i, cnt) {
		cnt[i.f].eb(n);
	}
	trav(i, cnt) {
		int l = 0, r = n;
		while(l < r) {
			int mid = (l + r) / 2;
			if(check(i.s, mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		cnt1[i.f] = l;
	}
	trav(i, cnt1) {
		hld.eb(i.s, i.f);
	}
	sor(hld);
	trav(i, hld) {
		swap(i.f, i.s);
	}
	 
	for(int i = 0; i < si(hld); ++i) {
		hld1.eb(hld[i].f);
	}
	for(int i = 1; i < si(hld1); ++i) {
		ckmin(hld1[i], hld1[i - 1]);
	}
	for(int i = 1; i <= n; ++i) {
		int l = 0, r = si(hld);
		while(l < r) {
			int mid = (l + r) / 2;
			if(hld[mid].s <= i) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		l--, r--;
		if(l == -1 && l == r) {
			__FIO__.WRITE_VAR(l), __FIO__.WRITE_VAR(' ');
			continue;
		}
		__FIO__.WRITE_VAR(hld1[l]), __FIO__.WRITE_VAR(' ');
	}
	__FIO__.WRITE_VAR(nl);
}
 
int32_t main() {
	setIO();
 
	int T;
	__FIO__.READ_VAR(T);
	while(T--) {
		solve();
	}
}

#undef mp
#undef si
#undef all
#undef rall
#undef sor
#undef res
#undef sort_by
#undef rep
#undef rop
#undef per
#undef por
#undef trav
#undef dbg
#undef edbg
#undef dbg
#undef edbg
#undef pb
#undef eb
#undef mp
#undef f
#undef s
#undef si
#undef all
#undef rall
#undef rs
#undef ins
#undef nl
#undef sor
#undef res
#undef int
#undef sort_by
#undef rep
#undef rop
#undef per
#undef por
#undef trav
#undef ts
#undef dbg
#undef edbg
#undef dbg
#undef edbg

inline void FASTIO::ignore() {
  if(REMAINING_CHARACTER == true) REMAINING_CHARACTER = false; else READ_CHARACTER = getchar();
}

inline void FASTIO::flush() {
  fflush(stdout);
}




template <typename T>
inline bool FASTIO::READ_INT(T &x) {
  x = 0; T sig = 1;
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while (!isdigit(READ_CHARACTER) && READ_CHARACTER != EOF) sig = (READ_CHARACTER == '-' ? -sig : sig), READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while (isdigit(READ_CHARACTER)) x = x * 10 + READ_CHARACTER - '0', READ_CHARACTER = getchar();
  x *= sig; REMAINING_CHARACTER = true;
  return true;
}

template <typename T>
inline bool FASTIO::READ_STRING(T &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_GETLINE(std::string &x) {
  x = "";
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != EOF)) x += READ_CHARACTER, READ_CHARACTER = getchar();
  REMAINING_CHARACTER = false;
  return true;
}

template <typename T>
inline bool FASTIO::READ_CHAR(T &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  x = READ_CHARACTER; REMAINING_CHARACTER = false;
  return true;
}


template<size_t N>
inline bool FASTIO::READ_CHAR_ARRAY(char (&x)[N]) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  char *ptr = &x[0];
  while ((READ_CHARACTER != '\n' && READ_CHARACTER != '\t' && READ_CHARACTER != ' ' && READ_CHARACTER != EOF)) *ptr++ = READ_CHARACTER, READ_CHARACTER = getchar();
  *ptr = '\0', REMAINING_CHARACTER = true;
  return true;
}

inline bool FASTIO::READ_CHAR_ARRAY(char*& x) {
  std::string y;
  if(READ_STRING(y) == false)
    return false;
  x = new char[(int)y.size() + 1];
  strcpy(x, y.c_str());
  return true;
}

template <typename T>
inline bool FASTIO::READ_FLOAT(T &x) {
  return (scanf("%f", &x) != EOF);
}

template <typename T>
inline bool FASTIO::READ_DOUBLE(T &x) {
  double y;
  if(scanf("%lf", &y) == EOF) return false;
  x = y;
  return true;
}

template<std::size_t N>
inline bool FASTIO::READ_BITSET(std::bitset<N> &x) {
  if(!REMAINING_CHARACTER) READ_CHARACTER = getchar(), REMAINING_CHARACTER = true; else REMAINING_CHARACTER = false;
  while ((READ_CHARACTER == '\n' || READ_CHARACTER == '\t' || READ_CHARACTER == ' ')) READ_CHARACTER = getchar();
  if(READ_CHARACTER == EOF) return REMAINING_CHARACTER = false, false;
  int i = 0; REMAINING_CHARACTER = true;
  while (READ_CHARACTER == '0' || READ_CHARACTER == '1') x[i++] = READ_CHARACTER - '0', READ_CHARACTER = getchar();
  return true;
}

inline bool FASTIO::READ_VAR(short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(long long int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned short int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned int &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(unsigned long long &x) {
  return READ_INT(x);    
}

inline bool FASTIO::READ_VAR(std::string &x) {
  return READ_STRING(x);    
}

inline bool FASTIO::READ_VAR(char &x) {
  return READ_CHAR(x);
}

template<size_t N>
inline bool FASTIO::READ_VAR(char (&x)[N]) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(char*& x) {
  return READ_CHAR_ARRAY(x);
}

inline bool FASTIO::READ_VAR(float &x) {
  return READ_FLOAT(x);
}

inline bool FASTIO::READ_VAR(double &x) {
  return READ_DOUBLE(x);
}

inline bool FASTIO::READ_VAR(long double &x) {
  return READ_DOUBLE(x);
}

template<std::size_t N>
inline bool FASTIO::READ_VAR(std::bitset<N> &x) {
  return READ_BITSET(x);
}




template <typename T>
inline void FASTIO::WRITE_INT(T x) {
  if (x < 0) {putchar('-'); x = -x; }
  char writeBuffer[20], *writePtr = writeBuffer;
  do {
    *writePtr++ = '0' + x % 10;
    x /= 10;
  }
  while (x);
  do  { putchar(*--writePtr); }
  while (writePtr > writeBuffer);
}

inline void FASTIO::WRITE_CHAR(char x) {
  putchar(x);
}

inline void FASTIO::WRITE_CHAR_ARRAY(const char *x) {
  while(*x != '\0')
    putchar(*x++);
}

inline void FASTIO::WRITE_STRING(std::string &x) {
  for(char c: x) 
    putchar(c);
}

inline void FASTIO::WRITE_FLOAT(float x) {
  printf("%.20f", x);
}

template <typename T>
inline void FASTIO::WRITE_DOUBLE(T x) {
  printf("%.20lf", (double)x);
}

template<std::size_t N>
inline void FASTIO::WRITE_BITSET(std::bitset<N> &x) {
  for(int i = (int)x.size() - 1; i >= 0; i--)
    putchar(x[i] + 48);
}

inline void FASTIO::WRITE_VAR(bool x) {
  WRITE_INT(x);
}

inline void FASTIO::WRITE_VAR(short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(long long int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned short int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned int x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(unsigned long long x) {
  WRITE_INT(x);    
}

inline void FASTIO::WRITE_VAR(std::string &x) {
  WRITE_STRING(x);    
}

inline void FASTIO::WRITE_VAR(char x) {
  WRITE_CHAR(x);
}

inline void FASTIO::WRITE_VAR(const char *x) {
  WRITE_CHAR_ARRAY(x);
}

inline void FASTIO::WRITE_VAR(float x) {
  WRITE_FLOAT(x);
}

inline void FASTIO::WRITE_VAR(double x) {
  WRITE_DOUBLE(x);
}

inline void FASTIO::WRITE_VAR(long double x) {
  WRITE_DOUBLE(x);
}

template<std::size_t N>
inline void FASTIO::WRITE_VAR(std::bitset<N> &x) {
  WRITE_BITSET(x);
}  


