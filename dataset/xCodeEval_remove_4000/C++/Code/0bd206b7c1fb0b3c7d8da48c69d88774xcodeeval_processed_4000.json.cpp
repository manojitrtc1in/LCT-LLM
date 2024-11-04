







































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
    void id8()
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


            atexit(id8);
            start_time = std::chrono::system_clock::now();

        }
    } id9;
} 


class id4
{
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    std::string built_func, last_func;
    bool id7;

  public:
    explicit id4() : id7(false)
    {}
    void build(int crt_ln, const std::string &crt_func)
    {
        id7 = true;
        last_pt = built_pt = std::chrono::system_clock::now();
        last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(id7)
        {
            last_pt = std::chrono::system_clock::now();
            last_ln = crt_ln, last_func = crt_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] "
                         << "id4::set failed (yet to be built!)\n";
        }
    }
    void get(int crt_ln, const std::string &crt_func)
    {
        if(id7)
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
                         << "id4::get failed (yet to be built!)\n";
        }
    }
};

id4 id0;









namespace std
{
    template <class RAitr>
    void rsort(RAitr __first, RAitr __last)
    {
        sort(__first, __last, greater<>());
    }
    template <class T>
    size_t id6(size_t seed, T const &key)
    {
        return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
    }
    template <class T, class U>
    struct hash<pair<T, U>>
    {
        size_t operator()(pair<T, U> const &pr) const
        {
            return id6(id6(0, pr.first), pr.second);
        }
    };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc
    {
        static size_t apply(size_t seed, tuple_t const &t)
        {
            return id6(
                tuple_hash_calc<tuple_t, index - 1>::apply(seed, t),
                get<index>(t));
        }
    };
    template <class tuple_t>
    struct tuple_hash_calc<tuple_t, 0>
    {
        static size_t apply(size_t seed, tuple_t const &t)
        {
            return id6(seed, get<0>(t));
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



template <class T>
void write(const T &x)
{
    std::cout << x << '\n';
}
template <class T, class... rest_t>
void write(const T &x, rest_t... rest)
{
    std::cout << x << ' ';
    write(rest...);
}
void writeln()
{}
template <class T, class... rest_t>
void writeln(const T &x, rest_t... rest)
{
    std::cout << x << '\n';
    writeln(rest...);
}

template <class P>
void read_range(P __first, P __second)
{
    for(P i = __first; i != __second; ++i)
        std::cin >> *i;
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
template <class A, size_t N, class T>
void init(A (&array)[N], const T &val)
{
    std::fill((T *)array, (T *)(array + N), val);
}
template <class A, size_t N>
void init(A (&array)[N])
{
    memset(array, 0, sizeof(array));
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

namespace math
{
    template <class int_t>
    constexpr int_t gcd(int_t x, int_t y)
    {
        x = x > 0 ? x : -x, y = y > 0 ? y : -y;
        while(y)
            y ^= x ^= y ^= x %= y;
        return x;
    }
    template <class int_t>
    constexpr int_t lcm(int_t x, int_t y)
    {
        return x ? x / gcd(x, y) * y : 0;
    }
    

    template <class int_t>
    constexpr std::tuple<int_t, int_t, int_t> id1(int_t a, int_t b)
    {
        int_t id3 = a >= 0 ? 1 : (a = -a, 0),
              id5 = b >= 0 ? 1 : (b = -b, 0);
        int_t p = 1, q = 0, r = 0, s = 1;
        while(b)
        {
            int_t t = a / b;
            r ^= p ^= r ^= p -= t * r;
            s ^= q ^= s ^= q -= t * s;
            b ^= a ^= b ^= a %= b;
        }
        return std::tuple<int_t, int_t, int_t>(a, id3 ? p : -p,
                                               id5 ? q : -q);
    }
    

    template <class int_t>
    constexpr std::pair<int_t, int_t> mod_comp(int_t k, int_t m, int_t l,
                                               int_t n)
    {
        assert(m > 0 and n > 0);
        int_t g, x, y;
        std::tie(g, x, y) = id1(m, n);
        k += ((k %= m) < 0) * m, l += ((l %= n) < 0) * n;
        int_t s = k / g, t = l / g, r = k % g;
        if(r != l % g) return std::pair<int_t, int_t>(-1, -1);
        int_t lcm = m / g * n;
        return std::pair<int_t, int_t>(
            (m * x % lcm * t % lcm + n * y % lcm * s % lcm + r + lcm * 2) % lcm,
            lcm);
    }
} 




using namespace std;
using namespace math;

signed main()
{
    void __solve();
    void id2();

    unsigned int t = 1;
    cin >> t;
    id2();

    while(t--)
    {
        __solve();
    }
}

void id2()
{}

void fail()
{
    std::cout << "-1" << '\n';
}

int p[1 << 19], nx[1 << 19];
vector<int> pos[1 << 19];
int itr[1 << 19];
int l[1 << 19], r[1 << 19], x[1 << 19], y[1 << 19];
int stk[1 << 19];

void __solve()
{
    int n;
    cin >> n;
    read_range(nx, nx + n);
    for(int i = 1; i <= n; ++i)
    {
        pos[i].clear();
    }
    stk[0] = n;
    for(int i = n - 1, t = 1; i >= 0; i--)
    {
        if(~nx[i])
        {
            nx[i]--;
            while(stk[t - 1] < nx[i])
            {
                t--;
            }
            if(stk[t - 1] != nx[i])
            {
                fail();
                return;
            }
        }
        else
        {
            nx[i] = i + 1;
        }
        stk[t++] = i;
        pos[nx[i]].emplace_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        itr[i] = 0;
        reverse(all(pos[i]));
    }
    int t = 1;
    l[0] = x[0] = 0, r[0] = y[0] = n;
    while(t--)
    {
        int _l = l[t], _r = r[t], _x = x[t], _y = y[t];
        if(_l == _r) continue;
        int k = pos[_r][itr[_r]++];
        p[k] = _y;
        l[t] = _l, r[t] = k, x[t] = _x, y[t] = _x + k - _l;
        ++t;
        r[t] = _r, l[t] = k + 1, y[t] = _y - 1, x[t] = y[t - 1];
        ++t;
    }
    for(int i = 0; i < n; i++)
    {
        if(i)
        {
            std::cout << " ";
        }
        std::cout << p[i];
    }
    std::cout << "\n";
}