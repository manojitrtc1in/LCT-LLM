#include <bits/stdc++.h>
using namespace std;
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::cpp_dec_float_100;
	using namespace boost::multiprecision;
#endif
#ifdef LOCAL_DEV
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
#else
	#define debug(...) do {} while (false)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::reverse_iterator first, const typename std::vector<T>::reverse_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_iterator first, const typename std::vector<T>::const_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_reverse_iterator first, const typename std::vector<T>::const_reverse_iterator last) : std::vector<T>(first, last) {}
			T& operator[](size_t n) {
				try { return this->at(n); } catch (const std::exception& e) {
					std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n);
				}
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) {
					std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n);
				}
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}		
		dbool(const dbool&) = default;
		dbool(dbool&&) = default;
		dbool& operator=(const dbool&) = default;
		dbool& operator=(dbool&&) = default;
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::dvector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::dvector<std::dvector<T>>& vv) {
		s << "\\\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void catch_SIGSEGV([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif


using ll = long long;


constexpr ll INF = (ll)1e18;

constexpr ll MOD = 998244353;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1LL, 0LL, -1LL, 0LL};
constexpr ll dy[4] = {0LL, 1LL, 0LL, -1LL};
constexpr ll dx8[8] = {1LL, 0LL, -1LL, 0LL, 1LL, 1LL, -1LL, -1LL};
constexpr ll dy8[8] = {0LL, 1LL, 0LL, -1LL, 1LL, -1LL, 1LL, -1LL};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }



inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y){ ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
inline constexpr ll invmod(ll a, ll m = MOD){ ll x = 0, y = 0; extgcd(a, m, x, y); return (x + m) % m; }
class Modint{
public:
	ll _num;
	constexpr Modint() : _num() { _num = 0; }
	constexpr Modint(ll x) : _num() { _num = x % MOD; if(_num < 0) _num += MOD; }
	inline constexpr Modint operator= (int x){ _num = x % MOD; if(_num<0) _num += MOD; return *this; }
	inline constexpr Modint operator= (ll x){ _num = x % MOD; if(_num<0) _num += MOD; return *this; }
	

	inline constexpr Modint operator+ (int x){ return Modint(_num + x); }
	inline constexpr Modint operator+ (ll x){ return Modint(_num + x); }
	inline constexpr Modint operator+ (Modint x){ ll a = _num + x._num; if(a >= MOD) a -= MOD; return Modint{a}; }
	inline constexpr Modint operator+=(int x){ _num += x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator+=(ll x){ _num += x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator+=(Modint x){ _num += x._num; if(_num >= MOD) _num -= MOD; return *this; }
	inline constexpr Modint operator++(){ _num++; if(_num == MOD) _num = 0; return *this; }
	inline constexpr Modint operator- (int x){ return Modint(_num - x); }
	inline constexpr Modint operator- (ll x){ return Modint(_num - x); }
	inline constexpr Modint operator- (Modint x){ ll a = _num - x._num; if(a < 0) a += MOD; return Modint{a}; }
	inline constexpr Modint operator-=(int x){ _num -= x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator-=(ll x){ _num -= x; _num %= MOD; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator-=(Modint x){ _num -= x._num; if(_num < 0) _num += MOD; return *this; }
	inline constexpr Modint operator--(){ _num--; if(_num == -1) _num = MOD - 1; return *this; }
	inline constexpr Modint operator* (int x){ return Modint(_num * (x % MOD)); }
	inline constexpr Modint operator* (ll x){ return Modint(_num * (x % MOD)); }
	inline constexpr Modint operator* (Modint x){ return Modint{_num * x._num % MOD}; }
	inline constexpr Modint operator*=(int x){ _num *= Modint(x); _num %= MOD; return *this; }
	inline constexpr Modint operator*=(ll x){ _num *= Modint(x); _num %= MOD; return *this; }
	inline constexpr Modint operator*=(Modint x){ _num *= x._num; _num %= MOD; return *this; }
	inline constexpr Modint operator/ (int x){ return Modint(_num * invmod(Modint(x), MOD)); }
	inline constexpr Modint operator/ (ll x){ return Modint(_num * invmod(Modint(x), MOD)); }
	inline constexpr Modint operator/ (Modint x){ return Modint{_num * invmod(x._num, MOD) % MOD}; }
	inline constexpr Modint operator/=(int x){ _num *= invmod(Modint(x), MOD); _num %= MOD; return *this; }
	inline constexpr Modint operator/=(ll x){ _num *= invmod(Modint(x), MOD); _num %= MOD; return *this; }
	inline constexpr Modint operator/=(Modint x){ _num *= invmod(x._num, MOD); _num %= MOD; return *this; }
	inline constexpr Modint pow(ll n){ ll i = 1, x = n>=0 ? n : -n; Modint ans = 1, cnt = n>=0 ? *this : Modint(1) / *this; while(i <= x){ if(x & i){ ans *= cnt; x ^= i; } cnt *= cnt; i *= 2; } return ans; }
	inline constexpr operator ll() const { return _num; }
};
inline std::istream& operator>>(std::istream &s, Modint &x){ ll t; s>>t; x=t; return s; }
vector<Modint> fac(1, 1), inv(1, 1);
inline void reserve(size_t a){
	if(fac.size() >= a) return;
	if(a < fac.size() * 2) a = fac.size() * 2;
	if(a >= MOD) a = MOD;
	while(fac.size() < a) fac.push_back(fac.back() * ll(fac.size()));
	inv.resize(fac.size());
	inv.back() = Modint(1) / fac.back();
	for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
inline Modint factorial(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
inline Modint nPk_loop(ll n, ll k){ if(n<k) return 0; Modint val(1); for(ll i=n;i>(n-k);i--)val*=i; return val; }
inline Modint nCk_loop(ll n, ll k){ if(n<k) return 0; Modint val(1); k=min(k,n-k); for(ll i=n;i>(n-k);i--)val*=i; for(ll i=k;i>1;i--)val/=i; return val; };
inline Modint nPk(ll n, ll k){ if(k < 0 || n < k) return 0; if(n>=(ll)1e7) return nPk_loop(n, k); reserve(n + 1); return fac[n] * inv[n - k]; }
inline Modint nCk(ll n, ll k){ if(k < 0 || n < k) return 0; if(n>=(ll)1e7) return nCk_loop(n, k); reserve(n + 1); return fac[n] * inv[k] * inv[n - k]; }
inline Modint nHk(ll n, ll k){ return nCk(n + k - 1, k); } 





map<ll,ll> prime_factorize(ll n) {
	map<ll,ll> ret;
	for(ll i = 2; i * i <= n; i++) {
		while(n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if(n != 1) ret[n] = 1;
	return ret;
}

template<typename T> inline T gcd(T a, T b){
	if(a==0) return b;
	if(b==0) return a;
	if(a<0) a=-a;
	if(b<0) b=-b;
	const int s=__builtin_ctzll(a|b);
	a>>=__builtin_ctzll(a);
	while(b){
		b>>=__builtin_ctzll(b);
		if(a>b) swap(a, b);
		b-=a;
	}
	return a<<s;
}


void solve() {
	std::cin.tie(0);
	std::cout.tie(0);
   	ios::sync_with_stdio(false);
	ll N,Q;
	cin>>N>>Q;
	vector<Modint> anslist(Q);

	vector<pair<ll,ll>> v(Q);
	rep(i,Q)cin>>v[i].first>>v[i].second;
	set<ll> s;
	rep(i,Q){
		ll g=gcd(v[i].first,v[i].second);
		s.insert(v[i].first/g);
		s.insert(v[i].second/g);
	}
	map<ll,map<ll,ll>> factorv;
	for(ll t:s){
		factorv[t]=prime_factorize(t);
	}

	auto f=[&](ll x)->Modint{
		Modint ans=1;
		ll t=0;
		for(pair<ll,ll> pr:factorv[x]){
			t+=pr.second;
			ans*=nCk(t,pr.second);
		}
		return ans;
	};
	rep(q,Q){
		auto [a,b]=v[q];		
		if(a==b){
			anslist[q]=1;continue;
		}
		if(a<b)swap(a,b);
		
		if(a%b==0){
			anslist[q]=f(a/b);
			continue;
		}

		ll g=gcd(a,b);
		anslist[q]=f(a/g)*f(b/g);
	}
	rep(q,Q)p(anslist[q]);
}

signed main() {
	solve();
	return 0;
}