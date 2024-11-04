





















































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

std::vector<std::string> id12(std::string s) {
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
constexpr id1<IntegerRange<T>> id7(const T from) {
	return reversed(range(from + 1));
}

template<typename T>
constexpr id1<IntegerRange<T>> id7(const T from, const T to) {
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
	static const uint64_t id5 = id0();
	return id5;
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
inline bool id6(const T& a) {
	return abs(a) < EPS;
}

template<typename T, typename std::enable_if<!std::is_floating_point<T>::value>::type* = nullptr>
inline bool id6(const T& a) {
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

inline size_t id13(const size_t month, const size_t year) {
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







template<typename T>
class id14 {
public:
	using value_type = T;
	using size_type = std::size_t;
	using container_type = std::vector<value_type>;

	explicit id14(const size_type n) : size_(n), data_(n, 0) {}

	explicit id14(const std::vector<value_type>& a) : size_(a.size()) {
		for (size_type i = 0; i < size_; ++i) {
			inc(i, a[i]);
		}
	}

	void clear() {
		data_.assign(size_, 0);
	}

	size_type size() const {
		return size_;
	}

	container_type& data() {
		return data_;
	}

	const container_type& data() const {
		return data_;
	}

	void inc(int v, const value_type delta) {
		for (; v < size_; v = (v | (v + 1))) {
			data_[v] += delta;
		}
	}

	value_type query(int v) const
	

	{
		value_type res = 0;
		for (; v >= 0; v = (v & (v + 1)) - 1) {
			res += data_[v];
		}
		return res;
	}

	value_type query(const int left, const int right) const
	

	{
		if (right < left) {
			return 0;
		}
		return query(right) - query(left - 1);
	}

private:
	size_type size_;
	container_type data_;
};

template<class T> class id11 {
public:
	T * add, * mul;
	int N;

	id11(const int N) : N(N) {
		add = new T[N];
		mul = new T[N];
		std::fill_n(add, N, 0);
		std::fill_n(mul, N, 0);
	}

	~id11() {
		delete[] add;
		delete[] mul;
	}

	void clear() {
		std::fill_n(add, N, 0);
		std::fill_n(mul, N, 0);
	}

	void setSize(const int n) {
		N = n;
	}

	void build(T a[], const int n) {
		N = n;
		for (int i = 0; i < N; ++i) {
			update(i, i, a[i]);
		}
	}

	void update(const int left, const int right, const T by) {
		if (left > right) {
			return;
		}
		_update(left, by, -by * (left - 1));
		_update(right, -by, by * right);
	}

	T query(int at) const {
		T resMul = 0;
		T resAdd = 0;
		int start = at;
		while (at >= 0) {
			resMul += mul[at];
			resAdd += add[at];
			at = (at & (at + 1)) - 1;
		}
		return resMul * start + resAdd;
	}

	T query(const int left, const int right) const {
		return query(right) - query(left - 1);
	}

private:
	void _update(int at, const T updMul, const T updAdd) {
		while (at < N) {
			mul[at] += updMul;
			add[at] += updAdd;
			at |= (at + 1);
		}
	}

};

class id4 {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;

	using Tree = id14<int>;

	void solve(std::istream& in, std::ostream& out) {
		auto a = input(in);
		const int n = a.size();
		const int m = a.front().size();
		std::vector<Tree> trees(n + m, Tree(n + m));

		auto z_left = make_vector<int>(n, m, 0);
		for (int i : range(n)) {
			for (int j : range(m)) {
				const int prev = (j > 0 ? z_left[i][j - 1] : 0);
				z_left[i][j] = (a[i][j] == 'z' ? prev + 1 : 0);
			}
		}

		auto z_right = make_vector<int>(n, m, 0);
		for (int i : range(n)) {
			for (int j : downrange(m)) {
				const int prev = (j < m - 1 ? z_right[i][j + 1] : 0);
				z_right[i][j] = (a[i][j] == 'z' ? prev + 1 : 0);
			}
		}

		auto z_down = make_vector<int>(n, m, 0);
		for (int i : downrange(n)) {
			for (int j : range(m)) {
				const int prev = (i < n - 1 && j > 0 ? z_down[i + 1][j - 1] : 0);
				z_down[i][j] = (a[i][j] == 'z' ? prev + 1 : 0);
			}
		}

		std::vector<std::pair<int, pii>> updates;
		updates.reserve(n * m);
		for (int i : range(n)) {
			for (int j : range(m)) {
				const int col = z_right[i][j] + j - 1;
				if (col >= j) {
					updates.emplace_back(col, pii{i, j});
				}
			}
		}
		sort(updates);
		reverse(updates);

		int index = 0;
		ll ans = 0;
		for (int j : downrange(m)) {
			while (index < updates.size() && updates[index].first == j) {
				const auto& it = updates[index].second;
				const int tree_id = it.X + it.Y;
				trees[tree_id].inc(it.Y, 1);
				++index;
			}
			for (int i : range(n)) {
				const int mn = std::min(z_left[i][j], z_down[i][j]);
				if (mn == 0) {
					continue;
				}
				ans += trees[i + j].query(j - mn + 1, j);
			}
		}

		out << ans << std::endl;
	}

	std::vector<std::string> input(std::istream& in) {
		int n, m;

		in >> n >> m;
		auto a = make_vector<std::string>(n, "");
		in >> a;

		scanf("%d%d", &n, &m);
		auto a = make_vector<std::string>(n, "");
		char s[3333];
		for (int i : range(n)) {
			scanf("%s", s);
			a[i] = std::string(s);
		}

		return a;
	}


	id4() {}


	static constexpr bool kUseCustomChecker = false;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static constexpr bool kStopAfterFirstFail = false;
	static void generate_test(std::ostream& test) {}

};


int main() {
	id4 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (id4::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (id4::kWriteCaseNumber) {
				out << "Case 
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
