





















































template <bool... Bools>
struct Disjunction : std::false_type {};

template <bool First, bool... Others>


struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {};


template <bool... Bools>
constexpr bool id17 = Disjunction<Bools...>::value;

static_assert(!id17<>, "");
static_assert(!id17<false, false>, "");
static_assert(id17<true>, "");
static_assert(id17<false, true>, "");
static_assert(id17<true, false>, "");
static_assert(id17<false, false, true, true>, "");






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

std::vector<std::string> id24(std::string s) {
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


void id7() {
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
class id4 {
public:
	using const_iterator = typename std::decay<T>::type::const_iterator;
	using reverse_iterator = std::reverse_iterator<const_iterator>;

	explicit constexpr id4(const T& iterable) : begin_(iterable.begin()), end_(iterable.end()) {}

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
id4<T> reversed(T&& iterable) {
	return id4<T>{iterable};
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
constexpr id4<IntegerRange<T>> downrange(const T from) {
	return reversed(range(from));
}

template<typename T>
constexpr id4<IntegerRange<T>> downrange(const T from, const T to) {
	return reversed(range(to, from));
}

template<typename T>
constexpr id4<IntegerRange<T>> id13(const T from) {
	return reversed(range(from + 1));
}

template<typename T>
constexpr id4<IntegerRange<T>> id13(const T from, const T to) {
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
bool id22(R& range) {
	return std::id22(range.begin(), range.end());
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

inline uint64_t id0() {
	return static_cast<uint64_t>(current_timestamp());
}

inline uint64_t id19() {
	static const uint64_t id11 = id0();
	return id11;
}

using Engine = std::mt19937_64;

template<typename T>
using Distribution = std::uniform_int_distribution<T>;

inline Engine& random_engine() {
	static Engine engine(id19());
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
inline bool id12(const T& a) {
	return abs(a) < EPS;
}

template<typename T, typename std::enable_if<!std::is_floating_point<T>::value>::type* = nullptr>
inline bool id12(const T& a) {
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
inline bool id6(const T year) {
	return year % 400 == 0 || (year % 100 != 0 && (year & 3) == 0);
}

inline size_t id25(const size_t month, const size_t year) {
	return kDayMonth[month] + (month == 1 && id6(year) ? 1 : 0);
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
std::vector<T> id14(const T n) {
	const auto id21 = static_cast<size_t>(cbrt(n));
	std::vector<T> ans;
	ans.reserve(id21);
	const auto id1 = static_cast<T>(sqrt(n));
	for (T i = 1; i <= id1; ++i) {
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
T id23(T n) {
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

inline void id9(int r[], const int n, const int mod)


{
	r[1] = 1;
	for (int i = 2; i < n; ++i) {
		r[i] = (mod - static_cast<long long>(mod) / i * r[mod % i] % mod) % mod;
	}
}

template<typename T>
T id20(const T n, const T mod)


{
	return binpow(n, id23(mod) - 1, mod);
}

template<typename T>
void id10(const size_t n, std::vector<std::vector<T>>* c) {
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
std::vector<T> id15(const T base, const size_t n) {
	std::vector<T> powers(n + 1);
	powers[0] = 1;
	for (size_t i = 1; i < powers.size(); ++i) {
		powers[i] = powers[i - 1] * base;
	}
	return powers;
}

template<typename T>
std::vector<T> id27(const size_t n) {
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


constexpr const int id28 = 1000000007;  


template<typename T>
inline T& add_mod(T& a, const T b, const T mod = id28) {
	if ((a += b) >= mod) {
		a -= mod;
	}
	return a;
}

template<typename T>
inline T& sub_mod(T& a, const T b, const T mod = id28) {
	if ((a -= b) < 0) {
		a += mod;
	}
	return a;
}

template<typename T>
inline T& mul_mod(T& a, const T b, const T mod = id28) {
	a = static_cast<long long>(a) * b % mod;
	return a;
}

template<typename T, T MOD = id28>
class ModInt {
public:
	using value_type = T;

	

	constexpr ModInt() : ModInt(0) {}

	constexpr ModInt(const value_type value) : value_(value) {
		static_assert(MOD > 0, "Modulo must be strictly positive.");
		

	}

	template<typename U>
	constexpr static ModInt from_integer(const U value) {
		return {ModInt::normalize(value)};
	}

	constexpr value_type value() const {
		return value_;
	}

	constexpr value_type mod() const {
		return MOD;
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
		value_type x = value_;
		return {add_mod(x, rhs.value_, MOD)};
	}

	ModInt operator -(const ModInt rhs) const {
		value_type x = value_;
		return {sub_mod(x, rhs.value_, MOD)};
	}

	ModInt operator *(const ModInt rhs) const {
		value_type x = value_;
		return {mul_mod(x, rhs.value_, MOD)};
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
		add_mod(value_, static_cast<value_type>(1), MOD);
		return ret;
	}

	ModInt operator --(int) {
		const ModInt ret(value_);
		sub_mod(value_, static_cast<value_type>(1), MOD);
		return ret;
	}

	ModInt& operator ++() {
		add_mod(value_, static_cast<value_type>(1), MOD);
		return *this;
	}

	ModInt& operator --() {
		sub_mod(value_, static_cast<value_type>(1), MOD);
		return *this;
	}

	constexpr ModInt operator +() const {
		return{ value_ };
	}

	constexpr ModInt operator -() const {
		return negate();
	}

	constexpr ModInt negate() const {
		return {ModInt::normalize(-value_)};
	}

	constexpr ModInt inverse() const {
		return {inverse_element(value_, MOD)};
	}

	std::string str() const {
		return std::to_string(value_);
	}

	template<typename C>
	C as() const {
		return static_cast<C>(value_);
	}

	friend std::istream& operator >>(std::istream& in, ModInt& rhs) {
		value_type x;
		in >> x;
		rhs.value_ = ModInt::normalize(x);
		return in;
	}

	friend std::ostream& operator <<(std::ostream& out, const ModInt& rhs) {
		out << rhs.value_;
		return out;
	}

private:
	value_type value_;

	template<typename U>
	static value_type normalize(const U value) {
		if (value >= 0 && value < MOD) {
			return value;
		}
		const value_type ret = value % MOD;
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


class id16 {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;

	using Int = ModInt<ll, 1000000007>;

	void solve(std::istream& in, std::ostream& out) {
		int n, k;
		ll l;
		in >> n >> l >> k;
		std::vector<pii> a;
		for (int i : range(n)) {
			int x;
			in >> x;
			a.emplace_back(x, i);
		}
		sort(a);

		const ll full = l / n;
		const ll rem = l % n;

		auto dp = make_vector<Int>(n, k + 1, 0);
		auto last = make_vector<Int>(n, k + 1, 0);
		for (int i : range(n)) {
			dp[i][1] = 1;
			if (a[i].second < rem) {
				last[i][1] = 1;
			}
		}

		for (int j : range(2, k + 1)) {
			Int sum = 0;
			Int sum_last = 0;
			int index = n - 1;
			for (int i : downrange(n)) {
				while (index >= 0 && a[index].first >= a[i].first) {
					sum += dp[index][j - 1];
					sum_last += last[index][j - 1];
					--index;
				}
				dp[i][j] = sum;
				last[i][j] = sum_last;
			}
		}

		for (int i : range(n)) {
			

		}

		for (int i : range(n)) {
			

		}

		Int ans = 0;
		for (int i : range(n)) {
			for (int j : range(1, k + 1)) {
				if (j <= full + 1) {
					ans += last[i][j];
				}
				ans += dp[i][j] * Int::from_integer(std::max(0LL, (full - j + 1)));
			}
		}

		out << ans << std::endl;
	}


	id16() {}


	static constexpr bool kUseCustomChecker = false;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		int n, l, k;
		in >> n >> l >> k;
		std::vector<int> b(n);
		in >> b;

		std::vector<int> a;
		a.reserve(l);
		for (int i : range(l)) {
			a.emplace_back(b[i % n]);
		}

		auto dp = make_vector<Int>(l, k + 1, 0);
		for (int i : range(l)) {
			dp[i][1] = 1;
		}

		Int jans = l;
		for (int i : downrange(l)) {
			const int block_id = i / n;
			const int id26 = std::min(l, (block_id + 1) * n);
			const int id2 = std::min(l, (block_id + 2) * n);
			const int cur_value = a[i];
			for (int j : range(2, k + 1)) {
				for (int x : range(id26, id2)) {
					if (a[x] >= a[i]) {
						dp[i][j] += dp[x][j - 1];
					}
				}
				jans += dp[i][j];
				

			}
		}

		Int pans;
		out >> pans;
		if (pans != jans) {
			debug(pans, jans);
			return false;
		}

		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static constexpr bool kStopAfterFirstFail = true;
	static void generate_test(std::ostream& test) {

		const int id18 = 100;
		const int id8 = 100;
		const int id5 = 1000;
		const int id3 = 100000;

		const int n = Random::get(1, id18);
		const int l = Random::get(1, id8);
		const int k = Random::get(1, id5);

		auto a = jngen::Array::random(n, 1, id3);
		test << n << " " << l << " " << k << std::endl;
		test << a << std::endl;

	}

};


int main() {
	id16 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (id16::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (id16::kWriteCaseNumber) {
				out << "Case 
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
