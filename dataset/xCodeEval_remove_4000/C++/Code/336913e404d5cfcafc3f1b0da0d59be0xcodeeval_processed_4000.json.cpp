




using namespace std;




using ll = long long;


constexpr ll MOD = 998244353; 



constexpr ll INF = std::numeric_limits<ll>::max() == INT_MAX ? (ll)1e9 + 7 : (ll)1e18;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};

	
	
	
	


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
		template <typename T, std::size_t N> class darray : public std::array<T, N> {
		public:
			using std::array<T, N>::array;
			darray(std::initializer_list<T> il) {
				*this = {}; int i = 0; for (auto&& x : il) this->operator[](i++) = x;
			}
			T& operator[](std::size_t n) {
				if (this->size() <= n) { std::cerr << boost::stacktrace::stacktrace() << '\n' << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")" << '\n'; } return this->at(n);
			}
			const T& operator[](std::size_t n) const {
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
	template <typename T, typename Compare> std::ostream& operator<<(std::ostream& s, const std::set<T, Compare>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T, typename Compare> std::ostream& operator<<(std::ostream& s, const std::multiset<T, Compare>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T1, typename T2, typename Compare> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2, Compare>& m) {
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
	template <typename Head, typename... Tail> void debug_impl(Head& head, Tail&... tail) { std::cerr << " " << head << (sizeof...(Tail) ? "," : ""); debug_impl(tail...); }
	template <typename Head, typename... Tail> void debug_impl(const Head& head, const Tail&... tail) { std::cerr << " " << head << (sizeof...(Tail) ? "," : ""); debug_impl(tail...); }
	
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return local; }

	
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return prod; }




















void p() { std::cout << '\n'; }
template <typename Head, typename... Tail> void p(Head& head, Tail&... tail) { std::cout << head << (sizeof...(Tail) ? " " : ""); p(tail...); }
template <typename Head, typename... Tail> void p(const Head& head, const Tail&... tail) { std::cout << head << (sizeof...(Tail) ? " " : ""); p(tail...); }
template <typename T> inline void pv(const T& v) { for(ll i=0, N=std::size(v); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template <typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template <typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template <typename T> inline void uniq(T& v) { std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end()); }
template <typename T> inline ll sz(const T& v) { return std::size(v); }
template <typename T, std::size_t N> std::vector<T> id0(std::vector<ll>& sizes, typename std::enable_if<(N==1), const T&>::type x) { return std::vector<T>(sizes.front(),x); }
template <typename T, std::size_t N> auto id0(std::vector<ll>& sizes, typename std::enable_if<(N>1), const T&>::type x) { ll size=sizes.back(); sizes.pop_back(); return std::vector<decltype(id0<T,N-1>(sizes,x))>(size,id0<T,N-1>(sizes,x)); }
template <typename T, std::size_t N> auto make_vector(const ll (&sizes)[N], const T& x=T()) { std::vector<ll> s(N); for(std::size_t i=0; i<N; ++i)s[i]=sizes[N-1-i]; return id0<T,N>(s,x); }
template <typename T, std::size_t N> std::array<T,N> make_array() { return std::array<T,N>{}; }
template <typename T, std::size_t Head, std::size_t... Tail, typename std::enable_if_t<(sizeof...(Tail)>=1), std::nullptr_t> = nullptr> auto make_array() { return std::array<decltype(make_array<T,Tail...>()),Head>(); }

	class custom_hash {
	public:
		static uint64_t splitmix64(uint64_t x) {
			x += 0x9e3779b97f4a7c15, x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9, x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
		}
		std::size_t operator()(uint64_t x) const {
			static const uint64_t id1 = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + id1);
		}
		std::size_t operator()(const string& x) const {
			return std::hash<std::string>()(x);
		}
	};
	template <typename Key, typename Mapped, typename Hash = custom_hash, typename std::enable_if_t<std::is_integral_v<Key> || std::is_same_v<Key, string>, std::nullptr_t> = nullptr> class fmap : public __gnu_pbds::gp_hash_table<Key, Mapped, Hash> {
	public:
		using __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::gp_hash_table;
		template <typename T> fmap(std::initializer_list<std::initializer_list<T>> il) : __gnu_pbds::gp_hash_table<Key, Mapped, Hash>() {
			for (auto&& x : il) __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::insert(std::pair<Key, Mapped>(*x.begin(), *(x.begin() + 1)));
		}
		template <typename T> ll count(const T& x) const {
			return __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::find(x) != __gnu_pbds::gp_hash_table<Key, Mapped, Hash>::end();
		}
	};

	template <typename Key, typename Mapped> using fmap = std::map<Key, Mapped>;

template <bool Index, typename... T> class zip_helper {
	class zip_iterator : std::iterator<std::forward_iterator_tag, std::tuple<decltype(*std::declval<T>().begin())...>> {
	public:
		ll idx_;
		std::tuple<decltype(std::declval<T>().begin())...> iters_;
		template <std::size_t... I> auto deref(std::index_sequence<I...>) const { return typename zip_iterator::value_type{*std::get<I>(iters_)...}; }
		template <std::size_t... I> void increment(std::index_sequence<I...>) { [[maybe_unused]] auto l = {(++std::get<I>(iters_), 0)...}; }
		explicit zip_iterator(decltype(iters_) iters) : idx_(0), iters_{std::move(iters)} {}
		zip_iterator& operator++() { ++idx_; increment(std::index_sequence_for<T...>{}); return *this; }
		zip_iterator operator++(int) { auto saved{*this}; ++idx_; increment(std::index_sequence_for<T...>{}); return saved; }
		bool operator!=(const zip_iterator& other) const { return iters_ != other.iters_; }
		template <bool Index_ = Index, typename std::enable_if_t<Index_, std::nullptr_t> = nullptr> auto operator*() const { return std::tuple_cat(std::make_tuple(this->idx_), this->deref(std::index_sequence_for<T...>{})); }
		template <bool Index_ = Index, typename std::enable_if_t<!Index_, std::nullptr_t> = nullptr> auto operator*() const { return this->deref(std::index_sequence_for<T...>{}); }
	};
public:
	zip_helper(T&... seqs) : begin_{std::make_tuple(seqs.begin()...)}, end_{std::make_tuple(seqs.end()...)} {}
	zip_iterator begin() const { return begin_; }
	zip_iterator end() const { return end_; }
	zip_iterator begin_, end_;
};
template <typename... T> auto zip(T&&... seqs) { return zip_helper<false, T...>{seqs...}; }
template <typename... T> auto zipindex(T&&... seqs) { return zip_helper<true, T...>{seqs...}; }







class RangeSet {
public:
	vector<pair<ll, ll>> a;
	vector<vector<ll>> data;
	vector<ll> x;
	int siz_x = 1;
	bool isbuilt = false;

	RangeSet() {}
	RangeSet(const vector<pair<ll, ll>> &v) : a(v) {}
	void add(ll x, ll y){
		a.emplace_back(x, y);
	}
	void build() {
		isbuilt = true;
		sort(a.begin(), a.end());
		if(a.size()) x.emplace_back(a[0].first);
		for(auto& i : a) if(x.back() != i.first) x.emplace_back(i.first);
		while((int)x.size() > siz_x) siz_x <<= 1;
		while((int)x.size() < siz_x) x.emplace_back(INF);
		data.resize(siz_x << 1);
		int at = 0;
		for(auto& i : a){
			if(x[at] != i.first) at++;
			data[siz_x + at].emplace_back(i.second);
		}
		for(int i = siz_x; --i; ){
			data[i].resize(data[i << 1].size() + data[(i << 1) | 1].size());
			merge(data[i << 1].begin(), data[i << 1].end(), data[(i << 1) | 1].begin(), data[(i << 1) | 1].end(), data[i].begin());
		}
	}
	

	ll query(ll x1, ll x2, ll y1, ll y2) {
		if (!isbuilt) build();
		if (x1 >= x2 || y1 >= y2) return 0;
		int l = lower_bound(x.begin(), x.end(), x1) - x.begin(), r = lower_bound(x.begin(), x.end(), x2) - x.begin();
		l += siz_x; r += siz_x;
		ll ans = 0;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1){
				ans += lower_bound(data[l].begin(), data[l].end(), y2) - lower_bound(data[l].begin(), data[l].end(), y1);
				l++;
			}
			if(r & 1){
				r--;
				ans += lower_bound(data[r].begin(), data[r].end(), y2) - lower_bound(data[r].begin(), data[r].end(), y1);
			}
		}
		return ans;
	}
};



void solve() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	rep(i,N)cin>>a[i];
	fmap<ll, ll> m;
	RangeSet seg;
	const ll geta = 3e5;
	vector<ll> b(N);
	rep(i, N) {
		b[i] = geta * a[i] - m[a[i]];
		m[a[i]]++;
		seg.add(i, b[i]);
	}

	debug(b);
	ll ans = 0;
	rep(i,N){
		ll t = seg.query(0, i, b[i] + 1, INF);
		ans += t;
	}
	p(ans);
	debug(ans);
	

	

}

signed main() {

	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	ll Q; cin >> Q; while(Q--)solve();
	

	return 0;
}
