

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













template<typename T>
inline T gcd(T a, T b) {
	while (b != 0) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

template<typename T>
inline T lcm(const T& a, const T& b) {
	return a / gcd(a, b) * b;
}

template<typename T>
constexpr inline T sqr(const T& x) {
	return x * x;
}

template<typename T>
T factorial(T n) {
	T ret = 1;
	for (int i = 2; i <= n; ++i) {
		ret *= i;
	}
	return ret;
}

template<typename T, typename U>
inline T binpow(T a, U b) {
	static_assert(std::is_integral<U>::value, "Degree must be integral. For real degree use pow.");
	T ret = 1;
	while (b != 0) {
		if ((b & 1) != 0) {
			ret *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ret;
}

template<typename T, typename U, typename Q>
inline T binpow(T a, U b, Q mod) {
	static_assert(std::is_integral<U>::value, "Degree must be integral. For real degree use pow.");
	long long ret = 1;
	a %= mod;
	while (b != 0) {
		if ((b & 1) != 0) {
			ret = ret * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ret % mod;
}

template<typename T>
T digit_sum(const T n) {
	T res = 0;
	T tmp = abs(n);
	while (tmp > 0) {
		res += tmp % 10;
		tmp /= 10;
	}
	return res;
}

template<typename T>
std::vector<size_t> digits(const T n) {
	if (n == 0) {
		return{ 0 };
	}
	std::vector<size_t> res;
	T tmp = abs(n);
	while (tmp > 0) {
		res.emplace_back(tmp % 10);
		tmp /= 10;
	}
	return res;
}

template<typename T>
size_t digit_count(const T n) {
	return digits(n).size();
}

template<typename T>
std::vector<T> divisors_vector(const T n) {
	const auto approximate_divisors_count = static_cast<size_t>(cbrt(n));
	std::vector<T> ans;
	ans.reserve(approximate_divisors_count);
	const auto floored_square_root = static_cast<T>(sqrt(n));
	for (T i = 1; i <= floored_square_root; ++i) {
		if (n % i == 0) {
			ans.emplace_back(i);
			if (n / i != i) {
				ans.emplace_back(n / i);
			}
		}
	}
	return ans;
}

template<typename T>
T euler_function(T n) {
	T res = n;
	for (T i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			res -= res / i;
		}
	}
	if (n > 1) {
		res -= res / n;
	}
	return res;
}

template<typename T, typename U>
T inverse_element(const T n, const U mod)


{
	return binpow(static_cast<long long>(n), mod - 2, mod);
}

inline void inverseElementForSegment(int r[], const int n, const int mod)


{
	r[1] = 1;
	for (int i = 2; i < n; ++i) {
		r[i] = (mod - static_cast<long long>(mod) / i * r[mod % i] % mod) % mod;
	}
}

template<typename T>
T inverse_element_comp_mod(const T n, const T mod)


{
	return binpow(n, euler_function(mod) - 1, mod);
}

template<typename T>
void binomial_coefficients(const size_t n, std::vector<std::vector<T>>* c) {
	std::vector<std::vector<T>> result(n, std::vector<T>(n));
	for (size_t i = 0; i < n; ++i) {
		result[i][0] = 1;
		result[i][i] = 1;
		for (size_t j = 1; j < i; ++j) {
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
	}
	c->swap(result);
}

template<class T> std::string toRoman(T n) {
	const int ValsCount = 13;
	const int Vals[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	const char * Digits[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	std::string res = "";
	int x = ValsCount - 1;
	while (n) {
		while (Vals[x] > n) {
			--x;
		}
		n -= Vals[x];
		res += Digits[x];
	}
	return res;
}

template<typename T>
std::vector<T> calc_powers(const T base, const size_t n) {
	std::vector<T> powers(n + 1);
	powers[0] = 1;
	for (size_t i = 1; i < powers.size(); ++i) {
		powers[i] = powers[i - 1] * base;
	}
	return powers;
}

template<typename T>
std::vector<T> calc_factorial(const size_t n) {
	std::vector<T> factorial(n + 1);
	factorial[0] = 1;
	for (size_t i = 1; i < factorial.size(); ++i) {
		factorial[i] = factorial[i - 1] * i;
	}
	return factorial;
}

inline uint32_t abs(const uint32_t x) {
	return x;
}

inline uint64_t abs(const uint64_t x) {
	return x;
}


constexpr const int BASE_MOD = 1000000007;  


template<typename T>
inline T& add_mod(T& a, const T b, const T mod = BASE_MOD) {
	if ((a += b) >= mod) {
		a -= mod;
	}
	return a;
}

template<typename T>
inline T& sub_mod(T& a, const T b, const T mod = BASE_MOD) {
	if ((a -= b) < 0) {
		a += mod;
	}
	return a;
}

template<typename T>
inline T& mul_mod(T& a, const T b, const T mod = BASE_MOD) {
	a = static_cast<long long>(a) * b % mod;
	return a;
}

template<typename T, T MOD = BASE_MOD>
class ModInt {
public:

	

	constexpr ModInt() : ModInt(0) {}

	constexpr ModInt(const T value) : value_(value) {
		static_assert(MOD > 0, "Modulo must be strictly positive.");
		

	}

	template<typename U>
	constexpr static ModInt from_integer(const U value) {
		return{ ModInt::normalize(value) };
	}

	constexpr T value() const {
		return value_;
	}

	constexpr bool operator ==(const ModInt rhs) const {
		return value_ == rhs.value_;
	}

	constexpr bool operator !=(const ModInt rhs) const {
		return !operator==(rhs);
	}

	constexpr bool operator <(const ModInt& rhs) const {
		return value_ < rhs.value_;
	}

	constexpr bool operator >(const ModInt& rhs) const {
		return value_ > rhs.value_;
	}

	ModInt operator +(const ModInt rhs) const {
		T x = value_;
		return{ add_mod(x, rhs.value_, MOD) };
	}

	ModInt operator -(const ModInt rhs) const {
		T x = value_;
		return{ sub_mod(x, rhs.value_, MOD) };
	}

	ModInt operator *(const ModInt rhs) const {
		T x = value_;
		return{ mul_mod(x, rhs.value_, MOD) };
	}

	ModInt& operator +=(const ModInt rhs) {
		add_mod(value_, rhs.value_, MOD);
		return *this;
	}

	ModInt& operator -=(const ModInt rhs) {
		sub_mod(value_, rhs.value_, MOD);
		return *this;
	}

	ModInt& operator *=(const ModInt rhs) {
		mul_mod(value_, rhs.value_, MOD);
		return *this;
	}

	ModInt operator ++(int) {
		const ModInt ret(value_);
		add_mod(value_, static_cast<T>(1), MOD);
		return ret;
	}

	ModInt operator --(int) {
		const ModInt ret(value_);
		sub_mod(value_, static_cast<T>(1), MOD);
		return ret;
	}

	ModInt& operator ++() {
		add_mod(value_, static_cast<T>(1), MOD);
		return *this;
	}

	ModInt& operator --() {
		sub_mod(value_, static_cast<T>(1), MOD);
		return *this;
	}

	constexpr ModInt operator +() const {
		return{ value_ };
	}

	constexpr ModInt operator -() const {
		return negate();
	}

	constexpr ModInt negate() const {
		return{ normalize(-value_) };
	}

	constexpr ModInt inverse() const {
		return{ inverse_element(value_, MOD) };
	}

	std::string str() const {
		return std::to_string(value_);
	}

	template<typename C>
	C as() const {
		return static_cast<C>(value_);
	}

	friend std::istream& operator >>(std::istream& in, ModInt& rhs) {
		T x;
		in >> x;
		rhs.value_ = rhs.normalize(x);
		return in;
	}

	friend std::ostream& operator <<(std::ostream& out, const ModInt& rhs) {
		out << rhs.value_;
		return out;
	}

private:
	T value_;

	template<typename U>
	static T normalize(const U value) {
		if (value >= 0 && value < MOD) {
			return value;
		}
		const T ret = value % MOD;
		if (ret < 0) {
			return ret + MOD;
		}
		return ret;
	}

};

namespace std {

template<typename T, T MOD>
struct is_integral<ModInt<T, MOD>> : std::true_type {};

template<typename T, T MOD>
struct is_arithmetic<ModInt<T, MOD>> : std::true_type {};

}  


template<typename T, T MOD>
std::string to_string(const ModInt<T, MOD>& val) {
	return val.str();
}



#include <cctype>


inline bool is_lower(const char ch) {
	return std::islower(ch);
}

inline bool is_upper(const char ch) {
	return std::isupper(ch);
}

inline bool is_alpha(const char ch) {
	return std::isalpha(ch);
}

inline bool is_digit(const char ch) {
	return std::isdigit(ch);
}

template<typename T>
inline T to_upper(T);

template<typename T>
inline T to_lower(T);

template<>
inline char to_upper<char>(const char ch) {
	return is_lower(ch) ? ch ^ 32 : ch;
}

template<>
inline char to_lower<char>(const char ch) {
	return is_upper(ch) ? ch ^ 32 : ch;
}

template<>
inline std::string to_upper<std::string>(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), to_upper<char>);
	return s;
}

template<>
inline std::string to_lower<std::string>(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(), to_lower<char>);
	return s;
}

inline uint8_t to_digit(const char ch)




{
	return ch - '0';
}










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







template<typename T>
class DoubleHasher {
public:
	static const uint32_t MA = static_cast<uint32_t>(1e9) + 7;
	static const uint32_t MB = static_cast<uint32_t>(1e9) + 9;

	using a_integer_type = ModInt<T, MA>;
	using b_integer_type = ModInt<T, MB>;

	DoubleHasher() : DoubleHasher(0) {}
	DoubleHasher(const T x) : DoubleHasher(x, x) {}
	DoubleHasher(const T a, const T b) : DoubleHasher(static_cast<a_integer_type>(a), static_cast<b_integer_type>(b)) {}
	DoubleHasher(const a_integer_type a, const b_integer_type b) : a(a), b(b) {}

	DoubleHasher operator +(const DoubleHasher& rhs) const {
		return {a + rhs.a, b + rhs.b};
	}

	DoubleHasher operator -(const DoubleHasher& rhs) const {
		return {a - rhs.a, b - rhs.b};
	}

	DoubleHasher operator *(const int rhs) const {
		return {a * static_cast<a_integer_type>(rhs), b * static_cast<b_integer_type>(rhs)};
	}

	DoubleHasher operator *(const DoubleHasher& rhs) const {
		return {a * rhs.a, b * rhs.b};
	}

	bool operator ==(const DoubleHasher& rhs) const {
		return a == rhs.a && b == rhs.b;
	}

	bool operator <(const DoubleHasher& rhs) const {
		return a < rhs.a || (a == rhs.a && b < rhs.b);
	}

	explicit operator long long() const {
		return a.template as<int64_t>() * MB + b.template as<int64_t>() + 1;
	}

	std::string str() const {
		return to_string(std::make_pair(a, b));
	}

private:
	a_integer_type a;
	b_integer_type b;
};

template<typename T>
std::string to_string(const DoubleHasher<T>& value) {
	return value.str();
}


template<typename T, typename Container = StringView>
class Hasher {
public:
	using size_type = std::size_t;
	using container_type = Container;
	using value_type = T;

	explicit Hasher(const container_type& data) : size_(data.size()), hash_(size_ + 1), data_(data) {
		const value_type kHashPoint = Random::get(307, 877117);
		deg_ = calc_powers(kHashPoint, size_ + 1);

		hash_[0] = 0;
		for (size_type i = 0; i < data_.size(); ++i) {
			hash_[i + 1] = hash_[i] * kHashPoint + data_[i];
		}
	}

	T get_hash(const size_type left, const size_type right) const
	

	{
		return hash_[right + 1] - hash_[left] * deg_[right - left + 1];
	}

	size_type lcp(const size_type a, const size_type b) const {
		size_type L = 0;
		size_type R = size_ - std::max(a, b) + 1;
		while (L < R) {
			const size_type md = (L + R + 1) / 2;
			if (get_hash(a, a + md - 1) == get_hash(b, b + md - 1)) {
				L = md;
			} else {
				R = md - 1;
			}
		}
		return L;
	}

	bool compare_substrings(const size_type a, const size_type b) const {
		return compare_substrings_impl(a, b) < 0;
	}

private:
	size_type size_;
	std::vector<value_type> deg_;
	std::vector<value_type> hash_;
	const container_type& data_;

	int compare_substrings_impl(size_type a, size_type b) const {
		const size_type max_substring_length = size_ - std::max(a, b);
		const size_type lcp_length = lcp(a, b);
		return lcp_length < max_substring_length ? static_cast<int>(data_[a + lcp_length] - data_[b + lcp_length]) : static_cast<int>(b) - a;
	}

};


class DNoviiGodIDrevneeProrochestvo {
public:
	using Int = ModInt<int, 1000000007>;

	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;
	void solve(std::istream& in, std::ostream& out) {
		int n;
		std::string s;
		in >> n >> s;

		auto dp = make_vector<Int>(n, n, 0);
		dp[0][0] = 1;

		auto lcp = make_vector<int>(n + 1, n + 1, 0);
		for (int i : downrange(n)) {
			for (int j : downrange(n)) {
				if (s[i] == s[j]) {
					lcp[i][j] = lcp[i + 1][j + 1] + 1;
				}
			}
		}

		


		for (int L : range(n)) {
			for (int R : range(L, n - 1)) {
				dp[L][R + 1] += dp[L][R];
				const int len = R - L + 1;
				const int start = R + 1;
				const int finish = R + len;

				if (finish >= n || s[start] == '0') {
					continue;
				}

				

				const int max_prefix_length = lcp[L][start];
				const int first_to_cmp = start + max_prefix_length;

				int need_len = len;
				if (max_prefix_length >= len || s[first_to_cmp] < s[L + max_prefix_length]) {
					++need_len;
				}
				if (R + need_len < n) {
					dp[R + 1][R + need_len] += dp[L][R];
				}
			}
		}

		Int ans = 0;
		for (int i : range(n)) {
			ans += dp[i][n - 1];
		}
		out << ans << std::endl;
	}


	DNoviiGodIDrevneeProrochestvo() {}

	ll solve_slow(const std::string& s, const int index, const ll cur_value, const ll prev_value) const {
		if (index == s.size()) {
			if (cur_value > prev_value) {
				

			}
			return (cur_value > prev_value ? 1 : 0);
		}
		ll ans = solve_slow(s, index + 1, cur_value * 10 + to_digit(s[index]), prev_value);
		if (cur_value > prev_value && s[index] != '0') {
			ans += solve_slow(s, index + 1, to_digit(s[index]), cur_value);
		}
		return ans;
	}


	static constexpr bool kUseCustomChecker = false;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		int n;
		std::string s;
		in >> n >> s;

		ll pans;
		out >> pans;

		ll jans = solve_slow(s, 1, to_digit(s.front()), 0);
		if (jans != pans) {
			

			return false;
		}

		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static void generate_test(std::ostream& test) {
		const int kMaxn = 15;

		const int n = Random::get(1, kMaxn);
		std::string input;
		for (int i : range(n)) {
			input += Random::get(0, 9) + '0';
		}
		if (input.front() == '0') {
			++input.front();
		}
		test << n << std::endl << input << std::endl;
	}

};


int main() {
	DNoviiGodIDrevneeProrochestvo solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (DNoviiGodIDrevneeProrochestvo::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (DNoviiGodIDrevneeProrochestvo::kWriteCaseNumber) {
				out << "Case #" << test_id << ": ";
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
