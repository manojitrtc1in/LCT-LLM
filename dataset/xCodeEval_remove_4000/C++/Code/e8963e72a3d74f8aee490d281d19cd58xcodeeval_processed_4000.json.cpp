





















using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef string str;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
gene T rint(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
template <class T = int> T inf() { return numeric_limits<T>::max(); }
gene bool tmin(T &a, T b) { return b < a ? a = b, true : false; }
gene bool tmax(T &a, T b) { return b > a ? a = b, true : false; }

gene auto min(const T &a) { return *min_element(rang(a)); }
gene auto max(const T &a) { return *max_element(rang(a)); }
gene auto sum(const T &a) { return accumulate(rang(a), 0); }
template <class T, int N, class I>
auto gath(const T (&a)[N], const vector<I> &b) {
    vector<T> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}
template <class T, class I> auto gath(const T &a, const vector<I> &b) {
    vector<typename T::value_type> r;
    for (auto i : b)
        r.push_back(a[i]);
    return r;
}

template <class T, class C = less<typename T::value_type>>
void sort(T &a, C c = C()) {
    sort(rang(a), c);
}
gene void reve(T &a) { reverse(rang(a)); }
gene void uniq(T &a) { sort(a), a.erase(unique(rang(a)), end(a)); }
gene void shuf(T &a) { shuffle(rang(a), rng); }
gene void merg(T l, T m, T r) { inplace_merge(l, m, r); }

template <typename... T> void in(T &... a) { ((cin >> a), ...); }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a, ((cout << ' ' << b), ...), cout << endl;
}

template <class F, class S> istream &operator>>(istream &s, pair<F, S> &a) {
    return s >> a.first >> a.second;
}
template <class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &a) {
    return s << '(' << a.first << ", " << a.second << ')';
}
gene istream &operator>>(istream &s, vector<T> &a) {
    for (int i = -1; i < 0 && (!a.size() && (cin >> i, a.resize(i), 0), i = 0),
             i < int(a.size());)
        s >> a[i++];
    return s;
}
gene ostream &operator<<(ostream &s, const vector<T> &a) {
    lv(i, a) cout << a[i] << (i + 1 == int(a.size()) ? "" : " ");
    return s;
}
gene using bbst =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
gene using heap = __gnu_pbds::priority_queue<T, greater<T>, pairing_heap_tag>;
namespace integer_factorization_3 {
template <class T> T multiply(const T &x, const T &y, const T &z) {
    return T((long long)x * y % z);
}
template <>
long long multiply<long long>(const long long &x, const long long &y,
                              const long long &z) {
    return (x * y - (long long)(((long double)x * y + 0.5) / z) * z + z) % z;
}
template <class T> T pow(T a, T b, const T &c) {
    T r = 1;
    for (; b; b & 1 ? r = multiply(r, a, c) : 0, b >>= 1, a = multiply(a, a, c))
        ;
    return r;
}
template <class T> bool id4(const T &a) {
    if (a == 2)
        return true;
    if (a % 2 == 0 || a < 2)
        return false;
    static int id12[] = {11000544, 31481107}, id8[] = {2, 7, 61},
               id2[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int c, *pi;
    if (a < 316349281)
        c = 2, pi = id12;
    else if (a < 4759123141ll)
        c = 3, pi = id8;
    else
        c = 7, pi = id2;
    T u = a - 1, t = 0, p = 1;
    for (; u % 2 == 0; u /= 2, ++t)
        ;
    for (int i = 0; i < c; ++i) {
        p = pi[i] % a;
        if (!p)
            return true;
        T x = pow(p, u, a);
        if (x == 1)
            continue;
        for (int j = 0; x != a - 1 && j < t; ++j) {
            x = multiply(x, x, a);
            if (x == 1)
                return false;
        }
        if (x == a - 1)
            continue;
        return false;
    }
    return true;
}
template <class T> T isqrt(const T &x) {
    T ret = T(sqrtl(x));
    while (ret > 0 && ret * ret > x)
        --ret;
    while (x - ret * ret > 2 * ret)
        ++ret;
    return ret;
}
template <class T> T id13(const T &x) {
    T ret = T(cbrt(x));
    while (ret > 0 && ret * ret * ret > x)
        --ret;
    while (x - ret * ret * ret > 3 * ret * (ret + 1))
        ++ret;
    return ret;
}
vector<uint16_t> saved;
uint64_t id1(uint64_t const &x, uint64_t const &k,
                            uint64_t const &it_max, uint32_t id10) {
    if (__gcd((uint64_t)k, x) != 1)
        return __gcd((uint64_t)k, x);
    saved.clear();
    uint64_t scaledn = k * x;
    if (scaledn >> 62)
        return 1;
    uint32_t id5 = isqrt(scaledn);
    uint32_t cutoff = isqrt(2 * id5) / id10;
    uint32_t q0 = 1;
    uint32_t p1 = id5;
    uint32_t q1 = scaledn - p1 * p1;
    if (q1 == 0) {
        uint64_t factor = __gcd(x, (uint64_t)p1);
        return factor == x ? 1 : factor;
    }
    uint32_t multiplier = 2 * k;
    uint32_t id9 = cutoff * multiplier;
    uint32_t i, j;
    uint32_t p0 = 0;
    uint32_t sqrtq = 0;
    for (i = 0; i < it_max; ++i) {
        uint32_t q, bits, tmp;
        tmp = id5 + p1 - q1;
        q = 1;
        if (tmp >= q1)
            q += tmp / q1;
        p0 = q * q1 - p1;
        q0 = q0 + (p1 - p0) * q;
        if (q1 < id9) {
            tmp = q1 / __gcd(q1, multiplier);
            if (tmp < cutoff) {
                saved.push_back((uint16_t)tmp);
            }
        }
        bits = 0;
        tmp = q0;
        while (!(tmp & 1)) {
            bits++;
            tmp >>= 1;
        }
        if (!(bits & 1) && ((tmp & 7) == 1)) {
            sqrtq = (uint32_t)isqrt(q0);
            if (sqrtq * sqrtq == q0) {
                for (j = 0; j < saved.size(); ++j) {
                    if (saved[j] == sqrtq)
                        break;
                }
                if (j == saved.size())
                    break;
            }
        }
        tmp = id5 + p0 - q0;
        q = 1;
        if (tmp >= q0)
            q += tmp / q0;
        p1 = q * q0 - p0;
        q1 = q1 + (p0 - p1) * q;
        if (q0 < id9) {
            tmp = q0 / __gcd(q0, multiplier);
            if (tmp < cutoff)
                saved.push_back((uint16_t)tmp);
        }
    }
    if (sqrtq == 1)
        return 1;
    if (i == it_max)
        return 1;
    q0 = sqrtq;
    p1 = p0 + sqrtq * ((id5 - p0) / sqrtq);
    q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
    for (j = 0; j < it_max; ++j) {
        uint32_t q, tmp;
        tmp = id5 + p1 - q1, q = 1;
        if (tmp >= q1)
            q += tmp / q1;
        p0 = q * q1 - p1, q0 = q0 + (p1 - p0) * q;
        if (p0 == p1) {
            q0 = q1;
            break;
        }
        tmp = id5 + p0 - q0, q = 1;
        if (tmp >= q0)
            q += tmp / q0;
        p1 = q * q0 - p0, q1 = q1 + (p0 - p1) * q;
        if (p0 == p1)
            break;
    }
    uint64_t factor = __gcd((uint64_t)q0, x);
    if (factor == x)
        factor = 1;
    return factor;
}
uint64_t id3(uint64_t const &x) {
    static array<uint32_t, 16> multipliers{
        1,          3,          5,          7,
        11,         3 * 5,      3 * 7,      3 * 11,
        5 * 7,      5 * 11,     7 * 11,     3 * 5 * 7,
        3 * 5 * 11, 3 * 7 * 11, 5 * 7 * 11, 3 * 5 * 7 * 11};
    uint64_t id6 = id13(x);
    if (id6 * id6 * id6 == x)
        return id6;
    for (uint32_t iter_fact = 1; iter_fact < 20000; iter_fact *= 4) {
        for (uint32_t const &k : multipliers) {
            if (numeric_limits<uint64_t>::max() / k <= x)
                continue;
            uint32_t const it_max = iter_fact * 300;
            uint64_t factor = id1(x, k, it_max, 1);
            if (factor == 1 || factor == x)
                continue;
            return factor;
        }
    }
}
template <class T> vector<T> factorize(T x) {
    vector<T> ret;
    auto trial = [&](uint32_t const &i) {
        while (x % i == 0) {
            x /= i;
            ret.push_back(i);
        }
    };
    trial(2), trial(3);
    for (uint32_t i = 5, j = 2; i < 5000 && i * i <= x; i += j, j = 6 - j)
        trial(i);
    if (x > 1) {
        static stack<T> s;
        s.push(x);
        while (!s.empty()) {
            x = s.top(), s.pop();
            if (!id4(x)) {
                T factor = id3(x);
                s.push(factor), s.push(x / factor);
            } else {
                ret.push_back(x);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
template <class T>
vector<pair<T, int>> id0(const T &a) {
    vector<pair<T, int>> r;
    for (auto v : factorize(a)) {
        if (r.empty() || r.back().first != v)
            r.push_back(make_pair(v, 1));
        else
            ++r.back().second;
    }
    return r;
}
} 

namespace modular_arithmetic {
template <class T = long long> struct integer {
    integer() : v(0) {}
    integer(T t) : v(t) { wrap_around(); }
    void wrap_around() {
        if (v < 0)
            v = (v % p + p) % p;
        else if (v >= p)
            v %= p;
    }
    auto operator-() const {
        integer<T> a;
        a.v = (v ? p - v : 0);
        return a;
    }
    auto &operator+=(integer<T> a) { return *this = *this + a; }
    auto &operator-=(integer<T> a) { return *this = *this - a; }
    auto &operator*=(integer<T> a) { return *this = *this * a; }
    auto &operator/=(integer<T> a) { return *this = *this / a; }
    auto &operator<<=(T a) { return *this = *this << a; };
    auto &operator>>=(T a) { return *this = *this >> a; };
    friend auto operator/(integer<T> a, integer<T> b) { return a * inverse(b); }
    friend auto operator+(integer<T> a, integer<T> b) {
        integer<T> c;
        c.v = a.v + b.v;
        if (c.v >= a.p)
            c.v -= a.p;
        return c;
    }
    friend auto operator-(integer<T> a, integer<T> b) {
        integer<T> c;
        c.v = a.v - b.v;
        if (c.v < 0)
            c.v += a.p;
        return c;
    }
    friend auto operator*(integer<T> a, integer<T> b) {
        integer<T> c;
        if (typeid(T) == typeid(long long))
            c.v = T((a.v * b.v -
                     (long long)(((long double)a.v * b.v + 0.5) / a.p) * a.p +
                     a.p) %
                    a.p);
        else if (typeid(T) == typeid(int))
            c.v = T((long long)a.v * b.v % a.p);
        else
            c.v = a.v * b.v % a.p;
        return c;
    }
    friend auto operator^(integer<T> a, T b) { return pow(a, b); }
    friend bool operator==(integer<T> a, integer<T> b) { return a.v == b.v; }
    friend bool operator!=(integer<T> a, integer<T> b) { return a.v != b.v; }
    friend bool operator<(integer<T> a, integer<T> b) { return a.v < b.v; };
    friend bool operator<=(integer<T> a, integer<T> b) { return a.v <= b.v; };
    friend bool operator>(integer<T> a, integer<T> b) { return a.v > b.v; };
    friend bool operator>=(integer<T> a, integer<T> b) { return a.v >= b.v; };
    T v;
    static T p;
    static mt19937 g_32;
    static mt19937_64 g_64;
    static vector<integer<T>> inverse_cache, factorial_cache;
};
template <class T> T integer<T>::p = 1e9 + 7;
template <class T> mt19937 integer<T>::g_32(random_device{}());
template <class T> mt19937_64 integer<T>::g_64(random_device{}());
template <class T> vector<integer<T>> integer<T>::inverse_cache(2, T(1));
template <class T> vector<integer<T>> integer<T>::factorial_cache(1, T(1));
template <class T> auto &operator>>(istream &s, integer<T> &a) {
    s >> a.v;
    a.wrap_around();
    return s;
}
template <class T> auto &operator<<(ostream &s, integer<T> a) {
    return s << a.v;
}
template <class T> auto pow(integer<T> a, T b) {
    integer<T> r(1);
    for (; b; b >>= 1, a = a * a)
        if (b & 1)
            r = r * a;
    return r;
}
template <class T> integer<T> inverse(T a) { return inverse(integer<T>(a)); }
template <class T> integer<T> inverse(integer<T> a) {
    assert(a.v);
    if (a.v < T(integer<T>::inverse_cache.size()))
        return integer<T>::inverse_cache[a.v];
    return pow(a, a.p - 2);
}
template <class T> auto inverse_cached(T a) {
    return inverse_cached(integer<T>(a));
}
template <class T> auto inverse_cached(integer<T> a) {
    assert(a.v);
    auto &t = integer<T>::inverse_cache;
    while (int(t.size()) <= a.v) {
        t.push_back(integer<T>(-integer<T>::p / T(t.size())) *
                    t[integer<T>::p % t.size()]);
    }
    return t[a.v];
}
template <class T> auto operator<<(integer<T> a, T b) {
    return a * pow(integer<T>(2), b);
}
template <class T> auto operator>>(integer<T> a, T b) {
    return a / pow(integer<T>(2), b);
}


template <class T> auto random() {
    if (typeid(T) == typeid(long long))
        return integer<T>::g_64() % integer<T>::p;
    else if (typeid(T) == typeid(int))
        return integer<T>::g_32() % integer<T>::p;
    else
        assert(0);
}


template <class T> auto sqrt(integer<T> a) {
    vector<integer<T>> r;
    if (!a.v)
        r.push_back(decltype(r)(0));
    else if (pow(a, a.p - 1 >> 1).v == 1) {
        int s = a.p - 1, t = 0;
        integer<T> b = 1;
        for (; pow(b, a.p - 1 >> 1).v != a.p - 1; b = integer<T>::random())
            ;
        for (; s % 2 == 0; ++t, s /= 2)
            ;
        integer<T> x = pow(a, (s + 1) / 2), e = pow(a, s);
        for (int i = 1; i < t; ++i, e = x * x / a)
            if (pow(e, 1 << t - i - 1).v != 1)
                x = x * pow(b, (1 << i - 1) * s);
        r.push_back(x);
        r.push_back(-x);
    }
    return r;
}
template <class T> auto factorial(T a) {
    assert(a >= 0);
    auto &t = integer<T>::factorial_cache;
    while (a >= t.size())
        t.push_back(t.back() * t.size());
    return t[a];
}
template <class T> auto id7(T n, T k) {
    assert(n >= 0 && k >= 0);
    if (n < k)
        return integer<T>();
    return factorial(n) / factorial(k) / factorial(n - k);
}
template <class T> integer<T> id11(const vector<T> &y, T x) {
    return id11(y, integer<T>(x));
}
template <class T>
integer<T> id11(const vector<T> &y, integer<T> x) {
    vector<integer<T>> t;
    for (auto v : y)
        t.push_back(integer<T>(v));
    return id11(t, x);
}
template <class T>
integer<T> id11(const vector<integer<T>> &y, T x) {
    return id11(y, integer<T>(x));
}
template <class T>
integer<T> id11(const vector<integer<T>> &y, integer<T> x) {
    vector<integer<T>> f(1, 1), g(y.size(), x), h(y.size(), x);
    for (int i = 1; i < int(y.size()); ++i) {
        f.push_back(f.back() * inverse_cached<T>(i));
        g[i] = h[i] -= i, g[i] *= g[i - 1];
    }
    for (int i = int(y.size()) - 2; i >= 0; --i)
        h[i] *= h[i + 1];
    integer<T> r = 0;
    for (int i = 0; i < int(y.size()); ++i) {
        integer<T> t = f[i] * f[y.size() - 1 - i];
        if (i)
            t *= g[i - 1];
        if (i + 1 != int(y.size()))
            t *= h[i + 1];
        if (int(y.size() - i - 1) % 2)
            t = -t;
        r += t * y[i];
    }
    return r;
}
} 



int main() {
    fast, prec(12);
    using inte = modular_arithmetic::integer<int>;
    inte::p = 998244353;
    vector<ll> a;
    in(a);
    map<ll, int> cnt;
    for (auto v : a)
        for (auto p :
             integer_factorization_3::id0(v)) {
            cnt[p.first] += p.second;
        }
    inte ans = 1;
    for (auto p : cnt)
        ans *= p.second + 1;
    ou(ans);
    return 0;
}