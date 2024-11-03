

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





struct Max {
    template<typename T>
    T operator()(const T& lhs, const T& rhs) const {
        return std::max(lhs, rhs);
    }
};












#ifdef _MSC_VER
#include <intrin.h>
#include <nmmintrin.h>

#define __builtin_popcount __popcnt
#define __builtin_popcountll _mm_popcnt_u64







static inline int __builtin_ctz(unsigned x) {
    unsigned long ret;
    _BitScanForward(&ret, x);
    return (int)ret;
}

static inline int __builtin_ctzll(unsigned long long x) {
    unsigned long ret;
    _BitScanForward64(&ret, x);
    return (int)ret;
}

static inline int __builtin_ctzl(unsigned long x) {
    return sizeof(x) == 8 ? __builtin_ctzll(x) : __builtin_ctz((uint32_t)x);
}

static inline int __builtin_clz(unsigned x) {
    

    

    

    return (int)__lzcnt(x);
}

static inline int __builtin_clzll(unsigned long long x) {
    

    

    

    return (int)__lzcnt64(x);
}

static inline int __builtin_clzl(unsigned long x) {
    return sizeof(x) == 8 ? __builtin_clzll(x) : __builtin_clz((uint32_t)x);
}

#ifdef __cplusplus
static inline int __builtin_ctzl(unsigned long long x) {
    return __builtin_ctzll(x);
}

static inline int __builtin_clzl(unsigned long long x) {
    return __builtin_clzll(x);
}
#endif
#endif





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
constexpr size_t countl_zero(const T value) noexcept {
    constexpr size_t digits = std::numeric_limits<T>::digits;
    if (value == 0) {
        return digits;
    }
    if (sizeof(T) <= sizeof(uint32_t)) {
        return __builtin_clz(value) - (std::numeric_limits<uint32_t>::digits - digits);
    } else {
        return __builtin_clzll(value) - (std::numeric_limits<uint64_t>::digits - digits);
    }
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr size_t countl_zero(const T value) noexcept {
    return countl_zero(static_cast<typename std::make_unsigned_t<T>>(value));
}



template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
constexpr size_t countl_one(const T value) noexcept {
    return countl_zero(static_cast<T>(~value));
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr size_t countr_zero(const T value) noexcept {
    if (value == 0) {
        return std::numeric_limits<T>::digits;
    }
    if (sizeof(T) <= sizeof(uint32_t)) {
        return __builtin_ctz(value);
    } else {
        return __builtin_ctzll(value);
    }
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr size_t countr_zero(const T value) noexcept {
    return countr_zero(static_cast<typename std::make_unsigned_t<T>>(value));
}

template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
constexpr size_t countr_one(const T value) noexcept {
    return countr_zero(static_cast<T>(~value));
}

template<typename T, typename std::enable_if_t<std::is_integral<T>::value>* = nullptr>
constexpr bool has_single_bit(const T value) noexcept {
    return value != 0 && (value & (value - 1)) == 0;
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr T bit_ceil(const T value) noexcept {
    if (value == 0) {
        return 1;
    }
    return static_cast<T>(T{1} << (std::numeric_limits<T>::digits - countl_zero(static_cast<T>(value - 1))));
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr T bit_ceil(const T value) noexcept {
    return static_cast<T>(bit_ceil(static_cast<typename std::make_unsigned_t<T>>(value)));
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr T bit_floor(const T value) noexcept {
    if (value == 0) {
        return 0;
    }
    return static_cast<T>(T{1} << (std::numeric_limits<T>::digits - 1 - countl_zero(value)));
}

template<typename T, typename std::enable_if_t<!std::is_unsigned<T>::value>* = nullptr>
constexpr T bit_floor(const T value) noexcept {
    return static_cast<T>(bit_floor(static_cast<typename std::make_unsigned_t<T>>(value)));
}

template<typename T, typename std::enable_if_t<std::is_unsigned<T>::value>* = nullptr>
constexpr size_t bit_width(const T value) noexcept {
    return static_cast<T>(std::numeric_limits<T>::digits - countl_zero(value));
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
std::string to_binary_string(const T value) {
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
std::string to_binary_string(const T value) {
    return to_binary_string(static_cast<typename std::make_unsigned_t<T>>(value));
}


template<typename T, typename Merge>
class BaseSegmentTree {
public:
    using size_type = std::size_t;
    using value_type = T;
    using merge_type = Merge;

    explicit BaseSegmentTree(
            const size_type elements_count,
            const value_type& default_value = value_type(0),
            const merge_type& merge = merge_type()
    ) :
            elements_count_(elements_count),
            offset_(calculate_offset(elements_count_)),
            size_(offset_ << 1),
            data_(size_, default_value),
            merge_(merge),
            default_value_(default_value)
    {}

    static constexpr size_type calculate_offset(const size_type N) {
        return bit_ceil(N);
    }

    constexpr size_type offset() const {
        return offset_;
    }

    constexpr size_type size() const {
        return size_;
    }

    constexpr size_type elements_count() const {
        return elements_count_;
    }

    constexpr value_type default_value() const {
        return default_value_;
    }

    std::vector<value_type>& data() {
        return data_;
    }

    const std::vector<value_type>& data() const {
        return data_;
    }

    virtual void build(const value_type* a) {
        std::copy(a, a + elements_count_, data_.begin() + offset_);
        for (size_type i = offset_ - 1; i >= 1; --i) {
            merge_children(i);
        }
    }

    virtual void build(const std::vector<value_type>& a) {
        build(a.data());
    }

protected:
    size_type elements_count_;
    size_type offset_;
    size_type size_;

    std::vector<value_type> data_;
    const merge_type merge_;
    const value_type default_value_;

    void merge_children(const size_type v) {
        data_[v] = merge_(data_[v << 1], data_[(v << 1) ^ 1]);
    }
};


template<typename T, typename Merge, typename Update, typename ApplyUpdate, typename MergeUpdates>
class TopDownSegmentTree : public BaseSegmentTree<T, Merge> {
public:
    using apply_update_type = ApplyUpdate;
    using merge_type = Merge;
    using merge_updates_type = MergeUpdates;
    using update_type = Update;
    using value_type = T;

    using Base = BaseSegmentTree<value_type, merge_type>;
    using size_type = typename Base::size_type;

    explicit TopDownSegmentTree(
            const size_type elements_count,
            const value_type& default_value = value_type(),
            const merge_type& merge = merge_type(),
            const update_type& default_update = update_type(),
            const apply_update_type& apply_update = apply_update_type(),
            const merge_updates_type& merge_updates = merge_updates_type()
    ) :
            Base(elements_count, default_value, merge),
            updates_(size_, default_update),
            default_update_(default_update),
            apply_update_(apply_update),
            merge_updates_(merge_updates)
    {}

    void point_update(const size_type index, const update_type& update) {
        range_update(index, index, update);
    }

    void range_update(const size_type left, const size_type right, const update_type& update) {
        update_impl(1, 0, offset_ - 1, left, right, update);
    }

    value_type get(const size_type index) {
        return get(index, index);
    }

    value_type get(const size_type left, const size_type right) {
        return get_impl(1, 0, offset_ - 1, left, right);
    }

    std::vector<update_type>& updates() {
        return updates_;
    }

    const std::vector<update_type>& updates() const {
        return updates_;
    }

    constexpr update_type default_update() const {
        return default_update_;
    }

protected:
    using Base::offset_;
    using Base::size_;
    using Base::data_;
    using Base::merge_;
    using Base::default_value_;

private:
    std::vector<update_type> updates_;
    const update_type default_update_;
    const apply_update_type apply_update_;
    const merge_updates_type merge_updates_;

    static constexpr size_type get_mid(const size_type cur_left, const size_type cur_right) {
        return (cur_left + cur_right) / 2;
    }

    value_type get_impl(const size_type v, const size_type cur_left, const size_type cur_right, const size_type left, const size_type right) {
        if (right < cur_left || left > cur_right) {
            return default_value_;
        }
        debug(left, right, cur_left, cur_right);
        if (left <= cur_left && cur_right <= right) {
            return data_[v];
        }
        push_impl(v, cur_left, cur_right);
        const size_type mid = get_mid(cur_left, cur_right);
        return merge_(
                get_impl(v << 1, cur_left, mid, left, right),
                get_impl((v << 1) ^ 1, mid + 1, cur_right, left, right)
        );
    }

    void update_impl(const size_type v, const size_type cur_left, const size_type cur_right, const size_type left, const size_type right, const update_type& update) {
        if (right < cur_left || left > cur_right) {
            return;
        }
        debug("update_impl", cur_left, cur_right, update.new_multiplier, update.new_index);
        if (left <= cur_left && cur_right <= right) {
            data_[v] = apply_update_(data_[v], update, cur_left, cur_right);
            updates_[v] = merge_updates_(updates_[v], update);
            return;
        }
        push_impl(v, cur_left, cur_right);

        const size_type mid = get_mid(cur_left, cur_right);
        update_impl(v << 1, cur_left, mid, left, right, update);
        update_impl((v << 1) ^ 1, mid + 1, cur_right, left, right, update);

        debug("merge", v, cur_left, cur_right);
        debug("before_merge", data_[v << 1].index, data_[v << 1].multiplier);
        debug("before_merge", data_[(v << 1) ^ 1].index, data_[(v << 1) ^ 1].multiplier);
        this->merge_children(v);
        debug("after_merge", data_[v].index, data_[v].multiplier);
    }

    void push_impl(const size_type v, const size_type cur_left, const size_type cur_right) {
        const size_type mid = get_mid(cur_left, cur_right);

        data_[v << 1] = apply_update_(data_[v << 1], updates_[v], cur_left, mid);
        updates_[v << 1] = merge_updates_(updates_[v << 1], updates_[v]);

        data_[(v << 1) ^ 1] = apply_update_(data_[(v << 1) ^ 1], updates_[v], mid + 1, cur_right);
        updates_[(v << 1) ^ 1] = merge_updates_(updates_[(v << 1) ^ 1], updates_[v]);

        updates_[v] = default_update_;
    }

};

template<typename T, typename Update = T>
struct Applier {
    using size_type = std::size_t;
    using update_type = Update;
    using value_type = T;

    virtual value_type operator()(const value_type& value, const update_type& update, const size_type left, const size_type right) const = 0;
};

template<typename Update>
struct Merger {
    using update_type = Update;

    virtual update_type operator()(const update_type& acc_updates, const update_type& update) const = 0;
};


class DRedaktiruemZingerColor {
public:
	static constexpr bool kWriteCaseNumber = false;
	static constexpr bool kMultiTest = false;

    struct Value {
        int index = 0;
        int multiplier = 0;

        [[nodiscard]] int int_value() const {
            return index * multiplier;
        }

        bool operator <(const Value& rhs) const {
            return int_value() < rhs.int_value() || (int_value() == rhs.int_value() && index < rhs.index);
        }
    };

    struct Update {
        int new_index = 0;
        int new_multiplier = 0;
        bool update_index = false;
        bool update_multiplier = false;

        static Update index_update(const int new_index) {
            return Update{new_index, 0, true, false};
        }

        static Update multiplier_update(const int new_multiplier) {
            return Update{0, new_multiplier, false, true};
        }
    };

    struct ApplyUpdate : Applier<Value, Update> {
        Value operator()(const Value& value, const Update& update, const size_t left, const size_t right) const {
            debug(left, right, update.new_index, update.new_multiplier, update.update_index, update.update_multiplier);
            Value res = value;
            if (update.update_multiplier) {
                res.multiplier = update.new_multiplier;
            }
            if (update.update_index) {
                res.index = update.new_index;
            }
            

            return res;
        }
    };

    struct MergeUpdates : Merger<Update> {
        Update operator()(const Update& acc_updates, const Update& update) const {
            Update res = acc_updates;
            if (update.update_index) {
                res.update_index = true;
                res.new_index = update.update_index;
            }
            if (update.update_multiplier) {
                res.update_multiplier = true;
                res.new_multiplier = update.new_multiplier;
            }
            return res;
        }
    };

    using SegmentTree = TopDownSegmentTree<Value, Max, Update, ApplyUpdate, MergeUpdates>;

	void solve(std::istream& in, std::ostream& out) {
        int n;
        in >> n;

        SegmentTree segment_tree(n + 1);
        segment_tree.point_update(0, Update::index_update(0));
        segment_tree.point_update(0, Update::multiplier_update(1));

        std::vector<std::string> colors(n + 1);
        std::set<int> locks = {-1, n + 1}, unlocks = {0, n + 1};
        bool locked = false;
        colors.front() = "blue";

        for (int i : inclusiveRange(1, n)) {
            in >> colors[i];
            if (colors[i] == "lock") {
                locks.emplace(i);
                locked = true;
            }
            else if (colors[i] == "unlock") {
                unlocks.emplace(i);
                locked = false;
            } else {
                segment_tree.point_update(i, Update::index_update(i));
            }
            if (!locked) {
                segment_tree.point_update(i, Update::multiplier_update(1));
            }
        }

        int m;
        in >> m;
        for (int i : inclusiveRange(m)) {
            debug("QUERY");
            const Value res = segment_tree.get(0, n);
            debug(res.multiplier, res.index);
            {
                const Value tmp = segment_tree.get(n, n);
                debug(tmp.multiplier, tmp.index);
            }
            const int res_index = res.int_value();
            out << colors[res_index] << std::endl;
            if (i == m) {
                break;
            }
            debug("APPLY");
            int pos;
            std::string command;
            in >> pos >> command;

            if (colors[pos] == "lock") {
                locks.erase(pos);

                const int prev_lock = *std::prev(locks.upper_bound(pos));
                const int prev_unlock = *std::prev(unlocks.upper_bound(pos));
                if (prev_lock < prev_unlock) {
                    const int next_lock = *locks.lower_bound(pos);
                    segment_tree.range_update(pos, next_lock - 1, Update::multiplier_update(1));
                }
            }
            else if (colors[pos] == "unlock") {
                unlocks.erase(pos);

                const int prev_lock = *std::prev(locks.upper_bound(pos));
                const int prev_unlock = *std::prev(unlocks.upper_bound(pos));
                if (prev_unlock < prev_lock) {
                    const int next_unlock = *unlocks.lower_bound(pos);
                    segment_tree.range_update(pos, next_unlock - 1, Update::multiplier_update(0));
                }
            }

            colors[pos] = command;
            if (command == "lock") {
                segment_tree.point_update(pos, Update::index_update(0));
                const int next_unlock = *unlocks.lower_bound(pos);
                segment_tree.range_update(pos, next_unlock - 1, Update::multiplier_update(0));
                

                locks.emplace(pos);
            }
            else if (command == "unlock") {
                segment_tree.point_update(pos, Update::index_update(0));
                const int next_lock = *locks.lower_bound(pos);
                debug(pos, next_lock - 1);
                segment_tree.range_update(pos, next_lock - 1, Update::multiplier_update(1));
                

                unlocks.emplace(pos);
            }
            else {
                segment_tree.point_update(pos, Update::index_update(pos));
            }
        }
	}


	DRedaktiruemZingerColor() {}


	static constexpr bool kUseCustomChecker = true;
	bool check(std::istringstream in, std::istringstream jury, std::istringstream out) {
	    int commands_count;
	    in >> commands_count;
	    std::vector<std::string> commands(commands_count);
	    in >> commands;

	    auto process = [](const std::vector<std::string>& commands) {
	        std::string color = "blue";
	        bool locked = false;
	        for (const auto& command : commands) {
	            if (command == "lock") {
	                locked = true;
	            }
	            else if (command == "unlock") {
	                locked = false;
	            }
	            else if (!locked) {
	                color = command;
	            }
	        }
	        return color;
	    };

	    int changes_count;
	    in >> changes_count;
	    for (int i : inclusiveRange(changes_count)) {
	        std::string pans;
	        out >> pans;

            const std::string jans = process(commands);
            if (pans != jans) {
                debug("WTF", i, pans, jans);
                return false;
            }

            if (i == changes_count) {
                break;
            }
	        int index;
	        std::string command;
	        in >> index >> command;
	        commands[index - 1] = command;
	    }
		return true;
	}


	static constexpr size_t kGeneratedTestsCount = 1000;
	static constexpr bool kStopAfterFirstFail = true;
	static void generate_test(std::ostream& test) {
	    static std::vector<std::string> kCommands = {"lock", "unlock", "red", "orange", "yellow", "green", "blue", "indigo", "violet"};

	    auto random_command = []() {
	        return kCommands[Random::get<size_t>(0, kCommands.size() - 1)];
	    };

	    const int kMaxCommands = 4;
	    const int kMaxChanges = 4;

	    const int commands_count = Random::get(1, kMaxCommands);
	    test << commands_count << std::endl;
	    for (int _ : range(commands_count)) {
	        test << random_command() << std::endl;
	    }

	    const int changes_count = Random::get(1, kMaxChanges);
	    test << changes_count << std::endl;
	    for (int _ : range(changes_count)) {
	        test << Random::get(1, commands_count) << " " << random_command() << std::endl;
	    }
	}

};


int main() {
	DRedaktiruemZingerColor solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	srand(time(nullptr));
	out << std::fixed << std::setprecision(16);
	if (DRedaktiruemZingerColor::kMultiTest) {
		size_t tests_count;
		in >> tests_count;
		for (size_t test_id : inclusiveRange<size_t>(1, tests_count)) {
			if (DRedaktiruemZingerColor::kWriteCaseNumber) {
				out << "Case #" << test_id << ": ";
			}
			solver.solve(in, out);
		}
	} else {
		solver.solve(in, out);
	}
	return 0;
}
