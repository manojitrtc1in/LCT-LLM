#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
 
#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
 
#pragma region Macros


#define foa(v, a) for(auto &v : a)
#define REPname(a, b, c, d, e, ...) e
#define REP(...) REPname(__VA_ARGS__, REP3, REP2, REP1, REP0)(__VA_ARGS__)
#define REP0(x) for(int i = 0; i < (x); ++i)
#define REP1(i, x) for(int i = 0; i < (x); ++i)
#define REP2(i, l, r) for(int i = (l); i < (r); ++i)
#define REP3(i, l, r, c) for(int i = (l); i < (r); i += (c))
#define REPSname(a, b, c, ...) c
#define REPS(...) REPSname(__VA_ARGS__, REPS1, REPS0)(__VA_ARGS__)
#define REPS0(x) for(int i = 1; i <= (x); ++i)
#define REPS1(i, x) for(int i = 1; i <= (x); ++i)
#define RREPname(a, b, c, d, e, ...) e
#define RREP(...) RREPname(__VA_ARGS__, RREP3, RREP2, RREP1, RREP0)(__VA_ARGS__)
#define RREP0(x) for(int i = (x)-1; i >= 0; --i)
#define RREP1(i, x) for(int i = (x)-1; i >= 0; --i)
#define RREP2(i, l, r) for(int i = (r)-1; i >= (l); --i)
#define RREP3(i, l, r, c) for(int i = (r)-1; i >= (l); i -= (c))
#define RREPSname(a, b, c, ...) c
#define RREPS(...) RREPSname(__VA_ARGS__, RREPS1, RREPS0)(__VA_ARGS__)
#define RREPS0(x) for(int i = (x); i >= 1; --i)
#define RREPS1(i, x) for(int i = (x); i >= 1; --i)
 


#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define popcnt(x) __builtin_popcountll(x)
template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T = int>
using VVV = std::vector<std::vector<std::vector<T>>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
 


template <class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
	is >> p.first >> p.second;
	return is;
}
template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
	for(T &i : v) is >> i;
	return is;
}
std::istream &operator>>(std::istream &is, __int128_t &a) {
	std::string s;
	is >> s;
	__int128_t ret = 0;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] and s[i] <= '9')
			ret = 10 * ret + s[i] - '0';
	a = ret * (s[0] == '-' ? -1 : 1);
	return is;
}
namespace scanner {
void scan(int &a) { std::cin >> a; }
void scan(long long &a) { std::cin >> a; }
void scan(std::string &a) { std::cin >> a; }
void scan(char &a) { std::cin >> a; }
void scan(char a[]) { std::scanf("%s", a); }
void scan(double &a) { std::cin >> a; }
void scan(long double &a) { std::cin >> a; }
template <class T, class U>
void scan(std::pair<T, U> &p) { std::cin >> p; }
template <class T>
void scan(std::vector<T> &a) { std::cin >> a; }
void INPUT() {}
template <class Head, class... Tail>
void INPUT(Head &head, Tail &... tail) {
	scan(head);
	INPUT(tail...);
}
}  

#define VEC(type, name, size)     \
	std::vector<type> name(size); \
	scanner::INPUT(name)
#define VVEC(type, name, h, w)                                    \
	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)
#define INT(...)     \
	int __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LL(...)            \
	long long __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define STR(...)             \
	std::string __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define CHAR(...)     \
	char __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define DOUBLE(...)     \
	double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
#define LD(...)              \
	long double __VA_ARGS__; \
	scanner::INPUT(__VA_ARGS__)
 


template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &a) {
	for(int i = 0; i < int(a.size()); ++i) {
		if(i) os << " ";
		os << a[i];
	}
	return os;
}
std::ostream &operator<<(std::ostream &dest, __int128_t &value) {
	std::ostream::sentry s(dest);
	if(s) {
		__uint128_t tmp = value < 0 ? -value : value;
		char buffer[128];
		char *d = std::end(buffer);
		do {
			--d;
			*d = "0123456789"[tmp % 10];
			tmp /= 10;
		} while(tmp != 0);
		if(value < 0) {
			--d;
			*d = '-';
		}
		int len = std::end(buffer) - d;
		if(dest.rdbuf()->sputn(d, len) != len) {
			dest.setstate(std::ios_base::badbit);
		}
	}
	return dest;
}
template <class T>
void print(const T a) { std::cout << a << '\n'; }
template <class Head, class... Tail>
void print(Head H, Tail... T) {
	std::cout << H << ' ';
	print(T...);
}
template <class T>
void printel(const T a) { std::cout << a << '\n'; }
template <class T>
void printel(const std::vector<T> &a) {
	for(const auto &v : a)
		std::cout << v << '\n';
}
template <class Head, class... Tail>
void printel(Head H, Tail... T) {
	std::cout << H << '\n';
	printel(T...);
}
void Yes(const bool b = true) { std::cout << (b ? "Yes\n" : "No\n"); }
void No() { std::cout << "No\n"; }
void YES(const bool b = true) { std::cout << (b ? "YES\n" : "NO\n"); }
void NO() { std::cout << "No\n"; }
void err(const bool b = true) {
	if(b) {
		std::cout << "-1\n", exit(0);
	}
}
 


namespace debugger {
template <class T>
void view(const std::vector<T> &a) {
	std::cerr << "{ ";
	for(const auto &v : a) {
		std::cerr << v << ", ";
	}
	std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
	std::cerr << "{\n";
	for(const auto &v : a) {
		std::cerr << "\t";
		view(v);
		std::cerr << "\n";
	}
	std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
	std::cerr << "{\n";
	for(const auto &p : a) std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
	std::cerr << "{\n";
	for(const auto &p : m) std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
	std::cerr << "}";
}
template <class T, class U>
void view(const std::pair<T, U> &p) { std::cerr << "(" << p.first << ", " << p.second << ")"; }
template <class T>
void view(const std::set<T> &s) {
	std::cerr << "{ ";
	for(auto &v : s) {
		view(v);
		std::cerr << ", ";
	}
	std::cerr << "\b\b }";
}
 
template <class T>
void view(const T &e) { std::cerr << e; }
}  

#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}
#define debug(...)                                                \
	do {                                                          \
		std::cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
		debug_out(__VA_ARGS__);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)
#else
#define debug(...) (void(0))
#endif
 


template <class T>
int lb(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::lower_bound((a).begin(), (a).end(), (x))); }
template <class T>
int ub(const std::vector<T> &a, const T x) { return std::distance((a).begin(), std::upper_bound((a).begin(), (a).end(), (x))); }
template <class T>
void UNIQUE(std::vector<T> &a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
}
template <class T>
std::vector<T> press(std::vector<T> &a) {
	auto res = a;
	UNIQUE(res);
	for(auto &v : a)
		v = lb(res, v);
	return res;
}
#define SORTname(a, b, c, ...) c
#define SORT(...) SORTname(__VA_ARGS__, SORT1, SORT0, ...)(__VA_ARGS__)
#define SORT0(a) std::sort((a).begin(), (a).end())
#define SORT1(a, c) std::sort((a).begin(), (a).end(), [](const auto x, const auto y) { return x c y; })
template <class T>
void ADD(std::vector<T> &a, const T x) {
	for(auto &v : a) v += x;
}
template <class T>
void SUB(std::vector<T> &a, const T x = 1) {
	for(auto &v : a) v -= x;
}
template <class T>
void MUL(std::vector<T> &a, const T x) {
	for(auto &v : a) v *= x;
}
template <class T>
void DIV(std::vector<T> &a, const T x) {
	for(auto &v : a) v /= x;
}
 


template <class T, class U>
inline bool chmin(T &a, const U &b) { return a > b ? a = b, true : false; }
template <class T, class U>
inline bool chmax(T &a, const U &b) { return a < b ? a = b, true : false; }
template <class T>
T divup(T x, T y) { return (x + y - 1) / y; }
template <class T>
T POW(T a, long long n) {
	T ret = 1;
	while(n) {
		if(n & 1) ret *= a;
		a *= a;
		n >>= 1;
	}
	return ret;
}

template<typename T>
T ADD(T a, T b){
	T res;
	return __builtin_add_overflow(a, b, &res) ? numeric_limits<T>::max() : res;
}

template<typename T>
T MUL(T a, T b){
	T res;
	return __builtin_mul_overflow(a, b, &res) ? numeric_limits<T>::max() : res;
}



long long POW(long long a, long long n, const int mod) {
	long long ret = 1;
	while(n) {
		if(n & 1) (ret *= a) %= mod;
		(a *= a) %= mod;
		n >>= 1;
	}
	return ret;
}
 


struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;

#pragma endregion

using R = long double;
constexpr R EPS=1E-11;



int sgn(const R& r){ return (r > EPS) - (r < -EPS); }


int sgn(const R& a, const R &b){ return sgn(a-b); }













long long x10(const string& s, size_t n) {
    if (s.front() == '-') return -x10(s.substr(1), n);
    auto pos = s.find('.');
    if (pos == string::npos) return stoll(s + string(n, '0'));
    return stoll(s.substr(0, pos) + s.substr(pos + 1) + string(n + pos + 1 - s.size(), '0'));
}
 
long long ceildiv(long long a, long long b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return (a + b - 1) / b;
    else return a / b;
}
 
long long floordiv(long long a, long long b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return a / b;
    else return (a - b + 1) / b;
}
 
long long floorsqrt(long long x) {
    assert(x >= 0);
    long long ok = 0;
    long long ng = 1;
    while (ng * ng <= x) ng <<= 1;
    while (ng - ok > 1) {
        long long mid = (ng + ok) >> 1;
        if (mid * mid <= x) ok = mid;
        else ng = mid;
    }
    return ok;
}

inline int topbit(unsigned long long x){
	return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
	return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){

	return __builtin_parity(x);
}

const int inf = 1e9;
const ll INF = 1e18;

struct Sieve{
    int n;
    vector<int> f, primes;
    

    Sieve(int n=1):n(n), f(n+1){

        f[0]=f[1]=-1;
        for(ll i=2;i<=n;i++){
            if(f[i]) continue;
            primes.push_back(i);
            f[i]=i;
            for(ll j=i*i;j<=n;j+=i){
                if(!f[j]) f[j]=i;
            }
        }
    }
    bool isPrime(int x) { return f[x]==x;} 

    vector<int> factorList(int x){

        vector<int> res;
        while(x!=1){
            res.push_back(f[x]);
            x/=f[x];
        }
        return res;
    }
    vector<pair<int,int>> factor(int x){

        vector<int> fl=factorList(x);
        if(fl.size()==0) return {};
        vector<pair<int,int>> res(1,pair<int,int>(fl[0],0));
        for(int p : fl){
            if(res.back().first==p){
                res.back().second++;
            }else{
                res.emplace_back(p,1);
            }
        }
        return res;
    }
};

void main_() {
	INT(N,Q);
	VEC(int,A,N);
	Sieve sieve(100001);
	V<int> p(100001),q;
	int cnt = 0;
	for(int i = 2;i <= 100000;i++){
	    if(p[i] == 0){
	        p[i] = cnt;
	        cnt++;
	        q.push_back(i);
	        for(int j = 2 * i;j <= 100000;j += i){
	            p[j] = -1;
	        }
	    }
	}
	VV<int> pos(18,V<int>(N,N));
	
	VV<int> r(cnt);
	REP(i,N){
	    V<pii> res = sieve.factor(A[i]);
	    int sz = res.size();
	    for(auto [x,y]:res){
	        r[p[x]].push_back(i);
	    }
	    
	}
	
	int ri = 0;
	V<int> list(100001);
	
	for(int le = 0; le < N; le++){
	    while(ri < N){
	        bool ok = true;
	        V<pii> res = sieve.factor(A[ri]);
	        for(auto [x,y]:res){
	            if(list[x])ok = false;
	        }
	        if(!ok)break;
	        for(auto [x,y]:res){
	            list[x] = 1;
	        }
	        ri++;
	    }
	    pos[0][le] = ri;
	    V<pii> res = sieve.factor(A[le]);
	    for(auto [x,y]:res){
	        list[x] = 0;
	    }
	}

	REP(i,18){
	    REP(j,N){
	        if(pos[i][j] == N)continue;
	        pos[i+1][j] = pos[i][pos[i][j]];
	    }
	}
	
	REP(i,Q){
	    LL(L,R);
	    L--;
	   
	    int now = L;
	    int ans = 1;
	    
	    for(int j = 17;j >= 0;j--){
	        
	        if(pos[j][now] >= R)continue;
	        else{
	            ans += (1LL<<j);
	            now = pos[j][now];
	        }
	    }
	    
	    cout << ans << endl;
	}
}
 
int main() {
	int t = 1;
	

	while(t--) main_();
	return 0;
}