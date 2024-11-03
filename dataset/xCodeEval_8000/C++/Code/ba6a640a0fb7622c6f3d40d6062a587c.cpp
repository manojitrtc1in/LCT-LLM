

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>







using namespace std;

using ll = long long;
using db = long double; 

using str = string;        




using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define fi first
#define se second

#define tcT template <class T
#define tcTU tcT, class U


tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vvi = V<vi>;
using vb = V<bool>;
using vll = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpii = V<pii>;
using vpll = V<pll>;
using vpd = V<pd>;
 
tcT > using pair2 = pair<T, T>;





#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }



#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = 998244353;
const int MX = 2e5 + 5;
const ll BIG = 1e18; 

const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1}; 

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;





constexpr int pct(int x) { return __builtin_popcount(x); } 

constexpr int bits(int x) { 

                            

    return x == 0 ? 0 : 31 - __builtin_clz(x);
} 

constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
} 

ll fdiv(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
} 


tcT > bool ckmin(T &a, const T &b) {
    return b < a ? a = b, 1 : 0;
} 

tcT > bool ckmax(T &a, const T &b) {
    return a < b ? a = b, 1 : 0;
} 


tcTU > T fstTrue(T lo, T hi, U f) {
    ++hi;
    assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
    --lo;
    assert(lo <= hi); 

    while (lo < hi) { 

        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}
tcT > void remDup(vector<T> &v) { 

    sort(all(v));
    v.erase(unique(all(v)), end(v));
}
tcTU > void erase(T &t, const U &u) { 

    auto it = t.find(u);
    assert(it != end(t));
    t.erase(it);
} 


#define tcTUU tcT, class... U

inline namespace Helpers {






tcT, class = void > struct is_iterable : false_type {};
tcT > struct is_iterable<
          T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
    : true_type {};
tcT > constexpr bool is_iterable_v = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT > struct is_readable<T, typename std::enable_if_t<is_same_v<
                                decltype(cin >> declval<T &>()), istream &>>>
    : true_type {};
tcT > constexpr bool is_readable_v = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<T, typename std::enable_if_t<is_same_v<
                                 decltype(cout << declval<T>()), ostream &>>>
    : true_type {};
tcT > constexpr bool is_printable_v = is_printable<T>::value;
} 


inline namespace Input {
tcT > constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
tcTUU > void re(T &t, U &...u);
tcTU > void re(pair<T, U> &p); 




tcT > typename enable_if<is_readable_v<T>, void>::type re(T &x) {
    cin >> x;
} 

tcT > void re(complex<T> &c) {
    T a, b;
    re(a, b);
    c = {a, b};
} 

tcT > typename enable_if<needs_input_v<T>, void>::type
      re(T &i); 

tcTU > void re(pair<T, U> &p) { re(p.fi, p.se); }
tcT > typename enable_if<needs_input_v<T>, void>::type re(T &i) {
    each(x, i) re(x);
}
tcTUU > void re(T &t, U &...u) {
    re(t);
    re(u...);
} 




void rv(size_t) {}
tcTUU > void rv(size_t N, V<T> &t, U &...u);
template <class... U> void rv(size_t, size_t N2, U &...u);
tcTUU > void rv(size_t N, V<T> &t, U &...u) {
    t.rsz(N);
    re(t);
    rv(N, u...);
}
template <class... U> void rv(size_t, size_t N2, U &...u) { rv(N2, u...); }



void decrement() {} 

tcTUU > void decrement(T &t, U &...u) {
    --t;
    decrement(u...);
}
#define ints(...)                                                              \
    int __VA_ARGS__;                                                           \
    re(__VA_ARGS__);
#define int1(...)                                                              \
    ints(__VA_ARGS__);                                                         \
    decrement(__VA_ARGS__);
} 


inline namespace ToString {
tcT > constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;



tcT > typename enable_if<is_printable_v<T>, str>::type ts(T v) {
    stringstream ss;
    ss << fixed << setprecision(30) << v;
    return ss.str();
} 

tcT > str bit_vec(T t) { 

    str res = "{";
    F0R(i, sz(t)) res += ts(t[i]);
    res += "}";
    return res;
}
str ts(V<bool> v) { return bit_vec(v); }
template <size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } 

tcTU > str ts(pair<T, U> p);                                     

tcT >
    typename enable_if<needs_output_v<T>, str>::type ts(T v); 

tcTU > str ts(pair<T, U> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
tcT > typename enable_if<is_iterable_v<T>, str>::type ts_sep(T v, str sep) {
    

    bool fst = 1;
    str res = "";
    for (const auto &x : v) {
        if (!fst)
            res += sep;
        fst = 0;
        res += ts(x);
    }
    return res;
}
tcT > typename enable_if<needs_output_v<T>, str>::type ts(T v) {
    return "{" + ts_sep(v, ", ") + "}";
}



template <int, class T>
typename enable_if<!needs_output_v<T>, vs>::type ts_lev(const T &v) {
    return {ts(v)};
}
template <int lev, class T>
typename enable_if<needs_output_v<T>, vs>::type ts_lev(const T &v) {
    if (lev == 0 || !sz(v))
        return {ts(v)};
    vs res;
    for (const auto &t : v) {
        if (sz(res))
            res.bk += ",";
        vs tmp = ts_lev<lev - 1>(t);
        res.ins(end(res), all(tmp));
    }
    F0R(i, sz(res)) {
        str bef = " ";
        if (i == 0)
            bef = "{";
        res[i] = bef + res[i];
    }
    res.bk += "}";
    return res;
}
} 


inline namespace Output {
template <class T> void pr_sep(ostream &os, str, const T &t) { os << ts(t); }
template <class T, class... U>
void pr_sep(ostream &os, str sep, const T &t, const U &...u) {
    pr_sep(os, sep, t);
    os << sep;
    pr_sep(os, sep, u...);
}


template <class... T> void pr(const T &...t) { pr_sep(cout, "", t...); }


void ps() { cout << "\n"; }
template <class... T> void ps(const T &...t) {
    pr_sep(cout, " ", t...);
    ps();
}


template <class... T> void dbg_out(const T &...t) {
    pr_sep(cerr, " | ", t...);
    cerr << endl;
}
void loc_info(int line, str names) {
    cerr << "Line(" << line << ") -> [" << names << "]: ";
}
template <int lev, class T> void dbgl_out(const T &t) {
    cerr << "\n\n" << ts_sep(ts_lev<lev>(t), "\n") << "\n" << endl;
}
#ifdef LOCAL
#define dbg(...) loc_info(__LINE__, #__VA_ARGS__), dbg_out(__VA_ARGS__)
#define dbgl(lev, x) loc_info(__LINE__, #x), dbgl_out<lev>(x)
#else 

#define dbg(...) 0
#define dbgl(lev, x) 0
#endif

const clock_t beg = clock();
#define dbg_time() dbg((db)(clock() - beg) / CLOCKS_PER_SEC)
} 


inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
    cin.tie(0)->sync_with_stdio(0); 

    

    

    

    if (sz(s))
        setIn(s + ".in"), setOut(s + ".out"); 

}
} 


template <typename T> T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T> class Modular {
  public:
    using Type = typename decay<decltype(T::value)>::type;

    constexpr Modular() : value() {}
    template <typename U> Modular(const U &x) { value = normalize(x); }

    template <typename U> static Type normalize(const U &x) {
        Type v;
        if (-mod() <= x && x < mod())
            v = static_cast<Type>(x);
        else
            v = static_cast<Type>(x % mod());
        if (v < 0)
            v += mod();
        return v;
    }

    const Type &operator()() const { return value; }
    template <typename U> explicit operator U() const {
        return static_cast<U>(value);
    }
    constexpr static Type mod() { return T::value; }

    Modular &operator+=(const Modular &other) {
        if ((value += other.value) >= mod())
            value -= mod();
        return *this;
    }
    Modular &operator-=(const Modular &other) {
        if ((value -= other.value) < 0)
            value += mod();
        return *this;
    }
    template <typename U> Modular &operator+=(const U &other) {
        return *this += Modular(other);
    }
    template <typename U> Modular &operator-=(const U &other) {
        return *this -= Modular(other);
    }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    Modular operator++(int) {
        Modular result(*this);
        *this += 1;
        return result;
    }
    Modular operator--(int) {
        Modular result(*this);
        *this -= 1;
        return result;
    }
    Modular operator-() const { return Modular(-value); }

    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                       Modular>::type &
    operator*=(const Modular &rhs) {
#ifdef _WIN32
        uint64_t x =
            static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
        uint32_t xh = static_cast<uint32_t>(x >> 32),
                 xl = static_cast<uint32_t>(x), d, m;
        asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
        value = m;
#else
        value = normalize(static_cast<int64_t>(value) *
                          static_cast<int64_t>(rhs.value));
#endif
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, long long>::value,
                       Modular>::type &
    operator*=(const Modular &rhs) {
        long long q = static_cast<long long>(static_cast<long double>(value) *
                                             rhs.value / mod());
        value = normalize(value * rhs.value - q * mod());
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                       Modular>::type &
    operator*=(const Modular &rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }

    Modular &operator/=(const Modular &other) {
        return *this *= Modular(inverse(other.value, mod()));
    }

    friend const Type &abs(const Modular &x) { return x.value; }

    template <typename U>
    friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename U>
    friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

    template <typename V, typename U>
    friend V &operator>>(V &stream, Modular<U> &number);

  private:
    Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) {
    return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) {
    return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) {
    return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) {
    return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1)
            res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T> bool IsZero(const Modular<T> &number) {
    return number() == 0;
}

template <typename T> string to_string(const Modular<T> &number) {
    return to_string(number());
}



template <typename U, typename T>
U &operator<<(U &stream, const Modular<T> &number) {
    return stream << number();
}



template <typename U, typename T> U &operator>>(U &stream, Modular<T> &number) {
    typename common_type<typename Modular<T>::Type, long long>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}



constexpr int md = (int)998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;




ll myRand(ll B) { return (unsigned long long)rng() % B; }

class segtree {
  public:
    struct node {
        

        

        ll a = 0;
        ll mn = 4e5;
        ll mx = -1;
        bool isset = false;
        int setted = -1;
        void apply(int l, int r, ll val) {
            this->a += val * (r - l + 1);
            mx = val;
            mn = val;
            if(l != r){
                isset = true;
                setted = val;
            }
        }
    };
    node unite(const node &a, const node &b) const {
        node res;
        
        res.a = a.a + b.a;
        
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);

        return res;
    }
    inline void push(int x, int l, int r) {
        if(tree[x].isset){
            
            
            int y = (l + r) >> 1;
            int z = x + ((y - l + 1) << 1);
            
            tree[x + 1].setted = tree[x].setted;
            tree[x + 1].mn = tree[x].setted;
            tree[x + 1].mx = tree[x].setted;
            tree[x + 1].isset = true;
            
            tree[z].setted = tree[x].setted;
            tree[z].mn = tree[x].setted;
            tree[z].mx = tree[x].setted;
            tree[z].isset = true;
        }
        tree[x].isset = false;
    }
    inline void pull(int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }
    template <typename M> void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }
    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y) {
            res = get(x + 1, l, y, ll, rr);
        } else {
            if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }
    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M &...v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v...);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v...);
        }
        pull(x, z);
    }
    int find_first_knowingly(int x, int l, int r,
                             const function<bool(const node &)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }
    int find_first(int x, int l, int r, int ll, int rr,
                   const function<bool(const node &)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y) {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1) {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    int find_last_knowingly(int x, int l, int r,
                            const function<bool(const node &)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        } else {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }
    int find_last(int x, int l, int r, int ll, int rr,
                  const function<bool(const node &)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y) {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1) {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    template <typename M> segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }
    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }
    template <typename... M> void modify(int ll, int rr, const M &...v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
    

    

    int find_first(int ll, int rr, const function<bool(const node &)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }
    int find_last(int ll, int rr, const function<bool(const node &)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};



template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 


template<class T>
istream& operator>>(istream& in, vector<T>& a){
    each(i, a){
        in >> i;
    }
    return in;
}
 
template<class T>
ostream& operator<<(ostream& out, vector<T>& a){
    out << a.size() << ' ';
    each(i, a){
        out << i << ' ';
    }
    out << '\n';
    return out;
}
 
 


void solve() {
    int n; re(n);
    vector<pair<pii, int>> a(n); for(int i = 0; i < n; ++i){ re(a[i].fi.fi); a[i].se = i;} for(int i = 0; i < n; ++i){ re(a[i].fi.se);}
    
    vector<vector<int>> gr(n);
    vi starts;
    
    sort(all(a), [](pair<pii, int>& ff, pair<pii, int>& ss){
        return ff.fi.fi < ss.fi.fi;
    });
    for(int i = 0; i + 1 < n; ++i){
        gr[a[i].se].pb(a[i + 1].se);
    }
    starts.pb(a[n - 1].se);

    sort(all(a), [](pair<pii, int>& ff, pair<pii, int>& ss){
        return ff.fi.se < ss.fi.se;
    });

    for(int i = 0; i + 1 < n; ++i){
        gr[a[i].se].pb(a[i + 1].se);
    }
    starts.pb(a[n - 1].se);
    
    if(starts[0] > starts[1]) swap(starts[0], starts[1]);
    starts.resize(unique(all(starts)) - starts.begin());

    vi used(n, 0);

    auto almost_dfs = [&](auto dfs, int v = 0) -> void {
        used[v] = true;
        for(int u : gr[v]){
            if(!used[u]){
                dfs(u);
            }
        }
        return;
    };

    auto dfs = y_combinator(ref(almost_dfs));


    for(int i = 0; i < starts.size(); ++i){
        int v = starts[i];
        dfs(v);
    }

    for(int i = 0; i < n; ++i){
        pr(used[i] ? "1" : "0");
    }
    pr('\n');

    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    int tt = 1;
    re(tt);
    rep(tt) solve();
    

}


