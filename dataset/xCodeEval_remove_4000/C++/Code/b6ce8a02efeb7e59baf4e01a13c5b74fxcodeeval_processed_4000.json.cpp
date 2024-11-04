

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using f64 = double;
using f80 = long double;
using f128 = __float128;
constexpr i32 operator"" _i32(u64 v)
{
    return v;
}
constexpr i32 operator"" _u32(u64 v)
{
    return v;
}
constexpr i64 operator"" _i64(u64 v)
{
    return v;
}
constexpr u64 operator"" _u64(u64 v)
{
    return v;
}
constexpr f64 operator"" _f64(f80 v)
{
    return v;
}
constexpr f80 operator"" _f80(f80 v)
{
    return v;
}
using Istream = std::istream;
using Ostream = std::ostream;
using Str = std::string;
template<typename T>
using Lt = std::less<T>;
template<typename T>
using Gt = std::greater<T>;
template<typename T>
using IList = std::initializer_list<T>;
template<int n>
using BSet = std::bitset<n>;
template<typename T1, typename T2>
using Pair = std::pair<T1, T2>;
template<typename... Ts>
using Tup = std::tuple<Ts...>;
template<typename T, int N>
using Arr = std::array<T, N>;
template<typename... Ts>
using Deq = std::deque<Ts...>;
template<typename... Ts>
using Set = std::set<Ts...>;
template<typename... Ts>
using MSet = std::multiset<Ts...>;
template<typename... Ts>
using USet = std::unordered_set<Ts...>;
template<typename... Ts>
using UMSet = std::unordered_multiset<Ts...>;
template<typename... Ts>
using Map = std::map<Ts...>;
template<typename... Ts>
using MMap = std::multimap<Ts...>;
template<typename... Ts>
using UMap = std::unordered_map<Ts...>;
template<typename... Ts>
using UMMap = std::unordered_multimap<Ts...>;
template<typename... Ts>
using Vec = std::vector<Ts...>;
template<typename... Ts>
using Stack = std::stack<Ts...>;
template<typename... Ts>
using Queue = std::queue<Ts...>;
template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, Vec<T>, Gt<T>>;
using NSec = std::chrono::nanoseconds;
using USec = std::chrono::microseconds;
using MSec = std::chrono::milliseconds;
using Sec = std::chrono::seconds;
template<typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
template<typename T>
constexpr T PI = T{3.141592653589793238462643383279502884};
template<typename T = u64>
constexpr T TEN(const int n)
{
    return n == 0 ? T{1} : TEN<T>(n - 1) * T{10};
}
Ostream& operator<<(Ostream& os, i128 v)
{
    bool minus = false;
    if (v < 0) { minus = true, v = -v; }
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) {
        ans.push_back('0' + v % 10), v /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return os << (minus ? "-" : "") << ans;
}
Ostream& operator<<(Ostream& os, u128 v)
{
    Str ans;
    if (v == 0) { ans = "0"; }
    while (v) {
        ans.push_back('0' + v % 10), v /= 10;
    }
    std::reverse(ans.begin(), ans.end());
    return os << ans;
}
template<typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template<typename T>
constexpr T fdiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? x / y : (x - y + 1) / y;
}
template<typename T>
constexpr T cdiv(T x, T y)
{
    if (y < T{}) { x = -x, y = -y; }
    return x >= T{} ? (x + y - 1) / y : x / y;
}
template<typename T, typename I>
constexpr T modPower(T v, I n, T mod)
{
    T ans = 1 % mod;
    for (; n > 0; n >>= 1, (v *= v) %= mod) {
        if (n % 2 == 1) { (ans *= v) %= mod; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n)
{
    T ans = 1;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T, typename I>
constexpr T power(T v, I n, const T& e)
{
    T ans = e;
    for (; n > 0; n >>= 1, v *= v) {
        if (n % 2 == 1) { ans *= v; }
    }
    return ans;
}
template<typename T>
Vec<T> operator+=(Vec<T>& vs1, const Vec<T>& vs2)
{
    vs1.insert(vs1.end(), vs2.begin(), vs2.end());
    return vs1;
}
template<typename T>
Vec<T> operator+(const Vec<T>& vs1, const Vec<T>& vs2)
{
    auto vs = vs1;
    vs += vs2;
    return vs;
}
template<typename T>
void fillAll(Vec<T>& vs, const T& v)
{
    std::fill(vs.begin(), vs.end(), v);
}
template<typename T, typename C = Lt<T>>
void sortAll(Vec<T>& vs, C comp = C{})
{
    std::sort(vs.begin(), vs.end(), comp);
}
template<typename T>
void reverseAll(Vec<T>& vs)
{
    std::reverse(vs.begin(), vs.end());
}
template<typename T>
void uniqueAll(Vec<T>& vs)
{
    sortAll(vs);
    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
}
template<typename T, typename V = T>
V sumAll(const Vec<T>& vs)
{
    return std::accumulate(vs.begin(), vs.end(), V{});
}
template<typename T>
int minInd(const Vec<T>& vs)
{
    return std::min_element(vs.begin(), vs.end()) - vs.begin();
}
template<typename T>
int maxInd(const Vec<T>& vs)
{
    return std::max_element(vs.begin(), vs.end()) - vs.begin();
}
template<typename T>
int lbInd(const Vec<T>& vs, const T& v)
{
    return std::lower_bound(vs.begin(), vs.end(), v) - vs.begin();
}
template<typename T>
int ubInd(const Vec<T>& vs, const T& v)
{
    return std::upper_bound(vs.begin(), vs.end(), v) - vs.begin();
}
template<typename T, typename F>
Vec<T> genVec(int n, F gen)
{
    Vec<T> ans;
    std::generate_n(std::back_insert_iterator(ans), n, gen);
    return ans;
}
Vec<int> id5(int n, int offset = 0)
{
    Vec<int> ans(n);
    std::iota(ans.begin(), ans.end(), offset);
    return ans;
}
template<typename T>
Vec<T> revVec(const Vec<T>& vs)
{
    auto ans = vs;
    reverseAll(ans);
    return ans;
}
constexpr int popcount(const u64 v)
{
    return v ? __builtin_popcountll(v) : 0;
}
constexpr int id0(const u64 v)
{
    return v ? 64 - __builtin_clzll(v) : 0;
}
constexpr int id7(const u64 v)
{
    return __builtin_ffsll(v);
}
constexpr int clog(const u64 v)
{
    return v ? id0(v - 1) : 0;
}
constexpr u64 ceil2(const u64 v)
{
    const int l = clog(v);
    return (l == 64) ? 0_u64 : (1_u64 << l);
}
constexpr u64 floor2(const u64 v)
{
    return v ? (1_u64 << (id0(v) - 1)) : 0_u64;
}
constexpr bool id6(const u64 v)
{
    return (v > 0) and ((v & (v - 1)) == 0);
}
constexpr bool btest(const u64 mask, const int ind)
{
    return (mask >> ind) & 1_u64;
}
template<typename F>
struct Fix : F
{
    Fix(F&& f) : F{std::forward<F>(f)} {}
    template<typename... Args>
    auto operator()(Args&&... args) const
    {
        return F::operator()(*this, std::forward<Args>(args)...);
    }
};
class irange
{
private:
    struct itr
    {
        itr(int start = 0, int step = 1) : m_cnt{start}, m_step{step} {}
        bool operator!=(const itr& it) const
        {
            return m_cnt != it.m_cnt;
        }
        int operator*()
        {
            return m_cnt;
        }
        itr& operator++()
        {
            m_cnt += m_step;
            return *this;
        }
        int m_cnt, m_step;
    };
    int m_start, m_end, m_step;
public:
    irange(int start, int end, int step = 1)
    {
        assert(step != 0);
        const int d = std::abs(step);
        const int l = (step > 0 ? start : end);
        const int r = (step > 0 ? end : start);
        int n = (r - l) / d + ((r - l) % d ? 1 : 0);
        if (l >= r) { n = 0; }
        m_start = start;
        m_end = start + step * n;
        m_step = step;
    }
    itr begin() const
    {
        return itr{m_start, m_step};
    }
    itr end() const
    {
        return itr{m_end, m_step};
    }
};
irange rep(int end)
{
    return irange(0, end, 1);
}
irange per(int rend)
{
    return irange(rend - 1, -1, -1);
}

namespace xoshiro_impl {
u64 x;
u64 next()
{
    uint64_t z = (x += 0x9e3779b97f4a7c15);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
    return z ^ (z >> 31);
}
}
class id3
{
public:
    using result_type = u32;
    using T = result_type;
    id3(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return std::numeric_limits<T>::min();
    }
    static constexpr T max()
    {
        return std::numeric_limits<T>::max();
    }
    T operator()()
    {
        return next();
    }
private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (32 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 9;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 11);
        return ans;
    }
    T s[4];
};
class id1
{
public:
    using result_type = u64;
    using T = result_type;
    id1(T seed = 0)
    {
        xoshiro_impl::x = seed;
        s[0] = xoshiro_impl::next();
        s[1] = xoshiro_impl::next();
        s[2] = xoshiro_impl::next();
        s[3] = xoshiro_impl::next();
    }
    static constexpr T min()
    {
        return std::numeric_limits<T>::min();
    }
    static constexpr T max()
    {
        return std::numeric_limits<T>::max();
    }
    T operator()()
    {
        return next();
    }
private:
    static constexpr T rotl(const T x, int k)
    {
        return (x << k) | (x >> (64 - k));
    }
    T next()
    {
        const T ans = rotl(s[1] * 5, 7) * 9;
        const T t = s[1] << 17;
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
        s[2] ^= t;
        s[3] = rotl(s[3], 45);
        return ans;
    }
    T s[4];
};
template<typename Rng>
class RNG
{
public:
    using result_type = typename Rng::result_type;
    using T = result_type;
    static constexpr T min()
    {
        return Rng::min();
    }
    static constexpr T max()
    {
        return Rng::max();
    }
    RNG() : RNG(std::random_device{}()) {}
    RNG(T seed) : m_rng(seed) {}
    T operator()()
    {
        return m_rng();
    }
    template<typename T>
    T val(T min, T max)
    {
        return std::uniform_int_distribution<T>(min, max)(m_rng);
    }
    template<typename T>
    Pair<T, T> pair(T min, T max)
    {
        return std::minmax({val<T>(min, max), val<T>(min, max)});
    }
    template<typename T>
    Vec<T> vec(int n, T min, T max)
    {
        return genVec<T>(n, [&]() { return val<T>(min, max); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, T min, T max)
    {
        return genVec<Vec<T>>(n, [&]() { return vec(m, min, max); });
    }
private:
    Rng m_rng;
};
RNG<std::mt19937> rng;
RNG<std::mt19937_64> rng64;
RNG<id3> id2;
RNG<id1> id4;
class Scanner
{
public:
    Scanner(Istream& is = std::cin) : m_is{is}
    {
        m_is.tie(nullptr)->sync_with_stdio(false);
    }
    template<typename T>
    T val()
    {
        T v;
        return m_is >> v, v;
    }
    template<typename T>
    T val(T offset)
    {
        return val<T>() - offset;
    }
    template<typename T>
    Vec<T> vec(int n)
    {
        return genVec<T>(n, [&]() { return val<T>(); });
    }
    template<typename T>
    Vec<T> vec(int n, T offset)
    {
        return genVec<T>(n, [&]() { return val<T>(offset); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m); });
    }
    template<typename T>
    Vec<Vec<T>> vvec(int n, int m, const T offset)
    {
        return genVec<Vec<T>>(n, [&]() { return vec<T>(m, offset); });
    }
    template<typename... Args>
    auto tup()
    {
        return Tup<Args...>{val<Args>()...};
    }
    template<typename... Args>
    auto tup(const Args&... offsets)
    {
        return Tup<Args...>{val<Args>(offsets)...};
    }
private:
    Istream& m_is;
};
Scanner in;
class Printer
{
public:
    Printer(Ostream& os = std::cout) : m_os{os}
    {
        m_os << std::fixed << std::setprecision(15);
    }
    template<typename... Args>
    int operator()(const Args&... args)
    {
        dump(args...);
        return 0;
    }
    template<typename... Args>
    int ln(const Args&... args)
    {
        dump(args...), m_os << '\n';
        return 0;
    }
    template<typename... Args>
    int el(const Args&... args)
    {
        dump(args...), m_os << std::endl;
        return 0;
    }
private:
    template<typename T>
    void dump(const T& v)
    {
        m_os << v;
    }
    template<typename T>
    void dump(const Vec<T>& vs)
    {
        for (const int i : rep(vs.size())) {
            m_os << (i ? " " : ""), dump(vs[i]);
        }
    }
    template<typename T>
    void dump(const Vec<Vec<T>>& vss)
    {
        for (const int i : rep(vss.size())) {
            m_os << (i ? "" : "\n"), dump(vss[i]);
        }
    }
    template<typename T, typename... Ts>
    int dump(const T& v, const Ts&... args)
    {
        dump(v), m_os << ' ', dump(args...);
        return 0;
    }
    Ostream& m_os;
};
Printer out;
template<typename T, int n, int i = 0>
auto ndVec(int const (&szs)[n], const T x = T{})
{
    if constexpr (i == n) {
        return x;
    } else {
        return std::vector(szs[i], ndVec<T, n, i + 1>(szs, x));
    }
}
template<typename T, typename F>
T binSearch(T ng, T ok, F check)
{
    while (std::abs(ok - ng) > 1) {
        const T mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    return ok;
}

int main()
{
    const auto T = in.val<int>();
    for (int t : rep(T)) {
        static_cast<void>(t);
        const auto N = in.val<int>();
        auto as = in.vec<i64>(N);
        sortAll(as);
        if (as.back() <= 0) {
            out.ln(N);
            continue;
        }
        int ans = 0;
        i64 mind = INF<i64>;
        int i = 0;
        for (; i < N; i++) {
            if (as[i] > 0) { break; }
            ans++;
            if (as[i + 1] <= 0) { chmin(mind, as[i + 1] - as[i]); }
        }
        if (as[i] <= mind) { ans++; }
        out.ln(ans);
    }
    return 0;
}

  				  	   		 	 			 								 	