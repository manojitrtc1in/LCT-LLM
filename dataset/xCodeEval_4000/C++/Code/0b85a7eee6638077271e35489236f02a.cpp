

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



static constexpr long double PI = 3.14159265358979323846;
static constexpr int INF = 0x3f3f3f3f;
static constexpr long double EPS = 1e-9;
static constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;

static constexpr int DX[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
static constexpr int DY[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

static constexpr size_t kDayMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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
inline bool is_equal_to_zero(const T& a) {
	if (std::is_floating_point<T>()) {
		return abs(a) < EPS;
	}
	return a == 0;
}

template<typename T>
inline bool umin(T& a, const T& b) {
	return (b < a ? a = b, true : false);
}

template<typename T>
inline bool umax(T& a, const T& b) {
	return (a < b ? a = b, true : false);
}

namespace std {

template<typename T, typename U>
struct hash<std::pair<T, U>> {
	std::size_t operator()(const std::pair<T, U>& lhs) const {
		return lhs.first * 877117 + lhs.second;
	}
};

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
#define sz(a) ((int)a.size())
#define X first
#define Y second
#define mp std::make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back







template<typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
class SafeIntegralHash {
public:
	const T kRandomValue = static_cast<T>(std::chrono::high_resolution_clock::now().time_since_epoch().count());

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





#ifdef _MSC_VER
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define pii std::pair<int, int>
#define pll std::pair<ll, ll>
#define pli std::pair<ll, int>
#define vi std::vector<int>
#define vvi std::vector<vi>
#define vp std::vector<pii>
#define ld long double














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
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
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
class ReversedIntegerRange {
public:
	using const_iterator = IntegerIterator<T>;
	using reverse_iterator = std::reverse_iterator<const_iterator>;

	constexpr ReversedIntegerRange(const T begin, const T end) : begin_(begin), end_(end) {}

	constexpr reverse_iterator begin() const {
		return reverse_iterator(const_iterator(begin_));
	}

	constexpr reverse_iterator end() const {
		return reverse_iterator(const_iterator(end_));
	}

	constexpr T size() const {
		return end_ - begin_;
	}

private:
	T begin_;
	T end_;

};


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
constexpr ReversedIntegerRange<T> downrange(const T from) {
	return ReversedIntegerRange<T>(from, 0);
}

template<typename T>
constexpr ReversedIntegerRange<T> downrange(const T from, const T to) {
	return ReversedIntegerRange<T>(from, to);
}

template<typename T>
constexpr ReversedIntegerRange<T> inclusiveDownrange(const T from) {
	return ReversedIntegerRange<T>(from + 1, 0);
}

template<typename T>
constexpr ReversedIntegerRange<T> inclusiveDownrange(const T from, const T to) {
	return ReversedIntegerRange<T>(from + 1, to);
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

template<typename R>
R reversed(R range) {
	reverse(range);
	return range;
}



















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

template<class T> inline bool isPrime(const T& n)


{
	if (n < 2) {
		return false;
	}
	T kk = (T)sqrt(n + 0.);
	for (T i = 2; i <= kk; ++i) {
		if (!(n % i)) {
			return false;
		}
	}
	return true;
}

inline void eratosthenes_sieve(const size_t n, std::vector<bool>* prime) {
	if (n < 2) {
		prime->assign(n, false);
		return;
	}
	std::vector<bool> result(n, true);
	result[0] = result[1] = false;
	for (size_t i = 4; i < n; i += 2) {
		result[i] = false;
	}
	for (size_t i = 3; i * i < n; i += 2) {
		if (result[i]) {
			const size_t delta = i << 1;
			for (size_t j = i * i; j < n; j += delta) {
				result[j] = false;
			}
		}
	}
	prime->swap(result);
}

inline void eratosthenes_sieve(std::vector<bool>* prime) {
	eratosthenes_sieve(prime->size(), prime);
}

template<typename T>
inline void primes_vector(const size_t n, std::vector<T>* primes) {
	std::vector<T> result;
	if (n < 2) {
		primes->swap(result);
		return;
	}
	std::vector<bool> prime(n);
	eratosthenes_sieve(&prime);
	result.emplace_back(2);
	for (size_t i = 3; i < n; i += 2) {
		if (prime[i]) {
			result.emplace_back(i);
		}
	}
	primes->swap(result);
}

template<typename T>
inline void min_prime_div_vector(const size_t n, std::vector<T>* min_prime_div) {
	std::vector<T> result(n, 0);
	result[0] = result[1] = 1;
	for (size_t i = 2; i < n; i += 2) {
		result[i] = 2;
	}
	size_t index = 3;
	while (index * index < n) {
		if (result[index] == 0) {
			result[index] = index;
			const size_t delta = index << 1;
			for (size_t j = index * index; j < n; j += delta) {
				if (result[j] == 0) {
					result[j] = index;
				}
			}
		}
		index += 2;
	}
	while (index < n) {
		if (result[index] == 0) {
			result[index] = index;
		}
		++index;
	}
	min_prime_div->swap(result);
}

template<typename T>
inline void min_prime_div_vector(std::vector<T>* min_prime_div) {
	min_prime_div_vector(min_prime_div->size(), min_prime_div);
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
void calc_powers(std::vector<T>& deg, const T base) {
	deg[0] = 1;
	for (size_t i = 1; i < deg.size(); ++i) {
		deg[i] = deg[i - 1] * base;
	}
}

inline uint32_t abs(const uint32_t x) {
	return x;
}

inline uint64_t abs(const uint64_t x) {
	return x;
}

namespace Random {

	static std::chrono::system_clock::rep GetRandSeed() {
		return std::chrono::system_clock::now().time_since_epoch().count();
	}

	static std::mt19937_64 gen(GetRandSeed());
	static std::uniform_int_distribution<long long> distrib(0, std::numeric_limits<long long>::max());

	template<typename T>
	static T get(T r) {
		return distrib(gen) % r;
	}

	template<typename T>
	static T get(T l, T r) {
		return get(r - l + 1) + l;
	}

};







template<typename T>
class Stack {
public:
	using value_type = T;
	using size_type = size_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using rvalue = value_type&&;
	using container = std::vector<value_type>;

	Stack(const size_type max_size) : data_(container(max_size)) {
		clear();
	}

	Stack() = delete;

	Stack(const Stack&) = default;
	Stack& operator =(const Stack&) = default;
	Stack(Stack&&) = default;
	Stack& operator =(Stack&&) = default;

	reference top() {
		return data_[top_index_ - 1];
	}

	const_reference top() const {
		return data_[top_index_ - 1];
	}

	constexpr bool empty() const {
		return top_index_ == 0;
	}

	void clear() {
		top_index_ = 0;
	}

	constexpr size_type size() const {
		return top_index_;
	}

	void push(const_reference value) {
		data_[top_index_++] = value;
	}

	void push(rvalue value) {
		data_[top_index_++] = std::move(value);
	}

	value_type pop() {
		return data_[--top_index_];
	}

	void swap(Stack& rhs) {
		data_.swap(rhs.data_);
		std::swap(top_index_, rhs.top_index_);
	}

	const container& data() const {
		return data_;
	}

	bool operator ==(const Stack& rhs) const {
		return top_index_ == rhs.top_index_ && data_ == rhs.data_;
	}

	bool operator !=(const Stack& rhs) const {
		return !operator==(rhs);
	}

	bool operator <(const Stack& rhs) const {
		return data_ < rhs.data_;
	}

	bool operator <=(const Stack& rhs) const {
		return data_ <= rhs.data_;
	}

	bool operator >(const Stack& rhs) const {
		return data_ > rhs.data_;
	}

	bool operator >=(const Stack& rhs) const {
		return data_ >= rhs.data_;
	}

private:
	container data_;
	size_type top_index_;

};

template<typename T>
class CmpStack {
public:
	using value_type = T;
	using size_type = size_t;
	using const_reference = const value_type&;
	using Comparator = std::function<bool(const_reference, const_reference)>;

	CmpStack(const size_type n, const Comparator& less = std::less<value_type>()) : stack_(n), less_(less) {}

	constexpr bool empty() const {
		return stack_.empty();
	}

	value_type min_value() const {
		return stack_.empty() ? 0 : stack_.top().second;
	}

	void push(const_reference element) {
		value_type cur_min = element;
		if (!stack_.empty() && less_(stack_.top().second, cur_min)) {
			cur_min = stack_.top().second;
		}
		stack_.push(std::make_pair(element, cur_min));
	}

	value_type pop() {
		return stack_.pop().first;
	}

	void clear() {
		stack_.clear();
	}

private:
	Stack<std::pair<value_type, value_type>> stack_;
	Comparator less_;

};





template<typename T>
class Queue {
public:
	using value_type = T;
	using size_type = size_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using rvalue = value_type&&;
	using container = std::vector<value_type>;

	Queue(const size_type max_size) : data_(container(max_size)) {
		clear();
	}

	Queue() = delete;

	Queue(const Queue&) = default;
	Queue& operator =(const Queue&) = default;
	Queue(Queue&&) = default;
	Queue& operator =(Queue&&) = default;

	reference front() {
		return data_[head_index_];
	}

	const_reference front() const {
		return data_[head_index_];
	}

	reference back() {
		return data_[tail_index_ - 1];
	}

	const_reference back() const {
		return data_[tail_index_ - 1];
	}

	constexpr bool empty() const {
		return head_index_ == tail_index_;
	}

	void clear() {
		head_index_ = 0;
		tail_index_ = 0;
	}

	constexpr size_type size() const {
		return tail_index_ - head_index_;
	}

	void push(const_reference value) {
		data_[tail_index_++] = value;
	}

	void push(rvalue value) {
		data_[tail_index_++] = std::move(value);
	}

	value_type pop_front() {
		return data_[head_index_++];
	}

	value_type pop_back() {
		return data_[--tail_index_];
	}

	void swap(Queue& rhs) {
		data_.swap(rhs.data_);
		std::swap(head_index_, rhs.head_index_);
		std::swap(tail_index_, rhs.tail_index_);
	}

	const container& data() const {
		return data_;
	}

	bool operator ==(const Queue& rhs) const {
		return head_index_ == rhs.head_index_ && tail_index_ == rhs.tail_index_ && data_ == rhs.data_;
	}

	bool operator !=(const Queue& rhs) const {
		return !operator==(rhs);
	}

	bool operator <(const Queue& rhs) const {
		return data_ < rhs.data_;
	}

	bool operator <=(const Queue& rhs) const {
		return data_ <= rhs.data_;
	}

	bool operator >(const Queue& rhs) const {
		return data_ > rhs.data_;
	}

	bool operator >=(const Queue& rhs) const {
		return data_ >= rhs.data_;
	}

private:
	container data_;
	size_type head_index_;
	size_type tail_index_;

};

template<typename T>
class CmpQueue {
public:
	using value_type = T;
	using size_type = size_t;
	using const_reference = const value_type&;
	using Comparator = std::function<bool(const_reference, const_reference)>;

	CmpQueue(const size_type n, const Comparator& less = std::less<value_type>()) : a_(n, less), b_(n, less), less_(less) {}

	constexpr bool empty() const {
		return a_.empty() && b_.empty();
	}

	value_type min_value() const {
		if (a_.empty()) {
			return b_.min_value();
		}
		if (b_.empty()) {
			return a_.min_value();
		}
		const value_type a = a_.min_value();
		const value_type b = b_.min_value();
		return less_(a, b) ? a : b;
	}

	void push(const_reference element) {
		a_.push(element);
	}

	value_type pop() {
		if (b_.empty()) {
			while (!a_.empty()) {
				b_.push(a_.pop());
			}
		}
		return b_.pop();
	}

	void clear() {
		a_.clear();
		b_.clear();
	}

private:
	CmpStack<value_type> a_;
	CmpStack<value_type> b_;
	Comparator less_;
};


enum GraphType {
	Weighted = 1
};

template<size_t MASK>
struct is_weighted
{
	

	static constexpr bool value = (MASK & GraphType::Weighted) != 0;
};

template<typename T = long long, size_t MASK = 0>
class Graph {
public:
	using EdgesList = std::vector<size_t>;

	class Edge {
	public:
		constexpr explicit Edge(const std::vector<size_t>& from, const std::vector<size_t>& to,
			const std::vector<T>& weight, const size_t index) :
			from_(from), to_(to), weight_(weight), index_(index) {}

		size_t from() const {
			return from_[index_];
		}

		size_t to() const {
			return to_[index_];
		}

		template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
		T weight() const {
			return weight_[index_];
		}

		constexpr size_t id() const {
			return index_;
		}

		void set_index(const size_t index) {
			index_ = index;
		}

		constexpr Edge reversed() const {
			return Edge(to_, from_, weight_, index_);
		}

	private:
		const std::vector<size_t>& from_;
		const std::vector<size_t>& to_;
		const std::vector<T>& weight_;
		size_t index_;

	};

	template<typename Range>
	class EdgesHolder {
	public:

		template<typename BaseConstIterator>
		class EdgeConstIterator : public BaseConstIterator {
		public:
			using value_type = Edge;
			using pointer = const value_type*;
			using const_reference = const value_type&;

			constexpr explicit EdgeConstIterator(BaseConstIterator it, const std::vector<size_t>& from,
				const std::vector<size_t>& to, const std::vector<T>& weight) :
				BaseConstIterator(it), cur_edge_(from, to, weight, 0) {}

			pointer operator->() {
				return addressof(operator*());
			}

			const_reference operator*() {
				const typename BaseConstIterator::value_type index = this->BaseConstIterator::operator*();
				cur_edge_.set_index(index);
				return cur_edge_;
			}

		private:
			Edge cur_edge_;

		};

		using const_iterator = EdgeConstIterator<typename Range::const_iterator>;
		using value_type = typename const_iterator::value_type;

		constexpr explicit EdgesHolder(const Range& range, const std::vector<size_t>& from,
			const std::vector<size_t>& to, const std::vector<T>& weight) :
			begin_(range.begin(), from, to, weight), end_(range.end(), from, to, weight) {}

		constexpr const_iterator begin() const {
			return begin_;
		}

		constexpr const_iterator end() const {
			return end_;
		}

		constexpr size_t size() const {
			return end_ - begin_;
		}

	private:
		const const_iterator begin_;
		const const_iterator end_;

	};

	Graph() : Graph(0) {}
	Graph(const size_t vertices_count) : vertices_count_(vertices_count), edges_(vertices_count) {}

	virtual ~Graph() {
		clear();
	}

	void init(const size_t vertices_count) {
		clear();
		vertices_count_ = vertices_count;
		edges_.resize(vertices_count_);
	}

	IntegerRange<size_t> vertices() const {
		return range(vertices_count_);
	}

	IntegerRange<size_t>::const_iterator begin() const {
		return vertices().begin();
	}

	IntegerRange<size_t>::const_iterator end() const {
		return vertices().end();
	}

	EdgesHolder<EdgesList> edges(const size_t vertex) const {
		return EdgesHolder<EdgesList>(edges_[vertex], from_, to_, weight_);
	}

	EdgesHolder<IntegerRange<size_t>> edges() const {
		return EdgesHolder<IntegerRange<size_t>>(range(from_.size()), from_, to_, weight_);
	}

	void clear();

	size_t vertices_count() const {
		return vertices_count_;
	}

	size_t edges_count() const {
		return from_.size();
	}

	size_t from(const size_t index) const {
		return from_[index];
	}

	size_t to(const size_t index) const {
		return to_[index];
	}

	Edge operator [](const size_t index) const {
		return Edge(from, to, weight, index);
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	T weight(const size_t index) const {
		return weight_[index];
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	T weight_infinity() const {
		return std::numeric_limits<T>::max() / 2;
	}

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void add_directed_edge(const size_t from, const size_t to) {
		push_edge(from, to);
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void add_directed_edge(const size_t from, const size_t to, const T weight) {
		weight_.emplace_back(weight);
		push_edge(from, to);
	}

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void add_directed_edge(const Edge& edge) {
		add_directed_edge(edge.from(), edge.to());
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void add_directed_edge(const Edge& edge) {
		add_directed_edge(edge.from(), edge.to(), edge.weight());
	}

	bool is_sparse() const {
		return vertices_count_ == 0 || sqr(static_cast<long long>(vertices_count_)) >= (edges_count() << 4);
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	std::vector<std::vector<T>> floyd() const {
		auto dist = make_vector<T>(vertices_count_, vertices_count_, weight_infinity());
		for (const auto v : vertices()) {
			dist[v][v] = 0;
		}
		for (const auto& edge : edges()) {
			umin(dist[edge.from()][edge.to()], edge.weight());
		}
		for (const auto k : vertices()) {
			for (const auto i : vertices()) {
				for (const auto j : vertices()) {
					umin(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		return dist;
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void dijkstra(const size_t start_vertex, std::vector<T>* distance, std::vector<size_t>* last_edge = nullptr) const {
		if (is_sparse()) {
			sparse_dijkstra(start_vertex, distance, last_edge);
		} else {
			dense_dijkstra(start_vertex, distance, last_edge);
		}
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	T dijkstra(const size_t start_vertex, const size_t finish_vertex, std::vector<size_t>* path = nullptr) const {
		if (start_vertex == finish_vertex) {
			return 0;
		}
		std::vector<T> dist;
		std::vector<size_t> last;
		dijkstra(start_vertex, &dist, &last);
		if (path != nullptr) {
			std::vector<size_t> tmp_path;
			size_t vertex = finish_vertex;
			while (vertex != start_vertex) {
				const size_t edge = last[vertex];
				tmp_path.emplace_back(edge);
				vertex = from_[edge];
			}
			std::reverse(tmp_path.begin(), tmp_path.end());
			path->swap(tmp_path);
		}
		return dist[finish_vertex];
	}

	size_t find_vertex_with_max_degree() const;

	bool is_bipartite(std::vector<size_t>& partition) const;
	void maximal_matching(std::vector<size_t>* match) const;

	bool try_kuhn(const size_t vertex, std::vector<bool>& used, std::vector<size_t>& match) const;

protected:
	void push_edge(const size_t from, const size_t to) {
		const size_t edge_id = from_.size();
		from_.emplace_back(from);
		to_.emplace_back(to);
		edges_[from].emplace_back(edge_id);
	}

	std::vector<EdgesList> edges_;
	std::vector<size_t> from_;
	std::vector<size_t> to_;
	std::vector<T> weight_;

	size_t vertices_count_;

private:
	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void sparse_dijkstra(const size_t start_vertex, std::vector<T>* distance, std::vector<size_t>* last_edge) const {
		std::vector<T> dist(vertices_count_, weight_infinity());
		std::vector<size_t> last(vertices_count_, std::numeric_limits<size_t>::max());
		dist[start_vertex] = 0;
		using QueueNode = std::pair<T, size_t>;
		std::priority_queue<QueueNode> q;
		q.emplace(0, start_vertex);
		while (!q.empty()) {
			const QueueNode node = q.top();
			q.pop();
			const T len = -node.first;
			const size_t vertex = node.second;
			if (len > dist[vertex]) {
				continue;
			}
			for (const auto& it : edges(vertex)) {
				const T new_dist = len + it.weight();
				const size_t to = it.to();
				if (umin(dist[to], new_dist)) {
					q.push(std::make_pair(-new_dist, to));
					last[to] = it.id();
				}
			}
		}
		distance->swap(dist);
		if (last_edge != nullptr) {
			last_edge->swap(last);
		}
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void dense_dijkstra(const size_t start_vertex, std::vector<T>* distance, std::vector<size_t>* last_edge) const {
		std::vector<bool> used(vertices_count_);
		std::vector<T> dist(vertices_count_, weight_infinity());
		std::vector<size_t> last(vertices_count_, std::numeric_limits<size_t>::max());
		dist[start_vertex] = 0;
		for (size_t iter = 0; iter < vertices_count_; ++iter) {
			size_t vertex = std::numeric_limits<size_t>::max();
			T min_dist = weight_infinity();
			for (const size_t v : vertices()) {
				if (!used[v] && umin(min_dist, dist[v])) {
					min_dist = dist[v];
					vertex = v;
				}
			}
			if (vertex == std::numeric_limits<size_t>::max()) {
				break;
			}
			used[vertex] = true;
			for (const auto& it : edges(vertex)) {
				const size_t to = it.to();
				const T len = min_dist + it.weight();
				if (!used[to] && umin(dist[to], len)) {
					dist[to] = len;
					last[to] = it.id();
				}
			}
		}
		distance->swap(dist);
		if (last_edge != nullptr) {
			last_edge->swap(last);
		}
	}

};

template<typename T, size_t MASK>
void Graph<T, MASK>::clear() {
	vertices_count_ = 0;
	edges_.clear();
	from_.clear();
	to_.clear();
	weight_.clear();
}

template<typename T, size_t MASK>
size_t Graph<T, MASK>::find_vertex_with_max_degree() const {
	const auto iter = std::max_element(edges_.begin(), edges_.end(),
		[](const EdgesList& lhs, const EdgesList& rhs) {
			return lhs.size() < rhs.size();
		});
	return static_cast<size_t>(std::distance(edges_.begin(), iter));
}

template<typename T, size_t MASK>
bool Graph<T, MASK>::is_bipartite(std::vector<size_t>& partition) const {
	const size_t kNone = std::numeric_limits<size_t>::max();
	partition.assign(vertices_count_, kNone);
	Queue<size_t> q(vertices_count_);
	for (size_t i = 0; i < vertices_count_; ++i) {
		if (partition[i] == kNone) {
			q.clear();
			q.push(i);
			partition[i] = 0;
			while (!q.empty()) {
				const size_t vertex = q.pop_front();
				const size_t color = partition[vertex];
				for (const auto& it : edges(vertex)) {
					const size_t to = it.to();
					if (partition[to] == kNone) {
						partition[to] = color ^ 1;
						q.push(to);
						continue;
					}
					if (partition[to] == color) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

template<typename T, size_t MASK>
void Graph<T, MASK>::maximal_matching(std::vector<size_t>* vertex_match) const {
	std::vector<size_t> match(vertices_count_, std::numeric_limits<size_t>::max());
	std::vector<bool> matched(vertices_count_, false);
	for (const size_t v : vertices()) {
		for (const auto& it : edges(v)) {
			const size_t to = it.to();
			if (match[to] == std::numeric_limits<size_t>::max()) {
				match[to] = v;
				matched[v] = true;
				break;
			}
		}
	}
	std::vector<bool> used;
	for (const size_t v : vertices()) {
		if (matched[v]) {
			continue;
		}
		used.assign(vertices_count_, false);
		try_kuhn(v, used, match);
	}
	vertex_match->swap(match);
}

template<typename T, size_t MASK>
bool Graph<T, MASK>::try_kuhn(const size_t vertex, std::vector<bool>& used, std::vector<size_t>& match) const {
	used[vertex] = true;
	for (const auto& it : edges(vertex)) {
		const size_t to = it.to();
		if (match[to] == std::numeric_limits<size_t>::max()) {
			match[to] = vertex;
			match[vertex] = to;
			return true;
		}
	}
	for (const auto& it : edges(vertex)) {
		const size_t to = it.to();
		if (!used[match[to]] && try_kuhn(match[to], used, match)) {
			match[to] = vertex;
			match[vertex] = to;
			return true;
		}
	}
	return false;
}


template<typename T = long long, size_t MASK = 0>
class DirectedGraph : public Graph<T, MASK> {
public:
	DirectedGraph() : DirectedGraph(0) {}
	DirectedGraph(const size_t vertices_count) : Graph<T, MASK>(vertices_count) {}

	bool is_acyclic() const;
	bool top_sort_acyclic(std::vector<size_t>* vertex_order = nullptr) const;
	void top_sort_rec(std::vector<size_t>* vertex_order) const;

	DirectedGraph reversed() const;

	size_t scc(std::vector<size_t>* vertex_color = nullptr) const;

private:
	void top_sort_rec_impl(const size_t vertex, std::vector<size_t>& order, std::vector<bool>& used) const;

};

template<typename T, size_t MASK>
DirectedGraph<T, MASK> DirectedGraph<T, MASK>::reversed() const {
	DirectedGraph<T, MASK> result;
	result.init(this->vertices_count_);
	for (const auto& edge : this->edges()) {
		result.add_directed_edge(edge.reversed());
	}
	return result;
}

template<typename T, size_t MASK>
bool DirectedGraph<T, MASK>::is_acyclic() const {
	return this->top_sort_acyclic();
}

template<typename T, size_t MASK>
bool DirectedGraph<T, MASK>::top_sort_acyclic(std::vector<size_t>* vertex_order) const


{
	std::vector<size_t> order;
	std::vector<size_t> inbound_degree(this->vertices_count_, 0);
	for (const auto& to : this->to_) {
		++inbound_degree[to];
	}
	for (const size_t i : this->vertices()) {
		if (inbound_degree[i] == 0) {
			order.emplace_back(i);
		}
	}
	size_t head = 0;
	while (head < order.size()) {
		const size_t cur_vertex = order[head++];
		for (const auto& it : this->edges(cur_vertex)) {
			const size_t to = it.to();
			--inbound_degree[to];
			if (inbound_degree[to] == 0) {
				order.emplace_back(to);
			}
		}
	}
	const bool result = (order.size() == this->vertices_count_);
	if (vertex_order != nullptr) {
		vertex_order->swap(order);
	}
	return result;
}

template<typename T, size_t MASK>
void DirectedGraph<T, MASK>::top_sort_rec(std::vector<size_t>* vertex_order) const {
	std::vector<bool> used(this->vertices_count_, false);
	std::vector<size_t> order;
	for (const size_t v : this->vertices()) {
		if (!used[v]) {
			top_sort_rec_impl(v, order, used);
		}
	}
	std::reverse(order.begin(), order.end());
	vertex_order->swap(order);
}

template<typename T, size_t MASK>
void DirectedGraph<T, MASK>::top_sort_rec_impl(const size_t vertex, std::vector<size_t>& order, std::vector<bool>& used) const {
	used[vertex] = true;
	for (const auto& it : this->edges(vertex)) {
		const size_t to = it.to();
		if (!used[to]) {
			top_sort_rec_impl(to, order, used);
		}
	}
	order.emplace_back(vertex);
}

template<typename T, size_t MASK>
size_t DirectedGraph<T, MASK>::scc(std::vector<size_t>* vertex_color) const {
	const DirectedGraph<T, MASK> rev_graph = reversed();
	std::vector<size_t> order(this->vertices_count_);
	top_sort_rec(&order);
	std::vector<bool> used(this->vertices_count_, false);
	std::vector<size_t> color(this->vertices_count_);
	Queue<size_t> queue(this->vertices_count_);
	size_t components_count = 0;
	for (const auto& v : order) {
		if (!used[v]) {
			queue.clear();
			queue.push(v);
			while (!queue.empty()) {
				const size_t vertex = queue.pop_front();
				color[vertex] = components_count;
				used[vertex] = true;
				for (const auto& it : rev_graph.edges(vertex)) {
					const size_t to = it.to();
					if (!used[to]) {
						used[to] = true;
						queue.push(to);
					}
				}
			}
			++components_count;
		}
	}
	if (vertex_color != nullptr) {
		vertex_color->swap(color);
	}
	return components_count;
}


class CZadachaProKvantori {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		DirectedGraph<int> graph(n);

		for (int i : range(m)) {
			int from, to;
			in >> from >> to;
			--from, --to;
			graph.add_directed_edge(from, to);
		}

		if (!graph.is_acyclic()) {
			out << -1 << std::endl;
			return;
		}

		const auto reversed = graph.reversed();

		auto quantor = make_vector<bool>(n, false);
		auto used_forward = make_vector<bool>(n, false);
		auto used_backward = make_vector<bool>(n, false);

		std::function<void(int, const DirectedGraph<int>&, std::vector<bool>&)> dfs = [&dfs](const int v, const DirectedGraph<int>& graph, std::vector<bool>& used) {
			if (used[v]) {
				return;
			}
			used[v] = true;
			for (const auto& edge : graph.edges(v)) {
				const int to = edge.to();
				dfs(to, graph, used);
			}
		};

		for (auto v : graph.vertices()) {
			if (!used_forward[v] && !used_backward[v]) {
				quantor[v] = true;
			}
			dfs(v, graph, used_forward);
			dfs(v, reversed, used_backward);
		}

		std::string ans;
		for (int i : range(n)) {
			ans += (quantor[i] ? 'A' : 'E');
		}
		const int ans_cnt = std::count(all(ans), 'A');

		out << ans_cnt << std::endl << ans << std::endl;
	}

	static constexpr bool kUseCustomChecker = true;
	bool check(std::string input, std::string expected_output, std::string actual_output) {
		std::istringstream jury(expected_output);
		std::istringstream participant(actual_output);

		int jans, pans;
		jury >> jans;
		participant >> pans;

		return jans == pans;
	}

	static constexpr size_t kGeneratedTestsCount = 0;
	static void generate_test(std::ostream& test) {}

private:
	size_t test_id_ = 0;
};


int main() {
	CZadachaProKvantori solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	solver.solve(in, out);
	return 0;
}
