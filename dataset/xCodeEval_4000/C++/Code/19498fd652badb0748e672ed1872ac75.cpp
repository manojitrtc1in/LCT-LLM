#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;


#if defined(LOCAL_TEST) || defined(LOCAL_DEV)
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE 1
	#include <boost/stacktrace.hpp>
#endif
#ifdef LOCAL_TEST
	namespace std {
		template <typename T> class dvector : public std::vector<T> {
		public:
			using std::vector<T>::vector;
			template <typename T_ = T, typename std::enable_if_t<std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			std::vector<bool>::reference operator[](std::size_t n) {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
			template <typename T_ = T, typename std::enable_if_t<std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			const T_ operator[](std::size_t n) const {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
			template <typename T_ = T, typename std::enable_if_t<!std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			T_& operator[](std::size_t n) {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
			template <typename T_ = T, typename std::enable_if_t<!std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			const T_& operator[](std::size_t n) const {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
		};
		template <typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>> class dmultiset : public std::multiset<T,Compare,Allocator> {
		public:
			using std::multiset<T,Compare,Allocator>::multiset;
			const typename std::multiset<T,Compare,Allocator>::iterator erase(const typename std::multiset<T,Compare,Allocator>::iterator it) {
				return std::multiset<T,Compare,Allocator>::erase(it);
			}
			std::size_t erase([[maybe_unused]] const T& x) {
				std::cerr << boost::stacktrace::stacktrace() << '\n'; assert(false);
			}
			std::size_t erase_all_elements(const T& x) {
				return std::multiset<T,Compare,Allocator>::erase(x);
			}
		};
	}
	#define vector dvector
	#define multiset dmultiset
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void catch_SIGSEGV([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#else
	#define erase_all_elements erase
#endif
#ifdef LOCAL_DEV
	template <typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	template <typename T, std::size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (std::size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template <typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template <typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (std::size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template <typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
		for (std::size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template <typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {
		s << "\\\n"; for (std::size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	template <typename T, std::size_t N, typename std::enable_if_t<!std::is_same_v<T, char>, std::nullptr_t> = nullptr> std::ostream& operator<<(std::ostream& s, const T (&v)[N]) {
		for (std::size_t i = 0; i < N; ++i){ s << v[i]; if (i < N - 1) s << "\t"; } return s; }
	#if __has_include(<ext/pb_ds/assoc_container.hpp>)
		template <typename Key, typename Compare> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& se) {
			s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
		template <typename Key, typename T, typename Hash> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::gp_hash_table<Key, T, Hash>& m) {
			s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	#endif
	void debug_impl() { std::cerr << '\n'; }
	template <typename Head, typename... Tail> void debug_impl(const Head& head, const Tail&... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << ":" << __LINE__ << " (" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return local; }
#else
	#define debug(...) do {} while (false)
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return prod; }
#endif


using ll = long long;


constexpr ll INF = std::numeric_limits<ll>::max() == INT_MAX ? (ll)1e9 + 7 : (ll)1e18;


constexpr ll MOD = 998244353; 

constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
void p() { std::cout << '\n'; }
template <typename Head, typename... Tail> void p(const Head& head, const Tail&... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template <typename T> inline void pv(const std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template <typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template <typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template <typename T> inline void uniq(std::vector<T>& v) { std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end()); }
template <typename T> inline ll sz(const T& v) { return std::size(v); }
template <typename T, std::size_t N> std::vector<T> make_vector_impl(std::vector<ll>& sizes, typename std::enable_if<(N==1), const T&>::type x) { return std::vector<T>(sizes.front(),x); }
template <typename T, std::size_t N> auto make_vector_impl(std::vector<ll>& sizes, typename std::enable_if<(N>1), const T&>::type x) { ll size=sizes.back(); sizes.pop_back(); return std::vector<decltype(make_vector_impl<T,N-1>(sizes,x))>(size,make_vector_impl<T,N-1>(sizes,x)); }
template <typename T, std::size_t N> auto make_vector(const ll (&sizes)[N], const T& x=T()) { std::vector<ll> s(N); for(std::size_t i=0; i<N; ++i)s[i]=sizes[N-1-i]; return make_vector_impl<T,N>(s,x); }
template <typename T> struct Indexer {
	struct iterator {
		ll _pos;
		typename T::iterator _it;
		iterator(typename T::iterator it): _pos(0), _it(it) {}
		std::pair<ll, typename std::iterator_traits<typename T::iterator>::reference> operator*() const { return {_pos, *_it}; }
		iterator& operator++() { ++_pos; ++_it; return *this; }
		iterator operator++(int) { iterator tmp(*this); ++*this; return tmp; }
		bool operator==(iterator const& it) const { return _it == it._it; }
		bool operator!=(iterator const& it) const { return !(*this == it); }
	};
	T& _container;
	Indexer(T& t): _container(t) {}
	iterator begin() const { return iterator(_container.begin()); }
	iterator end() const { return iterator(_container.end()); }
};
template <typename T> Indexer<T> indexer(const T& t) { return Indexer<T>(t); }
#define repv(i, val, v) for(auto&& [i, val] : indexer(v))
#if __has_include(<ext/pb_ds/assoc_container.hpp>)
	template <typename Key, typename Mapped, typename Hash = std::hash<Key>, typename std::enable_if_t<std::is_integral_v<Key>, std::nullptr_t> = nullptr> struct fmap : public __gnu_pbds::gp_hash_table<Key, Mapped, Hash> {
		using __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::gp_hash_table;
		template <typename T> fmap(std::initializer_list<std::initializer_list<T>> il) : __gnu_pbds::gp_hash_table<Key, Mapped, Hash>() {
			for (auto&& x : il) __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::insert(std::pair<Key, Mapped>(*x.begin(), *(x.begin() + 1)));
		}
		template <typename T> ll count(const T& x) const {
			return __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::find(x) != __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::end();
		}
	};
#else
	template <typename Key, typename Mapped> using fmap = std::map<Key, Mapped>;
#endif





constexpr int ModintConstexprSize = prodlocal(30000, 10);
template <int N = ModintConstexprSize>
struct ModintConstexpr {
	unsigned int inv[N + 1];
	constexpr inline long long modpow(long long a, long long n) {
		long long res = 1;
		while (n) {
			if (n & 1) res = res * a % MOD;
			a = a * a % MOD;
			n >>= 1;
		}
		return res;
	}
	constexpr ModintConstexpr() : inv() {
		inv[1] = 1;
		for (int i = 2; i <= N; ++i) inv[i] = modpow(i, MOD - 2);
	}
};
#ifdef __INTELLISENSE__
	#pragma diag_suppress 28
#endif
constexpr auto modintconstexpr = ModintConstexpr<>();

struct Modint{
#if __has_include(<ext/pb_ds/assoc_container.hpp>)
	using inv_cache_type = __gnu_pbds::gp_hash_table<unsigned int, unsigned int>;
#else
	using inv_cache_type = map<unsigned int, unsigned int>;
#endif
	inline static inv_cache_type& inv_cache() { static inv_cache_type inv_cache; return inv_cache; }
	unsigned num = 0;
	constexpr Modint() noexcept {}
	

    inline constexpr operator ll() const noexcept { return num; }
    inline constexpr Modint& operator+=(Modint x) noexcept { num += x.num; if(num >= MOD) num -= MOD; return *this; }
    inline constexpr Modint& operator++() noexcept { if(num == MOD - 1) num = 0; else num++; return *this; }
    inline constexpr Modint operator++(int) noexcept { Modint ans(*this); operator++(); return ans; }
    inline constexpr Modint operator-() const noexcept { return Modint(0) -= *this; }
    inline constexpr Modint operator-(Modint x) const noexcept { return Modint(*this) -= x; }
    inline constexpr Modint& operator-=(Modint x) noexcept { if(num < x.num) num += MOD; num -= x.num; return *this; }
    inline constexpr Modint& operator--() noexcept { if(num == 0) num = MOD - 1; else num--; return *this; }
    inline constexpr Modint operator--(int) noexcept { Modint ans(*this); operator--(); return ans; }
    inline constexpr Modint& operator*=(Modint x) noexcept { num = (unsigned long long)(num) * x.num % MOD; return *this; }
    inline Modint& operator/=(Modint x) noexcept { return operator*=(x.inv()); }
    template<class T> constexpr Modint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(MOD); if(y < 0) y += MOD; num = unsigned(y);
    }
    template<class T> inline constexpr Modint operator+(T x) const noexcept { return Modint(*this) += x; }
    template<class T> inline constexpr Modint& operator+=(T x) noexcept { return operator+=(Modint(x)); }
    template<class T> inline constexpr Modint operator-(T x) const noexcept { return Modint(*this) -= x; }
    template<class T> inline constexpr Modint& operator-=(T x) noexcept { return operator-=(Modint(x)); }
    template<class T> inline constexpr Modint operator*(T x) const noexcept { return Modint(*this) *= x; }
    template<class T> inline constexpr Modint& operator*=(T x) noexcept { return operator*=(Modint(x)); }
    template<class T> inline constexpr Modint operator/(T x) const noexcept { return Modint(*this) /= x; }
    template<class T> inline constexpr Modint& operator/=(T x) noexcept { return operator/=(Modint(x)); }
	inline Modint inv() const noexcept { if (num <= ModintConstexprSize) return modintconstexpr.inv[num]; auto& cachemap = inv_cache(); unsigned cached = cachemap[num]; if (cached) return cached; Modint x = inv_calc(); cachemap[num] = x.num; return x;}
    inline constexpr Modint inv_calc() const noexcept { ll x = 0, y = 0; extgcd(num, MOD, x, y); return x; }
    static inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
	inline constexpr Modint pow(ll x) const noexcept { Modint ans(1), cnt(num); if (x < 0) { cnt = inv(); x = -x; } while (x) { if (x & 1) ans *= cnt; cnt *= cnt; x >>= 1; } return ans; }
	inline constexpr ll val() const noexcept { return num; }
	static inline constexpr ll mod() { return MOD; }
};
std::istream& operator>>(std::istream& is, Modint& x){ ll a; is>>a; x = a; return is; }
inline constexpr Modint operator""_M(unsigned long long x) noexcept { return Modint(x); }
std::vector<Modint> fac_vec(1, 1), inv_vec(1, 1);
inline void reserve_fac_vec(size_t a){
	if(fac_vec.size() >= a) return;
	if(a < fac_vec.size() * 2) a = fac_vec.size() * 2;
	if(a >= (size_t)Modint::mod()) a = Modint::mod();
	fac_vec.reserve(a);
	while(fac_vec.size() < a) fac_vec.push_back(fac_vec.back() * Modint(fac_vec.size()));
	inv_vec.resize(fac_vec.size());
	inv_vec.back() = fac_vec.back().inv();
	for(ll i = inv_vec.size() - 1; !inv_vec[i - 1].val(); i--) inv_vec[i - 1] = inv_vec[i] * i;
}
inline Modint factorial(ll n){ if(n < 0) return 0; reserve_fac_vec(n + 1); return fac_vec[n]; }
inline Modint nPk(ll n, ll r){
	if(r < 0 || n < r) return 0;
	if(n >> 24){ Modint ans = 1; for(ll i = 0; i < r; i++) ans *= n--; return ans; }
	reserve_fac_vec(n + 1); return fac_vec[n] * inv_vec[n - r];
}
inline Modint nCk(ll n, ll r){ if(r < 0 || n < r) return 0; r = min(r, n - r); reserve_fac_vec(r + 1); return inv_vec[r] * nPk(n, r); }
inline Modint nHk(ll n, ll r){ return nCk(n + r - 1, n - 1); } 

inline Modint catalan(ll n){ reserve_fac_vec(n * 2 + 1); return fac_vec[n * 2] * inv_vec[n] * inv_vec[n + 1]; }



void solve() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];

	ll maxval = 0;
	map<ll, ll> m;

	{
		rep(i, N) m[a[i]]++, chmax(maxval, a[i]);
		if (m[maxval] == 1 && m[maxval - 1] == 0) {
			p(0);
			return;
		}
		if (m[maxval] > 1) {
			p(factorial(N));
			return;
		}
	}

	Modint ans = factorial(N);
	Modint dame = factorial(N) / factorial(m[maxval - 1] + 1) * factorial(m[maxval - 1]);
	ans -= dame;
	p(ans);
}

signed main() {
#ifndef LOCAL_DEV
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
#endif
	ll Q; cin >> Q; while(Q--)solve();
	

	return 0;
}
