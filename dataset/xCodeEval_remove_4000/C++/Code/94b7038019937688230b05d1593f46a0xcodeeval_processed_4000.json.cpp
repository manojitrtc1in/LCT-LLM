











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
static constexpr bool id5 = is_nbit<T, n>::value;



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
constexpr inline int id3(T n) {
    return -(n & 1) | 1;
}


template <>
constexpr inline int id3<bool>(bool n) {
    return -int(n) | 1;
}



template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + id3(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + id3(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id7(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id7(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id7(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id13(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id6(const T x) { return suisen::bit_num<T> - 1 - id7(x); }
template <typename T>
constexpr inline int id10(const T x)  { return id6(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id14(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id9 {
        const int s; int t;
        constexpr id9(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id9(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id8(const Comparator comparator) {
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
auto id4(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id4(T n) {
    return id4(0, n);
}

template <typename T>
void id11(std::vector<T> &a) {
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
} id2 {};








namespace suisen {
template <typename T>
class id0 {
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
        id0() : _xs(std::vector<T>{}) {}
        explicit id0(const std::vector<T> &xs) : _xs(xs) {}
        explicit id0(std::vector<T> &&xs) : _xs(std::move(xs)) {}
        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        id0(const int n, Gen generator) {
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
            return id0(xs).build();
        }
        

        static auto build(std::vector<T> &&xs) {
            return id0(std::move(xs)).build();
        }
        

        template <typename Gen, constraints_t<is_same_as_invoke_result<T, Gen, int>> = nullptr>
        static auto build(const int n, Gen generator) {
            return id0<T>(n, generator).build();
        }
    private:
        std::vector<T> _xs;
};

} 




namespace suisen {
    struct Permutation : public std::vector<int> {
        using base_type = std::vector<int>;
        using base_type::base_type;

        Permutation() : Permutation(0) {}
        Permutation(std::size_t n) : Permutation(int(n)) {}
        Permutation(int n) : base_type(n) {
            std::iota(begin(), end(), 0);
        }
        Permutation(const std::vector<int>& a) : std::vector<int>(a) {}
        Permutation(std::vector<int>&& a) : std::vector<int>(std::move(a)) {}

        

        template <typename T>
        std::vector<T> permute(const std::vector<T>& a) const {
            const int n = a.size();
            std::vector<T> res(n);
            for (int i = 0; i < n; ++i) res[i] = a[(*this)[i]];
            return res;
        }
        

        template <typename T>
        std::vector<T> id12(const std::vector<T>& a) const {
            const int n = a.size();
            std::vector<T> res(n);
            for (int i = 0; i < n; ++i) res[(*this)[i]] = a[i];
            return res;
        }

        

        friend Permutation operator*(const Permutation& p, const Permutation& q) {
            return q.permute(p);
        }
        Permutation& operator*=(const Permutation& q) {
            return *this = *this * q;
        }
        Permutation inv() const {
            const int n = size();
            Permutation res(n);
            for (int i = 0; i < n; ++i) res[(*this)[i]] = i;
            return res;
        }
        Permutation pow(long long k) const {
            const int n = size();
            Permutation res(n), p = *this;
            for (; k; k >>= 1) {
                if (k & 1) res *= p;
                p *= p;
            }
            return res;
        }

        template <typename T, typename Comp = std::less<T>>
        static Permutation index_sort(const std::vector<T>& a, Comp comp = Comp{}) {
            Permutation p(a.size());
            std::sort(p.begin(), p.end(), [&](int i, int j) { return comp(a[i], a[j]); });
            return p;
        }
    };

    template <typename hash_t>
    struct PermutationHash {
        hash_t operator()(const Permutation &p) const {
            return hash(p);
        }
        
        static hash_t hash(const Permutation &per) {
            hash_t h = 0;
            const int n = per.size();
            Permutation p = per;
            Permutation q = per.inv();
            for (int i = n - 1; i >= 0; --i) {
                h = h * (i + 1) + p[i];
                p[q[i]] = p[i];
                q[p[i]] = q[i];
            }
            return h;
        }
        static Permutation unhash(int n, hash_t h) {
            Permutation p = Permutation(n), q = p;
            for (int i = 0; i < n; ++i) {
                p[i] = h % (i + 1), q[i] = q[p[i]];
                q[p[i]] = p[q[i]] = i;
                h /= i + 1;
            }
            return p;
        }
    };
} 


constexpr long long inf = numeric_limits<long long>::max() / 2;

constexpr int L = 21;

int main() {
    input(int, n, m);
    id0<int> builder;
    vector a(n, vector<int>(m));
    vector<long long> w(n);
    rep(i, n) {
        read(a[i]);
        read(w[i]);
        sort(all(a[i]));
        for (int e : a[i]) builder.push(e);
    }
    builder.push(0);
    auto cmp = builder.build();
    rep(i, n) rep(j, m) a[i][j] = cmp[a[i][j]];
    {
        auto p = Permutation::index_sort(w);
        a = p.permute(a);
        w = p.permute(w);
    }
    w.push_back(inf);

    id0<i128> builder2;
    vector raw_keys(n, vector<i128>(1 << m));
    rep(i, n) {
        rep(s, 1, 1 << m) {
            int t = s & -s;
            raw_keys[i][s] = (raw_keys[i][s ^ t] << L) | a[i][id13(t)];
            builder2.push(raw_keys[i][s]);
        }
    }
    auto cmp2 = builder2.build();
    const int c = cmp2.size();
    vector keys(n, vector<int>(1 << m));
    rep(i, n) {
        rep(s, 1, 1 << m) keys[i][s] = cmp2[raw_keys[i][s]];
        raw_keys[i].clear();
        raw_keys[i].shrink_to_fit();
    }

    vector<int> ng(n, 0), ok(n, n + 1);
    while (true) {
        bool finished = true;
        vector<vector<int>> mid(n + 1);
        rep(i, n) {
            if (ok[i] - ng[i] > 1) {
                mid[(ok[i] + ng[i]) >> 1].push_back(i);
                finished = false;
            }
        }
        if (finished) break;
        vector<int> cnt(c);
        rep(i, n + 1) {
            for (int k : mid[i]) {
                int sum = i;
                rep(s, 1, 1 << m) {
                    if (popcount(s) & 1) {
                        sum -= cnt[keys[k][s]];
                    } else {
                        sum += cnt[keys[k][s]];
                    }
                }
                (sum ? ok[k] : ng[k]) = i;
            }
            if (i == n) break;
            rep(s, 1, 1 << m) ++cnt[keys[i][s]];
        }
    }

    long long ans = inf;
    rep(i, n) chmin(ans, w[i] + w[ng[i]]);
    print(ans == inf ? -1 : ans);

    return 0;
}

