























































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

std::vector<std::string> id23(std::string s) {
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
	const std::string& arg = args[idx];
	const std::string value = ss.str();
	if (arg == value) {
		std::cerr << arg;
	} else {
		std::cerr << arg << " = " << value;
	}
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
class id5 {
public:
	using const_iterator = typename std::decay<T>::type::const_iterator;
	using reverse_iterator = std::reverse_iterator<const_iterator>;

	explicit constexpr id5(const T& iterable) : begin_(iterable.begin()), end_(iterable.end()) {}

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
id5<T> reversed(T&& iterable) {
	return id5<T>{iterable};
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
constexpr id5<IntegerRange<T>> downrange(const T from) {
	return reversed(range(from));
}

template<typename T>
constexpr id5<IntegerRange<T>> downrange(const T from, const T to) {
	return reversed(range(to, from));
}

template<typename T>
constexpr id5<IntegerRange<T>> id9(const T from) {
	return reversed(range(from + 1));
}

template<typename T>
constexpr id5<IntegerRange<T>> id9(const T from, const T to) {
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
bool id20(R& range) {
	return std::id20(range.begin(), range.end());
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

inline uint64_t id17() {
	static const uint64_t id8 = id0();
	return id8;
}

using Engine = std::mt19937_64;

template<typename T>
using Distribution = std::uniform_int_distribution<T>;

inline Engine& random_engine() {
	static Engine engine(id17());
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
		return static_cast<int64_t>(pair.first) * 877117 + pair.second;
	}
};


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

template<typename T, typename U, typename std::enable_if<is_container<T>::value && is_container<U>::value>::type* = nullptr>
T as_container(const U& collection) {
    return T{std::begin(collection), std::end(collection)};
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








class DSU {
public:
	using size_type = std::size_t;

	DSU() : DSU(0) {}

	explicit DSU(const size_type vertices_count) {
		init(vertices_count);
	}

	void init(const size_type vertices_count) {
		parent_.resize(vertices_count);
		std::iota(parent_.begin(), parent_.end(), 0);
		id26 = vertices_count;
	}

	size_type find_set(const size_type vertex) {
		if (vertex != parent_[vertex]) {
			parent_[vertex] = find_set(parent_[vertex]);
		}
		return parent_[vertex];
	}

	bool unite(const size_type a, const size_type b) {
		size_type x = find_set(a);
		size_type y = find_set(b);
		if (x == y) {
			return false;
		}
		if (Random::get(2) == 0) {
			std::swap(x, y);
		}
		parent_[x] = y;
		--id26;
		return true;
	}

	DSU& finalize() {
		for (auto& it : parent_) {
			it = find_set(it);
		}
		return *this;
	}

	size_type size() const {
		return parent_.size();
	}

	size_type sets_count() const {
		return id26;
	}

	const std::vector<size_type>& data() const {
		return parent_;
	}

private:
	std::vector<size_type> parent_;
	size_type id26;
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

template<typename T, typename U>
inline T binpow(T a, U b) {
	static_assert(std::is_integral<U>::value, "Degree must be integral. For real degree use pow().");
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

inline uint32_t abs(const uint32_t x) {
	return x;
}

inline uint64_t abs(const uint64_t x) {
	return x;
}






template<typename T>
class Queue {
public:
	using value_type = T;
	using size_type = std::size_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using rvalue = value_type&&;
	using container = std::vector<value_type>;

	explicit Queue(const size_type max_size) : data_(container(max_size)) {
		clear();
	}

	reference front() {
		return data_[id24];
	}

	const_reference front() const {
		return data_[id24];
	}

	reference back() {
		return data_[id21 - 1];
	}

	const_reference back() const {
		return data_[id21 - 1];
	}

	constexpr bool empty() const {
		return id24 == id21;
	}

	void clear() {
		id24 = 0;
		id21 = 0;
	}

	constexpr size_type size() const {
		return id21 - id24;
	}

	void push(const_reference value) {
		data_[id21++] = value;
	}

	void push(rvalue value) {
		data_[id21++] = std::move(value);
	}

	value_type pop_front() {
		return data_[id24++];
	}

	value_type pop_back() {
		return data_[--id21];
	}

	void swap(Queue& rhs) {
		data_.swap(rhs.data_);
		std::swap(id24, rhs.id24);
		std::swap(id21, rhs.id21);
	}

	const container& data() const {
		return data_;
	}

	bool operator ==(const Queue& rhs) const {
		return id24 == rhs.id24 && id21 == rhs.id21 && data_ == rhs.data_;
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
	size_type id24;
	size_type id21;
};


enum GraphType {
	Weighted = 1
};

template<size_t MASK>
struct is_weighted
{
	

	static constexpr bool value = (MASK & GraphType::Weighted) != 0;
};

template<typename T = int64_t, size_t MASK = 0>
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
		class id19 : public BaseConstIterator {
		public:
			using value_type = Edge;
			using pointer = const value_type*;
			using const_reference = const value_type&;

			constexpr explicit id19(BaseConstIterator it, const std::vector<size_t>& from,
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

		using const_iterator = id19<typename Range::const_iterator>;
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

	explicit Graph(const size_t vertices_count) {
		init(vertices_count);
	}

	virtual ~Graph() {
		clear();
	}

	void init(const size_t vertices_count) {
		clear();
		id22 = vertices_count;
		edges_.resize(id22);
	}

	IntegerRange<size_t> vertices() const {
		return range(id22);
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

	const std::vector<size_t>& edges_list(const size_t vertex) const {
	    return edges_[vertex];
	}

	void clear();

	size_t vertices_count() const {
		return id22;
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
		return Edge(from_, to_, weight_, index);
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	T weight(const size_t index) const {
		return weight_[index];
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	T id11() const {
		return std::numeric_limits<T>::max() / 2;
	}

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void id1(const size_t from, const size_t to) {
		push_edge(from, to);
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void id1(const size_t from, const size_t to, const T weight) {
		weight_.emplace_back(weight);
		push_edge(from, to);
	}

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void id1(const Edge& edge) {
		id1(edge.from(), edge.to());
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void id1(const Edge& edge) {
		id1(edge.from(), edge.to(), edge.weight());
	}

	bool is_sparse() const {
		return id22 == 0 || sqr<int64_t>(id22) >= (edges_count() << 4);
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	std::vector<std::vector<T>> floyd() const {
		auto dist = make_vector<T>(id22, id22, id11());
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
			id25(start_vertex, distance, last_edge);
		} else {
			id12(start_vertex, distance, last_edge);
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

	size_t id22;

private:
	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void id25(const size_t start_vertex, std::vector<T>* distance, std::vector<size_t>* last_edge) const {
		std::vector<T> dist(id22, id11());
		std::vector<size_t> last(id22, std::numeric_limits<size_t>::max());
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
	void id12(const size_t start_vertex, std::vector<T>* distance, std::vector<size_t>* last_edge) const {
		std::vector<bool> used(id22);
		std::vector<T> dist(id22, id11());
		std::vector<size_t> last(id22, std::numeric_limits<size_t>::max());
		dist[start_vertex] = 0;
		for (size_t iter = 0; iter < id22; ++iter) {
			size_t vertex = std::numeric_limits<size_t>::max();
			T min_dist = id11();
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
	id22 = 0;
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
	partition.assign(id22, kNone);
	Queue<size_t> q(id22);
	for (size_t i = 0; i < id22; ++i) {
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
	std::vector<size_t> match(id22, std::numeric_limits<size_t>::max());
	std::vector<bool> matched(id22, false);
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
		used.assign(id22, false);
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


template<typename T = int64_t, size_t MASK = 0>
class id15 : public Graph<T, MASK> {
public:
	id15() : id15(0) {}

	explicit id15(const size_t vertices_count) : Graph<T, MASK>(vertices_count) {}

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void id28(const size_t from, const size_t to) {
		this->id1(from, to);
		this->id1(to, from);
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void id28(const size_t from, const size_t to, const T weight) {
		this->id1(from, to, weight);
		this->id1(to, from, weight);
	}

	template<size_t Mask = MASK, typename std::enable_if<!is_weighted<Mask>::value>::type* = nullptr>
	void id28(const typename Graph<T, MASK>::Edge& edge) {
		id28(edge.from(), edge.to());
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	void id28(const typename Graph<T, MASK>::Edge& edge) {
		id28(edge.from(), edge.to(), edge.weight());
	}

	template<size_t Mask = MASK, typename std::enable_if<is_weighted<Mask>::value>::type* = nullptr>
	T id10(std::vector<size_t>* mst = nullptr) const {
		std::vector<size_t> graph_edges(this->edges_count());
		std::iota(graph_edges.begin(), graph_edges.end(), 0);
		std::sort(graph_edges.begin(), graph_edges.end(), [&](const size_t& lhs, const size_t& rhs) {
			return this->weight(lhs) < this->weight(rhs);
		});
		DSU dsu(this->id22);
		T total_weight = 0;
		std::vector<size_t> tree;
		for (const auto& it : graph_edges) {
			if (dsu.unite(this->from(it), this->to(it))) {
				total_weight += this->weight(it);
				tree.emplace_back(it);
			}
		}
		if (mst != nullptr) {
			mst->swap(tree);
		}
		return total_weight;
	}

	bool is_connected() const {
		return dsu().sets_count() == 1;
	}

	DSU dsu() const {
		DSU dsu(this->id22);
		for (const auto& it : this->edges()) {
			dsu.unite(it.from(), it.to());
		}
		return dsu;
	}

	std::vector<size_t> labelled_components() const {
		return dsu().finalize().data();
	}
};






class LCA {
public:
	using size_type = std::size_t;

	template<typename T, size_type MASK>
	explicit LCA(const id15<T, MASK>& graph, const size_type starting_vertex = 0) :
			up_(graph.vertices_count()),
			tin_(graph.vertices_count()),
			tout_(graph.vertices_count()),
			timer_(0)
	{
		log_ = 1;
		while ((1 << log_) <= graph.vertices_count()) {
			++log_;
		}
		for (auto& it : up_) {
			it.resize(log_ + 1);
		}
		dfs(graph, starting_vertex, starting_vertex);
	}

	const std::vector<size_type>& tin() const {
		return tin_;
	}

	const std::vector<size_type>& tout() const {
		return tout_;
	}

	const std::vector<std::vector<size_type>>& up() const {
	    return up_;
	}

    size_type tin(const size_type vertex) const {
		return tin_[vertex];
	}

	size_type tout(const size_type vertex) const {
		return tout_[vertex];
	}

	bool upper(const size_type lhs, const size_type rhs) const {
		const size_type time_in = tin_[rhs];
		return tin_[lhs] <= time_in && tout_[lhs] >= time_in;
	}

	size_type query(const size_type lhs, const size_type rhs) const {
		if (upper(lhs, rhs)) {
			return lhs;
		}
		if (upper(rhs, lhs)) {
			return rhs;
		}
		size_type vertex = lhs;
		for (const size_type i : id9(log_)) {
			if (!upper(up_[vertex][i], rhs)) {
				vertex = up_[vertex][i];
			}
		}
		return up_[vertex][0];
	}

private:
	template<typename T, size_type MASK>
	void dfs(const id15<T, MASK>& graph, const size_type vertex, const size_type parent) {
		tin_[vertex] = timer_++;
		up_[vertex][0] = parent;
		for (size_type i = 1; i <= log_; ++i) {
			up_[vertex][i] = up_[up_[vertex][i - 1]][i - 1];
		}
		for (const auto& it : graph.edges(vertex)) {
			const size_type to = it.to();
			if (to == parent) {
				continue;
			}
			dfs(graph, to, vertex);
		}
		tout_[vertex] = timer_++;
	}

	std::vector<std::vector<size_type>> up_;
	std::vector<size_type> tin_;
	std::vector<size_type> tout_;
	size_type log_;
	size_type timer_;
};


class id2 {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;

	static constexpr int kSmallGraph = 777;

	struct Edge {
	    int from;
	    int to;
	    int weight;

	    friend std::istream& operator>>(std::istream& in, Edge& edge) {
	        in >> edge.from >> edge.to >> edge.weight;
	        --edge.from;
	        --edge.to;
	        return in;
	    }

	    bool operator <(const Edge& rhs) const {
	        return weight < rhs.weight;
	    }
	};

	void solve(std::istream& in, std::ostream& out) {
        int n, m;
        in >> n >> m;
        std::vector<Edge> edges(m);
        in >> edges;

        std::vector<int> degree(n, 0);
        std::unordered_set<pii> used_edges;
        int xor_sum = 0;
        std::vector<std::vector<int>> matrix(n);
        for (const auto& it : edges) {
            used_edges.emplace(it.from, it.to);
            used_edges.emplace(it.to, it.from);
            ++degree[it.from];
            ++degree[it.to];
            xor_sum ^= it.weight;
            matrix[it.from].emplace_back(it.to);
            matrix[it.to].emplace_back(it.from);
        }

        if (n <= kSmallGraph) {
            for (int from : range(n)) {
                for (int to : range(from + 1, n)) {
                    if (used_edges.count(pii{from, to})) {
                        continue;
                    }
                    edges.emplace_back(Edge{from, to, 0});
                }
            }
            sort(edges);
            DSU dsu(n);
            ll sum = 0;
            id15<> graph(n);
            bool id14 = false;
            std::vector<Edge> id27;
            for (const auto& it : edges) {
                if (dsu.unite(it.from, it.to)) {
                    sum += it.weight;
                    graph.id28(it.from, it.to);
                } else {
                    id14 |= (it.weight == 0);
                    if (it.weight < xor_sum) {
                        id27.emplace_back(it);
                    }
                }
            }
            if (!id14) {
                const LCA lca(graph);
                const auto& up = lca.up();
                sum += xor_sum;
                for (const auto& it : id27) {
                    const int parent = lca.query(it.from, it.to);
                    bool id18 = false;
                    {
                        int v = it.from;
                        while (!id18 && v != parent) {
                            const int to = up[v][0];
                            id18 |= (used_edges.count(pii{v, to}) == 0);
                            v = to;
                        }
                    }
                    {
                        int v = it.to;
                        while (!id18 && v != parent) {
                            const int to = up[v][0];
                            id18 |= (used_edges.count(pii{v, to}) == 0);
                            v = to;
                        }
                    }
                    if (id18) {
                        sum += it.weight;
                        sum -= xor_sum;
                        break;
                    }
                }
            }
            out << sum << std::endl;
            return;
        }

        std::vector<int> vertices(n);
        std::iota(all(vertices), 0);
        sort(vertices, [&degree](const int x, const int y) {
            return degree[x] > degree[y];
        });

        for (int v : range(n)) {
            sort(matrix[v]);
        }

        DSU dsu(n);
        for (int i : range(kSmallGraph)) {
            const int v = vertices[i];
            int index = 0;
            for (int to : range(n)) {
                while (index < matrix[v].size() && matrix[v][index] < to) {
                    ++index;
                }
                if (index >= matrix[v].size() || matrix[v][index] > to) {
                    

                    dsu.unite(v, to);
                }
            }
        }

        for (int i : range(kSmallGraph)) {
            const int v = vertices[n - i - 1];
            int index = 0;
            for (int to : range(n)) {
                while (index < matrix[v].size() && matrix[v][index] < to) {
                    ++index;
                }
                if (index >= matrix[v].size() || matrix[v][index] > to) {
                    

                    dsu.unite(v, to);
                }
            }
        }
        ll sum = 0;
        sort(edges);
        for (const auto& it : edges) {
            if (dsu.unite(it.from, it.to)) {
                sum += it.weight;
            }
        }
        assert(dsu.sets_count() == 1);
        out << sum << std::endl;

        out << xor_sum << std::endl;

	}


	id2() {}


	static constexpr bool kUseCustomChecker = true;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
	    int n, m;
	    in >> n >> m;
	    auto g = make_vector<int>(n, n, 0);
	    for (int i : range(m)) {
	        int x, y, w;
	        in >> x >> y >> w;
	        g[x - 1][y - 1] = g[y - 1][x - 1] = w;
	    }
	    std::vector<Edge> edges;
	    std::vector<int> zero_edges;
	    int xor_sum = 0;
	    for (int v : range(n)) {
	        for (int to : range(v + 1, n)) {
	            const int weight = g[v][to];
	            if (weight == 0) {
	                zero_edges.emplace_back(edges.size());
	            }
	            xor_sum ^= weight;
	            edges.emplace_back(Edge{v, to, weight});
	        }
	    }

	    DSU dsu(n);
	    ll jans = LINF;
	    for (int xored_edge : range(zero_edges.size())) {
	        auto tmp = edges;
            tmp[zero_edges[xored_edge]].weight = xor_sum;
	        sort(tmp);

	        ll cur = 0;
	        dsu.init(n);
	        for (const auto& it : tmp) {
	            if (dsu.unite(it.from, it.to)) {
	                cur += it.weight;
	            }
	        }
	        umin(jans, cur);
	    }

	    ll pans;
	    out >> pans;
	    if (jans != pans) {
	        debug("WA", jans, pans);
	        return false;
	    }

		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 100;
	static constexpr bool kStopAfterFirstFail = true;
	static void generate_test(std::ostream& test) {
	    const int id16 = 1000;
	    const int id6 = 1000;
	    const int id4 = 200;

	    const int n = Random::get(kSmallGraph, id16);

	    std::vector<pii> edges;
	    for (int v : range(n)) {
	        for (int to : range(v + 1, n)) {
	            edges.emplace_back(v, to);
	        }
	    }
        const int deleted_edges = Random::get(1, std::min<int>(id4, edges.size()));

	    std::vector<int> edge_id(edges.size());
	    std::iota(all(edge_id), 0);
	    std::shuffle(all(edge_id), Random::random_engine());
	    std::set<int> id3;
	    for (int i : range(deleted_edges)) {
	        id3.emplace(edge_id[i]);
	    }
	    test << n << " " << std::max<size_t>(0, edge_id.size() - deleted_edges) << std::endl;
	    for (int i : range(edge_id.size())) {
	        if (id3.count(i)) {
	            continue;
	        }
	        const int weight = Random::get(1, id6);
	        test << edges[i].first + 1 << " " << edges[i].second + 1 << " " << weight << std::endl;
	    }
	}

};


int main() {
	id2 solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (id2::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (id2::kWriteCaseNumber) {
				out << "Case 
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
