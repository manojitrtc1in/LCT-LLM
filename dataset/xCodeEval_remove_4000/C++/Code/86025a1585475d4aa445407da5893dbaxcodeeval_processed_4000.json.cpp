

































































using namespace std;
































































typedef double                db;
typedef long double           ldb;
typedef unsigned char         uchar;
typedef unsigned short        ushort;
typedef unsigned int          uint;
typedef long long             ll;
typedef unsigned long long    ull;
typedef vector<bool>          VB;
typedef vector<VB>            VVB;
typedef vector<char>          VC;
typedef vector<VC>            VVC;
typedef vector<int>           VI;
typedef vector<VI>            VVI;
typedef vector<ll>            VLL;
typedef vector<VLL>           VVLL;
typedef vector<double>        VD;
typedef vector<VD>            VVD;
typedef vector<string>        VS;
typedef vector<VS>            VVS;
typedef pair<int, int>        PII;
typedef pair<ll, ll>          PLL;
typedef vector<PII>           VPII;
typedef vector<PLL>           VPLL;
typedef pair<int, PII>        PIPII;
typedef pair<ll, PLL>         PLPLL;
typedef pair<PII, int>        PPIII;
typedef pair<PLL, ll>         PPLLL;
typedef map<int, int>         MII;
typedef map<ll, ll>           MLL;
typedef map<db, db>           MDD;
typedef map<string, int>      MSI;
typedef map<int, string>      MIS;
typedef set<int>              SI;
typedef set<ll>               SLL;
typedef queue<int>            QI;
typedef queue<ll>             QLL;
typedef queue<PII>            QPII;
typedef deque<int>            DI;
typedef deque<ll>             DLL;
typedef deque<PII>            DPII;
const double                  eps = 1e-9;
const double                  pi = 3.14159265358979323846264338327950288419716939937510;
const int                     inf = 0x3f3f3f3f;
const int                     mod = 1000000007;
const int                     mod2 = 1000000006;
const long long               infll = 0x3f3f3f3f3f3f3f3fLL;
const int                     dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
const int                     dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };





template<typename T> inline bool RD(T& v) { char c; bool n; while (c = getchar(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = getchar(), c >= '0' && c <= '9') v = (v << 3) + (v << 1) + c - '0'; if (n) v *= -1; return true; }

template<typename A, typename ...Args> inline bool RD(A& a, Args&... rest) { return RD(a) && RD(rest...); }

template<typename T> inline bool RD(T& a, T& b) { return RD(a) && RD(b); }
template<typename T> inline bool RD(T& a, T& b, T& c) { return RD(a, b) && RD(c); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d) { return RD(a, b, c) && RD(d); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e) { return RD(a, b, c, d) && RD(e); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f) { return RD(a, b, c, d, e) && RD(f); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g) { return RD(a, b, c, d, e, f) && RD(g); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h) { return RD(a, b, c, d, e, f, g) && RD(h); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i) { return RD(a, b, c, d, e, f, g, h) && RD(i); }
template<typename T> inline bool RD(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i, T& j) { return RD(a, b, c, d, e, f, g, h, i) && RD(j); }

inline int RD() { int v; RD(v); return v; }


static char _BUF_[1 << 15], *_HEAD_ = _BUF_, *_TAIL_ = _BUF_;
inline static char id0() { return _HEAD_ == _TAIL_ && (_TAIL_ = (_HEAD_ = _BUF_) + fread(_BUF_, 1, 1 << 15, stdin), _HEAD_ == _TAIL_) ? EOF : *_HEAD_++; }
template<typename T> inline bool RDB(T& v) { char c; bool n; while (c = id0(), c != '-' && (c < '0' || c > '9')) if (c == EOF) return false; if (c == '-') { n = true; v = 0; } else { n = false; v = c - '0'; } while (c = id0() - '0', c >= 0 && c <= 9) v = (v << 3) + (v << 1) + c; if (n) v *= -1; return true; }

template<typename A, typename ...Args> inline bool RDB(A& a, Args&... rest) { return RDB(a) && RDB(rest...); }

template<typename T> inline bool RDB(T& a, T& b) { return RDB(a) && RDB(b); }
template<typename T> inline bool RDB(T& a, T& b, T& c) { return RDB(a, b) && RDB(c); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d) { return RDB(a, b, c) && RDB(d); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e) { return RDB(a, b, c, d) && RDB(e); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f) { return RDB(a, b, c, d, e) && RDB(f); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g) { return RDB(a, b, c, d, e, f) && RDB(g); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h) { return RDB(a, b, c, d, e, f, g) && RDB(h); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i) { return RDB(a, b, c, d, e, f, g, h) && RDB(i); }
template<typename T> inline bool RDB(T& a, T& b, T& c, T& d, T& e, T& f, T& g, T& h, T& i, T& j) { return RDB(a, b, c, d, e, f, g, h, i) && RDB(j); }

inline int RDB() { int v; RDB(v); return v; }


template<typename T> inline void _WR(T a) { if (a < 0) { putchar('-'); a *= -1; } T t = a / 10; if (t) _WR(t); putchar(a - (t << 1) - (t << 3) + '0'); }
template<typename T> inline void WR_(const T&a) { _WR(a); putchar(' '); }
template<typename T> inline void WR(const T&a) { _WR(a); putchar('\n'); }

template<typename A, typename ...Args> inline void _WR(const A& a, const Args&... rest) { WR_(a); _WR(rest...); }
template<typename A, typename ...Args> inline void WR_(const A& a, const Args&... rest) { WR_(a); WR_(rest...); }
template<typename A, typename ...Args> inline void WR(const A& a, const Args&... rest) { WR_(a); WR(rest...); }

template<typename T> inline void _WR(const T& a, const T& b) { WR_(a); _WR(b); }
template<typename T> inline void WR_(const T& a, const T& b) { WR_(a); WR_(b); }
template<typename T> inline void WR(const T& a, const T& b) { WR_(a); WR(b); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c) { WR_(a, b); _WR(c); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c) { WR_(a, b); WR_(c); }
template<typename T> inline void WR(const T& a, const T& b, const T& c) { WR_(a, b); WR(c); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); _WR(d); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); WR_(d); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d) { WR_(a, b, c); WR(d); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); _WR(e); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); WR_(e); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e) { WR_(a, b, c, d); WR(e); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); _WR(f); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); WR_(f); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { WR_(a, b, c, d, e); WR(f); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); _WR(g); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); WR_(g); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { WR_(a, b, c, d, e, f); WR(g); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); _WR(h); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); WR_(h); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { WR_(a, b, c, d, e, f, g); WR(h); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); _WR(i); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); WR_(i); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { WR_(a, b, c, d, e, f, g, h); WR(i); }
template<typename T> inline void _WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); _WR(j); }
template<typename T> inline void WR_(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); WR_(j); }
template<typename T> inline void WR(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { WR_(a, b, c, d, e, f, g, h, i); WR(j); }











template <typename A> inline istream &IN(A& a) { return std::cin >> a; }

template <typename A, typename ...Args> inline istream &IN(A& a, Args&... rest) { std::cin >> a; return IN(rest...); }

template <typename A, typename B> inline istream &IN(A& a, B& b) { return std::cin >> a >> b; }
template <typename A, typename B, typename C> inline istream &IN(A& a, B& b, C& c) { return std::cin >> a >> b >> c; }
template <typename A, typename B, typename C, typename D> inline istream &IN(A& a, B& b, C& c, D& d) { return std::cin >> a >> b >> c >> d; }
template <typename A, typename B, typename C, typename D, typename E> inline istream &IN(A& a, B& b, C& c, D& d, E& e) { return std::cin >> a >> b >> c >> d >> e; }
template <typename A, typename B, typename C, typename D, typename E, typename F> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f) { return std::cin >> a >> b >> c >> d >> e >> f; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g) { return std::cin >> a >> b >> c >> d >> e >> f >> g; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h, I& i) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i; }
template <typename A, typename B, typename C, typename D, typename E, typename F, typename G, typename H, typename I, typename J> inline istream &IN(A& a, B& b, C& c, D& d, E& e, F& f, G& g, H& h, I& i, J& j) { return std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j; }

inline std::ostream& OUT() { return std::cout << std::endl; }

template <typename A> inline ostream& _OUT(const A &a) { return std::cout << a; }
template <typename A, typename...Args> inline ostream& _OUT(const A &a, const Args&... rest) { std::cout << a << " "; return _OUT(rest...); }
template <typename...Args> inline ostream& OUT_(const Args&... args) { _OUT(args...); return std::cout << " "; }
template <typename...Args> inline ostream& OUT(const Args&... args) { _OUT(args...); return std::cout << std::endl; }

template<typename T> inline ostream& _OUT(const T&a) { return std::cout << a; }
template<typename T> inline ostream& OUT_(const T&a) { return std::cout << a << ' '; }
template<typename T> inline ostream& OUT(const T&a) { return std::cout << a << std::endl; }
template<typename T, typename U> inline ostream& _OUT(const T&a, const U&b) { return std::cout << a << " " << b; }
template<typename T, typename U> inline ostream& OUT_(const T&a, const U&b) { return std::cout << a << " " << b << " "; }
template<typename T, typename U> inline ostream& OUT(const T&a, const U&b) { return std::cout << a << " " << b << std::endl; }
template<typename T, typename U, typename V> inline ostream& _OUT(const T&a, const U&b, const V&c) { OUT_(a, b); return _OUT(c); }
template<typename T, typename U, typename V> inline ostream& OUT_(const T&a, const U&b, const V&c) { OUT_(a, b); return OUT_(c); }
template<typename T, typename U, typename V> inline ostream& OUT(const T&a, const U&b, const V&c) { OUT_(a, b); return OUT(c); }
template<typename T, typename U, typename V, typename W> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return _OUT(d); }
template<typename T, typename U, typename V, typename W> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return OUT_(d); }
template<typename T, typename U, typename V, typename W> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d) { OUT_(a, b, c); return OUT(d); }
template<typename T, typename U, typename V, typename W, typename X> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return _OUT(e); }
template<typename T, typename U, typename V, typename W, typename X> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return OUT_(e); }
template<typename T, typename U, typename V, typename W, typename X> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e) { OUT_(a, b, c, d); return OUT(e); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return _OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return OUT_(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f) { OUT_(a, b, c, d, e); return OUT(f); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return _OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return OUT_(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g) { OUT_(a, b, c, d, e, f); return OUT(g); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return _OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return OUT_(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h) { OUT_(a, b, c, d, e, f, g); return OUT(h); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return _OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return OUT_(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i) { OUT_(a, b, c, d, e, f, g, h); return OUT(i); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline ostream& _OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return _OUT(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline ostream& OUT_(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return OUT_(j); }
template<typename T, typename U, typename V, typename W, typename X, typename Y, typename Z, typename A, typename B, typename C> inline ostream& OUT(const T&a, const U&b, const V&c, const W&d, const X&e, const Y&f, const Z&g, const A&h, const B&i, const C&j) { OUT_(a, b, c, d, e, f, g, h, i); return OUT(j); }








template<typename A> inline void clr(A& a) { a.clear(); }

template<typename A, typename...Args> inline void clr(A& a, Args&... args) { a.clear(); clr(args...); }

template<typename A, typename B> inline void clr(A &a, B &b) { a.clear(); b.clear(); }
template<typename A, typename B, typename C> inline void clr(A &a, B &b, C &c) { a.clear(); b.clear(); c.clear(); }
template<typename A, typename B, typename C, typename D> inline void clr(A &a, B &b, C &c, D &d) { a.clear(); b.clear(); c.clear(); d.clear(); }
template<typename A, typename B, typename C, typename D, typename E> inline void clr(A &a, B &b, C &c, D &d, E &e) { a.clear(); b.clear(); c.clear(); d.clear(); e.clear(); }
template<typename A, typename B, typename C, typename D, typename E, typename F> inline void clr(A &a, B &b, C &c, D &d, E &e, F &f) { a.clear(); b.clear(); c.clear(); d.clear(); e.clear(); f.clear(); }




inline long long madd(long long a, long long b, const long long mod = 1000000007) { long long ret = (a + b) % mod; if (ret < 0) ret += mod; return ret; }
inline long long msub(long long a, long long b, const long long mod = 1000000007) { long long ret = (a - b) % mod; if (ret < 0) ret += mod; return ret; }
inline long long mmul(long long a, long long b, const long long mod = 1000000007) { return a * b % mod; }
inline long long mpow(long long x, long long k, const long long mod = 1000000007) { x %= mod; long long ret = 1; while (k > 0) { if (k & 1) ret = ret * x % mod; x = x * x % mod; k >>= 1; } return ret; }


template<typename T, typename U> inline bool cmax(T& a, const U& b) { return a < b ? a = b, true : false; }
template<typename T, typename U> inline bool cmin(T& a, const U& b) { return a > b ? a = b, true : false; }


template<typename T, typename U> inline T cadd(T& a, const U& b, const int mod = 1000000007) { a = (a * 1LL + b) % mod; if (a < 0) a += mod; return a; }
template<typename T, typename U> inline T csub(T& a, const U& b, const int mod = 1000000007) { a = (a * 1LL - b) % mod; if (a < 0) a += mod; return a; }
template<typename T, typename U> inline T cmul(T& a, const U& b, const int mod = 1000000007) { return a = (a * 1LL * b) % mod; }


template<typename T> inline T clow(T& a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T cup(T& a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T cboth(T& a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }


template<typename T> inline T vlow(T a, const int mod = 1000000007) { while (a < 0) a += mod; return a; }
template<typename T> inline T vup(T a, const int mod = 1000000007) { while (a >= mod) a -= mod; return a; }
template<typename T> inline T vboth(T a, const int mod = 1000000007) { while (a < 0) a += mod; while (a >= mod) a -= mod; return a; }



template<typename T> inline T max(const T& a, const T& b, const T& c) { return std::max(std::max(a, b), c); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d) { return std::max(max(a, b, c), d); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e) { return std::max(max(a, b, c, d), e); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { return std::max(max(a, b, c, d, e), f); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { return std::max(max(a, b, c, d, e, f), g); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { return std::max(max(a, b, c, d, e, f, g), h); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { return std::max(max(a, b, c, d, e, f, g, h), i); }
template<typename T> inline T max(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { return std::max(max(a, b, c, d, e, f, g, h, i), j); }
template<typename T> inline T min(const T& a, const T& b, const T& c) { return std::min(std::min(a, b), c); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d) { return std::min(min(a, b, c), d); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e) { return std::min(min(a, b, c, d), e); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f) { return std::min(min(a, b, c, d, e), f); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g) { return std::min(min(a, b, c, d, e, f), g); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h) { return std::min(min(a, b, c, d, e, f, g), h); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i) { return std::min(min(a, b, c, d, e, f, g, h), i); }
template<typename T> inline T min(const T& a, const T& b, const T& c, const T& d, const T& e, const T& f, const T& g, const T& h, const T& i, const T& j) { return std::min(min(a, b, c, d, e, f, g, h, i), j); }

template<int n = 1024, int m = n, typename T = int> class BIT02 {
	T c[n][m];
public:
	BIT02() { memset(c, 0, sizeof(c)); }
	void clear() { memset(c, 0, sizeof(c)); }
	int add(int x, int y, T d) {
		if (x <= -1 || y <= -1) return -1;
		for (int i = x; i < n; i |= i + 1)
			for (int j = y; j < m; j |= j + 1)
				c[i][j] += d;
		return 0;
	}
	T sum(int x, int y) {
		T sum = 0;
		for (int i = x; i >= 0; i = (i & i + 1) - 1)
			for (int j = y; j >= 0; j = (j & j + 1) - 1)
				sum += c[i][j];
		return sum;
	}
	T sum(int r1, int c1, int r2, int c2) {
		return sum(r2, c2) + sum(r1 - 1, c1 - 1) - sum(r2, c1 - 1) - sum(r1 - 1, c2);
	}

	template<typename U>
	int madd(int x, int y, T d, U mod) {
		if (x <= -1 || y <= -1) return -1;
		for (int i = x; i < n; i |= i + 1)
			for (int j = y; j < m; j |= j + 1) {
				c[i][j] = (c[i][j] + d) % mod;
				if (c[i][j] < 0) c[i][j] += mod;
			}
		return 0;
	}
	template<typename U>
	T msum(int x, int y, U mod) {
		T sum = 0;
		for (int i = x; i >= 0; i = (i & i + 1) - 1)
			for (int j = y; j >= 0; j = (j & j + 1) - 1) {
				sum = (sum + c[i]) % mod;
				if (sum < 0) sum += mod;
			}
		return sum;
	}
	template<typename U>
	T msum(int r1, int c1, int r2, int c2, U mod) {
		T ret = (msum(r2, c2, mod) + msum(r1 - 1, c1 - 1, mod) - msum(r2, c1 - 1, mod) - msum(r1 - 1, c2, mod)) % mod;
		if (ret < 0) ret += mod;
		return ret;
	}
};


class bit_set {
	typedef unsigned char uchar;
	std::vector<uchar> __bits;
	size_t __size_to_vector_size(size_t n) { return (n + 7) >> 3; }
	size_t __size;
public:
	bit_set() {}
	bit_set(size_t n) : __size(n), __bits(__size_to_vector_size(n), 0) {}
	bit_set(const bit_set& b) : __size(b.__size), __bits(b.__bits) {}
	void clear() { __bits.clear(); __size = 0; }
	size_t size() const { return __size; }
	void resize(int n, bool is_set = false) {
		__size = n;
		__bits.assign(__size_to_vector_size(n), is_set ? uchar(255) : 0);
	}
	bool test(size_t n) {
		uchar&c = __bits[n >> 3];
		size_t i = n & 7;
		return (c >> i) & 1;
	}
	bool set(size_t n) {
		uchar&c = __bits[n >> 3];
		size_t i = n & 7;
		if ((c >> i) & 1) return false;
		c |= uchar(1) << i;
		return true;
	}
	bool reset(size_t n) {
		uchar&c = __bits[n >> 3];
		size_t i = n & 7;
		if (~(c >> i) & 1) return false;
		c &= ~(uchar(1) << i);
		return true;
	}
	void flip(size_t n) {
		uchar&c = __bits[n >> 3];
		size_t i = n & 7;
		c ^= uchar(1) << i;
	}
	void set() {
		for (size_t i = 0; i < __bits.size(); ++i)
			__bits[i] = 255;
	}
	void reset() {
		for (size_t i = 0; i < __bits.size(); ++i)
			__bits[i] = 0;
	}
	void flip() {
		for (size_t i = 0; i < __bits.size(); ++i)
			__bits[i] ^= 255;
	}
	std::string to_string() const {
		std::string ret;
		for (size_t i = 0; i < __bits.size(); ++i) {
			const uchar& c = __bits[i];
			for (size_t j = 0; j < 8; ++j)
				ret += (c >> j & 1) ? "1" : "0";
		}
		ret.resize(__size);
		return ret;
	}
	bit_set& operator = (const bit_set& rhs) {
		__size = rhs.__size;
		__bits = rhs.__bits;
		return *this;
	}
};






const int _  = (int)(2e3 + 10);
const int __ = (int)(1e6 + 10);
const int LOG = 20;

int n, m, k, q;
struct Garland {
	int len;
	VI r, c, w;
	Garland() : len(0) {}
	void upd(int rr, int cc, int ww) {
		r.push_back(rr);
		c.push_back(cc);
		w.push_back(ww);
	}
} g[_];
BIT02<_,_,ll> bit;
bit_set bs;
struct Query { int x1, y1, x2, y2; };
vector<Query> vq;
vector<bit_set> vb;
vector<ll> preans[_];
inline void _main() {
	RD(n, m, k);
	bs.resize(k, true);
	REP(i, k) {
		RD(g[i].len);
		DO(g[i].len) {
			int r, c, w;
			RD(r, c, w);
			g[i].upd(--r, --c, w);
		}
	}
	RD(q);
	DO(q) {
		char op[20];
		scanf("%s", op);
		if (op[0] == 'S') {
			int id = RD();
			bs.flip(--id);
		}
		else {
			int x1, y1, x2, y2;
			RD(x1, y1, x2, y2);
			vq.push_back(Query{ --x1, --y1, --x2, --y2 });
			vb.push_back(bs);
		}
	}
	REP(i, k) {
		preans[i].resize(sz(vq));
		REP(j, g[i].len) {
			bit.add(g[i].r[j], g[i].c[j], g[i].w[j]);
		}
		REP(j, sz(vq)) {
			preans[i][j] = bit.sum(vq[j].x1, vq[j].y1, vq[j].x2, vq[j].y2);
		}
		REP(j, g[i].len) {
			bit.add(g[i].r[j], g[i].c[j], -g[i].w[j]);
		}
	}
	REP(i, sz(vq)) {
		ll ans = 0;
		REP(j, k) if (vb[i].test(j)) {
			ans += preans[j][i];
		}
		WR(ans);
	}
}




void id1() {

	srand(time(0));
	uniform_int_distribution<ll> u(-ll(1e9), ll(1e9));
	default_random_engine e(time(0));
	auto random = [&]() { return u(e); };
	ll n = 1000;
	ll m = 1000;
	WR(n, m);
	DO(n) WR(random(), random());
	DO(m) WR(random());

	exit(0);
}
int main() {
	
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
		freopen("err.txt", "w", stderr);
	
	
		_main();
	
		id1();
	
	
		OUT("Time elapsed:", run_time(), "s.");
		OUT(my_time());
		
			FILE *fp = fopen(FILE_NAME, "r+");
			fprintf(fp, "//Latest run time : %s\n", my_time());
			fclose(fp);
		
	
	return 0;
}

