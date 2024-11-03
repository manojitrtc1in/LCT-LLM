


































































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





struct default_random_weight_generator {
	int operator()() const {
		return rand() << 15 | rand();
	}
};

template<typename T, typename RandomWeightGenerator = default_random_weight_generator>
struct id2 {
	T val;
	int weight;
	size_t subtree_size;
	

	static RandomWeightGenerator generate_weight;
	id2(T v = 0) : val(v), weight(generate_weight()), subtree_size(1)
		

	{}
	

	virtual void downpush() {}
	virtual void print() const {
		printf("val = %d\nweight = %d\n", val, weight);
		

		


		

		


		

		

		printf("subtree_size = %u\n", subtree_size);
	}
};
template<typename T, typename RandomWeightGenerator>
RandomWeightGenerator id2<T, RandomWeightGenerator>::generate_weight = RandomWeightGenerator();




template<typename T, typename id4 = id2<T> >
class id1 {
private:
	id4* __root;
public:
	id1(id4* r = 0) : __root(r) {}
	id1(const id1& tt) : __root(tt.__root) {}

	void destroy() { __destroy(__root); }
	void clear() { __destroy(__root); __root = 0; }
	size_t size() const { return __root ? __root->subtree_size : 0; }
	bool empty() const { return !__root; }
	id4* root() const { return __root; }
	id4* insert(const T& val) {
		id4* newnode = new id4(val);
		return insert(newnode);
	}
	id4* insert(id4* newnode) {
		if (!__root) {
			__root = newnode;
			return newnode;
		}
		__insert(__root, newnode);
		__rotate(newnode);
		return newnode;
	}
	id4* find(const T& val) const {
		return __find(__root, val);
	}
	void erase(const T& val) {
		return erase(__find(__root, val));
	}
	void erase(id4* node) {
		node->downpush();
		while (node->left && node->right) {
			if (node->left->weight < node->right->weight) __right_rotate(node);
			else __left_rotate(node);
		}
		id4 *f = node->father;
		while (f) {
			--(f->subtree_size);
			f = f->father;
		}
		if (node->left) {
			node->left->father = node->father;
			if (node == __root) __root = node->left;
			else {
				if (node == node->father->left) node->father->left = node->left;
				else node->father->right = node->left;
			}
		}
		else if (node->right) {
			node->right->father = node->father;
			if (node == __root) __root = node->right;
			else {
				if (node == node->father->left) node->father->left = node->right;
				else node->father->right = node->right;
			}
		}
		else {
			if (node == __root) __root = NULL;
			else {
				if (node == node->father->left) node->father->left = NULL;
				else node->father->right = NULL;
			}
		}
		delete node;
	}
	

	std::pair<id1, id1> split(const T& k) {
		id4* l, *r;
		__split(__root, k, l, r);
		return std::make_pair(id1(l), id1(r));
	}
	

	id1& merge(id1& rhs) {
		__root = __merge(__root, rhs.__root);
		return *this;
	}
	void downpush_all() {
		__downpush_all(__root);
	}

	void traversal() const {
		_OUT("traversal, root = ");
		if (!__root) OUT("NULL");
		else OUT(__root->val);

		dfs(__root);
	}

	void dfs(id4 *u) const {
		if (!u) return;
		u->downpush();
		u->record();
		u->print();
		dfs(u->left);
		dfs(u->right);
	}

	id4* max_element() const {
		id4* u = __root;
		assert(u);
		u->downpush();
		while (u->right) {
			u = u->right;
			u->downpush();
		}
		return u;
	}
	id4* min_element() const {
		id4* u = __root;
		assert(u);
		u->downpush();
		while (u->left) {
			u = u->left;
			u->downpush();
		}
		return u;
	}
private:
	void __destroy(id4* u) {
		if (!u) return;
		__destroy(u->left);
		__destroy(u->right);
		delete u;
	}
	void __downpush_all(id4* u) {
		if (!u) return;
		u->downpush();
		u->record();
		__downpush_all(u->left);
		__downpush_all(u->right);
	}
	id4* __merge(id4* l, id4* r) {
		if (!l) return r;
		if (!r) return l;
		l->downpush();
		r->downpush();
		if (l->weight < r->weight) {
			l->subtree_size += r->subtree_size;
			r = __merge(l->right, r);
			l->right = r;
			r->father = l;
			return l;
		}
		else {
			r->subtree_size += l->subtree_size;
			l = __merge(l, r->left);
			l->father = r;
			r->left = l;
			return r;
		}
	}
	void __split(id4* u, const T& k, id4* &l, id4* &r) {
		if (!u) {
			l = r = NULL;
			return;
		}
		u->downpush();
		if (u->val < k) {
			__split(u->right, k, l, r);
			if (r) u->subtree_size -= r->subtree_size;
			u->right = l;
			if (l) l->father = u;
			if (r) r->father = NULL;
			l = u;
		}
		else {
			__split(u->left, k, l, r);
			if (l) u->subtree_size -= l->subtree_size;
			u->left = r;
			if (r) r->father = u;
			if (l) l->father = NULL;
			r = u;
		}
	}
	id4* __find(id4* u, const T& val) const {
		if (!u) return u;
		if (u->val < val) return __find(u->right, val);
		if (u->val > val) return __find(u->left, val);
		return u;
	}
	void __rotate(id4* newnode) {
		while (newnode->father) {
			id4* f = newnode->father;
			if (newnode->weight >= f->weight) break;
			if (newnode == (f->left)) __right_rotate(f);
			else __left_rotate(f);
		}
	}
	id4* __insert(id4* cur, id4* newnode) {
		++(cur->subtree_size);
		cur->downpush();
		if (newnode->val < cur->val) {
			if (cur->left != 0)
				return __insert(cur->left, newnode);
			cur->left = newnode;
			newnode->father = cur;
			return newnode;
		}
		else {
			if (cur->right != 0)
				return __insert(cur->right, newnode);
			cur->right = newnode;
			newnode->father = cur;
			return newnode;
		}
	}
	void __left_rotate(id4* f) {
		id4* r = f->right;
		f->downpush();
		r->downpush();
		--(f->subtree_size);
		if (r->right) f->subtree_size -= r->right->subtree_size;
		++(r->subtree_size);
		if (f->left) r->subtree_size += f->left->subtree_size;

		r->father = f->father;
		if (f == __root) __root = r;
		else {
			if (f->father->left == f) f->father->left = r;
			else f->father->right = r;
		}
		f->right = r->left;
		if (r->left) r->left->father = f;
		r->left = f;
		f->father = r;
	}
	void __right_rotate(id4* f) {
		id4* l = f->left;
		f->downpush();
		l->downpush();
		--(f->subtree_size);
		if (l->left) f->subtree_size -= l->left->subtree_size;
		++(l->subtree_size);
		if (f->right) l->subtree_size += f->right->subtree_size;

		l->father = f->father;
		if (f == __root) __root = l;
		else {
			if (f->father->left == f) f->father->left = l;
			else f->father->right = l;
		}
		f->left = l->right;
		if (l->right) l->right->father = f;
		l->right = f;
		f->father = l;
	}
};







const int _  = (int)(2e5 + 10);
const int __ = (int)(1e6 + 10);
const int LOG = 20;


int ans[_];
struct id4 : id2<int> {
	id4* father, *left, *right;
	int cnt, id;
	int val_lazy, cnt_lazy;
	id4(int v=0, int i = 0) : 
		id2(v), cnt(0), id(i), val_lazy(0), cnt_lazy(0),
		father(0), left(0), right(0) {}
	void downpush() override {
		if (left) {
			left->apply(val_lazy, cnt_lazy);
		}
		if (right) {
			right->apply(val_lazy, cnt_lazy);
		}
		val_lazy = cnt_lazy = 0;
	}
	void apply(int dv, int dc) {
		val += dv;
		val_lazy += dv;
		cnt += dc;
		cnt_lazy += dc;
	}
	virtual void print() {
		id2::print();
		printf("id = %d, cnt = %d\n", id, cnt);
		printf("vallazy = %d,  cntlazy = %d\n", val_lazy, cnt_lazy);
		if (father) printf("father = %d\n", father->val);
		else printf("father = NULL\n");

		if (left) printf("left = %d\n", left->val);
		else printf("left = NULL\n");

		if (right) printf("right = %d\n", right->val);
		else printf("right = NULL\n");
		OUT();
	}
	void record() { ans[id] = cnt; }
};





typedef id1<int, id4> TT;
TT tt;
int n, k;
PII tshirt[_];

inline void _main() {
	RDB(n);
	REP(i, n) {
		RDB(tshirt[i].second, tshirt[i].first);
		tshirt[i].first *= -1;
	}
	sort(tshirt, tshirt + n);
	RDB(k);
	REP(i, k) {
		id4* t = new id4(RDB(), i);
		tt.insert(t);
	}
	

	REP(i, n) {
		int c = tshirt[i].second;
		

		TT l, r;
		tie(l, r) = tt.split(c);
		

		if (r.empty()) continue;
		r.root()->apply(-c, 1);
		if (l.empty()) continue;
		id4* lr = l.max_element();
		id4* rl = r.min_element();
		

		

		while (lr->val > rl->val) {
			TT Rl, Rr;
			tie(Rl, Rr) = r.split(rl->val + 1);
			TT Ll, Lr;
			tie(Ll, Lr) = l.split(rl->val);
			l = Ll.merge(Rl).merge(Lr);
			r = Rr;
			if (l.empty() || r.empty()) break;
			lr = l.max_element();
			rl = r.min_element();

			

			

		}
		tt = l.merge(r);
		

	}
	
	tt.downpush_all();
	

	WRn(ans, 0, k);


	tt.destroy();
}




void id3() {

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
	
		id3();
	
	
		OUT("Time elapsed:", run_time(), "s.");
		OUT(my_time());
		
			FILE *fp = fopen(FILE_NAME, "r+");
			fprintf(fp, "//Latest run time : %s\n", my_time());
			fclose(fp);
		
	
	return 0;
}

