




















using ld = long double;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr unsigned int MOD = 1000000007;
template <typename T>
constexpr T INF = std::numeric_limits<T>::max() / 4;
template <typename F>
constexpr F PI = static_cast<F>(3.1415926535897932385);
std::mt19937 mt{std::random_device{}()};
template <typename T>
bool chmin(T& a, const T& b) { return a = std::min(a, b), a == b; }
template <typename T>
bool chmax(T& a, const T& b) { return a = std::max(a, b), a == b; }
template <typename T>
std::vector<T> Vec(const std::size_t n, T v) { return std::vector<T>(n, v); }
template <class... Args>
auto Vec(const std::size_t n, Args... args) { return std::vector<decltype(Vec(args...))>(n, Vec(args...)); }
template <typename T>
constexpr T popCount(const T u)
{

    return u == 0 ? T(0) : (T)__builtin_popcountll(u);

    unsigned long long v = static_cast<unsigned long long>(u);
    return v = (v & 0x5555555555555555ULL) + (v >> 1 & 0x5555555555555555ULL), v = (v & 0x3333333333333333ULL) + (v >> 2 & 0x3333333333333333ULL), v = (v + (v >> 4)) & 0x0F0F0F0F0F0F0F0FULL, static_cast<T>(v * 0x0101010101010101ULL >> 56 & 0x7f);

}
template <typename T>
constexpr T id2(const T u)
{

    return u == 0 ? T(0) : T(64 - __builtin_clzll(u));

    unsigned long long v = static_cast<unsigned long long>(u);
    return v = static_cast<unsigned long long>(v), v |= (v >> 1), v |= (v >> 2), v |= (v >> 4), v |= (v >> 8), v |= (v >> 16), v |= (v >> 32), popCount(v);

}
template <typename T>
constexpr T clog(const T v) { return v == 0 ? T(0) : id2(v - 1); }
template <typename T>
constexpr T id4(const T v) { return id2(v); }
template <typename T>
constexpr T id0(const T v)
{

    return __builtin_ffsll(v);

    return v == 0 ? T(0) : popCount((v & (-v)) - T(1)) + T(1);

}
template <typename T>
constexpr bool id1(const T v) { return popCount(v) == 1; }
template <typename T>
constexpr T ceil2(const T v) { return v == 0 ? T(1) : T(1) << id2(v - 1); }
template <typename T>
constexpr T floor2(const T v) { return v == 0 ? T(0) : T(1) << (id2(v) - 1); }
















template <typename T>
constexpr std::pair<T, T> id3(const T a, const T b)
{
    if (b == 0) { return std::pair<T, T>{1, 0}; }
    const auto p = id3(b, a % b);
    return {p.second, p.first - p.second * (a / b)};
}
template <typename T>
constexpr T inverse(const T a, const T mod) { return (mod + id3((mod + a % mod) % mod, mod).first % mod) % mod; }
















template <uint mod>
class ModInt
{
private:
    uint v;
    static uint norm(const uint& x) { return x < mod ? x : x - mod; }
    static ModInt make(const uint& x)
    {
        ModInt m;
        return m.v = x, m;
    }
    static ModInt power(ModInt x, ll n)
    {
        ModInt ans = 1;
        for (; n; n >>= 1, x *= x) {
            if (n & 1) { ans *= x; }
        }
        return ans;
    }
    static ModInt inv(const ModInt& x) { return ModInt{inverse((ll)x.v, (ll)mod)}; }

public:
    ModInt() : v{0} {}
    ModInt(const ll val) : v{norm(uint(val % (ll)mod + (ll)mod))} {}
    ModInt(const ModInt<mod>& n) : v{n()} {}
    explicit operator bool() const { return v != 0; }
    ModInt<mod>& operator=(const ModInt<mod>& n) { return v = n(), (*this); }
    ModInt<mod>& operator=(const ll val) { return v = norm(uint(val % (ll)mod + (ll)mod)), (*this); }
    ModInt<mod> operator+() const { return *this; }
    ModInt<mod> operator-() const { return make(norm(mod - v)); }
    ModInt<mod> operator+(const ModInt<mod>& val) const { return make(norm(v + val())); }
    ModInt<mod> operator-(const ModInt<mod>& val) const { return make(norm(v + mod - val())); }
    ModInt<mod> operator*(const ModInt<mod>& val) const { return make((uint)((ll)v * val() % (ll)mod)); }
    ModInt<mod> operator/(const ModInt<mod>& val) const { return *this * inv(val()); }
    ModInt<mod>& operator+=(const ModInt<mod>& val) { return *this = *this + val; }
    ModInt<mod>& operator-=(const ModInt<mod>& val) { return *this = *this - val; }
    ModInt<mod>& operator*=(const ModInt<mod>& val) { return *this = *this * val; }
    ModInt<mod>& operator/=(const ModInt<mod>& val) { return *this = *this / val; }
    ModInt<mod> operator+(const ll val) const { return ModInt{v + val}; }
    ModInt<mod> operator-(const ll val) const { return ModInt{v - val}; }
    ModInt<mod> operator*(const ll val) const { return ModInt{(ll)v * (val % mod)}; }
    ModInt<mod> operator/(const ll val) const { return ModInt{(ll)v * inv(val)}; }
    template <typename I>
    ModInt<mod> operator^(const I n) const { return power(v, n); }
    ModInt<mod>& operator+=(const ll val) { return *this = *this + val; }
    ModInt<mod>& operator-=(const ll val) { return *this = *this - val; }
    ModInt<mod>& operator*=(const ll val) { return *this = *this * val; }
    ModInt<mod>& operator/=(const ll val) { return *this = *this / val; }
    template <typename I>
    ModInt<mod>& operator^=(const I n) { return (*this) = ((*this) ^ n); }
    bool operator==(const ModInt<mod>& val) const { return v == val.v; }
    bool operator!=(const ModInt<mod>& val) const { return not(*this == val); }
    bool operator==(const ll val) const { return v == norm(uint((ll)mod + val % (ll)mod)); }
    bool operator!=(const ll val) const { return not(*this == val); }
    uint operator()() const { return v; }
};
template <uint mod>
inline ModInt<mod> operator+(const ll val, const ModInt<mod>& n) { return n + val; }
template <uint mod>
inline ModInt<mod> operator-(const ll val, const ModInt<mod>& n) { return ModInt<mod>{val - (ll)n()}; }
template <uint mod>
inline ModInt<mod> operator*(const ll val, const ModInt<mod>& n) { return n * val; }
template <uint mod>
inline ModInt<mod> operator/(const ll val, const ModInt<mod>& n) { return ModInt<mod>(val) / n; }
template <uint mod>
inline bool operator==(const ll val, const ModInt<mod>& n) { return n == val; }
template <uint mod>
inline bool operator!=(const ll val, const ModInt<mod>& n) { return not(val == n); }
template <uint mod>
inline std::istream& operator>>(std::istream& is, ModInt<mod>& n)
{
    uint v;
    return is >> v, n = v, is;
}
template <uint mod>
std::ostream& operator<<(std::ostream& os, const ModInt<mod>& n) { return (os << n()); }
















class UnionFind
{
public:
    UnionFind(const std::size_t v) : V(v), parent(v), size(v, 1) { std::iota(parent.begin(), parent.end(), 0); }
    std::size_t find(const std::size_t a) { return assert(a < V), parent[a] == a ? a : parent[a] = find(parent[a]); }
    bool same(const std::size_t a, const std::size_t b)
    {
        assert(a < V), assert(b < V);
        return find(a) == find(b);
    }
    void unite(std::size_t a, std::size_t b)
    {
        assert(a < V), assert(b < V);
        a = find(a), b = find(b);
        if (a == b) { return; }
        if (size[a] < size[b]) { std::swap(a, b); }
        size[a] += size[b], parent[b] = a;
    }
    std::size_t getSize(const std::size_t a) { return assert(a < V), size[find(a)]; }
    friend std::ostream& operator<<(std::ostream& os, const UnionFind& uf)
    {
        os << "[";
        for (std::size_t i = 0; i < uf.parent.size(); i++) { os << uf.parent[i] << (i + 1 == uf.parent.size() ? "" : ","); }
        return (os << "]\n");
    }

private:
    const std::size_t V;
    std::vector<std::size_t> parent, size;
};
















int main()
{
    constexpr uint MOD = 998244353;
    using mint = ModInt<MOD>;
    std::string S;
    std::cin >> S;
    std::reverse(S.begin(), S.end());
    const int M = S.size();
    std::vector<int> A(M);
    for (int i = 0; i < M; i++) { A[i] = (i * 2 >= M ? M - i - 1 : i); }
    const int AN = (M + 1) / 2;
    mint ans = 0;
    for (int l = 1; l < M; l++) {
        std::vector<int> B(M, -1);
        for (int i = 0; i < l; i++) { B[i] = (i * 2 >= l ? l - i - 1 : i); }
        const int BN = (l + 1) / 2;
        UnionFind uf(AN * 2 + BN * 2 + 2);
        uf.unite(2 * AN, 2 * AN + 2 * BN + 1), uf.unite(2 * AN + 1, 2 * AN + 2 * BN);
        for (int i = 0; i < M; i++) {
            if (S[i] == '?') { continue; }
            const int a = A[i], b = B[i];
            const int v = S[i] == '1';
            if (b == -1) {
                uf.unite(a * 2, 2 * AN + 2 * BN + v);
                uf.unite(a * 2 + 1, 2 * AN + 2 * BN + (v ^ 1));
            } else {
                uf.unite(a * 2, 2 * AN + 2 * b + v);
                uf.unite(a * 2 + 1, 2 * AN + 2 * b + (v ^ 1));
            }
        }
        bool ng = false;
        for (int i = 0; i < AN + BN; i++) {
            if (uf.same(2 * i, 2 * i + 1)) {
                ng = true;
                break;
            }
        }
        if (ng) { continue; }
        std::set<int> root;
        for (int i = 0; i < 2 * AN + 2 * BN + 2; i++) { root.insert(uf.find(i)); }
        const int sz = root.size() / 2 - 1;
        ans += (mint)2 ^ (sz);
    }
    std::cout << ans << std::endl;
    return 0;
}
