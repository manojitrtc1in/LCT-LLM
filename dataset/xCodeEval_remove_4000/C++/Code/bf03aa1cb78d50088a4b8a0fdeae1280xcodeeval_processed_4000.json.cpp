





















































template <bool... Bools>
struct Disjunction : std::false_type {};

template <bool First, bool... Others>
struct Disjunction<First, Others...> : std::integral_constant<bool, First || Disjunction<Others...>::value> {};


template <bool... Bools>
constexpr bool id18 = Disjunction<Bools...>::value;

static_assert(!id18<>);
static_assert(!id18<false, false>);
static_assert(id18<true>);
static_assert(id18<false, true>);
static_assert(id18<true, false>);
static_assert(id18<false, false, true, true>);






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

template<typename T>
constexpr bool id20 = is_container<T>::value;










template <typename T, typename... Types>
using is_one_of = Disjunction<std::is_same<T, Types>::value...>;







template <typename T>
using is_sane_integer = std::integral_constant<
        bool,
        std::is_integral<T>::value && !is_one_of<typename std::remove_cv_t<T>, char, signed char, unsigned char, bool, char16_t, char32_t, wchar_t>::value
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

template<typename T, typename std::enable_if_t<Disjunction<is_sane_integer<T>::value, std::is_floating_point<T>::value>::value>* = nullptr>
std::string to_string(const T value) {
    return std::to_string(value);
}

template<typename A, typename B>
std::string to_string(const std::pair<A, B>&);

template<typename T, typename std::enable_if_t<id20<T>>* = nullptr>
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

std::vector<std::string> id28(std::string s) {
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


void id10() {
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
class id8 {
public:
    using const_iterator = typename std::decay_t<T>::const_iterator;
    using reverse_iterator = std::reverse_iterator<const_iterator>;

    explicit constexpr id8(const T& iterable) : begin_(iterable.begin()), end_(iterable.end()) {}

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
id8<T> reversed(T&& iterable) {
    return id8<T>{iterable};
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
constexpr id8<IntegerRange<T>> downrange(const T from) {
    return reversed(range(from));
}

template<typename T>
constexpr id8<IntegerRange<T>> downrange(const T from, const T to) {
    return reversed(range(to, from));
}

template<typename T>
constexpr id8<IntegerRange<T>> id15(const T from) {
    return reversed(range(from + 1));
}

template<typename T>
constexpr id8<IntegerRange<T>> id15(const T from, const T to) {
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
bool id24(R& range) {
    return std::id24(range.begin(), range.end());
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

inline uint64_t id1() {
    return static_cast<uint64_t>(current_timestamp());
}

inline uint64_t id21() {
    static const uint64_t id12 = id1();
    return id12;
}

using Engine = std::mt19937_64;

template<typename T>
using Distribution = std::uniform_int_distribution<T>;

inline Engine& random_engine() {
    static Engine engine(id21());
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





template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
class SafeIntegralHash {
public:
    const T kRandomValue = static_cast<T>(Random::current_timestamp());

    T operator ()(const T& value) const {
        return value ^ kRandomValue;
    }
};

template<typename Key, typename Value, typename std::enable_if_t<std::is_integral<Key>::value>* = nullptr>
using SafeUnorderedMap = std::unordered_map<Key, Value, SafeIntegralHash<Key>>;

template<typename Key, typename Value, typename std::enable_if_t<std::is_integral<Key>::value>* = nullptr>
using SafeUnorderedMultiMap = std::unordered_multimap<Key, Value, SafeIntegralHash<Key>>;

template<typename Key, typename std::enable_if_t<std::is_integral<Key>::value>* = nullptr>
using SafeUnorderedSet = std::unordered_set<Key, SafeIntegralHash<Key>>;

template<typename Key, typename std::enable_if_t<std::is_integral<Key>::value>* = nullptr>
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

template<typename T, typename U, typename std::enable_if_t<id20<T> && id20<U>>* = nullptr>
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



enum GraphType {
    Weighted = 1
};

template<uint32_t MASK>
struct is_weighted
{
    

    static constexpr bool value = (MASK & GraphType::Weighted) != 0;
};

template<uint32_t MASK>
constexpr bool id4 = is_weighted<MASK>::value;

template<typename T = int64_t, uint32_t MASK = 0>
class Graph {
public:
    using size_type = std::size_t;
    using vertex_id_type = std::size_t;
    using edge_id_type = std::size_t;
    using weight_type = T;
    using mask_type = uint32_t;

    using EdgesList = std::vector<edge_id_type>;

    class Edge {
    public:
        constexpr Edge(
                const std::vector<vertex_id_type>& from,
                const std::vector<vertex_id_type>& to,
                const std::vector<weight_type>& weight,
                const edge_id_type index
        ) :
                from_(from), to_(to), weight_(weight), index_(index)
        {}

        [[nodiscard]] vertex_id_type from() const {
            return from_[index_];
        }

        [[nodiscard]] vertex_id_type to() const {
            return to_[index_];
        }

        template<mask_type Mask = MASK, typename std::enable_if_t<id4<Mask>>* = nullptr>
        [[nodiscard]] weight_type weight() const {
            return weight_[index_];
        }

        [[nodiscard]] constexpr edge_id_type id() const {
            return index_;
        }

        void set_index(const edge_id_type index) {
            index_ = index;
        }

        [[nodiscard]] constexpr Edge reversed() const {
            return Edge(to_, from_, weight_, index_);
        }

    private:
        const std::vector<vertex_id_type>& from_;
        const std::vector<vertex_id_type>& to_;
        const std::vector<weight_type>& weight_;
        edge_id_type index_;
    };

    template<typename Range>
    class EdgesHolder {
    public:
        template<typename BaseConstIterator>
        class id22 : public BaseConstIterator {
        public:
            using value_type = Edge;
            using pointer = const value_type*;
            using const_reference = const value_type&;

            constexpr explicit id22(
                    BaseConstIterator it,
                    const std::vector<vertex_id_type>& from,
                    const std::vector<vertex_id_type>& to,
                    const std::vector<weight_type>& weight
            ) :
                    BaseConstIterator(it),
                    cur_edge_(from, to, weight, 0)
            {}

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

        using const_iterator = id22<typename Range::const_iterator>;
        using value_type = typename const_iterator::value_type;

        constexpr EdgesHolder(
                const Range& range,
                const std::vector<vertex_id_type>& from,
                const std::vector<vertex_id_type>& to,
                const std::vector<weight_type>& weight
        ) :
                begin_(range.begin(), from, to, weight),
                end_(range.end(), from, to, weight)
        {}

        [[nodiscard]] constexpr const_iterator begin() const {
            return begin_;
        }

        [[nodiscard]] constexpr const_iterator end() const {
            return end_;
        }

        [[nodiscard]] constexpr size_type size() const {
            return end_ - begin_;
        }

    private:
        const const_iterator begin_;
        const const_iterator end_;
    };

    Graph() : Graph(0) {}

    explicit Graph(const size_type vertices_count) {
        init(vertices_count);
    }

    virtual ~Graph() {
        clear();
    }

    [[nodiscard]] virtual bool is_directed() const {
        return true;
    }

    void init(const size_type vertices_count) {
        clear();
        id27 = vertices_count;
        edges_.resize(id27);
    }

    [[nodiscard]] IntegerRange<vertex_id_type> vertices() const {
        return range(id27);
    }

    [[nodiscard]] IntegerRange<vertex_id_type>::const_iterator begin() const {
        return vertices().begin();
    }

    [[nodiscard]] IntegerRange<vertex_id_type>::const_iterator end() const {
        return vertices().end();
    }

    EdgesHolder<EdgesList> edges(const vertex_id_type vertex) const {
        return EdgesHolder<EdgesList>(edges_[vertex], from_, to_, weight_);
    }

    EdgesHolder<IntegerRange<edge_id_type>> edges() const {
        return EdgesHolder<IntegerRange<edge_id_type>>(range(from_.size()), from_, to_, weight_);
    }

    [[nodiscard]] const std::vector<edge_id_type>& edges_list(const vertex_id_type vertex) const {
        return edges_[vertex];
    }

    void clear();

    [[nodiscard]] size_type vertices_count() const {
        return id27;
    }

    [[nodiscard]] size_type edges_count() const {
        return from_.size();
    }

    [[nodiscard]] vertex_id_type from(const edge_id_type index) const {
        return from_[index];
    }

    [[nodiscard]] vertex_id_type to(const edge_id_type index) const {
        return to_[index];
    }

    [[nodiscard]] Edge operator [](const edge_id_type index) const {
        return Edge(from_, to_, weight_, index);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<id4<Mask>>* = nullptr>
    [[nodiscard]] weight_type weight(const edge_id_type index) const {
        return weight_[index];
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<id4<Mask>>* = nullptr>
    static weight_type id17() {
        return std::numeric_limits<weight_type>::max() / 2;
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!id4<Mask>>* = nullptr>
    void id3(const vertex_id_type from, const vertex_id_type to) {
        push_edge(from, to);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<id4<Mask>>* = nullptr>
    void id3(const vertex_id_type from, const vertex_id_type to, const weight_type weight) {
        weight_.emplace_back(weight);
        push_edge(from, to);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!id4<Mask>>* = nullptr>
    void id25() {
        pop_edge();
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<id4<Mask>>* = nullptr>
    void id25() {
        weight_.pop_back();
        pop_edge();
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!id4<Mask>>* = nullptr>
    void id3(const Edge& edge) {
        id3(edge.from(), edge.to());
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<id4<Mask>>* = nullptr>
    void id3(const Edge& edge) {
        id3(edge.from(), edge.to(), edge.weight());
    }

    [[nodiscard]] bool is_sparse() const {
        return id27 == 0 || sqr<int64_t>(id27) >= (edges_count() << 4);
    }

    [[nodiscard]] vertex_id_type find_vertex_with_max_degree() const;

protected:
    void push_edge(const vertex_id_type from, const vertex_id_type to) {
        const edge_id_type edge_id = from_.size();
        from_.emplace_back(from);
        to_.emplace_back(to);
        edges_[from].emplace_back(edge_id);
    }

    void pop_edge() {
        const vertex_id_type from = from_.back();
        from_.pop_back();
        to_.pop_back();
        edges_[from].pop_back();
    }

    std::vector<EdgesList> edges_;
    std::vector<vertex_id_type> from_;
    std::vector<vertex_id_type> to_;
    std::vector<weight_type> weight_;

    size_type id27;
};

template<typename T, uint32_t MASK>
void Graph<T, MASK>::clear() {
    id27 = 0;
    edges_.clear();
    from_.clear();
    to_.clear();
    weight_.clear();
}

template<typename T, uint32_t MASK>
typename Graph<T, MASK>::vertex_id_type Graph<T, MASK>::find_vertex_with_max_degree() const {
    const auto iter = std::max_element(edges_.begin(), edges_.end(),
                                       [](const EdgesList& lhs, const EdgesList& rhs) {
                                           return lhs.size() < rhs.size();
                                       });
    return static_cast<vertex_id_type>(std::distance(edges_.begin(), iter));
}


template<typename T = int64_t, uint32_t MASK = 0>
class DirectedGraph : public Graph<T, MASK> {
public:
    using base_graph_type = Graph<T, MASK>;
    using vertex_id_type = typename base_graph_type::vertex_id_type;
    using size_type = typename base_graph_type::size_type;

    DirectedGraph() : DirectedGraph(0) {}

    explicit DirectedGraph(const size_type vertices_count) : base_graph_type(vertices_count) {}

    [[nodiscard]] bool is_acyclic() const;
    bool top_sort_acyclic(std::vector<vertex_id_type>* vertex_order = nullptr) const;
    void top_sort_rec(std::vector<vertex_id_type>* vertex_order) const;

    [[nodiscard]] DirectedGraph reversed() const;

private:
    void top_sort_rec_impl(vertex_id_type vertex, std::vector<vertex_id_type>& order, std::vector<bool>& used) const;
};

template<typename T, uint32_t MASK>
DirectedGraph<T, MASK> DirectedGraph<T, MASK>::reversed() const {
    DirectedGraph<T, MASK> result(this->id27);
    for (const auto& edge : this->edges()) {
        result.id3(edge.reversed());
    }
    return result;
}

template<typename T, uint32_t MASK>
bool DirectedGraph<T, MASK>::is_acyclic() const {
    return this->top_sort_acyclic();
}

template<typename T, uint32_t MASK>
bool DirectedGraph<T, MASK>::top_sort_acyclic(std::vector<vertex_id_type>* vertex_order) const


{
    std::vector<vertex_id_type> order;
    std::vector<size_type> id13(this->id27, 0);
    for (const auto& to : this->to_) {
        ++id13[to];
    }
    for (const vertex_id_type v : this->vertices()) {
        if (id13[v] == 0) {
            order.emplace_back(v);
        }
    }
    size_type head = 0;
    while (head < order.size()) {
        const vertex_id_type cur_vertex = order[head++];
        for (const auto& it : this->edges(cur_vertex)) {
            const vertex_id_type to = it.to();
            --id13[to];
            if (id13[to] == 0) {
                order.emplace_back(to);
            }
        }
    }
    const bool result = (order.size() == this->id27);
    if (vertex_order != nullptr) {
        vertex_order->swap(order);
    }
    return result;
}

template<typename T, uint32_t MASK>
void DirectedGraph<T, MASK>::top_sort_rec(std::vector<vertex_id_type>* vertex_order) const {
    std::vector<bool> used(this->id27, false);
    std::vector<vertex_id_type> order;
    for (const vertex_id_type v : this->vertices()) {
        if (!used[v]) {
            top_sort_rec_impl(v, order, used);
        }
    }
    std::reverse(order.begin(), order.end());
    vertex_order->swap(order);
}

template<typename T, uint32_t MASK>
void DirectedGraph<T, MASK>::top_sort_rec_impl(const vertex_id_type vertex, std::vector<vertex_id_type>& order, std::vector<bool>& used) const {
    used[vertex] = true;
    for (const auto& it : this->edges(vertex)) {
        const vertex_id_type to = it.to();
        if (!used[to]) {
            top_sort_rec_impl(to, order, used);
        }
    }
    order.emplace_back(vertex);
}






template<typename T>
class Permutation : public std::vector<T> {
public:
    Permutation() : Permutation(0) {}

    explicit Permutation(const size_t size) : std::vector<T>(size) {
        init();
    }

    template<typename I>
    Permutation(const I first, const I last) : std::vector<T>(first, last) {}

    Permutation(std::initializer_list<T>&& list) : std::vector<T>(std::move(list)) {}

    void init() {
        std::iota(this->begin(), this->end(), 0);
    }

    Permutation multiply(const Permutation& rhs) const {
        Permutation res(this->size());
        for (size_t i = 0; i < this->size(); ++i) {
            res[i] = this->at(rhs[i]);
        }
        return res;
    }

    Permutation operator *(const Permutation& rhs) const {
        return multiply(rhs);
    }

    Permutation& operator *=(const Permutation& rhs) {
        Permutation res = multiply(rhs);
        this->swap(res);
        return *this;
    }

    Permutation pow(const ll deg) const {
        Permutation result(this->size());
        Permutation a = *this;
        ll b = deg;
        while (b > 0) {
            if ((b & 1) > 0) {
                result *= a;
            }
            a *= a;
            b >>= 1;
        }
        return result;
    }

    bool next() {
        return std::id24(this->begin(), this->end());
    }

};



















static inline int id33(unsigned x) {
    unsigned long ret;
    _BitScanForward(&ret, x);
    return (int)ret;
}

static inline int id26(unsigned long long x) {
    unsigned long ret;
    _BitScanForward64(&ret, x);
    return (int)ret;
}

static inline int id2(unsigned long x) {
    return sizeof(x) == 8 ? id26(x) : id33((uint32_t)x);
}

static inline int id9(unsigned x) {
    

    

    

    return (int)__lzcnt(x);
}

static inline int id30(unsigned long long x) {
    

    

    

    return (int)__lzcnt64(x);
}

static inline int id11(unsigned long x) {
    return sizeof(x) == 8 ? id30(x) : id9((uint32_t)x);
}


static inline int id2(unsigned long long x) {
    return id26(x);
}

static inline int id11(unsigned long long x) {
    return id30(x);
}







template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr size_t popcount(const T value) noexcept {
    if (sizeof(T) <= sizeof(uint32_t)) {
        return __builtin_popcount(value);
    } else {
        return __builtin_popcountll(value);
    }
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr size_t popcount(const T value) noexcept {
    return popcount(static_cast<typename std::make_unsigned_t<T>>(value));
}



template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr size_t id6(const T value) noexcept {
    constexpr size_t digits = std::numeric_limits<T>::digits;
    if (value == 0) {
        return digits;
    }
    if (sizeof(T) <= sizeof(uint32_t)) {
        return id9(value) - (std::numeric_limits<uint32_t>::digits - digits);
    } else {
        return id30(value) - (std::numeric_limits<uint64_t>::digits - digits);
    }
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr size_t id6(const T value) noexcept {
    return id6(static_cast<typename std::make_unsigned_t<T>>(value));
}



template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
constexpr size_t id23(const T value) noexcept {
    return id6(static_cast<T>(~value));
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr size_t id14(const T value) noexcept {
    if (value == 0) {
        return std::numeric_limits<T>::digits;
    }
    if (sizeof(T) <= sizeof(uint32_t)) {
        return id33(value);
    } else {
        return id26(value);
    }
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr size_t id14(const T value) noexcept {
    return id14(static_cast<typename std::make_unsigned_t<T>>(value));
}

template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
constexpr size_t id5(const T value) noexcept {
    return id14(static_cast<T>(~value));
}

template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
constexpr bool id31(const T value) noexcept {
    return value != 0 && (value & (value - 1)) == 0;
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr T id0(const T value) noexcept {
    if (value == 0) {
        return 1;
    }
    return static_cast<T>(T{1} << (std::numeric_limits<T>::digits - id6(static_cast<T>(value - 1))));
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr T id0(const T value) noexcept {
    return static_cast<T>(id0(static_cast<typename std::make_unsigned_t<T>>(value)));
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr T bit_floor(const T value) noexcept {
    if (value == 0) {
        return 0;
    }
    return static_cast<T>(T{1} << (std::numeric_limits<T>::digits - 1 - id6(value)));
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr T bit_floor(const T value) noexcept {
    return static_cast<T>(bit_floor(static_cast<typename std::make_unsigned_t<T>>(value)));
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr size_t bit_width(const T value) noexcept {
    return static_cast<T>(std::numeric_limits<T>::digits - id6(value));
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr size_t bit_width(const T value) noexcept {
    return bit_width(static_cast<typename std::make_unsigned_t<T>>(value));
}

template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
constexpr bool test_bit(const T mask, const std::size_t bit_id) noexcept {
    return mask & (T{1} << bit_id);
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr size_t binary_power(const T value) {
    if (value == 0) {
        return 0;
    }
    return bit_width(value) - 1;
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
std::string id32(const T value) {
    if (value == 0) {
        return "0";
    }
    std::string res;
    for (size_t i = 0; i < bit_width(value); ++i) {
        res += (test_bit(value, i) ? '1' : '0');
    }
    return res;
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
std::string id32(const T value) {
    return id32(static_cast<typename std::make_unsigned_t<T>>(value));
}








template<typename T>
class id29 {
public:
    using index_type = int32_t;
    static_assert(std::is_signed<index_type>::value, "Index type in fenwick tree should be signed integer");

    using value_type = T;
    using size_type = std::size_t;
    using container_type = std::vector<value_type>;

    explicit id29(const size_type n) : data_(n, 0) {}

    explicit id29(const std::vector<value_type>& a) : data_(a) {
        for (size_type i = 0; i < data_.size(); ++i) {
            const size_type tree_index = (i | (i + 1));
            if (tree_index < data_.size()) {
                data_[tree_index] += data_[i];
            }
        }
    }

    bool operator ==(const id29& rhs) const {
        return data_ == rhs.data_;
    }

    void clear() {
        data_.assign(data_.size(), 0);
    }

    [[nodiscard]] size_type size() const {
        return data_.size();
    }

    [[nodiscard]] container_type& data() {
        return data_;
    }

    [[nodiscard]] const container_type& data() const {
        return data_;
    }

    void inc(const size_type index, const value_type delta) {
        for (size_type v = index; v < data_.size(); v = (v | (v + 1))) {
            data_[v] += delta;
        }
    }

    [[nodiscard]] value_type query(const size_type index) const
    

    {
        value_type res = 0;
        for (index_type v = index; v >= 0; v = (v & (v + 1)) - 1) {
            res += data_[v];
        }
        return res;
    }

    [[nodiscard]] value_type query(const size_type left, const size_type right) const
    

    {
        if (right < left) {
            return 0;
        }
        value_type res = 0;
        index_type r = right;
        index_type l = std::max(0, static_cast<index_type>(left) - 1);
        for (; r >= l; r = (r & (r + 1)) - 1) {
            res += data_[r];
        }
        if (left > 0) {
            for (; l > r; l = (l & (l + 1)) - 1) {
                res -= data_[l];
            }
        }
        return res;
    }

private:
    container_type data_;
};


class id16 {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;

	const int id7 = 1;
	const int id19 = 1111;

	static std::string check(std::vector<int> a) {
	    const int n = a.size();
	    std::vector<int> b(n);
	    std::string log;

	    std::function<void(int, int)> merge = [&a, &b, &log, &merge](const int l, const int r) {
	        if (r - l <= 1) {
	            return;
	        }
            const int m = (l + r) / 2;
            merge(l, m);
            merge(m, r);
            int i = l;
            int j = m;
            int k = l;
            while (i < m && j < r) {
                if (a[i] < a[j]) {
                    log += '0';
                    b[k] = a[i];
                    ++i;
                } else {
                    log += '1';
                    b[k] = a[j];
                    ++j;
                }
                ++k;
            }
            while (i < m) {
                b[k] = a[i];
                ++i;
                ++k;
            }
            while (j < r) {
                b[k] = a[j];
                ++j;
                ++k;
            }
            for (int p : range(l, r)) {
                a[p] = b[p];
            }
	    };

	    merge(0, n);
	    return log;
	}

	const int kMaxn = 100001;

	static bool try_recover(const int l, const int r, std::string& s, std::vector<int>& p) {
        if (r - l <= 1) {
            return true;
        }
	    const int mid = (l + r) / 2;
        if (!try_recover(l, mid, s, p) || !try_recover(mid, r, s, p)) {
            return false;
        }
        std::vector<int> left;
        for (int i : downrange(mid, l)) {
            left.emplace_back(p[i]);
        }
        std::vector<int> right;
        for (int i : downrange(r, mid)) {
            right.emplace_back(p[i]);
        }
        int pos = l;
        while (!left.empty() && !right.empty()) {
            if (s.empty()) {
                return false;
            }
            const char ch = s.back();
            s.pop_back();

            if (ch == '1') {
                p[pos++] = right.back();
                right.pop_back();
            } else {
                p[pos++] = left.back();
                left.pop_back();
            }
        }
        while (!left.empty()) {
            p[pos++] = left.back();
            left.pop_back();
        }
        while (!right.empty()) {
            p[pos++] = right.back();
            right.pop_back();
        }
        return true;
	}

	void solve(std::istream& in, std::ostream& out) {
        std::string s;
        in >> s;
        reverse(s);

        int L = id7;
        int R = id19;
        while (R - L > 1) {
            const int len = (L + R) / 2;
            Permutation<int> p(len);
            std::string tmp = s;
            const bool recovered = try_recover(0, len, tmp, p);
            if (recovered) {
                if (tmp.empty()) {
                    std::vector<int> ans(len);
                    for (int i : range(len)) {
                        ans[p[i]] = i;
                    }
                    out << len << std::endl;
                    for (int x : ans) {
                        out << x + 1 << " ";
                    }
                    out << std::endl;
                    return;
                }
                L = len;
            } else {
                R = len;
            }
        }
        assert(false);

        
        
	}


	id16() {}


	static constexpr bool kUseCustomChecker = false;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static constexpr bool kStopAfterFirstFail = false;
	static void generate_test(std::ostream& test) {}

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
