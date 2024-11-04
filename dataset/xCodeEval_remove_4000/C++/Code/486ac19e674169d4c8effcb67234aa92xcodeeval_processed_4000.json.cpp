







namespace suisen {


template <typename ...Types>
using constraints_t = std::enable_if_t<std::conjunction_v<Types...>, std::nullptr_t>;
template <bool cond_v, typename Then, typename OrElse>
constexpr decltype(auto) constexpr_if(Then&& then, OrElse&& or_else) {
    if constexpr (cond_v) {
        return std::forward<Then>(then);
    } else {
        return std::forward<OrElse>(or_else);
    }
}



template <typename ReturnType, typename Callable, typename ...Args>
using is_same_as_invoke_result = std::is_same<std::invoke_result_t<Callable, Args...>, ReturnType>;
template <typename F, typename T>
using is_uni_op = is_same_as_invoke_result<T, F, T>;
template <typename F, typename T>
using is_bin_op = is_same_as_invoke_result<T, F, T, T>;

template <typename Comparator, typename T>
using is_comparator = std::is_same<std::invoke_result_t<Comparator, T, T>, bool>;



template <typename T, typename = constraints_t<std::is_integral<T>>>
constexpr int bit_num = std::numeric_limits<std::make_unsigned_t<T>>::digits;
template <typename T, unsigned int n>
struct is_nbit { static constexpr bool value = bit_num<T> == n; };
template <typename T, unsigned int n>
static constexpr bool id6 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long long> { using type = __uint128_t; };
template <>
struct safely_multipliable<float> { using type = float; };
template <>
struct safely_multipliable<double> { using type = double; };
template <>
struct safely_multipliable<long double> { using type = long double; };
template <typename T>
using safely_multipliable_t = typename safely_multipliable<T>::type;

} 




using i128 = __int128_t;
using u128 = __uint128_t;
using ll = long long;
using uint = unsigned int;
using ull  = unsigned long long;

template <typename T> using vec  = std::vector<T>;
template <typename T> using vec2 = vec<vec <T>>;
template <typename T> using vec3 = vec<vec2<T>>;
template <typename T> using vec4 = vec<vec3<T>>;

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;


































template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U> &a) {
    return out << a.first << ' ' << a.second;
}


template <unsigned int N = 0, typename ...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return out;
    } else {
        out << std::get<N>(a);
        if constexpr (N + 1 < std::tuple_size_v<std::tuple<Args...>>) {
            out << ' ';
        }
        return operator<<<N + 1>(out, a);
    }
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}


template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end();) {
        out << *it;
        if (++it != a.end()) out << ' ';
    }
    return out;
}
inline void print() { std::cout << '\n'; }
template <typename Head, typename... Tail>
inline void print(const Head &head, const Tail &...tails) {
    std::cout << head;
    if (sizeof...(tails)) std::cout << ' ';
    print(tails...);
}
template <typename Iterable>
auto print_all(const Iterable& v, std::string sep = " ", std::string end = "\n") -> decltype(std::cout << *v.begin(), void()) {
    for (auto it = v.begin(); it != v.end();) {
        std::cout << *it;
        if (++it != v.end()) std::cout << sep;
    }
    std::cout << end;
}



template <typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U> &a) {
    return in >> a.first >> a.second;
}


template <unsigned int N = 0, typename ...Args>
std::istream& operator>>(std::istream& in, std::tuple<Args...> &a) {
    if constexpr (N >= std::tuple_size_v<std::tuple<Args...>>) {
        return in;
    } else {
        return operator>><N + 1>(in >> std::get<N>(a), a);
    }
}


template <typename T>
std::istream& operator>>(std::istream& in, std::vector<T> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}


template <typename T, size_t N>
std::istream& operator>>(std::istream& in, std::array<T, N> &a) {
    for (auto it = a.begin(); it != a.end(); ++it) in >> *it;
    return in;
}
template <typename ...Args>
void read(Args &...args) {
    ( std::cin >> ... >> args );
}






template <typename T>
constexpr inline int id4(T n) {
    return -(n & 1) | 1;
}


template <>
constexpr inline int id4<bool>(bool n) {
    return -int(n) | 1;
}



template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + id4(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + id4(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id8(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id8(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id8(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id7(const T x) { return suisen::bit_num<T> - 1 - id8(x); }
template <typename T>
constexpr inline int id11(const T x)  { return id7(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id0(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id10 {
        const int s; int t;
        constexpr id10(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id10(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id9(const Comparator comparator) {
    return std::priority_queue<T, std::vector<T>, Comparator>(comparator);
}

template <typename Iterable>
auto isize(const Iterable &iterable) -> decltype(int(iterable.size())) {
    return iterable.size();
}

template <typename T, typename Gen, suisen::constraints_t<suisen::is_same_as_invoke_result<T, Gen, int>> = nullptr>
auto generate_vector(int n, Gen generator) {
    std::vector<T> v(n);
    for (int i = 0; i < n; ++i) v[i] = generator(i);
    return v;
}
template <typename T>
auto id5(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id5(T n) {
    return id5(0, n);
}

template <typename T>
void id12(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto id1(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto id1(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()){
    id1(c.begin(), c.end(), f);
}






template <typename T>
inline bool chmin(T &x, const T &y) {
    if (y >= x) return false;
    x = y;
    return true;
}


template <typename T>
inline bool chmax(T &x, const T &y) {
    if (y <= x) return false;
    x = y;
    return true;
}

namespace suisen {}
using namespace suisen;
using namespace std;

struct io_setup {
    io_setup(int precision = 20) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(precision);
    }
} id3 {};









namespace suisen {
template <typename T, int bit_length = std::numeric_limits<std::make_unsigned_t<T>>::digits>
class BinaryTrie {
    using U = std::make_unsigned_t<T>;
    struct Node {
        int siz;
        Node *ch[2] {nullptr, nullptr};
        Node() : siz(0) {}
        ~Node() {
            delete ch[0];
            delete ch[1];
        }
        inline Node* get_or_create(bool b) noexcept {
            if (is_absent(b)) ch[b] = new Node();
            return ch[b];
        }
        inline Node* operator[](bool b) const noexcept { return ch[b]; }
        inline bool is_absent (bool b) const noexcept { return ch[b] == nullptr; }
        inline bool is_present(bool b) const noexcept { return ch[b] != nullptr; }
        static inline int size(const Node *const node) noexcept { return node == nullptr ? 0 : node->siz; }
        inline void update_size() noexcept { siz = size(ch[0]) + size(ch[1]); }

        std::string to_string(const int k = bit_length - 1, const U val = 0, const std::string &prefix = "") const {
            static const std::string zo[2] {"+-[0]- ", "+-[1]- "};
            static const std::string branch = '|' + std::string(zo[0].size() - 1, ' ');
            auto res = std::to_string(siz) + ' ';
            if (is_absent(0) and is_absent(1)) {
                return res + "(" + std::to_string(val) + ")\n";
            }
            auto pref0 = prefix + std::string(res.size(), ' ');
            auto prefb = pref0 + branch;
            auto pref1 = pref0 + std::string(zo[0].size(), ' ');
            if (is_absent(0) or is_absent(1)) {
                bool b = is_absent(0);
                return res + zo[b] + ch[b]->to_string(k - 1, val | (b << k), pref1);
            }
            res += zo[0] + ch[0]->to_string(k - 1, val, prefb);
            res += pref0 + "|\n";
            res += pref0 + zo[1] + ch[1]->to_string(k - 1, val | (1 << k), pref1);
            return res;
        }
    };
    public:
        BinaryTrie() : root(new Node) {}
        ~BinaryTrie() { delete root; }

        inline int size() const noexcept { return Node::size(root); }
        inline bool empty() const noexcept { return size() == 0; }

        int insert(const U val, const int num = 1) noexcept {
            if (num == 0) return 0;
            Node *cur = root;
            cur->siz += num;
            for (int i = bit_length; i --> 0;) {
                cur = cur->get_or_create(bit(val, i));
                cur->siz += num;
            }
            return cur->siz;
        }
        int erase(const U val, const int num = 1) noexcept {
            if (num == 0) return 0;
            return erase(root, bit_length - 1, val, num);
        }
        int erase_all(const U val) noexcept {
            return erase(val, std::numeric_limits<int>::max());
        }
        int prefix_count(const U val, const unsigned int l) const noexcept {
            Node *cur = root;
            for (int i = bit_length; i --> l;) {
                if (cur == nullptr) return 0;
                cur = (*cur)[bit(val, i)];
            }
            return Node::size(cur);
        }
        inline int count(const U val) const noexcept { return prefix_count(val, 0); }
        inline bool contains(const U val) const noexcept { return count(val) > 0; }

        inline U xor_kth_min(const U x, const int k) const {
            assert(0 <= k and k < size());
            return id14<false>(x, k);
        }
        inline U xor_kth_max(const U x, const int k) const {
            assert(0 <= k and k < size());
            return id14<true>(x, k);
        }
        inline U xor_min(const U x) const { return xor_kth_min(x, 0);  }
        inline U xor_max(const U x) const { return xor_kth_max(x, 0); }
        int xor_count_lt(const U x, const U val) const noexcept {
            int res = 0;
            Node *cur = root;
            for (int i = bit_length - 1; i >= 0; --i) {
                if (cur == nullptr) break;
                bool bx = bit(x, i);
                bool bv = bit(x ^ val, i);
                if (bx != bv) {
                    res += Node::size((*cur)[bx]);
                }
                cur = (*cur)[bv];
            }
            return res;
        }
        inline int xor_count_leq(const U x, const U val) const noexcept { return xor_count_lt(x, val) + count(val); }
        inline int xor_count_gt (const U x, const U val) const noexcept { return size() - xor_count_leq(x, val);    }
        inline int xor_count_geq(const U x, const U val) const noexcept { return size() - xor_count_lt(x, val);     }
        inline U xor_lower(const U x, const U val, const U default_value = ~U(0)) const noexcept {
            int k = size() - xor_count_geq(x, val) - 1;
            return k < 0 ? default_value : id14(x, k);
        }
        inline U xor_floor(const U x, const U val, const U default_value = ~U(0)) const noexcept {
            int k = size() - xor_count_gt(x, val) - 1;
            return k < 0 ? default_value : id14(x, k);
        }
        inline U xor_higher(const U x, const U val, const U default_value = ~U(0)) const noexcept {
            int k = xor_count_leq(x, val);
            return k == size() ? default_value : id14(x, k);
        }
        inline U xor_ceil(const U x, const U val, const U default_value = ~U(0)) const noexcept {
            int k = xor_count_lt(x, val);
            return k == size() ? default_value : id14(x, k);
        }

        inline U kth_min(const int k) const { return xor_kth_min(0, k); }
        inline U min() const { return xor_kth_min(0, 0); }
        inline U max() const { return xor_kth_min(~U(0), 0); }
        inline int count_lt (const U val) const noexcept { return xor_count_lt(0, val);  }
        inline int count_leq(const U val) const noexcept { return xor_count_leq(0, val); }
        inline int count_gt (const U val) const noexcept { return xor_count_gt(0, val);  }
        inline int count_geq(const U val) const noexcept { return xor_count_geq(0, val); }
        inline U lower (const U val, const U default_value = ~U(0)) const noexcept { return xor_lower (0, val, default_value); }
        inline U floor (const U val, const U default_value = ~U(0)) const noexcept { return xor_floor (0, val, default_value); }
        inline U higher(const U val, const U default_value = ~U(0)) const noexcept { return xor_higher(0, val, default_value); }
        inline U ceil  (const U val, const U default_value = ~U(0)) const noexcept { return xor_ceil  (0, val, default_value); }

        inline std::string to_string() const noexcept { return root->to_string(); }
        friend std::ostream& operator<<(std::ostream& out, const BinaryTrie &bt) { return out << bt.to_string(); }
    private:
        Node *const root;
        static constexpr bool bit(const U val, const int i) noexcept {
            return (val >> i) & 1;
        }
        int erase(Node *cur, const int k, const U val, const int num) {
            if (k == -1) {
                int removed = std::min(cur->siz, num);
                cur->siz -= removed;
                return removed;
            }
            bool b = bit(val, k);
            if (cur->is_absent(b)) return 0;
            int removed = erase((*cur)[b], k - 1, val, num);
            cur->update_size();
            return removed;
        }
        template <bool id2 = false>
        U id14(const U x, const int k) const noexcept {
            U res = 0;
            int rest = k;
            Node *cur = root;
            for (int i = bit_length - 1; i >= 0; --i) {
                bool b = id2 ^ bit(x, i);
                int sz = Node::size((*cur)[b]);
                if (sz <= rest) rest -= sz, b = not b;
                res |= U(b) << i;
                cur = (*cur)[b];
            }
            return x ^ res;
        }
};
} 


int main() {
    input(int, t);
    loop(t) {
        input(uint32_t, l, r);
        vector<uint32_t> a(r - l + 1);
        read(a);

        BinaryTrie<uint32_t, 17> bt;
        for (int v : a) bt.insert(v);

        for (uint32_t v : a) {
            uint32_t x = v ^ l;
            uint32_t vl = bt.xor_min(x);
            uint32_t vr = bt.xor_max(x);
            if (vl == l and vr == r) {
                print(x);
                break;
            }
        }
    }
    return 0;
}

