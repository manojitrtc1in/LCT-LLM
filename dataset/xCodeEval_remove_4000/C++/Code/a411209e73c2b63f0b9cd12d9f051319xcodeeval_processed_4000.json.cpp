















using namespace std;





template <typename T, typename U>
inline std::vector<T> wrapGrid(std::vector<T> grid, U material) {
    std::vector<T> wrappedGrid(grid.size() + 2,
                               T(grid[0].size() + 2, material));
    for (std::size_t i = 0; i < grid.size(); i++) {
        for (std::size_t j = 0; j < grid[i].size(); j++) {
            wrappedGrid[i + 1][j + 1] = grid[i][j];
        }
    }
    return wrappedGrid;
}


constexpr int dr4[] = {0, 1, 0, -1};
constexpr int dc4[] = {-1, 0, 1, 0};







namespace io {
    inline void id6() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
    }
    inline void setDigits(int digits) {
        std::cout << std::fixed;
        std::cout << std::setprecision(digits);
    }
} 



template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto& it : v) is >> it;
    return is;
}











class reverse_range {
  private:
    struct I {
        int x;
        int operator*() { return x - 1; }
        bool operator!=(I& lhs) { return x > lhs.x; }
        void operator++() { --x; }
    };
    I i, n;

  public:
    
    reverse_range(int n) : i({0}), n({n}) {}
    
    reverse_range(int i, int n) : i({i}), n({n}) {}
    
    I& begin() { return n; }
    
    I& end() { return i; }
};

class range {
  private:
    struct I {
        int x;
        int operator*() { return x; }
        bool operator!=(I& lhs) { return x < lhs.x; }
        void operator++() { ++x; }
    };
    I i, n;

  public:
    
    range(int n) : i({0}), n({n}) {}
    
    range(int i, int n) : i({i}), n({n}) {}
    
    I& begin() { return i; }
    
    I& end() { return n; }
    
    reverse_range operator!() { return reverse_range(*i, *n); }
};























template <typename T>
inline T& unused_var(T& v) {
    return v;
}

template <typename T>
std::vector<T> id5(std::size_t size) {
    return std::vector<T>(size);
}

template <typename T, typename... Ts>
inline auto id5(std::size_t size, Ts... ts) {
    return std::vector<decltype(id5<T>(ts...))>(
        size, id5<T>(ts...));
}






template <typename F, typename T>
inline T chain(T&& v) {
    return v;
}


template <typename F, typename T, typename... Ts>
inline auto chain(const T head, Ts&&... tail) {
    return F::exec(head, chain<F>(tail...));
}


template <typename F, typename T, typename... Ts>
inline bool changeTarget(T& target, Ts&&... candidates) {
    const T old = target;
    target      = chain<F>(target, candidates...);
    return old != target;
}





namespace math {

    
    int64_t id4(int64_t a, int64_t b, int64_t& x, int64_t& y) {
        int64_t g = a;
        x         = 1;
        y         = 0;
        if (b != 0) g = id4(b, a % b, y, x), y -= (a / b) * x;
        return g;
    }


    
    struct BetouzSolution {
        int64_t x, y, dx, dy;
    };


    
    std::optional<BetouzSolution> id3(int64_t a, int64_t b,
                                                 int64_t c) {
        BetouzSolution sol;
        const int64_t g = id4(a, b, sol.x, sol.y);
        if (c % g == 0) {
            return std::nullopt;
        }
        sol.dx = b / g;
        sol.dy = a / g;
        sol.x *= c / g;
        sol.y *= c / g;
        return sol;
    }

    namespace inner {
        
        template <typename T>
        struct GCDFunc {
            
            static inline T exec(T l, T r) {
                while (r != 0) {
                    T u = l % r;
                    l   = r;
                    r   = u;
                }
                return l;
            }
        };

        
        template <typename T>
        struct LCMFunc {
            
            static inline T exec(T l, T r) {
                return (l / GCDFunc<T>::exec(l, r)) * r;
            }
        };

    } 


    
    template <typename... Ts>
    inline int64_t gcd(Ts&&... values) {
        return chain<inner::GCDFunc<int64_t>>(values...);
    }

    
    template <typename... Ts>
    inline int64_t lcm(Ts&&... values) {
        return chain<inner::LCMFunc<int64_t>>(values...);
    }

    
    template <typename ITR>
    inline int64_t id1(ITR l, ITR r) {
        int64_t ret = 1;
        for (auto it = l; it != r; ++it) {
            ret = lcm(ret, *it);
        }
        return ret;
    }

    
    template <typename Container>
    inline int64_t id1(Container container) {
        int64_t ret = 1;
        for (auto e : container) {
            ret = lcm(ret, e);
        }
        return ret;
    }

    
    template <typename ITR>
    inline int64_t id2(ITR l, ITR r) {
        int64_t ret = 0;
        for (auto it = l; it != r; ++it) {
            ret = gcd(ret, *it);
        }
        return ret;
    }

    
    template <typename Container>
    inline int64_t id2(Container container) {
        int64_t ret = 0;
        for (auto e : container) {
            ret = gcd(ret, e);
        }
        return ret;
    }

    
    template <typename T>
    inline T ceil(T u, T d) {
        return (u + d - (T)1) / d;
    }

} 



template <typename T>
struct minFunc {
    
    static T exec(const T l, const T r) { return l < r ? l : r; }
};


template <typename T>
struct maxFunc {
    
    static T exec(const T l, const T r) { return l > r ? l : r; }
};


template <typename T, typename... Ts>
inline T minOf(T head, Ts... tail) {
    return chain<minFunc<T>>(head, tail...);
}


template <typename T, typename... Ts>
inline T maxOf(T head, Ts... tail) {
    return chain<maxFunc<T>>(head, tail...);
}


template <typename T, typename... Ts>
inline bool chmin(T& target, Ts&&... candidates) {
    return changeTarget<minFunc<T>>(target, candidates...);
}


template <typename T, typename... Ts>
inline bool chmax(T& target, Ts&&... candidates) {
    return changeTarget<maxFunc<T>>(target, candidates...);
}







const pid_t pid = getpid();


class id0 {
  private:
    

    unsigned value;

    
    inline void update() {
        value = value ^ (value << 13);
        value = value ^ (value >> 17);
        value = value ^ (value << 5);
    }

    
    inline unsigned get() {
        unsigned v = value;
        update();
        return v;
    }

  public:
    
    template <int bit = 31>
    inline int next_int() {
        return (int)(get() >> (32 - bit));
    }

    
    template <int bit = 31>
    inline int next_signed() {
        unsigned v = get();
        return (int)((v >> (31 - bit)) - (1 << (bit)));
    }

    
    template <int bit = 31>
    inline int range_max() {
        return (int)((1u << bit) - 1);
    };

    
    id0(const unsigned seed) {
        value = seed;
        update();
    }

    
    id0() : id0(pid) {}
};




namespace ext {
    
    template <typename Container>
    inline Container& sort(Container& container) {
        sort(std::begin(container), std::end(container));
        return container;
    }

    
    template <typename Container, typename Comparator>
    inline Container& sort(Container& container, Comparator comparator) {
        sort(std::begin(container), std::end(container), comparator);
        return container;
    }

    
    template <typename Container>
    inline Container& reverse(Container& container) {
        reverse(std::begin(container), std::end(container));
        return container;
    }

    
    template <typename T, typename U>
    inline U accumulate(const std::vector<T>& container, U zero) {
        return std::accumulate(std::begin(container), std::end(container),
                               zero);
    }

    
    template <typename T>
    inline T accumulate(const std::vector<T>& container) {
        return accumulate(container, T(0));
    }

    
    template <typename Container, typename T>
    inline int count(Container& container, T value) {
        return std::count(std::begin(container), std::end(container), value);
    }

    
    inline std::vector<int> iota(int n, int startFrom = 0, int step = 1) {
        std::vector<int> container(n);
        int v = startFrom;
        for (int i = 0; i < n; i++, v += step) {
            container[i] = v;
        }
        return container;
    }

    
    template <typename ITR>
    inline auto maxIn(ITR l, ITR r,
                      std::remove_reference_t<decltype(*l)> defaultValue = 0) {
        if (r == l) {
            return defaultValue;
        }
        return *std::max_element(l, r);
    }


    
    template <typename T>
    inline T maxIn(std::vector<T> container, T defaultValue = 0) {
        return maxIn(container.begin(), container.end(), defaultValue);
    }

    
    template <typename ITR>
    inline auto minIn(ITR l, ITR r,
                      std::remove_reference_t<decltype(*l)> defaultValue = 0) {
        if (r == l) {
            return defaultValue;
        }
        return *std::min_element(l, r);
    }

    
    template <typename T>
    inline T minIn(std::vector<T> container, T defaultValue = 0) {
        return minIn(container.begin(), container.end(), defaultValue);
    }

} 







template <typename T, typename DelimiterType>
std::string join(const T& v, const DelimiterType& delimiter) {
    std::stringstream ss;
    bool isFirst = true;
    for (auto& it : v) {
        if (!isFirst) {
            ss << delimiter;
        }
        isFirst = false;
        ss << it;
    }
    return ss.str();
}


template <typename ITR, typename DelimiterType>
std::string join(const ITR bg, const ITR ed, const DelimiterType& delimiter) {
    std::stringstream ss;
    bool isFirst = true;
    for (auto it = bg; it != ed; ++it) {
        if (!isFirst) {
            ss << delimiter;
        }
        isFirst = false;
        ss << *it;
    }
    return ss.str();
}


namespace strings {

    
    template <std::size_t i>
    struct IndexWrapper {};

    
    template <typename CurrentIndex, typename LastIndex, typename DelimiterType,
              typename... Ts>
    struct JoinFunc;


    
    template <std::size_t i, typename DelimiterType, typename... Ts>
    struct JoinFunc<IndexWrapper<i>, IndexWrapper<i>, DelimiterType, Ts...> {
        
        static std::stringstream& join(std::stringstream& ss,
                                       const std::tuple<Ts...>& values,
                                       const DelimiterType& delimiter) {
            unused_var(delimiter);
            ss << std::get<i>(values);
            return ss;
        }
    };

    
    template <std::size_t i, std::size_t j, typename DelimiterType,
              typename... Ts>
    struct JoinFunc<IndexWrapper<i>, IndexWrapper<j>, DelimiterType, Ts...> {
        
        static std::stringstream& join(std::stringstream& ss,
                                       const std::tuple<Ts...>& values,
                                       const DelimiterType& delimiter) {
            ss << std::get<i>(values);
            ss << delimiter;
            return JoinFunc<IndexWrapper<i + 1>, IndexWrapper<j>, DelimiterType,
                            Ts...>::join(ss, values, delimiter);
        }
    };
} 




template <typename DelimiterType, typename... Ts>
std::string join(const std::tuple<Ts...>& values,
                 const DelimiterType& delimiter) {
    std::stringstream ss;
    constexpr std::size_t lastIndex =
        std::tuple_size<std::tuple<Ts...>>::value - 1u;
    return strings::JoinFunc<strings::IndexWrapper<0>,
                             strings::IndexWrapper<lastIndex>, DelimiterType,
                             Ts...>::join(ss, values, delimiter)
        .str();
}










struct cww {
    cww() {
        io::id6();
        io::setDigits(10);
    }
} star;

int64_t a[112345];
int64_t g[112345]; 


int64_t x[3][112345];
int64_t X[3][112345];


void solve() {
    int n, m;
    cin >> n >> m;
    for (int i : range(n)) {
        cin >> a[i];
    }
    vector<int64_t> k(m);
    vector<vector<int64_t>> b;
    for (int i : range(m)) {
        cin >> k[i];
        b.push_back(vector<int64_t>(k[i]));
        for (int j : range(k[i])) {
            cin >> b[i][j];
        }
        g[i] = std::accumulate(b[i].begin(), b[i].end(), int64_t(0));
    }
    std::sort(a, a + n);
    std::reverse(a, a + n);
    n = m;
    std::reverse(a, a + n);
    auto gi = ext::iota(n);
    ext::sort(gi, [&](int l, int r) { return g[l] * k[r] < g[r] * k[l]; });
    for (int d : {-1, 0, 1}) {
        for (int i : range(n)) {
            x[d + 1][i] = 0;
            if (i + d < 0 || i + d >= n) continue;
            const int id = gi[i + d];
            if (a[i] * k[id] >= g[id]) x[d + 1][i] = 1;
        }
        X[d + 1][0] = 0;
        for (int i : range(n)) {
            X[d + 1][i + 1] = X[d + 1][i] + x[d + 1][i];
        }
    }
    vector<string> ret(n);

    for (int i : range(n)) {
        const int id = gi[i];
        ret[id]      = string(k[id], '0');

        for (int ki : range(k[id])) {
            const auto sum = g[id] - b[id][ki];
            int j          = 0; 

            {
                int ub = n;
                int lb = -1;
                while (ub - lb > 1) {
                    const int mid = (lb + ub) / 2;
                    if (sum * k[gi[mid]] <= g[gi[mid]] * (k[id] - 1)) {
                        ub = mid;
                    }
                    else
                        lb = mid;
                }
                j = ub;
            }


            if (i + 1 < j) {
                if (X[1][i] != i) continue;
                if (X[1][n] - X[1][j] != n - j) continue;
                const auto ss = X[2][j - 1] - X[2][i];
                const auto tt = j - 1 - i;
                if (ss != tt) continue;
                if (a[j - 1] * (k[id] - 1) < sum) continue;
            }
            if (j < i) {
                if (X[1][j] != j) continue;
                if (X[1][n] - X[1][i + 1] != n - (i + 1)) continue;
                const auto ss = X[0][i + 1] - X[0][j + 1];
                const auto tt = i - j;
                if (ss != tt) continue;
                if (a[j] * (k[id] - 1) < sum) continue;
            }
            if (i == j || i + 1 == j) {
                if (X[1][i] != i) continue;
                if (X[1][n] - X[1][i + 1] != n - (i + 1)) continue;
                if (a[i] * (k[id] - 1) < sum) continue;
            }
            ret[id][ki] = '1';
        }
    }

    cout << join(ret, "") << "\n";
}

int main() {
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
