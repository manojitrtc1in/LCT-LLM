




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
constexpr inline int id19(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id19(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id25(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id25(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id25(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id17(const T x) { return suisen::bit_num<T> - 1 - id19(x); }
template <typename T>
constexpr inline int id23(const T x)  { return id17(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id27(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id22 {
        const int s; int t;
        constexpr id22(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id22(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id21(const Comparator comparator) {
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
void id24(std::vector<T> &a) {
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













namespace atcoder {

namespace internal {





int id12(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}





constexpr int id14(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}





int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

}  


}  


namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id26 {
  public:
    id26() : id26(0) {}
    explicit id26(int n) : id26(std::vector<S>(n, e())) {}
    explicit id26(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id12(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  


namespace suisen {
    template <typename T, typename F, T(*mapping)(F, T), F(*composition)(F, F), F(*id)()>
    struct id8 {
        id8() {}
        id8(std::vector<T>&& a) : n(a.size()), m(id12(a.size())), data(std::move(a)), lazy(m, id()) {}
        id8(const std::vector<T>& a) : id8(std::vector<T>(a)) {}
        id8(int n, const T& fill_value) : id8(std::vector<T>(n, fill_value)) {}

        T operator[](int i) const {
            assert(0 <= i and i < n);
            T res = data[i];
            for (i = (i + m) >> 1; i; i >>= 1) res = mapping(lazy[i], res);
            return res;
        }
        T get(int i) const {
            return (*this)[i];
        }
        void apply(int l, int r, const F& f) {
            assert(0 <= l and r <= n);
            for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
                if (l & 1) apply(l++, f);
                if (r & 1) apply(--r, f);
            }
        }
    protected:
        int n, m;
        std::vector<T> data;
        std::vector<F> lazy;

        void apply(int k, const F& f) {
            if (k < m) {
                lazy[k] = composition(f, lazy[k]);
            } else {
                data[k - m] = mapping(f, data[k - m]);
            }
        }
    private:
        static int id12(int n) {
            int m = 1;
            while (m < n) m <<= 1;
            return m;
        }
    };
} 






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

constexpr std::uint8_t id15(const std::uint8_t bits) {
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
                    const std::uint8_t mp = id15(bits & -bits), m = RM[mp];
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
                    res.push_back(offset + RM[id15(g)]);
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
                const int base_i = kp * K, id1 = kp * PROD;
                for (int mp = 0; mp < K; ++mp) {
                    const int m = RM[mp], i = base_i + mp;
                    if (pf[i] == 0) {
                        unsigned int act_i = id1 + m;
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
            std::vector<std::pair<int, int>> id0;
            while (n > 1) {
                int p = prime_factor(n), c = 0;
                do { n /= p, ++c; } while (n % p == 0);
                id0.emplace_back(p, c);
            }
            return id0;
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
    struct id20 {
        id20() {}
        template <typename RandomAccessibleContainer>
        id20(const RandomAccessibleContainer& a, Comparator comp = Comparator{}) : n(a.size()), comp(comp), par(calc_par(a, comp)) {}

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
            return id20(a, comp).build();
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
template <typename T>
class id3 {
    public:
        struct Compressor {
            public:
                static constexpr int absent = -1;

                

                Compressor() : _xs(std::vector<T>{}) {}
                

                Compressor(const std::vector<T> &xs) : _xs(xs) {
                    assert(is_strictly_sorted(xs));
                }

                

                int size() const {
                    return _xs.size();
                }
                

                bool has_key(const T &e) const {
                    return std::binary_search(_xs.begin(), _xs.end(), e);
                }
                

                int comp(const T &e, int default_value = absent) const {
                    const int res = min_geq_index(e);
                    return res != size() and _xs[res] == e ? res : default_value;
                }
                

                T decomp(const int compressed_index) const {
                    return _xs[compressed_index];
                }
                

                int operator[](const T &e) const {
                    return comp(e);
                }
                

                T min_gt(const T &e, const T &default_value) const {
                    auto it = std::upper_bound(_xs.begin(), _xs.end(), e);
                    return it == _xs.end() ? default_value : *it;
                }
                

                T min_geq(const T &e, const T &default_value) const {
                    auto it = std::lower_bound(_xs.begin(), _xs.end(), e);
                    return it == _xs.end() ? default_value : *it;
                }
                

                T max_lt(const T &e, const T &default_value) const {
                    auto it = std::upper_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>());
                    return it == _xs.rend() ? default_value : *it;
                }
                

                T max_leq(const T &e, const T &default_value) const {
                    auto it = std::lower_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>());
                    return it == _xs.rend() ? default_value : *it;
                }
                

                int min_gt_index(const T &e) const {
                    return std::upper_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
                }
                

                int min_geq_index(const T &e) const {
                    return std::lower_bound(_xs.begin(), _xs.end(), e) - _xs.begin();
                }
                

                int max_lt_index(const T &e) const {
                    return int(_xs.rend() - std::upper_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>())) - 1;
                }
                

                int max_leq_index(const T &e) const {
                    return int(_xs.rend() - std::lower_bound(_xs.rbegin(), _xs.rend(), e, std::greater<T>())) - 1;
                }
            private:
                std::vector<T> _xs;
                static bool is_strictly_sorted(const std::vector<T> &v) {
                    return std::adjacent_find(v.begin(), v.end(), std::greater_equal<T>()) == v.end();
                }
        };
        id3() : _xs(std::vector<T>{}) {}
        explicit id3(const std::vector<T> &xs) : _xs(xs) {}
        explicit id3(std::vector<T> &&xs) : _xs(std::move(xs)) {}
        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        id3(const int n, Gen generator) {
            reserve(n);
            for (int i = 0; i < n; ++i) push(generator(i));
        }
        

        void reserve(int n) {
            _xs.reserve(n);
        }
        

        void push(const T &first) {
            _xs.push_back(first);
        }
        

        void push(T &&first) {
            _xs.push_back(std::move(first));
        }
        

        template <typename Iterator>
        auto push(const Iterator &first, const Iterator &last) -> decltype(std::vector<T>{}.push_back(*first), void()) {
            for (auto it = first; it != last; ++it) _xs.push_back(*it);
        }
        

        template <typename Iterable>
        auto push(const Iterable &iterable) -> decltype(std::vector<T>{}.push_back(*iterable.begin()), void()) {
            push(iterable.begin(), iterable.end());
        }
        

        template <typename ...Args>
        void emplace(Args &&...args) {
            _xs.emplace_back(std::forward<Args>(args)...);
        }
        

        auto build() {
            std::sort(_xs.begin(), _xs.end()), _xs.erase(std::unique(_xs.begin(), _xs.end()), _xs.end());
            return Compressor {_xs};
        }
        

        static auto build(const std::vector<T> &xs) {
            return id3(xs).build();
        }
        

        static auto build(std::vector<T> &&xs) {
            return id3(std::move(xs)).build();
        }
        

        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        static auto build(const int n, Gen generator) {
            return id3<T>(n, generator).build();
        }
    private:
        std::vector<T> _xs;
};

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
struct LinearFunction { T a, b; };

template <typename T>
struct Data {
    LinearFunction<T> f;
    int len;
};
template <typename T>
Data<T> op(Data<T> x, Data<T> y) {
    return Data<T>{ LinearFunction<T> { x.f.a + y.f.a, x.f.b + y.f.b }, x.len + y.len };
}
template <typename T>
Data<T> e() {
    return Data<T>{ LinearFunction<T> { T{ 0 }, T{ 0 } }, 0 };
}
template <typename T>
Data<T> mapping(LinearFunction<T> f, Data<T> x) {
    return Data<T>{ LinearFunction<T> { x.f.a + x.len * f.a, x.f.b + x.len * f.b }, x.len };
}
template <typename T>
LinearFunction<T> composition(LinearFunction<T> f, LinearFunction<T> g) {
    return LinearFunction<T>{ f.a + g.a, f.b + g.b };
}
template <typename T>
LinearFunction<T> id() {
    return LinearFunction<T>{ T{ 0 }, T{ 0 } };
};

template <typename T>
std::vector<T> id2(std::vector<AddQuery<T>> add_queries, std::vector<SumQuery> sum_queries) {
    const int id10 = add_queries.size(), id13 = sum_queries.size();

    id3<int> bx, by;
    for (const auto& add_query : add_queries) {
        bx.push(add_query.l), bx.push(add_query.r);
        by.push(add_query.d), by.push(add_query.u);
    }
    for (const auto& sum_query : sum_queries) {
        bx.push(sum_query.l), bx.push(sum_query.r);
        by.push(sum_query.d), by.push(sum_query.u);
    }
    const auto cmp_x = bx.build(), cmp_y = by.build();

    const int siz_x = cmp_x.size(), siz_y = cmp_y.size();

    std::vector<std::vector<std::tuple<int, int, LinearFunction<T>>>> id18(siz_x);
    std::vector<std::vector<std::tuple<int, int, bool, int>>> id16(siz_x);
    for (int i = 0; i < id10; ++i) {
        auto& add_query = add_queries[i];
        add_query.l = cmp_x[add_query.l], add_query.r = cmp_x[add_query.r];
        add_query.d = cmp_y[add_query.d], add_query.u = cmp_y[add_query.u];
        id18[add_query.l].emplace_back(
            add_query.d, add_query.u,
            LinearFunction<T>{ add_query.val, add_query.val * -cmp_x.decomp(add_query.l) }
        );
        id18[add_query.r].emplace_back(
            add_query.d, add_query.u,
            LinearFunction<T>{ -add_query.val, add_query.val * cmp_x.decomp(add_query.r) }
        );
    }
    for (int i = 0; i < id13; ++i) {
        auto& sum_query = sum_queries[i];
        sum_query.l = cmp_x[sum_query.l], sum_query.r = cmp_x[sum_query.r];
        sum_query.d = cmp_y[sum_query.d], sum_query.u = cmp_y[sum_query.u];
        id16[sum_query.l].emplace_back(sum_query.d, sum_query.u, false, i);
        id16[sum_query.r].emplace_back(sum_query.d, sum_query.u, true, i);
    }

    std::vector<Data<T>> init(siz_y - 1, Data<T>{ id<T>(), 0 });
    for (int i = 0; i < siz_y - 1; ++i) init[i].len = cmp_y.decomp(i + 1) - cmp_y.decomp(i);

    atcoder::id26<Data<T>, op<T>, e<T>, LinearFunction<T>, mapping<T>, composition<T>, id<T>> seg(init);

    std::vector<T> res(id13, T{ 0 });
    for (int i = 0; i < siz_x; ++i) {
        
        for (const auto& [l, r, is_add, id] : id16[i]) {
            Data<T> dat = seg.prod(l, r);
            T val = dat.f.a * cmp_x.decomp(i) + dat.f.b;
            if (is_add) {
                res[id] += val;
            } else {
                res[id] -= val;
            }
        }
        for (const auto& [l, r, f] : id18[i]) {
            seg.apply(l, r, f);
        }
    }

    return res;
}

int op_min(int x, int y) {
    return min(x, y);
}
int e_min() {
    return numeric_limits<int>::max() / 2;
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

    auto builder = id20<int, greater<int>>{ p };
    auto t = builder.build();

    auto rec = [&](auto rec, int l, int r, int root) -> void {
        if (root == t.absent) return;

        vector<pair<int, int>> points;
        vector<int> xs{ l - 1 };

        for (int x : sieve.divisors(p[root])) {
            const int y = p[root] / x;
            if (x <= y) continue;
            int a = min(inv_p[x], inv_p[y]);
            int b = max(inv_p[x], inv_p[y]);
            if (a < l or b >= r) continue;
            chmin(a, root);
            chmax(b, root);
            points.emplace_back(a, b + 1);
            xs.push_back(a);
        }

        auto cmp = id3<int>::build(xs);
        const int m = cmp.size();

        id8<int, int, op_min, op_min, e_min> seg(vector<int>(m, r + 1));
        for (auto [a, b] : points) {
            a = cmp[a];
            seg.apply(0, a + 1, b);
        }

        rep(i, 1, m) {
            int lx = cmp.decomp(i - 1) + 1;
            int rx = cmp.decomp(i) + 1;
            int ly = seg.get(i);
            int ry = r + 1;
            debug(p[root], lx, rx, ly, ry);
            add_queries.push_back(AddQuery<long long> { lx, rx, ly, ry, 1 });
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

    print_all(id2(add_queries, sum_queries), "\n");

    return 0;
}

