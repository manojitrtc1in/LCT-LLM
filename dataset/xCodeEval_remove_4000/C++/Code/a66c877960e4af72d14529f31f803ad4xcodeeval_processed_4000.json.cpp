







































using i64 = int_fast64_t;
using pii = std::pair<int, int>;
using pll = std::pair<int_fast64_t, int_fast64_t>;
template <class T>
using heap = std::priority_queue<T>;
template <class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
constexpr T inf = std::numeric_limits<T>::max() / T(2) - T(1123456);

namespace execution
{
    std::chrono::system_clock::time_point start_time, end_time;
    void id5()
    {
        end_time = std::chrono::system_clock::now();
        std::cerr << "\n----- Exec time : ";
        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(
                         end_time - start_time)
                         .count();
        std::cerr << " ms -----\n\n";
    }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie)
            {
                std::ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(__precision__);

            if(freopen(stderr_path, "a", stderr))
            {
                std::cerr << std::fixed << std::setprecision(__precision__);
            }
            else
                fclose(stderr);


            if(not freopen(stdout_path, "w", stdout))
            {
                freopen("CON", "w", stdout);
                std::cerr << "Failed to open the stdout file\n\n";
            }
            std::cout << "";


            if(not freopen(stdin_path, "r", stdin))
            {
                freopen("CON", "r", stdin);
                std::cerr << "Failed to open the stdin file\n\n";
            }


            atexit(id5);
            start_time = std::chrono::system_clock::now();

        }
    } id6;
} 


class id2
{
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    std::string built_func, last_func;
    bool id4;

  public:
    explicit id2() : id4(false)
    {}
    void build(int crt_ln, const std::string &crt_func)
    {
        id4 = true;
        last_pt = built_pt = std::chrono::system_clock::now();
        last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(id4)
        {
            last_pt = std::chrono::system_clock::now();
            last_ln = crt_ln, last_func = crt_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] "
                         << "id2::set failed (yet to be built!)\n";
        }
    }
    void get(int crt_ln, const std::string &crt_func)
    {
        if(id4)
        {
            std::chrono::system_clock::time_point crt_pt(
                std::chrono::system_clock::now());
            int64_t diff =
                std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt -
                                                                      last_pt)
                    .count();
            debug_stream << diff << " ms elapsed from"
                         << " [ " << last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to"
                         << " [ " << crt_ln << " : " << crt_func << " ]"
                         << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] "
                         << "id2::get failed (yet to be built!)\n";
        }
    }
};

id2 id0;









namespace std
{
    template <class RAitr>
    void rsort(RAitr __first, RAitr __last)
    {
        sort(__first, __last, greater<>());
    }
    template <class T>
    size_t id3(size_t seed, T const &key)
    {
        return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
    }
    template <class T, class U>
    struct hash<pair<T, U>>
    {
        size_t operator()(pair<T, U> const &pr) const
        {
            return id3(id3(0, pr.first), pr.second);
        }
    };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc
    {
        static size_t apply(size_t seed, tuple_t const &t)
        {
            return id3(
                tuple_hash_calc<tuple_t, index - 1>::apply(seed, t),
                get<index>(t));
        }
    };
    template <class tuple_t>
    struct tuple_hash_calc<tuple_t, 0>
    {
        static size_t apply(size_t seed, tuple_t const &t)
        {
            return id3(seed, get<0>(t));
        }
    };
    template <class... T>
    struct hash<tuple<T...>>
    {
        size_t operator()(tuple<T...> const &t) const
        {
            return tuple_hash_calc<tuple<T...>>::apply(0, t);
        }
    };
    template <class T, class U>
    istream &operator>>(std::istream &s, pair<T, U> &p)
    {
        return s >> p.first >> p.second;
    }
    template <class T, class U>
    ostream &operator<<(std::ostream &s, const pair<T, U> p)
    {
        return s << p.first << " " << p.second;
    }
    template <class T>
    istream &operator>>(istream &s, vector<T> &v)
    {
        for(T &e : v)
        {
            s >> e;
        }
        return s;
    }
    template <class T>
    ostream &operator<<(ostream &s, const vector<T> &v)
    {
        bool is_front = true;
        for(const T &e : v)
        {
            if(not is_front)
            {
                s << ' ';
            }
            else
            {
                is_front = false;
            }
            s << e;
        }
        return s;
    }
    template <class tuple_t, size_t index>
    struct tupleos
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            tupleos<tuple_t, index - 1>::apply(s, t);
            return s << " " << get<index>(t);
        }
    };
    template <class tuple_t>
    struct tupleos<tuple_t, 0>
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            return s << get<0>(t);
        }
    };
    template <class... T>
    ostream &operator<<(ostream &s, const tuple<T...> &t)
    {
        return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(
            s, t);
    }
    template <>
    ostream &operator<<(ostream &s, const tuple<> &t)
    {
        return s;
    }
    string revstr(string str)
    {
        reverse(str.begin(), str.end());
        return str;
    }
} 




    debug_stream << "[ " << __LINE__ << " : " << __FUNCTION__ << " ]\n",       \
        dump_func(
template <class T>
void dump_func(const char *ptr, const T &x)
{
    debug_stream << '\t';
    for(char c = *ptr; c != '\0'; c = *++ptr)
    {
        if(c != ' ') debug_stream << c;
    }
    debug_stream << " : " << x << '\n';
}
template <class T, class... rest_t>
void dump_func(const char *ptr, const T &x, rest_t... rest)
{
    debug_stream << '\t';
    for(char c = *ptr; c != ','; c = *++ptr)
    {
        if(c != ' ') debug_stream << c;
    }
    debug_stream << " : " << x << ",\n";
    dump_func(++ptr, rest...);
}



template <class P>
void read_range(P __first, P __second)
{
    for(P i = __first; i != __second; ++i)
        std::cin >> *i;
}
template <class P>
void write_range(P __first, P __second)
{
    for(P i = __first; i != __second;
        std::cout << (++i == __second ? '\n' : ' '))
    {
        std::cout << *i;
    }
}



template <class T>
void subst(T &x, const T &y)
{
    x = y;
}


template <class T>
bool chmin(T &x, const T &y)
{
    return x > y ? x = y, true : false;
}


template <class T>
bool chmax(T &x, const T &y)
{
    return x < y ? x = y, true : false;
}
template <class T>
constexpr T minf(const T &x, const T &y)
{
    return std::min(x, y);
}
template <class T>
constexpr T maxf(const T &x, const T &y)
{
    return std::max(x, y);
}


template <class int_t, class F>
int_t bin(int_t ok, int_t ng, const F &f)
{
    while(std::abs(ok - ng) > 1)
    {
        int_t mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class T, class A, size_t N>
void init(A (&array)[N], const T &val)
{
    std::fill((T *)array, (T *)(array + N), val);
}
void reset()
{}
template <class A, class... rest_t>
void reset(A &array, rest_t... rest)
{
    memset(array, 0, sizeof(array));
    reset(rest...);
}


template <typename int_t>
int_t rand_int(int_t l, int_t r)
{
    static std::random_device seed_gen;
    static std::mt19937 engine(seed_gen());
    std::uniform_int_distribution<int_t> unid(l, r - 1);
    return unid(engine);
}


template <typename real_t>
real_t rand_real(real_t l, real_t r)
{
    static std::random_device seed_gen;
    static std::mt19937 engine(seed_gen());
    std::uniform_real_distribution<real_t> unid(l, r);
    return unid(engine);
}



using namespace std;



signed main()
{
    void __solve();
    void id1();

    unsigned int t = 1;
    

    id1();

    while(t--)
    {
        __solve();
    }
}

void id1()
{}

namespace math
{
    template <int_fast32_t mod>
    struct modint
    {
        int x;

        constexpr modint() : x(0)
        {}
        constexpr modint(int_fast64_t y)
            : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod)
        {}

        constexpr modint &operator+=(const modint &p)
        {
            if((x += p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator++()
        {
            return ++x, *this;
        }

        constexpr modint operator++(int)
        {
            modint t = *this;
            return ++x, t;
        }

        constexpr modint &operator-=(const modint &p)
        {
            if((x += mod - p.x) >= mod) x -= mod;
            return *this;
        }

        constexpr modint &operator--()
        {
            return --x, *this;
        }

        constexpr modint operator--(int)
        {
            modint t = *this;
            return --x, t;
        }

        constexpr modint &operator*=(const modint &p)
        {
            return x = (int_fast64_t)x * p.x % mod, *this;
        }

        constexpr modint &operator/=(const modint &p)
        {
            return *this *= inverse(p);
        }

        


        constexpr modint operator-() const
        {
            return modint(-x);
        }

        constexpr modint operator+(const modint &p) const
        {
            return modint(*this) += p;
        }

        constexpr modint operator-(const modint &p) const
        {
            return modint(*this) -= p;
        }

        constexpr modint operator*(const modint &p) const
        {
            return modint(*this) *= p;
        }

        constexpr modint operator/(const modint &p) const
        {
            return modint(*this) /= p;
        }

        

        


        constexpr bool operator==(const modint &p) const
        {
            return x == p.x;
        }

        constexpr bool operator!=(const modint &p) const
        {
            return x != p.x;
        }

        constexpr bool operator!() const
        {
            return !x;
        }

        


        


        


        


        constexpr friend modint inverse(const modint &p)
        {
            int a = p.x, b = mod, u = 1, v = 0;
            while(b > 0)
            {
                int t = a / b;
                a -= t * b;
                a ^= b ^= a ^= b;
                u -= t * v;
                u ^= v ^= u ^= v;
            }
            return modint(u);
        }

        constexpr friend modint pow(modint p, int_fast64_t e)
        {
            if(e < 0) e = (e % (mod - 1) + mod - 1) % (mod - 1);
            modint ret = 1;
            while(e)
            {
                if(e & 1) ret *= p;
                p *= p;
                e >>= 1;
            }
            return ret;
        }

        friend std::ostream &operator<<(std::ostream &s, const modint &p)
        {
            return s << p.x;
        }

        friend std::istream &operator>>(std::istream &s, modint &p)
        {
            int_fast64_t x;
            p = modint((s >> x, x));
            return s;
        }
    };
} 


template <class K>


struct matrix
{
    std::vector<std::vector<K>> mat;

    matrix()
    {}
    matrix(size_t n)
    {
        assign(n, n);
    }
    matrix(size_t h, size_t w)
    {
        assign(h, w);
    }
    matrix(const matrix &x) : mat(x.mat)
    {}

    void resize(size_t h, size_t w, const K v = K(0))
    {
        mat.resize(h, std::vector<K>(w, v));
    }

    void assign(size_t h, size_t w, const K v = K())
    {
        mat.assign(h, std::vector<K>(w, v));
    }

    size_t height() const
    {
        return mat.size();
    }

    size_t width() const
    {
        return mat.empty() ? 0 : mat[0].size();
    }

    bool is_square() const
    {
        return height() == width();
    }

    std::vector<K> &operator[](const size_t i)
    {
        return mat[i];
    }

    static matrix identity(size_t n)
    {
        matrix ret(n, n);
        for(size_t i = 0; i < n; ++i)
            ret[i][i] = K(1);
        return ret;
    }

    matrix operator-() const
    {
        size_t h = height(), w = width();
        matrix res(*this);
        for(size_t i = 0; i < h; ++i)
        {
            for(size_t j = 0; j < w; ++j)
            {
                res[i][j] = -mat[i][j];
            }
        }
        return res;
    }

    matrix operator&(const matrix &x) const
    {
        return matrix(*this) &= x;
    }

    matrix operator|(const matrix &x) const
    {
        return matrix(*this) |= x;
    }

    matrix operator^(const matrix &x) const
    {
        return matrix(*this) ^= x;
    }

    matrix operator+(const matrix &x) const
    {
        return matrix(*this) += x;
    }

    matrix operator-(const matrix &x) const
    {
        return matrix(*this) -= x;
    }

    matrix operator*(const matrix &x) const
    {
        return matrix(*this) *= x;
    }

    matrix &operator&=(const matrix &x)
    {
        size_t h = height(), w = width();
        assert(h == x.height() and w == x.width());
        for(size_t i = 0; i < h; ++i)
        {
            for(size_t j = 0; j < w; ++j)
            {
                mat[i][j] &= x.mat[i][j];
            }
        }
        return *this;
    }

    matrix &operator|=(const matrix &x)
    {
        size_t h = height(), w = width();
        assert(h == x.height() and w == x.width());
        for(size_t i = 0; i < h; ++i)
        {
            for(size_t j = 0; j < w; ++j)
            {
                mat[i][j] |= x.mat[i][j];
            }
        }
        return *this;
    }

    matrix &operator^=(const matrix &x)
    {
        size_t h = height(), w = width();
        assert(h == x.height() and w == x.width());
        for(size_t i = 0; i < h; ++i)
        {
            for(size_t j = 0; j < w; ++j)
            {
                mat[i][j] ^= x.mat[i][j];
            }
        }
        return *this;
    }

    matrix &operator+=(const matrix &x)
    {
        size_t h = height(), w = width();
        assert(h == x.height() and w == x.width());
        for(size_t i = 0; i < h; ++i)
        {
            for(size_t j = 0; j < w; ++j)
            {
                mat[i][j] += x.mat[i][j];
            }
        }
        return *this;
    }

    matrix &operator-=(const matrix &x)
    {
        size_t h = height(), w = width();
        assert(h == x.height() and w == x.width());
        for(size_t i = 0; i < h; ++i)
        {
            for(size_t j = 0; j < w; ++j)
            {
                mat[i][j] -= x.mat[i][j];
            }
        }
        return *this;
    }

    matrix &operator*=(const matrix &x)
    {
        size_t l = height(), m = width(), n = x.width();
        assert(m == x.height());
        matrix res(l, n);
        for(size_t i = 0; i < l; ++i)
        {
            for(size_t j = 0; j < m; ++j)
            {
                for(size_t k = 0; k < n; ++k)
                {
                    res[i][k] += mat[i][j] * x.mat[j][k];
                }
            }
        }
        return *this = res;
    }

    friend matrix pow(matrix x, int_fast64_t n)
    {
        assert(x.is_square());
        matrix res = identity(x.height());
        while(n)
        {
            if(n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    friend matrix inverse(const matrix &x)
    {
        assert(x.is_square());
        size_t n = x.height();
        matrix ext_x(x), e(identity(n)), res(n);
        for(size_t i = 0; i < n; ++i)
            ext_x[i].insert(end(ext_x[i]), begin(e[i]), end(e[i]));
        ext_x = ext_x.row_canonicalize();
        for(size_t i = 0; i < n; ++i)
        {
            if(std::vector<K>(begin(ext_x[i]), begin(ext_x[i]) + n) != e[i])
                return matrix();
            res[i] = std::vector<K>(begin(ext_x[i]) + n, end(ext_x[i]));
        }
        return res;
    }

    matrix row_canonical_form()
    {
        size_t h = height(), w = width(), rank = 0;
        matrix res = *this;
        for(size_t j = 0; j < w; ++j)
        {
            bool piv = false;
            for(size_t i = rank; i < h; ++i)
            {
                if(res[i][j] != K(0))
                {
                    if(piv)
                    {
                        K r = -res[i][j];
                        for(size_t k = j; k < w; ++k)
                        {
                            res[i][k] += res[rank][k] * r;
                        }
                    }
                    else
                    {
                        swap(res[rank], res[i]);
                        K r = res[rank][j];
                        for(size_t k = j; k < w; ++k)
                        {
                            res[rank][k] /= r;
                        }
                        for(size_t k = 0; k < rank; ++k)
                        {
                            r = -res[k][j];
                            for(size_t l = j; l < w; ++l)
                            {
                                res[k][l] += res[rank][l] * r;
                            }
                        }
                        piv = true;
                    }
                }
            }
            if(piv) ++rank;
        }
        return res;
    }

    K det() const
    {
        matrix<K> x(*this);
        assert(is_square());
        size_t n = height();
        K res(1);
        for(size_t j = 0; j < n; ++j)
        {
            bool piv = false;
            for(size_t i = j; i < n; ++i)
            {
                if(x[i][j] != K(0))
                {
                    if(piv)
                    {
                        const K r = -x[i][j];
                        for(size_t k = j; k < n; ++k)
                        {
                            x[i][k] += x[j][k] * r;
                        }
                    }
                    else
                    {
                        swap(x[i], x[j]);
                        if(i != j) res = -res;
                        const K r = x[j][j];
                        res *= r;
                        for(size_t k = j; k < n; ++k)
                        {
                            x[j][k] /= r;
                        }
                        piv = true;
                    }
                }
            }
            if(not piv)
            {
                return K(0);
            }
        }
        return res;
    }

    friend std::istream &operator>>(std::istream &s, matrix &x)
    {
        size_t h = x.height(), w = x.width();
        for(size_t i = 0; i < h; ++i)
        {
            for(size_t j = 0; j < w; ++j)
            {
                s >> x[i][j];
            }
        }
        return s;
    }

    friend std::ostream &operator<<(std::ostream &s, const matrix &x)
    {
        size_t h = x.height(), w = x.width();
        for(size_t i = 0; i < h; ++i)
        {
            if(i) s << "\n";
            for(size_t j = 0; j < w; ++j)
            {
                s << (j ? " " : "") << x.mat[i][j];
            }
        }
        return s;
    }
};

void __solve()
{
    using mint = math::modint<2>;
    int n;
    cin >> n;
    vector<int> s(n);
    cin >> s;
    sort(all(s));
    matrix<mint> f(18, n + 1);

    int top[19] = {};

    for(int i = 0; i < n; ++i)
    {
        int x = s[i];
        int j = 0;
        while(x)
        {
            f[j++][i] = x & 1;
            x >>= 1;
        }
        top[j]++;
    }

    for(int i = 0; i < 18; ++i)
    {
        top[i + 1] += top[i];
    }

    f = f.row_canonical_form();

    int ans = 0;
    vector<int> p[19];
    for(int i = 0, j = 0, rank = 0; i < 18 and j < n; ++i, ++j)
    {
        while(j < n and f[i][j] == 0)
        {
            j++;
        }
        if(j < n)
        {
            p[rank + 1] = p[rank];
            p[++rank].emplace_back(j);
        }
        if(top[rank] > j) ans = rank;
    }

    std::cout << ans << "\n";

    static int step[1 << 18];
    step[0] = 0;
    for(int i = 0; i < ans; ++i)
    {
        for(int j = 0; j < 1 << i; ++j)
        {
            step[j + (1 << i)] = 1 << i | step[(1 << i) - 1 - j];
        }
    }

    static int g[1 << 18];
    g[0] = 0;
    for(int t = 0; t < 1 << ans; t++)
    {
        if(t)
        {
            g[t] = g[t & (t - 1)] ^ s[p[ans][__ctz32(t)]];
        }
    }
    for(int i = 0; i < 1 << ans; ++i)
    {
        cout << g[step[i]] << " ";
    }

    cout << "\n";
}