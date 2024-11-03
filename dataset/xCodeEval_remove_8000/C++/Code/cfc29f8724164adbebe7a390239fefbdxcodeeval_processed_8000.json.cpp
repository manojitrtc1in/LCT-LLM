




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
static constexpr bool id9 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
template <>
struct safely_multipliable<unsigned int> { using type = unsigned long long; };
template <>
struct safely_multipliable<unsigned long int> { using type = __uint128_t; };
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

template <typename T>
using pq_greater = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T, typename U>
using umap = std::unordered_map<T, U>;
































template <class T, class... Args>
void debug_internal(const char* s, T&& first, Args&&... args) {
    constexpr const char* prefix = "[\033[32mDEBUG\033[m] ";
    constexpr const char* open_brakets = sizeof...(args) == 0 ? "" : "(";
    constexpr const char* close_brakets = sizeof...(args) == 0 ? "" : ")";
    std::cerr << prefix << open_brakets << s << close_brakets << ": " << open_brakets << std::forward<T>(first);
    ((std::cerr << ", " << std::forward<Args>(args)), ...);
    std::cerr << close_brakets << "\n";
}










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
constexpr inline int id6(T n) {
    return -(n & 1) | 1;
}


template <>
constexpr inline int id6<bool>(bool n) {
    return -int(n) | 1;
}



template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + id6(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + id6(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id15(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id15(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id15(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id22(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id22(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id22(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id13(const T x) { return suisen::bit_num<T> - 1 - id15(x); }
template <typename T>
constexpr inline int id20(const T x)  { return id13(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id24(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id19 {
        const int s; int t;
        constexpr id19(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id19(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id18(const Comparator comparator) {
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
auto id8(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id8(T n) {
    return id8(0, n);
}

template <typename T>
void id21(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto id4(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto id4(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()){
    id4(c.begin(), c.end(), f);
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
} id5{};










namespace suisen::internal::sieve {

constexpr std::uint8_t K = 8;
constexpr std::uint8_t PROD = 2 * 3 * 5;
constexpr std::uint8_t RM[K] = { 1,  7, 11, 13, 17, 19, 23, 29 };
constexpr std::uint8_t DR[K] = { 6,  4,  2,  4,  2,  4,  6,  2 };
constexpr std::uint8_t DF[K][K] = {
    { 0, 0, 0, 0, 0, 0, 0, 1 }, { 1, 1, 1, 0, 1, 1, 1, 1 },
    { 2, 2, 0, 2, 0, 2, 2, 1 }, { 3, 1, 1, 2, 1, 1, 3, 1 },
    { 3, 3, 1, 2, 1, 3, 3, 1 }, { 4, 2, 2, 2, 2, 2, 4, 1 },
    { 5, 3, 1, 4, 1, 3, 5, 1 }, { 6, 4, 2, 4, 2, 4, 6, 1 },
};
constexpr std::uint8_t DRP[K] = { 48, 32, 16, 32, 16, 32, 48, 16 };
constexpr std::uint8_t DFP[K][K] = {
    {  0,  0,  0,  0,  0,  0,  0,  8 }, {  8,  8,  8,  0,  8,  8,  8,  8 },
    { 16, 16,  0, 16,  0, 16, 16,  8 }, { 24,  8,  8, 16,  8,  8, 24,  8 },
    { 24, 24,  8, 16,  8, 24, 24,  8 }, { 32, 16, 16, 16, 16, 16, 32,  8 },
    { 40, 24,  8, 32,  8, 24, 40,  8 }, { 48, 32, 16, 32, 16, 32, 48,  8 },
};

constexpr std::uint8_t MASK[K][K] = {
    { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 }, { 0x02, 0x20, 0x10, 0x01, 0x80, 0x08, 0x04, 0x40 },
    { 0x04, 0x10, 0x01, 0x40, 0x02, 0x80, 0x08, 0x20 }, { 0x08, 0x01, 0x40, 0x20, 0x04, 0x02, 0x80, 0x10 },
    { 0x10, 0x80, 0x02, 0x04, 0x20, 0x40, 0x01, 0x08 }, { 0x20, 0x08, 0x80, 0x02, 0x40, 0x01, 0x10, 0x04 },
    { 0x40, 0x04, 0x08, 0x80, 0x01, 0x10, 0x20, 0x02 }, { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 },
};
constexpr std::uint8_t OFFSET[K][K] = {
    { 0, 1, 2, 3, 4, 5, 6, 7, },
    { 1, 5, 4, 0, 7, 3, 2, 6, },
    { 2, 4, 0, 6, 1, 7, 3, 5, },
    { 3, 0, 6, 5, 2, 1, 7, 4, },
    { 4, 7, 1, 2, 5, 6, 0, 3, },
    { 5, 3, 7, 1, 6, 0, 4, 2, },
    { 6, 2, 3, 7, 0, 4, 5, 1, },
    { 7, 6, 5, 4, 3, 2, 1, 0, },
};

constexpr std::uint8_t id12(const std::uint8_t bits) {
    switch (bits) {
        case 1 << 0: return 0;
        case 1 << 1: return 1;
        case 1 << 2: return 2;
        case 1 << 3: return 3;
        case 1 << 4: return 4;
        case 1 << 5: return 5;
        case 1 << 6: return 6;
        case 1 << 7: return 7;
        default: assert(false);
    }
}
} 


namespace suisen {

template <unsigned int N>
class id11 {
    private:
        static constexpr unsigned int siz = N / internal::sieve::PROD + 1;
        static std::uint8_t flag[siz];
    public:
        id11() {
            using namespace internal::sieve;
            flag[0] |= 1;
            unsigned int k_max = (unsigned int) std::sqrt(N + 2) / PROD;
            for (unsigned int kp = 0; kp <= k_max; ++kp) {
                for (std::uint8_t bits = ~flag[kp]; bits; bits &= bits - 1) {
                    const std::uint8_t mp = id12(bits & -bits), m = RM[mp];
                    unsigned int kr = kp * (PROD * kp + 2 * m) + m * m / PROD;
                    for (std::uint8_t mq = mp; kr < siz; kr += kp * DR[mq] + DF[mp][mq], ++mq &= 7) {
                        flag[kr] |= MASK[mp][mq];
                    }
                }
            }
        }
        std::vector<int> prime_list(unsigned int max_val = N) const {
            using namespace internal::sieve;
            std::vector<int> res { 2, 3, 5 };
            res.reserve(max_val / 25);
            for (unsigned int i = 0, offset = 0; i < siz and offset < max_val; ++i, offset += PROD) {
                for (uint8_t f = ~flag[i]; f;) {
                    uint8_t g = f & -f;
                    res.push_back(offset + RM[id12(g)]);
                    f ^= g;
                }
            }
            while (res.size() and (unsigned int) res.back() > max_val) res.pop_back();
            return res;
        }
        bool is_prime(const unsigned int p) const {
            using namespace internal::sieve;
            switch (p) {
                case 2: case 3: case 5: return true;
                default:
                    switch (p % PROD) {
                        case RM[0]: return ((flag[p / PROD] >> 0) & 1) == 0;
                        case RM[1]: return ((flag[p / PROD] >> 1) & 1) == 0;
                        case RM[2]: return ((flag[p / PROD] >> 2) & 1) == 0;
                        case RM[3]: return ((flag[p / PROD] >> 3) & 1) == 0;
                        case RM[4]: return ((flag[p / PROD] >> 4) & 1) == 0;
                        case RM[5]: return ((flag[p / PROD] >> 5) & 1) == 0;
                        case RM[6]: return ((flag[p / PROD] >> 6) & 1) == 0;
                        case RM[7]: return ((flag[p / PROD] >> 7) & 1) == 0;
                        default: return false;
                    }
            }
        }
};
template <unsigned int N>
std::uint8_t id11<N>::flag[id11<N>::siz];

template <unsigned int N>
class Sieve {
    private:
        static constexpr unsigned int base_max = (N + 1) * internal::sieve::K / internal::sieve::PROD;
        static unsigned int pf[base_max + internal::sieve::K];

    public:
        Sieve() {
            using namespace internal::sieve;
            pf[0] = 1;
            unsigned int k_max = ((unsigned int) std::sqrt(N + 1) - 1) / PROD;
            for (unsigned int kp = 0; kp <= k_max; ++kp) {
                const int base_i = kp * K, id2 = kp * PROD;
                for (int mp = 0; mp < K; ++mp) {
                    const int m = RM[mp], i = base_i + mp;
                    if (pf[i] == 0) {
                        unsigned int act_i = id2 + m;
                        unsigned int base_k = (kp * (PROD * kp + 2 * m) + m * m / PROD) * K;
                        for (std::uint8_t mq = mp; base_k <= base_max; base_k += kp * DRP[mq] + DFP[mp][mq], ++mq &= 7) {
                            pf[base_k + OFFSET[mp][mq]] = act_i;
                        }
                    }
                }
            }
        }
        bool is_prime(const unsigned int p) const {
            using namespace internal::sieve;
            switch (p) {
                case 2: case 3: case 5: return true;
                default:
                    switch (p % PROD) {
                        case RM[0]: return pf[p / PROD * K + 0] == 0;
                        case RM[1]: return pf[p / PROD * K + 1] == 0;
                        case RM[2]: return pf[p / PROD * K + 2] == 0;
                        case RM[3]: return pf[p / PROD * K + 3] == 0;
                        case RM[4]: return pf[p / PROD * K + 4] == 0;
                        case RM[5]: return pf[p / PROD * K + 5] == 0;
                        case RM[6]: return pf[p / PROD * K + 6] == 0;
                        case RM[7]: return pf[p / PROD * K + 7] == 0;
                        default: return false;
                    }
            }
        }
        int prime_factor(const unsigned int p) const {
            using namespace internal::sieve;
            switch (p % PROD) {
                case  0: case  2: case  4: case  6: case  8:
                case 10: case 12: case 14: case 16: case 18:
                case 20: case 22: case 24: case 26: case 28: return 2;
                case  3: case  9: case 15: case 21: case 27: return 3;
                case  5: case 25: return 5;
                case RM[0]: return pf[p / PROD * K + 0] ? pf[p / PROD * K + 0] : p;
                case RM[1]: return pf[p / PROD * K + 1] ? pf[p / PROD * K + 1] : p;
                case RM[2]: return pf[p / PROD * K + 2] ? pf[p / PROD * K + 2] : p;
                case RM[3]: return pf[p / PROD * K + 3] ? pf[p / PROD * K + 3] : p;
                case RM[4]: return pf[p / PROD * K + 4] ? pf[p / PROD * K + 4] : p;
                case RM[5]: return pf[p / PROD * K + 5] ? pf[p / PROD * K + 5] : p;
                case RM[6]: return pf[p / PROD * K + 6] ? pf[p / PROD * K + 6] : p;
                case RM[7]: return pf[p / PROD * K + 7] ? pf[p / PROD * K + 7] : p;
                default: assert(false);
            }
        }
        
        std::vector<std::pair<int, int>> factorize(unsigned int n) const {
            assert(0 < n and n <= N);
            std::vector<std::pair<int, int>> id1;
            while (n > 1) {
                int p = prime_factor(n), c = 0;
                do { n /= p, ++c; } while (n % p == 0);
                id1.emplace_back(p, c);
            }
            return id1;
        }
        
        std::vector<int> divisors(unsigned int n) const {
            assert(0 < n and n <= N);
            std::vector<int> divs { 1 };
            for (auto [prime, index] : factorize(n)) {
                int sz = divs.size();
                for (int i = 0; i < sz; ++i) {
                    int d = divs[i];
                    for (int j = 0; j < index; ++j) {
                        divs.push_back(d *= prime);
                    }
                }
            }
            return divs;
        }
};
template <unsigned int N>
unsigned int Sieve<N>::pf[Sieve<N>::base_max + internal::sieve::K];
} 





namespace suisen {
    struct CartesianTree : public std::vector<std::array<int, 2>> {
        using base_type = std::vector<std::array<int, 2>>;

        static constexpr int absent = -1;

        const int root;

        CartesianTree() : base_type(), root(0) {}
        CartesianTree(int root, const base_type& g) : base_type(g), root(root) {}
        CartesianTree(int root, base_type&& g) : base_type(std::move(g)), root(root) {}

        auto ranges() const {
            std::vector<std::pair<int, int>> res;
            res.reserve(size());
            auto rec = [&](auto rec, int l, int m, int r) -> void {
                if (m == absent) return;
                const auto& [lm, rm] = (*this)[m];
                rec(rec, l, lm, m), res.emplace_back(l, r), rec(rec, m + 1, rm, r);
            };
            rec(rec, 0, root, size());
            return res;
        }
    };

    template <typename T, typename Comparator, constraints_t<is_comparator<Comparator, T>> = nullptr>
    struct id16 {
        id16() {}
        template <typename RandomAccessibleContainer>
        id16(const RandomAccessibleContainer& a, Comparator comp = Comparator{}) : n(a.size()), comp(comp), par(calc_par(a, comp)) {}

        CartesianTree build() const {
            int root = -1;
            std::vector<std::array<int, 2>> g(n, { CartesianTree::absent, CartesianTree::absent });
            for (int i = 0; i < n; ++i) {
                int p = par[i];
                (p >= 0 ? g[p][p <= i] : root) = i;
            }
            return CartesianTree{ root, std::move(g) };
        }

        template <typename RandomAccessibleContainer>
        static CartesianTree build(const RandomAccessibleContainer& a, Comparator comp = Comparator{}) {
            return id16(a, comp).build();
        }

        int parent(std::size_t i) const {
            assert(i < std::size_t(n));
            return par[i];
        }
        int operator[](std::size_t i) const {
            return parent(i);
        }
    private:
        const int n;
        const Comparator comp;
        const std::vector<int> par;

        template <typename RandomAccessibleContainer>
        static std::vector<int> calc_par(const RandomAccessibleContainer& a, Comparator comp) {
            const int n = a.size();
            std::vector<int> par(n, -1);
            for (int i = 1; i < n; ++i) {
                int p = i - 1, l = i;
                while (p >= 0 and comp(a[i], a[p])) l = p, p = par[p];
                par[l] = i, par[i] = p;
            }
            return par;
        }
    };
} 





namespace suisen {
    namespace internal {
        template <typename T, typename index_t = int, typename Container = std::vector<T>>
        class id10 {
        public:
            id10() {}
            explicit id10(index_t n) : n(n) {}

            int size() const {
                return n;
            }
            void add(index_t i, T v) {
                for (++i; i <= n; i += (i & -i)) data[i - 1] += v;
            }
            T sum(index_t l, index_t r) const {
                return sum(r) - sum(l);
            }
            auto operator[](int i) {
                struct {
                    int i;
                    id10& ft;
                    operator T() const { return ft.sum(i, i + 1); }
                    auto& operator++() { return *this += 1; }
                    auto& operator--() { return *this -= 1; }
                    auto& operator+=(T val) { ft.add(i, val); return *this; }
                    auto& operator-=(T val) { ft.add(i, -val); return *this; }
                    auto& operator*=(T val) { T cur = ft.sum(i, i + 1); ft.add(i, cur * val - cur); return *this; }
                    auto& operator/=(T val) { T cur = ft.sum(i, i + 1); ft.add(i, cur / val - cur); return *this; }
                    auto& operator%=(T val) { T cur = ft.sum(i, i + 1); ft.add(i, cur % val - cur); return *this; }
                    auto& operator =(T val) { T cur = ft.sum(i, i + 1); ft.add(i, val - cur); return *this; }
                } obj{ i, *this };
                return obj;
            }
            T operator()(int l, int r) const { return sum(l, r); }

            Container& get_internal_container() { return data; }
        protected:
            index_t n;
            Container data;
            template <typename ...Args>
            id10(index_t n, Args &&...args) : n(n), data(std::forward<Args>(args)...) {}
        private:
            T sum(int r) const {
                T s{};
                for (; r; r -= r & -r) s += data[r - 1];
                return s;
            }
        };

        template <typename Key, typename Value, bool unordered>
        using cond_map_t = std::conditional_t<unordered, std::unordered_map<Key, Value>, std::map<Key, Value>>;

    } 


    template <typename T>
    struct id23 : public internal::id10<T> {
        id23() : id23(0) {}
        explicit id23(int n) : internal::id10<T>::id10(n, n, T{}) {}
        explicit id23(std::vector<T>&& a) : internal::id10<T>::id10(a.size(), std::move(a)) {
            for (int i = 1; i <= this->n; ++i) {
                int p = i + (i & -i);
                if (p <= this->n) this->data[p - 1] += this->data[i - 1];
            }
        }
        explicit id23(const std::vector<T>& a) : id23(std::vector<T>(a)) {}
    };

    template <typename T, typename index_t, bool id14 = false>
    using MapFenwickTree = internal::id10<T, index_t, internal::cond_map_t<index_t, T, id14>>;

} 




namespace suisen {
    namespace internal::tuple_ops {
        template <std::size_t N, typename F, typename ...Args>
        std::tuple<Args...>& update(std::tuple<Args...> &lhs, F &&fun) {
            if constexpr (N == std::tuple_size_v<std::tuple<Args...>>) return lhs;
            else return fun(std::get<N>(lhs)), update<N + 1>(lhs, std::forward<F>(fun));
        }
        template <std::size_t N, typename F, typename ...Args>
        std::tuple<Args...>& merge(std::tuple<Args...> &lhs, const std::tuple<Args...>& rhs, F &&fun) {
            if constexpr (N == std::tuple_size_v<std::tuple<Args...>>) return lhs;
            else return fun(std::get<N>(lhs), std::get<N>(rhs)), merge<N + 1>(lhs, rhs, std::forward<F>(fun));
        }
    }
    template <typename ...Args>
    std::tuple<Args...>& operator+=(std::tuple<Args...>& t1, const std::tuple<Args...>& t2) {
        return internal::tuple_ops::merge<0>(t1, t2, [](auto &x, const auto &y) { x += y; });
    }
    template <typename ...Args>
    std::tuple<Args...>& operator-=(std::tuple<Args...>& t1, const std::tuple<Args...>& t2) {
        return internal::tuple_ops::merge<0>(t1, t2, [](auto &x, const auto &y) { x -= y; });
    }
    template <typename ...Args>
    std::tuple<Args...> operator+(std::tuple<Args...> t1, const std::tuple<Args...>& t2) { return std::move(t1 += t2); }
    template <typename ...Args>
    std::tuple<Args...> operator-(std::tuple<Args...> t1, const std::tuple<Args...>& t2) { return std::move(t1 -= t2); }
    
    template <typename V, typename ...Args>
    std::tuple<Args...>& operator*=(std::tuple<Args...>& t1, const V &v) { return internal::tuple_ops::update<0>(t1, [&v](auto &x) { x *= v; }); }
    template <typename V, typename ...Args>
    std::tuple<Args...>& operator/=(std::tuple<Args...>& t1, const V &v) { return internal::tuple_ops::update<0>(t1, [&v](auto &x) { x /= v; }); }

    template <typename V, typename ...Args>
    std::tuple<Args...> operator*(const V &v, std::tuple<Args...> t1) { return std::move(t1 *= v); }
    template <typename V, typename ...Args>
    std::tuple<Args...> operator*(std::tuple<Args...> t1, const V &v) { return std::move(t1 *= v); }
    template <typename V, typename ...Args>
    std::tuple<Args...> operator/(std::tuple<Args...> t1, const V &v) { return std::move(t1 /= v); }
} 


template <typename T>
struct AddQuery {
    int l, r, d, u;
    T val;
};
struct SumQuery {
    int l, r, d, u;
};

template <typename T>
std::vector<T> id3(const std::vector<AddQuery<T>>& add_queries, const std::vector<SumQuery>& sum_queries) {
    using suffix_add_query_t = std::tuple<int, int, T>;
    using prefix_sum_query_t = std::tuple<int, int, int, bool>;

    std::vector<int> ys;
    std::vector<suffix_add_query_t> id17;
    for (const auto& q : add_queries) {
        ys.push_back(q.d), ys.push_back(q.u);
        id17.emplace_back(q.l, q.d, q.val), id17.emplace_back(q.r, q.d, -q.val);
        id17.emplace_back(q.l, q.u, -q.val), id17.emplace_back(q.r, q.u, q.val);
    }

    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());
    auto compress = [&ys](int y) -> int { return std::lower_bound(ys.begin(), ys.end(), y) - ys.begin(); };

    std::vector<prefix_sum_query_t> id7;
    for (std::size_t i = 0; i < sum_queries.size(); ++i) {
        const auto& q = sum_queries[i];
        id7.emplace_back(q.l, q.d, i, true), id7.emplace_back(q.r, q.d, i, false);
        id7.emplace_back(q.l, q.u, i, false), id7.emplace_back(q.r, q.u, i, true);
    }

    static constexpr auto id0 = [](const auto& q1, const auto& q2) { return std::get<0>(q1) < std::get<0>(q2); };
    std::sort(id17.begin(), id17.end(), id0);
    std::sort(id7.begin(), id7.end(), id0);

    using data_type = std::tuple<T, T, T, T>;
    id23<data_type> ft(ys.size());

    std::vector<T> res(sum_queries.size(), T{ 0 });
    const int n = id17.size(), m = id7.size();
    for (int i = 0, j = 0; i < n or j < m;) {
        if (j == m or (i < n and std::get<0>(id17[i]) < std::get<0>(id7[j]))) {
            const auto &[l, d, v] = id17[i++];
            

            ft.add(compress(d), data_type { v, -v * d, -v * l, v * l * d });
        } else {
            const auto &[x, y, qid, is_add] = id7[j++];
            auto [a, b, c, d] = ft.sum(0, compress(y));
            const T sum = a * x * y + b * x + c * y + d;
            if (is_add) res[qid] += sum;
            else        res[qid] -= sum;
        }
    }
    return res;
}

Sieve<200000> sieve;

int main() {
    input(int, n, q);
    vector<int> p(n);
    read(p);

    vector<int> inv_p(n + 1);
    rep(i, n) {
        inv_p[p[i]] = i;
    }

    std::vector<AddQuery<long long>> add_queries;

    auto builder = id16<int, greater<int>>{ p };
    auto t = builder.build();

    auto rec = [&](auto rec, int l, int r, int root) -> void {
        if (root == t.absent) return;

        vector<pair<int, int>> points;

        for (int x : sieve.divisors(p[root])) {
            const int y = p[root] / x;
            if (x <= y) continue;
            int a = min(inv_p[x], inv_p[y]);
            int b = max(inv_p[x], inv_p[y]);
            if (a < l or b >= r) continue;
            chmin(a, root);
            chmax(b, root);
            points.emplace_back(a, b);
        }

        sort(all(points));

        vector<pair<int, int>> st;
        for (const auto& [x, y] : points) {
            while (st.size() and st.back().second >= y) st.pop_back();
            st.emplace_back(x, y);
        }

        int px = l - 1;
        for (const auto& [x, y] : st) {
            add_queries.push_back(AddQuery<long long> { px + 1, x + 1, y + 1, r + 1, 1 });
            px = x;
        }

        rec(rec, l, root, t[root][0]);
        rec(rec, root + 1, r, t[root][1]);
    };
    rec(rec, 0, n, t.root);

    std::vector<SumQuery> sum_queries;

    for (int i = 0; i < q; ++i) {
        input(int, l, r);
        --l;
        sum_queries.push_back(SumQuery{ l, n + 1, 0, r + 1 });
    }

    print_all(id3(add_queries, sum_queries), "\n");

    return 0;
}

