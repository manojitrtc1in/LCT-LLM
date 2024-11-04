






#include <bits/stdc++.h>
using namespace std;

const uint64_t FIXED_SEED = 12345;

const auto START_TIME = chrono::steady_clock::now();
const uint64_t RANDOM_SEED = START_TIME.time_since_epoch().count();
const uint64_t XORSHIFT_SEED = FIXED_SEED;

#include <bits/extc++.h>

template<class T> class custom_hash;

template<class K, class V> using __hash_table = __gnu_pbds::gp_hash_table<
    K, V, custom_hash<K>, equal_to<K>, __gnu_pbds::direct_mask_range_hashing<K>, __gnu_pbds::linear_probe_fn<>,
    __gnu_pbds::hash_standard_resize_policy<__gnu_pbds::hash_exponential_size_policy<>, __gnu_pbds::hash_load_check_resize_trigger<true>, true>
>;

template<class K, class V = __gnu_pbds::null_type> class hash_table : public __hash_table<K, V> {
public:
    hash_table() : __hash_table<K, V>() {
        this->set_loads({.25, .5});
    }
    template<class It> hash_table(It b, It e) : hash_table() {
        this->resize(distance(b, e));
        for (; b != e; this->insert(*b++));
    }
    size_t count(const K& k) {
        return this->find(k) != this->end();
    }
};

template<class K, class V = __gnu_pbds::null_type> using ordered_set = __gnu_pbds::tree<
    K,
    V,
    less<K>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;  


#define all(a) a.begin(), a.end()
#define X first
#define Y second
#ifndef LOCAL
    #define cerr if(0)cerr
#endif

template<class T> istream& operator>>(istream& is, vector<T>& v) {
    for (T& it : v) is >> it;
    return is;
}

template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p);

template<class It> struct __range {
    It b, e;
    __range(It b, It e) : b(move(b)), e(move(e)) {}
};

template<class It> __range<It> range(It b, It e) {
    return __range<It>(move(b), move(e));
}

template<class It> ostream& operator<<(ostream& os, __range<It> r) {
#ifdef LOCAL
    for (os << "["; r.b != r.e; os << *r.b << (++r.b == r.e ? "" : ", "));
    os << "]";
#else
    for (; r.b != r.e; os << *r.b++ << ' ');
#endif
    return os;
}

template<class C> auto operator<<(ostream& os, const C& c) -> decltype((c.begin(), os)) {
    return os << range(c.begin(), c.end());
}

ostream& operator<<(ostream& os, const string& c) {
    return os << c.data();
}

template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}



namespace std {
    template<class T1, class T2> struct hash<pair<T1, T2>> {
        size_t operator()(const pair<T1, T2>& p) const {
            size_t l = hash<T1>()(p.first);
            return l ^= hash<T2>()(p.second) + 0x9e3779b9 + (l << 6) + (l >> 2);
        }
    };
};

template<class T> struct custom_hash : hash<T> {
    size_t operator()(const T& t) const {
        uint64_t x = hash<T>::operator()(t);
        static const uint64_t C = (uint64_t)(4e18 * acos(0)) | 71;
        return __builtin_bswap64((x ^ RANDOM_SEED)*C);
        
    }
};

template<class T> struct Xorshift {
    typedef T result_type;
    constexpr T min() { return 1; }
    constexpr T max() { return -1; }
    virtual T operator()() = 0;
    template<class It, class N> void fill(It b, It e, N l, N u) {
        uniform_int_distribution<N> d(l, u);
        for (; b != e; *b++ = d(*this));
    }
};

struct Xorshift32 : Xorshift<uint32_t> {
    result_type operator()() {
        static result_type s = XORSHIFT_SEED;
        s ^= s << 13;
        s ^= s >> 17;
        return s ^= s << 5;
    }
} gen;

struct Xorshift64 : Xorshift<uint64_t> {
    result_type operator()() {
        static result_type s = XORSHIFT_SEED;
        s ^= s << 13;
        s ^= s >> 7;
        return s ^= s << 17;
    }
} gen64;

struct _ {
    _() {
        ios_base::Init();
        cin.sync_with_stdio(0);
        cout.sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(5);

        

        

    }

    ~_() {
        cerr << fixed << setprecision(2) << "\nTime = ";
        cerr << chrono::duration_cast<chrono::duration<double>>(chrono::steady_clock::now() - START_TIME).count() << '\n';
    }
} _;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 1.01e9;
const long long INF64 = 4.1e18;
const int MOD = 1e9 + 7;
const long double EPS = 1e-9;




namespace FFT {
    typedef complex<double> base;

    const long double PI = acos((long double)-1);

    vector<base> __powersFFT;

    void FFT(vector<base>& a, bool invert = false) {
        int n = a.size();
        assert(n && !(n & (n - 1)));

        for (int i = 1, j = 0, bit; i < n; ++i) {
            for (bit = n >> 1; j >= bit; j -= bit, bit >>= 1);
            j += bit;
            

            

            if (i < j)
                swap(a[i], a[j]);
        }

        if (__powersFFT.size() != n >> 1) {
            __powersFFT.resize(0);
            __powersFFT.reserve(n >> 1);
            long double f = PI / n, ang;
            for (int i = 0; i < n; i += 2) {
                ang = f * i;
                __powersFFT.emplace_back(cos(ang), sin(ang));
            }
        }

        for (int len = 2, len2 = 1, ilen = n >> 1, s = (invert ? -1 : 1); len <= n; len <<= 1, len2 <<= 1, ilen >>= 1)
            for (int i = 0; i < n; i += len)
                for (int j = 0, k = 0; j < len2; ++j, k += ilen) {
                    base u = a[i + j], v = a[i + j + len2] * base(real(__powersFFT[k]), imag(__powersFFT[k]) * s);
                    a[i + j] = u + v;
                    a[i + j + len2] = u - v;
                }

        if (invert)
            for (int i = 0; i < n; ++i)
                a[i] /= n;
    }

    template<class T>
    void PairFFT(const vector<T>& a, const vector<T>& b, vector<base>& fa, vector<base>& fb, size_t n) {
        if (a.size() < b.size()) {
            PairFFT(b, a, fb, fa, n);
            return;
        }
        assert(a.size() <= n);
        fa.resize(0);
        fa.reserve(n);
        for (int i = 0; i < b.size(); ++i)
            fa.emplace_back(a[i], b[i]);
        for (int i = b.size(); i < a.size(); ++i)
            fa.emplace_back(a[i]);
        for (int i = a.size(); i < n; ++i)
            fa.emplace_back(0);
        FFT(fa);
        fb.resize(n);
        fb[0] = imag(fa[0]);
        fa[0] = real(fa[0]);
        if (n > 1) {
            fb[n >> 1] = imag(fa[n >> 1]);
            fa[n >> 1] = real(fa[n >> 1]);
        }
        for (int i = 1, j = n - 1; i < j; ++i, --j) {
            base x = fa[i], y = fa[j];
            fa[i] = (x + conj(y)) * base(0.5);
            fb[i] = (x - conj(y)) * base(0, -0.5);
            fa[j] = (conj(x) + y) * base(0.5);
            fb[j] = (y - conj(x)) * base(0, -0.5);
        }
    }

    void PairIFFT(const vector<base>& a, const vector<base>& b, vector<base>& f) {
        assert(a.size() == b.size());
        f.resize(a.size());
        for (int i = 0; i < a.size(); ++i)
            f[i] = a[i] + b[i] * base(0, 1);
        FFT(f, true);
    }

    int CeilLb(int s) {
        int n = 1 << (sizeof(int) * 8 - 1 - __builtin_clz(s));
        return n << (n < s);
    }

    template<class T, class R>
    void Mult(const vector<T>& a, const vector<T>& b, vector<R>& res, int n = -1) {
        assert(!a.empty() && !b.empty());
        if (n <= 0)
            n = CeilLb(a.size() + b.size() - 1);
        vector<base> fa, fb;
        PairFFT(a, b, fa, fb, n);
        for (int i = 0; i < n; ++i)
            fa[i] *= fb[i];
        FFT(fa, true);
        res.resize(n);
        if (is_integral<R>::value)
            for (int i = 0; i < n; ++i)
                res[i] = round(real(fa[i]));
        else
            for (int i = 0; i < n; ++i)
                res[i] = real(fa[i]);
    }

    template<class T, class R>
    void SplitMult(vector<T> a, vector<T> b, vector<R>& res, int n = -1) {
        const int SPLT = 16;

        assert(!a.empty() && !b.empty());
        if (n <= 0)
            n = CeilLb(a.size() + b.size() - 1);
        res.resize(n);

        vector<base> m[2][2], buf[2];
        for (int i = 0; i < 2; ++i) {
            auto& c = (i ? b : a);
            vector<T> d(c.size());
            for (int i = 0, mask = (1 << SPLT) - 1; i < c.size(); ++i) {
                d[i] = c[i] >> SPLT;
                c[i] &= mask;
            }
            PairFFT(c, d, m[i][0], m[i][1], n);
            buf[i].resize(n);
        }

        for (int i = 0; i < n; ++i)
            buf[0][i] = m[0][0][i] * m[1][1][i] + m[0][1][i] * m[1][0][i];
        FFT(buf[0], true);
        for (int i = 0; i < n; ++i)
            res[i] = (R)(round(real(buf[0][i]))) << SPLT;

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
                buf[i][j] = m[0][i][j] * m[1][i][j];
        PairIFFT(buf[0], buf[1], buf[0]);
        for (int i = 0; i < n; ++i)
            res[i] += (R)(round(real(buf[0][i]))) + ((R)(round(imag(buf[0][i]))) << (SPLT << 1));
    }
};



const int MOD2 = 1009;


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi cnt(m);
    for (int i = 0, re; i < n; ++i) {
        cin >> re;
        ++cnt[re - 1];
    }
    multimap<int, vll> pols;
    for (int i = 0; i < m; ++i)
        if (cnt[i])
            pols.emplace(cnt[i] + 1, vll(cnt[i] + 1, 1));
    while (pols.size() > 3) {
        vector<vll> a;
        for (int i = 0; i < 4; ++i) {
            a.push_back(move(pols.begin()->second));
            pols.erase(pols.begin());
        }
        vector<FFT::base> tmp[4];
        int sz1 = FFT::CeilLb(a[0].size() + a[1].size() - 1), sz2 = FFT::CeilLb(a[2].size() + a[3].size() - 1);
        int sz = max(sz1, sz2);
        for (int i = 0; i < 2; ++i) {
            int x = i << 1, y = i << 1 | 1;
            FFT::PairFFT(a[x], a[y], tmp[x], tmp[y], sz);
            for (int j = 0; j < sz; ++j)
                 tmp[x][j] *= tmp[y][j];
        }
        FFT::PairIFFT(tmp[0], tmp[2], tmp[0]);

        a[0].resize(sz1);
        for (int i = 0; i < sz1; ++i) {
            a[0][i] = real(tmp[0][i]) + 0.5;
            if (a[0][i] >= MOD2)
                a[0][i] %= MOD2;
        }
        for (; a[0].size() > 1 && a[0].back() == 0; a[0].pop_back());

        a[1].resize(sz2);
        for (int i = 0; i < sz2; ++i) {
            a[1][i] = imag(tmp[0][i]) + 0.5;
            if (a[1][i] >= MOD2)
                a[1][i] %= MOD2;
        }
        for (; a[1].size() > 1 && a[1].back() == 0; a[1].pop_back());

        for (int i = 0; i < 2; ++i)
            pols.emplace(a[i].size(), move(a[i]));
    }
    while (pols.size() > 1) {
        vector<vll> a;
        for (int i = 0; i < 2; ++i) {
            a.push_back(move(pols.begin()->second));
            pols.erase(pols.begin());
        }
        auto& res = a[0];
        FFT::Mult(a[0], a[1], res);
        for (int i = 0; i < res.size(); ++i)
            if (res[i] >= MOD2)
                res[i] %= MOD2;
        for (; res.size() > 1 && res.back() == 0; res.pop_back());
        pols.emplace(res.size(), move(res));
    }

    cout << pols.begin()->second[k] << endl;
}


int main() {
    int t = 1;
    

    while (t--) {
        solve();
    }
    return 0;
}

