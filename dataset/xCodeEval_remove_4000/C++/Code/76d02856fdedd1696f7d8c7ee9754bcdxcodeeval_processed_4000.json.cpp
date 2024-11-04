
 




 

 
 






























 
 
 
 
 
 
 
 
 
 
 
 


template <bool... Bools>
struct Disjunction : std::false_type {};
 
template <bool First, bool... Others>


struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {};
 

template <bool... Bools>
constexpr bool id8 = Disjunction<Bools...>::value;
 
static_assert(!id8<>, "");
static_assert(!id8<false, false>, "");
static_assert(id8<true>, "");
static_assert(id8<false, true>, "");
static_assert(id8<true, false>, "");
static_assert(id8<false, false, true, true>, "");

 
 

 
 
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

 
void id3() {
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
class id1 {
public:
	using const_iterator = typename std::decay<T>::type::const_iterator;
	using reverse_iterator = std::reverse_iterator<const_iterator>;
 
	explicit constexpr id1(const T& iterable) : begin_(iterable.begin()), end_(iterable.end()) {}
 
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
id1<T> reversed(T&& iterable) {
	return id1<T>{iterable};
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
constexpr id1<IntegerRange<T>> downrange(const T from) {
	return reversed(range(from));
}
 
template<typename T>
constexpr id1<IntegerRange<T>> downrange(const T from, const T to) {
	return reversed(range(to, from));
}
 
template<typename T>
constexpr id1<IntegerRange<T>> id6(const T from) {
	return reversed(range(from + 1));
}
 
template<typename T>
constexpr id1<IntegerRange<T>> id6(const T from, const T to) {
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
bool id10(R& range) {
	return std::id10(range.begin(), range.end());
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
 
inline uint64_t id9() {
	static const uint64_t id4 = id0();
	return id4;
}
 
using Engine = std::mt19937_64;
 
template<typename T>
using Distribution = std::uniform_int_distribution<T>;
 
inline Engine& random_engine() {
	static Engine engine(id9());
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
inline bool id5(const T& a) {
	return abs(a) < EPS;
}
 
template<typename T, typename std::enable_if<!std::is_floating_point<T>::value>::type* = nullptr>
inline bool id5(const T& a) {
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
inline bool id2(const T year) {
	return year % 400 == 0 || (year % 100 != 0 && (year & 3) == 0);
}
 
inline size_t id11(const size_t month, const size_t year) {
	return kDayMonth[month] + (month == 1 && id2(year) ? 1 : 0);
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
 
 
 
class id7 {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = true;
	void solve(std::istream& in, std::ostream& out) {
        int n;
        in >> n;
        n *= 2;
        std::vector<int> a(n);
        in >> a;
 
        const int array_len = n / 2;
 
        std::vector<std::vector<int>> chains;
        std::vector<int> items;
        int index = 0;
        while (index < n) {
            const int start = a[index];
            chains.emplace_back(std::vector<int>());
            while (index < n && a[index] <= start) {
                chains.back().emplace_back(a[index]);
                ++index;
            }
            items.emplace_back(chains.back().size());
        }
        debug(chains);
        debug(items);
 
        const int items_count = items.size();
        auto dp = make_vector<bool>(items_count + 1, n + 1,false);
        dp[0][0] = true;
        for (int item : range(items_count)) {
            const int cur_size = items[item];
            dp[item + 1] = dp[item];
            for (int total : range(n)) {
                if (!dp[item][total] || total + cur_size > array_len) {
                    continue;
                }
                dp[item + 1][total + cur_size] = true;
            }
            debug(dp[item]);
        }
 
        int start = -1;
        for (int item : inclusiveRange(1, items_count)) {
            if (dp[item][array_len]) {
                start = item;
                break;
            }
        }
        if (start == -1) {
            out << "NO" << std::endl;
            return;
        }
        out << "YES" << std::endl;
	}
 
 
	id7() {}
 
 
	static constexpr bool kUseCustomChecker = false;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		return true;
	}
 
 
	static constexpr size_t kGeneratedTestsCount = 0;
	static constexpr bool kStopAfterFirstFail = false;
	static void generate_test(std::ostream& test) {}
 
};
 
 
int main() {
	id7 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
 
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (id7::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (id7::kWriteCaseNumber) {
				out << "Case 
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}