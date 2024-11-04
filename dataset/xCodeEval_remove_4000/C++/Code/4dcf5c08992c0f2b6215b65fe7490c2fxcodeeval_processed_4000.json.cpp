







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
static constexpr bool id4 = is_nbit<T, n>::value;



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
constexpr inline int id2(T n) {
    return -(n & 1) | 1;
}


template <>
constexpr inline int id2<bool>(bool n) {
    return -int(n) | 1;
}



template <typename T>
constexpr inline T fld(const T x, const T y) {
    return (x ^ y) >= 0 ? x / y : (x - (y + id2(y >= 0))) / y;
}
template <typename T>
constexpr inline T cld(const T x, const T y) {
    return (x ^ y) <= 0 ? x / y : (x + (y + id2(y >= 0))) / y;
}

template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcount(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int popcount(const T x) { return __builtin_popcountll(x); }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id6(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id6(const T x) { return x ? __builtin_clz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id6(const T x) { return x ? __builtin_clzll(x) : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 16>> = nullptr>
constexpr inline int id12(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 32>> = nullptr>
constexpr inline int id12(const T x) { return x ? __builtin_ctz(x)   : suisen::bit_num<T>; }
template <typename T, suisen::constraints_t<suisen::is_nbit<T, 64>> = nullptr>
constexpr inline int id12(const T x) { return x ? __builtin_ctzll(x) : suisen::bit_num<T>; }
template <typename T>
constexpr inline int id5(const T x) { return suisen::bit_num<T> - 1 - id6(x); }
template <typename T>
constexpr inline int id10(const T x)  { return id5(x) + ((x & -x) != x); }
template <typename T>
constexpr inline int id13(const T x, const unsigned int k) { return (x >> k) & 1; }
template <typename T>
constexpr inline int parity(const T x) { return popcount(x) & 1; }

struct all_subset {
    struct id8 {
        const int s; int t;
        constexpr id8(int s) : s(s), t(s + 1) {}
        constexpr auto operator*() const { return t; }
        constexpr auto operator++() {}
        constexpr auto operator!=(std::nullptr_t) { return t ? (--t &= s, true) : false; }
    };
    int s;
    constexpr all_subset(int s) : s(s) {}
    constexpr auto begin() { return id8(s); }
    constexpr auto end()   { return nullptr; }
};




template <typename T, typename Comparator, suisen::constraints_t<suisen::is_comparator<Comparator, T>> = nullptr>
auto id7(const Comparator comparator) {
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
auto id3(T l, T r) {
    return generate_vector(r - l, [l](int i) { return l + i; });
}
template <typename T>
auto id3(T n) {
    return id3(0, n);
}

template <typename T>
void id11(std::vector<T> &a) {
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
}

template <typename InputIterator, typename BiConsumer>
auto id0(InputIterator first, InputIterator last, BiConsumer f) -> decltype(f(*first++, *last), void()) {
    if (first != last) for (auto itr = first, itl = itr++; itr != last; itl = itr++) f(*itl, *itr);
}
template <typename Container, typename BiConsumer>
auto id0(Container c, BiConsumer f) -> decltype(c.begin(), c.end(), void()){
    id0(c.begin(), c.end(), f);
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
} id1 {};






namespace suisen {
template <typename Container>
class id9 {
    public:
        using content_type   = typename Container::value_type;
        using value_type     = std::pair<content_type, long long>;
        using iterator       = typename std::vector<value_type>::iterator;
        using const_iterator = typename std::vector<value_type>::const_iterator;

        id9() noexcept : _length(0), comp() {}
        id9(const Container &c) noexcept {
            compress(c, comp);
            _length = c.size();
        }
        long long length() const noexcept {
            return _length;
        }
        void swap(id9<Container>  &other) { comp.swap(other.comp); }
        void swap(id9<Container> &&other) { comp.swap(other.comp); }
        void clear() { comp.clear(); }
        auto begin()   const noexcept { return comp.begin();   }
        auto end()     const noexcept { return comp.end();     }
        auto rbegin()  const noexcept { return comp.rbegin();  }
        auto rend()    const noexcept { return comp.rend();    }
        auto cbegin()  const noexcept { return comp.cbegin();  }
        auto cend()    const noexcept { return comp.cend();    }
        auto crbegin() const noexcept { return comp.crbegin(); }
        auto crend()   const noexcept { return comp.crend();   }

        const auto& front() const { return comp.front(); }
        const auto& back()  const { return comp.back(); }

        void push_back(const content_type &val, const long long num = 1) {
            if (comp.size() and comp.back().first == val) {
                comp.back().second += num;
            } else {
                comp.emplace_back(val, num);
            }
            _length += num;
        }

        long long pop_back(long long num = 1) {
            long long rem = 0;
            while (comp.size()) {
                long long cnt = comp.back().second;
                if (cnt > num) {
                    comp.back.second -= num;
                    return rem + num;
                }
                num -= cnt, rem += cnt;
                comp.pop_back();
            }
            _length -= rem;
            return rem;
        }

    private:
        long long _length;
        std::vector<value_type> comp;

        static void compress(const Container &c, std::vector<value_type> &res) {
            res.clear();
            for (auto it_l = c.begin(), it_r = c.begin(); it_l != c.end(); it_l = it_r) {
                while (it_r != c.end() and *it_l == *it_r) ++it_r;
                res.emplace_back(*it_l, it_r - it_l);
            }
        }
        static std::vector<value_type> compress(const Container &c) {
            std::vector<value_type> res;
            compress(c, res);
            return res;
        }
};
} 


int main() {
    input(int, t);
    loop(t) {
        input(int, n);
        input(long long, a, b, c);
        input(string, s);

        int s0 = 0, s1 = 0;
        rep(i, n - 1) {
            s0 += s[i] == '0' and s[i + 1] == '0';
            s1 += s[i] == '1' and s[i + 1] == '1';
        }
        int c0 = 0, c1 = 0;
        rep(i, n) {
            c0 += s[i] == '0';
            c1 += s[i] == '1';
        }

        id9 rle(s);

        vector<long long> w;
        for (auto [k, v] : rle) {
            if (k == '1') continue;
            w.push_back(v);
        }
        if (s[0] == '0') w.erase(w.begin());
        if (w.size() and s[n - 1] == '0') w.pop_back();
        sort(all(w));
        
        int q = w.size();
        vector<long long> sum(q + 1, 0);
        rep(i, q) sum[i + 1] = w[i] + sum[i];

        long long ans = 0;
        rep(op0, n + 1) {
            if (op0 > c0) break;
            for (int op1 : { op0 - 1, op0, op0 + 1 }) {
                if (op1 < 0 or op1 > c1 - (op1 > 0)) continue;
                long long score = op1 * b;
                if (int r = op1 - s1; r <= 0) {
                    int x = min(op0, s0);
                    score += x * a - (op0 - x) * c;
                    chmax(ans, score);
                } else if (sum[r] <= op0 - (op0 > op1)) {
                    int x = min(op0 - r, s0);
                    int y = op0 - x;
                    score += x * a;
                    score -= y * c;
                    chmax(ans, score);
                }
            }
        }
        print(ans);
    }
    return 0;
}

