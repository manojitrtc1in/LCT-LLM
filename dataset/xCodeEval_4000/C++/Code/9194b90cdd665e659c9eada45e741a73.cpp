#define _USE_MATH_DEFINES
#define _EXT_CODECVT_SPECIALIZATIONS_H 1
#define _EXT_ENC_FILEBUF_H 1
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;




using ll = long long;


constexpr ll MOD = 998244353; 



constexpr ll INF = std::numeric_limits<ll>::max() == INT_MAX ? (ll)1e9 + 7 : (ll)1e18;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
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
	#define vector dvector
	#define array darray
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
	#if __has_include(<ext/pb_ds/assoc_container.hpp>)
		template <typename Key, typename Compare> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>& se) {
			s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
		template <typename Key, typename T, typename Hash> std::ostream& operator<<(std::ostream& s, const __gnu_pbds::gp_hash_table<Key, T, Hash>& m) {
			s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	#endif
	void debug_impl() { std::cerr << '\n'; }
	template <typename Head, typename... Tail> void debug_impl(Head& head, Tail&... tail) { std::cerr << " " << head << (sizeof...(Tail) ? "," : ""); debug_impl(tail...); }
	template <typename Head, typename... Tail> void debug_impl(const Head& head, const Tail&... tail) { std::cerr << " " << head << (sizeof...(Tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << ":" << __LINE__ << " (" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return local; }
#else
	#define debug(...) do {} while (false)
	constexpr inline long long prodlocal([[maybe_unused]] long long prod, [[maybe_unused]] long long local) { return prod; }
#endif
#define repoverload3(_1, _2, _3, name, ...) name
#define rep3(i, a, b) for(ll i=(a), i##_length=(b); i<i##_length; ++i)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep3(i, 0, n)
#define rep(...) repoverload3(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define repeq3(i, a, b) rep3(i, (a)+1, (b)+1)
#define repeq2(i, n) rep3(i, 1, (n)+1)
#define repeq1(n) rep3(i, 1, (n)+1)
#define repeq(...) repoverload3(__VA_ARGS__, repeq3, repeq2, repeq1)(__VA_ARGS__)
#define rrep3(i, a, b) for(ll i=(b)-1; i>=(a); --i)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep1(n) rrep3(i, 0, n)
#define rrep(...) repoverload3(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define rrepeq3(i, a, b) rrep3(i, (a)+1, (b)+1)
#define rrepeq2(i, n) rrep3(i, 1, (n)+1)
#define rrepeq1(n) rrep3(i, 1, (n)+1)
#define rrepeq(...) repoverload3(__VA_ARGS__, rrepeq3, rrepeq2, rrepeq1)(__VA_ARGS__)
#define all(v) std::begin(v), std::end(v)
#define rall(v) std::rbegin(v), std::rend(v)
void p() { std::cout << '\n'; }
template <typename Head, typename... Tail> void p(Head& head, Tail&... tail) { std::cout << head << (sizeof...(Tail) ? " " : ""); p(tail...); }
template <typename Head, typename... Tail> void p(const Head& head, const Tail&... tail) { std::cout << head << (sizeof...(Tail) ? " " : ""); p(tail...); }
template <typename T> inline void pv(const T& v) { for(ll i=0, N=std::size(v); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template <typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template <typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template <typename T> inline void uniq(T& v) { std::sort(v.begin(), v.end()); v.erase(std::unique(v.begin(), v.end()), v.end()); }
template <typename T> inline ll sz(const T& v) { return std::size(v); }
template <typename T, std::size_t N> std::vector<T> make_vector_impl(std::vector<ll>& sizes, typename std::enable_if<(N==1), const T&>::type x) { return std::vector<T>(sizes.front(),x); }
template <typename T, std::size_t N> auto make_vector_impl(std::vector<ll>& sizes, typename std::enable_if<(N>1), const T&>::type x) { ll size=sizes.back(); sizes.pop_back(); return std::vector<decltype(make_vector_impl<T,N-1>(sizes,x))>(size,make_vector_impl<T,N-1>(sizes,x)); }
template <typename T, std::size_t N> auto make_vector(const ll (&sizes)[N], const T& x=T()) { std::vector<ll> s(N); for(std::size_t i=0; i<N; ++i)s[i]=sizes[N-1-i]; return make_vector_impl<T,N>(s,x); }
template <typename T, std::size_t N> std::array<T,N> make_array() { return std::array<T,N>{}; }
template <typename T, std::size_t Head, std::size_t... Tail, typename std::enable_if_t<(sizeof...(Tail)>=1), std::nullptr_t> = nullptr> auto make_array() { return std::array<decltype(make_array<T,Tail...>()),Head>(); }
#if __has_include(<ext/pb_ds/assoc_container.hpp>)
	class custom_hash {
	public:
		static uint64_t splitmix64(uint64_t x) {
			x += 0x9e3779b97f4a7c15, x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9, x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
		}
		std::size_t operator()(uint64_t x) const {
			static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);
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
#else
	template <typename Key, typename Mapped> using fmap = std::map<Key, Mapped>;
#endif
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






#ifdef __INTELLISENSE__
	#pragma diag_suppress 28
#endif
template <class Integral, ::std::size_t Bitlength, Integral None>
class WaveletMatrix {
public:
	using value_type = Integral;
	using size_type = ::std::size_t;
	static constexpr value_type none = None;

private:
	class bitvector {
		using bitfield = ::std::uint_least64_t;
		static constexpr ::std::size_t wordsize = 64;
		static ::std::size_t popcount(bitfield c) {
#ifdef __has_builtin
			return __builtin_popcountll(c);
#else
			c = (c & 0x5555555555555555ULL) + (c >> 1 & 0x5555555555555555ULL);
			c = (c & 0x3333333333333333ULL) + (c >> 2 & 0x3333333333333333ULL);
			c = (c + (c >> 4)) & 0x0F0F0F0F0F0F0F0FULL;
			return static_cast<::std::size_t>(c * 0x0101010101010101ULL >> 56 & 0x7f);
#endif
		}
		using value_type = typename WaveletMatrix::value_type;
		using size_type = typename WaveletMatrix::size_type;
		::std::vector<::std::pair<bitfield, size_type>> dic;

	public:
		size_type cnt;
		value_type bit;
		constexpr bitvector() : dic(), cnt(0), bit(0) {}
		bitvector(const size_type size, const value_type b)
				: dic(size / wordsize + 1, {0, 0}), cnt(0), bit(b) {}
		void set(const size_type index) {
			dic[index / wordsize].first |= static_cast<bitfield>(1) << (index % wordsize);
		}
		void build() {
			const size_type len = dic.size();
			for (size_type i = 1; i < len; ++i)
				dic[i].second = dic[i - 1].second + popcount(dic[i - 1].first);
		}
		size_type rank(const size_type last) const {
			return dic[last / wordsize].second +
						popcount(dic[last / wordsize].first &
							((static_cast<bitfield>(1) << (last % wordsize)) - 1));
		}
		bool access(const size_type index) const {
			return dic[index / wordsize].first >> (index % wordsize) & 1;
		}
	};
	static bool valid(const value_type value) {
		return value == none || !(value >> (Bitlength - 1) >> 1);
	}
	::std::array<bitvector, Bitlength> matrix;
	size_type size_;

	size_type at_least(size_type first, size_type last, const value_type value) const {
		assert(first <= size());
		assert(last <= size());
		assert(first <= last);
		size_type ret = 0;
		for (const auto &v : matrix) {
			const size_type l = v.rank(first), r = v.rank(last);
			if (value & v.bit) {
				first = l + v.cnt;
				last = r + v.cnt;
			} else {
				ret += r - l;
				first -= l;
				last -= r;
			}
		}
		return ret + last - first;
	}

public:
	constexpr WaveletMatrix() : matrix(), size_(0) {}
	template <class InputIter>
	WaveletMatrix(InputIter first, InputIter last) : matrix(), size_(0) {
		::std::vector<value_type> vec0(first, last);
		const size_type len = vec0.size();
		size_ = len;
		::std::vector<value_type> vec_l(len), vec_r(len);
		size_type l, r;
		value_type temp = static_cast<value_type>(1) << (Bitlength - 1);
		for (auto &v : matrix) {
			v = bitvector(len, temp);
			temp >>= 1;
			l = 0;
			r = 0;
			for (size_type j = 0; j < len; ++j)
				if (vec0[j] & v.bit)
					vec_r[r++] = vec0[j], v.set(j);
				else
					vec_l[l++] = vec0[j];
			v.cnt = l;
			v.build();
			::std::swap(vec0, vec_l);
			::std::copy(vec_r.cbegin(), vec_r.cbegin() + r, vec0.begin() + l);
		}
	}

	size_type size() const noexcept { return size_; }
	bool empty() const noexcept { return size() == 0; }

	value_type operator[](size_type index) const {
		assert(index < size());
		value_type ret = 0;
		for (const auto &v : matrix)
			if (v.access(index))
				ret |= v.bit, index = v.rank(index) + v.cnt;
			else
				index -= v.rank(index);
		return ret;
	}
	value_type at(const size_type index) const {
		if (index < size())
			return operator[](index);
		else
			throw ::std::out_of_range("index out of range");
	}

	size_type rank(size_type first, size_type last, const value_type value) const {
		assert(first <= size());
		assert(last <= size());
		assert(first <= last);
		assert(valid(value));
		for (const auto &v : matrix)
			if (value & v.bit)
				first = v.rank(first) + v.cnt, last = v.rank(last) + v.cnt;
			else
				first -= v.rank(first), last -= v.rank(last);
		return last - first;
	}
	value_type quantile(size_type first, size_type last, size_type k = 0, const value_type upper = none) const {
		assert(first <= size());
		assert(last <= size());
		assert(valid(upper));
		if (upper != none)
			k += at_least(first, last, upper);
		if (last - first <= k)
			return none;
		value_type ret = 0;
		for (const auto &v : matrix) {
			const size_type l = v.rank(first), r = v.rank(last);
			if (r - l > k)
				first = l + v.cnt, last = r + v.cnt, ret |= v.bit;
			else
				first -= l, last -= r, k -= r - l;
		}
		return ret;
	}
	value_type rquantile(const size_type first, const size_type last, size_type k = 0, const value_type lower = none) const {
		assert(first <= size());
		assert(last <= size());
		assert(first <= last);
		assert(valid(lower));
		if (lower != none)
			k += last - first - at_least(first, last, lower);
		if (last - first <= k)
			return none;
		return quantile(first, last, last - first - k - 1, none);
	}
	size_type rangefreq(const size_type first, const size_type last, const value_type lower, const value_type upper) const {
		assert(first <= size());
		assert(last <= size());
		assert(first <= last);
		assert(valid(lower));
		assert(valid(upper));
		assert(lower == none || upper == none || lower <= upper);
		size_type ret = lower == none ? last - first : at_least(first, last, lower);
		return upper == none ? ret : ret - at_least(first, last, upper);
	}

	

	

	value_type prev_value(size_type l, size_type r, value_type upper) {
		size_type cnt = rangefreq(l, r, None, upper);
		return cnt == 0 ? None : rquantile(l, r, cnt - 1);
	}

	

	

	value_type next_value(size_type l, size_type r, value_type lower) {
		size_type cnt = rangefreq(l, r, None, lower);
		return cnt == r - l ? None : rquantile(l, r, cnt);
	}
};



class RangeQuery {
	static const ll bitlength = 1 + (int)log2(4e5);
public:
	bool comp;
	vector<pair<ll, ll>> v;
	WaveletMatrix<ll, bitlength, -1> wm;
	vector<ll> compedy;
	bool isbuilt = false;

	RangeQuery(bool comp = false) : comp(comp) {}
	RangeQuery(const vector<pair<ll, ll>> &v, bool comp = false) : comp(comp), v(v) {}
	void add(ll x, ll y) {
		v.emplace_back(x, y);
	}
	void build() {
		isbuilt = true;
		sort(v.begin(), v.end());
		vector<ll> w(v.size());
		for (int i = 0; i < (int)v.size(); ++i) w[i] = v[i].second;
		if(comp){
			compedy = w;
			sort(compedy.begin(), compedy.end());
			compedy.erase(unique(compedy.begin(), compedy.end()), compedy.end());
			for (int i = 0; i < (int)v.size(); ++i) w[i] = lower_bound(compedy.begin(), compedy.end(), w[i]) - compedy.begin();
		}
		wm = WaveletMatrix<ll, bitlength, -1>(w.begin(), w.end());
	}
	

	ll query(ll x1, ll x2, ll y1, ll y2) {
		if (!isbuilt) build();
		auto ita = lower_bound(v.begin(), v.end(), pair<ll, ll>(x1, 0));
		ll a = ita - v.begin();
		auto itb = lower_bound(v.begin(), v.end(), pair<ll, ll>(x2, 0));
		ll b = itb - v.begin();
		if (comp) {
			y1 = lower_bound(compedy.begin(), compedy.end(), y1) - compedy.begin();
			y2 = lower_bound(compedy.begin(), compedy.end(), y2) - compedy.begin();
		}
		return wm.rangefreq(a, b, y1, y2);
	}
};



void solve() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	rep(i,N)cin>>a[i];
	fmap<ll, ll> m;
	RangeQuery seg(true);
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
#ifndef LOCAL_DEV
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
#endif
	ll Q; cin >> Q; while(Q--)solve();
	

	return 0;
}
