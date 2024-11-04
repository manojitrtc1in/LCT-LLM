





















































template <bool... Bools>
struct Disjunction : std::false_type {};

template <bool First, bool... Others>


struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {};


template <bool... Bools>
constexpr bool id16 = Disjunction<Bools...>::value;

static_assert(!id16<>, "");
static_assert(!id16<false, false>, "");
static_assert(id16<true>, "");
static_assert(id16<false, true>, "");
static_assert(id16<true, false>, "");
static_assert(id16<false, false, true, true>, "");






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

std::vector<std::string> id22(std::string s) {
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
constexpr id4<IntegerRange<T>> id11(const T from) {
	return reversed(range(from + 1));
}

template<typename T>
constexpr id4<IntegerRange<T>> id11(const T from, const T to) {
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
bool id21(R& range) {
	return std::id21(range.begin(), range.end());
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

inline uint64_t id18() {
	static const uint64_t id8 = id1();
	return id8;
}

using Engine = std::mt19937_64;

template<typename T>
using Distribution = std::uniform_int_distribution<T>;

inline Engine& random_engine() {
	static Engine engine(id18());
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
inline bool id10(const T& a) {
	return abs(a) < EPS;
}

template<typename T, typename std::enable_if<!std::is_floating_point<T>::value>::type* = nullptr>
inline bool id10(const T& a) {
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


static uint32_t __inline id25(uint32_t x) {
	unsigned long r = 0;
	_BitScanReverse(&r, x);
	return (31 - r);
}

static uint32_t __inline id24(uint32_t x) {
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
inline bool id6(const T year) {
	return year % 400 == 0 || (year % 100 != 0 && (year & 3) == 0);
}

inline size_t id23(const size_t month, const size_t year) {
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
inline bool is_prime(const T& n)


{
	if (n < 2) {
		return false;
	}
	const T id2 = static_cast<T>(sqrt(n));
	for (T i = 2; i <= id2; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

template<typename T>
inline T next_prime(const T& n) {
	for (T candidate = n; ; ++candidate) {
		if (is_prime(candidate)) {
			return candidate;
		}
	}
}

template<typename T>
inline T random_prime(const T from, const T to)




{
	return next_prime(Random::get(from, to));
}

template<typename T = uint32_t>
inline T id13(const T from = 1000000000, const T to = INF) {
	return random_prime(from, to);
}

inline std::vector<bool> id26(const size_t n) {
	if (n < 2) {
		return std::vector<bool>(n, false);
	}
	std::vector<bool> prime(n, true);
	prime[0] = false;
	prime[1] = false;
	for (size_t i = 4; i < n; i += 2) {
		prime[i] = false;
	}
	for (size_t i = 3; i * i < n; i += 2) {
		if (prime[i]) {
			const size_t delta = i * 2;
			for (size_t j = i * i; j < n; j += delta) {
				prime[j] = false;
			}
		}
	}
	return prime;
}

template<typename T = uint32_t>
inline std::vector<T> id19(const size_t n) {
	if (n < 2) {
		return {};
	}
	const std::vector<bool> prime = id26(n);
	std::vector<T> result = {2};
	for (size_t i = 3; i < n; i += 2) {
		if (prime[i]) {
			result.emplace_back(i);
		}
	}
	return result;
}

template<typename T = uint32_t>
inline std::vector<T> id12(const size_t n) {
	std::vector<T> result(n, 0);
	result[0] = 1;
	result[1] = 1;
	for (size_t i = 2; i < n; i += 2) {
		result[i] = 2;
	}
	size_t index = 3;
	while (index * index < n) {
		if (result[index] == 0) {
			result[index] = index;
			const size_t delta = index * 2;
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
	return result;
}


class id3 {
public:
	template<typename T>
	std::vector<T> id14(const T n) {
		const auto id20 = static_cast<size_t>(cbrt(n));
		std::vector<T> ans;
		ans.reserve(id20);
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

	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;
	void solve(std::istream& in, std::ostream& out) {
		int n, q;
		in >> n >> q;
		std::vector<int> a(n);
		in >> a;

		std::vector<std::vector<int>> id0(n);
		for (int i : range(n)) {
			const int x = a[i];
			const auto divs = id14(x);
			auto& id5 = id0[i];
			id5.reserve(divs.size());
			for (int div : divs) {
				if (good_divisors_set.find(div) != good_divisors_set.cend()) {
					id5.emplace_back(div);
				}
			}
		}

		std::vector<int> id15(kMaxn, 0);
		std::vector<bool> used(n, false);

		auto shelf = [&id15, &id0](const int index, const int delta) {
			for (int div : id0[index]) {
				id15[div] += delta;
			}
		};

		auto count = [&id15, &id0, this](const int index) {
			ll ans = 0;
			for (int div : id0[index]) {
				ans += id15[div] * div_multiplier[div];
			}
			return ans;
		};

		ll ans = 0;
		ll id9 = 0;
		for (int _ : range(q)) {
			debug(id15);
			int x;
			in >> x;
			--x;
			bool dry_run = false;
			int multiplier = 1;
			if (used[x]) {
				shelf(x, -1);
				dry_run = true;
				multiplier = -1;
				used[x] = false;
				--id9;
			}
			const ll cur_value = id9 - count(x);
			if (!dry_run) {
				shelf(x, 1);
				used[x] = true;
				++id9;
			}
			ans += cur_value * multiplier;
			out << ans << std::endl;
		}
	}

	const int kMaxn = 555555;
	std::vector<int> id17;
	SafeUnorderedSet<int> good_divisors_set;
	std::vector<int> div_multiplier;
	id3() {
		id17 = id12<int>(kMaxn);
		div_multiplier.assign(kMaxn, 0);
		for (int i : range(2, kMaxn)) {
			int cur = i;
			int last = -1;
			bool ok = true;
			int cnt = 0;
			while (cur > 1 && ok) {
				const int div = id17[cur];
				ok &= (last != div);
				last = div;
				cur /= div;
				++cnt;
			}
			if (ok) {
				good_divisors_set.emplace(i);
				div_multiplier[i] = (cnt % 2 == 1 ? 1 : -1);
			}
		}
	}


	static constexpr bool kUseCustomChecker = false;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static void generate_test(std::ostream& out) {}

};


int main() {
	id3 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (id3::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (id3::kWriteCaseNumber) {
				out << "Case 
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
