








































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






















template<typename T>
inline bool id5(const T& a) {
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


static uint32_t __inline id17(uint32_t x) {
	unsigned long r = 0;
	_BitScanReverse(&r, x);
	return (31 - r);
}

static uint32_t __inline id16(uint32_t x) {
	unsigned long r = 0;
	_BitScanForward(&r, x);
	return r;
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
inline bool id1(const T year) {
	return year % 400 == 0 || (year % 100 != 0 && (year & 3) == 0);
}

inline size_t id14(const size_t month, const size_t year) {
	return kDayMonth[month] + (month == 1 && id1(year) ? 1 : 0);
}
















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

template<typename Key, typename std::enable_if<std::is_integral<Key>::value>::type* = nullptr>
using SafeUnorderedSet = std::unordered_set<Key, SafeIntegralHash<Key>>;





























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


void id2() {
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
class id15 {
public:
	using const_iterator = IntegerIterator<T>;
	using reverse_iterator = std::reverse_iterator<const_iterator>;

	constexpr id15(const T begin, const T end) : begin_(begin), end_(end) {}

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
constexpr id15<T> downrange(const T from) {
	return id15<T>(from, 0);
}

template<typename T>
constexpr id15<T> downrange(const T from, const T to) {
	return id15<T>(from, to);
}

template<typename T>
constexpr id15<T> id6(const T from) {
	return id15<T>(from + 1, 0);
}

template<typename T>
constexpr id15<T> id6(const T from, const T to) {
	return id15<T>(from + 1, to);
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
bool id12(R& range) {
	return std::id12(range.begin(), range.end());
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





template<size_t N>
class Bitset {
public:
	static const int id10 = (N >> 6) + 1;
	unsigned long long data[id10];

	Bitset() {
		std::fill_n(data, id10, 0);
	}

	Bitset& set(const int x) {
		data[x >> 6] |= (1LL << (x & 63));
		return *this;
	}

	Bitset& flip(const int x) {
		data[x >> 6] ^= (1LL << (x & 63));
		return *this;
	}

	Bitset& clear(const int x) {
		data[x >> 6] &= ~(1LL << (x & 63));
		return *this;
	}

	bool get(const int x) const {
		return data[x >> 6] & (1LL << (x & 63));
	}

	int size() const {
		return N;
	}

	bool any() const {
		for (int i = 0; i < id10; ++i) {
			if (data[i]) {
				return true;
			}
		}
		return false;
	}

	bool none() const {
		for (int i = 0; i < id10; ++i) {
			if (data[i]) {
				return false;
			}
		}
		return true;
	}

	Bitset& reset() {
		std::fill_n(data, id10, 0);
		return *this;
	}

	Bitset& set() {
		std::fill_n(data, id10, 0xffffffffffffffffLL);
		return *this;
	}

	Bitset& flip() {
		for (int i = 0; i < id10; ++i) {
			data[i] = ~data[i];
		}
		return *this;
	}

	int count() const {
		int ret = 0;
		for (int i = 0; i < id10; ++i) {
			ret += popcount(data[i]);
		}
		return ret;
	}

	Bitset& operator &= (const Bitset& bitset) {
		for (int i = 0; i < id10; ++i) {
			data[i] &= bitset.data[i];
		}
		return *this;
	}

	Bitset& operator |= (const Bitset& bitset) {
		for (int i = 0; i < id10; ++i) {
			data[i] |= bitset.data[i];
		}
		return *this;
	}

	Bitset& operator ^= (const Bitset& bitset) {
		for (int i = 0; i < id10; ++i) {
			data[i] ^= bitset.data[i];
		}
		return *this;
	}

	Bitset operator ~ () const {
		Bitset ret;
		for (int i = 0; i < id10; ++i) {
			ret.data[i] = ~data[i];
		}
		return ret;
	}

	bool operator == (const Bitset& bitset) const {
		for (int i = 0; i < id10; ++i) {
			if (data[i] != bitset.data[i]) {
				return false;
			}
		}
		return true;
	}

	bool operator != (const Bitset& bitset) const {
		for (int i = 0; i < id10; ++i) {
			if (data[i] != bitset.data[i]) {
				return true;
			}
		}
		return false;
	}

	Bitset operator & (const Bitset& bitset) const {
		Bitset ret;
		for (int i = 0; i < id10; ++i) {
			ret.data[i] = data[i] & bitset.data[i];
		}
		return ret;
	}

	Bitset operator | (const Bitset& bitset) const {
		Bitset ret;
		for (int i = 0; i < id10; ++i) {
			ret.data[i] = data[i] | bitset.data[i];
		}
		return ret;
	}

	Bitset operator ^ (const Bitset& bitset) const {
		Bitset ret;
		for (int i = 0; i < id10; ++i) {
			ret.data[i] = data[i] ^ bitset.data[i];
		}
		return ret;
	}

	Bitset rotate_left(const size_t shift) const {
		Bitset ret;
		int full_shift = shift >> 6;
		int rem_shift = shift & 63;
		for (int i = 0; i < id10; ++i) {
			int ind = i + full_shift;
			if (ind >= id10) {
				ind -= id10;
			}
			int prv = i - 1;
			if (prv < 0) {
				prv += id10;
			}
			ret.data[ind] = (data[i] << rem_shift) | (data[prv] >> (64 - rem_shift));
		}
		return ret;
	}

};












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

inline void id18(const size_t n, std::vector<bool>* prime) {
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

inline void id18(std::vector<bool>* prime) {
	id18(prime->size(), prime);
}

template<typename T>
inline void id9(const size_t n, std::vector<T>* primes) {
	std::vector<T> result;
	if (n < 2) {
		primes->swap(result);
		return;
	}
	std::vector<bool> prime(n);
	id18(&prime);
	result.emplace_back(2);
	for (size_t i = 3; i < n; i += 2) {
		if (prime[i]) {
			result.emplace_back(i);
		}
	}
	primes->swap(result);
}

template<typename T>
inline void id7(const size_t n, std::vector<T>* min_prime_div) {
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
inline void id7(std::vector<T>* min_prime_div) {
	id7(min_prime_div->size(), min_prime_div);
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
T id13(T n) {
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

inline void id3(int r[], const int n, const int mod)


{
	r[1] = 1;
	for (int i = 2; i < n; ++i) {
		r[i] = (mod - static_cast<long long>(mod) / i * r[mod % i] % mod) % mod;
	}
}

template<typename T>
T id11(const T n, const T mod)


{
	return binpow(n, id13(mod) - 1, mod);
}

template<typename T>
void id4(const size_t n, std::vector<std::vector<T>>* c) {
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
void id8(std::vector<T>& deg, const T base) {
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

	static std::chrono::system_clock::rep id0() {
		return std::chrono::system_clock::now().time_since_epoch().count();
	}

	static std::mt19937_64 gen(id0());
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


const int MAXN = 3003;

using bitset = Bitset<MAXN * MAXN>;
using modint = ModInt<int, 998244353>;

bitset begin[32];
bitset end[32];

modint dp[2][MAXN];

class EKaaviIMagicheskoeZaklinanie {
public:
	void solve(std::istream& in, std::ostream& out) {
		

		for (int i : range(32)) {
			begin[i].reset();
			end[i].reset();
		}
		std::string s;
		std::string t;
		in >> s >> t;
		std::vector<int> a(all(s));
		n = a.size();
		std::vector<int> b(all(t));
		m = b.size();
		for (int& x : a) {
			x -= 'a';
		}
		for (int& x : b) {
			x -= 'a';
		}

		for (int i : range(m)) {
			for (int j : range(i, m)) {
				if (i == j) {
					mark(begin[b[i]], i + 1, j + 1);
					mark(end[b[j]], i, i);
					continue;
				} else {
					mark(end[b[j]], i, j);
					mark(begin[b[i]], i + 1, j + 1);
				}
			}
		}

		fill(dp, 0);
		const int cur_char = a.front();
		for (int i : range(m)) {
			if (b[i] == cur_char) {
				dp[0][i] = 2;
			}
		}
		dp[0][m] = 2;

		for (int i : range(m + 1)) {
			if (dp[0][i] > 0) {
				

			}
		}

		modint ans = 0;
		if (m == 1) {
			ans += dp[0][0];
		}
		for (int idx : range(1, n)) {
			

			const int next = idx & 1;
			const int prev = next ^ 1;
			const int value = a[idx];
			for (int i : range(m + 1)) {
				dp[next][i] = 0;
			}

			for (int i : range(m + 1)) {
				const modint cur = dp[prev][i];
				const int x = i;
				const int y = std::min(m, i + idx);
				if (cur > 0) {
					if (way_end(x, y, value)) {
						dp[next][x] += cur;
						

					} else
					if (y == m) {
						dp[next][x] += cur;
						

					}
					if (way_begin(x, y, value)) {
						dp[next][x - 1] += cur;
						

					}
				}
			}
			if (idx + 1 >= m) {
				ans += dp[next][0];
			}
			dp[next][m] = dp[prev][m] * 2;

			for (int i : range(m + 1)) {
				if (dp[next][i] > 0) {
					

				}
			}
		}
		out << ans << std::endl;

	}

	bool way_begin(const int x, const int y, const int ch) const {
		return begin[ch].get(bit_id(x, y));
	}

	bool way_end(const int x, const int y, const int ch) const {
		return end[ch].get(bit_id(x, y));
	}

	void mark(bitset& set, const int x, const int y) const {
		set.set(bit_id(x, y));
	}

	size_t bit_id(const int x, const int y) const {
		return x * (m + 1) + y;
	}

	bool check(std::string input, std::string expected_output, std::string actual_output) {
		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 1;
	static void generate_test(std::ostream& test) {
		test << std::string(3000, 'a') << std::endl;
		test << std::string(1500, 'a') << std::endl;
	}

private:
	int n, m;
	size_t test_id_ = 0;
};


int main() {
	EKaaviIMagicheskoeZaklinanie solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	solver.solve(in, out);
	return 0;
}
