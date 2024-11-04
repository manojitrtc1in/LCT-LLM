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

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using pld = pair<ld, ld>;

using vi = vector<int>;
using vd = vector<db>;
using vld = vector<ld>;
using vl = vector<ll>;
using vs = vector<str>;
using vc = vector<char>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvc = vector<vc>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define si(s) ((int)(s).size())
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rs resize
#define ins insert
#define nl "\n"
#define trav(i, x) for(auto& i: x)
#define lower(s) transform(all(s), s.begin(), ::tolower);
#define upper(s) transform(all(s), s.begin(), ::toupper);
#define gcd(a, b) ggcd(a, b)
#define lcm(a, b) llcm(a, b)

const int MX = 2e5 + 5;
const long long INF = 1e18;
const long long MOD = 998244353;
const long double PI = acos((long double)-1);
const long double EPS = 1e-18;

 
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A, B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A, SZ>& a);
 
template<class T> void re(T& x) { __FIO__.READ_VAR(x); }
void re(db& d) { string t; re(t); d = stod(t); }
void re(ld& d) { string t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a, b; re(a, b); c = {a, b}; }
template<class A, class B> void re(pair<A, B>& p) { re(p.f, p.s); }
template<class A> void re(vector<A>& x) { trav(i, x) re(i); }
template<class A, size_t SZ> void re(array<A, SZ>& x) { trav(i, x) re(i); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll a, ll b) { uniform_int_distribution<ll> u(a, b); return u(rng); }

 
#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<class A>
string ts(complex<A> c) { 
	stringstream ss;
	ss << c;
	return ss.str();
}
string ts(vector<bool> v) { 
	string res = "{";
	for(int i = 0; i < si(v); i++) {
		res += char('0' + v[i]);
	}
	res += "}";
	return res;
}
template<size_t SZ>
string ts(bitset<SZ> b) {
	string res = "";
	for(int i = 0; i < SZ; i++) {
		res += char('0' + b[i]);
	}
	return res;
}
template<class A, class B>
string ts(pair<A, B> p) {
	return "(" + ts(p.f) + ", " + ts(p.s) + ")";
}
template<class T>
string ts(T v) {  
	bool fst = 1;
	string res = "{";
	for(const auto& x: v) {
		if(!fst) {
			res += ", ";
		}
		fst = 0;
		res += ts(x);
	}
	res += "}";
	return res;
}
 
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T>
void DBG(H h, T... t) {
	cerr << ts(h);
	if(sizeof...(t)) {
		cerr << ", ";
	}
	DBG(t...);
}
void EDBG(string names) { names = names; }
template<class H, class... T>
void EDBG(string names, H h, T... t) {
	auto pos = names.find(',');
	auto first_name = names.substr(0, pos);
	auto rest = names.substr(pos + 1);
	while(rest.front() == ' ') {
		rest = rest.substr(1);
	}
	cerr << "[" << first_name << "]: [" << ts(h) << "]" << nl;
	EDBG(rest, t...);
}

 
#ifdef LOCAL  
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#define edbg(...) 0
#endif

 
void pr() {}
template <typename H, typename... T> 
void pr(const H& var1, const T&... var2) {
    __FIO__.WRITE_VAR(var1);
    pr(var2...); 
}

void ps() { __FIO__.WRITE_VAR(nl); }
template<typename H, typename... T>
void ps(const H& var1, const T&... var2) {
	pr(var1, ' ');
	ps(var2...);
}

 
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { 0; 0; 0, 0; }
void setIO(string s = "") { unsyncIO(); if(si(s)) { setIn(s + ".in"); setOut(s + ".out"); } }

template<class T> void uni(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)), end(v)); }
ll cdiv(ll a, ll b) { return a / b + !(a < 0 || a % b == 0); }  
ll ggcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }
ll gld(ll a, ll b) { return (a - (a % b)); }  
ll llcm(ll a, ll b) { return (a / (gcd(a, b)) * b); }
ll power(ll a, ll b, ll c) { ll res = 1; a %= c; while(b > 0) { if(b & 1) res = res * a % c; a = a * a % c; b >>= 1; } return res; }
ll power(ll a, ll b) { ll res = 1; while(b > 0) { if(b % 2) res = res * a; a = a * a; b >>= 1; } return res; }
bool prime(ll a) { if(a < 2) { return false; } if(a <= 3) { return true; } if(a % 2 == 0 || a % 3 == 0 || (a % 5 == 0 && a != 5) || (a % 7 == 0 && a != 7) || (a % 11 == 0 && a != 11) || (a % 13 == 0 && a != 13) || (a % 17 == 0 && a != 17) || (a % 23 == 0 && a != 23) || (a % 29 == 0 && a != 29) || (a % 31 == 0 && a != 31) || (a % 37 == 0 && a != 37) || (a % 41 == 0 && a != 41) || (a % 43 == 0 && a != 43) || (a % 47 == 0 && a != 47) || (a % 53 == 0 && a != 53) || (a % 59 == 0 && a != 59) || (a % 61 == 0 && a != 61) || (a % 67 == 0 && a != 67) || (a % 67 == 0 && a != 67)) { return false; } if((a % 71 == 0 && a != 71) || (a % 73 == 0 && a != 73) || (a % 79 == 0 && a != 79) || (a % 83 == 0 && a != 83) || (a % 89 == 0 && a != 89) || (a % 97 == 0 && a != 97)) { return false; } if((a % 101 == 0 && a != 101) || (a % 103 == 0 && a != 103) || (a % 107 == 0 && a != 107) || (a % 109 == 0 && a != 109) || (a % 113 == 0 && a != 113) || (a % 127 == 0 && a != 127) || (a % 131 == 0 && a != 131) || (a % 139 == 0 && a != 139) || (a % 149 == 0 && a != 149) || (a % 151 == 0 && a != 151) || (a % 157 == 0 && a != 157) || (a % 163 == 0 && a != 163) || (a % 167 == 0 && a != 167) || (a % 173 == 0 && a != 173) || (a % 179 == 0 && a != 179) || (a % 181 == 0 && a != 181) || (a % 191 == 0 && a != 191)) { return false; } if((a % 193 == 0 && a != 193) || (a % 197 == 0 && a != 197) || (a % 199 == 0 && a != 199)) { return false; } for(ll i = 5; i * i <= a; i += 6) { if(a % i == 0 || a % (i + 2) == 0) { return false; } } return true; }
 

int n;
vi a;
string s;
int hlda, hldb;
vpi hld, b, c;

int main() {
	setIO();

	re(n);
	a.rs(n);
	re(a);
	re(s);
	for(int i = 0; i < si(a); i++) {
		hld.pb({a[i], i + 1});
	}
	sort(all(hld));
	for(int i = 0; i < si(s); i++) {
		if(s[i] == '0') {
			b.pb(hld[hlda]);
			pr(hld[hlda].s, ' ');
			hlda++;
		} else {
			c.pb({b.back()});
			pr(b.back().s, ' ');
			b.pop_back();
			hldb++;
		}
		 
	}
}


#undef si
#undef all
#undef rall
#undef trav
#undef lower
#undef upper
#undef gcd
#undef lcm
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
#undef trav
#undef lower
#undef upper
#undef gcd
#undef lcm
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


