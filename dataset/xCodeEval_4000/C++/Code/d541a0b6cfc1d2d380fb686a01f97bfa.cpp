

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>




#pragma comment(linker, "/STACK:66777216")
#pragma warning(disable : 4996)
#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#pragma hdrstop














template <bool... Bools>
struct Disjunction : std::false_type {};

template <bool First, bool... Others>


struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {};

#if __cplusplus >= 201703L
template <bool... Bools>
constexpr bool DisjunctionV = Disjunction<Bools...>::value;

static_assert(!DisjunctionV<>, "");
static_assert(!DisjunctionV<false, false>, "");
static_assert(DisjunctionV<true>, "");
static_assert(DisjunctionV<false, true>, "");
static_assert(DisjunctionV<true, false>, "");
static_assert(DisjunctionV<false, false, true, true>, "");
#endif


#include <iterator>


template<typename T>
constexpr auto has_begin(int) -> decltype(std::begin(std::declval<T>()), true) {
	return true;
}

template<typename T>
constexpr bool has_begin(...) {
	return false;
}

template <typename T>
using is_container = std::integral_constant<bool, has_begin<T>(0)>;






template <typename T, typename... Types>




using is_one_of = Disjunction<std::is_same<T, Types>::value...>;







template <typename T>
using is_sane_integer = std::integral_constant<
		bool,
		std::is_integral<T>::value && !is_one_of<typename std::remove_cv<T>::type, char, signed char, unsigned char, bool, char16_t, char32_t, wchar_t>::value
>;


std::string to_string(const std::string& s) {
	return '"' + s + '"';
}

std::string to_string(const char* s) {
	return to_string(std::string(s));
}

std::string to_string(const char ch) {
	return {'\'', ch, '\''};
}

std::string to_string(const bool b) {
	return (b ? "true" : "false");
}

template<typename T, typename std::enable_if<Disjunction<is_sane_integer<T>::value, std::is_floating_point<T>::value>::value>::type* = nullptr>
std::string to_string(const T value) {
	return std::to_string(value);
}

template<typename A, typename B>
std::string to_string(const std::pair<A, B>&);

template<typename T, typename std::enable_if<is_container<T>::value>::type* = nullptr>
std::string to_string(const T& container) {
	bool is_first = true;
	std::string res = "{";
	for (const auto & x : container) {
		if (!is_first) {
			res += ", ";
		}
		is_first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template<typename A, typename B>
std::string to_string(const std::pair<A, B>& p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

std::vector<std::string> vec_splitter(std::string s) {
	s += ',';
	std::vector<std::string> res;
	while (!s.empty()) {
		const size_t pos = s.find(',');
		res.emplace_back(s.substr(0, pos));
		s = s.substr(pos + 1);
	}
	return res;
}

void debug_out(
		std::vector<std::string> __attribute__ ((unused)) args,
		__attribute__ ((unused)) int idx,
		__attribute__ ((unused)) int LINE_NUM)
{
	std::cerr << std::endl;
}

template<typename Head, typename... Tail>
void debug_out(std::vector<std::string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	std::stringstream ss;
	ss << to_string(H);
	if (idx > 0) {
		std::cerr << ", ";
	} else {
		std::cerr << "Line(" << LINE_NUM << ") ";
	}
	std::cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef HOME
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif





namespace std {

template<typename T>
std::istream& operator>>(std::istream& in, std::vector<T>& vec) {
	for (auto& it : vec) {
		in >> it;
	}
	return in;
}


template<typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& rhs) {
	in >> rhs.first >> rhs.second;
	return in;
}

}  


void assign_files_input_txt() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}








#include <cstddef>


template<typename T>
class IntegerIterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
public:
	using value_type = T;

	constexpr explicit IntegerIterator(const value_type value) : value_(value) {}

	IntegerIterator& operator++() {
		++value_;
		return *this;
	}

	IntegerIterator operator++(int) {
		IntegerIterator copy = *this;
		++value_;
		return copy;
	}

	IntegerIterator& operator--() {
		--value_;
		return *this;
	}

	IntegerIterator operator--(int) {
		IntegerIterator copy = *this;
		--value_;
		return copy;
	}

	constexpr value_type operator*() const {
		return value_;
	}

	constexpr bool operator ==(const IntegerIterator rhs) const {
		return value_ == rhs.value_;
	}

	constexpr bool operator !=(const IntegerIterator rhs) const {
		return !(*this == rhs);
	}

	constexpr value_type operator +(const IntegerIterator rhs) const {
		return value_ + rhs.value_;
	}

	IntegerIterator& operator +=(const IntegerIterator rhs) const {
		value_ += rhs.value_;
		return *this;
	}

	constexpr value_type operator -(const IntegerIterator rhs) const {
		return value_ - rhs.value_;
	}

	IntegerIterator& operator -=(const IntegerIterator rhs) const {
		value_ -= rhs.value_;
		return *this;
	}

private:
	value_type value_;
};


template<typename T>
class IntegerRange {
public:
	using const_iterator = IntegerIterator<T>;

	constexpr IntegerRange(const T begin, const T end) : begin_(begin), end_(end) {}

	constexpr const_iterator begin() const {
		return const_iterator(begin_);
	}

	constexpr const_iterator end() const {
		return const_iterator(end_);
	}

	constexpr T size() const {
		return end_ - begin_;
	}

private:
	T begin_;
	T end_;
};





template<typename T>
class ReversedRange {
public:
	using const_iterator = typename std::decay<T>::type::const_iterator;
	using reverse_iterator = std::reverse_iterator<const_iterator>;

	explicit constexpr ReversedRange(const T& iterable) : begin_(iterable.begin()), end_(iterable.end()) {}

	constexpr reverse_iterator begin() const {
		return reverse_iterator(end_);
	}

	constexpr reverse_iterator end() const {
		return reverse_iterator(begin_);
	}

private:
	const_iterator begin_;
	const_iterator end_;
};

template<typename T>
ReversedRange<T> reversed(T&& iterable) {
	return ReversedRange<T>{iterable};
}


template<typename T>
constexpr IntegerRange<T> range(const T to) {
	return IntegerRange<T>(0, to);
}

template<typename T>
constexpr IntegerRange<T> range(const T from, const T to) {
	return IntegerRange<T>(from, to);
}

template<typename T>
constexpr IntegerRange<T> inclusiveRange(const T to) {
	return IntegerRange<T>(0, to + 1);
}

template<typename T>
constexpr IntegerRange<T> inclusiveRange(const T from, const T to) {
	return IntegerRange<T>(from, to + 1);
}

template<typename T>
constexpr ReversedRange<IntegerRange<T>> downrange(const T from) {
	return reversed(range(from));
}

template<typename T>
constexpr ReversedRange<IntegerRange<T>> downrange(const T from, const T to) {
	return reversed(range(to, from));
}

template<typename T>
constexpr ReversedRange<IntegerRange<T>> inclusiveDownrange(const T from) {
	return reversed(range(from + 1));
}

template<typename T>
constexpr ReversedRange<IntegerRange<T>> inclusiveDownrange(const T from, const T to) {
	return reversed(range(to, from + 1));
}

template<typename R>
void sort(R& range) {
	std::sort(range.begin(), range.end());
}

template<typename R, typename Comp>
void sort(R& range, Comp comp) {
	std::sort(range.begin(), range.end(), comp);
}

template<typename R>
void reverse(R& range) {
	std::reverse(range.begin(), range.end());
}

template<typename R, typename T>
auto lower_bound(const R& range, const T& value) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value);
}

template<typename R, typename T, typename Comp>
auto lower_bound(const R& range, const T& value, Comp comp) -> decltype(range.begin()) {
	return std::lower_bound(range.begin(), range.end(), value, comp);
}

template<typename R, typename T>
auto upper_bound(const R& range, const T& value) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value);
}

template<typename R, typename T, typename Comp>
auto upper_bound(const R& range, const T& value, Comp comp) -> decltype(range.begin()) {
	return std::upper_bound(range.begin(), range.end(), value, comp);
}

template<typename R>
auto min_element(const R& range) -> decltype(range.begin()) {
	return std::min_element(range.begin(), range.end());
}

template<typename R>
auto max_element(const R& range) -> decltype(range.begin()) {
	return std::max_element(range.begin(), range.end());
}

template<typename R>
bool next_permutation(R& range) {
	return std::next_permutation(range.begin(), range.end());
}

template<typename T>
void unique(std::vector<T>& range) {
	range.erase(std::unique(range.begin(), range.end()), range.end());
}

template<typename T>
void dedup(std::vector<T>& range) {
	sort(range);
	unique(range);
}

template<typename R>
R sorted(R range) {
	sort(range);
	return range;
}

template<typename R, typename Comp>
R sorted(R range, Comp comp) {
	sort(range, comp);
	return range;
}



static constexpr long double PI = 3.14159265358979323846;
static constexpr long double EPS = 1e-9;
static constexpr int32_t INF = 0x3f3f3f3f;
static constexpr int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;

static constexpr int32_t DX[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
static constexpr int32_t DY[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

static constexpr uint32_t kDayMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

enum Direction : uint8_t {
	Up,
	Right,
	Down,
	Left,
	UpLeft,
	UpRight,
	DownRight,
	DownLeft,
	North = Up,
	East = Right,
	South = Down,
	West = Left,
	NorthWest = UpLeft,
	NorthEast = UpRight,
	SouthEast = DownRight,
	SouthWest = DownLeft,
	Unknown = 255
};


#include <cstdint>

















namespace Random {

inline std::chrono::system_clock::rep current_timestamp() {
	return std::chrono::system_clock::now().time_since_epoch().count();
}

inline uint64_t get_new_rand_seed() {
	return static_cast<uint64_t>(current_timestamp());
}

inline uint64_t get_rand_seed() {
	static const uint64_t kRandSeed = get_new_rand_seed();
	return kRandSeed;
}

using Engine = std::mt19937_64;

template<typename T>
using Distribution = std::uniform_int_distribution<T>;

inline Engine& random_engine() {
	static Engine engine(get_rand_seed());
	return engine;
}

template<typename T>
inline T get(const T to) {
	Distribution<T> distribution(0, to);
	return distribution(random_engine());
}

template<typename T>
inline T get(const T from, const T to) {
	return get(to - from) + from;
}

template<typename T = int32_t>
inline T get() {
	return get(static_cast<T>(0), std::numeric_limits<T>::max());
}

}  



template<typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
class SafeIntegralHash {
public:
	const T kRandomValue = static_cast<T>(Random::current_timestamp());

	T operator ()(const T& value) const {
		return value ^ kRandomValue;
	}
};

template<typename Key, typename Value, typename std::enable_if<std::is_integral<Key>::value>::type* = nullptr>
using SafeUnorderedMap = std::unordered_map<Key, Value, SafeIntegralHash<Key>>;

template<typename Key, typename Value, typename std::enable_if<std::is_integral<Key>::value>::type* = nullptr>
using SafeUnorderedMultiMap = std::unordered_multimap<Key, Value, SafeIntegralHash<Key>>;

template<typename Key, typename std::enable_if<std::is_integral<Key>::value>::type* = nullptr>
using SafeUnorderedSet = std::unordered_set<Key, SafeIntegralHash<Key>>;

template<typename Key, typename std::enable_if<std::is_integral<Key>::value>::type* = nullptr>
using SafeUnorderedMultiSet = std::unordered_multiset<Key, SafeIntegralHash<Key>>;





namespace std {

template<typename T, typename U>
struct hash<std::pair<T, U>> {
	std::size_t operator()(const std::pair<T, U>& pair) const {
		return pair.first * 877117 + pair.second;
	}
};

}  








template<typename T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
inline bool is_equal_to_zero(const T& a) {
	return abs(a) < EPS;
}

template<typename T, typename std::enable_if<!std::is_floating_point<T>::value>::type* = nullptr>
inline bool is_equal_to_zero(const T& a) {
	return a == 0;
}



#ifdef _MSC_VER
#include <intrin.h>
#define popcount(a) __popcnt(a)
#define clz(a) __clz(a)
#define ctz(a) __ctz(a)
#else
#define popcount(a) __builtin_popcount(a)
#define clz(a) __builtin_clz(a)
#define ctz(a) __builtin_ctz(a)
#endif

template<typename T>
inline bool umin(T& a, const T& b) {
	return (b < a ? a = b, true : false);
}

template<typename T>
inline bool umax(T& a, const T& b) {
	return (a < b ? a = b, true : false);
}

#ifdef _MSC_VER
static uint32_t __inline __clz(uint32_t x) {
	unsigned long r = 0;
	_BitScanReverse(&r, x);
	return (31 - r);
}

static uint32_t __inline __ctz(uint32_t x) {
	unsigned long r = 0;
	_BitScanForward(&r, x);
	return r;
}
#endif

template<typename T, size_t N>
struct MakeVector {
	template<typename... Args,
		typename R = std::vector<decltype(MakeVector<T, N - 1>::make_vector(std::declval<Args>()...)) >>
		static R make_vector(size_t first, Args... sizes) {
		auto inner = MakeVector<T, N - 1>::make_vector(sizes...);
		return R(first, inner);
	}
};

template<typename T>
struct MakeVector<T, 1> {
	

	template<typename R = std::vector<T>>
	static R make_vector(std::size_t size, const T& value) {
		return R(size, value);
	}
};

template<typename T, typename... Args>
auto make_vector(Args... args) -> decltype(MakeVector<T, sizeof...(Args)-1>::make_vector(args...)) {
	return MakeVector<T, sizeof...(Args)-1>::make_vector(args...);
}

template<typename T>
inline bool is_leap_year(const T year) {
	return year % 400 == 0 || (year % 100 != 0 && (year & 3) == 0);
}

inline size_t get_days_in_month(const size_t month, const size_t year) {
	return kDayMonth[month] + (month == 1 && is_leap_year(year) ? 1 : 0);
}

#define fill(a, x) memset(a, x, sizeof(a))
#define X first
#define Y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()





#ifdef _MSC_VER
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

using ll = int64_t;
using ull = uint64_t;
using uint = uint32_t;
using ld = long double;

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using pli = std::pair<ll, int>;

using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vp = std::vector<pii>;









class StringView {
public:
	using iterator = const char*;

	

	constexpr StringView() : data_(nullptr), length_(0) {}

	constexpr StringView(const StringView&) = default;
	constexpr StringView(StringView&&) = default;
	StringView& operator =(const StringView&) = default;
	StringView& operator =(StringView&&) = default;

	StringView(const char* begin, const char* end) : data_(begin), length_(static_cast<size_t>(end - begin)) {}
	StringView(const char* data, size_t length) : data_(data), length_(length) {}
	StringView(const char* data) : data_(data), length_(strlen(data)) {}
	StringView(const std::string& data) : data_(data.c_str()), length_(data.length()) {}

	constexpr char operator[](const size_t index) const {
		return data_[index];
	}

	constexpr const char* data() const {
		return data_;
	}

	constexpr const char* c_str() const {
		return data_;
	}

	constexpr size_t length() const {
		return length_;
	}

	constexpr size_t size() const {
		return length_;
	}

	constexpr bool empty() const {
		return length_ == 0;
	}

	constexpr char front() const {
		return data_[0];
	}

	constexpr char back() const {
		return data_[length_ - 1];
	}

	std::string to_string() const {
		return{ begin(), end() };
	}

	constexpr iterator begin() const {
		return data_;
	}

	constexpr iterator end() const {
		return data_ + length_;
	}

	StringView substr(const size_t pos) const {
		return StringView(data_ + pos, length_ - pos);
	}

	StringView substr(const size_t pos, const size_t len) const {
		return StringView(data_ + pos, len);
	}

	size_t find(const char ch, const size_t pos) const {
		for (size_t i = pos; i < length_; ++i) {
			if (data_[i] == ch) {
				return i;
			}
		}
		return std::string::npos;
	}

	std::string operator +(const StringView& rhs) const;

	friend bool operator ==(const StringView& lhs, const StringView& rhs);
	friend bool operator ==(const StringView& lhs, const char* rhs);
	friend bool operator ==(const char* lhs, const StringView& rhs);
	friend bool operator !=(const StringView& lhs, const StringView& rhs);
	friend bool operator !=(const StringView& lhs, const char* rhs);
	friend bool operator !=(const char* lhs, const StringView& rhs);

private:
	const char* data_;
	size_t length_;
};

bool operator ==(const StringView& lhs, const StringView& rhs) {
	if (lhs.length_ != rhs.length_) {
		return false;
	}
	for (size_t i = 0; i < lhs.length_; ++i) {
		if (lhs.data_[i] != rhs.data_[i]) {
			return false;
		}
	}
	return true;
}

bool operator ==(const StringView& lhs, const char* rhs) {
	for (size_t i = 0; i < lhs.length_; ++i) {
		if (rhs[i] == 0 || rhs[i] != lhs.data_[i]) {
			return false;
		}
	}
	return rhs[lhs.length_] == 0;
}

bool operator ==(const char* lhs, const StringView& rhs) {
	return rhs == lhs;
}

bool operator !=(const StringView& lhs, const StringView& rhs) {
	return !(lhs == rhs);
}

bool operator !=(const StringView& lhs, const char* rhs) {
	return !(lhs == rhs);
}

bool operator !=(const char* lhs, const StringView& rhs) {
	return !(rhs == lhs);
}


std::vector<std::size_t> prefix_function(const StringView& string) {
	std::vector<std::size_t> p(string.length(), 0);
	for (std::size_t i = 1; i < string.length(); ++i) {
		std::size_t j = p[i - 1];
		while (j > 0 && string[i] != string[j]) {
			j = p[j - 1];
		}
		if (string[i] == string[j]) {
			++j;
		}
		p[i] = j;
	}
	return p;
}


class CBegovoiTrek {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;
	void solve(std::istream& in, std::ostream& out) {
		std::string s, t;
		in >> s >> t;

		const std::string s_reversed(all(reversed(s)));

		const int n = t.length();
		std::vector<int> dp(n + 1, INF);
		std::vector<pii> prev(n + 1, {-1, -1});

		dp[0] = 0;
		std::string tmp = t + "#" + s;
		std::string tmp_reversed = t + "#" + s_reversed;
		size_t s_start = n + 1;
		for (int i : range(n)) {
			auto p = prefix_function(tmp);
			debug(i);
			debug(p);
			for (int j : range(s_start, tmp.size())) {
				const int p_value = p[j];
				if (p_value > 0) {
					if (umin(dp[i + p_value], dp[i] + 1)) {
						prev[i + p_value] = {j - p_value + 1 - s_start, j - s_start};
					}
				}
			}
			auto pr = prefix_function(tmp_reversed);
			debug(pr);
			debug(tmp_reversed);
			for (int j : range(s_start, tmp_reversed.size())) {
				const int p_value = pr[j];
				if (p_value > 0) {
					if (umin(dp[i + p_value], dp[i] + 1)) {
						if (i + p_value == n) {
							debug(i + p_value, dp[i + p_value], j, s_start, j - s_start, j - s_start - p_value + 1);
						}
						prev[i + p_value] = {s.length() - 1 - (j - p_value + 1 - s_start), s.length() - 1 - (j - s_start)};
					}
				}
			}
			tmp = tmp.substr(1);
			tmp_reversed = tmp_reversed.substr(1);
			--s_start;
		}
		debug(dp);

		if (dp[n] == INF) {
			out << -1 << std::endl;
			return;
		}
		std::vector<pii> ans;
		int pos = n;
		while (pos > 0) {
			const int len = std::abs(prev[pos].X - prev[pos].Y) + 1;
			ans.emplace_back(prev[pos]);
			pos -= len;
		}
		out << ans.size() << std::endl;
		for (const auto& it : reversed(ans)) {
			out << it.X + 1 << " " << it.Y + 1 << std::endl;
		}
	}


	CBegovoiTrek() {}


	static constexpr bool kUseCustomChecker = false;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static void generate_test(std::ostream& test) {}

};


int main() {
	CBegovoiTrek solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (CBegovoiTrek::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (CBegovoiTrek::kWriteCaseNumber) {
				out << "Case #" << test_id << ": ";
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
