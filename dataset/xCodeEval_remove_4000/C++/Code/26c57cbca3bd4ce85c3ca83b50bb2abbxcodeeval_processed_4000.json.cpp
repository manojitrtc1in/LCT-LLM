


using namespace std;



	
	
	
	


	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			template <typename Itr> dvector(const Itr first, const Itr last) : std::vector<T>(first, last) {}
			template <typename T_ = T, typename std::enable_if_t<std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			std::vector<bool>::reference operator[](size_t n) {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
			template <typename T_ = T, typename std::enable_if_t<std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			const T_ operator[](size_t n) const {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
			template <typename T_ = T, typename std::enable_if_t<!std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			T_& operator[](size_t n) {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
			template <typename T_ = T, typename std::enable_if_t<!std::is_same_v<T_, bool>, std::nullptr_t> = nullptr>
			const T_& operator[](size_t n) const {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
		};
		template<typename T, typename Compare = std::less<T>, typename Allocator = std::allocator<T>> class id4 : public std::multiset<T,Compare,Allocator> {
		public:
			id4() : std::multiset<T,Compare,Allocator>() {}
			id4(const std::multiset<T,Compare,Allocator>& m) : std::multiset<T,Compare,Allocator>(m) {}
			id4(const std::initializer_list<T> il) : std::multiset<T,Compare,Allocator>(il) {}
			id4(const Compare& comp) : std::multiset<T,Compare,Allocator>(comp) {}
			const typename std::multiset<T,Compare,Allocator>::iterator erase(const typename std::multiset<T,Compare,Allocator>::iterator it) {
				return std::multiset<T,Compare,Allocator>::erase(it);
			}
			size_t erase([[maybe_unused]] const T& x) {
				std::cerr << boost::stacktrace::stacktrace() << '\n'; assert(false);
			}
			size_t erase_all_elements(const T& x) {
				return std::multiset<T,Compare,Allocator>::erase(x);
			}
		};
	}
	
	
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void id2([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void id3([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, id2); signal(SIGSEGV, id3); return convertedmain(); }
	

	


	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {
		s << "\\\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return local; }

	
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return prod; }



using ll = long long;


constexpr ll INF = numeric_limits<ll>::max() == INT_MAX ? (ll)1e9 + 7 : (ll)1e18;
constexpr ll MOD = (ll)1e9 + 7; 



constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};






void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }
template<typename T> inline ll sz(T& v) { return v.size(); }
template<typename T, size_t N> std::vector<T> id1(std::vector<ll>& sizes, typename std::enable_if<(N==1), T const&>::type x) { return std::vector<T>(sizes.front(),x); }
template<typename T, size_t N> auto id1(std::vector<ll>& sizes, typename std::enable_if<(N>1), T const&>::type x) { ll size=sizes.back(); sizes.pop_back(); return std::vector<decltype(id1<T,N-1>(sizes,x))>(size,id1<T,N-1>(sizes,x)); }
template<typename T, size_t N> auto makevector(ll const (&sizes)[N], T const& x=T()) { std::vector<ll> s(N); for(size_t i=0; i<N; ++i)s[i]=sizes[N-1-i]; return id1<T,N>(s,x); }










constexpr ll MAXVAL = 2e7+1;
constexpr int BITS = (sizeof(int) * 8);
constexpr int FLAGS_NUM = (MAXVAL / BITS + 1);
class id0 {
public:
	

	vector<ll> primes;
	

	vector<bool> isprime;
	

	vector<ll> min_factor;
private:
	inline void upflag(int *flags, int BITS, int i) {
		flags[i / BITS] |= 1 << (i % BITS);
	}
	inline int getflag(int *flags, int BITS, int i) {
		return (flags[i / BITS] >> (i % BITS)) & 1;
	}
	inline void setprime(int x) {
		primes.push_back(x);
		isprime[x] = true;
		min_factor[x] = x;
	}
	inline void setcomposite(int x, int factorval) {
		if(min_factor[x] == -1) min_factor[x] = factorval;
	}
public:
	id0() : primes(), isprime(MAXVAL+1, false), min_factor(MAXVAL+1, -1) {
		int flags[FLAGS_NUM] = {};
		int i, j, f, s;
		int max = (int)sqrt(MAXVAL) + 1;
		setcomposite(0,0);
		setcomposite(1,1);
		setprime(2);
		setprime(3);
		for (i = 4; i<=MAXVAL; i+=2) setcomposite(i,2);
		for (i = 9; i<=MAXVAL; i+=6) setcomposite(i,3);
		for (i = 5, f = 4; i <= max; i += (f = 6 - f)) {
			if (!getflag(flags,BITS,i)) {
				setprime(i);
				s = MAXVAL / i;
				for (j = s - !(s & 1); j >= i; j -= 2) {
					if (!getflag(flags,BITS,i)){
						upflag(flags,BITS,i*j);
						setcomposite(i*j,i);
					}
				}
			}
		}
		for (; i <= MAXVAL; i += (f = 6 - f)){
			if (!getflag(flags,BITS,i)){
				setprime(i);
			}
		}
	}

	

	map<ll,ll> prime_factorize(ll n) {
		map<ll,ll> res;
		while (n != 1) {
			ll prime = min_factor[n];
			ll exp = 0;
			while (min_factor[n] == prime) {
				++exp;
				n /= prime;
			}
			res[prime]=exp;
		}
		return res;
	}

	

	

	vector<ll> divisor(ll n){
		vector<ll> res;
		map<ll,ll> m=prime_factorize(n);
		ll N=m.size();
		vector<pair<ll,ll>> v(N);
		ll i=0;
		for(auto&& pr:m){
			v[i]=pr;
			i++;
		}
		auto f=[&](auto&& f, ll index, ll val){
			if(index==N){
				res.push_back(val);return;
			}
			f(f,index+1,val);
			for(ll i=0; i<v[index].second; i++){
				val*=v[index].first;
				f(f,index+1,val);
			}
		};
		f(f,0,1);
		

		return res;
	}
};






template<typename T> inline T power(T a, ll b) {
	if(b < 0){ a = T(1) / a; b = -b; } T res = 1; while(b){ if(b & 1)res *= a; b >>= 1; if(b)a = a * a; } return res;
}
template<typename T> inline T power(T a, ll b, ll mod) {
	if(b < 0){ a = T(1) / a; b = -b; } T res = 1; a %= mod; while(b){ if(b & 1)res = res * a % mod; b >>= 1; if(b)a = a * a % mod; } return res;
}

void solve() {
	id0 er = id0();

	vector<ll> cache(2e7 + 1);
	rep(i, cache.size()) cache[i] = er.isprime[i];
	rep(i, cache.size()){
		if (cache[i] || i<4) continue;
		cache[i] = cache[i / er.min_factor[i]];
		cache[i] += er.min_factor[i] != er.min_factor[i / er.min_factor[i]];
	}

	ll Q;
	cin >> Q;
	while (Q--) {
		ll C, D, X;
		cin >> C >> D >> X;
		vector<ll> div = er.divisor(X);
		ll ans = 0;
		for (auto&& G : div){
			if((G + D) % C)continue;
			ll N = (G + D) / C;
			ll t = power(2LL,cache[N]);
			ans += t;
		}
		p(ans);
	}
}

signed main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	

	solve();
	return 0;
}
