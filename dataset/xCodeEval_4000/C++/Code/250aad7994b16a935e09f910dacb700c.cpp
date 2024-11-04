

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

static_assert(!DisjunctionV<>);
static_assert(!DisjunctionV<false, false>);
static_assert(DisjunctionV<true>);
static_assert(DisjunctionV<false, true>);
static_assert(DisjunctionV<true, false>);
static_assert(DisjunctionV<false, false, true, true>);
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

template<typename T>
constexpr bool is_container_v = is_container<T>::value;










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

template<typename T, typename std::enable_if_t<is_container_v<T>>* = nullptr>
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
    const std::string& arg = args[idx];
    const std::string value = ss.str();
    if (arg == value) {
        std::cerr << arg;
    } else {
        std::cerr << arg << " = " << value;
    }
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
    using const_iterator = typename std::decay_t<T>::const_iterator;
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

#ifndef STD_HASH_PAIR
template<typename T, typename U>
struct hash<std::pair<T, U>> {
    std::size_t operator()(const std::pair<T, U>& pair) const {
        return static_cast<int64_t>(pair.first) * 877117 + pair.second;
    }
};
#endif

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

template<typename T, typename U, typename std::enable_if_t<is_container_v<T> && is_container_v<U>>* = nullptr>
T as_container(const U& collection) {
    return T{std::begin(collection), std::end(collection)};
}

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












class DSU {
public:
    using size_type = std::size_t;
    using vertex_id_type = std::size_t;
    using container_type = std::vector<vertex_id_type>;

    DSU() : DSU(0) {}

    explicit DSU(const size_type vertices_count) {
        init(vertices_count);
    }

    void init(const size_type vertices_count) {
        parent_.resize(vertices_count);
        std::iota(parent_.begin(), parent_.end(), 0);
        sets_count_ = vertices_count;
    }

    vertex_id_type find_set(const vertex_id_type vertex) {
        if (vertex != parent_[vertex]) {
            parent_[vertex] = find_set(parent_[vertex]);
        }
        return parent_[vertex];
    }

    bool unite(const vertex_id_type a, const vertex_id_type b) {
        vertex_id_type x = find_set(a);
        vertex_id_type y = find_set(b);
        if (x == y) {
            return false;
        }
        if (Random::get(2) == 0) {
            std::swap(x, y);
        }
        parent_[x] = y;
        --sets_count_;
        return true;
    }

    DSU& finalize() {
        for (auto& it : parent_) {
            it = find_set(it);
        }
        return *this;
    }

    [[nodiscard]] size_type size() const {
        return parent_.size();
    }

    [[nodiscard]] size_type sets_count() const {
        return sets_count_;
    }

    [[nodiscard]] const container_type& data() const {
        return parent_;
    }

private:
    container_type parent_;
    size_type sets_count_;
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
class Stack {
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using rvalue = value_type&&;
    using container = std::vector<value_type>;

    explicit Stack(const size_type max_size) : data_(container(max_size)) {
        clear();
    }

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


enum GraphType {
    Weighted = 1
};

template<uint32_t MASK>
struct is_weighted
{
    

    static constexpr bool value = (MASK & GraphType::Weighted) != 0;
};

template<uint32_t MASK>
constexpr bool is_weighted_v = is_weighted<MASK>::value;

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

        template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
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
        class EdgeConstIterator : public BaseConstIterator {
        public:
            using value_type = Edge;
            using pointer = const value_type*;
            using const_reference = const value_type&;

            constexpr explicit EdgeConstIterator(
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

        using const_iterator = EdgeConstIterator<typename Range::const_iterator>;
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
        vertices_count_ = vertices_count;
        edges_.resize(vertices_count_);
    }

    [[nodiscard]] IntegerRange<vertex_id_type> vertices() const {
        return range(vertices_count_);
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
        return vertices_count_;
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

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    [[nodiscard]] weight_type weight(const edge_id_type index) const {
        return weight_[index];
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    static weight_type weight_infinity() {
        return std::numeric_limits<weight_type>::max() / 2;
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!is_weighted_v<Mask>>* = nullptr>
    void add_directed_edge(const vertex_id_type from, const vertex_id_type to) {
        push_edge(from, to);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void add_directed_edge(const vertex_id_type from, const vertex_id_type to, const weight_type weight) {
        weight_.emplace_back(weight);
        push_edge(from, to);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!is_weighted_v<Mask>>* = nullptr>
    void remove_last_directed_edge() {
        pop_edge();
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void remove_last_directed_edge() {
        weight_.pop_back();
        pop_edge();
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!is_weighted_v<Mask>>* = nullptr>
    void add_directed_edge(const Edge& edge) {
        add_directed_edge(edge.from(), edge.to());
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void add_directed_edge(const Edge& edge) {
        add_directed_edge(edge.from(), edge.to(), edge.weight());
    }

    [[nodiscard]] bool is_sparse() const {
        return vertices_count_ == 0 || sqr<int64_t>(vertices_count_) >= (edges_count() << 4);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    [[nodiscard]] std::vector<std::vector<weight_type>> floyd() const {
        auto dist = make_vector<weight_type>(vertices_count_, vertices_count_, weight_infinity());
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

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void dijkstra(const vertex_id_type start_vertex, std::vector<weight_type>* distance, std::vector<edge_id_type>* last_edge = nullptr) const {
        if (is_sparse()) {
            sparse_dijkstra(start_vertex, distance, last_edge);
        } else {
            dense_dijkstra(start_vertex, distance, last_edge);
        }
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    weight_type dijkstra(const vertex_id_type start_vertex, const vertex_id_type finish_vertex, std::vector<edge_id_type>* path = nullptr) const {
        if (start_vertex == finish_vertex) {
            return 0;
        }
        std::vector<weight_type> dist;
        std::vector<edge_id_type> last_edge;
        dijkstra(start_vertex, &dist, &last_edge);
        if (path != nullptr) {
            std::vector<edge_id_type> tmp_path;
            vertex_id_type vertex = finish_vertex;
            while (vertex != start_vertex) {
                const edge_id_type edge = last_edge[vertex];
                tmp_path.emplace_back(edge);
                vertex = from_[edge];
            }
            std::reverse(tmp_path.begin(), tmp_path.end());
            path->swap(tmp_path);
        }
        return dist[finish_vertex];
    }

    [[nodiscard]] vertex_id_type find_vertex_with_max_degree() const;

    bool find_eulerian_path(std::vector<edge_id_type>* eulerian_path = nullptr, bool strict_cycle = false, vertex_id_type starting_vertex = 0, bool strict_starting_vertex = false);

    bool is_bipartite(std::vector<vertex_id_type>& partition) const;
    void maximal_matching(std::vector<vertex_id_type>* match) const;

    bool try_kuhn(vertex_id_type vertex, std::vector<bool>& used, std::vector<vertex_id_type>& match) const;

protected:
    void push_edge(const vertex_id_type from, const vertex_id_type to) {
        const edge_id_type edge_id = from_.size();
        from_.emplace_back(from);
        to_.emplace_back(to);
        edges_[from].emplace_back(edge_id);
    }

    void pop_edge() {
        const vertex_id_type from = from_.back();
        debug("remove", from);
        from_.pop_back();
        to_.pop_back();
        edges_[from].pop_back();
    }

    std::vector<EdgesList> edges_;
    std::vector<vertex_id_type> from_;
    std::vector<vertex_id_type> to_;
    std::vector<weight_type> weight_;

    size_type vertices_count_;

private:
    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void sparse_dijkstra(const vertex_id_type start_vertex, std::vector<weight_type>* distance, std::vector<edge_id_type>* last_edge) const {
        std::vector<weight_type> dist(vertices_count_, weight_infinity());
        std::vector<edge_id_type> last(vertices_count_, std::numeric_limits<edge_id_type>::max());
        dist[start_vertex] = 0;
        using QueueNode = std::pair<weight_type, vertex_id_type>;
        std::priority_queue<QueueNode> q;
        q.emplace(0, start_vertex);
        while (!q.empty()) {
            const QueueNode node = q.top();
            q.pop();
            const weight_type len = -node.first;
            const vertex_id_type vertex = node.second;
            if (len > dist[vertex]) {
                continue;
            }
            for (const auto& it : edges(vertex)) {
                const weight_type new_dist = len + it.weight();
                const vertex_id_type to = it.to();
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

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void dense_dijkstra(const vertex_id_type start_vertex, std::vector<weight_type>* distance, std::vector<edge_id_type>* last_edge) const {
        std::vector<bool> used(vertices_count_);
        std::vector<weight_type> dist(vertices_count_, weight_infinity());
        std::vector<edge_id_type> last(vertices_count_, std::numeric_limits<edge_id_type>::max());
        dist[start_vertex] = 0;
        for (size_type iter = 0; iter < vertices_count_; ++iter) {
            vertex_id_type vertex = std::numeric_limits<vertex_id_type>::max();
            weight_type min_dist = weight_infinity();
            for (const vertex_id_type v : vertices()) {
                if (!used[v] && umin(min_dist, dist[v])) {
                    min_dist = dist[v];
                    vertex = v;
                }
            }
            if (vertex == std::numeric_limits<vertex_id_type>::max()) {
                break;
            }
            used[vertex] = true;
            for (const auto& it : edges(vertex)) {
                const vertex_id_type to = it.to();
                const weight_type len = min_dist + it.weight();
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

template<typename T, uint32_t MASK>
void Graph<T, MASK>::clear() {
    vertices_count_ = 0;
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

template<typename T, uint32_t MASK>
bool Graph<T, MASK>::is_bipartite(std::vector<vertex_id_type>& partition) const {
    const vertex_id_type kNone = std::numeric_limits<vertex_id_type>::max();
    partition.assign(vertices_count_, kNone);
    Queue<vertex_id_type> q(vertices_count_);
    for (size_type i = 0; i < vertices_count_; ++i) {
        if (partition[i] == kNone) {
            q.clear();
            q.push(i);
            partition[i] = 0;
            while (!q.empty()) {
                const vertex_id_type vertex = q.pop_front();
                const vertex_id_type color = partition[vertex];
                for (const auto& it : edges(vertex)) {
                    const vertex_id_type to = it.to();
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

template<typename T, uint32_t MASK>
void Graph<T, MASK>::maximal_matching(std::vector<vertex_id_type>* vertex_match) const {
    std::vector<vertex_id_type> match(vertices_count_, std::numeric_limits<vertex_id_type>::max());
    std::vector<bool> matched(vertices_count_, false);
    for (const vertex_id_type v : vertices()) {
        for (const auto& it : edges(v)) {
            const vertex_id_type to = it.to();
            if (match[to] == std::numeric_limits<vertex_id_type>::max()) {
                match[to] = v;
                matched[v] = true;
                break;
            }
        }
    }
    std::vector<bool> used;
    for (const vertex_id_type v : vertices()) {
        if (matched[v]) {
            continue;
        }
        used.assign(vertices_count_, false);
        try_kuhn(v, used, match);
    }
    vertex_match->swap(match);
}

template<typename T, uint32_t MASK>
bool Graph<T, MASK>::try_kuhn(const vertex_id_type vertex, std::vector<bool>& used, std::vector<vertex_id_type>& match) const {
    used[vertex] = true;
    for (const auto& it : edges(vertex)) {
        const vertex_id_type to = it.to();
        if (match[to] == std::numeric_limits<vertex_id_type>::max()) {
            match[to] = vertex;
            match[vertex] = to;
            return true;
        }
    }
    for (const auto& it : edges(vertex)) {
        const vertex_id_type to = it.to();
        if (!used[match[to]] && try_kuhn(match[to], used, match)) {
            match[to] = vertex;
            match[vertex] = to;
            return true;
        }
    }
    return false;
}

template<typename T, uint32_t MASK>
bool Graph<T, MASK>::find_eulerian_path(std::vector<edge_id_type>* eulerian_path, const bool strict_cycle, const vertex_id_type starting_vertex, const bool strict_starting_vertex) {
    std::vector<size_type> degree(vertices_count_, 0);
    for (const auto& it : edges()) {
        ++degree[it.to()];
    }
    std::vector<vertex_id_type> odd_degree_vertices;
    for (const vertex_id_type v : vertices()) {
        if (degree[v] % 2 == 1) {
            odd_degree_vertices.emplace_back(v);
        }
    }
    vertex_id_type root = starting_vertex;
    if (!odd_degree_vertices.empty()) {
        if (odd_degree_vertices.size() > 2 || strict_cycle) {
            return false;
        }
        const bool starting_vertex_has_odd_degree = (std::find(odd_degree_vertices.cbegin(), odd_degree_vertices.cend(), starting_vertex) != odd_degree_vertices.cend());
        if (!starting_vertex_has_odd_degree) {
            if (strict_starting_vertex) {
                return false;
            } else {
                root = odd_degree_vertices.front();
            }
        }
    }

    std::vector<bool> used_edge(edges_count(), false);
    auto mark_used = [&used_edge, this](const edge_id_type edge_id) {
        used_edge[edge_id] = true;
        if (!is_directed()) {
            used_edge[edge_id ^ 1] = true;  

        }
    };

    std::vector<typename EdgesList::const_iterator> current_edge_pointer(vertices_count_);
    for (const vertex_id_type v : vertices()) {
        current_edge_pointer[v] = edges_[v].cbegin();
    }
    const edge_id_type kFakeEdgeId = std::numeric_limits<edge_id_type>::max();
    const size_type real_edges_count = edges_count() / (is_directed() ? 1 : 2);
    const size_type max_edges_count = real_edges_count + 1;  

    Stack<std::pair<vertex_id_type, edge_id_type>> stack(max_edges_count);
    stack.push({root, kFakeEdgeId});

    std::vector<edge_id_type> result;
    result.reserve(max_edges_count);
    while (!stack.empty()) {
        vertex_id_type v;
        edge_id_type last_edge_id;
        std::tie(v, last_edge_id) = stack.top();

        auto& iterator = current_edge_pointer[v];
        if (iterator == edges_[v].cend()) {
            result.emplace_back(last_edge_id);
            stack.pop();
            continue;
        }

        const edge_id_type next_edge_id = *iterator++;
        if (used_edge[next_edge_id]) {
            continue;
        }
        mark_used(next_edge_id);
        stack.push({to(next_edge_id), next_edge_id});
    }
    debug(result);
    if (!result.empty() && result.back() == kFakeEdgeId) {
        result.pop_back();
    }
    if (result.size() != real_edges_count) {
        return false;
    }

    if (eulerian_path != nullptr) {
        std::reverse(result.begin(), result.end());
        eulerian_path->swap(result);
    }
    return true;
}


template<typename T = int64_t, uint32_t MASK = 0>
class UndirectedGraph : public Graph<T, MASK> {
public:
    using base_graph_type = Graph<T, MASK>;
    using weight_type = typename base_graph_type::weight_type;
    using vertex_id_type = typename base_graph_type::vertex_id_type;
    using edge_id_type = typename base_graph_type::edge_id_type;
    using size_type = typename base_graph_type::size_type;
    using mask_type = typename base_graph_type::mask_type;

    UndirectedGraph() : UndirectedGraph(0) {}

    explicit UndirectedGraph(const size_type vertices_count) : base_graph_type(vertices_count) {}

    [[nodiscard]] bool is_directed() const override {
        return false;
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!is_weighted_v<Mask>>* = nullptr>
    void add_bidirectional_edge(const vertex_id_type from, const vertex_id_type to) {
        this->add_directed_edge(from, to);
        this->add_directed_edge(to, from);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void add_bidirectional_edge(const vertex_id_type from, const vertex_id_type to, const weight_type weight) {
        this->add_directed_edge(from, to, weight);
        this->add_directed_edge(to, from, weight);
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<!is_weighted_v<Mask>>* = nullptr>
    void add_bidirectional_edge(const typename base_graph_type::Edge& edge) {
        add_bidirectional_edge(edge.from(), edge.to());
    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    void add_bidirectional_edge(const typename base_graph_type::Edge& edge) {
        add_bidirectional_edge(edge.from(), edge.to(), edge.weight());
    }

    void remove_last_bidirectional_edge() {
        this->remove_last_directed_edge();
        this->remove_last_directed_edge();  

    }

    template<mask_type Mask = MASK, typename std::enable_if_t<is_weighted_v<Mask>>* = nullptr>
    weight_type minimal_spanning_tree(std::vector<vertex_id_type>* mst = nullptr) const {
        std::vector<edge_id_type> graph_edges(this->edges_count());
        std::iota(graph_edges.begin(), graph_edges.end(), 0);
        std::sort(graph_edges.begin(), graph_edges.end(), [this](const edge_id_type& lhs, const edge_id_type& rhs) {
            return this->weight(lhs) < this->weight(rhs);
        });
        DSU dsu(this->vertices_count_);
        weight_type total_weight = 0;
        std::vector<vertex_id_type> tree;
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

    [[nodiscard]] bool is_connected() const {
        return dsu().sets_count() == 1;
    }

    [[nodiscard]] DSU dsu() const {
        DSU dsu(this->vertices_count_);
        for (const auto& it : this->edges()) {
            dsu.unite(it.from(), it.to());
        }
        return dsu;
    }

    [[nodiscard]] DSU::container_type labelled_components() const {
        return dsu().finalize().data();
    }
};



class FUnichtozhenieReber {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;

	bool find_eulerian_path(const int starting_vertex, std::vector<std::unordered_multiset<int>>& graph, std::vector<int>& path) {
	    const int n = graph.size();

	    std::vector<int> degree(n, 0);
	    std::vector<int> odd_vertices;
	    for (int i : range(n)) {
            degree[i] = graph[i].size();
            if (degree[i] % 2 == 1) {
                odd_vertices.emplace_back(i);
            }
	    }

	    if (!odd_vertices.empty() && odd_vertices.size() != 2) {
	        return false;
	    }

	    if (!odd_vertices.empty()) {
	        ++degree[odd_vertices.front()];
	        ++degree[odd_vertices.back()];

	        graph[odd_vertices.front()].emplace(odd_vertices.back());
            graph[odd_vertices.back()].emplace(odd_vertices.front());
	    }

	    auto cleanup = [&odd_vertices, &graph]() {
            if (odd_vertices.empty()) {
                return;
            }
            graph[odd_vertices.front()].erase(odd_vertices.back());
            graph[odd_vertices.back()].erase(odd_vertices.front());
	    };

	    


	    const int edges_count = std::accumulate(all(degree), 0);

        auto delete_edge = [&graph, &degree](const int from, const int to) {
            const auto it = graph[from].find(to);
            if (it != graph[from].cend()) {
                graph[from].erase(it);
            }
            const auto jt = graph[to].find(from);
            if (jt != graph[to].cend()) {
                graph[to].erase(jt);
            }

            degree[from] -= 1;
            degree[to] -= 1;
        };

        debug(edges_count);
        path.clear();
        Stack<int> stack(edges_count * 4 + n);
        stack.push(starting_vertex);
        while (!stack.empty()) {
            const int v = stack.top();
            debug(v, degree[v], graph[v]);
            if (degree[v] == 0) {
                stack.pop();
                path.emplace_back(v);
                continue;
            }

            const int to = *graph[v].begin();
            delete_edge(v, to);
            stack.push(to);
        }

        for (int i : range(n)) {
            if (!graph[i].empty()) {
                cleanup();
                return false;
            }
        }

        if (!odd_vertices.empty()) {
            std::vector<int> adjusted_path;

            for (int i : range(path.size() - 1)) {
                const int cur = path[i];
                const int next = path[i + 1];
                if ((cur == odd_vertices.front() && next == odd_vertices.back()) || (cur == odd_vertices.back() && next == odd_vertices.front())) {
                    for (int j : range<int>(i + 1, path.size())) {
                        adjusted_path.emplace_back(path[j]);
                    }
                    for (int j : inclusiveRange<int>(1, i)) {
                        adjusted_path.emplace_back(path[j]);
                    }
                    path.swap(adjusted_path);
                    break;
                }
            }
        }
        cleanup();
        return true;
	}

	void solve(std::istream& in, std::ostream& out) {
        int n, m;
        in >> n >> m;

        std::vector<int> degree(n, 0);
        UndirectedGraph<> graph(n);
        for (int i : range(m)) {
            int from, to;
            in >> from >> to;
            graph.add_bidirectional_edge(from - 1, to - 1);
            ++degree[from - 1];
            ++degree[to - 1];
        }

        

        std::vector<int> path;
        std::vector<size_t> edge_path;
        for (int switch_point : range(-1, n)) {
            std::vector<int> visitors;
            UndirectedGraph<> tmp_graph(n);
            


            for (const auto& it : graph.edges()) {
                if (it.from() == switch_point && degree[it.to()] % 2 == 1) {
                    visitors.emplace_back(it.to());
                    continue;
                }
                if (it.to() == switch_point && degree[it.from()] % 2 == 1) {
                    

                    continue;
                }
                tmp_graph.add_directed_edge(it);
            }


            for (int add_index : range<int>(-1, visitors.size())) {
                const int tmp_vertex = (add_index == -1 ? -1 : visitors[add_index]);
                const int adjusted_visitors_empty_size = (add_index == -1 ? 0 : 1);
                const bool strict_starting_vertex = (switch_point >= 0 && visitors.size() > adjusted_visitors_empty_size);
                if (tmp_vertex != -1) {
                    tmp_graph.add_bidirectional_edge(switch_point, tmp_vertex);
                }
                const bool eulerian_path_found = tmp_graph.find_eulerian_path(&edge_path, false, std::max(switch_point, 0), strict_starting_vertex);
                if (tmp_vertex != -1) {
                    tmp_graph.remove_last_bidirectional_edge();
                }
                if (!eulerian_path_found) {
                    continue;
                }
                debug("PATH FOUND");

                path.clear();
                for (const auto& it : edge_path) {
                    path.emplace_back(tmp_graph.to(it));
                }
                reverse(path);
                if (!edge_path.empty()) {
                    path.emplace_back(tmp_graph.from(edge_path.front()));
                }

                debug(switch_point, tmp_vertex, path);
                if (path.empty()) {
                    path.emplace_back(switch_point);
                }
                path.emplace_back(-2);
                for (const auto& x : visitors) {
                    if (x == tmp_vertex) {
                        continue;
                    }
                    path.emplace_back(x);
                    path.emplace_back(switch_point);
                }

                out << path.size() << std::endl;
                for (const auto& x : path) {
                    out << x + 1 << " ";
                }
                out << std::endl;
                return;
            }
        }
        out << 0 << std::endl;
	}


	FUnichtozhenieReber() {}


	static constexpr bool kUseCustomChecker = true;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
	    auto get_edge = [](const int x, const int y) {
	        return std::make_pair(std::min(x, y), std::max(x, y));
	    };

	    int n, m;
	    in >> n >> m;
	    std::unordered_set<pii> used_edges;
	    for (int i : range(m)) {
	        int x, y;
	        in >> x >> y;
	        used_edges.emplace(get_edge(x, y));
	    }

	    int pcnt;
	    int prev;
	    out >> pcnt >> prev;
	    bool switched = false;
	    bool delete_cur = true;
	    for (int i : range(1, pcnt)) {
	        int v;
	        out >> v;
	        if (v == -1) {
	            switched = true;
	            continue;
	        }
	        delete_cur ^= switched;
	        const auto edge = get_edge(prev, v);
            prev = v;

	        auto it = used_edges.find(edge);
	        if (it == used_edges.cend()) {
	            debug("No such edge", edge);
	            return false;
	        }
	        if (delete_cur) {
	            used_edges.erase(it);
	        }
	    }
	    if (!used_edges.empty()) {
	        debug("Some edges left", used_edges);
	        return false;
	    }

		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 0;
	static constexpr bool kStopAfterFirstFail = true;
	static void generate_test(std::ostream& test) {}

};


int main() {
	FUnichtozhenieReber solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (FUnichtozhenieReber::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (FUnichtozhenieReber::kWriteCaseNumber) {
				out << "Case #" << test_id << ": ";
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
