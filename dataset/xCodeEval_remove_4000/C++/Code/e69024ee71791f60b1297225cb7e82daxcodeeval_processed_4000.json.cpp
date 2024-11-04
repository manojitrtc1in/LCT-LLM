







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
static constexpr bool id8 = is_nbit<T, n>::value;



template <typename T>
struct safely_multipliable {};
template <>
struct safely_multipliable<int> { using type = long long; };
template <>
struct safely_multipliable<long long> { using type = __int128_t; };
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
constexpr inline int id12(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id12(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id12(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id11(const T x) { return suisen::bit_num<T> - 1 - id12(x); }
template <typename T>
constexpr inline int id16(const T x)  { return id11(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id20(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id15 {
        const int s; int t;
        constexpr id15(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id15(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id14(const Comparator comparator) {
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
auto id7(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id7(T n) {
    return id7(0, n);
}

template <typename T>
void id18(std::vector<T> &a) {
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

struct id17 {
    id17(int precision = 20) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << std::fixed << std::setprecision(precision);
    }
} id3 {};










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

constexpr std::uint8_t id10(const std::uint8_t bits) {
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
class id9 {
    private:
        static constexpr unsigned int siz = N / internal::sieve::PROD + 1;
        static std::uint8_t flag[siz];
    public:
        id9() {
            using namespace internal::sieve;
            flag[0] |= 1;
            unsigned int k_max = (unsigned int) std::sqrt(N + 2) / PROD;
            for (unsigned int kp = 0; kp <= k_max; ++kp) {
                for (std::uint8_t bits = ~flag[kp]; bits; bits &= bits - 1) {
                    const std::uint8_t mp = id10(bits & -bits), m = RM[mp];
                    unsigned int kr = kp * (PROD * kp + 2 * m) + m * m / PROD;
                    for (std::uint8_t mq = mp; kr < siz; kr += kp * DR[mq] + DF[mp][mq], ++mq &= 7) {
                        flag[kr] |= MASK[mp][mq];
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
std::uint8_t id9<N>::flag[id9<N>::siz];

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

    template <typename ContainerType, typename ValueType, typename HashType>
    struct id13 {
        using container_type = ContainerType;
        using value_type = ValueType;
        using hash_type = std::make_unsigned_t<HashType>;

        template <typename ...Args>
        id13(Args &&...args) : h(std::forward<Args>(args)...) {}

        

        


        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        


        hash_type empty_set() const {
            return 0;
        }
        hash_type sigleton_set(value_type val) const {
            return h[val];
        }
        hash_type flip(hash_type old_hash, value_type val) const {
            return old_hash ^ h[val];
        }
        hash_type xor_set(hash_type set1, hash_type set2) const {
            return set1 ^ set2;
        }
    protected:
        container_type h;
    };

    template <typename HashType = std::uint64_t>
    struct id0 : public id13<std::vector<HashType>, std::size_t, HashType> {
        using Base = id13<std::vector<HashType>, std::size_t, HashType>;
        
        id0(typename Base::value_type max_val) : Base(max_val + 1) {
            using RNG = std::conditional_t<std::numeric_limits<typename Base::hash_type>::digits == 64, std::mt19937_64, std::mt19937>;
            std::generate(this->h.begin(), this->h.end(), RNG{std::random_device{}()});
        }
    };
    
    template <typename ValueType, typename HashType = std::uint64_t>
    struct id5 : public id13<std::map<ValueType, std::make_unsigned_t<HashType>>, ValueType, HashType> {
        using Base = id13<std::vector<HashType>, std::size_t, HashType>;

        template <typename Container>
        id5(const Container &container) : Base() {
            using RNG = std::conditional_t<std::numeric_limits<typename Base::hash_type>::digits == 64, std::mt19937_64, std::mt19937>;
            RNG rng(std::random_device{}());
            for (auto &val : container) this->h[val] = rng();
        }
    };

} 


constexpr int N = 1000000;
Sieve<N> sieve;

int main() {
    id0 hasher(N);

    input(int, n);

    vector<int> ans(n);
    iota(all(ans), 1);

    auto out = [&]{
        print(ans.size());
        print(ans);
        exit(0);
    };

    auto hash_x = hasher.empty_set();

    for (int v = n; v >= 1; v -= 2) {
        for (auto [p, c] : sieve.factorize(v)) if (c & 1) {
            hash_x = hasher.flip(hash_x, p);
        }
    }

    if (hash_x == 0) {
        out();
    }

    auto hash_y = hasher.empty_set();
    for (int v = 1; v <= n; ++v) {
        for (auto [p, c] : sieve.factorize(v)) if (c & 1) {
            hash_y = hasher.flip(hash_y, p);
        }

        if (hash_x == hash_y) {
            ans.erase(ans.begin() + (v - 1));
            out();
        }
    }

    unordered_map<uint64_t, int> mp;

    hash_y = hasher.empty_set();
    for (int v = 1; v <= n; ++v) {
        for (auto [p, c] : sieve.factorize(v)) if (c & 1) {
            hash_x = hasher.flip(hash_x, p);
            hash_y = hasher.flip(hash_y, p);
        }

        if (auto it = mp.find(hash_x); it != mp.end()) {
            ans.erase(ans.begin() + (v - 1));
            ans.erase(ans.begin() + (it->second - 1));
            out();
        }

        mp[hash_y] = v;
    }

    ans.pop_back();
    ans.erase(ans.begin() + (n / 2 - 1));
    ans.erase(ans.begin() + 1);
    out();
    return 0;
}

