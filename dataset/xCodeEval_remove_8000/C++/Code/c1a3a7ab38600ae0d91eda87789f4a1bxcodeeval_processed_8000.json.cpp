





















































template <bool... Bools>
struct Disjunction : std::false_type {};

template <bool First, bool... Others>


struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {};


template <bool... Bools>
constexpr bool id13 = Disjunction<Bools...>::value;

static_assert(!id13<>, "");
static_assert(!id13<false, false>, "");
static_assert(id13<true>, "");
static_assert(id13<false, true>, "");
static_assert(id13<true, false>, "");
static_assert(id13<false, false, true, true>, "");






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

std::vector<std::string> id20(std::string s) {
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


void id5() {
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
class id3 {
public:
	using const_iterator = typename std::decay<T>::type::const_iterator;
	using reverse_iterator = std::reverse_iterator<const_iterator>;

	explicit constexpr id3(const T& iterable) : begin_(iterable.begin()), end_(iterable.end()) {}

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
id3<T> reversed(T&& iterable) {
	return id3<T>{iterable};
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
constexpr id3<IntegerRange<T>> downrange(const T from) {
	return reversed(range(from));
}

template<typename T>
constexpr id3<IntegerRange<T>> downrange(const T from, const T to) {
	return reversed(range(to, from));
}

template<typename T>
constexpr id3<IntegerRange<T>> id10(const T from) {
	return reversed(range(from + 1));
}

template<typename T>
constexpr id3<IntegerRange<T>> id10(const T from, const T to) {
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
bool id18(R& range) {
	return std::id18(range.begin(), range.end());
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




















namespace Random {

inline std::chrono::system_clock::rep current_timestamp() {
	return std::chrono::system_clock::now().time_since_epoch().count();
}

inline uint64_t id1() {
	return static_cast<uint64_t>(current_timestamp());
}

inline uint64_t id15() {
	static const uint64_t id8 = id1();
	return id8;
}

using Engine = std::mt19937_64;

template<typename T>
using Distribution = std::uniform_int_distribution<T>;

inline Engine& random_engine() {
	static Engine engine(id15());
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
inline bool id9(const T& a) {
	return abs(a) < EPS;
}

template<typename T, typename std::enable_if<!std::is_floating_point<T>::value>::type* = nullptr>
inline bool id9(const T& a) {
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
inline bool id4(const T year) {
	return year % 400 == 0 || (year % 100 != 0 && (year & 3) == 0);
}

inline size_t id21(const size_t month, const size_t year) {
	return kDayMonth[month] + (month == 1 && id4(year) ? 1 : 0);
}


















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
std::vector<T> id11(const T n) {
	const auto id17 = static_cast<size_t>(cbrt(n));
	std::vector<T> ans;
	ans.reserve(id17);
	const auto id2 = static_cast<T>(sqrt(n));
	for (T i = 1; i <= id2; ++i) {
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
T id19(T n) {
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

inline void id6(int r[], const int n, const int mod)


{
	r[1] = 1;
	for (int i = 2; i < n; ++i) {
		r[i] = (mod - static_cast<long long>(mod) / i * r[mod % i] % mod) % mod;
	}
}

template<typename T>
T id16(const T n, const T mod)


{
	return binpow(n, id19(mod) - 1, mod);
}

template<typename T>
void id7(const size_t n, std::vector<std::vector<T>>* c) {
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
std::vector<T> id12(const T base, const size_t n) {
	std::vector<T> powers(n + 1);
	powers[0] = 1;
	for (size_t i = 1; i < powers.size(); ++i) {
		powers[i] = powers[i - 1] * base;
	}
	return powers;
}

template<typename T>
std::vector<T> id22(const size_t n) {
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


template<typename T>
class Rational {
public:
	static_assert(std::is_integral<T>::value, "Base type of Rational must be an integral.");

	constexpr Rational() : Rational(0) {}
	constexpr Rational(const T a) : a_(a), b_(1) {}
	Rational(const T a, const T b) : a_(a), b_(b) {
		normalize();
	}

	void swap(Rational& rhs) {
		std::swap(a_, rhs.a_);
		std::swap(b_, rhs.b_);
	}

	constexpr operator bool() const {
		return a_ != 0;
	}

	constexpr operator T() const {
		return to_int();
	}

	constexpr operator long double() const {
		return to_double();
	}

	std::string to_string() const {
		return std::to_string(a_) + "/" + std::to_string(b_);
	}

	constexpr bool operator !() const {
		return a_ == 0;
	}

	constexpr Rational operator -() const {
		return negate();
	}

	constexpr Rational operator +() const {
		return{ a_, b_ };
	}

	Rational& operator ++() {
		a_ += b_;
		return *this;
	}

	Rational operator ++(int) {
		a_ += b_;
		return {a_ - b_, b_};
	}

	Rational& operator --() {
		a_ -= b_;
		return *this;
	}

	Rational operator --(int) {
		a_ -= b_;
		return{ a_ + b_, b_ };
	}

	constexpr Rational add(const Rational& rhs) const {
		return{ a_ * rhs.b_ + rhs.a_ * b_, b_ * rhs.b_ };
	}

	constexpr Rational subtract(const Rational& rhs) const {
		return add(rhs.negate());
	}

	constexpr Rational multiply(const Rational& rhs) const {
		return{ a_ * rhs.a_, b_ * rhs.b_ };
	}

	constexpr Rational divide(const Rational& rhs) const {
		return{ a_ * rhs.b_, b_ * rhs.a_ };
	}

	constexpr Rational operator +(const Rational& rhs) const {
		return add(rhs);
	}

	constexpr Rational operator -(const Rational& rhs) const {
		return subtract(rhs);
	}

	constexpr Rational operator *(const Rational& rhs) const {
		return multiply(rhs);
	}

	constexpr Rational operator /(const Rational& rhs) const {
		return divide(rhs);
	}

	constexpr T a() const {
		return a_;
	}

	constexpr T b() const {
		return b_;
	}

	Rational& operator +=(const Rational& rhs) {
		Rational res = add(rhs);
		swap(res);
		return *this;
	}

	Rational& operator -=(const Rational& rhs) {
		Rational res = subtract(rhs);
		swap(res);
		return *this;
	}

	Rational& operator *=(const Rational& rhs) {
		Rational res = multiply(rhs);
		swap(res);
		return *this;
	}

	Rational& operator /=(const Rational& rhs) {
		Rational res = divide(rhs);
		swap(res);
		return *this;
	}

	constexpr friend bool operator ==(const Rational& lhs, const Rational& rhs) {
		return lhs.a_ == rhs.a_ && lhs.b_ == rhs.b_;
	}

	constexpr friend bool operator !=(const Rational& lhs, const Rational& rhs) {
		return !(lhs == rhs);
	}

	constexpr friend bool operator <(const Rational& lhs, const Rational& rhs) {
		return lhs.a_ * rhs.b_ < rhs.a_ * lhs.b_;
	}

	constexpr friend bool operator >(const Rational& lhs, const Rational& rhs) {
		return rhs < lhs;
	}

	constexpr friend bool operator <=(const Rational& lhs, const Rational& rhs) {
		return lhs.a_ * rhs.b_ <= rhs.a_ * lhs.b_;
	}

	constexpr friend bool operator >=(const Rational& lhs, const Rational& rhs) {
		return rhs <= lhs;
	}

	friend std::ostream& operator << (std::ostream& out, const Rational& rational) {
		return out << rational.to_string();
	}

	friend std::istream& operator >> (std::istream& in, Rational& rational) {
		in >> rational .a_ >> rational.b_;
		rational.normalize();
		return in;
	}

	void normalize() {
		const T g = gcd(a_, b_);
		a_ /= g;
		b_ /= g;
		if (b_ < 0) {
			a_ = -a_;
			b_ = -b_;
		}
	}

	void read_slash(std::istream& in) {
		char ch;
		in >> a_ >> ch >> b_;
		normalize();
	}

	void print_slash(std::ostream& out) const {
		out << a_ << "/" << b_;
	}

	constexpr Rational negate() const {
		return{ -a_, b_ };
	}

	constexpr Rational abs() const {
		return a_ < 0 ? Rational(-a_, b_) : Rational(a_, b_);
	}

	constexpr Rational inverse() const {
		return{ b_, a_ };
	}

	constexpr int sign() const {
		return a_ < 0 ? -1 : static_cast<int>(a_ > 0);
	}

	constexpr long double to_double() const {
		return static_cast<long double>(a_) / b_;
	}

	constexpr T to_int() const {
		return a_ / b_;
	}

	constexpr T floor() const {
		return to_int();
	}

	constexpr T ceil() const {
		return static_cast<T>(ceil(to_double() - EPS));
	}

	constexpr T round() const {
		const long double cur = to_double();
		return static_cast<T>(cur < 0 ? ceil(cur - 0.5 - EPS) : floor(cur + 0.5 + EPS));
	}

	constexpr long double frac() const {
		return to_double() - to_int();
	}

	constexpr Rational pow(const ll n) const {
		return{ binpow(a_, n), binpow(b_, n) };
	}

private:
	T a_;
	T b_;
};

namespace std {

template<typename T>
std::string to_string(const Rational<T>& arg) {
	return arg.to_string();
}

template<typename T>
struct hash<Rational<T>> {
	size_t operator()(const Rational<T>& arg) const {
		return hash<pair<T, T>>({ arg.a, arg.b });
	}
};

template<typename T>
void swap(Rational<T>& lhs, Rational<T>& rhs) {
	lhs.swap(rhs);
}

}  



class id0 {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = true;

	using Ratio = Rational<ll>;

	void solve(std::istream& in, std::ostream& out) {
		int h, c, t;
		in >> h >> c >> t;

		if (2 * t <= h + c) {
			out << 2 << std::endl;
			return;
		}

		ll L = 0;
		ll R = 1e6;

		const ld id23 = 1e-16;

		auto check = [t, h, c](const ll hot) {
			return (Ratio{(hot + 1) * h + hot * c, 2 * hot + 1} - Ratio{t}).abs();
		};

		while (R - L > 2) {
			ll diff = (R - L);
			ll m1 = L + diff / 3;
			ll m2 = R - diff / 3;






			if (check(m1) < check(m2)) {
				R = m2;
			} else {
				L = m1;
				

			}
		}

		Ratio best = check(0);
		ll ans = 0;
		for (ll i : range(std::max(L - 10, 0LL), R + 10)) {
			const Ratio cur_value = check(i);
			if (best > cur_value) {
				best = cur_value;
				ans = i;
			}
		}
		out << ans * 2 + 1 << std::endl;

		
	}

	int solve_stupid(const double hot, const double cold, const double temp) {
		if (temp * 2 <= hot + cold) {
			return 2;
		}

		double best_diff = INF;
		double prev_diff = INF;
		int jans = 1;
		int cnt = 0;

		for (int i : range(1, 100000)) {
			const double cur_temp = (hot * i + cold * (i - 1)) / (2 * i - 1);
			const double cur_diff = std::abs(cur_temp - temp);
			if (cur_diff + EPS < best_diff) {
				best_diff = cur_diff;
				jans = 2 * i - 1;
			} else {
				if (cur_diff > prev_diff + EPS) {
					++cnt;
					if (cnt == 10) {
						break;
					}
				} else {
					cnt = 0;
					prev_diff = cur_diff;
				}
			}
		}
		return jans;
	}


	id0() {}


	static constexpr bool kUseCustomChecker = true;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		int testsCount;
		in >> testsCount;

		

		for (int test_id : range(testsCount)) {
			int h, c, t;
			in >> h >> c >> t;
			int pans, jans;
			out >> pans;
			jury >> jans;
			if (pans != jans) {
				debug("FAIL", test_id);
				debug(h, c, t);
				debug(pans, jans);
				return false;
			}
		}

		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static constexpr bool kStopAfterFirstFail = true;
	static void generate_test(std::ostream& test) {
		const int id14 = 1000000;

		const int cold = Random::get(1, id14);
		const int hot = Random::get(cold, id14);
		const int temp = Random::get(cold, hot);
		test << 1 << std::endl;
		test << hot << " " << cold << " " << temp << std::endl;
	}

};


int main() {
	id0 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (id0::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (id0::kWriteCaseNumber) {
				out << "Case 
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
