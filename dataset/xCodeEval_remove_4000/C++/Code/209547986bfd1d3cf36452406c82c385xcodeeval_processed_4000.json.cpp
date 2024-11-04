


using namespace std;



	
	
	
	


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
	
	
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void id2([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void id3([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, id2); signal(SIGSEGV, id3); return convertedmain(); }
	

	


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
	template <typename T, std::size_t N, std::size_t M, typename std::enable_if_t<!std::is_same_v<T, char>, std::nullptr_t> = nullptr> std::ostream& operator<<(std::ostream& s, const T (&vv)[N][M]) {
		s << "\\\n"; for (std::size_t i = 0; i < N; ++i){ s << vv[i] << "\n"; } return s; }
	
		template <typename Key, typename Compare> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& se) {
			s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
		template <typename Key, typename T, typename Hash> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::gp_hash_table<Key, T, Hash>& m) {
			s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	
	void debug_impl() { std::cerr << '\n'; }
	template <typename Head, typename... Tail> void debug_impl(const Head& head, const Tail&... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return local; }

	
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return prod; }





using ll = int;


constexpr ll INF = std::numeric_limits<ll>::max() == INT_MAX ? (ll)1e9 + 7 : (ll)1e18;
constexpr ll MOD = (ll)1e9 + 7; 



constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};



















void p() { std::cout << '\n'; }
template <typename Head, typename... Tail> void p(const Head& head, const Tail&... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template <typename T> inline void pv(const std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template <typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template <typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template <typename T> inline void uniq(std::vector<T>& v) { std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end()); }
template <typename T> inline ll sz(const T& v) { return std::size(v); }
template <typename T, std::size_t N> std::vector<T> id0(std::vector<ll>& sizes, typename std::enable_if<(N==1), const T&>::type x) { return std::vector<T>(sizes.front(),x); }
template <typename T, std::size_t N> auto id0(std::vector<ll>& sizes, typename std::enable_if<(N>1), const T&>::type x) { ll size=sizes.back(); sizes.pop_back(); return std::vector<decltype(id0<T,N-1>(sizes,x))>(size,id0<T,N-1>(sizes,x)); }
template <typename T, std::size_t N> auto make_vector(const ll (&sizes)[N], const T& x=T()) { std::vector<ll> s(N); for(std::size_t i=0; i<N; ++i)s[i]=sizes[N-1-i]; return id0<T,N>(s,x); }

	template <typename Key, typename Mapped, typename Hash = std::hash<Key>, typename std::enable_if_t<std::is_integral_v<Key>, std::nullptr_t> = nullptr> struct fmap : public __gnu_pbds::gp_hash_table<Key, Mapped, Hash> {
		using __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::gp_hash_table;
		template <typename T> fmap(std::initializer_list<std::initializer_list<T>> il) : __gnu_pbds::gp_hash_table<Key, Mapped, Hash>() {
			for (auto&& x : il) __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::insert(std::pair<Key, Mapped>(*x.begin(), *(x.begin() + 1)));
		}
		template <typename T> ll count(const T& x) const {
			return __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::find(x) != __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::end();
		}
	};

	template <typename Key, typename Mapped> using fmap = std::map<Key, Mapped>;

template <typename T> struct id1 {
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
	id1(T& t): _container(t) {}
	iterator begin() const { return iterator(_container.begin()); }
	iterator end() const { return iterator(_container.end()); }
};
template <typename T> id1<T> each(T& t) { return id1<T>(t); } 

template <typename... T> class zip_helper {
public:
	class iterator : std::iterator<std::forward_iterator_tag, std::tuple<decltype(*std::declval<T>().begin())...>> {
	private:
		std::tuple<decltype(std::declval<T>().begin())...> iters_;
		template <std::size_t... I> auto deref(std::index_sequence<I...>) const { return typename iterator::value_type{*std::get<I>(iters_)...}; }
		template <std::size_t... I> void increment(std::index_sequence<I...>) { [[maybe_unused]] auto l = {(++std::get<I>(iters_), 0)...}; }
	public:
		explicit iterator(decltype(iters_) iters) : iters_{std::move(iters)} {}
		iterator& operator++() { increment(std::index_sequence_for<T...>{}); return *this; }
		iterator operator++(int) { auto saved{*this}; increment(std::index_sequence_for<T...>{}); return saved; }
		bool operator!=(const iterator& other) const { return iters_ != other.iters_; }
		auto operator*() const { return deref(std::index_sequence_for<T...>{}); }
	};
	zip_helper(T&... seqs) : begin_{std::make_tuple(seqs.begin()...)}, end_{std::make_tuple(seqs.end()...)} {}
	iterator begin() const { return begin_; }
	iterator end() const { return end_; }
private:
	iterator begin_, end_;
};
template <typename... T> auto zip(T&&... seqs) { return zip_helper<T...>{seqs...}; } 






void solve() {
	ll N;
	cin >> N;
	vector<vector<ll>> A(N);
	vector<ll> K(N);
	rep(i, N) {	
		cin >> K[i];
		A[i].resize(K[i]);
		rep(j, K[i]) cin >> A[i][j];
	}
	ll M;
	cin >> M;
	vector<array<ll,11>> B(M,array<ll,11>{});
	rep(i, M) {
		

		repeq(j, N) cin >> B[i][j], B[i][j]--;
		repeq(j, N) B[i][0] += A[j-1][B[i][j]];
	}
	debug(B);
	vector<array<ll,11>> s;
	rep(i, M) s.emplace_back(B[i]);
	uniq(s);

	set<array<ll,11>> q;
	array<ll,11> L{};
	

	repeq(i, N) L[i] = K[i-1]-1;
	rep(i, N) L[0] += A[i].back();
	debug(L);
	q.emplace(L);

	while (1) {
		array<ll,11> v = *prev(end(q));
		q.erase(prev(end(q)));
		debug(v);
		if(!binary_search(all(s),v)){
			repeq(i, N) cout << v[i]+1 << " \n"[i == N];
			return;
		}
		ll bk = v[0];
		repeq(i, N) {
			if (v[i] == 0) continue;
			v[0] = bk;
			v[0] -= A[i - 1][v[i]];
			v[i]--;
			v[0] += A[i - 1][v[i]];
			q.emplace(v);
			v[i]++;
		}
	}

}

signed main() {

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	

	solve();
	return 0;
}
