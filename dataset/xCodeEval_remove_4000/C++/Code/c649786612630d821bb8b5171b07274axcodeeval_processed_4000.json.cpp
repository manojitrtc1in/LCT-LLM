


 

using namespace std;


using namespace atcoder;

 
























 










template <class T = int>
using V = std::vector<T>;
template <class T = int>
using VV = std::vector<std::vector<T>>;
template <class T = int>
using VVV = std::vector<std::vector<std::vector<T>>>;
template <class T = int>
using VVVV = std::vector<std::vector<std::vector<std::vector<T>>>>;
template <class T>
using pqup = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using ll = long long;
using ld = long double;
using int128 = __int128_t;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using Tp = tuple<ll,ll,ll>;
 


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


	std::vector<type> name(size); \
	scanner::INPUT(name)

	std::vector<std::vector<type>> name(h, std::vector<type>(w)); \
	scanner::INPUT(name)

	int id0; \
	scanner::INPUT(id0)

	long long id0; \
	scanner::INPUT(id0)

	std::string id0; \
	scanner::INPUT(id0)

	char id0; \
	scanner::INPUT(id0)

	double id0; \
	scanner::INPUT(id0)

	long double id0; \
	scanner::INPUT(id0)
 


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


void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	debugger::view(H);
	std::cerr << ", ";
	debug_out(T...);
}

	do {                                                          \
		std::cerr << __LINE__ << " [" << 
		debug_out(id0);                                   \
		std::cerr << "\b\b]\n";                                   \
	} while(false)



 


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
} id3;



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
 
long long id2(long long a, long long b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return a / b;
    else return (a - b + 1) / b;
}
 
long long id1(long long x) {
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

const ll mod = 998244353;

struct mint {
  ll x; 

  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint val(){
    return x;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  

  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}




struct combination {
  vector<mint> fact, ifact;
  combination(ll n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (ll i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (ll i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(ll n, ll k) {
    return fact[n]*ifact[n-k];
  }
};

void main_() {
    LL(N);
    V<ll> A(N);
    
    REP(i,N){
        char c;
        cin >> c;
        if(c == '-')A[i] = -1;
        else{
            cin >> A[i];
        }
    }
    mint ans = 0;
    REP(i,N){
        if(A[i] == -1)continue;
        VV<mint> dp(N+1,V<mint>(N+1));
        dp[0][0] = 1;
        REP(j,N){
            if(i == j){
                REP(k,N+1)dp[j+1][k] = dp[j][k];
                continue;
            }
            if(A[j] == -1){
                REP(k,N+1){
                    if(k > 0){
                        dp[j+1][k-1] += dp[j][k];
                    }
                    else if(j < i)dp[j+1][k] += dp[j][k];
                    dp[j+1][k] += dp[j][k];
                }
                continue;
            }
            else{
                if((j < i && A[j] == A[i]) || A[j] < A[i]){
                    REP(k,N+1){
                        if(k < N){
                            dp[j+1][k+1] += dp[j][k];
                        }
                        dp[j+1][k] += dp[j][k];
                    }
                }
                else{
                    REP(k,N+1){
                        dp[j+1][k] += dp[j][k];
                        dp[j+1][k] += dp[j][k];
                    }
                }
            }
        }
        REP(j,N+1){
            mint val = A[i];
            val *= dp[N][j];
            ans +=val;
        }
    }
    
    cout << ans << endl;
}

int main() {
	int t = 1;
	

	while(t--) main_();
	return 0;
}